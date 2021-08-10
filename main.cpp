#define DEBUG 0
#if DEBUG == 0
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "../../../Other/Processing.hpp"
#include "Global.hpp"
#include "MainMenu.hpp"
#include "AddMenu.hpp"
#include "DeleteConfirmMenu.hpp"
#include "ApplListMenu.hpp"
#include "TextBox.hpp"
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(200, 200), "SFML works!");


	procs.add_process(main_menu, "main_menu");
	procs["main_menu"].run();
	while (window.isOpen())
	{
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
	}

        window.clear();
        window.display();
}
#elif DEBUG == 1
#include <Windows.h>
#include <iostream>
using namespace std;
int main()
{
	char filename[256];
	filename[0] = '\0';
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = filename;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(filename);
	ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	GetOpenFileName(&ofn);
	cout << filename << endl;
	system("pause");
	return 0;
}
#endif
