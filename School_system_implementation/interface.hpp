/*****************************************

		   Interface.hpp                      

	User interface for the school system                               
										 
******************************************/

#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <cstdlib>

class Interface
{

	public:
	Facade *f;

	Interface() : f(new Facade) {}
	void main_menu()
	{
		system("clear");
		std::cout << " ****** School XYZ ******" << std::endl;

		std::cout << "\n1 - New Student";
		std::cout << "\n2 - Find Student";
		std::cout << "\n3 - Update Student";
		std::cout << "\n4 - Remove Student";
		std::cout << std::endl;
	    std::cout << "\n5 - New Course";
		std::cout << "\n6 - Find Course";
		std::cout << "\n7 - Update Course";
		std::cout << "\n8 - Remove Course";
		std::cout << std::endl;
		std::cout << "\n9 - New Registration";
		std::cout << "\n10 - Find Registration";
		std::cout << "\n11 - Remove Registration";
		std::cout << std::endl;
		std::cout << "\n12 - List all registrations";
		std::cout << "\n13 - List all courses registered";
		std::cout << "\n14 - List all students registered";
		std::cout << "\n15 - List all students registered of a course";
		std::cout << "\n16 - List all students enrolled in at least one course";
		std::cout << "\n17 - List all courses of a student";
		std::cout << "\n18 - List all courses that have students enrolled";
		std::cout << "\n19 - List all registrations of a student";
		std::cout << "\n20 - List all registrations of a course";
		std::cout << "\n21 - List all students that have not registered for any course";
		std::cout << "\n22 - List all courses that have no students";
		std::cout << "\n23 - EXIT";
		std::cout << "\n\n - Please, select an option: ";
	}

	void input(int n)
	{
		switch (n)
		{
			case 1:
			{
				Student s = new_student_routine();
				f->student_management(s,"new");
				break;
			}
			case 2:
			{
				std::string name;
				std::cout << "\nType the student name you wish to find: "; std::cin >> name;
				f->student_management(name,"print");
				break;
			}
			case 3:
			{
				Student s = student_update_routine();
				f->student_management(s,"update");
				break;
			}
			case 4:
			{
				std::string name;
				std::cout << "\nType the student name you wish to remove: "; std::cin >> name;
				f->student_management(name,"remove");
				break;
			}
			case 5:
			{
				Course c = new_course_routine();
				f->course_management(c,"new");
				break;
			}
			case 6:
			{
				std::string code;
				std::cout << "\nType the course code you wish to find: "; std::cin >> code;
				f->course_management(code,"print");
				break;
			}
			case 7:
			{
				Course c = course_update_routine();
				f->course_management(c,"update");
				break;
			}
			case 8:
			{
				std::string code;
				std::cout << "\nType the course code you wish to remove: "; std::cin >> code;
				f->course_management(code,"remove");
				break;
			}
			case 9:
			{
				std::string name, code;

				std::cout << "\nType the student name you want to register for a course: "; 
				std::cin >> name;
				if((f->find_db(name,"student") == false))
				{
					std::cout << "\nYou typed an invalid name.";
					break; 
				}

				std::cout << "\nType the course code you want to register the student for: "; 
				std::cin >> code;
				if((f->find_db(code,"course") == false))
				{
					std::cout << "\nYou typed an invalid code.";
					break; 
				}

				f->registration_management(name,code,"new");
				break;
			}
			case 10:
			{
				//to implement...
			}
			case 11:
			{
				std::string name, code;
				std::cout << "\nType the student name: "; std::cin >> name;
				std::cout << "\nType the course code: "; std::cin >> code;
				f->registration_management(name, code,"remove");
				break;
			}
			case 12:
			{
				f->registration_management("","list_allr");
				break;
			}
			case 13:
			{
				f->course_management("","list");
				break;
			}
			case 14:
			{
				f->student_management("","list");
				break;
			}
			case 15:
			{
				std::string code;
				std::cout << "Type the course code: "; std::cin >> code;
				f->registration_management(code,"l_student_code");
				break;
			}
			case 17:
			{
				std::string name;
				std::cout << "Type the student name: "; std::cin >> name;
				f->registration_management(name,"l_code_student");
				break;
			}
			case 23:
			{
				break;
			}
		}
	}

	Student new_student_routine()
	{
		std::string name; char op;
		std::cout << "\nStudent name: "; std::cin >> name;
		while(1)
		{
			std::cout << "\nMore info?(y/n): "; std::cin >> op;
			if(op=='y')
			{ 
				int age;
				char temp[40], ch;

				while ((ch = std::cin.get()) != '\n' && ch != EOF); // Flushing cin

				std::cout << "\nStudent address: "; 
				std::cin.getline(temp,sizeof(temp));
				std::string address(temp);

				std::cout << "\nStudent phone: ";
				std::cin.getline(temp,sizeof(temp));
				std::string phone(temp);
				
				std::cout << "\nStudent age: "; std::cin >> age;
				Student s(name,address,phone,age);
				return s;
			}
			else if (op=='n')
			{
				Student s(name);
				return s;
			}
			else{
				std::cout << "\nInvalid Option.";
			}
		}
	}

	Student student_update_routine()
	{
		std::string name;
	    std::cout << "\nStudent name: "; std::cin >> name;
		
		while(1)
		{
			char op, temp[40], ch;
			std::cout << "\nWhat do you wish to update? (p = Phone) (a = Address) (i = age)"; 
			std::cin >> op;

			while ((ch = std::cin.get()) != '\n' && ch != EOF); // Flushing cin

			if (op == 'p')
			{
				std::cout << "\nWhat is the new phone? ";
				std::cin.getline(temp,sizeof(temp));
				std::string phone(temp);
				Student s(name,"",phone,0);
				return s;
			}
			else if (op == 'a')
			{
				std::cout << "\nWhat is the new address? ";
				std::cin.getline(temp,sizeof(temp));
				std::string address(temp);
				Student s(name,address,"",0);
				return s;
			}
			else if (op == 'i')
			{
				int age;
				std::cout << "\nWhat is the new age? ";
				std::cin >> age;
				Student s(name,"","",age);
				return s;
			}
			else
			{
				std::cout << "\nInvalid Option.";
			} 
		}
	}

	Course new_course_routine()
	{
		std::string code; char op;
		std::cout << "\nCourse code: "; std::cin >> code;
		while(1)
		{
			std::cout << "\nMore info?(y/n): "; std::cin >> op;
			if(op=='y')
			{ 
				char temp[40], ch;

				while ((ch = std::cin.get()) != '\n' && ch != EOF); // Flushing cin

				std::cout << "\nCourse name: "; 
				std::cin.getline(temp,sizeof(temp));
				std::string name(temp);

				std::cout << "\nCourse instructor: ";
				std::cin.getline(temp,sizeof(temp));
				std::string instructor(temp);

				Course c(code,name,instructor);
				return c;
			}
			else if (op=='n')
			{
				Course c(code);
				return c;
			}
			else{
				std::cout << "\nInvalid Option.";
			}
		}
	}

	Course course_update_routine()
	{
		std::string code;
	    std::cout << "\nCourse code: "; std::cin >> code;
		
		while(1)
		{
			char op, temp[40], ch;
			std::cout << "\nWhat do you wish to update? (n = name) (i = instructor): "; 
			std::cin >> op;

			while ((ch = std::cin.get()) != '\n' && ch != EOF); // Flushing cin

			if (op == 'n')
			{
				std::cout << "\nWhat is the new course name? ";
				std::cin.getline(temp,sizeof(temp));
				std::string name(temp);
				Course c(code,name,"");
				return c;
			}
			else if (op == 'i')
			{
				std::cout << "\nWhat is the new course instructor? ";
				std::cin.getline(temp,sizeof(temp));
				std::string instructor(temp);
				Course c(code,"",instructor);
				return c;
			}
			else
			{
				std::cout << "\nInvalid Option.";
			} 
		}
	}
};

#endif