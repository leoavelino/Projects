#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "headers.hpp"
#include "interface.hpp"
using namespace std;

int main()
{
	Interface i; int n;
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
