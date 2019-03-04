#include <SFML/Graphics.hpp>
//#include"ArrayOfClass.h"
#include"LoadData.h"
#include"Course.h"
#include"Login.h"
#include"ScreenControl.h"



enum AppState {
	LOGIN, STUDENT, LECTURER, ADMIN
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(1800, 800), "Student Management");

	ArrOfAccount Acc;
	Acc.loadAccount();
	ArrayOfClass Class;
	Class.load(Acc);
	Acc.saveAccount();

	AppState state = STUDENT;

	Login login;
	login.initGraphic();

	Screen screenControl;
	screenControl.initGraphic();

	sf::Texture rectTexture;
	sf::Sprite rect;
	sf::View view;

	loadTexture("rect.png", rectTexture);
	rect.setPosition(1772, 0);
	rect.setTexture(rectTexture);

	view.reset(sf::FloatRect(0.0, 0.0, SCREEN_WIDTH, SCREEN_HEIGHT));


	float screenX, screenY;
	screenX = screenY = 0;
	float veclocity = 0;
	bool scroll = false;

	sf::RectangleShape r;
	r.setFillColor(sf::Color::Blue);
	r.setPosition(0, 1000);
	r.setSize(sf::Vector2f(200, 200));

	while (window.isOpen())
	{
		sf::Event event;
		int st = 0;
		string now = "";

		//HANDLE EVENT
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			switch (state)
			{
			case LOGIN:
				//if (event.type == sf::Event::MouseButtonPressed) cout << 1 << endl;
				st = login.handleEvent(event, Acc);
				cout << st << endl;
				break;
			case STUDENT:
				now = screenControl.handleEvent(event);
				if (now == "" && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				{
					if (rect.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						scroll = true;
					}
					else {
						scroll = false;
						now = "stop";
					}
				}
				if (scroll && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
					now = "down";
				}

				if (scroll && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
					now = "up";
				}

				if (scroll && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down) {
					now = "stop";
				}

				if (scroll && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up) {
					now = "stop";
				}
				break;
			}
		}

		//LOGIC

		switch (state)
		{
		case LOGIN:
			if (st == 1)
				state = ADMIN;
			if (st == 2)
				state = STUDENT;
			if (st == 3)
				state = LECTURER;
			if (st == -1)
				window.close();

			break;
		case STUDENT:
			if (now == "logout") state = LOGIN;
			if (now == "up")
			{
				veclocity = -0.2;

			}
			if (now == "down") {
				veclocity = 0.2;

			}
			if (now == "stop") {
				veclocity = 0;
			}
			rect.move(0, veclocity);
			if (rect.getPosition().y < 0)
				rect.setPosition(1772, 0);
			screenY = -(SCREEN_HEIGHT / 2) + rect.getPosition().y;
			if (screenX < 0) screenX = 0;
			if (screenY < 0) screenY = 0;

			view.reset(sf::FloatRect(screenX, screenY, screenX + SCREEN_WIDTH, screenY + SCREEN_HEIGHT));

			break;
		case LECTURER:
			break;
		case ADMIN:
			break;
		default:
			break;
		}

		//RENDER WINDOW
		window.clear();
		switch (state)
		{
		case LOGIN:
			login.render(window);
			break;
		case STUDENT:
			window.setView(view);
			screenControl.render(window);
			window.draw(rect);
			window.draw(r);
			break;
		case LECTURER:
			screenControl.render(window);
			break;
		case ADMIN:
			screenControl.render(window);
			break;

		default:
			break;
		}

		window.display();
	}

	return 0;
}