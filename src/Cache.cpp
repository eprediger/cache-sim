#include "Cache.h"

#include <map>
#include <string>

Cache::Cache(ConfigFileReader& config) : 
	cache_specs(config),
	cache_size(config.get_cache_size()),
	line_size(config.get_line_size()),
	total_blocks(cache_size/line_size),
	debug(config.get_debug()),
	debug_report(),
	error_report(),
	total_hits(0),
	total_misses(0) {}

Cache::~Cache() {}

std::string Cache::get_cache_specs() {
	return this->cache_specs.get_specs();
}

bool Cache::is_valid_address(unsigned int address) {
	return (fmod(address, 4) == 0);
}

bool Cache::access_memory_addresses(unsigned int address) {
	Lock l(m);
	if (this->is_valid_address(address)) {
		this->store_address(address);
		return true;
	} else {
		this->store_error_report(address);
		return false;
	}
}

unsigned int Cache::get_tag(unsigned int address) {
	unsigned int offset_bit = log2(this->line_size);
	return address >> offset_bit;
}

void Cache::store_hit(unsigned int memory_address) {
	this->total_hits++;
	this->store_debug_report("Hit: ", memory_address);
}

void Cache::store_miss(unsigned int memory_address) {
	this->total_misses++;
	this->store_debug_report("Miss: ", memory_address);
}


void Cache::store_debug_report(std::string event, unsigned int memory_address) {
	std::stringstream stream;
	stream << "0x" << std::setfill('0') << std::setw(sizeof(memory_address)*2) 
		   << std::hex << memory_address;
	std::string address_str(stream.str());

	this->debug_report += event + address_str + std::string("\n");
}

void Cache::store_error_report(unsigned int memory_address) {
	std::string event = std::string("Direccion invalida: ");

	std::stringstream stream;
	stream << "0x" << std::setfill('0') << std::setw(sizeof(memory_address)*2) 
		   << std::hex << memory_address;
	std::string address_str(stream.str());

	this->error_report += event + address_str + std::string("\nAbortando\n");
}

std::string Cache::report_stats() {
	std::string stats = std::string("\n");

	if (this->debug) {
		stats += this->debug_report;
	}

	stats += "\n# Informe\n\n";
	
	stats += std::string("* Total de hits: ");
	stats += std::to_string(this->total_hits);
	stats += std::string("\n");
	
	stats += std::string("* Total de misses: ");
	stats += std::to_string(this->total_misses);
	stats += std::string("\n");

	return stats;
}

std::string Cache::report_error() {
	return this->error_report;
}
