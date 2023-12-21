#ifndef FIXED_HPP
#define FIXED_HPP

#include<iostream>

class Fixed
{
    private:
        int value;
        const static int    bit = 8;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& obj);
        Fixed& operator=(const Fixed &obj);
        float toFloat(void) const;
        int toInt(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
        ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);


#endif