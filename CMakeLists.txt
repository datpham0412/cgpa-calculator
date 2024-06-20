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
    src/Student.cpp
    src/Database.cpp
    src/Menu.cpp
    src/StudentOperations.cpp
)

# Link SQLiteCpp to your target
target_link_libraries(CGPA_Calculator_Main PRIVATE SQLiteCpp)

# Add the test executables
# add_executable(TestMain
#     test/TestMain.cpp
#     src/Course.cpp
#     src/FileManager.cpp
#     src/Student.cpp
# )
# add_executable(TestCourse
#     test/TestCourse.cpp
#     src/Course.cpp
#     src/FileManager.cpp
#     src/Student.cpp
# )

# add_executable(TestFileManager
#     test/TestFileManager.cpp
#     src/Course.cpp
#     src/FileManager.cpp
#     src/Student.cpp
# )

# add_executable(TestStudent
#     test/TestStudent.cpp
#     src/Course.cpp
#     src/FileManager.cpp
#     src/Student.cpp
# )

# Link SQLiteCpp to test targets
# target_link_libraries(TestMain PRIVATE SQLiteCpp)
# target_link_libraries(TestCourse PRIVATE SQLiteCpp)
# target_link_libraries(TestFileManager PRIVATE SQLiteCpp)
# target_link_libraries(TestStudent PRIVATE SQLiteCpp)

# Set necessary policies
if (POLICY CMP0079)
  cmake_policy(SET CMP0079 NEW)
endif()

if (POLICY CMP0002)
  cmake_policy(SET CMP0002 NEW)
endif()
