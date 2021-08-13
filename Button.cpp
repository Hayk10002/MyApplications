#include "Button.hpp"


Button::Button(Sprite im, Sprite im_hv, Sprite im_hl):
	image(im),
	image_hovered(im_hv),
	image_holded(im_hl)
{
	
}

Button::Button(Sprite im, bool is_same):
	image(im),
	image_hovered(im),
	image_holded(im)
{
	IntRect im_text_rect = im.getTextureRect();
	image_hovered.setTextureRect(IntRect(im_text_rect.left + (!is_same) * im_text_rect.width, im_text_rect.top, im_text_rect.width, im_text_rect.height));
	image_holded.setTextureRect(IntRect(im_text_rect.left + (!is_same) * 2 * im_text_rect.width, im_text_rect.top, im_text_rect.width, im_text_rect.height));
}

Button::Button(Sprite im, IntRect im_hv_text_rect, IntRect im_hl_text_rect):
	image(im),
	image_hovered(im),
	image_holded(im)
{
	image_hovered.setTextureRect(im_hv_text_rect);
	image_holded.setTextureRect(im_hl_text_rect);
}

bool Button::update(Event event)
{
	/*bool is_mouse_in_now = current_image.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window)));
	bool is_mouse_hl_now = Mouse::isButtonPressed(Mouse::Left);
	if (!is_mouse_in && is_mouse_in_now) { on_mouse_entered(); current_image = image_hovered; }
	if (is_mouse_in && !is_mouse_in_now) { on_mouse_lefted(); current_image = image;}
	if (!is_mouse_hl && is_mouse_hl_now && is_mouse_in_now) { on_press(); current_image = image_holded; }
	if (is_mouse_hl && !is_mouse_hl_now && is_mouse_in_now) { on_release(); is_cl = 1; current_image = image_hovered; }
	is_mouse_hl = is_mouse_hl_now;
	is_mouse_in = is_mouse_in_now;*/
	bool ret = 0;
	if (event.type == Event::MouseMoved)
	{
		Vector2f mouse_pos = Vector2f(event.mouseMove.x, event.mouseMove.y);
		bool is_mouse_in_now = current_image.getGlobalBounds().contains(mouse_pos);
		ret = is_mouse_in_now;
		if (!is_mouse_in && is_mouse_in_now) { on_mouse_entered(); current_image = image_hovered; }
		if (is_mouse_in && !is_mouse_in_now) { on_mouse_lefted(); current_image = image; }
		is_mouse_in = is_mouse_in_now;
	}
	else if (event.type == Event::MouseButtonPressed)
	{
		if (is_mouse_in)
		{
			ret = 1;
			on_press(); 
			current_image = image_holded;
		}
		else ret = 0;
	}
	else if (event.type == Event::MouseButtonReleased)
	{
		if (is_mouse_in)
		{
			ret = 1;
			on_release();
			current_image = image_hovered;
		}
		else ret = 0;
	}
	return ret;
}

Button createButton(Texture& texture, Vector2f position, IntRect texture_rect_def, IntRect texture_rect_hov, IntRect texture_rect_hol)
{
	Sprite def(texture, texture_rect_def);
	def.setPosition(position);
	return Button(def, texture_rect_hov, texture_rect_hol);
}

Button createButton(Texture& texture, Vector2f position, IntRect texture_rect_def)
{
	Sprite def(texture, texture_rect_def);
	def.setPosition(position);
	return Button(def);
}
