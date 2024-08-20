#include "Card.h"

TrainCard::TrainCard(TrainColour colour)
{
	this->colour = colour;
}

TrainColour TrainCard::getColour() const
{
	return colour;
}
