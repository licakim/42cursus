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
        Fixed(const Fixed& obj);
        Fixed& operator=(const Fixed &obj);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        ~Fixed();
};


#endif