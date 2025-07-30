#ifndef RESERVATION_SYSTEM_HPP
#define RESERVATION_SYSTEM_HPP

#include <vector>
#include <string>

struct Seat {
    int seatNumber;
    bool isBooked;
    std::string passengerName;

    Seat(int num) : seatNumber(num), isBooked(false), passengerName("") {}
};

class ReservationSystem {
private:
    std::vector<Seat> seats;
    int totalSeats;

public:
    ReservationSystem(int numSeats);

    // Book a seat. Returns true if successful, false otherwise
    bool bookSeat(int seatNum, const std::string& passengerName);

    // Cancel a booking. Returns true if successful, false otherwise
    bool cancelBooking(int seatNum);

    // Get all booked seats
    std::vector<Seat> getBookedSeats() const;

    // Get all seats (booked or not) - note: returns reference to internal vector
    std::vector<Seat>& getAllSeats();

    // Display seats - optional, if you want CLI output
    void displaySeats() const;

    // Get total seats count
    int getTotalSeats() const { return totalSeats; }
};

#endif // RESERVATION_SYSTEM_HPP
