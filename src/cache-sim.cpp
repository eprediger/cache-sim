//
// Created by emiliano on 12/09/18.
//

#include <string>
#include <fstream>
#include <iostream>
#include <map>

int main(int argc, const char *argv[]) {

	std::string filename(argv[1]);
    std::ifstream config_file(filename, std::ifstream::in);

    char enter_delim = '=';
    char newline_delim = '\n';
    std::string key, value;
    std::map<std::string, std::string> my_map;

    while (std::getline(config_file, key, enter_delim)) {
        std::getline(config_file, value, newline_delim);
        my_map[key] = value;
    }

    config_file.close();

    return EXIT_SUCCESS;
}