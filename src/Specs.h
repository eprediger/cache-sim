#ifndef __SPECS_H__
#define __SPECS_H__

#include "ConfigFileReader.h"

#include <string>
#include <iostream>
#include <map>

class Specs {
public:
	explicit Specs(ConfigFileReader& config);

	~Specs();

	std::string get_specs();

private:
	const std::string vendor_id;
	const std::string model_name;
	const std::string cpu_MHz;
};

#endif
