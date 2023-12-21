#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout<<"Default constructor called"<<std::endl;
    this->value=0;
}

Fixed::Fixed(const Fixed& obj)
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this = obj;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
    std::cout<<"Copy assignment operator called"<<std::endl;
    if(this != &obj)
        this -> value = obj.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

Fixed::~Fixed(){
    std::cout<<"Destructor called\n";
}