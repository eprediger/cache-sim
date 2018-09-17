#include "AddressReader.h"

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
		// std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex << memory_address << std::endl;
		this->address.push_back(memory_address);
	}
}

std::deque<unsigned int> AddressReader::get_address() {
	return this->address;
}
