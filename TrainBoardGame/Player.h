#pragma once
#include "Card.h"
#include <vector>

using namespace std;

class Player
{
public:

	Player(int numTrains) : trains(numTrains) {}
	// Actions player can do in a turn
	int chooseAction();
	void drawCard(shared_ptr<TrainCard> card);
	void claimRoute();
	void drawDestination();
	void showHand();

private:
	vector<shared_ptr<TrainCard>> hand; 
	vector<shared_ptr<DestinationCard>> dests;
	vector<shared_ptr<Route>> claimedRoutes;
	int trains; // Starts as 45

};

