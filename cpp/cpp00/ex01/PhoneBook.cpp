#include "PhoneBook.hpp" 
#include<iomanip>

PhoneBook::PhoneBook() : num(0), index(0) {}
PhoneBook::~PhoneBook() {}
std::string PhoneBook::cut_str(std::string str)
{
	if(str.size() > 10)
		return str.substr(0,9) + "." ;
	return str;
}

std::string PhoneBook::read_line()
{
	std::string str;
	std::getline(std::cin, str);
	if(std::cin.fail())
		exit(1);
	if(str == "")
	{
		std::cout<<"*** empty field ***"<<std::endl;
		throw std::exception();
	}
	return str;
}

void PhoneBook::add()
{
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string darkestsecret;
	try{
		if(index == 8)
			index = 0;
		std::cout<<"fist name:";
		firstname = read_line();
		std::cout<<"last name:";
		lastname = read_line();
		std::cout<<"nick name:";
		nickname = read_line();
		std::cout<<"phone number:";
		phonenumber= read_line();
		std::cout<<"darkest secret:";
		darkestsecret = read_line();
		contacts[index].set_firstname(firstname);
		contacts[index].set_lastname(lastname);
		contacts[index].set_nickname(nickname);
		contacts[index].set_phonenumber(phonenumber);
		contacts[index].set_darkestsecret(darkestsecret);
		index++;
		num++;
	}
	catch(const std::exception& e){
		return;
	}
}

void PhoneBook::search()
{
	if(num == 0)
	{
		std::cout<<"*** empty phonebook ***"<<std::endl;
		return ;
	}
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nick name" << std::endl;
	for(int i = 0; i < num && i < 8; i++)
		{
			std::cout << std::setw(10) << i << "|";
			std::cout << std::setw(10) << cut_str(contacts[i].get_firstname()) << "|";
			std::cout << std::setw(10) << cut_str(contacts[i].get_lastname()) << "|";
			std::cout << std::setw(10) << cut_str(contacts[i].get_nickname()) << std::endl;
		}
	std::cout << "enter the index : ";
	std::string str;
	std::getline(std::cin, str);
	if(std::cin.fail())
		exit(1);
	int idx = str[0] - '0';
	if(str.length() !=1  ||  !(0 <= idx && idx <=7))
		std::cout<<"*** invalid index ***" <<std::endl;
	else if(contacts[idx].get_firstname() != "")
	{
		std::cout << "first name: " << contacts[idx].get_firstname() <<std::endl;
		std::cout << "last name: " << contacts[idx].get_lastname() <<std::endl;
		std::cout << "nick name: " << contacts[idx].get_nickname() <<std::endl;
		std::cout << "phone number: " << contacts[idx].get_phonenumber() <<std::endl;
		std::cout << "darkest secret: " << contacts[idx].get_darkestsecret() <<std::endl;
	}
	else
		std::cout << "*** empty index ***" <<std::endl;
}