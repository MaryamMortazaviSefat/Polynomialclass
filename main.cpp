#include <iostream>
#include <fstream>
#include  "term.h"
#include "polynomial.h"
using namespace std;

void main_menu( Polynomial & current_polynomial);
void polynomial_menu( Polynomial & current_polynomial);

int main()
{
    Polynomial current_polynomial;
    Term temp;
    cout<<" IN THE NAME OF GOD\n Hi"<<"\n"<<"Well come"<<"\n";
    cout<<"Mohammad Mahdi Sheikhzade & Maryam Mortazavi sefat"<<"\n";
    main_menu(current_polynomial);
    return 0;

}

void main_menu( Polynomial & current_polynomial){

    int option=0;
    string file_name;

    cout<<"choose one option, please."<<"\n";
    cout<<"1- New Polynomial "<<"\n";
    cout<<"2- Load from text file "<<"\n";
    cout<<"3- Load from binary file "<<"\n";
    cout<<"4- Quit "<<"\n";

    cin>>option;

    if(option==1)
    {
        polynomial_menu(current_polynomial);
    }
    else if(option==2)
    {
        cin>>file_name;
        ifstream in_text_file;
        in_text_file.open(file_name,ios::in);

        if(!in_text_file)
        {
            cerr<<"not found"<<"\n";
            exit(1);
        }


            in_text_file>>current_polynomial;
            cout<<current_polynomial<<"\n";

        polynomial_menu(current_polynomial);
    }
    else if(option==3)
    {
        cin>>file_name;
        ifstream in_binary_file;
        in_binary_file.open(file_name,ios::in | ios::binary);

        if(!in_binary_file)
        {
            cerr<<"not found"<<"\n";
            exit(1);
        }

       in_binary_file.read(reinterpret_cast<char *>(& current_polynomial),sizeof (Polynomial));

               cout<<current_polynomial<<"\n";

       polynomial_menu(current_polynomial);
    }
    else if(option==4)
    {
        cout<<"good job"<<"\n";
    }

}

void polynomial_menu( Polynomial &current_polynomial){

    int option=0;
    Polynomial input;
    float input_float=0;
    string file_name;

    cout<<"current polynomial = "<< current_polynomial<<"\n";
    cout<<"polynomial menu:"<<"\n";
    cout<<"1- Add"<<"\n";
    cout<<"2- Subtract"<<"\n";
    cout<<"3- Multiply"<<"\n";
    cout<<"4- Derivative"<<"\n";
    cout<<"5- Find Degree"<<"\n";
    cout<<"6- Find Value for specific x"<<"\n";
    cout<<"7- Compare"<<"\n";
    cout<<"8- Save to a text file"<<"\n";
    cout<<"9- Save to a binary file"<<"\n";
    cout<<"10-    Back to Main Menu"<<"\n";

    cin>>option;


    if(option==1)
    {
        cin>>input;
        current_polynomial += input;
    }
    else if(option==2)
    {
        cin>>input;
        current_polynomial -= input;
    }
    else if(option==3)
    {
        cin>>input;
        current_polynomial *= input;
    }
    else if(option==4)
    {
        current_polynomial =~current_polynomial ;
    }
    else if(option==5)
    {
        cout<<current_polynomial.get_polynomial_degree();
    }
    else if(option==6)
    {
        cin>>input_float;
        cout<<current_polynomial(input_float);
    }
    else if(option==7)
    {
        cin>>input;
        cout<<" *Comparing Current_Polynomial with Other_Polynomial "<<"\n";

        cout<<"Current_Polynomial > Other_Polynomial : ";
        if((current_polynomial>input))
        {
            cout<<"true\n";
        }
        else if(!(current_polynomial>input))
        {
            cout<<"false\n";
        }

        cout<<"Current_Polynomial >= Other_Polynomial : ";
        if((current_polynomial>=input))
        {
            cout<<"true\n";
        }
        else if(!(current_polynomial>=input))
        {
            cout<<"false\n";
        }

        cout<<"Current_Polynomial < Other_Polynomial : ";
        if((current_polynomial<input))
        {
            cout<<"true\n";
        }
        else if(!(current_polynomial<input))
        {
            cout<<"false\n";
        }

        cout<<"Current_Polynomial <= Other_Polynomial : ";
        if((current_polynomial<=input))
        {
            cout<<"true\n";
        }
        else if(!(current_polynomial<=input))
        {
            cout<<"false\n";
        }

        cout<<"Current_Polynomial == Other_Polynomial : ";
        if((current_polynomial==input))
        {
            cout<<"true\n";
        }
        else if(!(current_polynomial==input))
        {
            cout<<"false\n";
        }

    }
    else if(option==8)
    {
        cin>>file_name;
        ofstream out_text_file;
        out_text_file.open(file_name,ios::out);

        if(!out_text_file)
        {
            cerr<<"not found"<<"\n";
            exit(EXIT_FAILURE);
        }

       out_text_file<<" "<<current_polynomial;

    }
    else if(option==9)
    {
        cin>>file_name;
        ofstream out_binary_file;
        out_binary_file.open(file_name,ios::out | ios::binary);

        if(!out_binary_file)
        {
            cerr<<"not found"<<"\n";
            exit(EXIT_FAILURE);
        }


       out_binary_file.write(reinterpret_cast<const char *>(&current_polynomial),sizeof (Polynomial));
    }
    else if(option==10)
    {
        main_menu(current_polynomial);
    }

    option=0;
    cout<<"Do you want to back to main menu?"<<"\n";
    cout<<"1.no\n"<<"2.yes\n";
    cin>>option;

    if(option==2)
    {
        main_menu(current_polynomial);
    }
    else
    {
        cout<<"good job.\n";
    }

}





