#include "DirectCache.h"

#include <map>
#include <string>

DirectCache::DirectCache(ConfigFileReader& config) :
	Cache(config),
	cache_blocks() {}

DirectCache::~DirectCache() {}

void DirectCache::store_address(unsigned int memory_address) {
	// Trabajo con la direccion sin el offset
	unsigned int tag = get_tag(memory_address);

	// index = no_offset_addr % total_blocks
	unsigned int index = get_tag_index(tag);

	if ((this->cache_blocks.find(index) != this->cache_blocks.end())
		&& (this->cache_blocks[index] == tag) ) {
		// Cache Hit
		this->store_hit(memory_address);
	} else {
		// Cache Miss
		this->store_miss(memory_address);
		this->cache_blocks[index] = tag;
	}
}

unsigned int DirectCache::get_tag_index(unsigned int tag) {
	return fmod(tag, total_blocks);
}
