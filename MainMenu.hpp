#pragma once
#include <SFML/Graphics.hpp>
#include "../../../Other/Processing.hpp"
using namespace sf;
class MainMenu : public Process
{

public:
	MainMenu();
	void on_run();
	void on_pause();
	void on_resume();
	void on_stop();
	void loop();
};

