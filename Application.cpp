#include "Application.hpp"

using namespace std;
using namespace nlohmann;

void Application::set_multirun(bool em)
{
	multirun = em;
}

Application::Application(string name, string address, bool is_multirun_enabled):
	name(name),
	address(address),
	multirun(is_multirun_enabled)
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
	return multirun;
}

void Application::enable_multirun()
{
	multirun = 1;
}

void Application::disable_multirun()
{
	multirun = 0;
}

void Application::set_data(json& data)
{
	set_name(data["name"].get<string>());
	set_address(data["address"].get<string>());
	set_multirun(data["multirun"].get<bool>());
}

void Application::get_data(json& data)
{
	data["name"] = get_name();
	data["address"] = get_address();
	data["multirun"] = is_multirun_enabled();
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



