#ifndef __FIFOCACHE_H__
#define __FIFOCACHE_H__

#include "ConfigFileReader.h"
#include "AssociativeCache.h"

class FIFOCache : public AssociativeCache {
public:
	explicit FIFOCache(ConfigFileReader& config);
	
	~FIFOCache();

	void store_address(unsigned int memory_address) override;
};

#endif
