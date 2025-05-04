#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
int main(){
    ifstream file;
    file.open("vehicle.txt",ios::in);
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            if(!(line.find(' ')==0||line.substr(0,2)=="//")){
                istringstream input_line(line);
                string Type,ID,Name,Year,ExtraData,Certification;
                getline(input_line,Type,',');
                getline(input_line,ID,',');
                getline(input_line,Name,',');
                getline(input_line,Year,',');
                getline(input_line,ExtraData,',');
                getline(input_line,Certification);
                cout<<line<<endl;
                cout<<"Type: "<<Type<<endl;
                cout<<"ID: "<<ID<<endl;
                cout<<"Name: "<<Name<<endl;
                cout<<"Year: "<<Year<<endl;
                cout<<"Extra Data: "<<ExtraData<<endl;
                cout<<"Certification: "<<Certification<<endl<<endl;
            }            
        }
    }
    else{
        cout<<"File not opened"<<endl;
        exit(1);
    }
    return 0;
}