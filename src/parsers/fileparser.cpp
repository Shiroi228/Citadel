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
    bool isSensorFound = false;
    string foundSensor;
    
    while (getline(file, line)) {
        if (!isSensorFound) {
            regex sensorRegex("Датчик\\s+(\\d+)");
            smatch match;

            if (regex_search(line, match, sensorRegex)) {
                foundSensor = "sensor" + match[1].str();

                for (const base::Sensor &item : config_.sensors_) {
                    if (!foundSensor.compare(item.name())) {
                        cout << endl << "В файле " << filename << " найден " << foundSensor << endl;
                        
                        isSensorFound = true;
                    }
                }
            }

            continue;
        }
        
        parseValue(line);
        
        if (line.empty() || line.find("Датчик") != string::npos) {
            base::SensorParametersSet set(state_, temp_, speed_);
            manager_->updateData(foundSensor, filename, set);

            isSensorFound = false;
        }
    }
}

void FilesParser::parseValue(const string &line) {
    smatch match;
    regex stateRegex("Состояние\\s*:\\s*(\\S+)");
    regex tempRegex("Температура\\s*:\\s*([\\d.]+)");
    regex speedRegex("Скорость\\s*:\\s*([\\d.]+)\\s*(\\S+)");

    if (regex_search(line, match, stateRegex)) {
        state_ = base::StateRule(match[1].str());

        cout << "Состояние: " << match[1].str() << " : " << state_.value() << endl;
    }

    if (regex_search(line, match, tempRegex)) {
        temp_ = base::TempRule(stof(match[1].str()));

        cout << "Температура: " << match[1].str() << " : " << temp_.value() << endl;
    }

    if (regex_search(line, match, speedRegex)) {
        speed_ = base::SpeedRule(stof(match[1].str()), match[2].str());

        cout << "Скорость: " << match[1].str() << " " << match[2].str() << " : " << speed_.value() << endl;
    }
}

void FilesParser::info() {
    manager_->info();
}

}