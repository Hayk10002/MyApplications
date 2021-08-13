#include "MainMenu.hpp"

MainMenu::MainMenu():
	background(MainMenuBackground)
{
	add = createButton(ButtonsTexture, Vector2f(400, 80), IntRect(0, 100, 200, 100));
	del = createButton(ButtonsTexture, Vector2f(250, 250), IntRect(0, 200, 200, 100));
	run = createButton(ButtonsTexture, Vector2f(550, 250), IntRect(0, 0, 200, 100));
	exit = createButton(ButtonsTexture, Vector2f(400, 420), IntRect(0, 300, 200, 100));
}

void MainMenu::on_run()
{
	this_proc_ptr = &procs["main_menu"];
	run.on_release = []()
	{
		cout << "Run\n";
	};
	add.on_release = []()
	{
		cout << "Add\n";
	};
	del.on_release = []()
	{
		cout << "Delete\n";
	};
	exit.on_release = []()
	{
		window.close();
	};
}

void MainMenu::on_pause()
{
}

void MainMenu::on_resume()
{
}

void MainMenu::on_stop()
{
}

void MainMenu::loop()
{
	Event event;
	while (this_proc_ptr->get_event(event))
	{
		if (event.type == Event::Closed) window.close();

	}
	

	//run.update();
	//add.update();
	//del.update();
	//exit.update();
	this_proc_ptr->clear();
	this_proc_ptr->draw(background);
	this_proc_ptr->draw(run);
	this_proc_ptr->draw(add);
	this_proc_ptr->draw(del);
	this_proc_ptr->draw(exit);
	this_proc_ptr->display();
}
