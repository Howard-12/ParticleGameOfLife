#include "Game.h"

#include <iostream>

namespace Game {
	Game::Game() : 
		winWidth  (sf::VideoMode::getDesktopMode().width), 
		winHeight (sf::VideoMode::getDesktopMode().height),
		deltaTime (0.f)
	{
		std::srand(std::time(nullptr));
		window.create(sf::VideoMode(winWidth, winHeight), "Particle Game of Life", sf::Style::Fullscreen);
		window.setFramerateLimit(0);
		ImGui::SFML::Init(window);
	}

	Game::~Game()
	{
		ImGui::SFML::Shutdown();
	}

	void Game::start()
	{
		timeElapsed = clock.restart();
		deltaTime = (float)timeElapsed.asMicroseconds() / 10000.f;
	}

	void Game::events()
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(window, event);

			if (event.type == sf::Event::Closed)
				window.close();
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
				window.close();
		}
	}

	void Game::drawGUI()
	{
		ImGui::SFML::Update(window, timeElapsed);

		bool t = true;
		if (t)
			ImGui::ShowDemoWindow(&t);

		ImGui::Begin("Yeah");
		ImGui::Button("Look");
		ImGui::End();
	}

	void Game::clear()
	{
		window.clear();
	}

	void Game::display()
	{
		ImGui::SFML::Render(window);
		window.display();
		ImGui::EndFrame();
	}
}