#include "Cache.h"

Cache::Cache(const std::map<std::string, std::string> config) : 
	cache_specs(config),
	cache_type(config.find("cache type")->second),

	cache_size(std::stoi(config.find("cache size")->second, 0, 10)),
	line_size(std::stoi(config.find("line size")->second, 0, 10)),
	total_blocks(cache_size/line_size),
	debug(false),
	debug_report(),
	error_report(),
	total_hits(0),
	total_misses(0) {

	std::string debug_value = config.find("debug")->second;
	if (debug_value.compare("true") == 0) {
		this->debug = true;
	} else {
		this->debug = false;
	}
}

Cache::~Cache() {}

std::string Cache::get_cache_specs() {
	return this->cache_specs.get_specs();
}

bool Cache::is_valid_address(unsigned int address) {
	return (fmod(address, 4) == 0);
}

void Cache::access_memory_addresses(std::deque<unsigned int> addresses) {

	bool valid_address = true;
	while (!addresses.empty() && valid_address)	{
		unsigned int address = addresses.front();
		valid_address = is_valid_address(address);
		if (valid_address) {
			this->store_address(addresses.front());
		} else {
			this->store_error_report(address);
			return;
		}
		addresses.pop_front();
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
	// std::string address_str = std::to_string(memory_address) << std::hex;

	std::stringstream stream;
	stream << "0x" << std::setfill('0') << std::setw(sizeof(memory_address)*2) << std::hex << memory_address;
	std::string address_str( stream.str() );

	this->debug_report += event + address_str + std::string("\n");
}

void Cache::store_error_report(unsigned int memory_address) {
	// std::string address_str = std::to_string(memory_address) << std::hex;
	std::string event = std::string("Direccion invalida: ");

	std::stringstream stream;
	stream << "0x" << std::setfill('0') << std::setw(sizeof(memory_address)*2) << std::hex << memory_address;
	std::string address_str( stream.str() );

	this->error_report += event + address_str + std::string("\nAbortando\n");
}

std::string Cache::report_stats() {
	std::string stats = std::string("\n");

	if (this->debug) {
		stats += this->debug_report + std::string("\n");
	}

	stats += "# Informe\n\n";
	
	stats += std::string("* Total de hits: ") + std::to_string(this->total_hits) + std::string("\n");
	stats += std::string("* Total de misses: ") + std::to_string(this->total_misses) + std::string("\n");

	return stats;
}

std::string Cache::report_error() {
	return this->error_report;
}
