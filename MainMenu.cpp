#include "MainMenu.hpp"

MainMenu::MainMenu():
	background(MainMenuBackground),
	add_sprite(ButtonsTexture, IntRect(0, 100, 200, 100)),
	del_sprite(ButtonsTexture, IntRect(0, 200, 200, 100)),
	run_sprite(ButtonsTexture, IntRect(0, 0, 200, 100)),
	exit_sprite(ButtonsTexture, IntRect(0, 300, 200, 100))
	
{
	run_sprite.setPosition(400, 80);
	add_sprite.setPosition(250, 250);
	del_sprite.setPosition(550, 250);
	exit_sprite.setPosition(400, 420);
	run = Button(run_sprite);
	add = Button(add_sprite);
	del = Button(del_sprite);
	exit = Button(exit_sprite);
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
	

	run.update();
	add.update();
	del.update();
	exit.update();
	this_proc_ptr->clear();
	this_proc_ptr->draw(background);
	this_proc_ptr->draw(run);
	this_proc_ptr->draw(add);
	this_proc_ptr->draw(del);
	this_proc_ptr->draw(exit);
	this_proc_ptr->display();
}
