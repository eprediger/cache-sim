#ifndef __CONFIGFILEREADER_H__
#define __CONFIGFILEREADER_H__

#include <fstream>
#include <map>
#include <string>

class ConfigFileReader {
public:
	explicit ConfigFileReader(std::string filename);

	~ConfigFileReader();

	void read_configuration();

	std::string get_vendor_id();

	std::string get_model_name();

	std::string get_cpu_MHz();

	std::string get_cache_type();

	unsigned int get_cache_size();

	unsigned int get_line_size();

	bool get_debug();

	
private:
	std::ifstream file;
	std::map<std::string, std::string> config_map;
};

#endif
