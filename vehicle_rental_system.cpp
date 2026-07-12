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
        cout << "-----------------------------------------------\n";
        cout << "Vehicle ID    : " << vehicleId << endl;
        cout << "Brand         : " << Brand << endl;
        cout << "Model         : " << Model << endl;
        cout << "Price Per Day : Rs. " << pricePerDay << endl;

        if (Availability)
        {
            cout << "Status: Available" << endl;
        }
        else
        {
            cout << "Status: Rented" << endl;
        }
        cout << "-----------------------------------------------\n";
    }

    bool getAvailability()
    {
        return Availability;
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

    void markAsRented()
    {
        Availability = false;
    }

    void markAsAvailable()
    {
        Availability = true;
    }
};

void addVehicle(vector<Vehicle> &vehicles)
{
    cout << "\n=================== Add Vehicle =====================\n";
    string id;
    cout << "Enter Vehicle Id : ";
    cin >> id;

    int f = 1;
    for (Vehicle &vehicle : vehicles)
    {
        if (vehicle.getVehicleID() == id)
        {
            f = 0;
            break;
        }
    }
    if (f == 0)
    {
        cout << "\nError: Vehicle ID " << id << " already exists.\n";
        cout << "Vehicle not added.\n";
        cout << "==================================================\n";
    }
    else
    {
        string brand;
        cout << "Enter Brand         : ";
        cin >> brand;
        string model;
        cout << "Enter Model         : ";
        cin >> model;
        int price;
        cout << "Enter Price per Day : ";
        cin >> price;
        Vehicle newVehicle(id, brand, model, price);
        vehicles.push_back(newVehicle);
        cout << "\n----Vehicle Added Sucessfully----\n";
        cout << "================================================\n";
    }
}

void displayVehicle(vector<Vehicle> &vehicles)
{
    cout << "\n================= ALL VEHICLES ==================\n";
    if (vehicles.empty())
    {
        cout << "-------- No Vehicles Found in the System --------\n";
    }
    else
    {
        cout << "\n----All Vehicles----\n";
        for (Vehicle &vehicle : vehicles)
        {
            vehicle.displayDetail();
        }
        cout << "==================================================\n";
    }
}

void searchVehicle(vector<Vehicle> &vehicles)
{
    cout << "\n================ SEARCH VEHICLE =================\n";
    string id;
    cout << "Enter Vehicle ID to search : ";
    cin >> id;
    int f = 0;

    for (Vehicle& vehicle : vehicles)
    {
        if (vehicle.getVehicleID() == id)
        {
            cout << "\n----Vehicle Found----\n";
            vehicle.displayDetail();
            f = 1;
            break;
        }
    }
    if (f == 0)
    {
        cout << "\nVehicle with ID " << id << " not found.\n";
    }
    cout << "======================================================";
}

void updateVehicle(vector<Vehicle> &vehicles)
{
    cout << "\n================ UPDATE VEHICLE =================\n";
    string id;
    cout << "Enter Vehicle ID to update: ";
    cin >> id;
    int f = 0;
    for (Vehicle &vehicle : vehicles)
    {
        if (vehicle.getVehicleID() == id)
        {
            f = 1;
            cout << "\n----Vehicle Found----\n";
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

                cout << "\nBrand Updated Successfully!\n";
            }
            else if (ch == 2)
            {
                string model;
                cout << "Enter new Model name : ";
                cin >> model;

                vehicle.setModel(model);

                cout << "\nModel Updated Successfully!\n";
            }
            else if (ch == 3)
            {
                int price;
                cout << "Enter new Price per Day : ";
                cin >> price;

                if (vehicle.setPrice(price))
                {
                    cout << "\nPrice Updated Successfully!\n";
                }
                else
                {
                    cout << "\nInvalid price! Price must be greater than 0.\n";
                }
            }

            else
            {
                cout << "\nUpdate Cancelled or Invalid Choice.\n";
            }

            break;
        }
    }
    if (f == 0)
    {
        cout << "\nVehicle with ID " << id << " not found.\n";
    }
    cout << "================================================\n";
}

void displayAvlbVehicle(vector<Vehicle> &vehicles)
{
    cout << "\n=============== Available Vehicle ===============\n";
    int f = 0;
    for (Vehicle &vehicle : vehicles)
    {
        if (vehicle.getAvailability() == true)
        {
            vehicle.displayDetail();
            f = 1;
        }
    }
    if (f == 0)
    {
        cout << "\n!!!!!-- No Vehicle Available --!!!!!\n";
    }
    cout << "\n==================================================\n";
}

void markRented(vector<Vehicle> &vehicles)
{
    cout << "\n=============== Mark Vehicle Rented ===============\n";
    string id;
    cout << "Enter Vehicle ID to mark rented : ";
    cin >> id;
    int f = 0;
    for (Vehicle &vehicle : vehicles)
    {
        if (vehicle.getVehicleID() == id)
        {
            f = 1;
            if (vehicle.getAvailability() == false)
            {
                cout << "\n!!!!!  Vehicle " << id << " is already Rented  !!!!!";
            }
            else
            {
                vehicle.markAsRented();
                cout << "\n!!!!!  Vehicle " << id << " marked as rented successfully.  !!!!!";
            }
            break;
        }
    }
    if (f == 0)
    {
        cout << "\n!!!!!  Vehicle with ID " << id << " not found.  !!!!!";
    }
    cout << "\n=========================================================\n";
}

void returnVehicle(vector<Vehicle> &vehicles)
{
    cout << "\n=============== Return Rented Vehicle ===============\n";
    string id;
    cout << "Enter Vehicle ID to return : ";
    cin >> id;
    int f = 0;
    for (Vehicle &vehicle : vehicles)
    {
        if (vehicle.getVehicleID() == id)
        {
            f = 1;
            if (vehicle.getAvailability() == true)
            {
                cout << "\n!!!!!  Vehicle " << id << " is already Available.  !!!!!";
            }
            else
            {
                vehicle.markAsAvailable();
                cout << "\n!!!!!  Vehicle " << id << " returned successfully.  !!!!!";
                cout << "\n Status is now Available. \n";
            }
            break;
        }
    }
    if (f == 0)
    {
        cout << "\n!!!!!  Vehicle with ID " << id << " not found.  !!!!!";
    }
    cout << "\n=========================================================\n";
}

int main()
{
    vector<Vehicle> vehicles;
    bool f = true;
    while (f)
    {
        cout << "\n===== VEHICLE RENTAL SYSTEM MENU =====\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Display All Vehicles\n";
        cout << "3. Search Vehicle\n";
        cout << "4. Update Vehicle\n";
        cout << "5. Display Available Vehicles\n";
        cout << "6. Mark Vehicle as Rented\n";
        cout << "7. Return Vehicle\n";
        cout << "8. Exit\n";
        cout << "======================================\n";
        cout << "Enter your choice: ";
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
            displayAvlbVehicle(vehicles);
        }
        else if (choice == 6)
        {
            markRented(vehicles);
        }
        else if (choice == 7)
        {
            returnVehicle(vehicles);
        }
        else if (choice == 8)
        {
            cout << "\nExiting Vehicle Rental System...\n";
            f = false;
        }
        else
        {
            cout << "\nInvalid choice! Please try again.\n";
        }
    }

    return 0;
}