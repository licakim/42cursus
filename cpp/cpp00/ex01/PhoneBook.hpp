#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
	private:
		Contact contacts[8];
		int num;
		int index;
	public:
		PhoneBook();
		void add();
		void search();
		std::string read_line();
		std::string cut_str(std::string str);
		~PhoneBook();
};

#endif