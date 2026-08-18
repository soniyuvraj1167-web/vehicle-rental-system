#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <unordered_map>
using namespace std;

class Date
{
private:
    int date;
    int month;
    int year;

public:
    Date()
    {
        date = 0;
        month = 0;
        year = 0;
    }

    Date(int d, int m, int y)
    {
        date = d;
        month = m;
        year = y;
    }

    static Date getCurrentDate()
    {
        time_t now = time(0);
        tm *currentDate = localtime(&now);

        int currentDay = currentDate->tm_mday;
        int currentMon = currentDate->tm_mon + 1;
        int currentYear = currentDate->tm_year + 1900;

        return Date(currentDay, currentMon, currentYear);
    }

    static Date getExpectedDate(int rentalDays)
    {
        time_t now = time(0);
        now += (86400 * rentalDays);

        tm *currentDate = localtime(&now);

        int currentDay = currentDate->tm_mday;
        int currentMon = currentDate->tm_mon + 1;
        int currentYear = currentDate->tm_year + 1900;

        return Date(currentDay, currentMon, currentYear);

        // this method is using mktime() to

        // // Get current time
        // time_t now = time(0);

        // // Convert to local date/time
        // tm *currentDate = localtime(&now);

        // // Make a copy (don't modify the pointer returned by localtime)
        // tm expectedDate = *currentDate;

        // // Add rental days
        // expectedDate.tm_mday += rentalDays;

        // // Normalize the date
        // mktime(&expectedDate);

        // // Return Date object
        // return Date(
        //     expectedDate.tm_mday,
        //     expectedDate.tm_mon + 1,
        //     expectedDate.tm_year + 1900);
    }

    static int getDifference(Date rentalDate, Date actualDate)
    {
        tm r = {};
        tm a = {};

        r.tm_mday = rentalDate.getDate();
        r.tm_mon = rentalDate.getMonth() - 1;
        r.tm_year = rentalDate.getYear() - 1900;

        a.tm_mday = actualDate.getDate();
        a.tm_mon = actualDate.getMonth() - 1;
        a.tm_year = actualDate.getYear() - 1900;

        time_t strtTm = mktime(&r);
        time_t endTm = mktime(&a);

        double second = difftime(endTm, strtTm);

        int lateday = second / (60 * 60 * 24);

        if (lateday < 0)
        {
            return 0;
        }
        else
        {
            return lateday;
        }
    }

    int getDate()
    {
        return date;
    }

    int getMonth()
    {
        return month;
    }

    int getYear()
    {
        return year;
    }

    void displayDate()
    {
        cout << setfill('0') << setw(2) << date << '-' << setw(2) << month << '-' << year << setfill(' ');
    }
};

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

    Date rentalDate;
    Date expectedReturnDate;
    Date actualDate;

    int pricePerDay;
    int lateDays;
    int totalLateCharge;

public:
    Rental(string rentalID, string customerID, string vehicleID, int days, int pricePerDay, int totalAmount, Date rentalDate, Date expectedReturnDate, Date ActualReturnDate)
    {
        this->rentalID = rentalID;
        this->customerID = customerID;
        this->vehicleID = vehicleID;
        this->days = days;
        this->pricePerDay = pricePerDay;
        this->totalAmount = totalAmount;
        this->rentalDate = rentalDate;
        this->expectedReturnDate = expectedReturnDate;
        this->actualDate = ActualReturnDate;
        this->lateDays = 0;
        this->totalLateCharge = 0;
        this->status = true;
    }

    void displayDetail()
    {
        cout << "------------------------------------------------------\n";
        cout << "Rental ID            : " << rentalID << endl;
        cout << "Customer ID          : " << customerID << endl;
        cout << "Vehicle ID           : " << vehicleID << endl;
        cout << "Rental Days          : " << days << endl;
        cout << "Price Per Day        : Rs. " << pricePerDay << endl;
        cout << "Total Amount         : Rs. " << totalAmount << endl;

        cout << "Rental Date          : ";
        rentalDate.displayDate();
        cout << endl;

        cout << "Expected Return Date : ";
        expectedReturnDate.displayDate();
        cout << endl;

        cout << "Actual Return Date   : ";
        if (actualDate.getDate() == 0)
            cout << "Not Returned Yet";
        else
            actualDate.displayDate();
        cout << endl;

        cout << "Late Days            : " << lateDays << endl;
        cout << "Late Charge          : Rs. " << totalLateCharge << endl;

        cout << "Status               : ";
        if (status)
            cout << "Active";
        else
            cout << "Completed";

        cout << "\n------------------------------------------------------\n";
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

    string getCustomerID()
    {
        return customerID;
    }

    int getdays()
    {
        return days;
    }

    int getTotalAmount()
    {
        return totalAmount;
    }

    Date getExpectedReturnDate()
    {
        return expectedReturnDate;
    }

    void setlateDays(int d)
    {
        this->lateDays = d;
    }

    void setTotalLateCharge(int charges)
    {
        this->totalLateCharge = charges;
    }

    void setActualReturnDate(Date curntDate)
    {
        this->actualDate = curntDate;
    }

    Date getRentalDate()
    {
        return rentalDate;
    }

    int getPrice()
    {
        return pricePerDay;
    }

    Date getActualReturnDate()
    {
        return actualDate;
    }

    int getLatedays()
    {
        return lateDays;
    }

    int getLateCharge()
    {
        return totalLateCharge;
    }
};

void saveVehicles(vector<Vehicle> &vehicles)
{
    ofstream out("vehicles.txt");
    if (!out.is_open())
    {
        cout << "Error: Could not open vehicles.txt for saving.\n";
        return;
    }
    for (Vehicle &vehicle : vehicles)
    {
        out << vehicle.getVehicleID() << "|";
        out << vehicle.getBrand() << "|";
        out << vehicle.getModel() << "|";
        out << vehicle.getprice() << "|";
        out << vehicle.getAvailability() << endl;
    }
    out.close();
}

void loadVehicles(vector<Vehicle> &vehicles)
{
    ifstream in("vehicles.txt");
    if (!in.is_open())
    {
        return;
    }
    string id;
    string brand;
    string model;
    string priceStr;
    string availabilityStr;

    while (getline(in, id, '|'))
    {
        getline(in, brand, '|');
        getline(in, model, '|');
        getline(in, priceStr, '|');
        getline(in, availabilityStr);

        int price = stoi(priceStr);
        bool availability = stoi(availabilityStr);

        Vehicle newVehicle(id, brand, model, price);
        if (availability)
        {
            newVehicle.markAsAvailable();
        }
        else
        {
            newVehicle.markAsRented();
        }
        vehicles.push_back(newVehicle);
    }
    in.close();
}

void saveCustomer(vector<Customer> &customers)
{
    ofstream out("customers.txt");
    if (!out.is_open())
    {
        cout << "Error: Could not open customers.txt for saving.\n";
        return;
    }
    for (Customer &customer : customers)
    {
        out << customer.getCustomerID() << '|';
        out << customer.getName() << '|';
        out << customer.getPhone() << '|';
        out << customer.getEmail() << '|';
        out << customer.getLicence() << endl;
    }
    out.close();
}

void loadCustomer(vector<Customer> &customers)
{
    ifstream in("customers.txt");
    if (!in.is_open())
    {
        return;
    }
    string id;
    string name;
    string phone;
    string email;
    string licence;

    while (getline(in, id, '|'))
    {
        getline(in, name, '|');
        getline(in, phone, '|');
        getline(in, email, '|');
        getline(in, licence);

        Customer newCustomer(id, name, phone, email, licence);
        customers.push_back(newCustomer);
    }
    in.close();
}

void saveRental(vector<Rental> &rentals)
{
    ofstream out("rentals.txt");
    if (!out.is_open())
    {
        cout << "Error: Could not open rentals.txt for saving.\n";
        return;
    }
    for (Rental &rental : rentals)
    {
        out << rental.getRentalID() << '|';
        out << rental.getCustomerID() << '|';
        out << rental.getVehicleID() << '|';
        out << rental.getdays() << '|';
        out << rental.getPrice() << '|';
        out << rental.getTotalAmount() << '|';
        Date d = rental.getRentalDate();
        out << d.getDate() << '|';
        out << d.getMonth() << '|';
        out << d.getYear() << '|';
        Date d1 = rental.getExpectedReturnDate();
        out << d1.getDate() << '|';
        out << d1.getMonth() << '|';
        out << d1.getYear() << '|';
        Date d2 = rental.getActualReturnDate();
        out << d2.getDate() << '|';
        out << d2.getMonth() << '|';
        out << d2.getYear() << '|';

        out << rental.getLatedays() << '|';
        out << rental.getLateCharge() << '|';
        out << rental.getStatus() << endl;
    }
    out.close();
}

void loadRental(vector<Rental> &rentals)
{
    ifstream in("rentals.txt");
    if (!in.is_open())
    {
        return;
    }
    string Rid;
    string Cid;
    string Vid;
    string daysStr;
    string pricePerDayStr;
    string totalAmountStr;
    string rentalDayStr;
    string rentalMonthStr;
    string rentalYearStr;
    string expectedDayStr;
    string expectedMonthStr;
    string expectedYearStr;
    string actualDayStr;
    string actualMonthStr;
    string actualYearStr;
    string LateDaysStr;
    string LateChargeStr;
    string statusStr;

    while (getline(in, Rid, '|'))
    {
        getline(in, Cid, '|');
        getline(in, Vid, '|');
        getline(in, daysStr, '|');
        getline(in, pricePerDayStr, '|');
        getline(in, totalAmountStr, '|');
        getline(in, rentalDayStr, '|');
        getline(in, rentalMonthStr, '|');
        getline(in, rentalYearStr, '|');
        getline(in, expectedDayStr, '|');
        getline(in, expectedMonthStr, '|');
        getline(in, expectedYearStr, '|');
        getline(in, actualDayStr, '|');
        getline(in, actualMonthStr, '|');
        getline(in, actualYearStr, '|');
        getline(in, LateDaysStr, '|');
        getline(in, LateChargeStr, '|');
        getline(in, statusStr);

        int days = stoi(daysStr);
        int pricePerDay = stoi(pricePerDayStr);
        int totalAmount = stoi(totalAmountStr);
        int rentalDay = stoi(rentalDayStr);
        int rentalMonth = stoi(rentalMonthStr);
        int rentalYear = stoi(rentalYearStr);
        int expectedDay = stoi(expectedDayStr);
        int expectedMonth = stoi(expectedMonthStr);
        int expectedYear = stoi(expectedYearStr);
        int actualDay = stoi(actualDayStr);
        int actualMonth = stoi(actualMonthStr);
        int actualYear = stoi(actualYearStr);
        int latedays = stoi(LateDaysStr);
        int latecharge = stoi(LateChargeStr);
        bool status = stoi(statusStr);

        Rental newRental(Rid, Cid, Vid, days, pricePerDay, totalAmount, Date(rentalDay, rentalMonth, rentalYear), Date(expectedDay, expectedMonth, expectedYear), Date(actualDay, actualMonth, actualYear));
        newRental.setlateDays(latedays);
        newRental.setTotalLateCharge(latecharge);
        if (status)
        {
            newRental.setStatusActive();
        }
        else
        {
            newRental.setStatusComplete();
        }
        rentals.push_back(newRental);
    }
    in.close();
}

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
        if (price <= 0)
        {
            cout << "Invalid price! Price must be greater than 0.\n";
            return;
        }
        Vehicle newVehicle(id, brand, model, price);
        vehicles.push_back(newVehicle);
        saveVehicles(vehicles);
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
                saveVehicles(vehicles);

                cout << "\nBrand Updated Successfully!\n";
            }
            else if (ch == 2)
            {
                string model;
                cout << "Enter new Model name : ";
                cin >> model;

                vehicle.setModel(model);
                saveVehicles(vehicles);

                cout << "\nModel Updated Successfully!\n";
            }
            else if (ch == 3)
            {
                int price;
                cout << "Enter new Price per Day : ";
                cin >> price;

                if (vehicle.setPrice(price))
                {
                    saveVehicles(vehicles);
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
                        Date currentDate = Date::getCurrentDate();
                        int latedays = Date::getDifference(rental.getExpectedReturnDate(), currentDate);
                        vehicle.markAsAvailable();
                        saveVehicles(vehicles);
                        rental.setStatusComplete();
                        cout << "\n=============== Return Summary ===============\n";
                        cout << "Rental ID : " << rental.getRentalID() << endl;
                        cout << "Customer ID : " << rental.getCustomerID() << endl;
                        cout << "Vehicle ID : " << rental.getVehicleID() << endl;
                        cout << endl;
                        cout << "Rental Date : ";
                        rental.getRentalDate().displayDate();
                        cout << endl;
                        cout << "Expected Return Date : ";
                        rental.getExpectedReturnDate().displayDate();
                        cout << endl;
                        cout << "Actual Return Date : ";
                        currentDate.displayDate();
                        cout << endl;
                        cout << endl;
                        if (latedays == 0)
                        {
                            cout << "Late Days : 0" << endl;
                            cout << "Late Charge : 0" << endl;
                            cout << "Status : Completed" << endl;
                        }
                        else
                        {
                            rental.setlateDays(latedays);
                            int lateCharge = latedays * (rental.getPrice() + 200);
                            rental.setTotalLateCharge(lateCharge);
                            cout << "Late Days : " << latedays << endl;
                            cout << "Late Charge : " << lateCharge << endl;
                            cout << "Status : Completed" << endl;
                        }
                        rental.setActualReturnDate(currentDate);
                        saveRental(rentals);
                        // saveVehicles(vehicles);
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
    for (Customer &customer : customers)
    {
        if (customer.getCustomerID() == id)
        {
            cout << "\nError: Customer ID " << id << " already exists.\n";
            cout << "Customer not added.\n";
            return;
        }
    }

    cin.ignore(1000, '\n');
    string name;
    cout << "Enter Full Name         : ";
    getline(cin, name);
    string phone;
    cout << "Enter Phone Number      : ";
    cin >> phone;
    for (Customer &customer : customers)
    {
        if (customer.getPhone() == phone)
        {
            cout << "\nError: Phone " << phone << " already exists.\n";
            cout << "Customer not added.\n";
            return;
        }
    }
    string email;
    cout << "Enter Email             : ";
    cin >> email;
    for (Customer &customer : customers)
    {
        if (customer.getEmail() == email)
        {
            cout << "\nError: Email " << email << " already exists.\n";
            cout << "Customer not added.\n";
            return;
        }
    }
    string licence;
    cout << "Enter Driving Licence   : ";
    cin >> licence;
    for (Customer &customer : customers)
    {
        if (customer.getLicence() == licence)
        {
            cout << "\nError: Licence Number " << licence << " already exists.\n";
            cout << "Customer not added.\n";
            return;
        }
    }

    Customer newCustomer(id, name, phone, email, licence);
    customers.push_back(newCustomer);
    saveCustomer(customers);
    cout << "\n----Customer Added Sucessfully----\n";

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

    Rental *selectedRental = nullptr;
    for (Rental &rental : rentals)
    {
        if (rental.getRentalID() == Rid)
        {
            selectedRental = &rental;
            break;
        }
    }

    if (selectedRental != nullptr)
    {
        cout << "Error: Rental ID " << Rid << " already exists.\n";
        cout << "Rental failed.";
        cout << "\n=======================================================\n";
        return;
    }

    cout << "Enter Customer ID : ";
    cin >> Cid;

    Customer *selectedCustomer = nullptr;
    for (Customer &customer : customers)
    {
        if (customer.getCustomerID() == Cid)
        {
            selectedCustomer = &customer;
            break;
        }
    }

    if (selectedCustomer == nullptr)
    {
        cout << "Customer with ID " << Cid << " not found.\n";
        cout << "Rental failed.";
        cout << "\n=======================================================\n";
        return;
    }

    cout << "Enter Vehicle ID : ";
    cin >> Vid;

    Vehicle *selectedVehicle = nullptr;
    for (Vehicle &vehicle : vehicles)
    {
        if (vehicle.getVehicleID() == Vid)
        {
            selectedVehicle = &vehicle;
            break;
        }
    }

    if (selectedVehicle == nullptr)
    {
        cout << "Vehicle with ID " << Vid << " not found.\n";
        cout << "Rental failed.";
        cout << "\n=======================================================\n";
        return;
    }

    if (!selectedVehicle->getAvailability())
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

    Date currentDate = Date::getCurrentDate();
    Date expectedReturnDate = Date::getExpectedDate(days);
    cout << "----------------RENTAL SUMMARY-------------------" << endl;

    cout << "Customer ID    : " << selectedCustomer->getCustomerID() << endl;
    cout << "Customer Name  : " << selectedCustomer->getName() << endl;

    int totalAmount = 0;

    cout << "Vehicle ID     : " << Vid << endl;
    cout << "Brand          : " << selectedVehicle->getBrand() << endl;
    cout << "Model          : " << selectedVehicle->getModel() << endl;
    cout << "Price per Day  : Rs. " << selectedVehicle->getprice() << endl;
    cout << "Rental Days    : " << days << endl;
    cout << "Rental Date    : ";
    currentDate.displayDate();
    cout << endl;
    cout << "Expected Retrun Date : ";
    expectedReturnDate.displayDate();
    cout << endl;
    totalAmount = days * selectedVehicle->getprice();
    cout << "Total Amount   : Rs. " << days * (selectedVehicle->getprice()) << endl;
    cout << "Rental Status  : Active" << endl;
    selectedVehicle->markAsRented();
    cout << "\nVehicle rented successfully!" << endl;

    cout << "-------------------------------------------------------\n";
    Rental newRental(Rid, Cid, Vid, days, selectedVehicle->getprice(), totalAmount, currentDate, expectedReturnDate, Date());
    rentals.push_back(newRental);
    saveVehicles(vehicles);
    saveRental(rentals);
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

void displayActiveRental(vector<Rental> &rentals)
{
    cout << "\n================ Active Rentals =================\n";
    bool found = false;
    for (Rental &rental : rentals)
    {
        if (rental.getStatus() == true)
        {
            rental.displayDetail();
            found = true;
        }
    }
    if (!found)
    {
        cout << "No active rentals found." << endl;
    }
    cout << "==================================================\n";
}

void displayCompleteRental(vector<Rental> &rentals)
{
    cout << "\n================ Complete Rentals =================\n";
    bool found = false;
    for (Rental &rental : rentals)
    {
        if (rental.getStatus() == false)
        {
            rental.displayDetail();
            found = true;
        }
    }
    if (!found)
    {
        cout << "No Complete rentals found." << endl;
    }
    cout << "==================================================\n";
}

void customerRentalHistory(vector<Rental> &rentals, vector<Customer> &customers)
{
    string id;
    cout << "Enter Customer ID : ";
    cin >> id;
    bool found = false;
    cout << "\n================ RENTAL HISTORY FOR CUSTOMER " << id << " =================\n";
    for (Customer &customer : customers)
    {
        if (customer.getCustomerID() == id)
        {
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Customer " << id << " does not exists at all." << endl;
        return;
    }
    found = false;
    for (Rental &rental : rentals)
    {
        if (rental.getCustomerID() == id)
        {
            rental.displayDetail();
            found = true;
        }
    }
    if (!found)
    {
        cout << "Customer " << id << " exists but has never rented a vehicle." << endl;
    }
    cout << "====================================================================\n";
}

void vehicleRentalHistory(vector<Rental> &rentals, vector<Vehicle> &vehicles)
{
    string id;
    cout << "Enter Vehicle ID : ";
    cin >> id;
    bool found = false;
    cout << "\n================ RENTAL HISTORY FOR VEHICLE " << id << " =================\n";
    for (Vehicle &vehicle : vehicles)
    {
        if (vehicle.getVehicleID() == id)
        {
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << id << " → Vehicle doesn't exist" << endl;
        return;
    }
    found = false;
    for (Rental &rental : rentals)
    {
        if (rental.getVehicleID() == id)
        {
            rental.displayDetail();
            found = true;
        }
    }
    if (!found)
    {
        cout << id << " → Vehicle exists but has never been rented" << endl;
    }
    cout << "====================================================================\n";
}

void dashboard(vector<Vehicle> &vehicles, vector<Rental> &rentals, vector<Customer> &customers)
{
    cout << "\n========== VEHICLE RENTAL DASHBOARD ==========\n";

    int totalVehicle = 0;
    int availableVehicle = 0;
    int rentedVehicle = 0;
    for (Vehicle vehicle : vehicles)
    {
        totalVehicle += 1;
        if (vehicle.getAvailability())
        {
            availableVehicle += 1;
        }
        else
        {
            rentedVehicle += 1;
        }
    }
    cout << "Total Vehicle : " << totalVehicle << endl;
    cout << "Available Vehicle : " << availableVehicle << endl;
    cout << "Rented Vehicle : " << rentedVehicle << endl;
    cout << endl;

    int totalCustomer = 0;
    for (Customer customer : customers)
    {
        totalCustomer += 1;
    }
    cout << "Total Customer : " << totalCustomer << endl;

    int totalRental = 0;
    int activeRental = 0;
    int completedRental = 0;
    int totalRevenue = 0;
    int lateFee = 0;
    for (Rental rental : rentals)
    {
        totalRental += 1;
        totalRevenue += rental.getTotalAmount();
        if (rental.getStatus())
        {
            activeRental += 1;
        }
        else
        {
            completedRental += 1;
            totalRevenue += rental.getLateCharge();
            lateFee += rental.getLateCharge();
        }
    }

    cout << "Total Rentals : " << totalRental << endl;
    cout << "Active Rentals : " << activeRental << endl;
    cout << "Completed Rentals : " << completedRental << endl;
    cout << endl;
    cout << "Total Revenue : " << totalRevenue << endl;
    cout << "Late Fee Collected : " << lateFee << endl;

    cout << "==============================================\n";
}

void searchVehicleByBrand(vector<Vehicle> &vehicles)
{
    cout << "\n========== SEARCH VEHICLE BY BRAND ==========\n";
    string brand;
    cout << "Enter Brand : ";
    cin >> brand;
    bool found = false;
    for (Vehicle &vehicle : vehicles)
    {
        if (vehicle.getBrand() == brand)
        {
            vehicle.displayDetail();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Vehicle with brand " << brand << " not found !\n";
    }

    cout << "==============================================\n";
}

void searchVehicleByModel(vector<Vehicle> &vehicles)
{
    cout << "\n========== SEARCH VEHICLE BY MODEL ==========\n";
    string model;
    cout << "Enter Brand : ";
    cin >> model;
    bool found = false;
    for (Vehicle &vehicle : vehicles)
    {
        if (vehicle.getModel() == model)
        {
            vehicle.displayDetail();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Vehicle with model " << model << " not found !\n";
    }

    cout << "==============================================\n";
}

void searchCustomerByName(vector<Customer> customers)
{
    cout << "\n========== SEARCH CUSTOMER BY NAME ==========\n";
    string name;
    cout << "Enter Customer Name : ";
    cin >> name;
    bool found = false;
    for (Customer &customer : customers)
    {
        if (customer.getName() == name)
        {
            customer.displayDetail();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Customer with Name " << name << " not found !\n";
    }

    cout << "==============================================\n";
}

void rentalDueToday(vector<Rental> rentals)
{
    cout << "\n========== TODAY RENTAL DUE ==========\n";
    Date currentDate = Date::getCurrentDate();
    for (Rental rental : rentals)
    {
        if (rental.getStatus() && rental.getExpectedReturnDate().getDate() == Date::getCurrentDate().getDate() && rental.getExpectedReturnDate().getMonth() == Date::getCurrentDate().getMonth() && rental.getExpectedReturnDate().getYear() == Date::getCurrentDate().getYear())
        {
            cout << "---------------------------------------------\n";
            cout << "Rental ID : " << rental.getRentalID() << endl;
            cout << "Coustomer ID : " << rental.getCustomerID() << endl;
            cout << "Vehicle ID : " << rental.getVehicleID() << endl;
            cout << "Expected Return    : ";
            rental.getExpectedReturnDate().displayDate();
            cout << "---------------------------------------------\n";
        }
    }
}

void overDueRental(vector<Rental> rentals)
{
    cout << "\n========== OVER DUE RENTAL ==========\n";
    int f = 1;
    for (Rental rental : rentals)
    {
        int c = Date::getDifference(Date::getCurrentDate(), rental.getExpectedReturnDate());
        if (c > 0)
        {
            cout << "------------------------------------------------------\n";
            cout << "Rental ID : " << rental.getRentalID() << endl;
            cout << "Customer ID : " << rental.getCustomerID() << endl;
            cout << "Expected Return : ";
            rental.getExpectedReturnDate().displayDate();
            cout << "\n";
            cout << "Today's Date : ";
            Date::getCurrentDate().displayDate();
            cout << "\n";
            cout << "Late Days : " << c;
            cout << "------------------------------------------------------\n";
            f = 0;
        }
    }
    if (f == 1)
    {
        cout << "No OverDue Found!!";
        cout << "===========================================================\n";
    }
}

void highestRevenueVehicle(vector<Rental> &rentals)
{
    cout << "\n========== HIGHEST REVENUE VEHICLE ==========\n";

    if (rentals.empty())
    {
        cout << "No rental records found.\n";
        cout << "==============================================\n";
        return;
    }

    unordered_map<string, int> revenue;

    for (Rental &rental : rentals)
    {
        revenue[rental.getVehicleID()] +=
            rental.getTotalAmount() + rental.getLateCharge();
    }

    string highestVehicle = "";
    int highestRevenue = 0;

    for (auto &entry : revenue)
    {
        if (entry.second > highestRevenue)
        {
            highestRevenue = entry.second;
            highestVehicle = entry.first;
        }
    }

    cout << "Vehicle ID    : " << highestVehicle << endl;
    cout << "Total Revenue : Rs. " << highestRevenue << endl;

    cout << "==============================================\n";
}

void mostActiveCustomer(vector<Rental> &rentals)
{
    cout << "\n========== Most Active Customer ==========\n";

    if (rentals.empty())
    {
        cout << "No rental records found.\n";
        cout << "==============================================\n";
        return;
    }

    unordered_map<string, int> detail;

    for (Rental &rental : rentals)
    {
        detail[rental.getCustomerID()] += 1;
    }

    string activeCustomer = "";
    int count = 0;

    for (const auto &entry : detail)
    {
        if (entry.second > count)
        {
            count = entry.second;
            activeCustomer = entry.first;
        }
    }

    cout << "Customer ID : " << activeCustomer << endl;
    cout << "Total Rental : " << count << endl;

    cout << "==============================================\n";
}

void saveData(vector<Vehicle> &vehicles,
              vector<Customer> &customers,
              vector<Rental> &rentals)
{
    cout << "\n================ SAVE DATA ================\n";

    saveVehicles(vehicles);
    saveCustomer(customers);
    saveRental(rentals);

    cout << "All data saved successfully!\n";
    cout << "============================================\n";
}

int main()
{
    vector<Vehicle> vehicles;
    vector<Customer> customers;
    vector<Rental> rentals;

    loadVehicles(vehicles);
    loadCustomer(customers);
    loadRental(rentals);

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

        cout << "17. Dashboard\n";

        cout << "18. Display Rentals Due Today\n";
        cout << "19. Display Overdue Rentals\n";

        cout << "20. Search Vehicle by Brand\n";
        cout << "21. Search Vehicle by Model\n";
        cout << "22. Search Customer by Name\n";

        cout << "23. Highest Revenue Vehicle\n";
        cout << "24. Most Active Customer\n";

        cout << "25. Save Data\n";
        cout << "26. Exit\n";

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
            customerRentalHistory(rentals, customers);
        }
        else if (choice == 16)
        {
            vehicleRentalHistory(rentals, vehicles);
        }
        else if (choice == 17)
        {
            dashboard(vehicles, rentals, customers);
        }
        else if (choice == 18)
        {
            rentalDueToday(rentals);
        }
        else if (choice == 19)
        {
            overDueRental(rentals);
        }
        else if (choice == 20)
        {
            searchVehicleByBrand(vehicles);
        }
        else if (choice == 21)
        {
            searchVehicleByModel(vehicles);
        }
        else if (choice == 22)
        {
            searchCustomerByName(customers);
        }
        else if (choice == 23)
        {
            highestRevenueVehicle(rentals);
        }
        else if (choice == 24)
        {
            mostActiveCustomer(rentals);
        }
        else if (choice == 25)
        {
            saveData(vehicles,customers,rentals);
        }

        else if (choice == 26)
        {
            cout << "\nExiting Vehicle Rental System...\n";
            f = false;
        }
        else
        {
            cout << "\nInvalid choice! Please try again.\n";
        }
    }

    Date today = Date::getCurrentDate();
    today.displayDate();

    return 0;
}