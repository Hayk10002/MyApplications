#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <deque>
#include "Application.hpp"
#include "TextBox.hpp"
using namespace sf;
using namespace std;
class ApplListMenu : public Drawable
{
	deque<Application> all_applications;
	deque<Application*> current_application_ptrs;
	string current_search;
	TextBox serch_text_box;
	void save_data_in_file();
	void add_appl();
	void delete_appl();
	void search();
	virtual void draw(RenderTarget& target, RenderStates states) const
	{

	}
};

