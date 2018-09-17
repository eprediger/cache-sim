#include "FIFOCache.h"

FIFOCache::FIFOCache(const std::map<std::string, std::string> config) : 
	Cache(config) {}

FIFOCache::~FIFOCache() {}

/* Metodo para la cache full associative, replacement policy: FIFO */
void FIFOCache::store_address(unsigned int memory_address) {
	// Trabajo con la direccion sin el offset
	unsigned int tag = get_tag(memory_address);

	// std::cout << "Address: 0x" << std::setfill('0') << std::setw(8) << std::hex << memory_address << " | ";
	// std::cout << "Tag: 0x" << std::setfill('0') << std::setw(6) << std::hex << tag << std::endl;
	
	if (this->cache_blocks.empty()) {
		this->store_miss(memory_address);
		this->cache_blocks.push_front(tag);
	} else {
		std::deque<unsigned int>::iterator it = this->cache_blocks.begin();
		bool tag_found = false;
		while ((it != this->cache_blocks.end()) && !(tag_found)) {
			if (*it == tag) {	//	cache hit
				this->store_hit(memory_address);
				tag_found = true;
			}
			it++;
		}
		if (!tag_found) {	//	cache miss
			this->store_miss(memory_address);
			this->cache_blocks.push_front(tag);
		}
	}

	if (this->cache_blocks.size() > this->total_blocks) {
		this->cache_blocks.pop_back();
	}
}
