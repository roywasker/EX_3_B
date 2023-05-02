#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

namespace ariel {
    class Fraction {
    public:
        Fraction();
        Fraction(int numerator ,int denominator);
        Fraction(float num);

        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        Fraction operator/(const Fraction& other) const;

        Fraction operator+(float other) const;
        Fraction operator-(float other) const;
        Fraction operator*(float other) const;
        Fraction operator/(float other) const;

        friend Fraction operator+(float float1,const Fraction& other);
        friend Fraction operator-(float float1,const Fraction& other);
        friend Fraction operator*(float float1,const Fraction& other);
        friend Fraction operator/(float float1,const Fraction& other);

        bool operator==(const Fraction& other)const;
        bool operator!=(const Fraction& other)const;
        bool operator>(const Fraction& other)const;
        bool operator<(const Fraction& other)const;
        bool operator>=(const Fraction& other)const;
        bool operator<=(const Fraction& other)const;

        bool operator==(float other);
        bool operator!=(float other);
        bool operator>(float other);
        bool operator<(float other);
        bool operator>=(float other);
        bool operator<=(float other);

        friend bool operator==(float lnum,const Fraction& rnum);
        friend bool operator!=(float lnum,const Fraction& rnum);
        friend bool operator>(float lnum,const Fraction& rnum);
        friend bool operator<(float lnum,const Fraction& rnum);
        friend bool operator>=(float lnum,const Fraction& rnum);
        friend bool operator<=(float lnum,const Fraction& rnum);

        Fraction& operator++(); // prefix
        Fraction& operator--();
        const Fraction operator++(int); // postfix
        const Fraction operator--(int);

        friend std::ostream& operator<< (ostream& output, const Fraction& fract);
        friend std::istream& operator>> (istream& input, Fraction& fract);

        int getNumerator();
        int getDenominator();

    private:
        int numerator_;
        int denominator_;
    };
}

#endif //FRACTION_HPP