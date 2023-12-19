#include<iostream>
#include"PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;
	while(1)
	{
		std::cout<<"My Awseome PhoneBook"<<std::endl;
		std::cout<<"--------------------------------"<<std::endl;
		std::cout<<"enter command(ADD, SEARCH, EXIT) : ";
		std::getline(std::cin, command);
		if(std::cin.fail())
			break;
		if(command == "ADD")
			phonebook.add();
		else if(command == "SEARCH")
			phonebook.search();
		else if(command == "EXIT")
			break;
		else
			std::cout<<"*** please enter command correctly ***"<<std::endl;
		std::cout<<std::endl;
	}
}