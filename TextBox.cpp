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
	background_sel(*background.getTexture(), IntRect(background.getTextureRect().left + is_same_image * background.getTextureRect().width, background.getTextureRect().top, background.getTextureRect().width, background.getTextureRect().height))
{
	init_text();
}

TextBox::TextBox(Sprite im, IntRect im_sel):
	background(im),
	background_sel(*background.getTexture(), im_sel)
{
	init_text();
}

void TextBox::select()
{
	is_selected = 1;
}

void TextBox::unselect()
{
	is_selected = 0;
}

void TextBox::proceed_char(char ch)
{
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
