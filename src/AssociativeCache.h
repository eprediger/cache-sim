#ifndef __ASSOCIATIVECACHE_H__
#define __ASSOCIATIVECACHE_H__

#include "ConfigFileReader.h"
#include "Cache.h"

#include <deque>
#include <map>

class AssociativeCache : public Cache {
public:
	explicit AssociativeCache(ConfigFileReader& config);
	
	~AssociativeCache();

protected:
	void if_full_remove_last();

	std::map<unsigned int, unsigned int> cache_map;
	std::deque<unsigned int> cache_queue;
};

#endif
