#include"ScreenControl.h"

void Screen::initGraphic() {

	loadTexture("logoutButton.png", logoutButtonText);
	loadTexture("menu.png", menuText);

	logoutButton.setTexture(logoutButtonText);
	logoutButton.setPosition(1582.65, 0);

	menu.setTexture(menuText);
	menu.setPosition(0, 0);

}

void Screen::render(sf::RenderWindow &window) {

	window.draw(menu);
	window.draw(logoutButton);

}

string Screen::handleEvent(sf::Event event) {
	
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (logoutButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			cout << 11111 << endl;
			return "logout";
		}
	}
	return "anywhere";
}

void Screen::logic(string now, float screenY, sf::Sprite &rect) {



}