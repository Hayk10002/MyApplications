#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "Global.hpp"

class Button : public sf::Drawable
{
	sf::Sprite image, image_hovered, image_holded;
	sf::Sprite current_image = image;
	bool is_mouse_in = 0;
public:
	std::function<void(void)> on_press = []() {}, on_release = []() {}, on_mouse_entered = []() {}, on_mouse_lefted = []() {};
	Button() {}
	Button(sf::Sprite im, sf::Sprite im_hv, sf::Sprite im_hl);
	Button(sf::Sprite im, bool is_same_image = 0);
	Button(sf::Sprite im, sf::IntRect im_hv_text_rect, sf::IntRect im_hl_text_rect);
	bool update(sf::Event event);
	
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const
	{
		window.draw(current_image, states);
	}

};


Button createButton(sf::Texture& texture, sf::Vector2f position, sf::IntRect texture_rect_def, sf::IntRect texture_rect_hov, sf::IntRect texture_rect_hol);
Button createButton(sf::Texture& texture, sf::Vector2f position, sf::IntRect texture_rect_def);

