#pragma once

#include"..\Headers\serialization.h"

///Klasa customera jest pochodną klasy Serializable. W obiekcie klasy Rental mamy kontener z obiektami klas Customer.
///Istnienie tego kontenera oraz klasy umożliwia programowi gromadzenie danych na temat customerów oraz funkcjom zaimplementowanym
///w obiekcie klasy Rental pozwala na zarządzanie tymi danymi. Każdy obiekt klasy Customer zawiera informacje o nameniu
///i nazwisku customera oraz ilość commodityu jaki wypożycza.

class Customer: public Serializable
{

private:
    int num_of_commodities;
    std::string name;
    std::string surname;
    friend class Rental;

public:
    Customer();
    Customer(std::string, std::string);
    Customer(std::string a, std::string b, int c);
    Customer(const Customer &);
    ~Customer();

    Customer& operator=(const Customer &);
    Customer& operator+(const Customer &);
    bool operator==(const Customer &);

    ///Funkcja wpisuje kaskadowo do pliku dane obiektu klasy Customer
    void serialize(std::ostream& stream) const;
    ///Funkcja wypisuje kaskadowo z pliku dane obiektu klasy Customer
    void deserialize(std::istream& stream);
    ///Funkcja wyświetla dane obiekty klasy Obiekt (jako parametr podajemy referencję do obiektu klasy Customer)
    void show_tests(const Customer &);
    ///Funkcja umożliwia edycję danych obiekty klasy Customer (wewnątrz jest uzyskiwany potrzebny parametr)
    void edit_customer();
    ///Funckja porównuje dwa obiekty klasy Customer na podstawie ilości wypożyczanych commodityów
    void compare_customers(Customer &p, Customer &r);




};
