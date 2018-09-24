#include "Specs.h"

#include <string>
#include <map>

/*Specs::Specs(const std::map<std::string, std::string> config) :
	vendor_id(config.find("vendor_id")->second),
	model_name(config.find("model name")->second),
	cpu_MHz(config.find("cpu MHz")->second) {}*/

Specs::Specs(ConfigFileReader& config) :
	vendor_id(config.get_vendor_id()),
	model_name(config.get_model_name()),
	cpu_MHz(config.get_cpu_MHz()) {}

Specs::~Specs() {}

void Specs::print_specs() {
	std::string specs = std::string("# Cache Inicializada\n\n");

	specs += std::string("* Fabricante: ") + this->vendor_id + std::string("\n");
	specs += std::string("* Modelo: ") + this->model_name + std::string("\n");
	specs += std::string("* Cpu MHz: ") + this->cpu_MHz + std::string("\n");

	std::cout << specs;
}
