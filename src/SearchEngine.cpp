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

SearchEngine::~SearchEngine()
{
}
