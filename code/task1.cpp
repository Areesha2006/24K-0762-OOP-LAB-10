#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream file;
    file.open("vehicle.txt",ios::in);
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            cout<<line<<endl;
        }
    }
    else{
        cout<<"File not opened"<<endl;
        exit(1);
    }
    return 0;
}