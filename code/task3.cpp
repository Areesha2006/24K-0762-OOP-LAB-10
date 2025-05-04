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
                string Type,ID,Name,Year;
                getline(input_line,Type,',');
                getline(input_line,ID,',');
                getline(input_line,Name,',');
                getline(input_line,Year,',');
                bool is_year_valid=true;
                for(int i=0;i<Year.size();i++){
                    if(!(Year[i]>='0'&&Year[i]<='9')){
                        is_year_valid=false;
                        break;
                    }
                }
                if(is_year_valid){
                    int year_in_int=stoi(Year);
                    cout<<line<<endl<<"Year: "<<year_in_int<<endl<<endl;
                }
                else{
                    cout<<"The purpose of stoi is to covert string to integer"<<endl<<endl;
                }
            }            
        }
    }
    else{
        cout<<"File not opened"<<endl;
        exit(1);
    }
    return 0;
}