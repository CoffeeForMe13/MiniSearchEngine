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

    std::vector<std::string> searchPhrase(const std::vector<std::string>& words) const;
    std::vector<int> returnPhrase(
        const std::vector<std::string>& phraseWords,
        const std::string& filepath
    ) const;
    

};
