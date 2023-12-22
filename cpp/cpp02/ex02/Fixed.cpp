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

bool Fixed::operator>(const Fixed& f) const
{
	return this->value > f.value;
}
bool Fixed::operator<(const Fixed &f) const
{
	return this->value<f.value;
}
bool Fixed::operator>=(const Fixed &f) const
{
	return this->value>=f.value;
}
bool Fixed::operator<=(const Fixed &f) const
{
	return this->value<=f.value;
}
bool Fixed::operator==(const Fixed &f) const
{
	return this->value == f.value;
}
bool Fixed::operator!=(const Fixed &f) const
{
	return this->value != f.value;
}

Fixed Fixed::operator+(const Fixed& f) const
{
	return Fixed(this->toFloat() + f.toFloat());
}
Fixed Fixed::operator-(const Fixed& f) const
{
	return Fixed(this->toFloat() - f.toFloat());
}
Fixed Fixed::operator*(const Fixed& f) const
{
	return Fixed(this->toFloat() * f.toFloat());
}
Fixed Fixed::operator/(const Fixed& f) const
{
	return Fixed(this->toFloat() / f.toFloat());
}

Fixed& Fixed::operator++(void)
{
	this->value++;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->value++;
	return temp;
}

Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
	if(f1>f2)
		return f2;
	else
		return f1;
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
	if(f1>f2)
		return f1;
	else
		return f2;
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if(f1>f2)
		return f2;
	else
		return f1;
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if(f1>f2)
		return f1;
	else
		return f2;
}


Fixed::~Fixed(){
    std::cout<<"Destructor called\n";
}