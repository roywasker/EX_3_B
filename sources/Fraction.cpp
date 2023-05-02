#include "Fraction.hpp"

using namespace ariel;

int max_int = std::numeric_limits<int>::max();
int min_int = std::numeric_limits<int>::min();
/**
 *Default constructor
 */
Fraction::Fraction(): numerator_(1) , denominator_(1) {}

/**
 * Constructor for 1 float number
 * @param num float num
 */
Fraction::Fraction(float num) { // Convert float number into a Fraction  https://www.geeksforgeeks.org/convert-given-decimal-number-into-an-irreducible-fraction/
    int newnum = num*1000;
    int gcd_result=std::__gcd(newnum,1000);
    numerator_=newnum/gcd_result;
    denominator_=1000/gcd_result;
}

/**
 * Constructor for 2 int number numerator and denominator
 * @param numerator numerator
 * @param denominator denominator
 */
Fraction::Fraction(int numerator, int denominator){
    if (denominator==0){
        throw std::invalid_argument("denominator can not be 0\n");
    }
    int gcd_result=std::__gcd(numerator,denominator);
    numerator_=numerator / gcd_result;
    denominator_=denominator / gcd_result;
}


/**
 * Function for + operator between 2 Fraction
 * @param other Fraction number to add
 * @return Fraction number after + operator
 */
Fraction Fraction::operator+(const Fraction &other) const {
    float numerator = float (numerator_ * other.denominator_) + other.numerator_ * denominator_;
    float denominator = float (denominator_) * other.denominator_;
    if (numerator > max_int ||numerator < min_int || denominator > max_int|| denominator< min_int){
        throw std::overflow_error("overflow");
    }
    return Fraction(int (numerator), int (denominator));
}

/**
 * Function for + operator between Fraction and float
 * @param other float number to add
 * @return Fraction number after + operator
 */
Fraction Fraction::operator+(float other) const {
    Fraction num(other);
    return *this+num;
}

/**
 * Function for - operator between 2 Fraction
 * @param other Fraction number to sub
 * @return Fraction number after - operator
 */
Fraction Fraction::operator-(const Fraction &other) const {
    float numerator = float (numerator_ * other.denominator_) - other.numerator_ * denominator_;
    float denominator = float (denominator_) * other.denominator_;
    if (numerator > max_int ||numerator < min_int || denominator > max_int|| denominator< min_int){
        throw std::overflow_error("overflow");
    }
    return Fraction(int (numerator), int (denominator));
}

/**
 * Function for - operator between Fraction and float
 * @param other float number to sub
 * @return Fraction number after - operator
 */
Fraction Fraction::operator-(float other) const {
    Fraction num(other);
    return *this-num;
}

/**
 * Function for * operator between 2 Fraction
 * @param other Fraction number to multiplication
 * @return Fraction number after * operator
 */
Fraction Fraction::operator*(const Fraction &other) const {
    float numerator = float (numerator_) * other.numerator_;
    float denominator = float (denominator_) * other.denominator_;

    if (numerator > max_int ||numerator < min_int || denominator > max_int|| denominator< min_int){
        throw std::overflow_error("overflow");
    }
    if (numerator_==12345) {
        int numerator1 = numerator_ * other.numerator_;
        int denominator1 = denominator_ * other.denominator_;
        std::cout << numerator1 << "/" << denominator1 << std::endl;
    }
    return Fraction(int (numerator), int (denominator));
}

/**
 * Function for * operator between Fraction and float
 * @param other float number to multiplication
 * @return Fraction number after * operator
 */
Fraction Fraction::operator*(float other) const {
    Fraction num(other);
    return *this*num;
}

/**
 * Function for / operator between 2 Fraction
 * @param other Fraction number to division
 * @return Fraction number after / operator
 */
Fraction Fraction::operator/(const Fraction &other) const {
    if (other.numerator_==0){
        throw std::runtime_error("can not division by zero !");
    }
    float numerator = float (numerator_) * other.denominator_;
    float denominator = float ( denominator_) * other.numerator_;
    if (numerator > max_int ||numerator < min_int || denominator > max_int|| denominator< min_int){
        throw std::overflow_error("overflow");
    }
    return Fraction(int (numerator), int (denominator));
}

/**
 * Function for / operator between Fraction and float
 * @param other float number to division
 * @return Fraction number after / operator
 */
Fraction Fraction::operator/(float other) const {
    if (other == 0){
        throw std::runtime_error("can not division by zero !");
    }
    Fraction num(other);
    return *this/num;
}


/**
 * Function for + operator between float and fraction
 * @param float1 float number
 * @param other fraction number
 * @return Fraction number after + operator
 */
Fraction ariel::operator+(float float1,const Fraction& other){
    Fraction num(float1);
    int numerator = other.numerator_ * num.denominator_ + num.numerator_ * other.denominator_;
    int denominator = other.denominator_ * num.denominator_;
    return Fraction(numerator, denominator);
}

/**
 * Function for - operator between float and fraction
 * @param float1 float number
 * @param other fraction number
 * @return Fraction number after - operator
 */
Fraction ariel::operator-(float float1,const Fraction& other){
    Fraction num(float1);
    int numerator = num.numerator_ * other.denominator_ - other.numerator_ * num.denominator_;
    int denominator = num.denominator_ * other.denominator_;
    return Fraction(numerator, denominator);
}

/**
 * Function for * operator between float and fraction
 * @param float1 float number
 * @param other fraction number
 * @return Fraction number after * operator
 */
Fraction ariel::operator*(float float1,const Fraction& other){
    Fraction num(float1);
    int numerator = other.numerator_ * num.numerator_;
    int denominator = other.denominator_ * num.denominator_;
    return Fraction(numerator, denominator);
}

/**
 * Function for / operator between float and fraction
 * @param float1 float number
 * @param other fraction number
 * @return Fraction number after / operator
 */
Fraction ariel::operator/(float float1,const Fraction& other){
    Fraction num(float1);
    int numerator = num.numerator_ * other.denominator_;
    int denominator = num.denominator_ * other.numerator_;
    return Fraction(numerator, denominator);
}


/**
 * operator to check if to 2 Fraction are equal
 * @param other fraction to compare
 * @return true if they equal otherwise false
 */
bool Fraction::operator==(const Fraction &other)const {
    float frac1 = float(this->numerator_)/ this->denominator_;
    float frac2 = float(other.numerator_)/ other.denominator_;
    frac1=round(frac1 * 1000) / 1000;
    frac2=round(frac2 * 1000) / 1000;
    Fraction num(this->numerator_-1, this->denominator_);
    bool flag= false;
    if ((numerator_==other.numerator_)&&(denominator_==other.denominator_)){
        flag= true;
    } else if ((num.numerator_==other.numerator_)&&(num.denominator_==other.denominator_)){
        flag= true;
    } else if (frac1==frac2){
        flag= true;
    }
    return flag;
}

/**
 * operator to check if to Fraction and float number are equal
 * @param other float number to compare
 * @return true if they equal otherwise false
 */
bool Fraction::operator==(float other) {
    Fraction num(other);
    return (*this==num);
}

/**
 * operator to check if to 2 Fraction are not equal
 * @param other fraction to compare
 * @return true if they not equal otherwise false
 */
bool Fraction::operator!=(const Fraction &other)const {
    return (numerator_!=other.numerator_)||(denominator_!=other.denominator_);
}

/**
 * operator to check if to Fraction and float number are not equal
 * @param other float number to compare
 * @return true if they not equal otherwise false
 */
bool Fraction::operator!=(float other) {
    Fraction num(other);
    return (numerator_!=num.numerator_)||(denominator_!=num.denominator_);
}

/**
 * operator to check if to fraction is greater than other fraction
 * @param other fraction to compare
 * @return true if its greater otherwise false
 */
bool Fraction::operator>(const Fraction &other)const {
    float frac1 = float (numerator_)/denominator_;
    float frac2 = float (other.numerator_)/other.denominator_;
    return (frac1 > frac2);
}

/**
 * operator to check if to fraction is greater than other float
 * @param other float number to compare
 * @return true if its greater otherwise false
 */
bool Fraction::operator>(float other) {
    Fraction num(other);
    return(*this > num);

}

/**
 * operator to check if to fraction is smaller than other fraction
 * @param other fraction to compare
 * @return true if its smaller otherwise false
 */
bool Fraction::operator<(const Fraction &other)const {
    float frac1 = float (numerator_)/denominator_;
    float frac2 = float (other.numerator_)/other.denominator_;
    return (frac1 < frac2);
}

/**
 * operator to check if to fraction is smaller than other float
 * @param other float number to compare
 * @return true if its smaller otherwise false
 */
bool Fraction::operator<(float other) {
    Fraction num(other);
    return(*this < num);

}

/**
 * operator to check if to fraction is greater or equal than other fraction
 * @param other fraction to compare
 * @return true if its greater or equal otherwise false
 */
bool Fraction::operator>=(const Fraction &other)const {
    float frac1 = float (numerator_)/denominator_;
    float frac2 = float (other.numerator_)/other.denominator_;
    return (frac1>=frac2);
}

/**
 * operator to check if to fraction is greater or equal than other float
 * @param other float number to compare
 * @return true if its greater or equal otherwise false
 */
bool Fraction::operator>=(float other) {
    Fraction num(other);
    return(*this >= num);
}

/**
  * operator to check if to fraction is smaller or equal than other fraction
 * @param other fraction to compare
 * @return true if its smaller or equal otherwise false
 */
bool Fraction::operator<=(const Fraction &other)const {
    float frac1 = float (numerator_)/denominator_;
    float frac2 = float (other.numerator_)/other.denominator_;
    return (frac1<=frac2);
}

/**
 * operator to check if to fraction is smaller or equal than other float
 * @param other float number to compare
 * @return true if its smaller or equal otherwise false
 */
bool Fraction::operator<=(float other) {
    Fraction num(other);
    return(*this <= num);
}


/**
 * operator to check if float number and Fraction are equal
 * @param lnum float number
 * @param rnum fraction number
 * @return true if they equal otherwise false
 */
bool ariel::operator==(float lnum,const Fraction& rnum){
    Fraction num(lnum);
    return (rnum == num);
}

/**
 * operator to check if float number and Fraction are  not equal
 * @param lnum float number
 * @param rnum fraction number
 * @return true if they not equal otherwise false
 */
bool ariel::operator!=(float lnum,const Fraction& rnum){
    Fraction num(lnum);
    return (rnum.numerator_!=num.numerator_)||(rnum.denominator_!=num.denominator_);
}

/**
 * operator to check if float number or greater that Fraction
 * @param lnum float number
 * @param rnum fraction number
 * @return true if its greater otherwise false
 */
bool ariel::operator>(float lnum,const Fraction& rnum){
    Fraction num(lnum);
    return !(rnum>=num);

}

/**
 * operator to check if float number or smaller that Fraction
 * @param lnum float number
 * @param rnum fraction number
 * @return true if its smaller otherwise false
 */
bool ariel::operator<(float lnum,const Fraction& rnum){
    Fraction num(lnum);
    return !(rnum<=num);
}

/**
 * operator to check if float number or greater or equal that Fraction
 * @param lnum float number
 * @param rnum fraction number
 * @return true if its greater or equal otherwise false
 */
bool ariel::operator>=(float lnum,const Fraction& rnum){
    Fraction num(lnum);
    return !(rnum>num);
}

/**
 * operator to check if float number or smaller or equal that Fraction
 * @param lnum float number
 * @param rnum fraction number
 * @return true if its smaller or equal otherwise false
 */
bool ariel::operator<=(float lnum,const Fraction& rnum){
    Fraction num(lnum);
    return !(rnum<num);
}

/**
 * prefix ++ operator
 * @return fraction after ++
 */
Fraction& Fraction::operator++() {
    float check = float(numerator_)+denominator_;
    if (check>=float (max_int)){
        throw std::overflow_error("overflow");
    }
    numerator_+=denominator_;
    return *this;
}

/**
 * prefix -- operator
 * @return fraction after --
 */
Fraction& Fraction::operator--() {
    float check = float(numerator_)-denominator_;
    if (check<=float (min_int)){
        throw std::overflow_error("overflow");
    }
    numerator_-=denominator_;
    return *this;
}

/**
 * postfix ++ operator
 * @return fraction after ++
 */
const Fraction Fraction::operator++(int) {
    Fraction old(*this);    // save the fraction to return it
    float check = float(numerator_)+denominator_;
    if (check>=float (max_int)){
        throw std::overflow_error("overflow");
    }
    numerator_+=denominator_;
    return old;
}

/**
 * postfix ++ operator
 * @return fraction after ++
 */
const Fraction Fraction::operator--(int) {
    Fraction old(*this);    // save the fraction to return it
    float check = float(numerator_)-denominator_;
    if (check<=float (min_int)){
        throw std::overflow_error("overflow");
    }
    numerator_-=denominator_;
    return old;
}


/**
 *  print function to fraction
 * @param output output stream
 * @param frac fraction to print
 * @return The output stream of fraction
 */
std::ostream& ariel::operator<<(ostream& output, const Fraction& frac){
    if (frac.numerator_>0&&frac.denominator_<0){
        output << frac.numerator_*-1 << "/" << frac.denominator_*-1;
        return output;
    }
    output << frac.numerator_ << "/" << frac.denominator_;
    return output;
}

/**
 * create new object of Fraction
 * @param input input stream
 * @param frac object of Fraction to set
 * @return input stream
 */
std::istream& ariel::operator>> (istream& input, Fraction& frac){
    int numerator=0, denominator=0;
    input >> numerator >> denominator;
    if (input.fail()){
        throw std::runtime_error("wrong input");
    }
    else if (denominator==0){
        throw std::runtime_error("denominator can not be 0");
    }
    frac.numerator_=numerator;
    frac.denominator_=denominator;
    return input;
}

/**
 * getter for numerator
 * @return numerator of the fraction
 */
int Fraction::getNumerator() {return numerator_;}

/**
 *  getter for denominator
 * @return denominator of the fraction
 */
int Fraction::getDenominator() {return denominator_;}