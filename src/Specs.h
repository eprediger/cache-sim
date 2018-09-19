#ifndef __SPECS_H__
#define __SPECS_H__

#include <string>
#include <iostream>
#include <map>

class Specs {
public:
	explicit Specs(const std::map<std::string, std::string> config);
	~Specs();

	void print_specs();

private:
	std::string vendor_id;
	std::string model_name;
	std::string cpu_MHz;
};

#endif
