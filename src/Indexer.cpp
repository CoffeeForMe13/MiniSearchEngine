#include "Indexer.h"
#include "utils.h"

#include <sstream>

void Indexer::addDocument(const std::string& filepath, const std::string& content)
{
    std::vector<std::string> words = tokenize(content);

    for (size_t i = 0; i < words.size(); i++)
    {
        const auto& word = words.at(i);
        index_[word].push_back(filepath);

        positionalIndex_[word][filepath].push_back(i);
    }
    
}

const Indexer::InvertedIndex& Indexer::getIndex() const
{
    return index_;
}

const Indexer::PositionalIndex& Indexer::getPositionalIndex() const
{
    return positionalIndex_;
}

std::vector<std::string> Indexer::tokenize(const std::string& text) const
{
    std::stringstream ss(text);
    std::string word;
    std::vector<std::string> result;

    while (ss >> word)
    {
        std::string norm = normalize(word);
        if (!norm.empty())
            result.push_back(norm);
    }

    return result;
}
