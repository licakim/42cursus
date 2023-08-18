#include<string>
#include<iostream>

class Contacts{
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phonenumber;
	public:
		void set_firstname();
		void set_lastname();
		void set_nickname();
		void set_phonenumber();
		void get_firstname();
		void get_lastname();
		void get_nickname();
		void get_phonenumber();
};

class PhoneBook{
	Contacts contacts[8];
	add();
	search();
	exit();
}

Contacts::set_firstname()
{
	std::getline(std::cin, firstname);
}