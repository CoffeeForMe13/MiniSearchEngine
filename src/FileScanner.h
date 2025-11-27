#pragma once

#include <string>
#include <vector>

class FileScanner
{
public:
    explicit FileScanner(const std::string& directory);

    std::vector<std::string> listTextFiles() const;
    std::string readFile(const std::string& filepath) const;

    ~FileScanner();

private:
    std::string directory_;
};
