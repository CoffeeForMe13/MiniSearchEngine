#include <iostream>
#include <string>

#include "Indexer.h"

int main()
{
    // std::cout << "Eeee" << std::endl;
    // return 0;
    /*****************************
     * Test Indexer class
     *****************************/

    // Create indexer object
    Indexer indexer;

    
    /*****************************
     * Test normalize() method
     *****************************/
    /* *********** 1 *********** */
    std::string word = "Terra41 The";

    std::cout << indexer.normalize(word) << std::endl;

    std::cout << std::endl;

    /*****************************
     * Test tokenize() method
     *****************************/
    /* *********** 1 *********** */
    std::string text = "carte funciara.txt";

    auto tokens = indexer.tokenize(text);

    for (auto token : tokens)
    {
        std::cout << token << std::endl;
    }

    std::cout << std::endl;

    /*****************************
     * Test addDocument() method
     *****************************/
    /* *********** 1 *********** */
    std::string filepath = "D:\\git\\TheProject\\Workspace\\ProjectName\\src\\Data\\file.txt";
    std::string content = "This is the content of a document";
    indexer.addDocument(filepath, content);

    // Iterate through the map
    for (const auto& pair : indexer.index_)
    {
        // pair.first is the key
        // pair.second is the value
        for (const auto& element : pair.second)
        {
            std::cout << "Key: " << pair.first << ", Value: " << element << std::endl;
        }
    }
    
    std::cout << std::endl;

    /*****************************
     * Test getIndex() method
     *****************************/
    /* *********** 1 *********** */
    
    
    std::cout << std::endl;

    /* End of testing*/
    std::cout << std::endl;
    return 0;
}
