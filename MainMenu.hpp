#pragma once
#include <SFML/Graphics.hpp>
#include "../../../Other/Processing.hpp"
#include "Global.hpp"
#include "Button.hpp"
using namespace sf;
class MainMenu : public Process
{
	Sprite background, add_sprite, del_sprite, run_sprite, exit_sprite;
	Proc* this_proc_ptr;
	
public:
	Button add, del, run, exit;
	MainMenu();
	void on_run();
	void on_pause();
	void on_resume();
	void on_stop();
	void loop();
};

