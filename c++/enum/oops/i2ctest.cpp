#include<iostream>
#include<conio.h>
using namespace std;
class I2C{
    int c,d;
    static int count;
    public:
    I2C(){
        c=0,d=2;
        ++count; // static varible counter to find out number of objects created
    } //constructor: used to intialize value when created
    void write_address(){
        cout<<"Hello World";
    }
    void display();
};
int I2C::count=0; // staic varible 
void I2C::display(){
    cout<<endl<<"display function"<<count;
}
extern I2C i2c,i3c; // declarion of the object (re)
I2C i2c;
int main(){
    i2c.write_address();
    i2c.display();
    I2C i3c;
    i3c.display();
    getch();
}