#include "Global.hpp"

using namespace sf;
using namespace std;

RenderWindow window;
Procs procs(window);
const Vector2u WINDOW_RES = Vector2u(1000, 600), SCREEN_RES = Vector2u(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
Texture MainMenuBackground, ButtonsTexture, TextBoxesTexture;

string add_caesar_cipher(string s, unsigned char k)
{
	for (size_t i = 0; i < s.size(); i++) s[i] += k;
	return s;
}




