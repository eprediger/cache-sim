#ifndef __LRUCACHE_H__
#define __LRUCACHE_H__

#include "ConfigFileReader.h"
#include "Cache.h"

#include <string>
#include <deque>
#include <map>

class LRUCache : public Cache {
public:
	explicit LRUCache(ConfigFileReader& config);
	
	~LRUCache();

	void store_address(unsigned int memory_address) override;

private:
	std::map<unsigned int, unsigned int> cache_map;
	std::deque<unsigned int> cache_queue;
};

#endif
