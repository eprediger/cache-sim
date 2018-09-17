#include "DirectCache.h"

DirectCache::DirectCache(const std::map<std::string, std::string> config) : 
	Cache(config),
	cache_blocks(this->total_blocks, 0) {}

DirectCache::~DirectCache() {}

void DirectCache::store_address(unsigned int memory_address) {
	// Trabajo con la direccion sin el offset
	unsigned int tag = get_tag(memory_address);

	// index = no_offset_addr % total_blocks
	unsigned int index = get_tag_index(tag);

	// unsigned int offset = fmod(memory_address, this->line_size);
	// std::cout << "Address: 0x" << std::setfill('0') << std::setw(8) << std::hex << memory_address << " | ";
	// std::cout << "Tag: 0x" << std::setfill('0') << std::setw(6) << std::hex << tag << " | ";
	// std::cout << "Index: 0x" << std::setfill('0') << std::setw(1) << std::hex << index << " | ";
	// std::cout << "Offset: 0x" << std::setfill('0') << std::setw(2) << std::hex << offset << std::endl;
	unsigned int memory_in_index = this->cache_blocks.at(index);

	if (get_tag(memory_in_index) == tag) {
		this->store_hit(memory_address);
		
	} else {
		this->store_miss(memory_address);
		this->cache_blocks.at(index) = memory_address;
	}
}

unsigned int DirectCache::get_tag_index(unsigned int tag) {
	return fmod(tag, total_blocks);
}
