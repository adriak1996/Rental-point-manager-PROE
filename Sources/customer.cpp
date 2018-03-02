#include<vector>
#include<iostream>
#include<string>

#include"..\Headers\customer.h"


Customer::Customer()
{

    num_of_commodities=0;

}

Customer::Customer(std::string a, std::string b)
{

    num_of_commodities=0;
    name=a;
    surname=b;
}

Customer::Customer(std::string a, std::string b, int c)
{

    num_of_commodities=c;
    name=a;
    surname=b;
}

Customer::Customer(const Customer &p)
{
    name=p.name;
    surname=p.surname;
    num_of_commodities=p.num_of_commodities;

}

Customer::~Customer()
{

}

Customer& Customer::operator=(const Customer &p)
{
    name=p.name;
    surname=p.surname;
    num_of_commodities=p.num_of_commodities;
    return *this;

}

Customer& Customer::operator+(const Customer &p)
{
    num_of_commodities+=num_of_commodities;
    name+=" "+ p.name;
    surname+=" "+p.surname;
    return *this;

}

bool Customer::operator==(const Customer &r)
{
    return (num_of_commodities==r.num_of_commodities);

}

void Customer::serialize(std::ostream& stream) const
{
    // Serialization code
    stream << name;
    stream << "\n";
    stream << surname;
    stream << "\n";
    stream << num_of_commodities;
    stream << "\n";
}

void Customer::deserialize(std::istream& stream)
{
    // Deserialization code
    stream >>name;
    stream >> surname;
    stream >> num_of_commodities;
}

void Customer::compare_customers(Customer &p, Customer &r)
{


    if(p==r)
        std::cout<<"Both the customers have the same amount of rented commodities"<<std::endl;
    else
        std::cout<<"The customers have a different amount of rented commodities"<<std::endl;
}

void Customer::show_tests(const Customer &p)
{
    std::cout<<"Customer:"<<std::endl;
    std::cout<<"Customer's name:"<<std::endl;
    std::cout<<"  "<<p.name<<std::endl;
    std::cout<<"Customer's surname:"<<std::endl;
    std::cout<<"  "<<p.surname<<std::endl;
}

void Customer::edit_customer()
{
    char a;
    std::cout<<"********************************************************************************"<<std::endl;
    std::cout<<"The chosen customer's data"<<std::endl;
    std::cout<<"Name\t\t\t\t: "<<name<<std::endl;
    std::cout<<"Surname\t\t\t: "<<surname<<std::endl;
    std::cout<<"********************************************************************************"<<std::endl;


    std::cout<<"Do you want to change customer's name? If YES type [a], otherwise press any key apart from [a]"<<std::endl;
    std::cin>>a;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    if(a=='a')
    {
        std::cout<<"Type new customer's name"<<std::endl;
        std::getline(std::cin,name);
    }

    std::cout<<"Do you want to change customer's surname? If YES type [a], otherwise press any key apart from [a]"<<std::endl;
    std::cin>>a;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    if(a=='a')
    {
        std::cout<<"Type new customer's surname"<<std::endl;
        std::getline(std::cin,surname);
    }

}



