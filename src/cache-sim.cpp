#include "ConfigFileReader.h"

#include <iostream>

int main(int argc, const char *argv[]) {

	if (argc == 1) {
		std::cout << "Usage: " << argv[0] << " <config-file>\n";
		return 1;
	} else {
		ConfigFileReader config_file(argv[1]);
		config_file.read_configuration();
	}

	return 0;
}
