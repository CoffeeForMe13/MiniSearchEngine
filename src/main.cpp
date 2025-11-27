#include <iostream>
#include <string>

#include "FileScanner.h"
#include "Indexer.h"
#include "SearchEngine.h"

int main()
{
    try
    {
        FileScanner scanner("..\\test_data");
        Indexer indexer;
        SearchEngine engine(scanner, indexer);

        std::cout << "Building indexer..." << std::endl;
        engine.buildIndex();
        std::cout << "Index built!" << std::endl;

        while (true)
        {
            std::cout << "\nSearch> ";
            std::string query;
            std::getline(std::cin, query);

            if (query == "quit")
                break;

            auto results = engine.search(query);

            if (results.empty())
            {
                std::cout << "No results." << std::endl;
            }
            else
            {
                std::cout << "Found in:" << std::endl;
                for (const auto& file : results)
                    std::cout << "  - " << file << std::endl;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    
    return 0;
}
