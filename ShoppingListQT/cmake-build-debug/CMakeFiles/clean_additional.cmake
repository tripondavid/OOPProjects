# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ProbaTestLab13Tura2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ProbaTestLab13Tura2_autogen.dir\\ParseCache.txt"
  "ProbaTestLab13Tura2_autogen"
  )
endif()
