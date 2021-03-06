#ifndef __DIRECTCACHE_H__
#define __DIRECTCACHE_H__

#include "ConfigFileReader.h"
#include "Cache.h"

#include <map>
#include <string>

class DirectCache : public Cache {
public:
	explicit DirectCache(ConfigFileReader& config);

	~DirectCache();

private:
	void store_address(unsigned int memory_address) override;

	unsigned int get_tag_index(unsigned int tag);

private:
	// <index, tag>
	std::map<unsigned int, unsigned int> cache_blocks;
};

#endif
