#ifndef FACADE_HPP
#define FACADE_HPP

#include "student.hpp"
#include "course.hpp"
#include "registration.hpp"

class Facade {
	BusinessLogicStudent bls;
	BusinessLogicCourse blc;
	BusinessLogicRegistration blr;

public:
	//Students
	void new_student(Student s)
	{
		bls.add_new_student(s);
	}
	void remove_student(std::string name)
	{
		bls.remove_student(name);
	}
	Student& find_student(std::string name)
	{
		return bls.find_student(name);
	}
	void print_student(std::string name)
	{
		return bls.print_student(name);
	}
	void list_all_students()
	{
		bls.list_students();
	}
	void update_student(Student s)
	{
		bls.update_student(s);
	}

	//Courses
	void new_course(Course c)
	{
		blc.add_new_course(c);
	}
	void remove_course(std::string code)
	{
		blc.remove_course(code);
	}
	Course& find_course(std::string code)
	{
		return blc.find_course(code);
	}
	void list_all_courses()
	{
		blc.list_course();
	}
	void update_course(Course c)
	{
		blc.update_course(c);
	}

	//Registration
	void new_registration(Registration r)
	{
		blr.add_new_registration(r);
	}
	void list_all_registrations()
	{
		blr.list_all_registrations();
	}
	void list_courses(std::string name)
	{
		if (bls.student_exists(name))
		{
			blr.list_courses_by_student(name);
		}
		else
			std::cout << "\nThis student does not exist in the database.";
	}
	void list_students(std::string code)
	{
		if (blc.course_exists(code))
		{
			blr.list_students_by_course(code);
		}
		else
			std::cout << "\nThis course does not exist in the database.";
	}
	void list_registries(std::string s)
	{
		if (bls.student_exists(s))
		{
			blr.list_registries(s, 's');
		}
		else if (blc.course_exists(s))
		{
			blr.list_registries(s, 'c');
		}
		else
			std::cout << "\nError. Not found in the database.";
	}

};
#endif