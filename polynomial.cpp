#include "polynomial.h"
#include <iostream>

Polynomial::Polynomial(){
    _terms.resize(0);
    sort_terms(*this);
}

Polynomial::Polynomial(vector <Term> terms){

   set_terms(terms);
}

void Polynomial::set_terms(vector<Term>& terms){

    _terms=terms;
    _terms.resize(terms.size());
    sort_terms(*this);
}

int Polynomial::get_terms_number() const{

    return _terms.size();
}

int Polynomial::get_polynomial_degree() const{

    return _terms[0].get_power();
}

istream & operator>>(istream & in,Polynomial &p){

    string index;
    in>>index;
    p.string_to_polynomial(index);
    return in;
}

ostream & operator<<(ostream & out,const Polynomial &p){
    if(p._terms.size()==0){
        out<<0;
    }

    if(p._terms.size()==1 && p._terms[0].get_coef()==0)
    {
        out<<0;
    }

    for(int i=0;i<p._terms.size();i++)
    {
         if(i!=0 && p._terms[i].get_coef()>0){
            out<<"+";
         }
         if(p._terms[i].get_coef()!=0)
         {
             out<<p._terms[i];
         }
    }

    return out;
}


Polynomial Polynomial::operator+(const Polynomial& p){

    Polynomial result(_terms);

    for(int i=0;i<p._terms.size();i++)
    {
        result._terms.push_back(p._terms[i]);
    }

    sort_terms(result);
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& p){

    Polynomial result(_terms);

    for(int i=0;i<p._terms.size();i++)
    {
        result._terms.push_back(p._terms[i]);
    }

    for(int i=_terms.size();i<result._terms.size();i++)
    {
        result._terms[i].setcoef(-1 *(result._terms[i].get_coef()));
    }

    sort_terms(result);
    return result;
}

Polynomial Polynomial::operator*(const Polynomial& p){

    Polynomial result;

    for(int i=0;i<p._terms.size();i++)
    {
        for(int j=0;j<_terms.size();j++)
        {
            result._terms.push_back(_terms[j] *p._terms[i]);
        }
    }

    sort_terms(result);
    return result;

}

Polynomial Polynomial::operator/(const Polynomial& p){

    Polynomial result;

    for(int i=0;i<p._terms.size();i++)
    {
        for(int j=0;j<_terms.size();j++)
        {
            result._terms.push_back(_terms[j] /p._terms[i]);
        }
    }

    sort_terms(result);
    return result;
}

Polynomial& Polynomial::operator+=(const Polynomial& p){

    for(int i=0;i<p._terms.size();i++)
    {
        _terms.push_back(p._terms[i]);
    }

    sort_terms(*this);
    return *this;

}

Polynomial& Polynomial::operator-=(const Polynomial& p){

    int temp=0;
    temp=_terms.size();
    for(int i=0;i<p._terms.size();i++)
    {
        _terms.push_back(p._terms[i]);
    }

    for(int i=temp;i<_terms.size();i++)
    {
        _terms[i].setcoef(-1 *(_terms[i].get_coef()));
    }

    sort_terms(*this);
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& p){

    Polynomial result;

    for(int i=0;i<p._terms.size();i++)
    {
        for(int j=0;j<_terms.size();j++)
        {
            result._terms.push_back(_terms[j] *p._terms[i]);
        }
    }

    sort_terms(result);
    *this=result;
    return *this;
}

Polynomial& Polynomial::operator/=(const Polynomial& p){

    Polynomial result;

    for(int i=0;i<p._terms.size();i++)
    {
        for(int j=0;j<_terms.size();j++)
        {
            result._terms.push_back(_terms[j] /p._terms[i]);
        }
    }

    sort_terms(result);
    *this=result;
    return *this;
}

Polynomial& Polynomial::operator=(const Polynomial& p){

    _terms.resize(0);
    for(int i=0;i<p._terms.size();i++)
    {
     _terms.push_back(p._terms[i]);
    }

    return *this;
}

bool Polynomial::operator>(const Polynomial& p){

    for(int i=0;i<_terms.size();i++)
    {
        if(_terms[i]> p._terms[i])
        {
            return true;
        }
    }

    return false;
}

bool Polynomial::operator<(const Polynomial& p){

    for(int i=0;i<_terms.size();i++)
    {
        if(_terms[i]< p._terms[i])
        {
            return true;
        }
    }

    return false;
}

bool Polynomial::operator<=(const Polynomial& p){

    for(int i=0;i<_terms.size();i++)
    {
        if(_terms[i]<=p._terms[i])
        {
            return true;
        }
    }

    return false;
}

bool Polynomial::operator>=(const Polynomial& p){

    for(int i=0;i<_terms.size();i++)
    {
        if(_terms[i]>= p._terms[i])
        {
            return true;
        }
    }

    return false;
}

bool Polynomial::operator==(const Polynomial& p){

    int count=0;

    for(int i=0;i<_terms.size();i++)
    {
        if(_terms[i]== p._terms[i])
        {
            count++;
        }
    }

    if(count==_terms.size())
    {
        return true;
    }

    return false;
}

bool Polynomial::operator!=(const Polynomial& p){

    if(*this==p)
    {
        return false;
    }

    return true;
}

Polynomial Polynomial::operator~(){

    Polynomial result;
    result._terms.resize(0);

    for(int i=0;i<_terms.size();i++)
    {
        result._terms.push_back(~_terms[i]);
    }

    sort_terms(result);
    return result;
}

Polynomial& Polynomial::operator++(){

    Polynomial polyone;
    Term one(1,0);
    polyone._terms.resize(0);
    polyone._terms.push_back(one);

    *this += polyone;
    return *this;
}

Polynomial& Polynomial::operator--(){

    Polynomial polyone;
    Term one(1,0);
    polyone._terms.resize(0);
    polyone._terms.push_back(one);

    *this -= polyone;
    return *this;
}

float Polynomial::operator()(float f){

    float result=0;

    for(int i=0;i<_terms.size();i++)
    {
        result+= _terms[i](f);
    }
    return result;
}

Term Polynomial::operator[](const int index) const{

    return _terms[index];
}

Term & Polynomial::operator[](const int index){

    return _terms[index];
}


// utillity function

void Polynomial::sort_terms(Polynomial &p){

    delete_equal_degree(p);
    //bubble sort
    bool flag= true ;
    for (int i=0;i<p._terms.size() && flag;i++)
    {
        flag= false;
        for(int j=p._terms.size()-1;j>i;j--)
        {
            if(p._terms[j].get_power()>p._terms[j-1].get_power() )
            {
                swap(p._terms[j], p._terms[j-1]);
                flag=true;
            }
        }
    }
}

void Polynomial::swap(Term &t1,Term &t2){

    Term temp;
    temp=t1;
    t1=t2;
    t2=temp;

}

void Polynomial::delete_equal_degree(Polynomial &p){

    for(int i=0;i<p._terms.size();i++)
    {
        for(int j=i+1;j<p._terms.size();j++)
        {
            if(p._terms[i].get_power()==p._terms[j].get_power())
            {
                p._terms[i].setcoef(p._terms[i].get_coef()+p._terms[j].get_coef());
                delete_index(p,j);
            }
        }
    }
}

void  Polynomial::delete_index(Polynomial &p, int index){

    if(index!= (p._terms.size()-1))
    {
        for(int i=index;i<p._terms.size()-1;i++)
        {
        p._terms[i]=p._terms[i+1];
        }
    }
    p._terms.resize(p._terms.size()-1);
}

void Polynomial::string_to_polynomial(string index)
{
    int i=0;
    bool flag=true;
    vector<Term> result; //chizi ke return khahad shod
    result.resize(0);
    while (index[i]!='\0')  // ta tamoom shodane string edame dare
    {
        string term="\0";  //halate string
        term.resize(0);
        if (index[i]!='\0')
        {
            flag=true;
            do
            {
                term.push_back(index[i]);
                if(index[i]!='^')
                {
                    if(index[i+1]=='\0' || index[i+1]=='+' || index[i+1]=='-')
                    {
                        flag=false;
                    }
                }
                i++;
            } while (flag);

            Term term_Term;
            term_Term.string_to_term(term);
            if( term_Term.get_coef()!=0)
            {
            result.push_back(term_Term);
            }
            else if(term_Term.get_coef()==0) {
                throw " this term of poly is not valid";
            }
        }
    }
    this->set_terms(result);
}

