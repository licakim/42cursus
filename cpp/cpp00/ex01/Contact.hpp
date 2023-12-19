#ifndef CONTACT_HPP
#define CONTACT_HPP

#include<iostream>

class Contact{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact();
		void set_firstname(std::string firstname);
		void set_lastname(std::string lastname);
		void set_nickname(std::string nickname);
		void set_phonenumber(std::string phonenumber);
		void set_darkestsecret(std::string darkestsecret);
		std::string get_firstname();
		std::string get_lastname();
		std::string get_nickname();
		std::string get_phonenumber();
		std::string get_darkestsecret();
		~Contact();
};

#endif


