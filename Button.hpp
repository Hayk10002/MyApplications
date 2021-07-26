#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "Global.hpp"
using namespace sf;
using namespace std;
class Button : public Drawable
{
	Sprite image, image_hovered, image_holded;
	Sprite* current_image_ptr = &image;
	bool is_mouse_in = 0, is_mouse_hl = 0;
	int cl_count = 0;
public:
	function<void(void)> on_press = []() {}, on_release = []() {}, on_mouse_entered = []() {}, on_mouse_lefted = []() {};
	Button() {}
	Button(Sprite im, Sprite im_hv, Sprite im_hl);
	Button(Sprite im, bool is_same_image = 0);
	Button(Sprite im, IntRect im_hv_text_rect, IntRect im_hl_text_rect);
	void update();
	bool is_clicked();
	
	virtual void draw(RenderTarget& window, RenderStates states) const
	{
		window.draw(*current_image_ptr, states);
	}

};

