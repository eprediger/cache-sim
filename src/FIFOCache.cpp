#include "FIFOCache.h"

#include <string>
#include <deque>
#include <map>

FIFOCache::FIFOCache(const std::map<std::string, std::string> config) : 
	Cache(config),
	cache_map(),
	cache_queue() {}

FIFOCache::~FIFOCache() {}

/* Metodo para la cache full associative, replacement policy: FIFO */
void FIFOCache::store_address(unsigned int memory_address) {
	// Trabajo con la direccion sin el offset
	unsigned int tag = get_tag(memory_address);

	if ((this->cache_map.find(tag) != this->cache_map.end())) {
		// Cache Hit
		this->store_hit(memory_address);
	} else {
		// Cache Miss
		this->store_miss(memory_address);
		this->cache_map[tag] = memory_address;
		this->cache_queue.push_front(tag);
	}

	if (this->cache_queue.size() > this->total_blocks) {
		unsigned int tag_to_remove = this->cache_queue.back();
		this->cache_queue.pop_back();
		
		std::map<unsigned int, unsigned int>::iterator it; 
		it = this->cache_map.find(tag_to_remove);
		this->cache_map.erase(it);
	}
}
