#pragma once
#pragma warning(disable : 4996)

#include <SFML/Graphics.hpp>
#include <string>

class TextBox : public sf::Drawable
{
	float dif = 0.f;
	bool is_sel = 0;
	sf::Text drawing_text;
	std::string text = "";
	sf::Font font;
	sf::Sprite background, background_sel;
	sf::RectangleShape cursor;
	size_t cursor_index = 0;
	void init();
	void update_drawing_text();
	void proceed_char(char ch);
	void proceed_backspace();
	sf::Vector2f get_cursor_pos();
public:
	TextBox(sf::Sprite im, sf::Sprite im_sel);
	TextBox(sf::Sprite im, bool is_same_image = 0);
	TextBox(sf::Sprite im, sf::IntRect im_sel);
	void select();
	void unselect();
	bool update(sf::Event event);
	void set_text_color(sf::Color col);
	void set_text(std::string text);
	bool set_font(std::string font_file);
	void set_font(sf::Font font);
	sf::Font get_font();
	sf::Color get_text_color();
	std::string get_text();
	sf::FloatRect get_bounds();
	bool is_selected();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		if (is_sel) target.draw(background_sel, states);
		else target.draw(background, states);
		target.draw(drawing_text, states);
		if (is_sel) target.draw(cursor, states);
	}
};


TextBox createTextBox(sf::Texture& texture, sf::Vector2f position, sf::IntRect texture_rect_def, sf::IntRect texture_rect_selected);
TextBox createTextBox(sf::Texture& texture, sf::Vector2f position, sf::IntRect texture_rect_def);