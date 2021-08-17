#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <deque>
#include <fstream>
#include <iostream>
#include "Application.hpp"
#include "TextBox.hpp"
using namespace sf;
using namespace std;
class ApplListMenu : public Drawable
{
public:
	ApplListMenu(string data_file_name);
	deque<Application> all_applications;
	deque<Application*> current_applications_ptrs;
	string data_file_name;
	TextBox search_text_box;
	void save_data_to_file();
	void get_data_from_file();
	void add_appl();
	void delete_appl();
	void search();
	virtual void draw(RenderTarget& target, RenderStates states) const
	{

	}
};