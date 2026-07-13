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

class Customer
{
private:
    string CustomerID;
    string Name;
    string Phone;
    string Email;
    string Licence;

public:
    Customer(string customerID, string name, string phone, string email, string licence)
    {
        this->CustomerID = customerID;
        this->Name = name;
        this->Phone = phone;
        this->Email = email;
        this->Licence = licence;
    }

    void displayDetail()
    {
        cout << "-----------------------------------------------\n";
        cout << "Custome ID    : " << CustomerID << endl;
        cout << "Name          : " << Name << endl;
        cout << "Phone Number  : " << Phone << endl;
        cout << "Email         : " << Email << endl;
        cout << "Driving Licence  : " << Licence << endl;
        cout << "-----------------------------------------------\n";
    }

    void setCustomerName(string name)
    {
        this->Name = name;
    }

    void setPhone(string phone)
    {
        this->Phone = phone;
    }

    void setEmail(string email)
    {
        this->Email = email;
    }

    void setLicence(string licence)
    {
        this->Licence = licence;
    }

    string getCustomerID()
    {
        return CustomerID;
    }

    string getName()
    {
        return Name;
    }

    string getPhone()
    {
        return Phone;
    }

    string getEmail()
    {
        return Email;
    }

    string getLicence()
    {
        return Licence;
    }
};

class Rental
{
private:
    string rentalID;
    string customerID;
    string vehicleID;
    int days;
    int totalAmount;
    bool status;

public:
    Rental(string rentalID, string customerID, string vehicleID, int days, int totalAmount)
    {
        this->rentalID = rentalID;
        this->customerID = customerID;
        this->vehicleID = vehicleID;
        this->days = days;
        this->totalAmount = totalAmount;
        this->status = true;
    }

    void displayDetail()
    {
        cout << "------------------------------------------------------" << endl;
        cout << "Rental ID : " << rentalID << endl;
        cout << "Customer ID : " << customerID << endl;
        cout << "Vehicle ID : " << vehicleID << endl;
        cout << "Rental Days : " << days << endl;
        cout << "Total Amount : " << totalAmount << endl;
        if (status)
        {
            cout << "Status : Active" << endl;
        }
        else
        {
            cout << "Status : Completed" << endl;
        }
        cout << "------------------------------------------------------" << endl;
    }

    string getRentalID()
    {
        return rentalID;
    }

    void setStatusActive()
    {
        status = true;
    }

    void setStatusComplete()
    {
        status = false;
    }

    bool getStatus()
    {
        return status;
    }

    string getVehicleID()
    {
        return vehicleID;
    }

    string getCustomerID(){
        return customerID;
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

    for (Vehicle &vehicle : vehicles)
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

void returnVehicle(vector<Vehicle> &vehicles, vector<Rental> &rentals)
{
    cout << "\n=============== Return Rented Vehicle ===============\n";
    string id;
    cout << "Enter Rental ID to complete : ";
    cin >> id;
    int found = false;
    for (Rental &rental : rentals)
    {
        if (rental.getRentalID() == id)
        {
            found = true;
            if (rental.getStatus() == true)
            {
                bool flag = false;
                string v = rental.getVehicleID();
                for (Vehicle &vehicle : vehicles)
                {
                    if (rental.getVehicleID() == vehicle.getVehicleID())
                    {
                        flag = true;
                        vehicle.markAsAvailable();
                        rental.setStatusComplete();
                        cout << "Vehicle " << vehicle.getVehicleID() << " returned successfully." << endl;
                        cout << "Rental " << rental.getRentalID() << " marked as Completed." << endl;
                        cout << "Vehicle status is now Available." << endl;
                        break;
                    }
                }
                if (flag == false)
                {
                    cout << "Associated vehicle " << v << " not found." << endl;
                    cout << " Return failed." << endl;
                }
            }
            else
            {
                cout << "Rental " << id << " is already completed." << endl;
                cout << "Return failed." << endl;
            }
            break;
        }
    }
    if (found == false)
    {
        cout << "\n!!!!!  Rental with ID " << id << " not found.  !!!!!";
    }
    cout << "\n=========================================================\n";
}

void registerCustomer(vector<Customer> &customers)
{
    cout << "\n=================== Register Customer =====================\n";
    string id;
    cout << "Enter Customer Id : ";
    cin >> id;
    cin.ignore(1000, '\n');
    string name;
    cout << "Enter Full Name         : ";
    getline(cin, name);
    string phone;
    cout << "Enter Phone Number      : ";
    cin >> phone;
    string email;
    cout << "Enter Email             : ";
    cin >> email;
    string licence;
    cout << "Enter Driving Licence   : ";
    cin >> licence;
    int f = 1;
    for (Customer &customer : customers)
    {
        if (customer.getCustomerID() == id)
        {
            cout << "\nError: Customer ID " << id << " already exists.\n";
            cout << "Customer not added.\n";
            f = 0;
            break;
        }
        else if (customer.getPhone() == phone)
        {
            cout << "\nError: Phone " << phone << " already exists.\n";
            cout << "Customer not added.\n";
            f = 0;
            break;
        }
        else if (customer.getEmail() == email)
        {
            cout << "\nError: Email " << email << " already exists.\n";
            cout << "Customer not added.\n";
            f = 0;
            break;
        }
        else if (customer.getLicence() == licence)
        {
            cout << "\nError: Licence Number " << licence << " already exists.\n";
            cout << "Customer not added.\n";
            f = 0;
            break;
        }
    }
    if (f == 1)
    {
        Customer newCustomer(id, name, phone, email, licence);
        customers.push_back(newCustomer);
        cout << "\n----Customer Added Sucessfully----\n";
    }
    cout << "================================================\n";
}

void displayAllCustomer(vector<Customer> &customers)
{
    cout << "\n================= ALL CUSTOMERS ==================\n";
    if (customers.empty())
    {
        cout << "-------- No Customer Found in the System --------\n";
    }
    else
    {
        for (Customer &customer : customers)
        {
            customer.displayDetail();
        }
        cout << "==================================================\n";
    }
}

void searchCustomer(vector<Customer> &customers)
{
    cout << "\n================ SEARCH CUSTOMER =================\n";
    string id;
    cout << "Enter Customer ID to search : ";
    cin >> id;
    int f = 0;

    for (Customer &customer : customers)
    {
        if (customer.getCustomerID() == id)
        {
            cout << "\n----Customer Found----\n";
            customer.displayDetail();
            f = 1;
            break;
        }
    }
    if (f == 0)
    {
        cout << "\nCustomer with ID " << id << " not found.\n";
    }
    cout << "======================================================";
}

void rentVehicle(vector<Vehicle> &vehicles, vector<Customer> &customers, vector<Rental> &rentals)
{
    cout << "\n================ RENT VEHICLE =================\n";
    string Cid, Vid, Rid;
    cout << "Enter Rental ID : ";
    cin >> Rid;
    int f = 0;
    for (Rental &rental : rentals)
    {
        if (rental.getRentalID() == Rid)
        {
            f = 1;
            break;
        }
    }
    if (f == 1)
    {
        cout << "Error: Rental ID " << Rid << " already exists.\n";
        cout << "Rental failed.";
        cout << "\n=======================================================\n";
        return;
    }

    cout << "Enter Customer ID : ";
    cin >> Cid;
    f = 0;
    for (Customer &customer : customers)
    {
        if (customer.getCustomerID() == Cid)
        {
            f = 1;
            break;
        }
    }
    if (f == 0)
    {
        cout << "Customer with ID " << Cid << " not found.\n";
        cout << "Rental failed.";
        cout << "\n=======================================================\n";
        return;
    }
    f = 0;
    cout << "Enter Vehicle ID : ";
    cin >> Vid;
    for (Vehicle &vehicle : vehicles)
    {
        if (vehicle.getVehicleID() == Vid)
        {
            f = 1;
            break;
        }
    }
    for (Vehicle &vehicle : vehicles)
    {
        if (vehicle.getAvailability() == false && vehicle.getVehicleID() == Vid)
        {
            f = 2;
            break;
        }
    }
    if (f == 0)
    {
        cout << "Vehicle with ID " << Vid << " not found.\n";
        cout << "Rental failed.";
        cout << "\n=======================================================\n";
        return;
    }
    if (f == 2)
    {
        cout << "Vehicle with ID " << Vid << " is currently unavailable.\n";
        cout << "Rental failed.";
        cout << "\n=======================================================\n";
        return;
    }
    int days;
    cout << "Enter number of rental days : ";
    cin >> days;
    if (days <= 0)
    {
        cout << "Invalid rental duration! Number of days must be greater than 0.\n";
        cout << "Rental Failed!";
        cout << "\n=======================================================\n";
        return;
    }

    for (Customer &customer : customers)
    {
        if (customer.getCustomerID() == Cid)
        {
            cout << "Customer ID    : " << Cid << endl;
            cout << "Customer Name  : " << customer.getName() << endl;
        }
    }
    int totalAmount;
    for (Vehicle &vehicle : vehicles)
    {
        if (vehicle.getVehicleID() == Vid)
        {
            cout << "Vehicle ID     : " << Vid << endl;
            cout << "Brand          : " << vehicle.getBrand() << endl;
            cout << "Model          : " << vehicle.getModel() << endl;
            cout << "Price per Day  : Rs. " << vehicle.getprice() << endl;
            cout << "Rental Days    : " << days << endl;
            totalAmount = days * (vehicle.getprice());
            cout << "Total Amount   : Rs. " << days * (vehicle.getprice()) << endl;
            cout << "Rental Status  : Active" << endl;
            cout << "\nVehicle rented successfully!" << endl;
            vehicle.markAsRented();
            break;
        }
    }

    Rental newRental(Rid, Cid, Vid, days, totalAmount);
    rentals.push_back(newRental);
    cout << "Rental transaction created successfully!" << endl;

    cout << "\n=======================================================\n";
}

void displayAllRental(vector<Rental> &rentals)
{
    if (rentals.empty())
    {
        cout << "No Rental at this time." << endl;
        return;
    }
    cout << "\n================ ALL RENTALS =================\n";
    for (Rental &rental : rentals)
    {
        rental.displayDetail();
    }
    cout << "\n==============================================\n";
}

void searchRental(vector<Rental> &rentals)
{
    cout << "\n================ SEARCH RENTAL =================\n";
    string id;
    cout << "Enter Rental ID : ";
    cin >> id;
    bool found = false;
    for (Rental &rental : rentals)
    {
        if (rental.getRentalID() == id)
        {
            rental.displayDetail();
            found = true;
            break;
        }
    }
    if (found == false)
    {
        cout << "\nRental ID " << id << " not found.\n";
    }
    cout << "======================================================";
}

void displayActiveRental(vector<Rental>& rentals){
    cout << "\n================ Active Rentals =================\n";
    bool found = false;
    for(Rental &rental : rentals){
        if(rental.getStatus() == true){
            rental.displayDetail();
            found = true;
        }
    }
    if(!found){
        cout << "No active rentals found." << endl; 
    }
    cout << "==================================================\n";
}

void displayCompleteRental(vector<Rental>& rentals){
    cout << "\n================ Complete Rentals =================\n";
    bool found = false;
    for(Rental &rental : rentals){
        if(rental.getStatus() == false){
            rental.displayDetail();
            found = true;
        }
    }
    if(!found){
        cout << "No Complete rentals found." << endl; 
    }
    cout << "==================================================\n";
}

void customerRentalHistory(vector<Rental> &rentals,vector<Customer> &customers){
    string id;
    cout << "Enter Customer ID : ";
    cin >> id;
    bool found = false;
    cout << "\n================ RENTAL HISTORY FOR CUSTOMER " << id << " =================\n";
    for(Customer &customer:customers){
        if(customer.getCustomerID() == id){
            found = true;
            break;
        }
    }
    if(!found){
        cout << "Customer " << id << " does not exists at all." << endl;
        return;
    }
    found = false;
    for(Rental &rental:rentals){
        if(rental.getCustomerID() == id){
            rental.displayDetail();
            found = true;
        }
    }
    if(!found){
        cout << "Customer " << id << " exists but has never rented a vehicle." << endl;
    }
    cout << "====================================================================\n";
}

void vehicleRentalHistory(vector<Rental> &rentals,vector<Vehicle> &vehicles){
    string id;
    cout << "Enter Vehicle ID : ";
    cin >> id;
    bool found = false;
    cout << "\n================ RENTAL HISTORY FOR VEHICLE " << id << " =================\n";
    for(Vehicle &vehicle:vehicles){
        if(vehicle.getVehicleID() == id){
            found = true;
            break;
        }
    }
    if(!found){
        cout << id << " → Vehicle doesn't exist" << endl;
        return;
    }
    found = false;
    for(Rental &rental:rentals){
        if(rental.getVehicleID() == id){
            rental.displayDetail();
            found = true;
        }
    }
    if(!found){
        cout << id << " → Vehicle exists but has never been rented" << endl;
    }
    cout << "====================================================================\n";

}

int main()
{
    vector<Vehicle> vehicles;
    vector<Customer> customers;
    vector<Rental> rentals;

    bool f = true;
    while (f)
    {
        cout << "\n===== VEHICLE RENTAL SYSTEM MENU =====\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Display All Vehicles\n";
        cout << "3. Search Vehicle\n";
        cout << "4. Update Vehicle\n";
        cout << "5. Display Available Vehicles\n";
        cout << "6. Return Vehicle\n";
        cout << "7. Register Customer\n";
        cout << "8. Display All Customer\n";
        cout << "9. Search Customer\n";
        cout << "10. Rent Vehicle\n";
        cout << "11. Display All Rental\n";
        cout << "12. Search Rental\n";
        cout << "13. Display Active Rentals\n";
        cout << "14. Display Completed Rentals\n";
        cout << "15. Customer Rental History\n";
        cout << "16. Vehicle Rental History\n";
        cout << "17. Exit\n";
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
            returnVehicle(vehicles, rentals);
        }
        else if (choice == 7)
        {
            registerCustomer(customers);
        }
        else if (choice == 8)
        {
            displayAllCustomer(customers);
        }
        else if (choice == 9)
        {
            searchCustomer(customers);
        }
        else if (choice == 10)
        {
            rentVehicle(vehicles, customers, rentals);
        }
        else if (choice == 11)
        {
            displayAllRental(rentals);
        }
        else if (choice == 12)
        {
            searchRental(rentals);
        }
        else if (choice == 13)
        {
            displayActiveRental(rentals);
        }
        else if (choice == 14)
        {
            displayCompleteRental(rentals);
        }
        else if (choice == 15)
        {
            customerRentalHistory(rentals,customers);
        }
        else if (choice == 16)
        {
            vehicleRentalHistory(rentals,vehicles);
        }
        else if (choice == 17)
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