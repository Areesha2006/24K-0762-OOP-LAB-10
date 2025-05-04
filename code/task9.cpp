#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream file;
    char content[11];
    file.open("large_log.txt");
    if(file.is_open()){
        file.read(content,10);
        cout<<"Current Position after reading 1st time: "<<file.tellg()<<endl;
        file.read(content,10);
        cout<<"Current Position after reading 2nd time: "<<file.tellg()<<endl;
        file.close();
    }
    else{
        cout<<"File not opened";
        exit(1);
    }
    return 0;
}