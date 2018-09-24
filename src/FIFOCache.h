#ifndef __FIFOCACHE_H__
#define __FIFOCACHE_H__

#include "ConfigFileReader.h"
#include "Cache.h"

#include <string>
#include <deque>
#include <map>

class FIFOCache : public Cache {
public:
	// explicit FIFOCache(const std::map<std::string, std::string> config);
	explicit FIFOCache(ConfigFileReader& config);
	
	~FIFOCache();

	void store_address(unsigned int memory_address) override;
	
private:
	std::map<unsigned int, unsigned int> cache_map;
	std::deque<unsigned int> cache_queue;
};

#endif
