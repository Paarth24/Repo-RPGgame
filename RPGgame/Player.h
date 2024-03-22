#pragma once
#include "Skeleton.h"

using namespace std;

class Player {

private:

	sf::Texture texture;

	vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.5f;

public:

	sf::Sprite sprite;

public:

	void Initialize();
	void Draw(sf::RenderWindow& window);
	void Update(Skeleton& skeleton);
	void Load();
};