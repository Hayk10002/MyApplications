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
	IntRect im_hv_text_rect = IntRect(im_text_rect.left + (!is_same) * im_text_rect.width, im_text_rect.top, im_text_rect.width, im_text_rect.height);
	image_hovered.setTextureRect(im_hv_text_rect);
	IntRect im_hl_text_rect = IntRect(im_text_rect.left + (!is_same) * 2 * im_text_rect.width, im_text_rect.top, im_text_rect.width, im_text_rect.height);
	image_holded.setTextureRect(im_hl_text_rect);
}

Button::Button(Sprite im, IntRect im_hv_text_rect, IntRect im_hl_text_rect):
	image(im),
	image_hovered(im),
	image_holded(im)
{
	image_hovered.setTextureRect(im_hv_text_rect);
	image_holded.setTextureRect(im_hl_text_rect);
}

void Button::update()
{
	if (cl_count) cl_count--;
	bool is_mouse_in_now = current_image.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window)));
	bool is_mouse_hl_now = Mouse::isButtonPressed(Mouse::Left);
	if (!is_mouse_in && is_mouse_in_now) { on_mouse_entered(); current_image = image_hovered; }
	if (is_mouse_in && !is_mouse_in_now) { on_mouse_lefted(); current_image = image;}
	if (!is_mouse_hl && is_mouse_hl_now && is_mouse_in_now) { on_press(); current_image = image_holded; }
	if (is_mouse_hl && !is_mouse_hl_now && is_mouse_in_now) { on_release(); cl_count++; current_image = image_hovered; }
	is_mouse_hl = is_mouse_hl_now;
	is_mouse_in = is_mouse_in_now;
}

bool Button::is_clicked()
{
	return cl_count;
}


