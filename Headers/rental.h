#pragma once
#ifndef KLIENT_H_
#define KLIENT_H_

#include<string>
#include<vector>
#include<algorithm>
#include <sstream>
#include <fstream>


#include"..\Headers\customer.h"
#include"..\Headers\commodity.h"
#include"..\Headers\register.h"
#include"..\Headers\serialization.h"


/**
* Klasa Rental jest główną klasą aplikacji. Jest ona klasą pochodną klasy Serializable i nie jest klasą abstrakcyjną.
* To ona magazynuje wszelkie potrzebne dane (informacje o customerach,
* commodityach, wypożyczeniach oraz dane statystyczne) oraz dysponuje
* odpowiednimi funkcjami które może obsługiwać użytkownik
* poprzez zaimplementowany interfejs.
*/
class Rental: public Serializable
{

private:

    std::string nazwa;
    std::vector <Commodity*> commodity;
    std::vector <Customer> customer;
    std::vector <Register> register_list;

    int num_all_customers; /*!< Liczba dotychczasowych customerów */
    int num_all_services; /*!< Liczba dotychczasowych wypożyczeń */
    friend class Commodity;
    friend class Customer;
    friend class Register;

public:
    Rental();
    Rental(Rental &);
    Rental(std::string);
    ~Rental();
    Rental& operator=(Rental &);

    friend std::ostream & operator <<( std::ostream & os_, const Register & ex );
    friend std::istream & operator >>( std::istream & is_, Register & ex );

    ///Funkcja wpisuje obiekt Rental do strumienia (pliku).
    virtual void serialize(std::ostream& stream) const;
    ///Funkcja wczytuje obiekt Rental ze strumienia (pliku).
    void deserialize(std::istream& stream);
    ///Funkcja dodaje nowy obiekt klasy Commodity do wypozyczalni.
    void add_commodity();
    ///Funkcja dodaje obiekt klasy Suit do rental (jako parametry podawane są wszystkie zmienne tej klasy). Funkcja sprawdza też czy istnieje commodity o podanych paramtrach. Jeśli istnieje to funkcja umiemożliwia dodadnie identycznego obiektu. Funkcja sortuje również alfabetycznie customerów zaraz po dodaniu nowego obiektu do kontenera. Ponadto zastępuje stary register_list nowym w celu uwzględnienia zmian w kolejności commodityów.
    void add_commodity1(std::string, bool);
    ///Funkcja dodaje obiekt klasy Dress do rental (jako parametry podawane są wszystkie zmienne tej klasy).
    void add_commodity2(std::string, float);
    ///Funkcja dodaje obiekt klasy Dress slubna do rental (jako parametry podawane są wszystkie zmienne tej klasy).
    void add_commodity3(std::string, float, float);
    ///Funkcja pokazuje commodityy w wypozyczalni.
    void show_commodities_list();
    ///Funkcja usuwa określony obiekt klasy Commodity z wypożyczalni (numer usuwanego customera pobierany jest wewnątrz).
    void remove_commodity();
    ///Funkcja usuwa określony obiekt klasy Commodity z wypożyczalni (numer usuwanego customera podawany jako parametr).
    void remove_commodity(int);
    ///Funkcja wyszukuje określony obiekt klasy Commodity do wypożyczalni (jako parametr podawana jest jego nazwa) i zwraca prawdę jeśli taki obiekt istnieje.
    bool find_commodity(std::string);
    ///Funkcja dodaje obiekt klasy Customer do wypozyczalni(parametry customera uzyskiwane są wewnątrz funkcji).
    void add_customer();
    ///Funkcja dodaje obiekt klasy Customer z wypozyczlani (parametry customera czyli imię i surname podawane są jako parametry). Funkcja sprawdza też czy istnieje customer o podanych paramtrach. Jeśli istnieje to funkcja umiemożliwia dodadnie identycznego obiektu.
    void add_customer(std::string, std::string);
    ///Funkcja dodaje zdublowanego customera (jako parametr podawna jest referencja na obiekt klasy Customer). Funkcja sprawdza też czy istnieje customer o podanych paramtrach. Jeśli istnieje to funkcja umiemożliwia dodadnie identycznego obiektu.
    void add_customer(Customer&);
    ///Funkcja wyświetla kolejno dane wszystkich obiektów klasy Customer zawartych w wypozyczalni.
    void show_customers_list();
    ///Funkcja usuwa obiekt klasy Customer z wypozyczlani (parametr customera do usunięcia uzyskiwany jest wewnątrz funkcji).
    void remove_customer();
    ///Funkcja usuwa obiekt klasy Customer z wypozyczalni (parametr customera do usunięcia podawany jest jako parametr).
    void remove_customer(int);
    ///Funkcja wyszukuje określony obiekt klasy Customer w wypożyczalni (jako parametry podawane są name customera i surname) i zwraca prawdę jeśli taki obiekt istnieje.
    bool find_customer(std::string, std::string);
    ///Funkcja dodaje obiekt klasy Register do wypozyczalni (parametry czyli numer customera i commodityu uzyskiwane są wewnątrz).
    void add_into_register_list();
    ///Funkcja dodaje obiekt klasy Register do wypozyczalni (parametry czyli numer customera i commodityu podwane są jako parametry).
    void add_into_register_list(int, int);
    ///Funkcja wyświetla kolejno dane wszystkich obiektów klasy Register zawartych w wypozyczalni.
    void show_register_list();
    ///Funkcja usuwa obiekt klasy Register z wypozyczlani (parametr customera do usunięcia uzyskiwany jest wewnątrz funkcji).
    void remove_from_register_list();
    ///Funkcja usuwa obiekt klasy Register z wypozyczalni (parametr customera do usunięcia podawany jest jako parametr).
    void remove_from_register_list(int);
    ///Funkcja usuwa elementy kontenera Register i twarzy nowy kontener Register na podstawie danych z kontenerów Customer i Commodity.
    void reedit_register_list();
    ///Funkcja używana w testach w pierwszym projekcie do wyświetlania nazwy zawartej w obiekcie klasy wypożyczalnia.
    void show_test_name_only(const Rental &);
    ///Funkcja wyświetla statystyki wypożyczalni, czyli dane aktualne i niektóre zaarchiwizowane.
    void rental_stats();
    ///Funkcja uruchamia odpowiednią wirtualną funkcję służącą do modyfikacji danych zawartych w wybranym obieckie klasy Commodity lub jego pochodną.
    void edit_commodity();
    ///Funkcja uruchamia odpowiednią funkcję służącą do modyfikacji danych zawartych w wybranym obiekcie klasy Customer.
    void edit_customer();
    ///Funkcja zapisuje binarnie dane zawarte w wypożyczalni do pliku w katalogu oraz uprzednio zawsze czyści zawartość plikiu jeśli takowy istnieje.
    void save();
    ///Funkcja czyści zawartość wypoyczalni i następnie tworzy ją ponownie na podstawie danych wczytanych z pliku w katalogu.
    void load();
    ///Funkcja uruchamia sekwencję do_testsącą główne funkcje programu.
    void do_tests();
    ///Funkcja usuwa zalokowaną pamięć w chwili zamykania programu.
    void clear_commodities();
    ///Funkcja usuwa wszystkie dane z wypożyczalni oraz usuwa również zaalokowaną pamięć.
    void clear_all();
    ///Funkcja służy do zaimplementowania oczekiwania na odpowiedź customera.
    void menu_waiting();



};
#endif
