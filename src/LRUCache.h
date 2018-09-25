#ifndef __LRUCACHE_H__
#define __LRUCACHE_H__

#include "ConfigFileReader.h"
#include "AssociativeCache.h"

class LRUCache : public AssociativeCache {
public:
	explicit LRUCache(ConfigFileReader& config);
	
	~LRUCache();

	void store_address(unsigned int memory_address) override;
};

#endif
