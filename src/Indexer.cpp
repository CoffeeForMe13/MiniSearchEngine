#include "Indexer.h"

#include <sstream>

void Indexer::addDocument(const std::string& filepath, const std::string& content)
{
    std::vector<std::string> words = tokenize(content);

    for (const auto& word : words)
    {
        index_[word].push_back(filepath);
    }
    
}

const Indexer::InvertedIndex& Indexer::getIndex() const
{
    return index_;
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

std::string Indexer::normalize(const std::string& word) const
{
    std::string cleaned;

    for (char c : word)
    {
        if (std::isalnum(static_cast<unsigned char>(c)))
            cleaned += std::tolower(c);
    }
    
    return cleaned;
}
