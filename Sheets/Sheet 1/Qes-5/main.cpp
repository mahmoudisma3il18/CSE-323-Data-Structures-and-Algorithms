/*
 Author : Mahmoud Ismail
 Date   : 24/10/2022
*/

/*----------------------------- Includes ----------------------------*/
#include <iostream>

using namespace std;


/*------------------------- Classes ---------------------------------*/

class email_book {
private :
    int MAX_SIZE;
    string *emails;
    string *names;
    int book_size ;


public:
    email_book(int MAX_SIZE = 100) {
        this->MAX_SIZE = MAX_SIZE;
        emails = new string [MAX_SIZE];
        names  = new string [MAX_SIZE];
        book_size = 0;
    }

    string getName(int index) {
        if(index < 0  &&  index > MAX_SIZE)
            return "Wrong Index";
        else
            return names[index];
    }

    void setName(string name,int index) {
        if(index < 0  &&  index > MAX_SIZE);

        else{
            this->names[index] = name;
            book_size++;
        }

    }

    void printAll(void) {
        for(int i = 0 ; i < book_size ; i++ )
            cout<<"Book Name: "<<names[i]<<endl;

    }

    ~email_book() {
        delete [] emails;
        delete [] names;
    }


} ;


int main()
{
    email_book book1;
    book1.setName("Mahmoud",0);
    book1.setName("Ismail",1);
    book1.printAll();
    return 0;
}
