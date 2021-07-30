#pragma once
#include "../../../Other/Processing.hpp"
#include "Button.hpp"
#include "Application.hpp"
class RunMenu :public Process
{
	Application* current_appl_ptr;
	Button run_button;
public:
	RunMenu();
	void on_run();
	void on_pause();
	void on_resume();
	void on_stop();
	void loop();
};

