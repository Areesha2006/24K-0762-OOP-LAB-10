#include<iostream>
#include<fstream>
using namespace std;
class InventoryItem{
    public:
        int itemID;
        char itemName[20];
};
int main(){
    ofstream output_file;
    InventoryItem item1;
    output_file.open("inventory.dat",ios::binary);
    cout<<"Enter item id: ";
    cin>>item1.itemID;
    cout<<"Enter item name: ";
    cin>>item1.itemName;
    output_file.write((char*)&item1,sizeof(item1));
    output_file.close();
    ifstream input_file;
    input_file.open("inventory.dat",ios::binary);
    InventoryItem item2;
    input_file.read((char*)&item2,sizeof(item2));
    cout<<endl<<"Item ID: "<<item2.itemID<<endl;
    cout<<"Item Name: "<<item2.itemName;
    input_file.close();
    return 0;
}