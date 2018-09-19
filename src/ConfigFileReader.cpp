#include "ConfigFileReader.h"

#include <map>
#include <string>

ConfigFileReader::ConfigFileReader(std::string filename) : 
	file(filename, std::ifstream::in) {}

ConfigFileReader::~ConfigFileReader() {
	file.close();
}

void ConfigFileReader::read_configuration() {
	char key_delim = '=';
	char value_delim = '\n';

	std::string key, value;
	
	while (std::getline(this->file, key, key_delim)) {
		std::getline(this->file, value, value_delim);
		this->config_map[key] = value;
	}
}

std::string ConfigFileReader::get_cache_type() {
	return this->config_map.find("cache type")->second;
}

std::map<std::string, std::string> ConfigFileReader::get_configuration() {
	return this->config_map;
}
