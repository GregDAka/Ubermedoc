# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\UberMedoc_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\UberMedoc_autogen.dir\\ParseCache.txt"
  "UberMedoc_autogen"
  )
endif()
