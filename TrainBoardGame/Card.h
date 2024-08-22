#pragma once
#include "Board.h"
#include <string>
#include <vector>
#include <memory>

// Undecided on whether I want a base Card class or just to leave them as distinct
class TrainCard
{
public:
	TrainCard(string colour);
	string getColour() const;
private:
	string colour;
};


class DestinationCard {
	shared_ptr<City> startCity; 
	shared_ptr<City> endCity;
	int points;
};

std::vector<std::shared_ptr<TrainCard>> generateTrains();
std::vector<std::shared_ptr<DestinationCard>> generateDests(const std::vector<std::shared_ptr<City>>& cities);