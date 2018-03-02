#pragma once

void menu()
{

    char start;
    std::cout << "Press any key to launch the menu..." << std::endl;
    std::cin>>start;
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    std::cout<<"********************************************************************************"<<std::endl;
    std::cout<<"\tRENTAL POINT'S MANAGER"<<std::endl;
    std::cout<<"________________________________________________________________________________"<<std::endl;
    std::cout<<"    @ Storage operations"<<std::endl;
    std::cout<<"    [a] - Add new commodity"<<std::endl;
    std::cout<<"    [b] - Remove a commodity"<<std::endl;
    std::cout<<"    [c] - Show list of the current commodities"<<std::endl;
    std::cout<<"    [k] - Check whether the commodity exists in the storage"<<std::endl;
    std::cout<<"    [n] - Edit a commodity"<<std::endl;
    std::cout<<"________________________________________________________________________________"<<std::endl;

    std::cout<<"    @ Customers operations "<<std::endl;
    std::cout<<"    [d] - Add new customer"<<std::endl;
    std::cout<<"    [e] - Remove a customer"<<std::endl;
    std::cout<<"    [f] - Show list of the current customers"<<std::endl;
    std::cout<<"    [l] - Check whether the customer exists in the storage"<<std::endl;
    std::cout<<"    [m] - Edit a customer's details"<<std::endl;
    std::cout<<"________________________________________________________________________________"<<std::endl;
    std::cout<<"    @ Renting services operations"<<std::endl;
    std::cout<<"    [g] - Rent a commodity for a customer"<<std::endl;
    std::cout<<"    [h] - Take commodity from a customer"<<std::endl;
    std::cout<<"    [i] - Show list of the current renting services"<<std::endl;
    std::cout<<"    [s] - Show current stats of rental point's"<<std::endl;
    std::cout<<"    [t] - Demonstrate the tests of the rental system"<<std::endl;
    std::cout<<"    [z] - Clear all data from the base"<<std::endl;
    std::cout<<"________________________________________________________________________________"<<std::endl;
    std::cout<<"    @ Saving and loading data to\\from file"<<std::endl;
    std::cout<<"    [p] - Save current condition of data to the file"<<std::endl;
    std::cout<<"    [r] - Load current condition of data from the file"<<std::endl;
    std::cout<<"          Warning! Previous condition of data will be overwritten!!!)"<<std::endl;
    std::cout<<"________________________________________________________________________________"<<std::endl;

    std::cout<<"    @ EXIT"<<std::endl;
    std::cout<<"    [q] - Quit the program"<<std::endl;
    std::cout<<"********************************************************************************"<<std::endl;
}
