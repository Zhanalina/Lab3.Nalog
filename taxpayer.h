#pragma once
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include "Pay.h"

class Full_name
{
private:
	std::string surname = "";
	char name = 0;
	char sec_name = 0;
public:
	Full_name() : surname(""), name(0), sec_name(0) {}

	Full_name(const std::string& surname,const char name,const char sec_name)
	{
		if (surname.empty())
		{
			return;
		}
		for (int i = 0; surname[i] != '\0'; i++)
		{
			if ((surname[i] < 'A' || surname[i] > 'Z') && (surname[i] < 'a' || surname[i] > 'z'))
			{
				return;
			}
		}
		if ((name < 'A' || (name > 'Z' && name < 'a') || name > 'z') || (sec_name < 'A' || (sec_name > 'Z' && sec_name < 'a') || sec_name > 'z'))
		{
			return;
		}
		this->surname = surname;
		if (surname[0] >= 'a')
		{
			this->surname[0] = surname[0] - 32;
		}
		if (name >= 'a')
		{
			this->name = name-32;
		}
		else
		{
			this->name = name;
		}
		if (sec_name >= 'a')
		{
			this->sec_name = sec_name - 32;
		}
		else
		{
			this->sec_name = sec_name;
		}
	}

	Full_name(const Full_name& other) : surname(other.surname), name(other.name), sec_name(other.sec_name) {}

	void SetFullName(const Full_name& other)
	{
		this->surname = other.surname;
		this->name = other.name;
		this->sec_name = other.sec_name;
	}

	std::tuple<const std::string, const char, const char> GetFullName()
	{
		return std::make_tuple(surname, name, sec_name);
	}

	~Full_name() {}
};

class taxpayer
{
protected:
	Full_name FIO;
	std::string workplace = nullptr;
	std::string position = nullptr;
	std::string taxpayer_type = nullptr;
	pay* pays = nullptr;
	int size = 0;
public:
	taxpayer() : workplace(nullptr), position(nullptr), taxpayer_type(nullptr), pays(nullptr),  size(0){}

	
	taxpayer(Full_name FIO, std::string place, std::string pos, pay* pays, int size, std::string taxpayer_type)
	{
		this->workplace = place;
		this->FIO = FIO;
		this->size = size;
		this->pays = new pay[this->size];
		std::copy(pays, pays + size, this->pays);
		this->taxpayer_type = taxpayer_type;
	}
	
	Full_name GetFullName()
	{
		return this->FIO;
	}

	void SetFIO(Full_name FIO)
	{
		this->FIO.SetFullName(GetFullName());
	}

	virtual void PrintInfo()
	{
		std::string x;
		char y, z;
		auto fio = FIO.GetFullName();
		std::tie(x, y, z) = fio;
		std::cout << "Full Name: " << x << "." << y << "." << z << std::endl;
		std::cout << "Place of work: " << workplace << std::endl;
		std::cout << "Position: " << position << std::endl;
		std::cout << "Type: " << taxpayer_type << std::endl;
	}
	
	void SetWorkplace(std:: string workplace)
	{
		this->workplace = workplace;
	}

	void SetPosition(std::string position)
	{
		this->position = position;
	}

	void SetTaxPayerType(std::string taxpayer_type)
	{
		this->taxpayer_type = taxpayer_type;
	}

	std::string GetTaxPayer()
	{
		return this->taxpayer_type;
	}
	
	std::string GetWorkplace()
	{
		return this->workplace;
	}
	
	pay* GetPays()
	{
		pay* tmp = new pay[size];
		std::copy(this->pays, this->pays + size, tmp);
		return tmp;
	}

	int GetSize()
	{
		return this->size;
	}

	int YearPayments(std::string type)
	{
		int yearpay=0;
		for (int i = 0; i < this->size; i++)
		{
			date last_year(26, 1, 2023);
			if (pays[i].GetPayType() == type)
			{
				if (pays[i].GetDate() >= last_year)
				{
					yearpay += pays[i].GetSumm();
				}
			}
		}
		return yearpay;
	}

	~taxpayer()
	{
		delete[] pays;
	}
};

class contract_soldier : public taxpayer
{
private:
	int contract_num = 0;
public:
	contract_soldier(int c_num, Full_name FIO, std::string place, std::string pos, pay* pays, int size, std::string taxpayer_type)
	{
		this->contract_num = c_num;
		taxpayer(FIO, place, pos, pays, size, taxpayer_type);
	}	 
	
	contract_soldier() :contract_num(0) {}
	
	int GetNum()
	{
		return contract_num;
	}
	
	void PlusPay(pay dop_pay)
	{
		pay* tmp = new pay[size + 1];
		std::copy(pays, pays + size, tmp);
		tmp[size] = dop_pay;
		delete[] pays;
		pays = tmp;
		tmp = nullptr;
		size++;
	}

	~contract_soldier(){}
};

class employee : public taxpayer
{
private:
	const int contract_num = 0;
public:
	employee(Full_name FIO, std::string place, std::string pos, pay* pays, int size, std::string taxpayer_type)
	{
		this->workplace = place;
		this->FIO = FIO;
		this->size = size;
		this->pays = new pay[this->size];
		std::copy(pays, pays + size, this->pays);
		this->taxpayer_type = taxpayer_type;
	}

	employee() :contract_num(0) {}

	int GetNum()
	{
		return contract_num;
	}
	
	void PlusPay(pay dop_pay)
	{
		pay* tmp = new pay[size + 1];
		std::copy(pays, pays + size, tmp);
		tmp[size] = dop_pay;
		delete[] pays;
		pays = tmp;
		tmp = nullptr;
		size++;
	}

	~employee() {}
};

Full_name Create_name();