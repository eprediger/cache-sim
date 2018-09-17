#ifndef __SPECS_H__
#define __SPECS_H__

#include <string>
#include <map>

class Specs {
public:
	Specs(const std::map<std::string, std::string> config);
	~Specs();

	std::string get_specs();

private:
	/* specs */
	std::string vendor_id;
	std::string model_name;
	std::string cpu_MHz;
};

#endif