#pragma once
#include <string>
#include "../../../Other/json.hpp"
#include "Global.hpp"

class Application
{
	std::string name, address;
	bool is_r = 0, multirun;
	void set_multirun(bool em);
public:
	Application(std::string name = "", std::string address = "", bool is_multirun_enabled = 0);
	bool run();
	bool is_running();
	bool is_multirun_enabled();
	void enable_multirun();
	void disable_multirun();
	void set_data(nlohmann::json& data);
	void get_data(nlohmann::json& data);
	void set_name(std::string name);
	std::string get_name();
	void set_address(std::string address);
	std::string get_address();
};
