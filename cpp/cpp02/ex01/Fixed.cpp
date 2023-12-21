#include "Fixed.hpp"
#include "cmath"

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

Fixed::Fixed(const int value)
{
    std::cout<<"Int constructor called"<<std::endl;
    this->value = value << this -> bit;
}

Fixed::Fixed(const float value)
{
    std::cout<<"Float constructor called"<<std::endl;
    this->value = roundf(value * (1 << this -> bit));
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
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->value / (1<<8);
}

int Fixed::toInt(void) const
{
    return this->value >> this->bit;
}

std::ostream& operator<<(std::ostream& os,const Fixed &f)
{
    os << f.toFloat();
    return os;
}


Fixed::~Fixed(){
    std::cout<<"Destructor called\n";
}