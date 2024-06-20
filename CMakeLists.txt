cmake_minimum_required(VERSION 3.10)
project(CGPA_Calculator_Project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Disable cpplint for SQLiteCpp
set(SQLITECPP_RUN_CPPLINT OFF)

# Add subdirectory for SQLiteCpp
add_subdirectory(external/SQLiteCpp)

# Include directories
include_directories(external/SQLiteCpp/include)
include_directories(external/SQLiteCpp/sqlite3)
include_directories(src)

# Add the executable
add_executable(CGPA_Calculator_Main
    src/main.cpp
    src/Course.cpp
    src/FileManager.cpp
    src/Student.cpp
)

# Link SQLiteCpp to your target
target_link_libraries(CGPA_Calculator_Main PRIVATE SQLiteCpp)

# Set necessary policies
if (POLICY CMP0079)
  cmake_policy(SET CMP0079 NEW)
endif()

if (POLICY CMP0002)
  cmake_policy(SET CMP0002 NEW)
endif()
