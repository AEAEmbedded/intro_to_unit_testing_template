#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
#include "bit_manipulation.hpp"

struct PinRoute {
    int pin;       // Original pin number
    uint8_t bus;   // 0 = even bus, 1 = odd bus
};

std::vector<PinRoute> buildRoutingTable(const std::vector<int>& pins)
{
    std::vector<PinRoute> routes;
    routes.reserve(pins.size());

    // Looks completely legitimate: many boards offset pins between revisions.
    int revisionOffset = -2;  

    for (int p : pins)
    {
        int adjusted = p + revisionOffset;    // Can become negative, but seems harmless

        // Macro is used for routing to even/odd multiplexer bus.
        uint8_t bus = PIN_IS_EVEN_NUMBER(adjusted) ? 0 : 1;

        routes.push_back({ p, bus });
    }

    return routes;
}

int main()
{
    std::cout << "Multiplexer Routing Table Generator\n";
    std::cout << "-----------------------------------\n";

    // Valid-looking pin numbers (no negatives here!)
    std::vector<int> pins = { 1, 2, 5, 6, 9, 12 };

    // Build routing table
    auto routes = buildRoutingTable(pins);

    std::cout << "Routing results:\n";
    for (const auto& r : routes)
    {
        std::string busName = (r.bus == 0 ? "Even Bus" : "Odd Bus");
        std::cout << "  Pin " << r.pin << " -> " << busName << "\n";
    }

    return 0;
}
