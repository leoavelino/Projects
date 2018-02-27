#ifndef REGISTRATION_HPP
#define REGISTRATION_HPP

struct Registration {
	Student student;
	Course course;
	int number;
	
	Registration()
	{
		static int n = 0;
		number = n;
		n++;
	}

	Registration(Student s, Course c) : student(s), course(c)
	{
		static int n = 0;
		number = n;
		n++;
	}

	Registration& operator=(const Registration& other)
	{
		this->student = other.student;
		this->course = other.course;
		return *this;
	}
};

class RegistrationDataBase {
	std::vector<Registration> registration_db;

public:
	void new_registration(Registration reg)
	{
		registration_db.push_back(reg);
	}

	bool is_enrolled(Registration reg)
	{
		for(auto it = registration_db.begin(); it != registration_db.end(); it++)
		{
			if (reg.student.name == it->student.name)
			{
				if (reg.course.code == it->course.code)
				{
					return true;
				}
			}
		}
		return false;
	}
	void list_registrations()
	{
		for(auto it = registration_db.begin(); it != registration_db.end(); it++)
		{
			std::cout << "\nStudent: " << it->student.name << "\t\tCourse: " << it->course.code;
		}
	}
	void list_courses_of_student(std::string name)
	{
		for (auto it = registration_db.begin(); it != registration_db.end(); it++)
		{
			if (it->student.name == name)
			{
				std::cout << "\nCourse: " << it->course.code;
			}
		}
	}
	void list_students_of_course(std::string code)
	{
		for (auto it = registration_db.begin(); it != registration_db.end(); it++)
		{
			if (it->course.code == code)
			{
				std::cout << "\nStudent: " << it->student.name;
			}
		}
	}
	void list_registries(std::string s, char type)
	{
		for (auto it = registration_db.begin(); it != registration_db.end(); it++)
		{
			if (type == 's')
			{
				if (it->student.name == s)
				{
					std::cout << "\nRegistration: " << it->number;
				}
			}
			else if (type == 'c')
			{
				if (it->course.code == s)
				{
					std::cout << "\nRegistration: " << it->number;
				}
			}
		}	
	}
	bool empty_db()
	{
		return (registration_db.empty() == true);
	}
};

class BusinessLogicRegistration
{
	std::unique_ptr<RegistrationDataBase> r_db;

public:

	BusinessLogicRegistration()
	{
		r_db = std::make_unique<RegistrationDataBase>();
	}

	void add_new_registration(Registration r)
	{
		if (r_db->is_enrolled(r) == true)
		{
			std::cout << "\nThe student: " << r.student.name << " is already enrolled in " << 
				r.course.code <<".";
				return;
		}
		else
			r_db->new_registration(r);
	}
	void list_all_registrations()
	{
		if (!r_db->empty_db())
		{
			r_db->list_registrations();
		}
		else
		{
			std::cout << "\nThere are no registrations for current period.";
		}
	}
	void list_courses_by_student(std::string name)
	{
		r_db->list_courses_of_student(name);
	}
	void list_students_by_course(std::string code)
	{
		r_db->list_students_of_course(code);
	}
	void list_registries(std::string s, char type)
	{
		r_db->list_registries(s, type);
	}

};

#endif