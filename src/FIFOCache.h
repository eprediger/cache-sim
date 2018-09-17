#ifndef __FIFOCACHE_H__
#define __FIFOCACHE_H__

#include "Cache.h"

class FIFOCache : public Cache {
public:
	FIFOCache(const std::map<std::string, std::string> config);
	~FIFOCache();

	void store_address(unsigned int memory_address) override;
	
private:
	std::deque<unsigned int> cache_blocks;
};

#endif
