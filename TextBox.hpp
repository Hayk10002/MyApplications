#pragma once
#pragma warning(disable : 4996)
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;
class TextBox : public Drawable
{
	int dif = 0;
	bool is_sel = 0;
	Text drawing_text;
	string text = "";
	Font font;
	Sprite background, background_sel;
	void init_drawing_text();
	void update_drawing_text();
	void proceed_char(char ch);
	void procees_backspace();
public:
	TextBox(Sprite im, Sprite im_sel);
	TextBox(Sprite im, bool is_same_image = 0);
	TextBox(Sprite im, IntRect im_sel);
	void select();
	void unselect();
	bool update(Event event);
	void set_text_color(Color col);
	void set_text(string text);
	bool set_font(string font_file);
	void set_font(Font font);
	Font get_font();
	Color get_text_color();
	string get_text();
	FloatRect get_bounds();
	bool is_selected();
	virtual void draw(RenderTarget& target, RenderStates states) const
	{
		if (is_sel) target.draw(background_sel, states);
		else target.draw(background, states);
		target.draw(drawing_text, states);
	}
};


TextBox createTextBox(Texture& texture, Vector2f position, IntRect texture_rect_def, IntRect texture_rect_selected);
TextBox createTextBox(Texture& texture, Vector2f position, IntRect texture_rect_def);