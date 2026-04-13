#include <fstream>
#include <iostream>

#include "fileparser.hpp"

namespace parsers {

FilesParser::FilesParser(const base::Config &config)
    : config_(config), manager_(base::SensorManager::instance()) {
    manager_->setConfiguration(config);
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
    vector<base::Sensor> sensorList = manager_->configurationSensors();

    while (getline(file, line)) {
        if (!sensorFound) {
            regex sensorRegex("Датчик\\s+(\\d+)");
            smatch match;

            if (regex_search(line, match, sensorRegex)) {
                string foundSensor = "sensor" + match[1].str();

                for (auto item : sensorList) {
                    if (foundSensor.compare(item.name()) != 0) {
                        cout << "В файле " << filename << " найден " << foundSensor << endl; 
                        
                        sensorFound = true;
                    }
                }
            }

            continue;
        }
    }
}

}