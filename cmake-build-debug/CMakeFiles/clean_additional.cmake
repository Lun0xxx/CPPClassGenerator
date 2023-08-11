# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\C__ClassGen_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\C__ClassGen_autogen.dir\\ParseCache.txt"
  "C__ClassGen_autogen"
  )
endif()
