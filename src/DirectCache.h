#ifndef __DIRECTCACHE_H__
#define __DIRECTCACHE_H__

#include "Cache.h"

#include <deque>	// direct cache

class DirectCache : public Cache {
public:
	DirectCache(const std::map<std::string, std::string> config);
	~DirectCache();

	void store_address(unsigned int memory_address) override;

// Metodos privados
private:
	unsigned int get_tag_index(unsigned int tag);

// Atributos privados
private:
	std::deque<unsigned int> cache_blocks;
};

#endif
