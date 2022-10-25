/*
 Author : Mahmoud Ismail
 Date   : 26/10/2022
*/

#include <iostream>

using namespace std;

class Box {
private :
    int l;
    int b;
    int h;

    public :
    Box(){
        l=b=h=0;
    }
    Box(int lenght,int breadth , int height){
        l = lenght;
        h = height;
        b = breadth;
    }
    Box(const Box &box){
        l = box.l;
        h = box.h;
        b = box.b;
    }

    int getLength(){
        return l;
    }
    int getBreadth(){
        return b;
    }
    int getHeight(){
        return h;
    }
    long long CalculateVolume(){
        return ((long long)l*b*h);
    }
   friend bool operator < (Box& b1, Box& b2)
        {
            if((b1.l < b2.l) || (b1.l == b2.l && b1.b < b2.b) ||
               (b1.l == b2.l && b1.b == b2.b && b1.h <b2.h))
                return(true);
            else
                return(false);
        }

        friend ostream& operator << (ostream& s,Box& b1)
        {
            s << b1.l << " " << b1.b << " " << b1.h;
            return s;
        }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
