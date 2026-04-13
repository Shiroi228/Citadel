#include <iostream>
#include <windows.h>

#include "parsers/configurationloader.hpp"
#include "parsers/fileparser.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    SetConsoleOutputCP(65001);
    
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <files...>" << endl;
        cerr << "Example: " << argv[0] << " *.txt" << endl;
        return 1;
    }

    parsers::ConfigurationLoader loader;
    if(!loader.read("cfg.json")) { return -1; };

    parsers::FilesParser fileParser(loader.configuration());
    for (int i = 1; i < argc; ++i) {
        fileParser.parseFile(argv[i]);
    }


    cout << "Successfully!" << endl;
    return 0;
}
