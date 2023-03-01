#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std; //allows syntax without std::
struct apartment{ //structure of apartment
    int number; // apartment number
    int monthly_rent; //monthly rent
    int max_tenants; //max tenants
    int num_tenants; //number of tenants
    string tenants[10]; //array of tenants within the apartment
};
void load(string fname, apartment apartments[], int &num){ //load function
    ifstream s; //input stream of file
    int temp, temp1, temp2, temp3;
    string temp4;
    int totalMonthlyRent, totalOccupied;
    s.open(fname);
    if(!s.is_open() && !s.good()){ //returns if file isn't valid
        return;
    }
    else{
        while(s.good() && !s.eof()){ 
            s >> num;
            for(int i = 0; i < num; i++){
                s >> apartments[i].number;
                s >> apartments[i].monthly_rent;
                s >> apartments[i].max_tenants;
                s >> apartments[i].num_tenants;
                s.ignore();
                for(int j = 0; j < apartments[i].num_tenants; j++){
                    getline(s, apartments[i].tenants[j]);
                }

            }
            for(int i = 0; i < num; i++){ //sorts them in ascending order by monthly rent
                for(int j = i + 1; j < num; j++){
                    if(apartments[i].monthly_rent > apartments[j].monthly_rent){
                        temp = apartments[i].number; 
                        apartments[i].number = apartments[j].number;
                        apartments[j].number = temp;
                        temp1 = apartments[i].monthly_rent;
                        apartments[i].monthly_rent = apartments[j].monthly_rent;
                        apartments[j].monthly_rent = temp1;
                        temp2 = apartments[i].max_tenants;
                        apartments[i].max_tenants = apartments[j].max_tenants;
                        apartments[j].max_tenants = temp2;
                        temp3 = apartments[i].num_tenants;
                        apartments[i].num_tenants = apartments[j].num_tenants;
                        apartments[j].num_tenants = temp3;
                        for(int k = 0; k < apartments[i].num_tenants; k++){
                            temp4 = apartments[i].tenants[k];
                            apartments[i].tenants[k] = apartments[j].tenants[k];
                            apartments[j].tenants[k] = temp4;

                        }


                    }
                }
            }
            for(int i = 0; i < num; i++){
                cout << "Apartment #" << apartments[i].number << ":" << endl;
                cout << "Monthly Rent: $" << apartments[i].monthly_rent << endl;
                cout << "Max # of tenants: " << apartments[i].max_tenants << endl;
                cout << "Number of Tenants: " << apartments[i].num_tenants << endl;
                if(apartments[i].num_tenants == 0){
                    cout << "";
                }
                else{
                    cout << "Tenants: ";
                    for(int j = 0; j < apartments[i].num_tenants; j++){
                        if((j < apartments[i].num_tenants - 1)){
                            cout << apartments[i].tenants[j] << ", ";
                        }
                        else{
                            cout << apartments[i].tenants[j] << endl;
                        }
                    }
                }
                cout << "---" << endl;
            }
            
            totalMonthlyRent = 0;
            totalOccupied = 0;
            for(int i = 0; i < num; i++){
                if(apartments[i].num_tenants > 0){
                    totalMonthlyRent += apartments[i].monthly_rent;
                    totalOccupied++;
                }
            }
            cout << "Total Monthly Rent Collected: $" << totalMonthlyRent << endl;
            cout << "Number of occupied units: " << totalOccupied << "/" << num << endl;
            cout << "---" << endl;
            s.close();
        }
    }
}
void list_available_apartments(apartment apartments[], int &num){ //prints all avaliable apartments
    for(int i = 0; i < num; i++){
        if(apartments[i].num_tenants < apartments[i].max_tenants){
            cout << "Apartment #" << apartments[i].number << ":" << endl;
            cout << "Monthly Rent: $" << apartments[i].monthly_rent << endl;
            cout << "Max # of Tenants: " << apartments[i].max_tenants << endl;
        }
        cout << "---" << endl;
    }
}
void move_out(string tenant_name, apartment apartments[], int num_apartments){ //remove tenant
    bool p = false;
    string temp;
    int index;
    int index2;
    for(int i = 0;i < num_apartments; i++){
        for(int j = 0; j < apartments[i].num_tenants; j++){
            if(tenant_name == apartments[i].tenants[j]){
                index = i;
                index2 = j;
                apartments[i].tenants[j] = "";
                cout << "Successfully moved out." << endl;
                p = true;
            }
            

        }
    }
    if(p == false){
        cout << "Error, there are no tenants with that name!" << endl;
    }
    else{
        
        for(int i = index2; i < apartments[index].num_tenants; i++){
            apartments[index].tenants[i] = apartments[index].tenants[i + 1];
        }
        apartments[index].num_tenants--;
    }
}

void menu(){
    cout << "Main Menu" << endl;
    cout << "1- List All Apartments" << endl;
    cout << "2- List Available Apartments" << endl;
    cout << "3- Move In" << endl;
    cout << "4- Move Out" << endl;
    cout << "5- Find Tenant" << endl;
    cout << "6- Save" << endl;
    cout << "7- Load" << endl;
    cout << "8- Exit" << endl;
    cout << "Please enter your choice:" << endl;
}
void move_in(string tenant_name, int apartment_num, apartment apartments[], int num_apartments){ //adds tenants
        bool p = false;
        int index;
        for(int i = 0; i < num_apartments; i++){
            if(apartments[i].number == apartment_num){
                if(apartments[i].num_tenants < apartments[i].max_tenants){
                    cout << "Successfully moved in!" << endl;
                    p = true;
                    index = i;
                    for(int j = 0; j < apartments[i].max_tenants;j++){
                        if(apartments[i].tenants[j] == ""){
                            apartments[i].tenants[j] = tenant_name;
                            break;
                        }  
                    }  
                
                }
            }

        }
        if(p == false){
            cout << "Error, the apartment cannot hold any more tenants!" << endl;
        }
        else{
            apartments[index].num_tenants++;
        }




}
void save(string fname, apartment apartments[], int num){ //create new file and saves info
    ofstream nFile;
    nFile.open(fname);
    if(!nFile.is_open() && !nFile.good()){
        return;
    }
    else{        
        nFile << num << endl;
        for(int i = 0; i < num; i++){
            nFile << apartments[i].number << endl;
            nFile << apartments[i].monthly_rent << endl;
            nFile << apartments[i].max_tenants << endl;
            nFile << apartments[i].num_tenants << endl;
            for(int j = 0; j < apartments[i].num_tenants; j++){
                nFile << apartments[i].tenants[j] << endl;
            }
         }
    nFile.close();
    }
}
void list_all_apartments(apartment apartments[], int& num){ //prints all apartments
    int totalMonthlyRent, totalOccupied;
    for(int i = 0; i < num; i++){
        cout << "Apartment #" << apartments[i].number << ":" << endl;
        cout << "Monthly Rent: $" << apartments[i].monthly_rent << endl;
        cout << "Max # of tenants: " << apartments[i].max_tenants << endl;
        cout << "Number of Tenants: " << apartments[i].num_tenants << endl;
        if(apartments[i].num_tenants == 0){
            cout << "";
        }
        else{
            cout << "Tenants: ";
            for(int j = 0; j < apartments[i].num_tenants; j++){
                if((j < apartments[i].num_tenants - 1)){
                    cout << apartments[i].tenants[j] << ", ";
                }
                else{
                    cout << apartments[i].tenants[j] << endl;
                        }
                }
            totalMonthlyRent = 0;
            totalOccupied = 0;
            for(int i = 0; i < num; i++){
                if(apartments[i].num_tenants > 0){
                    totalMonthlyRent += apartments[i].monthly_rent;
                    totalOccupied++;
                        }
                    }
                    
                }
                
                cout << "---" << endl;
            } 
        cout << "Total Monthly Rent Collected: $" << totalMonthlyRent << endl;
        cout << "Number of occupied units: " << totalOccupied << "/" << num << endl;
        cout << "---" << endl;
        }
int main(){
    int num, apartNum, input;
    apartment arr[10];
    string fileName, tName, apartName, mName, file2, file_name;
    ifstream file; // allow input file stream
    cout << "Please enter the name of the file to load:" << endl;
    cin >> file_name;
    load(file_name, arr, num);
    menu();
    cin >> input;
    if(input < 1 || input > 8 || isalpha(input)){
        cout << "Invalid option!";
    }
    else{
        while(input != 8){
            if(input == 1){
               list_all_apartments(arr, num);
            }
            else if(input == 2){
                list_available_apartments(arr, num);
            }
            else if(input == 3){
                cout << "Enter the apartment number to move in:" << endl;
                cin >> apartNum;
                cout << "Enter the name of the tenant:" << endl;
                cin.ignore();
                getline(cin, apartName);
                move_in(apartName, apartNum, arr, num);
                }
            else if(input == 4){
                cout << "Enter the name of the tenant moving out:" << endl;
                cin.ignore();
                getline(cin, mName);
                move_out(mName, arr, num);
            }
            else if(input == 5){
                cout <<  "Enter the name of the tenant to search for:" << endl;
                cin.ignore();
                getline(cin, tName);
                bool z = false;
                for(int i = 0;i < num; i++){
                    for(int j = 0; j < arr[i].num_tenants; j++){
                        if(tName == arr[i].tenants[j]){
                            cout << tName << " is in apartment #" << arr[i].number << "!" << endl;
                            z = true;
                        }
                    }
                }
                if(z == false){
                    cout << "Error, tenant not found!" << endl;
                }
            }
            else if(input == 6){
                cin >> fileName;
                save(fileName, arr, num);
            }
            else if(input == 7){
                cout << "Enter the file name to load from:" << endl;
                cin >> file2;
                load(file2, arr, num);
            }
            else{
                cout << "Invalid option!" << endl;
            }

            menu();
            cin >> input;
        }

    }


}
