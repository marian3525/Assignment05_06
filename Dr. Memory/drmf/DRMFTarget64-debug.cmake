#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "drsyscall" for configuration "Debug"
set_property(TARGET drsyscall APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(drsyscall PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/drmf/lib64/debug/drsyscall.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "ntdll_imports"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "dynamorio;drmgr;drcontainers"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/drmf/lib64/debug/drsyscall.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS drsyscall )
list(APPEND _IMPORT_CHECK_FILES_FOR_drsyscall "${_IMPORT_PREFIX}/drmf/lib64/debug/drsyscall.lib" "${_IMPORT_PREFIX}/drmf/lib64/debug/drsyscall.dll" )

# Import target "drsyscall_static" for configuration "Debug"
set_property(TARGET drsyscall_static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(drsyscall_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "dynamorio;drmgr_static;drcontainers;ntdll_imports"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/drmf/lib64/debug/drsyscall_static.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS drsyscall_static )
list(APPEND _IMPORT_CHECK_FILES_FOR_drsyscall_static "${_IMPORT_PREFIX}/drmf/lib64/debug/drsyscall_static.lib" )

# Import target "drsymcache" for configuration "Debug"
set_property(TARGET drsymcache APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(drsymcache PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/drmf/lib64/debug/drsymcache.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "drsyms"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "dynamorio;drmgr"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/drmf/lib64/debug/drsymcache.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS drsymcache )
list(APPEND _IMPORT_CHECK_FILES_FOR_drsymcache "${_IMPORT_PREFIX}/drmf/lib64/debug/drsymcache.lib" "${_IMPORT_PREFIX}/drmf/lib64/debug/drsymcache.dll" )

# Import target "drsymcache_static" for configuration "Debug"
set_property(TARGET drsymcache_static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(drsymcache_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "dynamorio;drcontainers;drmgr_static;drsyms_static"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/drmf/lib64/debug/drsymcache_static.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS drsymcache_static )
list(APPEND _IMPORT_CHECK_FILES_FOR_drsymcache_static "${_IMPORT_PREFIX}/drmf/lib64/debug/drsymcache_static.lib" )

# Import target "umbra" for configuration "Debug"
set_property(TARGET umbra APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(umbra PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/drmf/lib64/debug/umbra.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "ntdll_imports"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "dynamorio;drmgr;drcontainers"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/drmf/lib64/debug/umbra.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS umbra )
list(APPEND _IMPORT_CHECK_FILES_FOR_umbra "${_IMPORT_PREFIX}/drmf/lib64/debug/umbra.lib" "${_IMPORT_PREFIX}/drmf/lib64/debug/umbra.dll" )

# Import target "umbra_static" for configuration "Debug"
set_property(TARGET umbra_static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(umbra_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "dynamorio;drmgr_static;drcontainers;ntdll_imports"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/drmf/lib64/debug/umbra_static.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS umbra_static )
list(APPEND _IMPORT_CHECK_FILES_FOR_umbra_static "${_IMPORT_PREFIX}/drmf/lib64/debug/umbra_static.lib" )

# Import target "drfuzz" for configuration "Debug"
set_property(TARGET drfuzz APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(drfuzz PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/drmf/lib64/debug/drfuzz.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "dynamorio;drwrap;drmgr;drcontainers"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/drmf/lib64/debug/drfuzz.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS drfuzz )
list(APPEND _IMPORT_CHECK_FILES_FOR_drfuzz "${_IMPORT_PREFIX}/drmf/lib64/debug/drfuzz.lib" "${_IMPORT_PREFIX}/drmf/lib64/debug/drfuzz.dll" )

# Import target "drfuzz_static" for configuration "Debug"
set_property(TARGET drfuzz_static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(drfuzz_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "dynamorio"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/drmf/lib64/debug/drfuzz_static.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS drfuzz_static )
list(APPEND _IMPORT_CHECK_FILES_FOR_drfuzz_static "${_IMPORT_PREFIX}/drmf/lib64/debug/drfuzz_static.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
