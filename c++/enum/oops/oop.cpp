#include<iostream>
#include<conio.h>
using namespace std;
class rando{
    private: // by default private
    int a,b;
    public:
    int avalue()
    {
        return a;
    }
    void sum(){
        int s=0;
        a=1;
        b=9;
        s=a+b;
        cout<<s;
    }
}s1;
int main(){
    rando obj; // creating an object syntax: classname objectname;
    cout<<obj.avalue()<<endl;
    obj.sum();
    cout<<endl<<obj.avalue();
    getch();
}