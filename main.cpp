#include <iostream>
#include "taxpayer.h"
#include "Pay.h"
#include "table.h"
#include <tuple>

int main()
{
	std::string x;
	char y, z;
	std::cin >> x >> y >> z;
	Full_name FIO(x, y, z);
	auto mydata = FIO.GetFullName();
	std::tie(x, y, z) = mydata;
	std::cout << "Data: " << x << "." << y << "." << z << std::endl;
}