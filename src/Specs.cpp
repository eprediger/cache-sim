#include "Specs.h"

Specs::Specs(const std::map<std::string, std::string> config) :
	vendor_id(config.find("vendor_id")->second),
	model_name(config.find("model name")->second),
	cpu_MHz(config.find("cpu MHz")->second) {}

Specs::~Specs() {}

std::string Specs::get_specs() {
	std::string specs = std::string("# Cache Inicializada\n\n");

	specs += std::string("* Fabricante: ") + this->vendor_id + std::string("\n");
	specs += std::string("* Modelo: ") + this->model_name + std::string("\n");
	specs += std::string("* Cpu MHz: ") + this->cpu_MHz + std::string("\n");

	return specs;
}
