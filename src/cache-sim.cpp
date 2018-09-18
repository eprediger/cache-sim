#include "ConfigFileReader.h"
#include "AddressReader.h"

#include "DirectCache.h"
#include "FIFOCache.h"
#include "LRUCache.h"

#include <iostream>
#include <string>

int main(int argc, const char *argv[]) {

	if (argc < 3) {
		std::cout << "Usage: " << argv[0] << " <config-file> [<cpu-NN.bin>]\n";
		return 1;
	} else {
		ConfigFileReader config_file(argv[1]);
		config_file.read_configuration();
		
		std::string cache_type = config_file.get_cache_type();

		Cache* cache_memory;
		if (cache_type.compare("direct") == 0) {
			cache_memory = new DirectCache(config_file.get_configuration());
		}
		if (cache_type.compare("associative-fifo") == 0) {
			cache_memory = new FIFOCache(config_file.get_configuration());
		}
		if (cache_type.compare("associative-lru") == 0) {
			cache_memory = new LRUCache(config_file.get_configuration());
		}

		std::cout << cache_memory->get_cache_specs();

		for (int i = 2; i < argc; ++i) {
			AddressReader address_file(argv[i]);
			address_file.read_address();
			cache_memory->access_memory_addresses(address_file.get_address());
		}

		std::cout << cache_memory->report_stats();
		std::cerr << cache_memory->report_error();
		delete cache_memory;
	}

	return 0;
}
