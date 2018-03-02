#ifndef SERIALIZATION_H_
#define SERIALIZATION_H_

///Klasa Serializable jest klasą abstrakcyjną, która zawiera dwie główne wirtualne funkcje odpowiedzialne za kolejno
///wczytywanie i odczyt danych do i z pliku. Dziedziczą po niej te funckje klasy: Rental, Customer oraz Commodity i klasy pochodne Commodityu.
///Celem istnienia tej funkcji jest zatem umożliwienie zapisu i odczytu kaskadowego w postaci binarnej bez użycia specjalnych
///bibliotek do tego przeznaczonych.
class Serializable
{
public:
    Serializable(){}
    virtual ~Serializable(){}

    ///Funkcja wirtualna abstrakcyjna. Jej klasy pochodne służą do wczytywania danych oraz klas do pliku w katalogu
    virtual void serialize(std::ostream& stream) const = 0;
    ///Funkcja wirtualna abstrakcyjna. Jej klasy pochodne służą do wyczytywania danych oraz klas z pliku w katalogu
    virtual void deserialize(std::istream& stream) = 0;
};

#endif /* SERIALIZATION_H_ */
