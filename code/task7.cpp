#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream file;
    file.open("sensor_log.tct",ios::out);
    file<<"Sensor 1: 25.5 C"<<endl; 
    streampos pos=file.tellp();
    cout<<"Position after performing write operation: "<<pos<<endl;
    file<<"Sensor 2: 98.1 %RH"<<endl;
    pos=file.tellp();
    cout<<"Position after performing write operation: "<<pos<<endl;
    file.close(); 
    return 0;
}