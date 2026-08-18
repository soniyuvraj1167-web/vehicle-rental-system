# 🚗 Vehicle Rental Management System

A console-based **Vehicle Rental Management System** developed in **C++** using Object-Oriented Programming (OOP), STL containers, and file handling.

The system allows users to manage vehicles, customers, and rental transactions while maintaining data even after the program is closed.

---

## 📌 Features

### 🚘 Vehicle Management
- Add a new vehicle
- Display all vehicles
- Search vehicle by ID
- Update vehicle details
- Display available vehicles
- Track vehicle availability
- Mark vehicle as rented
- Return vehicle

### 👤 Customer Management
- Register new customers
- Display all customers
- Search customer by ID
- Search customer by name
- Validate duplicate:
  - Customer ID
  - Phone number
  - Email
  - Driving licence

### 📋 Rental Management
- Rent a vehicle
- Generate unique Rental ID
- Check customer existence
- Check vehicle existence
- Check vehicle availability
- Calculate rental amount
- Display all rentals
- Search rental by ID
- Display active rentals
- Display completed rentals
- Customer rental history
- Vehicle rental history

### 📅 Date & Return Management
- Automatically store rental date
- Automatically calculate expected return date
- Store actual return date
- Calculate late days
- Calculate late charges
- Track rental status:
  - Active
  - Completed

### 📊 Dashboard
The dashboard provides:
- Total vehicles
- Available vehicles
- Rented vehicles
- Total customers
- Total rentals
- Active rentals
- Completed rentals
- Total revenue
- Late fee collected

### 🔎 Search & Monitoring
- Search vehicle by brand
- Search vehicle by model
- Search customer by name
- Display rentals due today
- Display overdue rentals
- Find highest revenue vehicle
- Find most active customer

### 💾 File Handling
The system stores data in text files so that information is preserved after restarting the program.

Files used:

```text
vehicles.txt
customers.txt
rentals.txt