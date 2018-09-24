#include "ConfigFileReader.h"

#include <map>
#include <string>

ConfigFileReader::ConfigFileReader(std::string filename) : 
	file(filename, std::ifstream::in) {}

ConfigFileReader::~ConfigFileReader() {
	file.close();
}

void ConfigFileReader::read_configuration() {
	const char key_delim = '=';
	const char value_delim = '\n';

	std::string key, value;
	
	while (std::getline(this->file, key, key_delim)) {
		std::getline(this->file, value, value_delim);
		this->config_map[key] = value;
	}
}

std::string ConfigFileReader::get_vendor_id() {
	return this->config_map.find("vendor_id")->second;
}

std::string ConfigFileReader::get_model_name() {
	return this->config_map.find("model name")->second;
}

std::string ConfigFileReader::get_cpu_MHz() {
	return this->config_map.find("cpu MHz")->second;
}

std::string ConfigFileReader::get_cache_type() {
	return this->config_map.find("cache type")->second;
}

unsigned int ConfigFileReader::get_cache_size() {
	return std::stoi(this->config_map.find("cache size")->second, 0, 10);
}

unsigned int ConfigFileReader::get_line_size() {
	return std::stoi(this->config_map.find("line size")->second, 0, 10);
}

bool ConfigFileReader::get_debug() {
	bool debug_value(false);
	if (this->config_map.find("debug") != this->config_map.end()) {
		std::string debug_str = this->config_map.find("debug")->second;
		debug_str == "true" ? debug_value = true : debug_value = false;
	}
	return debug_value;
}
