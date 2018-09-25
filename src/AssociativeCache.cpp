#include "AssociativeCache.h"

#include <map>

AssociativeCache::AssociativeCache(ConfigFileReader& config) : 
	Cache(config) {}

AssociativeCache::~AssociativeCache() {}

void AssociativeCache::if_full_remove_last() {
	if (this->cache_queue.size() > this->get_total_blocks()) {
		unsigned int tag_to_remove = this->cache_queue.back();
		this->cache_queue.pop_back();
		
		std::map<unsigned int, unsigned int>::iterator it;
		it = this->cache_map.find(tag_to_remove);
		this->cache_map.erase(it);
	}
}
