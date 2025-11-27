#include "FileScanner.h"

#include <filesystem>
#include <iostream>
#include <fstream>

FileScanner::FileScanner(const std::string& directory)
    : directory_ {directory}
{
    if (!std::filesystem::exists(directory_))
    {
        throw std::runtime_error("Directory does not exist: " + directory_);
    }
}

std::vector<std::string> FileScanner::listTextFiles() const
{
    std::vector<std::string> files;

    for (const auto& f : std::filesystem::directory_iterator(directory_))
    {
        if (f.is_regular_file() && f.path().extension() == ".txt")
        {
            files.push_back(f.path().string());
        }
    }

    return files;
}

std::string FileScanner::readFile(const std::string& filepath) const
{
    std::ifstream file(filepath);

    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file: " + filepath);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}

FileScanner::~FileScanner()
{
}
