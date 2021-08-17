#pragma once
#include <string>
using namespace std;
class Application
{
	string name, address;
	bool is_r = 0, enabled_multirun;
	static string add_cipher(string s, unsigned char k);
	static string char_p_to_str(char* p, int l);
public:
	Application(string name = "", string address = "", bool is_multirun_enabled = 0);
	bool run();
	bool is_running();
	bool is_multirun_enabled();
	void enable_multirun();
	void disable_multirun();
	void set_data(string data);
	void set_data(char* data, int len);
	string get_data();
	void set_name(string name);
	string get_name();
	void set_address(string address);
	string get_address();
};
