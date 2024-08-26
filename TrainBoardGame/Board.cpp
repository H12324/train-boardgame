#include "Board.h"

Board::Board()
{
    cities = initializeCities();
    routes = initializeRoutes(cities);
}

Route::Route(shared_ptr<City> c1, shared_ptr<City> c2, string colour, int length) 
{
    city1 = c1;
    city2 = c2;
    colour = colour;
    length = length;
    owner = nullptr; // Nobody owns at beginning
}

// In Future could make custom Boards for different maps
std::vector<std::shared_ptr<City>> Board::initializeCities() {
    return {
        std::make_shared<City>("Atlanta"),
        std::make_shared<City>("Boston"),
        std::make_shared<City>("Calgary"),
        std::make_shared<City>("Charleston"),
        std::make_shared<City>("Chicago"),
        std::make_shared<City>("Dallas"),
        std::make_shared<City>("Denver"),
        std::make_shared<City>("Duluth"),
        std::make_shared<City>("El Paso"),
        std::make_shared<City>("Helena"),
        std::make_shared<City>("Houston"),
        std::make_shared<City>("Kansas City"),
        std::make_shared<City>("Las Vegas"),
        std::make_shared<City>("Little Rock"),
        std::make_shared<City>("Los Angeles"),
        std::make_shared<City>("Miami"),
        std::make_shared<City>("Montreal"),
        std::make_shared<City>("Nashville"),
        std::make_shared<City>("New Orleans"),
        std::make_shared<City>("New York"),
        std::make_shared<City>("Oklahoma City"),
        std::make_shared<City>("Omaha"),
        std::make_shared<City>("Phoenix"),
        std::make_shared<City>("Pittsburgh"),
        std::make_shared<City>("Portland"),
        std::make_shared<City>("Raleigh"),
        std::make_shared<City>("Saint Louis"),
        std::make_shared<City>("Salt Lake City"),
        std::make_shared<City>("San Francisco"),
        std::make_shared<City>("Santa Fe"),
        std::make_shared<City>("Sault Ste. Marie"),
        std::make_shared<City>("Seattle"),
        std::make_shared<City>("Toronto"),
        std::make_shared<City>("Vancouver"),
        std::make_shared<City>("Washington"),
        std::make_shared<City>("Winnipeg")
    };
}

std::vector<std::shared_ptr<Route>> Board::initializeRoutes(const std::vector<std::shared_ptr<City>>& cities) {
    return {
        // Format: Route(city1, city2, color, length)
        std::make_shared<Route>(cities[0], cities[17], "gray", 1),  // Atlanta -> Nashville
        std::make_shared<Route>(cities[0], cities[25], "gray", 2),  // Atlanta -> Raleigh
        std::make_shared<Route>(cities[0], cities[23], "blue", 2),  // Atlanta -> Pittsburgh
        std::make_shared<Route>(cities[0], cities[18], "yellow", 4), // Atlanta -> New Orleans
        std::make_shared<Route>(cities[1], cities[16], "gray", 2),  // Boston -> Montreal
        std::make_shared<Route>(cities[1], cities[19], "yellow", 2), // Boston -> New York
        std::make_shared<Route>(cities[2], cities[32], "gray", 3),  // Calgary -> Vancouver
        std::make_shared<Route>(cities[2], cities[34], "white", 4), // Calgary -> Winnipeg
        std::make_shared<Route>(cities[2], cities[9], "gray", 4),   // Calgary -> Helena
        std::make_shared<Route>(cities[3], cities[25], "gray", 2),  // Charleston -> Raleigh
        std::make_shared<Route>(cities[3], cities[15], "pink", 4),  // Charleston -> Miami
        std::make_shared<Route>(cities[4], cities[23], "orange", 3),// Chicago -> Pittsburgh
        std::make_shared<Route>(cities[4], cities[31], "white", 5), // Chicago -> Toronto
        std::make_shared<Route>(cities[4], cities[21], "blue", 4),  // Chicago -> Omaha
        std::make_shared<Route>(cities[4], cities[22], "red", 3),   // Chicago -> Kansas City
        std::make_shared<Route>(cities[4], cities[35], "gray", 4),  // Chicago -> Saint Louis
        std::make_shared<Route>(cities[5], cities[18], "red", 2),   // Dallas -> New Orleans
        std::make_shared<Route>(cities[5], cities[20], "gray", 2),  // Dallas -> Oklahoma City
        std::make_shared<Route>(cities[5], cities[10], "gray", 1),  // Dallas -> Houston
        std::make_shared<Route>(cities[6], cities[27], "red", 3),   // Denver -> Salt Lake City
        std::make_shared<Route>(cities[6], cities[9], "green", 4),  // Denver -> Helena
        std::make_shared<Route>(cities[6], cities[30], "orange", 2),// Denver -> Santa Fe
        std::make_shared<Route>(cities[6], cities[20], "red", 4),   // Denver -> Oklahoma City
        std::make_shared<Route>(cities[6], cities[8], "yellow", 5), // Denver -> El Paso
        std::make_shared<Route>(cities[6], cities[21], "purple", 4),// Denver -> Omaha
        std::make_shared<Route>(cities[7], cities[9], "orange", 6), // Duluth -> Helena
        std::make_shared<Route>(cities[7], cities[21], "gray", 2),  // Duluth -> Omaha
        std::make_shared<Route>(cities[7], cities[4], "red", 4),    // Duluth -> Chicago
        std::make_shared<Route>(cities[7], cities[30], "purple", 3),// Duluth -> Santa Fe
        std::make_shared<Route>(cities[7], cities[32], "gray", 5),  // Duluth -> Toronto
        std::make_shared<Route>(cities[7], cities[33], "gray", 6),  // Duluth -> Winnipeg
        std::make_shared<Route>(cities[8], cities[22], "yellow", 5),// El Paso -> Kansas City
        std::make_shared<Route>(cities[8], cities[30], "red", 2),   // El Paso -> Santa Fe
        std::make_shared<Route>(cities[8], cities[22], "blue", 4),  // El Paso -> Oklahoma City
        std::make_shared<Route>(cities[8], cities[24], "orange", 6),// El Paso -> Los Angeles
        std::make_shared<Route>(cities[9], cities[34], "blue", 4),  // Helena -> Winnipeg
        std::make_shared<Route>(cities[9], cities[31], "yellow", 6),// Helena -> Seattle
        std::make_shared<Route>(cities[9], cities[27], "purple", 3),// Helena -> Salt Lake City
        std::make_shared<Route>(cities[9], cities[29], "green", 5), // Helena -> Calgary
        std::make_shared<Route>(cities[10], cities[18], "gray", 2), // Houston -> New Orleans
        std::make_shared<Route>(cities[11], cities[4], "blue", 3),  // Kansas City -> Chicago
        std::make_shared<Route>(cities[11], cities[21], "pink", 1), // Kansas City -> Omaha
        std::make_shared<Route>(cities[11], cities[20], "gray", 2), // Kansas City -> Oklahoma City
        std::make_shared<Route>(cities[12], cities[24], "gray", 2), // Las Vegas -> Los Angeles
        std::make_shared<Route>(cities[12], cities[27], "orange", 3),// Las Vegas -> Salt Lake City
        std::make_shared<Route>(cities[13], cities[10], "gray", 2), // Little Rock -> Houston
        std::make_shared<Route>(cities[13], cities[18], "green", 3),// Little Rock -> New Orleans
        std::make_shared<Route>(cities[13], cities[22], "gray", 2), // Little Rock -> Oklahoma City
        std::make_shared<Route>(cities[13], cities[35], "orange", 2),// Little Rock -> Saint Louis
        std::make_shared<Route>(cities[14], cities[28], "gray", 3), // Los Angeles -> San Francisco
        std::make_shared<Route>(cities[15], cities[25], "green", 4),// Miami -> Raleigh
        std::make_shared<Route>(cities[16], cities[31], "black", 3),// Montreal -> Toronto
        std::make_shared<Route>(cities[16], cities[19], "blue", 3), // Montreal -> New York
        std::make_shared<Route>(cities[17], cities[35], "gray", 3), // Nashville -> Saint Louis
        std::make_shared<Route>(cities[17], cities[18], "yellow", 4),// Nashville -> New Orleans
        std::make_shared<Route>(cities[19], cities[23], "green", 2),// New York -> Pittsburgh
        std::make_shared<Route>(cities[19], cities[35], "orange", 2),// New York -> Washington
        std::make_shared<Route>(cities[20], cities[22], "gray", 2), // Oklahoma City -> Kansas City
        std::make_shared<Route>(cities[20], cities[21], "gray", 2), // Oklahoma City -> Omaha
        std::make_shared<Route>(cities[20], cities[22], "blue", 2), // Oklahoma City -> El Paso
        std::make_shared<Route>(cities[20], cities[10], "gray", 2), // Oklahoma City -> Houston
        std::make_shared<Route>(cities[21], cities[7], "gray", 2),  // Omaha -> Duluth
        std::make_shared<Route>(cities[21], cities[34], "pink", 3), // Omaha -> Winnipeg
        std::make_shared<Route>(cities[22], cities[27], "gray", 3), // Phoenix -> Salt Lake City
        std::make_shared<Route>(cities[22], cities[14], "pink", 3), // Phoenix -> Los Angeles
        std::make_shared<Route>(cities[23], cities[24], "green", 5),// Pittsburgh -> Portland
        std::make_shared<Route>(cities[23], cities[35], "yellow", 2),// Pittsburgh -> Washington
        std::make_shared<Route>(cities[24], cities[29], "yellow", 3),// Portland -> Seattle
        std::make_shared<Route>(cities[25], cities[1], "blue", 2),  // Raleigh -> Boston
        std::make_shared<Route>(cities[25], cities[19], "gray", 2), // Raleigh -> New York
        std::make_shared<Route>(cities[25], cities[3], "gray", 2),  // Raleigh -> Charleston
        std::make_shared<Route>(cities[25], cities[35], "gray", 2), // Raleigh -> Washington
        std::make_shared<Route>(cities[26], cities[21], "gray", 2), // Saint Louis -> Kansas City
        std::make_shared<Route>(cities[26], cities[35], "blue", 4), // Saint Louis -> Chicago
        std::make_shared<Route>(cities[27], cities[29], "pink", 6), // Salt Lake City -> Portland
        std::make_shared<Route>(cities[27], cities[14], "black", 3),// Salt Lake City -> Los Angeles
        std::make_shared<Route>(cities[27], cities[30], "gray", 3), // Salt Lake City -> Santa Fe
        std::make_shared<Route>(cities[28], cities[24], "gray", 3), // San Francisco -> Portland
        std::make_shared<Route>(cities[28], cities[12], "orange", 3),// San Francisco -> Las Vegas
        std::make_shared<Route>(cities[28], cities[14], "gray", 3), // San Francisco -> Los Angeles
        std::make_shared<Route>(cities[29], cities[27], "gray", 3), // Santa Fe -> Salt Lake City
        std::make_shared<Route>(cities[29], cities[30], "gray", 3), // Santa Fe -> El Paso
        std::make_shared<Route>(cities[30], cities[7], "gray", 2),  // Sault Ste. Marie -> Duluth
        std::make_shared<Route>(cities[30], cities[33], "gray", 2), // Sault Ste. Marie -> Toronto
        std::make_shared<Route>(cities[31], cities[9], "gray", 4),  // Seattle -> Helena
        std::make_shared<Route>(cities[31], cities[27], "gray", 6), // Seattle -> Portland
        std::make_shared<Route>(cities[32], cities[16], "gray", 3), // Toronto -> Montreal
        std::make_shared<Route>(cities[32], cities[34], "gray", 6), // Toronto -> Winnipeg
        std::make_shared<Route>(cities[33], cities[2], "gray", 2),  // Vancouver -> Calgary
        std::make_shared<Route>(cities[34], cities[33], "gray", 2), // Washington -> Montreal
        std::make_shared<Route>(cities[35], cities[33], "gray", 2)  // Winnipeg -> Vancouver
    };
}