#include "FileScanner.h"

#include <filesystem>
#include <iostream>

FileScanner::FileScanner(const std::string& directory)
    : directory_ {directory}
{
    if (!std::filesystem::exists(directory_))
    {
        throw std::runtime_error("Directory does not exist: " + directory_);
    }
}

FileScanner::~FileScanner()
{
}
