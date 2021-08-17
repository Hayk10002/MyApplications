#include "ApplListMenu.hpp"

ApplListMenu::ApplListMenu(string data_file_name) :
	data_file_name(data_file_name),
	search_text_box(Sprite())
{
}

void ApplListMenu::save_data_to_file()
{
	ofstream file(data_file_name);
	for (auto appl : all_applications)
	{
		string data = appl.get_data();
		file.write(data.c_str(), data.size());
	}
}

void ApplListMenu::get_data_from_file()
{
	all_applications.clear();
	ifstream file(data_file_name);
	if (!file)
	{
		cout << "Can't open the file " << data_file_name;
		abort();
	}
	file.seekg(0, ios::beg);
	while (1)
	{
		char key, ns[2], as[2];
		file.read(&key, 1);
		if (file.tellg() == -1) break;
		file.read(ns, 2);
		file.read(as, 2);
		int len = 6 + (unsigned char)ns[0] * 256 + (unsigned char)ns[1] + (unsigned char)as[0] * 256 + (unsigned char)as[1];
		char* data = new char[len];
		file.seekg(-5, ios::cur);
		file.read(data, len);
		Application appl;
		appl.set_data(data, len);
		all_applications.push_back(appl);
		delete[] data;
	}

}

void ApplListMenu::add_appl()
{
}

void ApplListMenu::delete_appl()
{
}

void ApplListMenu::search()
{
}
