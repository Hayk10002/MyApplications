#include "Application.hpp"

string Application::add_cipher(string s, unsigned char k)
{
	for (int i = 0; i < s.size(); i++)
	{
		s[i] += k;
	}
	return s;
}

string Application::char_p_to_str(char* p, int l)
{
	string res;
	for (int i = 0; i < l; i++) res += p[i];
	return res;
}


Application::Application(string name, string address, bool is_multirun_enabled):
	name(name),
	address(address),
	enabled_multirun(is_multirun_enabled)
{
	
}

bool Application::run()
{
	return false;
}

bool Application::is_running()
{
	return false;
}

bool Application::is_multirun_enabled()
{
	return enabled_multirun;
}

void Application::enable_multirun()
{
	enabled_multirun = 1;
}

void Application::disable_multirun()
{
	enabled_multirun = 0;
}

void Application::set_data(string data)
{
	unsigned char key = data[0];
	int names = (unsigned char)data[1] * 256 + (unsigned char)data[2];
	int addresss = (unsigned char)data[3] * 256 + (unsigned char)data[4];
	data.erase(0, 5);
	string n = data.substr(0, names);
	data.erase(0, names);
	string add = data.substr(0, addresss);
	data.erase(0, addresss);
	enabled_multirun = data[0];
	set_name(add_cipher(n, -key));
	set_address(add_cipher(add, key));
}

void Application::set_data(char *data, int len)
{
	set_data(char_p_to_str(data, len));
}

string Application::get_data()
{
	string data = "";
	unsigned char key = rand() % 256;
	data += key;
	data += unsigned char(get_name().size() / 256);
	data += unsigned char(get_name().size() % 256);
	data += unsigned char(get_address().size() / 256);
	data += unsigned char(get_address().size() % 256);
	data += add_cipher(get_name(), key);
	data += add_cipher(get_address(), -key);
	data += is_multirun_enabled();
	return data;
}

void Application::set_name(string name)
{
	this->name = name;
}

string Application::get_name()
{
	return name;
}

void Application::set_address(string address)
{
	this->address = address;
}

string Application::get_address()
{
	return address;
}



