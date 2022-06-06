#ifndef TERM_H
#define TERM_H
#include <istream>
#include <ostream>

using namespace std;

class Term
{
    friend istream & operator>>(istream & in,Term &t); //ok
    friend ostream & operator<<(ostream & out,const Term &t); //ok

public:
    Term();
    Term(float coef,int power);
    void setcoef(float coef);
    void setpower(int power);
    float get_coef() const;
    int get_power() const;
    Term operator+(const Term& t);
    Term operator-(const Term& t);
    Term operator*(const Term& t);
    Term operator/(const Term& t);
    Term& operator+=(const Term& t);
    Term& operator-=(const Term& t);
    Term& operator*=(const Term& t);
    Term& operator/=(const Term& t);
    Term& operator=(const Term& t);
    bool operator>(const Term& t);  //ok
    bool operator<(const Term& t);  //ok
    bool operator<=(const Term& t);  //ok
    bool operator>=(const Term& t);  //ok
    bool operator==(const Term& t); //ok
    bool operator!=(const Term& t); //ok
    Term operator~();
    Term& operator++();  //ok
    Term& operator--();  //ok
    float operator()(float f);

    void string_to_term(string index);  //help read term

private:
    int char_to_num(char c);  //help change char to number
    float string_to_num(string index); //help change string to number

private:
   float _coef;
   int _power;
};


#endif // TERM_H
