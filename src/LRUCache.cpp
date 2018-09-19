#include "LRUCache.h"

#include <string>
#include <deque>
#include <map>

LRUCache::LRUCache(const std::map<std::string, std::string> config) : 
	Cache(config),
	cache_map(),
	cache_queue() {}

LRUCache::~LRUCache() {}

/* Metodo para la cache full associative, replacement policy: LRU */
void LRUCache::store_address(unsigned int memory_address) {
	// Trabajo con la direccion sin el offset
	unsigned int tag = get_tag(memory_address);

	if (this->cache_map.find(tag) != this->cache_map.end()) {
		// Cache Hit
		this->store_hit(memory_address);
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
