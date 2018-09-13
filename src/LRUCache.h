#ifndef __LRUCACHE_H__
#define __LRUCACHE_H__

#include "Cache.h"

class LRUCache : public Cache {
public:
	LRUCache(const std::map<std::string, std::string> config);
	~LRUCache();
	
};

#endif
