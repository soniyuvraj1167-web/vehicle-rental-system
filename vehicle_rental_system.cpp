#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle
{
private:
    string vehicleId;
    string Brand;
    string Model;
    int pricePerDay;
    bool Availability;

public:
    Vehicle(string id, string brand, string model, int ppd)
    {
        this->vehicleId = id;
        this->Brand = brand;
        this->Model = model;
        this->pricePerDay = ppd;
        this->Availability = true;
    }

    void displayDetail(){

        cout << "Vehicle ID: " << vehicleId << endl;
        cout << "Brand: " << Brand << endl;
        cout << "Model: " << Model << endl;
        cout << "Price Per Day: Rs. " << pricePerDay << endl;

        if (Availability) {
            cout << "Status: Available" << endl;
        } else {
            cout << "Status: Rented" << endl;
        }
    }
};

void addVehicle(vector<Vehicle> &vehicles)
{
    string id;
    cout << "\nEnter Vehicle Id : ";
    cin >> id;
    string brand;
    cout << "Enter Brand : ";
    cin >> brand;
    string model;
    cout << "Enter Model : ";
    cin >> model;
    int price;
    cout << "Enter Price per Day : ";
    cin >> price;
    Vehicle newVehicle(id, brand, model, price);
    vehicles.push_back(newVehicle);
    cout << "\n----Vehicle Added Sucessfully----";
}

void displayVehicle(vector<Vehicle> vehicles){
    if(vehicles.empty()){
        cout << "----No Vehicle----" << endl;
    }else{
        cout << "\n----All Vehicles----\n";
        for(Vehicle& vehicle : vehicles){
            vehicle.displayDetail();
        }
    }
}

int main()
{
    vector<Vehicle> vehicles;
    bool f = true;
    while (f)
    {
        // cout << endl;
        cout << endl << "1. Add Vehicle\n2. Display All Vehicles\n3. Exit\n\nEnter your choice:";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            addVehicle(vehicles);
        }
        else if (choice == 2)
        {
            displayVehicle(vehicles);
        }
        else if (choice == 3)
        {
            cout << "Exiting Vehicle Rental System...";
            f = false;
        }
        else
        {
            cout << "Invalid choice! Please try again.";
        }
    }

    return 0;
}