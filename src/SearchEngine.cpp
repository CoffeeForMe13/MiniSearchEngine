#include <sstream>

#include "SearchEngine.h"
#include "utils.h"

SearchEngine::SearchEngine(FileScanner &scanner, Indexer &indexer)
    : scanner_{scanner}, indexer_{indexer}
{
}

void SearchEngine::buildIndex()
{
    auto files = scanner_.listTextFiles();

    for (const auto& file : files)
    {
        std::string content = scanner_.readFile(file);
        indexer_.addDocument(file, content);
    }
}

std::vector<std::string> SearchEngine::search(const std::string &query) const
{
    std::stringstream ss(query);
    std::string word;
    std::vector<std::string> words;
    int wordCount {0};

    while (ss >> word)
    {
        std::string norm = normalize(word);
        if (!norm.empty())
        {
            words.push_back(norm);
            wordCount++;
        }
    }
    if(wordCount > 1)
        return searchPhrase(words);

    auto& index = indexer_.getIndex();

    std::string normalized = normalize(query);

    if (index.count(normalized) == 0)
        return {};

    return index.at(normalized);
}

SearchEngine::~SearchEngine()
{
}

std::vector<std::string> SearchEngine::searchPhrase(const std::vector<std::string> &words) const
{
    if (words.empty())
        return {};

    const auto& positionalIndex = indexer_.getPositionalIndex();

    if (!positionalIndex.count(words.at(0)))
        return {};

    std::vector<std::string> results;
    for (const auto& [filepath, _] : positionalIndex.at(words.at(0)))
        if (containsPhrase(words, filepath))
            results.push_back(filepath);
    
    return results;
}
