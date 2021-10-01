#include "TextBox.hpp"

using namespace std;
using namespace sf;

#define BACKSPACE 8
#define TAB 9
#define ENTER 13
#define ESC 27

void TextBox::init()
{
	dif = 5.f;
	drawing_text.setCharacterSize((size_t)(get_bounds().height - 2 * dif));
	drawing_text.setColor(Color::Black);
	drawing_text.setFont(font);
	drawing_text.setString("");
	drawing_text.setPosition(get_bounds().left + dif, get_bounds().top + dif / 2.f);

	cursor.setFillColor(Color::Black);
	cursor.setPosition(get_cursor_pos());
	cursor.setSize(Vector2f(2.f, (float)drawing_text.getCharacterSize()));
	cursor.setOrigin(1, 0);
}

void TextBox::update_drawing_text()
{
	string t = text;
	drawing_text.setString(t);
	if (drawing_text.getGlobalBounds().width > get_bounds().width - 2 * dif)
	{
		t = "..." + t;
		while (drawing_text.getGlobalBounds().width > get_bounds().width - 2 * dif)
		{
			t.erase(3, 1);
			drawing_text.setString(t);
		}
		drawing_text.setPosition(Vector2f(get_bounds().left + get_bounds().width - drawing_text.getGlobalBounds().width - dif, get_bounds().top + dif));
	}
	else drawing_text.setPosition(get_bounds().left + dif, get_bounds().top + dif);
}

void TextBox::proceed_char(char ch)
{
	text.insert(cursor_index, 1, ch);
	cursor_index++;
	update_drawing_text();
}

void TextBox::proceed_backspace()
{
	if (cursor_index)
	{
		text.erase(text.size() - 1);
		cursor_index--;
	}
	update_drawing_text();
}

Vector2f TextBox::get_cursor_pos()
{
	return Vector2f(drawing_text.getGlobalBounds().left + drawing_text.getGlobalBounds().width, get_bounds().top + dif);
}

TextBox::TextBox(Sprite im, Sprite im_sel):
	background(im),
	background_sel(im_sel)
{
	init();
}

TextBox::TextBox(Sprite im, bool is_same_image):
	background(im),
	background_sel(im)
{
	IntRect im_text_rect = im.getTextureRect();
	background_sel.setTextureRect(IntRect(im_text_rect.left + !is_same_image * im_text_rect.width, im_text_rect.top, im_text_rect.width, im_text_rect.height));
	init();
}

TextBox::TextBox(Sprite im, IntRect im_sel):
	background(im),
	background_sel(im)
{
	background_sel.setTextureRect(im_sel);
	init();
}

void TextBox::select()
{
	is_sel = 1;
}

void TextBox::unselect()
{
	is_sel = 0;
}

bool TextBox::update(Event event)
{
	bool is_event_used = 0;
	if (event.type == Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			if (!is_selected() && get_bounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				select();
				is_event_used = 1; 
			}
			else
			{
				unselect();
				is_event_used = get_bounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y);
			}
		}
	}
	else if (event.type == Event::MouseButtonPressed) is_event_used = get_bounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y);
	else if(event.type == Event::MouseMoved) is_event_used = get_bounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y);
	if (is_selected())
	{
		if (event.type == Event::TextEntered)
		{
			switch (event.text.unicode)
			{
			case ESC:
			case ENTER:
				is_event_used = 1;
				unselect();
				break;
			case TAB:
				break;
			case BACKSPACE:
				is_event_used = 1;
				proceed_backspace();
				break;
			default:
				is_event_used = 1;
				proceed_char(event.text.unicode);
				break;
			}
		}
	}
	cursor.setPosition(get_cursor_pos());
	return is_event_used;
}

void TextBox::set_text_color(Color col)
{
	drawing_text.setColor(col);
}

void TextBox::set_text(string text)
{
	this->text = text;
}

bool TextBox::set_font(string font_file)
{
	return font.loadFromFile(font_file);
}

void TextBox::set_font(Font font)
{
	this->font = font;
}

Font TextBox::get_font()
{
	return font;
}

Color TextBox::get_text_color()
{
	return drawing_text.getColor();
}

string TextBox::get_text()
{
	return text;
}

FloatRect TextBox::get_bounds()
{
	return is_selected() ? background_sel.getGlobalBounds() : background.getGlobalBounds();
}

bool TextBox::is_selected()
{
	return is_sel;
}

TextBox createTextBox(Texture& texture, Vector2f position, IntRect texture_rect_def, IntRect texture_rect_selected)
{
	Sprite im(texture, texture_rect_def);
	im.setPosition(position);
	return TextBox(im, texture_rect_selected);
}

TextBox createTextBox(Texture& texture, Vector2f position, IntRect texture_rect_def)
{
	Sprite im(texture, texture_rect_def);
	im.setPosition(position);
	return TextBox(im);
}
