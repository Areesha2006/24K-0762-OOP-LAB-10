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
                else if(Type=="ElectricVehicle"){
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
                else if(Type=="HybridTruck"){
                    size_t pos_colon,pos_pipe;
                    pos_colon=ExtraData.find(':');
                    pos_pipe=ExtraData.find('|');
                    cout<<"Type: "<<Type<<endl;
                    cout<<"ID: "<<ID<<endl;
                    if(pos_colon!=std::string::npos){
                        std::string cargo_valiue_in_string=ExtraData.substr(pos_colon+1,pos_pipe-pos_colon-1);
                        int cargo_value_in_int=stoi(cargo_valiue_in_string);
                        cout<<"Cargo Value: : "<<cargo_value_in_int<<endl;
                    }
                    if(pos_pipe!=std::string::npos){
                        std::string battery=ExtraData.substr(pos_pipe+1,ExtraData.size()-pos_pipe-1);
                        cout<<battery<<endl;                        
                        size_t pos_colon=battery.find(':');
                        if(pos_colon!=std::string::npos){
                            std::string battery_value_in_string=battery.substr(pos_colon+1,battery.size()-pos_colon-1);
                            int battery_value_in_int=stoi(battery_value_in_string);
                            cout<<"Battery Value: "<<battery_value_in_int<<endl<<endl;    
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