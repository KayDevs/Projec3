#include "CourseList.h"

CourseList::Course::Course(string name, int section, int credits)
{
	this->name = name;
	this->section = section;
	this->credits = credits;
}

CourseList::CourseList()
{
	this->head = nullptr; //decapitate it
}

void CourseList::addCourse(string name, int section, int credits)
{
	//cout<<"Adding a course in the ";
	Course *ptr = head;

	if(ptr == nullptr) //if this is the first item, then make it the head
	{
			//cout<<"front."<<endl;
			Course *new_course = new Course(name, section, credits);
			new_course->next = nullptr;
			head = new_course;
			return;
	} 
	else
	while(ptr)
	{
		if(ptr->next == nullptr) //or if it needs to be appended at the very end
		{
			//cout<<"back."<<endl;
			Course *new_course = new Course(name, section, credits);
			ptr->next = new_course;
			new_course->next = nullptr;
			return;
		}
		if(name > ptr->name && name <= ptr->next->name) //insert somewhere in the middle, in order
		{
			//cout<<"middle."<<endl;
			Course *new_course = new Course(name, section, credits);
			new_course->next = ptr->next;
			ptr->next = new_course;
			return;
		}
		ptr = ptr->next;
	}
}

void CourseList::dropCourse(string name)
{
	Course *ptr = head;
	Course *follow = nullptr;
	if(name == ptr->name)
	{
		head = ptr->next;
		ptr->next = nullptr;
		delete ptr;
		return;
	}
	while(ptr->next)
	{
		//cout<<"name of current: "<<ptr->name<<endl;
		follow = ptr;
		ptr = ptr->next;
		if(name == ptr->name)
		{
			//cout<<"Supposedly deleting."<<endl;
			follow->next = ptr->next;
			//cout<<"repairing."<<endl;
			ptr->next = nullptr;
			delete ptr;
			return;
		}
	}
}

void CourseList::print()
{
	Course *ptr = head;
	while(ptr)
	{
		cout<<ptr->name<<endl;
		cout<<ptr->section<<endl;
		cout<<ptr->credits<<endl;
		ptr = ptr->next;
	}
}