/*****************************************

		   Course.hpp                      

	Course class, Course Database class
	and Business Logic Course class                       
										 
******************************************/

#ifndef COURSE_HPP
#define COURSE_HPP

struct Course {
	std::string code;
	std::string name;
	std::string instructor;

	Course() {}
	Course(std::string code) : code(code) {}
	Course(std::string code, std::string name, std::string instructor) :
		code(code), name(name), instructor(instructor) {}
};

class CourseDataBase {
	std::vector<Course> courses_db;

	std::vector<Course>::iterator match(std::string code)
	{
		for(auto it = courses_db.begin(); it != courses_db.end(); it++)
		{
			if (it->code == code)
			{
				return it;
			}
		}
		return courses_db.end();
	}

public:
	void new_course(Course c)
	{
		courses_db.push_back(c);
	}
	void delete_course(std::string code)
	{
		auto it = match(code);
		if (it != courses_db.end())
		{
			courses_db.erase(it);
		}
	}
	bool existent_course(std::string code)
	{
		auto it = match(code);
		if (it != courses_db.end())
		{
			return true;
		}
		return false;
	}
	Course& find_course(std::string code)
	{
		auto it = match(code);
		if (it != courses_db.end())
		{
			return *it;
		}
		else{
			Course* c = new Course("");
			return *c;
		}
	}
	void print_course(std::string code)
	{
		auto course = find_course(code);
		if(course.code != "")
		{
			std::cout << "Code: " << course.code << "\tName: " << course.name << 
				"\tInstructor: " << course.instructor;
		}
		else{
			std::cout << "\nNot found.";
		}
	}
	void list_course()
	{
		std::cout << std::endl;
		for(auto it = courses_db.begin(); it != courses_db.end(); it++)
		{
			print_course(it->code);
			std::cout << std::endl;
		}
	}
	void update_course(Course c)
	{
		auto it = match(c.code);
		if (it != courses_db.end())
		{
			it->code = c.code;
			if (c.name != "")
			{
				it->name = c.name;
			}
			if (c.instructor != "")
			{
				it->instructor = c.instructor;
			}
		}
	}
};

class BusinessLogicCourse 
{
	std::unique_ptr<CourseDataBase> c_db;

public:
	BusinessLogicCourse()
	{
		c_db = std::make_unique<CourseDataBase>();
	}
	void add_new_course(Course c)
	{
		if (c_db->existent_course(c.code))
		{
			std::cout << "\nSrry. We are unable to add a new course.";
		}
		else {
			c_db->new_course(c);
		}
	}
	void remove_course(std::string code)
	{
		if (c_db->existent_course(code))
		{
			c_db->delete_course(code);
		}
		else {
			std::cout << "\nThis course does not exist.";
		}
	}
	Course& find_course(std::string code)
	{
		return c_db->find_course(code);
	}
	void print_course(std::string code)
	{
		return c_db->print_course(code);
	}
	void list_course()
	{
		c_db->list_course();
	}
	bool course_exists(std::string code)
	{
		if (c_db->existent_course(code))
			return true;
		else 
			return false;
	}
	void update_course(Course c)
	{
		if(c_db->existent_course(c.code))
		{
			c_db->update_course(c);
		}
		else
		{
			std::cout << "\nThis course does not exist.";
		}
	}
};

#endif