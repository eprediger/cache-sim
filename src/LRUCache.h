#ifndef __LRUCACHE_H__
#define __LRUCACHE_H__

#include <string>
#include <deque>
#include <map>

#include "Cache.h"

class LRUCache : public Cache {
public:
	explicit LRUCache(const std::map<std::string, std::string> config);
	
	~LRUCache();

	void store_address(unsigned int memory_address) override;

private:
	std::map<unsigned int, unsigned int> cache_map;
	std::deque<unsigned int> cache_queue;
};

#endif
