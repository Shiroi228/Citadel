#include <fstream>
#include <iostream>

#include "fileparser.hpp"

namespace parsers {

FilesParser::FilesParser(const base::Config &config)
    : config_(config), manager_(shared_ptr<base::SenserManager>(new base::SenserManager(config))) {

}

void FilesParser::parseFile(const string &filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        lock_guard<mutex> lock(mutex_);
        cerr << "Cannot open file: " << filename << endl;
        return;
    }

    string line;
    bool sensorFound = false;

    while (getline(file, line)) {
        if (!sensorFound) {
            regex sensorRegex("Датчик\\s+(\\d+)");
            smatch match;
            if (regex_search(line, match, sensorRegex)) {
                string foundSensor = "sensor" + match[1].str();
                cout << "filename: " << filename << endl;
                cout << "sensor name: " << foundSensor << endl;
            }
            continue;
        }
    }
}

}