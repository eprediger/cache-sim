#include "FIFOCache.h"

#include <string>
#include <deque>
#include <map>

FIFOCache::FIFOCache(ConfigFileReader& config) :
	AssociativeCache(config) {}

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

	this->update_if_full();
}
