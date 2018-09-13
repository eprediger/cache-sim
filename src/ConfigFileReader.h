#ifndef __CONFIGFILEREADER_H__
#define __CONFIGFILEREADER_H__

#include <fstream>
#include <map>
#include <string>

class ConfigFileReader {
public:
	ConfigFileReader(const std::string filename);

	~ConfigFileReader();

	void read_configuration();
	
private:
	std::ifstream file;
	std::map<std::string, std::string> config_map;
};

#endif
