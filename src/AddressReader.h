#ifndef __ADDRESSREADER_H__
#define __ADDRESSREADER_H__

#include <fstream>
#include <string>
#include <deque>
#include <iomanip>
#include <iostream>

class AddressReader {
public:
	AddressReader(const std::string filename);

	~AddressReader();

	void read_address();

	std::deque<unsigned int> get_address();

private:
	std::ifstream file;
	std::deque<unsigned int> address;
};
#endif
