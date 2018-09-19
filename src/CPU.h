#ifndef __CPU_H__
#define __CPU_H__

#include "Thread.h"
#include "AddressReader.h"
#include "Cache.h"

class CPU : public Thread {
public:
	CPU(const char* address_filename, Cache &cache);
	~CPU();

	virtual void run() override;

private:
	AddressReader address_file;
	Cache &cache;
};

#endif
