#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream file;
    file.open("data_records.txt");
    if(!file){
        cout<<"File not opened";
        exit(1);
    }
    else{
        string line;
        file.seekg(0,ios::beg);
        file.seekg(20,ios::beg);
        getline(file,line);
        cout<<line<<endl;
        file.close();
    }
    return 0;
}