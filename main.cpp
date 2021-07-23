#include <SFML/Graphics.hpp>
#include "../../../Other/Processing.hpp"
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(200, 200), "SFML works!");

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.display();
	}

	return 0;
}
