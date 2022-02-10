#include<iostream>
#include<conio.h>
using namespace std;

typedef struct Sensor{
    int number;
    float s;
    char div;
}SensorValues;

uint8_t *bufferr[sizeof(SensorValues)];

void sendValues(SensorValues *values)
{
    writeBytes((uint8_t*)values, sizeof(SensorValues));
}

void writeBytes(uint8_t *buf, uint8_t len)
{
    std::cout<<"Writing values";
    //Wire.beginTransmission(EDGE_I2C_ADDR);

    for(uint8_t i = 0; i < len; i++) {
        bufferr[i] = &buf[i];
        std::cout<<buf[i]<< " "; 
       // Wire.write(buf[i]);
    }

    std::cout<<endl;

    //Wire.endTransmission();
}


int main()
{   
    SensorValues val1;
    val1.number=10;
    val1.s=0.5;
    val1.div ='a';
    sendValues(&val1);
    getch();
}