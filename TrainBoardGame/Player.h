#pragma once
#include "Card.h"
#include <vector>

using namespace std;

class Player
{
public:

	Player(int numTrains) : trains(numTrains) {}
	// Actions player can do in a turn
	void drawCard(TrainCard card);
	void claimRoute();
	void drawDestination();
	void showHand();

private:
	vector<TrainCard> hand; // Maybe switch to shared ptrs
	vector<DestinationCard> dests;
	vector<Route> claimedRoutes;
	int trains; // Starts as 45

};

