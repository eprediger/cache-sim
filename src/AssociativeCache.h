#ifndef __ASSOCIATIVECACHE_H__
#define __ASSOCIATIVECACHE_H__

#include "ConfigFileReader.h"
#include "Cache.h"

// #include <string>
#include <deque>
#include <map>

class AssociativeCache : public Cache {
public:
	explicit AssociativeCache(ConfigFileReader& config);
	
	~AssociativeCache();

protected:
	void update_if_full();

	std::map<unsigned int, unsigned int> cache_map;
	std::deque<unsigned int> cache_queue;
};

#endif
