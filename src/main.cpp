#include <iostream>
#include <string>

#include "FileScanner.h"

int main()
{
    // std::cout << "Eeee" << std::endl;
    // return 0;
    /*****************************
     * Test FileScanner class
     *****************************/

    // Create scanner object
    FileScanner scanner{"..\\src\\Data"};

    
    /*****************************
     * Test listTextFiles() method
     *****************************/
    /* *********** 1 *********** */
    // get files
    auto files = scanner.listTextFiles();

    // Check if all the files are in the list
    for (const auto& file : files) {
        std::cout << file << std::endl;
    }
    std::cout << std::endl;

    /*****************************
     * Test readFile() method
     *****************************/
    /* *********** 1 *********** */
    // Check the content of each file
    for (const auto& file : files) {
        std::string content = scanner.readFile(file);
        std::cout << file << ": "<< content << std::endl;
    }
    std::cout << std::endl;

    /* End of testing*/
    std::cout << std::endl;
    return 0;
}
