# FILEPATH: /c:/Users/kemal/Desktop/Evrenos Derivation/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(EvrenosDerivation)

# Add include directory
include_directories(include)

# Add all .cpp files in src directory to SOURCES variable
file(GLOB SOURCES "src/*.cpp")

# Create executable from SOURCES
add_executable(${PROJECT_NAME} ${SOURCES})

# Add some default compiler setting
set(CMAKE_CXX_STANDARD 20)
# add default and extra compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# add default and extra linker flags
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")

# set executable output directory to bin
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)