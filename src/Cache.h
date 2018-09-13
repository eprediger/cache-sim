#ifndef __CACHE_H__
#define __CACHE_H__

#include <string>
#include <map>

class Cache {
public:
	Cache(const std::map<std::string, std::string> config);
	~Cache();

	std::string get_specs();

protected:
	std::string vendor_id;
	std::string model_name;
	std::string cpu_MHz;
	std::string cache_type;
	int cache_size;
	int line_size;
	bool debug;
};

#endif
