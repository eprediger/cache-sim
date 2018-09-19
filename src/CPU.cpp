#include "CPU.h"

CPU::CPU(const char* address_filename, Cache& cache) : 
	address_file(address_filename),
	cache(cache) {}

CPU::~CPU() {}

void CPU::run() {
	this->address_file.read_address();

	bool valid_address_sent;
	do {
		unsigned int address = address_file.get_address();
		valid_address_sent = this->cache.access_memory_addresses(address);
		address_file.remove_address();
	} while ((!address_file.empty()) && (valid_address_sent));
}
