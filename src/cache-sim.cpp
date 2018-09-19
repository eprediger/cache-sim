#include "ConfigFileReader.h"

#include "CPU.h"

#include "DirectCache.h"
#include "FIFOCache.h"
#include "LRUCache.h"

#include <iostream>
#include <string>
#include <vector>

int main(int argc, const char *argv[]) {
	if (argc < 3) {
		std::cout << "Usage: " << argv[0] << " <config-file> [<cpu-NN.bin>]\n";
		return 1;
	} else {
		ConfigFileReader config_file(argv[1]);
		config_file.read_configuration();
		
		std::string cache_type = config_file.get_cache_type();

		Cache* cache_memory;
		if (cache_type == "direct") {
			cache_memory = new DirectCache(config_file.get_configuration());
		}
		if (cache_type == "associative-fifo") {
			cache_memory = new FIFOCache(config_file.get_configuration());
		}
		if (cache_type == "associative-lru") {
			cache_memory = new LRUCache(config_file.get_configuration());
		}

		cache_memory->print_cache_specs();

		std::vector<Thread*> threads;

		for (int i = 2; i < argc; ++i) {
			threads.push_back(new CPU(argv[i], *cache_memory));
		}

		for (size_t i = 0; i < threads.size(); ++i) {
			threads[i]->start();
		}

		for (size_t i = 0; i < threads.size(); ++i) {
			threads[i]->join();
			delete threads[i];
		}

		std::cout << cache_memory->report_stats();
		std::cerr << cache_memory->report_error();
		delete cache_memory;
	}

	return 0;
}
