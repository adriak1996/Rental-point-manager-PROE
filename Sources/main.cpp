#include <iostream>
#include <vector>
#include <fstream>

#include"..\Headers\rental.h"
#include"..\Headers\menu.h"




using namespace std;

int main()
{
    cout << "_________________________________________________________________________________________________" << endl;
    cout << "            MANAGER of ELEGANT CLOTHES' RENTAL POINT by Adrian Kotowski (el-gato)                " << endl;
    cout << "    An academic project at the course 'Object-oriented programming' Winter/Spring of the 2016    " << endl;
    cout << "_________________________________________________________________________________________________" << endl;
    cout << endl;

    char start;
    cout << "Press any key to launch rental point's manager ..." << endl;
    cin>>start;
    cin.clear();
    cin.ignore(1000, '\n');


    Rental rental;

    char a;
    int flag=0;

    menu();

    cin>>a;
    cin.clear();
    cin.ignore(1000, '\n');
    if(a=='q')
    {
        rental.clear_commodities();
        flag=1;
    }

    while(flag!=1)
    {
        switch(a)
        {
        case'a':
            rental.add_commodity();
            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        case'b':
            rental.remove_commodity();
            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        case'c':
            rental.show_commodities_list();
            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        case'd':
            rental.add_customer();
            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        case'e':
            rental.remove_customer();
            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        case'f':
            rental.show_customers_list();
            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        case'g':
            rental.add_into_register_list();
            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        case'h':
            rental.remove_from_register_list();
            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        case'i':
            rental.show_register_list();
            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        case'k':
        {
            string x;
            cout<<"Type name of the seeking commodity"<<endl;
            getline(cin,x);

            if(rental.find_commodity(x)==true)
                cout<<"The chosen commodity was found !!!"<<endl;
            else
                cout<<"There is no such commodity in the rental point's base"<<endl;

            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }
        case'l':
        {
            string x, y;
            cout<<"Type name of the seeking customer"<<endl;
            getline(cin,x);
            cout<<"Type surname of the seeking customer"<<endl;
            getline(cin,y);

            if(rental.find_customer(x, y)==true)
                cout<<"The chosen customer was found !!!"<<endl;
            else
                cout<<"There is no such customer in the rental point's base"<<endl;


            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }
        case'm':
            rental.edit_commodity();
            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        case'n':
            rental.edit_customer();
            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        case's':
            rental.rental_stats();
            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        case'p':
            rental.save();
            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        case'r':
            rental.load();
            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        case't':
            rental.do_tests();
            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        case'z':
            rental.clear_all();
            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        case'q':
        {
            rental.clear_commodities();
            flag=1;
            break;
        }
        default:
            cout<<"Unknown command was typed !!!"<<endl;
            menu();
            cin>>a;
            cin.clear();
            cin.ignore(1000, '\n');

            break;


        }

    }





    return 0;


}
