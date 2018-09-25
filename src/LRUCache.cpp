#include "LRUCache.h"

#include <string>
#include <deque>
#include <map>

LRUCache::LRUCache(ConfigFileReader& config) :
	AssociativeCache(config) {}

LRUCache::~LRUCache() {}

void LRUCache::update_cache(unsigned int tag) {
	std::deque<unsigned int>::iterator it = this->cache_queue.begin();
	bool tag_found = false;
	while ((it != this->cache_queue.end()) && !(tag_found)) {
		if (*it == tag) {	//	cache hit
			tag_found = true;
			unsigned int hit_address = *it;
			this->cache_queue.erase(it);
			this->cache_queue.push_front(hit_address);
		}
		it++;
	}
}

/* Metodo para la cache full associative, replacement policy: LRU */
void LRUCache::store_address(unsigned int memory_address) {
	// Trabajo con la direccion sin el offset
	unsigned int tag = get_tag(memory_address);

	if (this->cache_map.find(tag) != this->cache_map.end()) {
		// Cache Hit
		this->store_hit(memory_address);
		this->update_cache(tag);
	} else {
		// Cache Miss
		this->store_miss(memory_address);
		this->cache_map[tag] = memory_address;
		this->cache_queue.push_front(tag);
	}

	this->if_full_remove_last();
}
