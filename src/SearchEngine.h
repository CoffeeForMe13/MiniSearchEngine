#pragma once

#include <string>
#include <vector>

#include "FileScanner.h"
#include "Indexer.h"

class SearchEngine 
{
public:
    SearchEngine(FileScanner& scanner, Indexer& indexer);

    void buildIndex();
    std::vector<std::string> search(const std::string& query) const;

    ~SearchEngine();

private:
    FileScanner& scanner_;
    Indexer& indexer_;

};
