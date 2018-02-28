#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "facade.hpp"
#include "interface.hpp"
using namespace std;

int main()
{
	Interface i; int n;


	Student s1("amanda"), s2("leonardo"), s3("jose"), s4("fernando");
	Course c1("101"), c2("110"), c3("201"), c4("210");

	i.f->student_management(s1, "new"); i.f->student_management(s2, "new");
	i.f->student_management(s3, "new"); i.f->student_management(s4, "new");

	i.f->course_management(c1, "new"); i.f->course_management(c2, "new");
	i.f->course_management(c3, "new"); i.f->course_management(c4, "new");

	// Registration r1(s1,c1), r2(s2,c1), r3(s3,c1), r4(s4,c1),
	// 				r5(s2, c2), r6(s3,c2), r7(s4,c2),
	// 				r8(s1,c3), r9(s3,c3),
	// 				r10(s2,c4), r11(s3,c4);

	i.f->registration_management("amanda", "101", "new");
	i.f->registration_management("amanda", "201", "new");
	i.f->registration_management("amanda", "110", "new");
	i.f->registration_management("amanda", "210", "new");
	i.f->registration_management("leonardo", "101", "new");
	i.f->registration_management("leonardo", "210", "new");
	i.f->registration_management("leonardo", "110", "new");
	i.f->registration_management("jose", "101", "new");
	i.f->registration_management("jose", "110", "new");
	i.f->registration_management("fernando", "101", "new");
	i.f->registration_management("fernando", "210", "new");


	while(1)
	{
		i.main_menu(); cin >> n;
		if (n == 23)
			break;
		i.input(n);
		
		while (cin.get() != '\n');
		cout << "\n (press ENTER to continue...)";
		while (cin.get() != '\n');
	}
	
	return 0;
}
