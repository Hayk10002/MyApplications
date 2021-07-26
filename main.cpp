#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "../../../Other/Processing.hpp"
#include "Global.hpp"
#include "MainMenu.hpp"
using namespace sf;
int main()
{
	window.create(VideoMode(WINDOW_RES.x, WINDOW_RES.y), "MyApplications", Style::Close | Style::Titlebar);
	window.setPosition(Vector2i((SCREEN_RES - WINDOW_RES) / 2u));
	window.setFramerateLimit(60);
	//MainMenu main_menu;
	//procs.add_process(main_menu, "main_menu");

	while (window.isOpen())
	{
		procs.add_events();
		procs.update_procs();
		procs.clear();
		procs.draw();
		procs.display();
	}

	return 0;
}
