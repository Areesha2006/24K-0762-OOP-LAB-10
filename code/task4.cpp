#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
int main(){
    ifstream file;
    file.open("vehicle.txt",ios::in);
    if(file.is_open()){
        std::string line;
        while(getline(file,line)){
            if(!(line.find(' ')==0||line.substr(0,2)=="//")){
                istringstream input_line(line);
                std::string Type,ID,Name,Year,ExtraData;
                getline(input_line,Type,',');
                getline(input_line,ID,',');
                getline(input_line,Name,',');
                getline(input_line,Year,',');
                getline(input_line,ExtraData,',');
                if(Type=="AutonomousCar"){
                    size_t position;
                    position=ExtraData.find(':');
                    if(position!=std::string::npos){
                    std::string software_version_in_string=ExtraData.substr(position+1);
                        float software_version_in_float=stof(software_version_in_string);
                        cout<<"Type: "<<Type<<endl;
                        cout<<"ID: "<<ID<<endl;
                        cout<<"Software Version: "<<software_version_in_float<<endl<<endl;
                    }                    
                }
                else{
                    if(Type=="ElectricVehicle"){
                        size_t position;
                        position=ExtraData.find(':');
                        if(position!=std::string::npos){
                            std::string battery_capacity_in_string=ExtraData.substr(position+1);
                            int battery_capacity_in_int=stof(battery_capacity_in_string);
                            cout<<"Type: "<<Type<<endl;
                            cout<<"ID: "<<ID<<endl;
                            cout<<"Software Version: "<<battery_capacity_in_int<<endl<<endl;
                        }
                    }
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