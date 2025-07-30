#include "reservation_system.hpp"
#include <iostream>

ReservationSystem::ReservationSystem(int numSeats) : totalSeats(numSeats) {
    for (int i = 1; i <= totalSeats; ++i) {
        seats.emplace_back(i);
    }
}

bool ReservationSystem::bookSeat(int seatNum, const std::string& passengerName) {
    if (seatNum < 1 || seatNum > totalSeats) return false;
    Seat& seat = seats[seatNum - 1];
    if (seat.isBooked) return false;
    seat.isBooked = true;
    seat.passengerName = passengerName;
    return true;
}

bool ReservationSystem::cancelBooking(int seatNum) {
    if (seatNum < 1 || seatNum > totalSeats) return false;
    Seat& seat = seats[seatNum - 1];
    if (!seat.isBooked) return false;
    seat.isBooked = false;
    seat.passengerName = "";
    return true;
}

std::vector<Seat> ReservationSystem::getBookedSeats() const {
    std::vector<Seat> booked;
    for (const auto& seat : seats) {
        if (seat.isBooked) {
            booked.push_back(seat);
        }
    }
    return booked;
}

std::vector<Seat>& ReservationSystem::getAllSeats() {
    return seats;
}

void ReservationSystem::displaySeats() const {
    std::cout << "\nSeat Availability:\n";
    for (const auto& seat : seats) {
        std::cout << "Seat " << seat.seatNumber
                  << " - " << (seat.isBooked ? "Booked by " + seat.passengerName : "Available")
                  << std::endl;
    }
}