#include "reservation_system.hpp"
#include <iostream>

int main() {
    int totalSeats;
    std::cout << "Enter total number of seats: ";
    std::cin >> totalSeats;

    ReservationSystem rs(totalSeats);
    int choice;

    do {
        std::cout << "\nMenu:\n"
                  << "1. Display Seats\n"
                  << "2. Book Seat\n"
                  << "3. Cancel Booking\n"
                  << "4. Show Booked Seats\n"
                  << "5. Exit\n"
                  << "Enter choice: ";
        std::cin >> choice;

        int seat;
        std::string name;
        switch (choice) {
            case 1:
                rs.displaySeats();
                break;

            case 2:
                std::cout << "Enter seat number: ";
                std::cin >> seat;
                std::cout << "Enter passenger name: ";
                std::cin.ignore(); // flush newline from previous input
                std::getline(std::cin, name);
                if (!rs.bookSeat(seat, name))
                    std::cout << "Booking failed: invalid seat or already booked.\n";
                break;

            case 3:
                std::cout << "Enter seat number: ";
                std::cin >> seat;
                if (!rs.cancelBooking(seat))
                    std::cout << "Cancellation failed: seat not booked or invalid.\n";
                break;

            case 4: {
                auto booked = rs.getBookedSeats();
                if (booked.empty()) {
                    std::cout << "No seats booked yet.\n";
                } else {
                    std::cout << "Booked seats:\n";
                    for (const auto& s : booked) {
                        std::cout << "Seat " << s.seatNumber << ": " << s.passengerName << "\n";
                    }
                }
                break;
            }

            case 5:
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid choice, try again.\n";
        }
    } while (choice != 5);

    return 0;
}
