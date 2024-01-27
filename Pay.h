#pragma once
#include <iostream>
#include <tuple>

class date
{
private:
	int day = 1;
	int month = 1;
	int year = 1999;
public:
	void SetDate(int x, int y, int z)
	{
		if ((z <= 2023 || z >= 1999) && (x >= 1 || x <= 31) && (y >= 1 || y <= 12))
		{
			year = z;
			if (z == 2024 && y == 1 && x <= 27)
			{
				year = z;
			}
			if (year == z)
			{
				month = y;
			}
			else
			{
				year = 1999;
				std::cout << "Invalid data";
				return;
			}
			if ((y == 4 || y == 6 || y == 9 || y == 11) && x <= 30)
			{
				day = x;
			}
			if (y == 2 && z % 4 == 0 && x <= 29)
			{
				day = x;
			}
			if (y == 2 && z % 4 != 0 && x <= 28)
			{
				day = x;
			}
			if (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12)
			{
				day = x;
			}
		}
		else
		{
			std::cout << "Invalid data";
			return;
		}
		if (day != x || month != y || year != z)
		{
			year = 1999;
			month = 1;
			day = 1;
			std::cout << "Invalid data";
			return;
		}
	}
	date(const date& other) : day(other.day), month(other.month), year(other.year) {}
	date() :day(1), month(1), year(1999) {}
	date(int x, int y, int z)
	{
		if ((z <= 2023 || z >= 1999) && (x >= 1 || x <= 31) && (y >= 1 || y <= 12))
		{
			year = z;
			if (z == 2024 && y == 1 && x <= 27)
			{
				year = z;
			}
			if (year == z)
			{
				month = y;
			}
			else
			{
				year = 1999;
				std::cout << "Invalid data";
				return;
			}
			if ((y == 4 || y == 6 || y == 9 || y == 11) && x <= 30)
			{
				day = x;
			}
			if (y == 2 && z % 4 == 0 && x <= 29)
			{
				day = x;
			}
			if (y == 2 && z % 4 != 0 && x <= 28)
			{
				day = x;
			}
			if (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12)
			{
				day = x;
			}
		}
		else
		{
			std::cout << "Invalid date";
			return;
		}
		if (day != x || month != y || year != z)
		{
			year = 1999;
			month = 1;
			day = 1;
			std::cout << "Invalid date";
			return;
		}
	}

	int GetDay()
	{
		return this->day;
	}

	int GetMonth()
	{
		return this->month;
	}

	int GetYear()
	{
		return this->year;
	}

	bool operator==(const date& other) const
	{
		return std::tie(day, month, year) == std::tie(other.day, other.month, other.year);
	}

	bool operator>=(const date& other) const
	{
		return std::tie(day, month, year) >= std::tie(other.day, other.month, other.year);
	}

	bool operator<=(const date& other) const
	{
		return std::tie(day, month, year) <= std::tie(other.day, other.month, other.year);
	}

	bool operator!=(const date& other) const
	{
		return std::tie(day, month, year) != std::tie(other.day, other.month, other.year);
	}

	bool operator>(const date& other) const
	{
		return std::tie(day, month, year) > std::tie(other.day, other.month, other.year);
	}

	bool operator<(const date& other) const
	{
		return std::tie(day, month, year) < std::tie(other.day, other.month, other.year);
	}

	~date() {}
};

class pay
{
private:
	date data;
	std::string pay_type;
	int summ;
public:
	pay(const pay& other) : data(other.data), pay_type(other.pay_type), summ(other.summ) {}

	pay() :summ(0), pay_type(nullptr) {}

	date GetDate()
	{
		return this->data;
	}

	std::string GetPayType()
	{
		return this->pay_type;
	}

	int GetSumm()
	{
		return this->summ;
	}

	void Setpay(date data, std::string& type, int summ)
	{
		this->data = data;
		this->pay_type = type;
		this->summ = summ;
	}
	~pay() {}
};
