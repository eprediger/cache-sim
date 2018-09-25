#include "CPU.h"

CPU::CPU(const char* address_filename, Cache& cache) : 
	addressFile(address_filename),
	cache(cache) {}

CPU::~CPU() {}

void CPU::run() {
	this->addressFile.read_address();

	bool valid_address_sent;
	do {
		unsigned int address = addressFile.get_address();
		valid_address_sent = this->cache.access_memory_address(address);
		addressFile.remove_address();
	} while ((!addressFile.empty()) && (valid_address_sent));
}
