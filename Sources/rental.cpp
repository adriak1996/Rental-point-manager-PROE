#include<vector>
#include<iostream>
#include<string>
#include<algorithm>


#include"..\Headers\rental.h"

static const std::string DB_NAME = "data.txt";

Rental::Rental()
{
    nazwa="Rental";
    num_all_customers=0;
    num_all_services=0;
}

Rental::Rental(std::string a)
{
    nazwa=a;
    num_all_customers=0;
    num_all_services=0;
}

Rental::~Rental() {}

Rental::Rental(Rental &a)
{
    nazwa=a.nazwa;
    num_all_customers=a.num_all_customers;
    num_all_services=a.num_all_services;

    if((a.register_list.size()>0) &&(&a.register_list[0]!=NULL))
    { for(int i=0; i<a.register_list.size(); ++i) register_list.push_back(a.register_list[i]);}

    if((a.customer.size()>0) && (&a.customer[0]!=NULL))
    { for(int i=0; i<a.customer.size(); ++i) customer.push_back(a.customer[i]); }

    if((a.commodity.size()>0) && (&a.commodity[0]!=NULL))
    { for(int i=0; i<a.commodity.size(); ++i)commodity.push_back(a.commodity[i]); }
}

Rental& Rental::operator=(Rental &a)
{
    nazwa=a.nazwa;

    for(int i=0; i<register_list.size(); ++i) register_list[i]=a.register_list[i];

    for(int i=0; i<customer.size(); ++i) customer[i]=a.customer[i];

    for(int i=0; i<commodity.size(); ++i) commodity[i]=a.commodity[i];

    return *this;
}

    std::ostream & operator <<( std::ostream & os_, const Register & ex )
    {
	ex.serialize(os_);
    return os_;
    }

    std::istream & operator >>( std::istream & is_, Register & ex )
    {
    ex.deserialize(is_);
	return is_;
    }

    void Rental::serialize(std::ostream& stream) const  // Serialization code
    {
        stream << nazwa;
        stream << "\n";
        stream << num_all_customers ;
        stream << "\n";
        stream << num_all_services ;
        stream << "\n";
        stream << customer.size();
        stream << "\n";
        stream << commodity.size();
        stream << "\n";
        stream << register_list.size();
        stream << "\n";

        for(int i=0;i<customer.size();i++)
        {
        	customer[i].serialize(stream);
        	stream << "\n";
        }

        for(int i=0;i<commodity.size();i++)
        {
        	commodity[i]->serialize(stream);
        	stream << "\n";
        }

        for(int i=0;i<register_list.size();i++)
        {
        	register_list[i].serialize(stream);
        	stream << "\n";
        }
    }

    void Rental::deserialize(std::istream& stream)  // Deserialization code
    {
        int kli_size;
        int tow_size;
        int rej_size;

        stream >> nazwa;
        stream >> num_all_customers;
        stream >> num_all_services ;
        stream >> kli_size;
        stream >> tow_size;
        stream >> rej_size;
        for(int i=0;i<kli_size;++i)
        {
        	Customer kl;
        	kl.deserialize(stream);
        	customer.push_back(kl);
        }

        for(int i=0;i<tow_size;++i)
        {
            int temp;
            stream >> temp;
            switch(temp)
            {
            case 1:
            {
            Suit* tow = new Suit;
        	tow->deserialize(stream);
        	commodity.push_back(tow);
        	break;
        	}
            case 2:
            {
            Dress* tow = new Dress();
        	tow->deserialize(stream);
        	commodity.push_back(tow);
        	break;
        	}
            case 3:
            {
            Wedding_dress* tow = new Wedding_dress();
        	tow->deserialize(stream);
        	commodity.push_back(tow);
        	break;
        	}
        	default:
        	break;
            }
        }

            for(int i=0;i<rej_size;++i)
        {
        	Register re;
        	re.deserialize(stream);
        	register_list.push_back(re);
        }
    }


void Rental::show_test_name_only(const Rental &p)
{
    std::cout<<"________________________________________________"<<std::endl;
    std::cout<<"Rental:"<<std::endl;
    std::cout<<"Rental point's name:"<<std::endl;
    std::cout<<"  "<<nazwa<<std::endl;
}

void Rental::save()
{
        std::ofstream file;
        file.open(DB_NAME, std::ofstream::binary | std::ofstream::trunc);

        if( file.good() == true )
        {
        this->serialize(file);

    	file.close();

        std::cout << "Saving process succeeded" << std::endl;

        }
        else std::cout << "Saving process failed !!!" << std::endl;




}

void Rental::load()
{
        clear_commodities();
        customer.erase(customer.begin(), customer.end());
        register_list.erase(register_list.begin(), register_list.end());

    	std::ifstream file;
    	file.open (DB_NAME,std::ifstream::binary );

        if( file.good() == true )
        {

    	this->deserialize(file);

    	file.close();

        std::cout << "Loading process succeeded" << std::endl;

        }
        else std::cout << "Loading process failed !!!" << std::endl;


}

void Rental::do_tests()
{

char a;

std::cout<<"Press any key to start tests..."<<std::endl;
std::cin>>a;
std::cin.clear();
std::cin.ignore(1000, '\n');

std::cout<<"Adding commodity module's test i sort() (from library algorithm) function's test."<<std::endl;
menu_waiting();
std::cout<<"Initial list of commodities."<<std::endl;
menu_waiting();
show_commodities_list();
menu_waiting();
std::cout<<"Let's add 2 first new customers."<<std::endl;
add_commodity2("Bridesmaid's dress", 130);
add_commodity3("Bride's dress", 140, 150);
menu_waiting();
show_commodities_list();
menu_waiting();
std::cout<<"And new two customers."<<std::endl;
add_commodity1("Groom's suit", true);
add_commodity1("The best man's suit", false);
menu_waiting();
show_commodities_list();
std::cout<<"Let's look at the alphabetic sorting."<<std::endl;
menu_waiting();

std::cout<<"Sort() (from library algorithm) function's test."<<std::endl;
menu_waiting();
std::cout<<"Let's add new commodity named \"Groom's suit\""<<std::endl;
add_commodity1("Groom's suit", true);
menu_waiting();

std::cout<<"Edition of commodity module's test."<<std::endl;
menu_waiting();
std::cout<<"Let's change data of any commodity."<<std::endl;
edit_commodity();
menu_waiting();
show_commodities_list();
menu_waiting();
std::cout<<"Let's do it again"<<std::endl;
edit_commodity();
menu_waiting();
show_commodities_list();
menu_waiting();

std::cout<<"Find() (algorithm library) function's test and searching from menu function's test"<<std::endl;
menu_waiting();
show_commodities_list();
menu_waiting();

std::cout<<"Let's check whether \"Groom's suit\" exists."<<std::endl;
menu_waiting();
if(find_commodity("Groom's suit")==true)
std::cout<<"Yes, it exists!"<<std::endl;
else
std::cout<<"No, there is no such commodity!"<<std::endl;

menu_waiting();

std::cout<<"Let's check whether \"Bride's dress\" exists."<<std::endl;
menu_waiting();
if(find_commodity("Bride's dress")==true)
std::cout<<"Yes, it exists!"<<std::endl;
else
std::cout<<"No, there is no such commodity!"<<std::endl;

menu_waiting();

std::cout<<"Adding customer module's test and editing customer module's test."<<std::endl;
menu_waiting();
std::cout<<"Let's see current list of customers"<<std::endl;
menu_waiting();
show_customers_list();
menu_waiting();

std::cout<<"Lets's add 4 new customers"<<std::endl;
add_customer("Annie", "Smith");
add_customer("Margie", "Smith");
add_customer("Johny", "Novak");
add_customer("Chris", "Novak");

menu_waiting();
show_customers_list();
menu_waiting();

std::cout<<"Let's try to add existing customer"<<std::endl;
menu_waiting();
add_customer("Annie", "Smith");

menu_waiting();

std::cout<<"Check whether a customer called Johny Novak exists."<<std::endl;
menu_waiting();
if(find_customer("Johny", "Novak")==true)
std::cout<<"Yes, it exists!"<<std::endl;
else
std::cout<<"No, there is no such customer!!"<<std::endl;

menu_waiting();

std::cout<<"And now, is there any Ian McSevus ? (We did not add any Ian McServus before)"<<std::endl;
menu_waiting();
if(find_customer("Ian", "McServus")==true)
std::cout<<"Yes, it exists!"<<std::endl;
else
std::cout<<"No, there is no such customer!"<<std::endl;

menu_waiting();
std::cout<<"Let's change data of any customer"<<std::endl;
edit_customer();
menu_waiting();
show_customers_list();
menu_waiting();
std::cout<<"Let's do it again"<<std::endl;
edit_customer();
menu_waiting();
show_customers_list();
menu_waiting();

std::cout<<"Creating list of renting services."<<std::endl;
menu_waiting();
std::cout<<"Let's list of renting services at the moment."<<std::endl;
menu_waiting();
show_register_list();
menu_waiting();

std::cout<<"Let's appoint any commodities to some customers. (Creating new rental service)"<<std::endl;
add_into_register_list(1,3);
add_into_register_list(2,4);
add_into_register_list(3,1);
add_into_register_list(4,2);

menu_waiting();
show_register_list();
menu_waiting();

std::cout<<"Let's appoint to the customer no. 1 the commodity no. 2 (which is already rented)"<<std::endl;
add_into_register_list(1,2);

menu_waiting();
show_register_list();
menu_waiting();

std::cout<<"Let's see current rental point's stats."<<std::endl;
menu_waiting();
rental_stats();
menu_waiting();

std::cout<<"And let's glance at the customers, the commodities and renting services lists again"<<std::endl;
show_commodities_list();
menu_waiting();
show_customers_list();
menu_waiting();
show_register_list();
menu_waiting();

std::cout<<"Let's save current condition of data to the file. Save() function's test."<<std::endl;
menu_waiting();
save();
menu_waiting();

std::cout<<"And let's clear all data from base"<<std::endl;
menu_waiting();
clear_all();
std::cout<<"And it is a result"<<std::endl;
menu_waiting();
show_commodities_list();
menu_waiting();
show_customers_list();
menu_waiting();
show_register_list();
menu_waiting();
rental_stats();
menu_waiting();

std::cout<<"There is no doubt, the data base of rental point is empty."<<std::endl;
menu_waiting();

std::cout<<"After closing this testing module, there is an opportunity"<<std::endl;
std::cout<<"to check function loading data from the file. Just restart the program"<<std::endl;
std::cout<<"and load data from file\n"<<std::endl;

std::cout<<"Press any key to finish the tests..."<<std::endl;
std::cin>>a;
std::cin.clear();
std::cin.ignore(1000, '\n');

std::cout<<std::endl;

}


    bool warunek(const Commodity *x, const Commodity *y)
    {
    return (*x<*y);
    }


bool Rental::find_commodity(std::string a)
{
    std::vector<std::string> nazwy;
    std::vector<std::string>::iterator war;
    for(int i=0; i<commodity.size();)
    {
    nazwy.push_back(commodity[i]->commodity_name);
    ++i;
    }

    war=std::find(nazwy.begin(), nazwy.end(), a);

    if(war!=(nazwy.end()))
    {
    return true;
    }
    else return false;

}


void Rental::add_commodity()
{
    std::string a;
    int z;

    std::cout<<"Choose the kind of commodity by typing number of the element"<<std::endl;
    std::cout<<"[1] - Suit"<<std::endl;
    std::cout<<"[2] - Dress"<<std::endl;
    std::cout<<"[3] - Wedding dress"<<std::endl;

    std::cout<<"Type number of commodity's type"<<std::endl;
    std::cin>>z;
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    switch(z)
    {

    case 1:
    {
    std::cout<<"Type suit's name"<<std::endl;
    std::getline(std::cin,a);

    if(find_commodity(a)==true)
    {
    std::cout<<"The same named suit already exists !!!"<<std::endl;
    break;
    }


    std::cout<<"Press [a], if you prefer bow-tie to tie. Otherwise, press whatever apart from [a]."<<std::endl;
    char temp1;
    bool temp2;
    Suit* nowy;
    std::cin>>temp1;
    if(temp1=='a')
    {
    temp2=false;
    nowy = new Suit(a, temp2);
    commodity.push_back(nowy);
    std::cout<<"New suit was added to the base..."<<std::endl;
    sort(commodity.begin(), commodity.end(), warunek);
    reedit_register_list();
    }
    else
    {
    temp2=true;
    nowy = new Suit(a, temp2);
    commodity.push_back(nowy);
    std::cout<<"New suit was added to the base..."<<std::endl;
    sort(commodity.begin(), commodity.end(), warunek);
    reedit_register_list();
    }
    break;
    }

    case 2:
    {
    float temp3;
    Dress* nowa;
    std::cout<<"Type dress's name"<<std::endl;
    std::getline(std::cin,a);

    if(find_commodity(a)==true)
    {
    std::cout<<"The same named dress already exists !!!"<<std::endl;
    break;
    }

    std::cout<<"Type length of the dress in centimeters"<<std::endl;
    std::cin>>temp3;
    nowa = new Dress(a, temp3);
    commodity.push_back(nowa);
    std::cout<<"New dress was added to the base..."<<std::endl;
    sort(commodity.begin(), commodity.end(), warunek);
    reedit_register_list();
    break;
    }

    case 3:
    {
    float temp4;
    float temp5;
    Wedding_dress* nowa1;
    std::cout<<"Type wedding dress's name"<<std::endl;
    std::getline(std::cin,a);

    if(find_commodity(a)==true)
    {
    std::cout<<"The same named wedding dress already exists !!!"<<std::endl;
    break;
    }

    std::cout<<"Type length of the dress in centimeters"<<std::endl;
    std::cin>>temp4;
    std::cout<<"Type length of the veil in centimeters"<<std::endl;
    std::cin>>temp5;
    nowa1 = new Wedding_dress(a, temp4, temp5);
    commodity.push_back(nowa1);
    std::cout<<"New wedding dress was added to the base..."<<std::endl;
    sort(commodity.begin(), commodity.end(), warunek);
    reedit_register_list();
    break;
    }
    default:
    std::cout<<"There is no such option !!!"<<std::endl;

    }





}

void Rental::add_commodity1(std::string a, bool b)
{
    if(find_commodity(a)==false)
    {
    Suit* nowy = new Suit(a, b);
    commodity.push_back(nowy);
    std::cout<<"New suit was added to the base..."<<std::endl;
    sort(commodity.begin(), commodity.end(), warunek);
    reedit_register_list();

    }
    else
    std::cout<<"The same named suit already exists !!!"<<std::endl;



}

void Rental::add_commodity2(std::string a, float b)
{
    if(find_commodity(a)==false)
    {
    Dress* nowa = new Dress(a, b);
    commodity.push_back(nowa);
    std::cout<<"New dress was added to the base..."<<std::endl;
    sort(commodity.begin(), commodity.end(), warunek);
    reedit_register_list();
    }
    else
    std::cout<<"The same named dress already exists !!!"<<std::endl;

}

void Rental::add_commodity3(std::string a, float b, float c)
{

    if(find_commodity(a)==false)
    {
    Wedding_dress* nowa = new Wedding_dress(a, b, c);
    commodity.push_back(nowa);
    std::cout<<"New wedding dress was added to the base..."<<std::endl;
    sort(commodity.begin(), commodity.end(), warunek);
    reedit_register_list();
    }
    else
    std::cout<<"The same named wedding dress already exists !!!"<<std::endl;

}


void Rental::remove_commodity()
{
    int a;
    std::cout<<"Type number of a commodity to remove..."<<std::endl;
    std::cin>>a;

    if((a>0)&&(a<(commodity.size()+1)))
    {
        if(commodity[a-1]->status==true)
        {
            delete commodity[a-1];
            commodity.erase(commodity.begin() + (a-1));
            std::cout<<"The commodity has been removed from the base..."<<std::endl;

            int zap=commodity.size();

            if(register_list.size()!=0)
            {
                for(int i=0; zap>i;)
                {
                    if(register_list[i].id_commodity>a)
                    {
                        register_list[i].id_commodity=(register_list[i].id_commodity-1);
                    }

                    ++i;
                }
            }

        }
        else std::cout<<"The commodity cannot be removed, because it is currently rented"<<std::endl;
    }

}

void Rental::remove_commodity(int a)
{

    if((a>0)&&(a<(commodity.size()+1)))
    {
        if(commodity[a-1]->status==true)
        {
            delete commodity[a-1];
            commodity.erase(commodity.begin() + (a-1));
            std::cout<<"The commodity has been removed from the base..."<<std::endl;

            int zap=commodity.size();

            if(register_list.size()!=0)
            {
                for(int i=0; zap>i;)
                {
                    if(register_list[i].id_commodity>a)
                    {
                        register_list[i].id_commodity=(register_list[i].id_commodity-1);
                    }

                    ++i;
                }
            }

        }
        else std::cout<<"The commodity cannot be removed, because it is currently rented"<<std::endl;
    }

}


void Rental::show_commodities_list()
{
    std::cout<<"********************************************************************************"<<std::endl;
    std::cout<<"LIST OF THE ALL COMMODITIES BELONGED TO RENTAL POINT"<<std::endl;

    if(commodity.size()==0)
    {
        std::cout<<"________________________________________________________________________________"<<std::endl;
        std::cout<<"Empty list"<<std::endl;
    }
    for(int i=0; i<commodity.size(); i++)
    {
        std::cout<<"********************************************************************************"<<std::endl;
        std::cout<<"Commodity no. "<<i+1<<std::endl;

        commodity[i]->show_tests();

    }
    std::cout<<"********************************************************************************"<<std::endl;
    std::cout<<"********************************************************************************"<<std::endl;
    std::cout<<std::endl;

}

void Rental::edit_commodity()
{
std::cout<<"Type commodity number from list..."<<std::endl;
int a;
std::cin>>a;

if((a>0)&&((a-1)<commodity.size()))
{
commodity[a-1]->edit_commodity();
sort(commodity.begin(), commodity.end(), warunek);
reedit_register_list();
}
else std::cout<<"There is no commodity with the chosen number"<<std::endl;
}

void Rental::clear_commodities()
{
for(int i=(commodity.size()-1); i>=0; i--)
    {
            delete commodity[i];
            commodity.erase(commodity.begin()+i);
    }
}

void Rental::add_customer()
{
    std::string a, b;
    std::cout<<"Type new customer's name"<<std::endl;
    std::getline(std::cin,a);
    std::cout<<"Type new customer's surname"<<std::endl;
    std::getline(std::cin,b);

    if(find_customer(a, b)==true)
    std::cout<<"This customer already exist in the base !!!"<<std::endl;
    else
    {
    customer.push_back(Customer(a, b));
    ++num_all_customers;
    std::cout<<"New customer has been added"<<std::endl;
    }
}

void Rental::add_customer(std::string a, std::string b)
{
    if(find_customer(a, b)==true)
    std::cout<<"This customer already exist in the base !!!"<<std::endl;
    else
    {
    customer.push_back(Customer(a, b));
    ++num_all_customers;
    std::cout<<"New customer has been added"<<std::endl;
    }
}

void Rental::add_customer(Customer& a)
{
    ++num_all_customers;
    customer.push_back(a);
}


void Rental::remove_customer()
{
    int a;
    std::cout<<"Type number of customer to remove..."<<std::endl;
    std::cin>>a;

    if((a>0)&&(a<(customer.size()+1)))
    {
        if(customer[a-1].num_of_commodities==0)
        {
            if(register_list.size()>0)
            {
                for(int i=0; register_list.size()>i;)
                {
                    if(register_list[i].id_customer>a)
                    {
                        register_list[i].id_customer=(register_list[i].id_customer-1);
                    }
                    ++i;
                }
            }

            customer.erase(customer.begin() + a-1);
            std::cout<<"The chosen customer has been removed"<<std::endl;

            if(customer.size()>0)
            {
                for(int i=0; customer.size()>i;)
                {
                    if(i>=(a-1))
                        customer[i].num_of_commodities=(customer[i+1].num_of_commodities);
                    ++i;
                }
            }
        }
        else std::cout<<"The chosen customer has rented a commodity currently, so he cannot be removed !!!"<<std::endl;
    }
    else std::cout<<"Wrong data has been typed !!!"<<std::endl;
}

void Rental::remove_customer(int a)
{
    if((a>0)&&(a<(customer.size()+1)))
    {
        if(customer[a-1].num_of_commodities==0)
        {
            if(register_list.size()>0)
            {
                for(int i=0; register_list.size()>i;)
                {
                    if(register_list[i].id_customer>a)
                    {
                        register_list[i].id_customer=(register_list[i].id_customer-1);
                    }
                    ++i;
                }
            }

            customer.erase(customer.begin() + a-1);
            std::cout<<"The chosen customer has been removed..."<<std::endl;

            if(customer.size()>0)
            {
                for(int i=0; customer.size()>i;)
                {
                    if(i>=(a-1))
                        customer[i].num_of_commodities=(customer[i+1].num_of_commodities);
                    ++i;
                }
            }
        }
        else std::cout<<"The chosen customer has rented a commodity currently, so he cannot be removed !!!"<<std::endl;
    }
    else std::cout<<"Wrong data has been typed !!!"<<std::endl;
}

void Rental::show_customers_list()
{
    std::cout<<"********************************************************************************"<<std::endl;
    std::cout<<"LIST OF CURRENT CUSTOMERS"<<std::endl;

    if(customer.size()==0)
    {
        std::cout<<"________________________________________________________________________________"<<std::endl;
        std::cout<<"No customer at the moment"<<std::endl;
    }
    if(customer.size()>0)
    {
        for(int i=0; i<customer.size(); i++)
        {
            std::cout<<"********************************************************************************"<<std::endl;
            std::cout<<"Customer no. "<<i+1<<std::endl;
            std::cout<<"Name\t\t\t\t: "<<customer[i].name<<std::endl;
            std::cout<<"Surname\t\t\t: "<<customer[i].surname<<std::endl;
            std::cout<<"Amount of rented commodities\t: "<<customer[i].num_of_commodities<<std::endl;
        }
    std::cout<<"********************************************************************************"<<std::endl;
    std::cout<<"********************************************************************************"<<std::endl;
    }
    std::cout<<std::endl;
}

void Rental::edit_customer()
{
    std::cout<<"Type number of customer to edit"<<std::endl;
    int a;
    std::cin>>a;
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    if((a>0)&&((a-1)<customer.size()))
    { customer[a-1].edit_customer(); }
    else std::cout<<"There is no such customer !!!"<<std::endl;
}

bool Rental::find_customer(std:: string a, std::string b)
{
    std::vector<std::string> imiona;
    std::vector<std::string> nazwiska;
    std::vector<std::string>::iterator war1;
    std::vector<std::string>::iterator war2;
    int flag=0;

    for(int i=0; i<customer.size();)
    {
    nazwiska.push_back(customer[i].surname);
    ++i;
    }

    war1=std::find(nazwiska.begin(), nazwiska.end(), b);

    if(war1==(nazwiska.end()));

    else
    {
    for(int i=0; i<customer.size();)
    {
    imiona.push_back(customer[i].name);
    ++i;
    }

    war2=std::find(imiona.begin(), imiona.end(), a);
        if(war2==imiona.end());
        else
        {
        return true;
        flag=1;
        }
    }

    if(flag==0) return false;
}



void Rental::add_into_register_list()
{
    int a, b;
    std::cout<<"Type number of customer who wants to rent a commodity"<<std::endl;
    std::cin>>a;
    std::cout<<"Type number of commodity to rent"<<std::endl;
    std::cin>>b;

    if((0<a)&&(a<customer.size()+1)&&(0<b)&&(b<commodity.size()+1))
    {
        if((commodity[b-1]->status==false)&&(register_list.size()>0)) std::cout<<"This commodity has been already rented !!!"<<std::endl;

        if((&customer[a-1]!=NULL)&&(commodity[b-1]!=NULL)&&(a>0)&&(b>0)&&(commodity[b-1]->status==true)&&(a<(customer.size()+1))&&(b<(commodity.size()+1)))
        {
            ++customer[a-1].num_of_commodities;
            commodity[b-1]->status=false;

            ++num_all_services;
            register_list.push_back(Register(a, b));
            std::cout<<"New record in the register has been added..."<<std::endl;
            commodity[b-1]->id_customer=a;
        }
    }
    else std::cout<<"Invalid number of customer or commodity has been typed !!!"<<std::endl;
}

void Rental::add_into_register_list(int a, int b)
{
    if((0<a)&&(a<customer.size()+1)&&(0<b)&&(b<commodity.size()+1))
    {

        if((commodity[b-1]->status==false)&&(register_list.size()>0)) std::cout<<"This commodity has been already rented !!!"<<std::endl;

        if((&customer[a-1]!=NULL)&&(commodity[b-1]!=NULL)&&(a>0)&&(b>0)&&(commodity[b-1]->status==true)&&(a<(customer.size()+1))&&(b<(commodity.size()+1)))
        {

            ++customer[a-1].num_of_commodities;
            commodity[b-1]->status=false;
            ++num_all_services;
            register_list.push_back(Register(a, b));
            std::cout<<"New record in the register has been added..."<<std::endl;
            commodity[b-1]->id_customer=a;
        }
    }

    else std::cout<<"Invalid number of customer or commodity has been typed !!!"<<std::endl;
}


void Rental::show_register_list()
{
    std::cout<<"********************************************************************************"<<std::endl;
    std::cout<<"REGISTER OF CURRENT RENTING SERVICES"<<std::endl;

    if(register_list.size()==0)
    {
        std::cout<<"________________________________________________________________________________"<<std::endl;
        std::cout<<"No renting services at the moment"<<std::endl;
    }

    for(int i=0; i<register_list.size(); ++i)
    {
        std::cout<<"********************************************************************************"<<std::endl;
        std::cout<<"Renting service no. "<<i+1<<std::endl;
        std::cout<<"Customer's name\t\t: "<<customer[register_list[i].id_customer-1].name<<std::endl;
        std::cout<<"Customer's surname\t: "<<customer[register_list[i].id_customer-1].surname<<std::endl;
        std::cout<<"Name of renting commodity\t: "<<commodity[register_list[i].id_commodity-1]->commodity_name<<std::endl;
    }
    std::cout<<"********************************************************************************"<<std::endl;
    std::cout<<"********************************************************************************"<<std::endl;
    std::cout<<std::endl;
}


void Rental::remove_from_register_list()
{
    int i;
    std::cout<<"Type number of renting service to remove"<<std::endl;
    std::cin>>i;

    if((register_list.size()>0)&&((register_list.size()+1)>i))
    {
        if(i>0)
        {
            --customer[register_list[i-1].id_customer-1].num_of_commodities;
            commodity[register_list[i-1].id_commodity-1]->status = true;
            register_list.erase(register_list.begin() + (i-1));
            std::cout<<"The chosen renting service has been removed from the base..."<<std::endl;
            commodity[register_list[i-1].id_customer-1]->id_customer=0;
        }

    }
}

void Rental::remove_from_register_list(int i)
{

    if((register_list.size()>0)&&((register_list.size()+1)>i))
    {
        if(i>0)
        {
            --customer[register_list[i-1].id_customer-1].num_of_commodities;
            commodity[register_list[i-1].id_commodity-1]->status = true;
            register_list.erase(register_list.begin() + (i-1));
            std::cout<<"The chosen renting service has been removed from the base..."<<std::endl;
            commodity[register_list[i-1].id_customer-1]->id_customer=0;
        }
    }
}

void Rental::reedit_register_list()
{
    register_list.erase(register_list.begin(), register_list.end());

    for(int i=0; commodity.size()>i;)
    {
    if(commodity[i]->id_customer!=0)
    {
    register_list.push_back(Register(commodity[i]->id_customer,i+1));
    }
    ++i;
    }
}

void Rental::rental_stats()
{
    std::cout<<"********************************************************************************"<<std::endl;
    std::cout<<"RENTAL POINT'S STATS"<<std::endl;
    std::cout<<"________________________________________________________________________________"<<std::endl;
    std::cout<<"\tNumber of current customers\t\t: "<<customer.size()<<std::endl;
    std::cout<<"\tNumber of all customers so far\t\t: "<<num_all_customers<<std::endl;
    std::cout<<"\tNumber of current commodities\t\t: "<<commodity.size()<<std::endl;
    std::cout<<"\tNumber of available commodities \t: "<<commodity.size()-register_list.size()<<std::endl;
    std::cout<<"\tNumber of current renting services\t: "<<commodity.size()<<std::endl;
    std::cout<<"\tNumber of all renting services so far\t: "<<num_all_services<<std::endl;
    std::cout<<"********************************************************************************"<<std::endl;
}

void Rental::menu_waiting()
{
char a;
std::cout<<"\nPress any key to continue..."<<std::endl;
std::cin>>a;
std::cin.clear();
std::cin.ignore(1000, '\n');
}

void Rental::clear_all()
{
char a;
register_list.erase(register_list.begin(), register_list.end());
clear_commodities();
customer.erase(customer.begin(), customer.end());
num_all_customers=0;
num_all_services=0;
std::cout<<"All data concerning renting services, commodities and customers has been removed"<<std::endl;
}


