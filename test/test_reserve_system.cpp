#include "gtest/gtest.h"
#include "../reservation_system.hpp"

TEST(ReservationTest, BookSeatSuccess) {
    ReservationSystem rs(5);
    EXPECT_TRUE(rs.bookSeat(1, "Alice"));
}

TEST(ReservationTest, DoubleBookFails) {
    ReservationSystem rs(5);
    rs.bookSeat(2, "Bob");
    EXPECT_FALSE(rs.bookSeat(2, "Charlie"));
}

TEST(ReservationTest, CancelBooking) {
    ReservationSystem rs(5);
    rs.bookSeat(3, "Dan");
    EXPECT_TRUE(rs.cancelBooking(3));
    EXPECT_FALSE(rs.cancelBooking(3));
}
