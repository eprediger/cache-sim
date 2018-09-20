#ifndef __ADDRESSREADER_H__
#define __ADDRESSREADER_H__

#include <fstream>
#include <string>
#include <deque>

class AddressReader {
public:
	explicit AddressReader(const std::string filename);

	~AddressReader();

	void read_address();

	bool empty();

	unsigned int get_address() const;

	void remove_address();

private:
	std::ifstream file;
	std::deque<unsigned int> address;
};

#endif
