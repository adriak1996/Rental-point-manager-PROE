#include<vector>
#include<iostream>
#include<string>
#include<cstring>

#include"../Headers/commodity.h"


Commodity::Commodity()
{
    status = true;
    type=0;
    id_customer=0;
}

Suit::Suit()
{
    status = true;
    type=1;
    tie_or_bow = true;
    id_customer=0;

}

Dress::Dress()
{
    dress_length = 80;
    type=2;
    id_customer=0;

}

Wedding_dress::Wedding_dress()
{
    veil_length = 40;
    type=3;
    id_customer=0;

}


Suit::Suit(std::string a, bool b)
{
    status = true;
    commodity_name=a;
    tie_or_bow = b;
    type=1;
    id_customer=0;

}

Dress::Dress(std::string a, float b)
{
    status = true;
    commodity_name=a;
    dress_length=b;
    type=2;
    id_customer=0;
}

Wedding_dress::Wedding_dress(std::string a, float b, float c)
{
    status = true;
    commodity_name=a;
    dress_length=b;
    veil_length=c;
    type=3;
    id_customer=0;
}


Suit::Suit(const Suit &p)
{
    commodity_name = p.commodity_name;
    status=p.status;
    tie_or_bow=p.tie_or_bow;
    type=p.type;
    id_customer=p.id_customer;
}

Suit::Suit(const Suit* p)
{
    commodity_name = p->commodity_name;
    status=p->status;
    tie_or_bow=p->tie_or_bow;
    type=p->type;
    id_customer=p->id_customer;

}

Dress::Dress(const Dress &p)
{
    commodity_name = p.commodity_name;
    status=p.status;
    dress_length=p.dress_length;
    type=p.type;
    id_customer=p.id_customer;
}

Dress::Dress(const Dress* p)
{
    commodity_name = p->commodity_name;
    status=p->status;
    dress_length=p->dress_length;
    type=p->type;
    id_customer=p->id_customer;

}

Wedding_dress::Wedding_dress(const Wedding_dress &p)
{
    commodity_name = p.commodity_name;
    status=p.status;
    dress_length=p.dress_length;
    veil_length=p.veil_length;
    type=p.type;
    id_customer=p.id_customer;
}

Wedding_dress::Wedding_dress(const Wedding_dress* p)
{
    commodity_name = p->commodity_name;
    status=p->status;
    dress_length=p->dress_length;
    veil_length=p->veil_length;
    type=p->type;
    id_customer=p->id_customer;

}

Commodity::~Commodity()
{

}

Suit::~Suit()
{

}

Dress::~Dress()
{

}

Wedding_dress::~Wedding_dress()
{

}



Commodity& Commodity::operator=(const Commodity &p)
{
    commodity_name = p.commodity_name;
    status=p.status;
    type=p.type;
    id_customer=p.id_customer;
    return *this;

}

Commodity& Commodity::operator+=(const Commodity &p)
{
    commodity_name+=" "+ p.commodity_name;
    status=true;
    type=p.type;
    id_customer=p.id_customer;
    return *this;

}

Suit& Suit::operator=(const Suit &p)
{
    commodity_name = p.commodity_name;
    status=p.status;
    tie_or_bow=p.tie_or_bow;
    type=p.type;
    id_customer=p.id_customer;
    return *this;

}

Dress& Dress::operator=(const Dress &p)
{
    commodity_name = p.commodity_name;
    status=p.status;
    dress_length=p.dress_length;
    type=p.type;
    id_customer=p.id_customer;
    return *this;

}

Wedding_dress& Wedding_dress::operator=(const Wedding_dress &p)
{
    commodity_name = p.commodity_name;
    status=p.status;
    dress_length=p.dress_length;
    veil_length=p.veil_length;
    type=p.type;
    id_customer=p.id_customer;
    return *this;

}



void Suit::serialize(std::ostream& stream) const
{
    // Serialization code
    stream << type;
    stream << "\n";

    stream << commodity_name;

    stream << "\n";
    stream << status;
    stream << "\n";
    stream << type;
    stream << "\n";
    stream << id_customer;
    stream << "\n";
    stream << tie_or_bow;
    stream << "\n";
}

void Suit::deserialize(std::istream& stream)
{

    // Deserialization code

    stream >> commodity_name;
    stream >> status;
    stream >> type;
    stream >> id_customer;
    stream >> tie_or_bow;
}

void Suit::show_tests()
{


    std::cout<<"Type of the commodity\t\t: Suit"<<std::endl;
    std::cout<<"Name of the suit\t\t: "<<commodity_name<<std::endl;
    if(tie_or_bow==true) std::cout<<"Selected addition\t\t: Tie"<<std::endl;
    else std::cout<<"Selected addition\t\t: Bow-tie"<<std::endl;
    if(status==true) std::cout<<"Current status\t: Available"<<std::endl;
    else std::cout<<"Current status\t: Rented"<<std::endl;


}

void Suit::edit_commodity()
{
    char a;
    std::cout<<"********************************************************************************"<<std::endl;
    std::cout<<"Details of the selected commodity"<<std::endl;
    std::cout<<"________________________________________________________________________________"<<std::endl;
    std::cout<<"Type of the commodity\t\t: Suit"<<std::endl;
    std::cout<<"Name of the suit\t\t: "<<commodity_name<<std::endl;
    if(tie_or_bow==true) std::cout<<"Selected addition\t\t: Tie"<<std::endl;
    else std::cout<<"Selected addition\t\t: Bow-tie"<<std::endl;
    std::cout<<"********************************************************************************"<<std::endl;

    std::cout<<"Do you want to change name of commodity? If yes press [a]. Otherwise, press whatever apart from [a]."<<std::endl;
    std::cin>>a;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    if(a=='a')
    {
        std::cout<<"Type new name of the commodity"<<std::endl;
        std::getline(std::cin,commodity_name);
    }
    std::cout<<"Do you want to change current addition for the second one?. If yes press [a]. Otherwise, press whatever apart from [a]."<<std::endl;
    std::cin>>a;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    if(a=='a') tie_or_bow=(!(tie_or_bow));

}

void Dress::serialize(std::ostream& stream) const
{
    // Serialization code
    stream << type;
    stream << "\n";
    stream << commodity_name;
    stream << "\n";
    stream << status;
    stream << "\n";
    stream << type;
    stream << "\n";
    stream << id_customer;
    stream << "\n";
    stream << dress_length;
    stream << "\n";
}

void Dress::deserialize(std::istream& stream)
{
    // Deserialization code
    stream >> commodity_name;
    stream >> status;
    stream >> type;
    stream >> id_customer;
    stream >> dress_length;
}

void Dress::show_tests()
{
    std::cout<<"Type of the commodity\t\t: Dress"<<std::endl;
    std::cout<<"Name of the dress\t\t: "<<commodity_name<<std::endl;
    std::cout<<"Length of the dress [cm]\t: "<<dress_length<<std::endl;
    if(status==true) std::cout<<"Current status\t: Available"<<std::endl;
    else std::cout<<"Current status\t: Rented"<<std::endl;
}

void Dress::edit_commodity()
{
    char a;
    std::cout<<"********************************************************************************"<<std::endl;
    std::cout<<"Details of the selected commodity"<<std::endl;
    std::cout<<"________________________________________________________________________________"<<std::endl;
    std::cout<<"Type of the commodity\t\t: Dress"<<std::endl;
    std::cout<<"Name of the dress\t\t: "<<commodity_name<<std::endl;
    std::cout<<"Length of the dress [cm]\t: "<<dress_length<<std::endl;
    std::cout<<"********************************************************************************"<<std::endl;

    std::cout<<"Do you want to change name of commodity? If yes press [a]. Otherwise, press whatever apart from [a]."<<std::endl;
    std::cin>>a;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    if(a=='a')
    {
        std::cout<<"Type new name of the commodity"<<std::endl;
        std::getline(std::cin,commodity_name);
    }

    std::cout<<"Do you want to change length of the dress? If yes press [a]. Otherwise, press whatever apart from [a]."<<std::endl;
    std::cin>>a;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    if(a=='a')
    {
        std::cout<<"Type new length of the dress"<<std::endl;
        std::cin>>dress_length;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

}

void Wedding_dress::serialize(std::ostream& stream) const
{
    // Serialization code
    stream << type;
    stream << "\n";
    stream << commodity_name;
    stream << "\n";
    stream << status;
    stream << "\n";
    stream << type;
    stream << "\n";
    stream << id_customer;
    stream << "\n";
    stream << dress_length;
    stream << "\n";
    stream << veil_length;
    stream << "\n";
}

void Wedding_dress::deserialize(std::istream& stream)
{
    stream >> commodity_name;
    stream >> status;
    stream >> type;
    stream >> id_customer;
    stream >> dress_length;
    stream >> veil_length;
}

void Wedding_dress::show_tests()
{
    std::cout<<"Type of the commodity\t\t: Wedding dress"<<std::endl;
    std::cout<<"Name of the dress\t\t: "<<commodity_name<<std::endl;
    std::cout<<"Length of the dress [cm]\t: "<<dress_length<<std::endl;
    std::cout<<"Length of the veil [cm]\t: "<<veil_length<<std::endl;
    if(status==true) std::cout<<"Current status\t: Available"<<std::endl;
    else std::cout<<"Current status\t: Rented"<<std::endl;
}

void Wedding_dress::edit_commodity()
{
    char a;
    std::cout<<"********************************************************************************"<<std::endl;
    std::cout<<"Details of the selected commodity"<<std::endl;
    std::cout<<"________________________________________________________________________________"<<std::endl;
    std::cout<<"Type of the commodity\t\t: Wedding dress"<<std::endl;
    std::cout<<"Name of the dress\t\t: "<<commodity_name<<std::endl;
    std::cout<<"Length of the dress [cm]\t: "<<dress_length<<std::endl;
    std::cout<<"Length of the veil [cm]\t: "<<veil_length<<std::endl;
    std::cout<<"********************************************************************************"<<std::endl;

    std::cout<<"Do you want to change name of commodity? If yes press [a]. Otherwise, press whatever apart from [a]."<<std::endl;
    std::cin>>a;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    if(a=='a')
    {
        std::cout<<"Type new name of the commodity"<<std::endl;
        std::getline(std::cin,commodity_name);
    }

    std::cout<<"Do you want to change length of the dress? If yes press [a]. Otherwise, press whatever apart from [a]."<<std::endl;
    std::cin>>a;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    if(a=='a')
    {
        std::cout<<"Type new length of the dress"<<std::endl;
        std::cin>>dress_length;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    std::cout<<"Do you want to change length of the veil? If yes press [a]. Otherwise, press whatever apart from [a]."<<std::endl;
    std::cin>>a;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    if(a=='a')
    {
        std::cout<<"Type new length of the veil"<<std::endl;
        std::cin>>veil_length;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
}

bool operator<(const Commodity &p, const Commodity &r)
{

    return p.commodity_name<r.commodity_name;

}

bool operator==(const Commodity &p, const Commodity &r)
{
    return p.commodity_name==r.commodity_name;

}



