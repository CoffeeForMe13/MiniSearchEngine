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

    /*****************************
     * Test tokenize() method
     *****************************/
    /* *********** 1 *********** */
    
    
    std::cout << std::endl;

    /*****************************
     * Test addDocument() method
     *****************************/
    /* *********** 1 *********** */
    
    
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
