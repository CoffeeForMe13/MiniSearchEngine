#include <algorithm>
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

std::vector<int> SearchEngine::returnPhrase(
    const std::vector<std::string> &phraseWords, 
    const std::string& filepath) const
{
    const auto& positionalIndex = indexer_.getPositionalIndex();

    std::unordered_map<std::string, std::vector<int>> positions;
    std::vector<int> allMatches;

    for (const auto& word : phraseWords)
    {
        if (!positionalIndex.count(word))
            return {};
        if (!positionalIndex.at(word).count(filepath))
            return {};

        positions[word] = positionalIndex.at(word).at(filepath);
    }

    const std::vector<int>& firstWordPositions = positions.at(phraseWords.at(0));

    for (int startPos : firstWordPositions)
    {
        bool match = true;

        for (int i = 1; i < phraseWords.size(); i++)
        {
            const auto& posList = positions.at(phraseWords.at(i));

            if (!std::binary_search(posList.begin(), posList.end(), startPos + i))
            {
                match = false;
                break;
            }
        }

        if (match) 
            allMatches.push_back(startPos);
    }

    return allMatches;
}
