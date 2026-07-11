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

    void displayDetail()
    {

        cout << "Vehicle ID: " << vehicleId << endl;
        cout << "Brand: " << Brand << endl;
        cout << "Model: " << Model << endl;
        cout << "Price Per Day: Rs. " << pricePerDay << endl;

        if (Availability)
        {
            cout << "Status: Available" << endl;
        }
        else
        {
            cout << "Status: Rented" << endl;
        }
    }

    string getVehicleID()
    {
        return vehicleId;
    }

    string getBrand()
    {
        return Brand;
    }

    string getModel()
    {
        return Model;
    }

    int getprice()
    {
        return pricePerDay;
    }

    void setBrand(string b)
    {
        Brand = b;
    }

    void setModel(string m)
    {
        Model = m;
    }

    bool setPrice(int p)
    {
        if (p > 0)
        {
            pricePerDay = p;
            return true;
        }

        return false;
    }
};

void addVehicle(vector<Vehicle> &vehicles)
{
    string id;
    cout << "\nEnter Vehicle Id : ";
    cin >> id;

    int f = 1;
    for (Vehicle vehicle : vehicles)
    {
        if (vehicle.getVehicleID() == id)
        {
            f = 0;
        }
    }
    if (f == 0)
    {
        cout << "Error: Vehicle ID " << id << " already exists.\n";
        cout << "Vehicle not added.";
    }
    else
    {
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
}

void displayVehicle(vector<Vehicle> &vehicles)
{
    if (vehicles.empty())
    {
        cout << "----No Vehicle Found in System----" << endl;
    }
    else
    {
        cout << "\n----All Vehicles----\n";
        for (Vehicle &vehicle : vehicles)
        {
            vehicle.displayDetail();
        }
    }
}

void searchVehicle(vector<Vehicle> &vehicles)
{
    string id;
    cout << "Enter Vehicle ID to search : ";
    cin >> id;
    int f = 0;

    for (Vehicle vehicle : vehicles)
    {
        if (vehicle.getVehicleID() == id)
        {
            cout << "----Vehicle Found----";
            vehicle.displayDetail();
            f = 1;
            break;
        }
    }
    if (f == 0)
    {
        cout << "Vehicle with ID " << id << " not found.";
    }
}

void updateVehicle(vector<Vehicle> &vehicles)
{
    string id;
    cout << "Enter Vehicle ID to update: ";
    cin >> id;
    int f = 0;
    for (Vehicle &vehicle : vehicles)
    {
        if (vehicle.getVehicleID() == id)
        {
            f = 1;
            cout << "----Vehicle Found----";
            vehicle.displayDetail();
            cout << endl;
            cout << "1. Update Brand\n";
            cout << "2. Update Model\n";
            cout << "3. Update Price Per Day\n";
            cout << "4. Cancel\n";

            int ch;
            cout << "Enter your choice: ";
            cin >> ch;

            if (ch == 1)
            {
                string brand;
                cout << "Enter new Brand name : ";
                cin >> brand;

                vehicle.setBrand(brand);

                cout << "Brand Updated Successfully!";
            }
            else if (ch == 2)
            {
                string model;
                cout << "Enter new Model name : ";
                cin >> model;

                vehicle.setModel(model);

                cout << "Model Updated Successfully!";
            }
            else if (ch == 3)
            {
                int price;
                cout << "Enter new Price per Day : ";
                cin >> price;

                if (vehicle.setPrice(price))
                {
                    cout << "Price Updated Successfully!";
                }
                else
                {
                    cout << "Invalid price! Price must be greater than 0.";
                }
            }
            else if (ch == 4)
            {
                break;
            }
            else
            {
                cout << "Invalid Choice !!!!";
                break;
            }

            break;
        }
    }
    if (f == 0)
    {
        cout << "Vehicle with ID " << id << " not found.";
    }
}

int main()
{
    vector<Vehicle> vehicles;
    bool f = true;
    while (f)
    {
        // cout << endl;
        cout << endl
             << "1. Add Vehicle\n";
        cout << "2. Display All Vehicles\n";
        cout << "3. Search Vehicle\n";
        cout << "4. Update Vehicle\n";
        cout << "5. Exit\n";
        cout << "Enter your choice:";
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
            searchVehicle(vehicles);
        }
        else if (choice == 4)
        {
            updateVehicle(vehicles);
        }
        else if (choice == 5)
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