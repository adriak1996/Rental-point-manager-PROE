#pragma once

#include"..\Headers\serialization.h"

///Klasa Register jest klasą pochodną klasy Serializable oraz nie jest ona klasą abstrakcyjną.
///Kontener zawierający obiekty tej klasy znajdujący się w obiektcie klasy Rental oraz klasa Register
///służy do gromadzenia danych o aktualnych wypożyczeniach (czyli informacje jaki customer jaki commodity wypożycza).
///Klasa ta zawiera informacje o numerach klejno, customera oraz commodityu. Numery te oznaczają kolejność tych obiektów
///(licząc od 1, nie od 0!) w odpowiednich kontenerach zawierających customerów oraz commodityy.

class Register: public Serializable
{

private:
    int id_register_list;
    int id_customer, id_commodity;
    friend class Rental;

public:
    Register();
    Register(int, int);
    Register(const Register &);
    ~Register();
    Register& operator=(const Register &);

    ///Funkcja wpisuje kaskadowo do pliku dane obiektu klasy Register
    void serialize(std::ostream&) const;
    ///Funkcja wypisuje kaskadowo z pliku dane obiektu klasy Register
    void deserialize(std::istream&);




};
