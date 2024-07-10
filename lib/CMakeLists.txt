# THE LIST OF PLUGINS AND THE CORRESPONDING SOURCE FILES
# ======================================================
set(LLVM_TUTOR_PLUGINS
    MyPass
    BoundaryCheck
    )

set(MyPass_SOURCES
  DebugInfoUtils.cpp
  MyPass.cpp
  PDGUtils.cpp
  PDGNode.cpp
  Tree.cpp
  )

set(BoundaryCheck_SOURCES
  BoundaryCheck.cpp
  )

# CONFIGURE THE PLUGIN LIBRARIES
# ==============================
foreach( plugin ${LLVM_TUTOR_PLUGINS} )
    # Create a library corresponding to 'plugin'
    add_library(
      ${plugin}
      SHARED
      ${${plugin}_SOURCES}
      )

    # Configure include directories for 'plugin'
    target_include_directories(
      ${plugin}
      PRIVATE
      "${CMAKE_CURRENT_SOURCE_DIR}/../include"
    )

endforeach()
