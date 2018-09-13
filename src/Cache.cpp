#include "Cache.h"

Cache::Cache(const std::map<std::string, std::string> config) : 
	vendor_id(config.find("vendor_id")->second),
	model_name(config.find("model name")->second),
	cpu_MHz(config.find("cpu MHz")->second),
	cache_type(config.find("cache type")->second),

	cache_size(std::stoi(config.find("cache size")->second, 0, 10)),
	line_size(std::stoi(config.find("line size")->second, 0, 10)),
	
	debug(false) {

	std::string debug_value = config.find("debug")->second;
	if (debug_value.compare("true") == 0) {
		this->debug = true;
	} else {
		this->debug = false;
	}
}

Cache::~Cache() {}

std::string Cache::get_specs() {
	std::string specs = std::string("# Cache Inicializada\n\n");

	specs += std::string("* Fabricante: ") + this->vendor_id + std::string("\n");
	specs += std::string("* Modelo: ") + this->model_name + std::string("\n");
	specs += std::string("* Cpu MHz: ") + this->cpu_MHz + std::string("\n");

	return specs;
}
