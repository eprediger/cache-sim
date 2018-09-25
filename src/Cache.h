#ifndef __CACHE_H__
#define __CACHE_H__

#include "ConfigFileReader.h"
#include "Specs.h"
#include "Lock.h"

#include <string>
#include <map>

#include <cmath>	// log2, fmod

#include <iostream>
#include <sstream>
#include <iomanip>

#include <mutex>

#define ALIGN 4

class Cache {
public:
	explicit Cache(ConfigFileReader& config);
	
	virtual ~Cache();

	std::string get_cache_specs();

	bool access_memory_address(unsigned int address);

	std::string report_stats();

	std::string report_error();

// Metodos protegidos
protected:
	virtual void store_address(unsigned int address) = 0;

	bool is_valid_address(unsigned int address);

	void store_hit(unsigned int memory_address);

	void store_miss(unsigned int memory_address);

	void store_debug_report(std::string event, unsigned int memory_address);

	void store_error_report(unsigned int memory_address);

	unsigned int get_tag(unsigned int address);

	unsigned int get_total_blocks();

// Atributos protegidos
private:
	Specs cache_specs;

	const unsigned int line_size;
	const unsigned int total_blocks;
	const bool debug;
	std::string debug_report;
	std::string error_report;

	unsigned int total_hits;
	unsigned int total_misses;

	std::mutex m;
};

#endif
