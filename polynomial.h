#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "term.h"
#include <vector>
//#include <istream>
//#include <ostream>

class Polynomial
{

    friend istream & operator>>(istream & in,Polynomial &p);
    friend ostream & operator<<(ostream & out,const Polynomial &p);

public:
    Polynomial();
    Polynomial(vector<Term> terms);
    Polynomial(Polynomial& poly);
    void set_terms(vector <Term>& terms);
    int get_terms_number() const;
    int get_polynomial_degree() const;
    vector <Term> get_terms_of_poly() const;
    Polynomial operator+(const Polynomial& p);
    Polynomial operator-(const Polynomial& p);
    Polynomial operator*(const Polynomial& p);
    Polynomial operator/(const Polynomial& p);
    Polynomial& operator+=(const Polynomial& p);
    Polynomial& operator-=(const Polynomial& p);
    Polynomial& operator*=(const Polynomial& p);
    Polynomial& operator/=(const Polynomial& p);
    Polynomial& operator=(const Polynomial& p);
    bool operator>(const Polynomial& p);
    bool operator<(const Polynomial& p);
    bool operator<=(const Polynomial& p);
    bool operator>=(const Polynomial& p);
    bool operator==(const Polynomial& p);
    bool operator!=(const Polynomial& p);
    Polynomial operator~();
    Polynomial& operator++();
    Polynomial& operator--();
    float operator()(float f);
    Term operator[](const int index) const;
    Term& operator[](const int index);

private:

    void sort_terms(Polynomial &p);
    void swap(Term &t1,Term &t2);
    void delete_equal_degree(Polynomial &p);
    void delete_index(Polynomial &p, int index);
    void string_to_polynomial(string index); // help read polynomial

private:

    vector <Term> _terms;
};

#endif // POLYNOMIAL_H
