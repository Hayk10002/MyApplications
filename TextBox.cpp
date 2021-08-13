#include "TextBox.hpp"

void TextBox::init_text()
{
	dif = 5;
	text.setCharacterSize(background.getLocalBounds().height - 2 * dif);
	text.setColor(Color::Black);
	text.setFont(font);
	text.setPosition(background.getLocalBounds().left + dif, background.getLocalBounds().top + dif);
	text.setString("");
}

TextBox::TextBox(Sprite im, Sprite im_sel):
	background(im),
	background_sel(im_sel)
{
	init_text();
}

TextBox::TextBox(Sprite im, bool is_same_image):
	background(im),
	background_sel(im)
{
	IntRect im_text_rect = im.getTextureRect();
	background_sel.setTextureRect(IntRect(im_text_rect.left + !is_same_image * im_text_rect.width, im_text_rect.top, im_text_rect.width, im_text_rect.height));
	init_text();
}

TextBox::TextBox(Sprite im, IntRect im_sel):
	background(im),
	background_sel(im)
{
	background_sel.setTextureRect(im_sel);
	init_text();
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
	bool ret = 0;
	if (event.type == Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			if (!is_selected() && get_bounds().contains(event.mouseButton.x, event.mouseButton.y)) 
			{
				select();
				ret = 1; 
			}
			else
			{
				unselect();
				ret = get_bounds().contains(event.mouseButton.x, event.mouseButton.y);
			}
		}
	}
	else if (event.type == Event::MouseButtonPressed) ret = get_bounds().contains(event.mouseButton.x, event.mouseButton.y);
	else if(event.type == Event::MouseMoved) ret = get_bounds().contains(event.mouseMove.x, event.mouseMove.y);
	return ret;
}

void TextBox::set_text_color(Color col)
{
	text.setColor(col);
}

void TextBox::set_text(string text)
{
	this->text.setString(text);
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
	return text.getColor();
}

string TextBox::get_text()
{
	return text.getString();
}

FloatRect TextBox::get_bounds()
{
	return is_selected() ? background.getGlobalBounds() : background_sel.getGlobalBounds();
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
