#pragma once
#include <string>
#include <vector>
#include <memory>

//#include "Player.h"

using namespace std;

class Player;
class TrainCard;
class DestinationCard;

class City // Probably will need an operator==
{
private:
	std::string name;

public:
	City(std::string name) : name(name) {}
};

class Route {
public:
	Route(shared_ptr<City> c1, shared_ptr<City> c2, string colour, int length);
private:
	shared_ptr<City> city1;
	shared_ptr <City> city2;
	string colour;
	int length;
	shared_ptr<Player> owner;
};

class Board // Class may be redundant
{
public:
	Board();
	std::vector<std::shared_ptr<City>> initializeCities();
	std::vector<std::shared_ptr<Route>> initializeRoutes(const std::vector<std::shared_ptr<City>>& cities);

	vector<shared_ptr<City>> cities;
	vector<shared_ptr<Route>> routes;

};

