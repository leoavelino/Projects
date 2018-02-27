#ifndef STUDENT_HPP
#define STUDENT_HPP

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
			return *it;
		}
		else{
			Student* s = new Student("");
			return *s;
		}
	}
	void print_student(std::string name)
	{
		auto student = find_student(name);
		if(student.name != "")
		{
			std::cout << "Name: " << student.name << "\tAddress: " << student.address << "\tPhone: " << 
				student.phone << "\t\tAge: "<< student.age;
		}
		else{
			std::cout << "\nNot found.";
		}
	}
	void list_students()
	{
		std::cout << std::endl;
		for(auto it = students_db.begin(); it != students_db.end(); it++)
		{
			print_student(it->name);
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
	void print_student(std::string name)
	{
		return s_db->print_student(name);
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

#endif