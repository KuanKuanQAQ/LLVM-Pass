#ifndef TREE_H_
#define TREE_H_
#include "DebugInfoUtils.h"
#include "LLVMEssentials.h"
#include "PDGEnums.h"
#include "PDGNode.h"
#include "PDGUtils.h"
#include "llvm/Support/raw_ostream.h"
#include <set>

namespace pdg {
class Tree;
class TreeNode : public Node {
public:
    TreeNode(llvm::Value& val, GraphNodeType node_type)
        : Node(val, node_type) {};
    TreeNode(const TreeNode& tree_node);
    TreeNode(llvm::DIType* di_type, int depth, TreeNode* parent_node, Tree* tree, GraphNodeType node_type);
    TreeNode(llvm::Function& f, llvm::DIType* di_type, int depth, TreeNode* parent_node, Tree* tree, GraphNodeType node_type);
    int expandNode(); // build child nodes and connect with them
    llvm::DILocalVariable* getDILocalVar() { return _di_local_var; }
    void insertChildNode(TreeNode* new_child_node) { _children.push_back(new_child_node); }
    void setParentTreeNode(TreeNode* parent_node) { _parent_node = parent_node; }
    void setDILocalVariable(llvm::DILocalVariable& di_local_var) { _di_local_var = &di_local_var; }
    void addAddrVar(llvm::Value& v) { _addr_vars.insert(&v); }
    void setCanOptOut(bool can_opt_out) { _can_opt_out = can_opt_out; }
    bool getCanOptOut() { return _can_opt_out; }
    std::vector<TreeNode*>& getChildNodes() { return _children; }
    std::unordered_set<llvm::Value*>& getAddrVars() { return _addr_vars; }
    void computeDerivedAddrVarsFromParent();
    TreeNode* getParentNode() { return _parent_node; }
    Tree* getTree() const { return _tree; }
    void setTree(Tree* tree) { _tree = tree; }
    int getDepth() { return _depth; }
    void addAccessTag(AccessTag acc_tag) { _acc_tag_set.insert(acc_tag); }
    std::set<AccessTag>& getAccessTags() { return _acc_tag_set; }
    bool isRootNode() { return _parent_node == nullptr; }
    bool isStructMember();
    int numOfChild() { return _children.size(); }
    bool hasReadAccess() { return _acc_tag_set.find(AccessTag::DATA_READ) != _acc_tag_set.end(); }
    bool hasWriteAccess() { return _acc_tag_set.find(AccessTag::DATA_WRITE) != _acc_tag_set.end(); }
    bool hasAccess() { return (_acc_tag_set.size() != 0); }
    void setAccessInAtomicRegion() { _is_accessed_in_atomic_region = true; }
    bool isAccessedInAtomicRegion() { return _is_accessed_in_atomic_region; }
    void setAllocStr(std::string str) { _alloc_str = str; }
    std::string getAllocStr() { return _alloc_str; }
    void setDeallocStr(std::string str) { _dealloc_str = str; }
    std::string getDeallocStr() { return _dealloc_str; }
    bool isSeqPtr() { return _is_seq_ptr; }
    void setSeqPtr() { _is_seq_ptr = true; }
    void dump() override;

    // used for collecting ksplit stats
public:
    bool is_shared = false;
    bool is_ioremap = false;
    bool is_user = false;
    bool is_sentinel = false;
    bool is_string = false;
    bool _is_seq_ptr = false;
    std::set<std::string> annotations;

private:
    Tree* _tree = nullptr;
    TreeNode* _parent_node = nullptr;
    int _depth = 0;
    llvm::DILocalVariable* _di_local_var = nullptr;
    std::vector<TreeNode*> _children;
    std::unordered_set<llvm::Value*> _addr_vars;
    std::set<AccessTag> _acc_tag_set;
    bool _is_accessed_in_atomic_region = false;
    bool _can_opt_out = false;
    // FIXME: outdated
    std::string _alloc_str;
    std::string _dealloc_str;
};

class Tree {
public:
    Tree() = default;
    Tree(llvm::Value& v) { _base_val = &v; }
    Tree(const Tree& src_tree);
    void setRootNode(TreeNode& root_node) { _root_node = &root_node; }
    void setTreeNodeType(GraphNodeType node_type) { _root_node->setNodeType(node_type); }
    TreeNode* getRootNode() const { return _root_node; }
    int size() { return _size; }
    void setSize(int size) { _size = size; }
    void increaseTreeSize() { _size++; }
    void print();
    void build(int max_tree_depth = 6);
    llvm::Value* getBaseVal() const { return _base_val; }
    void setBaseVal(llvm::Value& v) { _base_val = &v; }
    llvm::Function* getFunc() { return (_root_node == nullptr ? nullptr : _root_node->getFunc()); }
    void addAccessForAllNodes(AccessTag acc_tag);

private:
    llvm::Value* _base_val = nullptr;
    TreeNode* _root_node = nullptr;
    int _size = 0;
};

class ArgAccessTree;

class ArgAccessTreeNode {
public:
    ArgAccessTreeNode() = delete;
    ArgAccessTreeNode(llvm::Value* val, llvm::DIType* ditype, bool flag)
        : value(val)
        , di_type(ditype)
        , mapping(flag)
    {
    }
    void addChildNode(ArgAccessTreeNode* child)
    {
        children.push_back(child);
        child->setTree(_tree);
        child->setDepth(_depth + 1);
    }
    std::vector<ArgAccessTreeNode*>& getChildNodes() { return children; }
    void setTree(ArgAccessTree* tree) { _tree = tree; }
    ArgAccessTree* getTree() { return _tree; }
    void setDepth(int depth) { _depth = depth; }
    int getDepth() { return _depth; }
    llvm::Value* getValue() { return value; }
    llvm::DIType* getDIType() { return di_type; }
    bool isMapping() { return mapping; }

    void dump()
    {
        llvm::errs() << "depth: " << _depth << " "; 
        di_type->print(llvm::errs());
        llvm::errs() << "\n";
    }

private:
    llvm::Value* value = nullptr;
    llvm::DIType* di_type = nullptr;
    ArgAccessTree* _tree = nullptr;
    std::vector<ArgAccessTreeNode*> children;
    bool mapping = false;
    int _depth = 0;
};

class ArgAccessTree {
public:
    ArgAccessTree() = delete;
    ArgAccessTree(TreeNode* root_node);
    int size() { return _size; }
    // static ArgAccessTree* buildArgAccessTree(TreeNode* root_node);

    void setRootNode(ArgAccessTreeNode* root)
    {
        _root_node = root;
        _size = 1;
        _root_node->setTree(this);
    }

    ArgAccessTreeNode* getRootNode() { return _root_node; }

    void incTreeSize() { _size++; }

private:
    ArgAccessTreeNode* _root_node = nullptr;
    int _size = 0;
};

} // namespace pdg

#endif