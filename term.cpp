#include "term.h"
#include "polynomial.h"
#include <iostream>
using namespace std;

Term::Term(){
    _coef =0;
    _power =0;
}

Term::Term(float coef,int power)
{
    _coef =0;
    _power =0;
    setcoef(coef);
    setpower(power);
}

void Term::setcoef(float coef){

    this->_coef=coef;   // _coef=coef;
}

void Term::setpower(int power){

    this->_power=power;   // _power=power;
}

float Term::get_coef() const{
   return _coef;
}

int Term::get_power() const{
   return _power;
}

istream & operator>>(istream & in,Term &t){

    string index;
    in>>index;
    t.string_to_term(index);
    return in;
}

ostream & operator<<(ostream & out,const Term &t){

    if(t._coef==0)
    {
        out<<0;
        return out;
    }

    if(t._coef!= 1 && t._coef!=-1)
    {
        out<<t._coef;
        if(t._power ==0)
        {
            return out;
        }
        else if(t._power==1)
        {
            out<<'x';
            return out;
        }
        else
        {
            out<<'x'<<'^'<<t._power;
            return out;
        }
    }

    else if(t._coef==1)
    {
        if(t._power ==0)
        {
            out<<1;
            return out;
        }
        else if(t._power==1)
        {
            out<<'x';
            return out;
        }
        else
        {
            out<<'x'<<'^'<<t._power;
            return out;
        }
    }

    else if (t._coef==-1)
    {
        if(t._power ==0)
        {
            out<<-1;
            return out;
        }
        else if(t._power==1)
        {
            out<<'-'<<'x';
            return out;
        }
        else
        {
            out<<'-'<<'x'<<'^'<<t._power;
            return out;
        }
    }

}

Term Term::operator+(const Term &t){

    Term result(_coef,_power);

    if(t._power!=_power){
        throw "powers are not equal" ;  //exception
    }
    else if(t._power==_power)
    {
        result._coef += t._coef;
    }
    return result;
}

Term Term::operator-(const Term& t){

    Term result(_coef,_power);

    if(t._power!=_power){
        throw "powers are not equal" ; //exception
    }
    else if(t._power==_power)
    {
        result._coef -= t._coef;
    }

      return result;
}

Term Term::operator*(const Term& t){

    Term result(_coef,_power);
    result._coef *= t._coef;
    result._power +=t._power;

    return result;
}

Term Term::operator/(const Term& t){

    Term result(_coef,_power);
    result._coef /= t._coef;
    result._power -=t._power;

    return result;
}

Term& Term::operator+=(const Term& t){

    if(t._power==_power)
    {
        _coef += t._coef;
    }
    return *this;
}

Term& Term::operator-=(const Term& t){

    if(t._power==_power)
    {
        _coef -= t._coef;
    }
    return *this;
}

Term& Term::operator*=(const Term& t){

    _coef *= t._coef;
    _power +=t._power;
    return *this;
}

Term& Term::operator/=(const Term& t){

    _coef /= t._coef;
    _power -=t._power;
    return *this;
}

Term& Term::operator=(const Term &t){

    _coef = t._coef;
    _power =t._power;

    return *this;
}

bool Term::operator>(const Term& t){

    if(_power>t._power)
    {
        return true;
    }
    else if(_power==t._power){
        if(_coef>t._coef){
            return true;
        }
    }
    return false;

}

bool Term::operator<(const Term& t){

    if(_power<t._power)
    {
        return true;
    }
    else if(_power==t._power){
        if(_coef<t._coef){
            return true;
        }
    }
    return false;

}

bool Term::operator<=(const Term& t){

    if(_power<t._power)
    {
        return true;
    }
    else if(_power==t._power){
        if(_coef<t._coef || _coef==t._coef){
            return true;
        }
    }
    return false;

}

bool Term::operator>=(const Term& t){

    if(_power>t._power)
    {
        return true;
    }
    else if(_power==t._power){
        if(_coef>t._coef || _coef==t._coef){
            return true;
        }
    }
    return false;

}

bool Term::operator==(const Term& t){

   if(_power==t._power){
        if(_coef==t._coef){
            return true;
        }
    }
    return false;

}

bool Term::operator!=(const Term& t){

    if(*this==t){
        return false;
     }
     return true;
}

Term Term::operator~(){

    Term result;
    result._coef =(_coef * _power);
    result._power= (_power-1);

    return result;
}

Term& Term::operator++(){

    Term temp(1,0);
    *this = *this + temp;

    return *this;
}

Term& Term::operator--(){

    Term temp(1,0);
    *this = *this - temp;

    return *this;
}

float Term::operator()(float f){
    float temp=0;
     cout<<f<<"\n";
    if(_power>0)
    {
        temp=1;
        for(int i=0;i<_power;i++)
        {
            temp*=f;
        }
    }
    else if(_power<0)
    {
        temp=1;
        for(int i=0;i<-(_power);i++)
        {
            temp*=f;
        }
        temp =1/temp;
    }

    temp *= _coef;

    return temp;
}


// utility

void Term::string_to_term(string index)
{
    int i=0;
    float coef_int=1;   //coef be halate int
    int power_int;  // power be halate int

    if ( index[i]=='+' )
        i++;

    else if(index[i]=='-')
    {
        i++;
        coef_int=-1;
    }

    char coef[10]={'\0'};   //coef be halate string
    for(int j=0; char_to_num(index[i])==-1 && i<index.length(); j++) // bade zarib, charactere badi ya 'x' hast, ya '-', ya '+'
    {
        coef[j]=index[i++];
    }

    if (coef[0]!='\0') // check mikonim bebinim aya string coef por shode dar halgheye bala ya na
    {
        coef_int*=string_to_num(coef);
    }

    char exp[10]={'\0'};  //exp be halate string
    if (i<index.length() && char_to_num(index[i])!=-1)
    {
        if(index[++i]!='^')
            power_int=1;

        else
        {
            i++; //berim soraghe charactere bad az '^'
            int alamat=1;
            if ( index[i]=='+' )
                i++;

            else if(index[i]=='-')
            {
                i++;
                alamat=-1;
            }

            for(int j=0; i<index.length(); j++) // bade tavan, charactere badi ya '-' hast, ya '+'
            {
                exp[j]=index[i++];
            }
            power_int=string_to_num(exp)*alamat;
        }
    }

    else
    {
        power_int=0;
    }

    this->setcoef(coef_int);
    this->setpower(power_int); // tanzime coef va exp Term
}

float Term::string_to_num(string index)
{
    string temp;
    temp.resize(0);
    float sum=0;
    float sum_float=0;
    float sum_int =0;
    int index_dat=-1;
    bool flag=true;

    for(int i=0; index[i]!='\0' && flag; i++)
    {
        if(index[i]=='.')
        {
            index_dat=i;
            flag=false;
        }
        else if(index[i]!='.')
        {
        sum_int*=10;
        sum_int=sum_int+( int(index[i])-48 );
        }
    }
    float temp1;
    if(!flag){
    for(int i=index.size()-1;i>index_dat && index[i]!='\0'; i--)
    {
        sum_float*=0.1;
        temp1=(int(index[i])-48);
        sum_float=sum_float+(temp1*0.1 );
    }}


    sum=sum_float+sum_int;

    return sum;
}

int Term::char_to_num(char c){

    int num=c;
    if(num>=97 && num<=122){
    return num;}
    else if(num>=65 && num<=90){
    return num;
    }
    else{return -1;}
}

