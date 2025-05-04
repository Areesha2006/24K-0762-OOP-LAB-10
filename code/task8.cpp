#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream file1;
    file1.open("config.txt");
    file1<<"AAAAABBBBBCCCCCC";
    file1.close();
    fstream file2;
    file2.open("config.txt",ios::in|ios::out);
    file2.seekp(5,ios::beg);
    file2<<"XXXXX";
    file2.close();
    file2.open("config.txt",ios::in|ios::out);
    string line;
    file2.seekp(0);
    file2>>line;
    cout<<line;
    file2.close();
    return 0;
}