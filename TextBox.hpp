#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;
class TextBox : Drawable
{
	Text text;
	Font font;
	Sprite background;
	void proceed_char(char ch);
	void set_text_color(Color col);
	void set_text(string text);
	Color get_text_color();
	string get_text();
	virtual void draw(RenderTarget& target, RenderStates states) const
	{

	}
};
