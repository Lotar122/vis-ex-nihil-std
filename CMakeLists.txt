# CMakeList.txt : CMake project for nstd, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("nstd")

file(GLOB SOURCES "sources/*.cpp")

# Add source to this project's executable.
add_library (nstd STATIC 
	${SOURCES}
)

target_include_directories(nstd 
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/thirdparty
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET nstd PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
