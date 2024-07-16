# THE LIST OF PLUGINS AND THE CORRESPONDING SOURCE FILES
# ======================================================
set(LLVM_TUTOR_PLUGINS
    BoundaryCheck
    CodeGenerator
    )

set(BoundaryCheck_SOURCES
  BoundaryCheck.cpp
  )

set(CodeGenerator_SOURCES
  CodeGenerator.cpp
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
