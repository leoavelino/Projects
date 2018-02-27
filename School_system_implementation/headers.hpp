#ifndef MAIN_CLASSES
#define MAIN_CLASSES

struct Student {
	std::string name;
	std::string address;
	std::string phone;
	int age;

	Student(){}
	Student(std::string name) : name(name) {}
	Student(std::string name, std::string address, std::string phone, int age) : 
		name(name), address(address), phone(phone), age(age) {}
};

struct Course {
	std::string code;
	std::string name;
	std::string instructor;

	Course() {}
	Course(std::string code) : code(code) {}
	Course(std::string code, std::string name, std::string instructor) :
		code(code), name(name), instructor(instructor) {}
};

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

class StudentDataBase {

	std::vector<Student> students_db;
	
	std::vector<Student>::iterator match(std::string name)
	{
		for(auto it = students_db.begin(); it != students_db.end(); it++)
		{
			if (it->name == name)
			{
				return it;
			}
		}
		return students_db.end();
	}

public:

	void new_student(Student s)
	{
		students_db.push_back(s);
	}

	void delete_student(std::string name)
	{
		auto it = match(name);
		if (it != students_db.end())
		{
			students_db.erase(it);
		}
	}

	bool existent_student(std::string name)
	{
		auto it = match(name);
		if (it != students_db.end())
		{
			return true;
		}
		return false;
	}

	Student& find_student(std::string name)
	{
		auto it = match(name);
		if (it != students_db.end())
		{
			std::cout << "Name: " << it->name << "\tAddress: " << it->address << "\tPhone: " << it->phone
				<< "\t\tAge: "<< it->age;
			return *it;
		}
		else{
			std::cout << "Not found.";
			Student* s = new Student("");
			return *s;
		}
	}

	void list_students()
	{
		std::cout << std::endl;
		for(auto it = students_db.begin(); it != students_db.end(); it++)
		{
			find_student(it->name);
			std::cout << std::endl;
		}
	}

	void update_student(Student s)
	{
		auto it = match(s.name);
		if (it != students_db.end())
		{
			it->name = s.name;
			if (s.phone != "")
			{
				it->phone = s.phone;
			}
			if (s.age != 0)
			{
				it->age = s.age;
			}
			if (s.address != "")
			{
				it->address = s.address;
			}
		}
	}
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
			std::cout << "Code: " << it->code << "\tName: " << it->name << "\tInstructor: " << it->instructor;
			return *it;
		}
		else{
			std::cout << "Not found.";
			Course *c = new Course("");
			return *c;
		}
	}
	void list_course()
	{
		std::cout << std::endl;
		for(auto it = courses_db.begin(); it != courses_db.end(); it++)
		{
			find_course(it->code);
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

class BusinessLogicStudent 
{
	std::unique_ptr<StudentDataBase> s_db;

public:
	BusinessLogicStudent()
	{
		s_db = std::make_unique<StudentDataBase>();
	}
	void add_new_student(Student s)
	{
		if (s_db->existent_student(s.name))
		{
			std::cout << "\nSrry. We are unable to add a new student.";
		}
		else {
			s_db->new_student(s);
		}
	}
	void remove_student(std::string name)
	{
		if (s_db->existent_student(name))
		{
			s_db->delete_student(name);
		}
		else {
			std::cout << "\nThis student does not exist.";
		}
	}
	Student& find_student(std::string name)
	{
		return s_db->find_student(name);
	}
	void list_students()
	{
		s_db->list_students();
	}
	bool student_exists(std::string name)
	{
		if (s_db->existent_student(name))
			return true;
		else 
			return false;
	}
	void update_student(Student s)
	{
		if (s_db->existent_student(s.name))
		{
			s_db->update_student(s);
		}
		else
		{
			std::cout << "\nThis student does not exist.";
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