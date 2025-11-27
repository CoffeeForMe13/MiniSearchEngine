# MiniSearchEngine
Mini Search Engine for Local Text Files


I. Description
-------------------------------------

The project, so far:
- Has a predefined directory in which it indexes all the .txt files.
- Creates an unordered map that contains a word as a key and the file location as a value
- Can only look for single words
- Returns all the files that contain it, as many times as the word is contained in them
- If the word does not exist in the files, the engine returns a 'No results.' message.


II. Setup steps
-------------------------------------

As an IDE, am tried multiple options, such as Visual Studio, CodeLite and Visual Stidion Code. I chose to use VS Code becose that way the overall project remained simple and clutter-free -- no VS generated files or complicated file structure.
So, here is how I did it:
- Install [CMake](https://cmake.org/download/)
- Install [VS Code](https://code.visualstudio.com/download)
- Add the following extensions:
    - C/C++
    - CMake Tools

A tutorial to configure CMake can be found [here](https://code.visualstudio.com/docs/cpp/CMake-linux).

With this setup, you should be able to easily build and run the code. The build, debug and run buttons should appear on the bottom left of the IDE.


III. Project structure
-------------------------------------

    MiniSearchEngine/
    │
    ├── src/
    │   ├── main.cpp
    │   ├── FileScanner.cpp
    │   ├── Indexer.cpp
    │   ├── SearchEngine.cpp
    │   ├── utils.cpp
    │   ├── FileScanner.h
    │   ├── Indexer.h
    │   ├── SearchEngine.h
    │   └── utils.h
    │
    ├── test_data/
    │   └── ... (test .txt files)
    │
    ├── build/           (CMake build files)
    │
    ├── CMakeLists.txt
    │
    ├── CMakePresets.json
    │
    └── README.md
