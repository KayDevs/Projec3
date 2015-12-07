#include <string>
#include <iostream>
using namespace std;

#ifndef INCLUDE_COURSELIST
#define INCLUDE_COURSELIST

struct CourseList
{
	struct Course
	{
		Course(string name, int section, int credits);
		string name;
		int section;
		int credits;	
		Course *next;
	};
	Course *head;
	CourseList();
	void addCourse(string name, int section, int credits);
	void dropCourse(string name);
	void print();
};

#endif