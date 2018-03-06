// tests-pressureTank.cpp
#include "catch.hpp"
#include "pressureTank.hpp"

TEST_CASE( "Pressurized tanks", "[pressureTank" ) {
    SECTION( "put gas in a tank" ) {
        PressureTank t(1.0, 2500.0, 200);
        t.addContents("oxygen", 10);
        REQUIRE(t.contents["oxygen"] == 10 * 15.9994); // Assert weight of Oxygen.
    }
}