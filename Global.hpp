#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <ctime>
#include "../../../Other/Processing.hpp"

extern const sf::Vector2u WINDOW_RES, SCREEN_RES;
extern sf::RenderWindow window;
extern Procs procs;
extern sf::Texture MainMenuBackground, ButtonsTexture, TextBoxesTexture;
std::string add_caesar_cipher(std::string s, unsigned char k);





