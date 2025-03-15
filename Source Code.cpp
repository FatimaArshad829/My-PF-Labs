#include <iostream>
#include <string>
#include <windows.h> 

using namespace std;
const string ADMIN_PASSWORD = "admin123";

struct Flight {
    int flightID;
    string destination;
    int availableSeats;
};

struct Ticket {
    int flightID;
    string passengerName;
    int age;
    string passportNumber;
    string uniquePIN;
};

const int MAX_FLIGHTS = 10;
const int MAX_TICKETS = 50;
Flight flights[MAX_FLIGHTS] = {
    {101, "New York", 5},
    {102, "London", 5},
    {103, "Paris", 5},
    {104, "Tokyo", 5},
    {105, "Dubai", 5}
};
int flightCount = 5;
Ticket tickets[MAX_TICKETS];
int ticketCount = 0;

void cls() {
    system("cls");
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void displayHeader(string title) {
    setColor(11);
    cout << "\n========================================\n";
    cout << "          " << title << "\n";
    cout << "========================================\n";
    setColor(15);
}

void displayFlights() {
    displayHeader("Available Flights");
    for (int i = 0; i < flightCount; i++) {
        setColor(14);
        cout << "Flight ID: " << flights[i].flightID << " | Destination: " << flights[i].destination
             << " | Available Seats: " << flights[i].availableSeats << endl;
    }
    setColor(15);
}

void bookFlight() {
    displayFlights();
    int flightID;
    cout << "\nEnter Flight ID to book: ";
    cin >> flightID;
    for (int i = 0; i < flightCount; i++) {
        if (flights[i].flightID == flightID && flights[i].availableSeats > 0) {
            Ticket ticket;
            ticket.flightID = flightID;
            cout << "Enter Name: "; cin >> ticket.passengerName;
            cout << "Enter Age: "; cin >> ticket.age;
            cout << "Enter Passport Number: "; cin >> ticket.passportNumber;
            ticket.uniquePIN = to_string(rand() % 9000 + 1000);
            tickets[ticketCount++] = ticket;
            flights[i].availableSeats--;
            setColor(10);
            cout << "\nBooking Successful! Your PIN: " << ticket.uniquePIN << "\n";
            setColor(15);
            return;
        }
    }
    setColor(12);
    cout << "Invalid Flight ID or No Seats Available!\n";
    setColor(15);
}

void cancelBooking() {
    displayHeader("Cancel Booking");
    string pin;
    cout << "Enter Your Booking PIN: ";
    cin >> pin;
    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].uniquePIN == pin) {
            for (int j = 0; j < flightCount; j++) {
                if (flights[j].flightID == tickets[i].flightID) {
                    flights[j].availableSeats++;
                    break;
                }
            }
            tickets[i] = tickets[--ticketCount]; 
            setColor(10);
            cout << "Booking Cancelled Successfully!\n";
            setColor(15);
            return;
        }
    }
    setColor(12);
    cout << "Invalid PIN!\n";
    setColor(15);
}

void viewMyTicket() {
    displayHeader("View My Ticket");
    string name, passport;
    cout << "Enter Your Name: "; cin >> name;
    cout << "Enter Your Passport Number: "; cin >> passport;
    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].passengerName == name && tickets[i].passportNumber == passport) {
            setColor(14);
            cout << "\nYour Ticket Details:\n";
            cout << "Passenger Name: " << tickets[i].passengerName << "\nAge: " << tickets[i].age
                 << "\nPassport Number: " << tickets[i].passportNumber
                 << "\nFlight ID: " << tickets[i].flightID
                 << "\nBooking PIN: " << tickets[i].uniquePIN << "\n";
            setColor(15);
            return;
        }
    }
    setColor(12);
    cout << "No ticket found with the provided details!\n";
    setColor(15);
}

void adminPanel() {
    displayHeader("Admin Panel");
    string password;
    cout << "Enter Admin Password: ";
    cin >> password;
    if (password == ADMIN_PASSWORD) {
        while (true) {
            int choice;
            cout << "\n1. View All Bookings\n2. Add Flight\n3. Remove Flight\n4. Exit\nEnter Choice: ";
            cin >> choice;
            if (choice == 1) {
                for (int i = 0; i < ticketCount; i++) {
                    setColor(14);
                    cout << "\nBooking " << i + 1 << ":\n";
                    cout << "Passenger Name: " << tickets[i].passengerName
                         << "\nAge: " << tickets[i].age
                         << "\nPassport Number: " << tickets[i].passportNumber
                         << "\nFlight ID: " << tickets[i].flightID
                         << "\nBooking PIN: " << tickets[i].uniquePIN << "\n";
                    setColor(15);
                }
            } else if (choice == 2 && flightCount < MAX_FLIGHTS) {
                cout << "Enter Flight ID: "; cin >> flights[flightCount].flightID;
                cout << "Enter Destination: "; cin >> flights[flightCount].destination;
                cout << "Enter Available Seats: "; cin >> flights[flightCount].availableSeats;
                flightCount++;
                setColor(10);
                cout << "Flight Added Successfully!\n";
                setColor(15);
            } else if (choice == 3) {
                int flightID;
                cout << "Enter Flight ID to Remove: ";
                cin >> flightID;
                for (int i = 0; i < flightCount; i++) {
                    if (flights[i].flightID == flightID) {
                        flights[i] = flights[--flightCount];
                        setColor(10);
                        cout << "Flight Removed Successfully!\n";
                        setColor(15);
                        return;
                    }
                }
                setColor(12);
                cout << "Invalid Flight ID!\n";
                setColor(15);
            } else break;
        }
    } else {
        setColor(12);
        cout << "Incorrect Password!\n";
        setColor(15);
    }
}

int main() {
    while (true) {
        displayHeader("Flight Management System");
        int choice;
        cout << "1. View Flights\n2. Book Flight\n3. Cancel Booking\n4. View My Ticket\n5. Admin Panel\n6. Exit\nEnter Choice: ";
        cin >> choice;
        if (choice == 1) displayFlights();
        else if (choice == 2) bookFlight();
        else if (choice == 3) cancelBooking();
        else if (choice == 4) viewMyTicket();
        else if (choice == 5) adminPanel();
        else break;
    }
    return 0;
}

