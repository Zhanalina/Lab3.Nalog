#include <iostream>
#include <tuple>
#include <string>
#include <vector>
//#include "Pay.h"
//#include "taxpayer.h"
#include "table.h"

Full_name Create_name()
{
	std::string surname;
	char name;
	char sec_name;
	std::cin >> surname;
	std::cin >> name;
	std::cin >> sec_name;
	Full_name FIO(surname, name, sec_name);
	return FIO;
}