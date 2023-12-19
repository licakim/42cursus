#include "Contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret("") {}

Contact::~Contact(){}
void Contact::set_firstname(std::string firstname)
{
	this->firstName = firstname;
}
void Contact::set_lastname(std::string lastname)
{
	this->lastName = lastname;
}
void Contact::set_nickname(std::string nickname)
{
	this->nickName = nickname;
}
void Contact::set_phonenumber(std::string phonenumber )
{
	this->phoneNumber = phonenumber;
}
void Contact::set_darkestsecret(std::string darkestsecret)
{
	this->darkestSecret = darkestsecret;
}

std::string Contact::get_firstname()
{
	return this->firstName;
}

std::string Contact::get_lastname()
{
	return this->lastName;
}

std::string Contact::get_nickname()
{
	return this->nickName;
}

std::string Contact::get_phonenumber()
{
	return this->phoneNumber;
}

std::string Contact::get_darkestsecret()
{
	return this->darkestSecret;
}

