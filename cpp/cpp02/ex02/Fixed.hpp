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
		bool operator>(const Fixed& f) const;
		bool operator<(const Fixed &f) const;
		bool operator>=(const Fixed &f) const;
		bool operator<=(const Fixed &f) const;
		bool operator==(const Fixed &f) const;
		bool operator!=(const Fixed &f) const;
		Fixed operator+(const Fixed& f) const;
		Fixed operator-(const Fixed& f) const;
		Fixed operator*(const Fixed& f) const;
		Fixed operator/(const Fixed& f) const;
		Fixed& operator++(void);
		Fixed operator++(int);
        static Fixed& min(Fixed& f1, Fixed& f2);
        const static Fixed& min(const Fixed& f1, const Fixed& f2);
        static Fixed& max(Fixed& f1, Fixed& f2);
        const static Fixed& max(const Fixed& f1, const Fixed& f2);
        ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);


#endif