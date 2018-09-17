#ifndef __CACHE_H__
#define __CACHE_H__

// #include "AddressMemory.h"
#include "Specs.h"

// #include "DirectCache.h"
// #include "FIFOCache.h"
// #include "LRUCache.h"

#include <string>
#include <map>
#include <deque>
#include <map>

#include <cmath>	// log2, fmod

#include <iostream>
#include <sstream>
#include <iomanip>

class Cache {
public:
	Cache(const std::map<std::string, std::string> config);
	virtual ~Cache();

	Cache* crearCache(std::map<std::string, std::string> config);

	std::string get_cache_specs();

	bool is_valid_address(unsigned int address);

	void access_memory_addresses(std::deque<unsigned int> address);

	std::string report_stats();

	std::string report_error();

// Metodos protegidos
protected:
	void store_hit(unsigned int memory_address);

	void store_miss(unsigned int memory_address);

	void store_debug_report(std::string event, unsigned int memory_address);

	void store_error_report(unsigned int memory_address);

	virtual void store_address(unsigned int address) = 0;

	unsigned int get_tag(unsigned int address);

// Atributos protegidos
protected:
	Specs cache_specs;
	
	/* runtime creation */
	std::string cache_type;

	const unsigned int cache_size;
	const unsigned int line_size;
	const unsigned int total_blocks;
	bool debug;
	std::string debug_report;
	std::string error_report;

	unsigned int total_hits;
	unsigned int total_misses;
};

#endif
