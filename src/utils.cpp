#include <iostream>

#include "utils.h"

std::string normalize(const std::string& word)
{
    std::string cleaned;

    for (unsigned char c : word) {
        if (std::isalnum(c))
            cleaned += std::tolower(c);
    }

    return cleaned;
}
