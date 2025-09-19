#pragma once

#include <iostream>
#include <string>
#include <vector>

// TODO: Functional explode string function, multi-bit delimiter support
inline std::vector<std::string> explode(std::string const& str, std::string const& delimiter) {
    std::vector<std::string> result;
    std::vector<unsigned int> delimiter_pos;

    if (delimiter.size() != 1) {
        throw std::invalid_argument("Invalid Delimiter");
    }

    for (int i = 0; i <= str.size(); i++) {
        if (str[i] == delimiter[0]) {
            delimiter_pos.push_back(i);
        }
    }

    if (delimiter_pos.empty()) {
        result.push_back(str);
        return result;
    }

    result.push_back(str.substr(0, delimiter_pos[0]));
    for (auto i = 0; i < delimiter_pos.size(); i++) {
        std::string substring;
        if (delimiter_pos.size() - 1 >= i + 1) {
            substring = str.substr(delimiter_pos[i] + 1, delimiter_pos[i + 1] - delimiter_pos[i] - 1);
        } else {
            substring = str.substr(delimiter_pos[i] + 1, str.size() - delimiter_pos[i]);
        }
        result.push_back(substring);
    }

    return result;
}