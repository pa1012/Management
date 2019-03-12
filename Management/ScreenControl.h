#pragma once

#include"LoadData.h"
#include"Constant.h"

class Screen {
private:
	sf::Sprite logoutButton, menu;
	sf::Texture logoutButtonText, menuText;

public:
	void initGraphic();
	void render(sf::RenderWindow &window);
	string handleEvent(sf::Event event);
	void logic(string now, float screenY, sf::Sprite &rect);
};