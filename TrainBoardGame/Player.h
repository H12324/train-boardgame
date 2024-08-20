#pragma once
#include "Card.h"
#include <vector>

using namespace std;

class Player
{
public:
	// Actions player can do in a turn
	void drawCard(TrainCard card);
	void claimRoute();
	void drawDestination();
	void showHand();

private:
	vector<TrainCard> hand;
	vector<DestinationCard> dests;

};

