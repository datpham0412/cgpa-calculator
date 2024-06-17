#include "../src/Course.h"
#include <cassert>
#include <iostream>

void testCourseConstructor()
{
    Course course("Data Structures and Algorithms", 90);
    assert(course.GetCourseName() == "Data Structures and Algorithms");
    assert(course.GetItsGrades() == 90);
    std::cout << "Test Course constructor passed" << std::endl;
}

void testCourseGetters()
{
    Course course("Introduction to physics", 85);
    assert(course.GetCourseName() == "Introduction to physics");
    assert(course.GetItsGrades() == 85);
    std::cout << "Test course getters passed" << std::endl;
}

int main()
{
    testCourseConstructor();
    testCourseGetters();
    std::cout << "All test passed" << std::endl;
    return 0;
}
