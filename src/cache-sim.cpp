#include "ConfigFileReader.h"

#include "CPU.h"

#include "Cache.h"
#include "DirectCache.h"
#include "FIFOCache.h"
#include "LRUCache.h"

#include <iostream>
#include <string>
#include <vector>

#define MIN_ARGS 3

int main(int argc, const char *argv[]) {
	if (argc < MIN_ARGS) {
		std::cout << "Usage: " << argv[0] << " <config-file> [<cpu-NN.bin>]\n";
		return 1;
	} else {
		ConfigFileReader config_file(argv[1]);
		config_file.read_configuration();
		
		std::unique_ptr<Cache> cache_memory(nullptr);

		if (config_file.get_cache_type() == "direct") {
			cache_memory.reset(new DirectCache(config_file));
		}
		if (config_file.get_cache_type() == "associative-fifo") {
			cache_memory.reset(new FIFOCache(config_file));
		}
		if (config_file.get_cache_type() == "associative-lru") {
			cache_memory.reset(new LRUCache(config_file));
		}

		std::cout << cache_memory->get_cache_specs();

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
	}

	return 0;
}
