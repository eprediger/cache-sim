#include "ConfigFileReader.h"
#include "Cache.h"

#include <iostream>
#include <map>

int main(int argc, const char *argv[]) {

	if (argc == 1) {
		std::cout << "Usage: " << argv[0] << " <config-file>\n";
		return 1;
	} else {
		ConfigFileReader config_file(argv[1]);
		config_file.read_configuration();
		Cache cacheDirecto(config_file.get_configuration());

		std::cout << cacheDirecto.get_specs();
	}

	return 0;
}
