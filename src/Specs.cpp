#include "Specs.h"

#include <string>
#include <map>

Specs::Specs(ConfigFileReader& config) :
	vendor_id(config.get_vendor_id()),
	model_name(config.get_model_name()),
	cpu_MHz(config.get_cpu_MHz()) {}

Specs::~Specs() {}

std::string Specs::get_specs() {
	std::string specs = std::string("# Cache Inicializada\n\n");

	specs += std::string("* Fabricante: ") + this->vendor_id + std::string("\n");
	specs += std::string("* Modelo: ") + this->model_name + std::string("\n");
	specs += std::string("* Cpu MHz: ") + this->cpu_MHz + std::string("\n");

	return specs;
}
