#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Booking {
public:
    int id;
    string patient_name;
    string contact_number;
    string location;
    string status;

    Booking(int id, string patient_name, string contact_number, string location) {
        this->id = id;
        this->patient_name = patient_name;
        this->contact_number = contact_number;
        this->location = location;
        this->status = "Booked";
    }
};

class AmbulanceBookingSystem {
private:
    vector<Booking> bookings;

public:
    void bookAmbulance(string patient_name, string contact_number, string location) {
        int booking_id = bookings.size() + 1;
        Booking new_booking(booking_id, patient_name, contact_number, location);
        bookings.push_back(new_booking);
        cout << "Ambulance booked successfully! Your booking ID is " << booking_id << "." << endl;
    }

    void viewBookings() {
        if (bookings.empty()) {
            cout << "No bookings found." << endl;
            return;
        }
        for (const auto& booking : bookings) {
            cout << "ID: " << booking.id
                << ", Patient: " << booking.patient_name
                << ", Contact: " << booking.contact_number
                << ", Location: " << booking.location
                << ", Status: " << booking.status << endl;
        }
    }

    void cancelBooking(int booking_id) {
        for (auto& booking : bookings) {
            if (booking.id == booking_id) {
                booking.status = "Cancelled";
                cout << "Booking ID " << booking_id << " has been cancelled." << endl;
                return;
            }
        }
        cout << "No booking found with ID " << booking_id << "." << endl;
    }

    void run() {
        while (true) {
            cout << "\nAmbulance Booking System" << endl;
            cout << "1. Book an Ambulance" << endl;
            cout << "2. View Bookings" << endl;
            cout << "3. Cancel a Booking" << endl;
            cout << "4. Exit" << endl;

            int choice;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();  // To ignore the newline character after the choice input

            if (choice == 1) {
                string patient_name, contact_number, location;
                cout << "Enter patient name: ";
                getline(cin, patient_name);
                cout << "Enter contact number: ";
                getline(cin, contact_number);
                cout << "Enter location: ";
                getline(cin, location);
                bookAmbulance(patient_name, contact_number, location);
            }
            else if (choice == 2) {
                viewBookings();
            }
            else if (choice == 3) {
                int booking_id;
                cout << "Enter booking ID to cancel: ";
                cin >> booking_id;
                cancelBooking(booking_id);
            }
            else if (choice == 4) {
                cout << "Exiting the system." << endl;
                break;
            }
            else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};

int main() {
    AmbulanceBookingSystem system;
    system.run();
    return 0;
}
