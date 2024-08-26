#include "Card.h"
#include <random>

TrainCard::TrainCard(string colour)
{
	this->colour = colour;
}

string TrainCard::getColour()
{
	return colour;
}

std::vector<std::shared_ptr<TrainCard>> generateTrains()
{
    std::vector<std::shared_ptr<TrainCard>> trainDeck;
    std::vector<std::string> colours = { "red", "blue", "green", "yellow", "black", "white", "orange", "pink" };

    // Generate 12 cards of each color
    for (const auto& colour : colours) {
        for (int i = 0; i < 12; ++i) {
            trainDeck.push_back(std::make_shared<TrainCard>(colour));
        }
    }

    // Add 14 locomotives (wild cards)
    for (int i = 0; i < 14; ++i) {
        trainDeck.push_back(std::make_shared<TrainCard>("rainbow"));
    }

    // Shuffle the deck
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(trainDeck.begin(), trainDeck.end(), g);

    return trainDeck;
}

DestinationCard::DestinationCard(shared_ptr<City> sC, shared_ptr<City> eC, int p) {
    startCity = sC;
    endCity = eC;
    points = p;
}

std::vector<std::shared_ptr<DestinationCard>> generateDests(const std::vector<std::shared_ptr<City>>& cities)
{
    std::vector<std::shared_ptr<DestinationCard>> ticketDeck;

    // Add all destination tickets with their respective point values
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[0], cities[14], 6));  // Atlanta to Los Angeles
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[0], cities[5], 5));   // Atlanta to Dallas
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[1], cities[16], 10)); // Boston to Miami
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[2], cities[29], 8));  // Calgary to Salt Lake City
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[3], cities[13], 11)); // Charleston to Little Rock
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[4], cities[31], 7));  // Chicago to Toronto
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[6], cities[9], 4));   // Denver to Helena
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[6], cities[22], 10)); // Denver to Phoenix
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[10], cities[18], 7)); // Houston to New Orleans
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[11], cities[21], 11)); // Kansas City to Omaha
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[12], cities[27], 8)); // Las Vegas to Salt Lake City
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[15], cities[28], 9)); // Miami to San Francisco
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[17], cities[34], 10)); // Nashville to Washington
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[18], cities[3], 5));  // New Orleans to Charleston
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[19], cities[23], 11)); // New York to Pittsburgh
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[24], cities[9], 11)); // Portland to Helena
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[26], cities[31], 7)); // St. Louis to Toronto
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[30], cities[2], 13)); // Seattle to Calgary
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[30], cities[28], 22)); // Seattle to San Francisco
    ticketDeck.push_back(std::make_shared<DestinationCard>(cities[32], cities[5], 12)); // Vancouver to Dallas

    // Shuffle the deck
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(ticketDeck.begin(), ticketDeck.end(), g);

    return ticketDeck;
}
