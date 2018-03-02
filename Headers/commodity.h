#pragma once

#include"..\Headers\serialization.h"

///Klasa Commodity jest klasą abstrakcyjną oraz klasą pochodną klasy Serializable. W obiekcie klasy Rental mamy kontener z wskaźnikami na obiekty tej klasy.
///Celem tego zabiegu jest umożliwienie stworzenia tablicy zawierającej obiekty pochodne, jednakże bez możliwości dodania
///obiektu klasy bazowej. Rolą tej klasy oraz kontenera z wskażnikami na obiekty jej klas pochodnych jest gromadzenie informacji
///o commodityach istniejących w wypożyczalni oraz możliwość zarządzania nimi za pośrednictwem metod z klasy Rental
///Każdy obiekt klasy Commodity oraz jego pochodne zawierają informacje o tym czy commodity jest aktualnie wypożyczony, jego type (czyli jaką klasą pochodną jest),
///numer kolejności customera w kontenerze z customerami (licząc od 1, nie od 0!) oraz oczywiście nazwę commodityu.

class Commodity: public Serializable
{

protected:
    bool status; // true - available, false - rented;
    int type;
    int id_customer;
    std::string commodity_name;
    friend class Rental;

public:
    Commodity();
    virtual ~Commodity();

    Commodity& operator=(const Commodity &);
    Commodity& operator+=(const Commodity &);
    friend bool operator<(const Commodity &,const Commodity &);
    friend bool operator==(const Commodity &,const Commodity &);

    ///Funkcja wirtualna abstrakcyjna. Jej funkcje pochodne służą do wyświetlania danych zawartych w obiektach klas które dziedziczą po klasie Commodity
    virtual void show_tests()=0;
    ///Funkcja wirtualna abstrakcyjna. Jej funkcje pochodne służą do edytowania danych zawartych w obiektach klas które dziedziczą po klasie Commodity
    virtual void edit_commodity()=0;
    ///Funkcja wirtualna abstrakcyjna. Jej klasy pochodne służą do wczytywania danych oraz klas do pliku w katalogu
    virtual void serialize(std::ostream& stream) const=0;
    ///Funkcja wirtualna abstrakcyjna. Jej klasy pochodne służą do wyczytywania danych oraz klas z pliku w katalogu
    virtual void deserialize(std::istream& stream)=0;

};

///Klasa Suit jest pochodną klasy Commodity oraz nie jest ona klasą abstrakcyjną. Służy ona podziałowi commodityu na różne typey
///które są opisywane przez różniące się zmienne. Klasa ta jest przykładem dziedziczenia, a funkcje w niej zaimplementowane polimorfizmu.
///Obiekt klasy różni się tym od obiektu klasy Commodity tym, że zawiera informacje czy dany commodity (tutaj garnitur) posiada muszkę czy też krawat jako dodatek.

class Suit: public Commodity
{

private:
    bool tie_or_bow;
    friend class Rental;

public:
    Suit();
    Suit(std::string, bool);
    Suit(const Suit &);
    Suit(const Suit* );
    ~Suit();

    Suit& operator=(const Suit &);

    ///Funkcja wpisuje kaskadowo do pliku dane obiektu klasy Suit
    void serialize(std::ostream& stream) const;
    ///Funkcja wypisuje kaskadowo z pliku dane obiektu klasy Suit
    void deserialize(std::istream& stream);
    ///Funkcja wyświetla zawartość obiektu klasy Suit (wewnątrz jest uzyskiwany potrzebny paramter)
    void show_tests();
    ///Funkcja umożliwia edycję danych obiekty klasy Suit (wewnątrz jest uzyskiwany potrzebny parametr)
    void edit_commodity();


};


///Klasa Dress jest pochodną klasy Commodity oraz nie jest ona klasą abstrakcyjną. Służy ona podziałowi commodityu na różne typey
///które są opisywane przez różniące się zmienne. Klasa ta jest przykładem dziedziczenia, a funkcje w niej zaimplementowane polimorfizmu.
///Obiekt tej klasy (tutaj sukienka ślubna) różni się tym od obiektu klasy Commodity, że zawiera informacje o dlugości sukienki.

class Dress: public Commodity
{

protected:
    float dress_length;
    friend class Rental;

public:
    Dress();
    Dress(std::string, float);
    Dress(const Dress &);
    Dress(const Dress* );
    ~Dress();

    Dress& operator=(const Dress &);

    ///Funkcja wpisuje kaskadowo do pliku dane obiektu klasy Dress
    void serialize(std::ostream& stream) const;
    ///Funkcja wypisuje kaskadowo z pliku dane obiektu klasy Dress
    void deserialize(std::istream& stream);
    ///Funkcja wyświetla zawartość obiektu klasy Dress (wewnątrz jest uzyskiwany potrzebny paramter)
    void show_tests();
    ///Funkcja umożliwia edycję danych obiekty klasy Dress (wewnątrz jest uzyskiwany potrzebny parametr)
    void edit_commodity();


};

///Klasa Wedding_dress jest pochodną klasy Sukienka oraz nie jest ona klasą abstrakcyjną. Służy ona głównie uszczegółowieniu klasy Dress.
/// Klasa ta jest przykładem dziedziczenia, a funkcje w niej zaimplementowane polimorfizmu.
///Obiekt tej klasy (tutaj sukienka ślubna) różni się tym od obiektu klasy Dress, że zawiera informacje o dlugości welonu.

class Wedding_dress: public Dress
{

private:
    float veil_length;
    friend class Rental;

public:
    Wedding_dress();
    Wedding_dress(std::string, float, float);
    Wedding_dress(const Wedding_dress &);
    Wedding_dress(const Wedding_dress* );
    ~Wedding_dress();

    Wedding_dress& operator=(const Wedding_dress &);

    ///Funkcja wpisuje kaskadowo do pliku dane obiektu klasy Wedding_dress
    void serialize(std::ostream& stream) const;
    ///Funkcja wypisuje kaskadowo z pliku dane obiektu klasy Wedding_dress
    void deserialize(std::istream& stream);
    ///Funkcja wyświetla zawartość obiektu klasy Wedding_dress (wewnątrz jest uzyskiwany potrzebny paramter)
    void show_tests();
    ///Funkcja umożliwia edycję danych obiekty klasy Wedding_dress (wewnątrz jest uzyskiwany potrzebny parametr)
    void edit_commodity();


};
