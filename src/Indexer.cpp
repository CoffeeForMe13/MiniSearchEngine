#include "Indexer.h"

void Indexer::addDocument(const std::string& filepath, const std::string& content)
{
    std::vector<std::string> words = tokenize(content);

    for (const auto& word : words)
    {
        index_[word].push_back(filepath);
    }
    
}
