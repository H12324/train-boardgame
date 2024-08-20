#pragma once
#include <string>

enum class TrainColour {
	RED, BLUE, GREEN, ORANGE, YELLOW, PURPLE, PINK, BLACK, WHITE // Rainbow
};


// Undecided on whether I want a base Card class or just to leave them as distinct
class TrainCard
{
public:
	TrainCard(TrainColour colour);
	TrainColour getColour() const;
private:
	TrainColour colour;
};

class DestinationCard {
	std::string startCity;
	std::string endCity;
};
