#include<vector>
#include<iostream>

#include"..\Headers\register.h"


Register::Register()
{
    id_customer=0;
    id_commodity=0;


}

Register::Register(int a, int b)
{
    id_customer=a;
    id_commodity=b;


}

Register::Register(const Register &p)
{
    id_customer = p.id_customer;
    id_commodity = p.id_commodity;

}

Register::~Register()
{



}

Register& Register::operator=(const Register &p)
{

    id_customer = p.id_customer;
    id_commodity = p.id_commodity;

    return *this;

}

       void Register::serialize(std::ostream& stream) const
    {
        // Serialization code
        stream << id_register_list;
        stream << "\n";
        stream << id_customer;
        stream << "\n";
        stream << id_commodity;
        stream << "\n";
    }

    void Register::deserialize(std::istream& stream)
    {
        // Deserialization code
        stream >> id_register_list;
        stream >> id_customer;
        stream >> id_commodity;
    }

