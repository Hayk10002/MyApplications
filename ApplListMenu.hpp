#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <deque>
#include <fstream>
#include <iostream>
#include "../../../Other/json.hpp"
#include "Application.hpp"
#include "TextBox.hpp"

class ApplListMenu : public sf::Drawable
{
public:
	ApplListMenu(std::string data_file_name);
	std::deque<Application> all_applications;
	std::deque<Application*> current_applications_ptrs;
	std::string data_file_name;
	TextBox search_text_box;
	void save_data_to_file();
	void get_data_from_file();
	void add_appl();
	void delete_appl();
	void search();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{

	}
private:

};