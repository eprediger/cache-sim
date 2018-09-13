#ifndef __DIRECTCACHE_H__
#define __DIRECTCACHE_H__

#include "Cache.h"

class DirectCache : public Cache {
public:
	DirectCache(const std::map<std::string, std::string> config);
	~DirectCache();

private:

};

#endif
