/*****************************************

		   Facade.hpp                      

	Facade design pattern. Facade manages
	all the business logic blocks                        
										 
******************************************/
#ifndef FACADE_HPP
#define FACADE_HPP

#include "student.hpp"
#include "course.hpp"
#include "registration.hpp"

class Facade {
	BusinessLogicStudent bls;
	BusinessLogicCourse blc;
	BusinessLogicRegistration blr;

	Student& find_student(std::string name)
	{
		return bls.find_student(name);
	}
	Course& find_course(std::string code)
	{
		return blc.find_course(code);
	}

public:
	void student_management(std::string obj, std::string op)
	{
		if(op=="remove") {
			bls.remove_student(obj);
		}
		else if(op=="print") {
			bls.print_student(obj);
		}
		else if(op=="list") {
			bls.list_students();
		}
	}
	void student_management(Student obj, std::string op)
	{
		if(op=="new") {
			bls.add_new_student(obj);
		}
		else if(op=="update") {
			bls.update_student(obj);
		}
	}

	void course_management(std::string obj, std::string op)
	{
		if(op=="remove") {
			blc.remove_course(obj);
		}
		else if(op=="print") {
			blc.print_course(obj);
		}
		else if(op=="list") {
			blc.list_course();
		}
	}
	void course_management(Course obj, std::string op)
	{
		if(op=="new") {
			blc.add_new_course(obj);
		}
		else if(op=="update") {
			blc.update_course(obj);
		}
	}

	void registration_management(std::string obj, std::string op)
	{
		if(op=="l_code_student")
		{
			if (bls.student_exists(obj))
			{
				blr.list_courses_by_student(obj);
			}
			else{
				std::cout << "\nThis student does not exist in the database.";
			}
		}
		else if(op=="l_student_code")
		{
			if (blc.course_exists(obj))
			{
				blr.list_students_by_course(obj);
			}
			else{
				std::cout << "\nThis course does not exist in the database.";
			}
		}
		else if(op=="list_rbytype") { 
			if (bls.student_exists(obj))
			{
				blr.list_reg_by_type(obj, 's');
			}
			else if (blc.course_exists(obj))
			{
				blr.list_reg_by_type(obj, 'c');
			}
			else{
				std::cout << "\nError. Not found in the database.";
			}
		}
		else if(op=="list_allr")
		{
			blr.list_all_registrations();
		}
	}
	void registration_management(std::string obj1, std::string obj2, std::string op)
	{
		if (op=="new")
		{
			Student student = find_student(obj1);
			if(student.name == "") {
				std::cout << "\nInvalid student";
				return;
			}
			Course course = find_course(obj2);
			if(course.code == "") {
				std::cout << "\nInvalid code";
				return;
			}
			blr.add_new_registration(student,course);
		}
		else if(op=="remove")
		{
			blr.remove_registration(obj1,obj2);
		}
	}

	bool find_db(std::string obj, std::string op)
	{
		if(op=="student")
		{
			auto temp = find_student(obj);
			if (temp.name == "")
				return false;
			else return true;
		}
		else if (op=="course") {
			auto temp = find_course(obj);
			if (temp.code == "")
				return false;
			else return true;
		}
	}
};
#endif