#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <imgui.h>
#include <imgui-SFML.h>

namespace Game {

	class Game
	{
	public:
		Game();
		~Game();

		void start();
		void events();
		void drawGUI();
		void clear();
		void display();

		inline const float getDeltaTime() const { return deltaTime; }

		sf::Clock clock; 
		sf::RenderWindow window;
		const unsigned int winWidth;
		const unsigned int winHeight;
	private:
		sf::Time timeElapsed;
		float deltaTime;
	};
}
