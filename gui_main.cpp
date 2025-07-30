#include "reservation_system.hpp"
#include "gui.hpp"
#include <iostream>

int main() {
    int totalSeats;
    std::cout << "Enter total number of seats: ";
    std::cin >> totalSeats;

    ReservationSystem system(totalSeats);

    run_gui(system);

    return 0;
}
