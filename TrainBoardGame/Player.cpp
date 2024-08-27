#include "Player.h"

int Player::chooseAction() {
	return 0;
}

void Player::drawCard(shared_ptr<TrainCard> card)
{
	hand.push_back(card);
}

void Player::claimRoute()
{
}

void Player::drawDestination()
{
}

void Player::showHand()
{
}
