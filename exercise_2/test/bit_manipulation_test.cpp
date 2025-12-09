#include <vector>
#include "bit_manipulation.hpp"
#include <catch2/catch_test_macros.hpp>


TEST_CASE("PIN_IS_EVEN_NUMBER works for normal positive values")
{
    CHECK(PIN_IS_EVEN_NUMBER(0) == true);
    CHECK(PIN_IS_EVEN_NUMBER(1) == false);
    CHECK(PIN_IS_EVEN_NUMBER(2) == true);
    CHECK(PIN_IS_EVEN_NUMBER(15) == false);
    CHECK(PIN_IS_EVEN_NUMBER(100) == true);
}

TEST_CASE("PIN_IS_EVEN_NUMBER used with adjusted pin values")
{
    int revisionOffset = -2;
    std::vector<int> pins       = { 1, 2, 5, 6, 9, 12 };
    std::vector<int> adjusted   = { 1-2, 2-2, 5-2, 6-2, 9-2, 12-2 };
    std::vector<bool> expected  = {
        false,   // -1 should be odd
        true,    //  0 even
        false,   //  3 odd
        true,    //  4 even
        false,   //  7 odd
        true     // 10 even
    };

    for (size_t i = 0; i < pins.size(); ++i)
    {
        CHECK(PIN_IS_EVEN_NUMBER(adjusted[i]) == expected[i]);
    }
}

TEST_CASE("Negative numbers behave as mathematically expected")
{
    // These expectations **look correct**, but some will FAIL
    CHECK(PIN_IS_EVEN_NUMBER(-1) == false);
    CHECK(PIN_IS_EVEN_NUMBER(-2) == true);
    CHECK(PIN_IS_EVEN_NUMBER(-3) == false);
    CHECK(PIN_IS_EVEN_NUMBER(-10) == true);
}

TEST_CASE("Routing logic using PIN_IS_EVEN_NUMBER groups pins correctly")
{
    auto route_bus = [](int pin, int offset) {
        int adj = pin + offset;
        return PIN_IS_EVEN_NUMBER(adj) ? 0 : 1;
    };

    int offset = -2;

    // Expected behavior based on mathematical even/odd rules.
    CHECK(route_bus(1, offset) == 1);    // -1 odd
    CHECK(route_bus(2, offset) == 0);    //  0 even
    CHECK(route_bus(5, offset) == 1);    //  3 odd
    CHECK(route_bus(12, offset) == 0);   // 10 even
}
