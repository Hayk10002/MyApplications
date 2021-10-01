#include "ApplListMenu.hpp"

using namespace sf;
using namespace std;
using namespace nlohmann;

ApplListMenu::ApplListMenu(string data_file_name) :
	data_file_name(data_file_name),
	search_text_box(Sprite())
{
}

void ApplListMenu::save_data_to_file()
{
	json appl_data = {};
	ofstream file(data_file_name);
	for (auto appl : all_applications)
	{
		json data;
		appl.get_data(data);
		appl_data.push_back(data);
	}
	file << appl_data;
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
	json appl_data = {};
	file >> appl_data;
	for (int i = 0; !appl_data[i].empty(); i++)
	{
		Application appl;
		appl.set_data(appl_data[i]);
		all_applications.push_back(appl);
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
