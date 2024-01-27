#pragma once
#include <iostream>
#include <tuple>
#include <string>
#include <algorithm>
//#include "Pay.h"
#include "taxpayer.h"

struct taxinfo
{
	long individ_num = 0;
	taxpayer* payer;
    int size=0;
};

class TaxTable {
private:
    taxinfo* taxpayers = nullptr;
    int count = 0;
public:
    TaxTable() {}

    TaxTable(taxinfo* taxpayers, int count)
    {
        this->count = count;
        this->taxpayers = new taxinfo[count];
        std::copy(taxpayers, taxpayers + count, this->taxpayers);
    }

    ~TaxTable()
    {
        delete[] taxpayers;
    }

    void PlusTaxpayer(taxinfo taxpayer)
    {
        taxinfo* tmp = new taxinfo[count + 1];
        std::copy(this->taxpayers, this->taxpayers, tmp);
        tmp[count] = taxpayer;
        delete[] taxpayers;
        taxpayers = tmp;
        tmp = nullptr;
        count++;
    }

    taxinfo* GetTaxpayers() const
    {
        taxinfo* tmp = new taxinfo[count];
        std::copy(this->taxpayers, this->taxpayers + count, tmp);
        return tmp;
    }

    int GetCount() const
    {
        return this->count;
    }
};

class TaxTableIterator
{
private:
    taxinfo* taxpayers;
    int currentIndex;
    int count;

public:
    TaxTableIterator(taxinfo* taxpayers, int count) : taxpayers(taxpayers), currentIndex(0), count(count) {}

    bool HasNext() const
    {
        return currentIndex < count;
    }

    taxpayer* GetNext()
    {
        if (HasNext())
        {
            return taxpayers[currentIndex++].payer;
        }
        else
        {
            std::cout << "No more taxpayers." << std::endl;
            return nullptr;
        }
    }
};

class App
{
private:
    TaxTable taxtable;
public:
    App(TaxTable taxtable) :taxtable(taxtable) {}

    App() {}

    void ChangeTaxPayer(int id_num)
    {
        int n = -1;
        for (int i = 0; i < taxtable.GetCount(); i++)
        {
            if (taxtable.GetTaxpayers()[i].individ_num == id_num)
            {
                n = i;
                break;
            }
        }

        if (n == -1)
        {
            std::cout << "Taxpayer with ID " << id_num << " not found." << std::endl;
            return;
        }

        std::cout << "1. Change FIO" << std::endl << "2. Change workplace" << std::endl << "3. Change positions" << std::endl << "4. Taxpayer type" << std::endl;
        int num;
        std::cout << "Press: ";
        std::cin >> num;

        switch (num)
        {
        case 1:
        {
            if (dynamic_cast<contract_soldier*>(taxtable.GetTaxpayers()[n].payer))
            {
                Full_name new_name(Create_name());
                taxtable.GetTaxpayers()[n].payer->SetFIO(new_name);
            }
            else if (dynamic_cast<employee*>(taxtable.GetTaxpayers()[n].payer))
            {
                Full_name new_name(Create_name());
                taxtable.GetTaxpayers()[n].payer->SetFIO(new_name);
            }
            break;
        }
        case 2:
        {
            std::string new_workplace;
            std::cout << "Enter new workplace: ";
            std::cin >> new_workplace;
            taxtable.GetTaxpayers()[n].payer->SetWorkplace(new_workplace);
            break;
        }
        case 3:
        {
            std::string new_position;
            std::cout << "Enter new position: ";
            std::cin >> new_position;
            taxtable.GetTaxpayers()[n].payer->SetPosition(new_position);
            break;
        }
        case 4:
        {
            std::string new_taxpayer_type;
            std::cout << "Enter new taxpayer type: ";
            std::cin >> new_taxpayer_type;
            taxtable.GetTaxpayers()[n].payer->SetTaxPayerType(new_taxpayer_type);
            break;
        }
        default:
        {
            std::cout << "Invalid input." << std::endl;
        }
        }
    }

    void AddTaxpayerRecord()
    {
        long individ_num;
        std::cout << "Enter individual number: ";
        std::cin >> individ_num;
        int taxpayerType;
        std::cout << "Select taxpayer type:" << std::endl;
        std::cout << "1. Contract Soldier" << std::endl;
        std::cout << "2. Employee" << std::endl;
        std::cout << "Enter choice (1 or 2): ";
        std::cin >> taxpayerType;
        taxpayer* newTaxpayer = nullptr;
        if (taxpayerType == 1)
        {
            contract_soldier* newContractSoldier = new contract_soldier();
            newTaxpayer = newContractSoldier;
        }
        else if (taxpayerType == 2)
        {
            employee* newEmployee = new employee();
            newTaxpayer = newEmployee;
        }
        else
        {
            std::cout << "Invalid choice." << std::endl;
            return;
        }
        taxinfo newTaxInfo;
        newTaxInfo.individ_num = individ_num;
        newTaxInfo.payer = newTaxpayer;
        taxtable.PlusTaxpayer(newTaxInfo);

        std::cout << "Taxpayer record added successfully." << std::endl;
    }

    double CalculateTaxForTaxpayer(const taxpayer& taxPayer)
    {
        for (int i = 0; i < taxPayer.GetSize(); i++);
        double tax = taxPayer. * 0, 13
            return tax;
    }

    taxpayer MaxTaxPayer()
    {
        taxtable.GetTaxpayers();
    }

};
