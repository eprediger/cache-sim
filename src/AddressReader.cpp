#include "AddressReader.h"

#include <string>

AddressReader::AddressReader(const std::string filename) : 
	file(filename, std::ifstream::in) {
	file.setf(std::ios::hex);
}

AddressReader::~AddressReader() {
	file.close();
}

void AddressReader::read_address() {
	std::string address_line;
	unsigned int memory_address;

	while (std::getline(this->file, address_line)) {
		memory_address = std::stoul(address_line, nullptr, 0);
		this->address.push_back(memory_address);
	}
}

bool AddressReader::empty() {
	return this->address.empty();
}

unsigned int AddressReader::get_address() const {
	return this->address.front();
}

void AddressReader::remove_address() {
	this->address.pop_front();
}
