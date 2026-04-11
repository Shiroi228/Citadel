#include <iostream>
#include <fstream>

#include "configurationloader.hpp"

namespace parsers {

bool ConfigurationLoader::read(const string &configuration) {
    ifstream configFile(configuration);
    if (!configFile.is_open()) {
        cerr << "Failed to open " << configuration << endl;
        return false;
    }

    json config;
    configFile >> config;

    cout << configuration << " has been opened" << endl;

    for (const auto& item : config["sensors"]) {
        Sensor sensor;
        sensor.name_ = item["name"];
        sensor.rule_ = item["rule"];
        configuration_.sensors_.push_back(sensor);
    }

    for (const auto& item : config["rules"]) {
        Rule rule;
        rule.name_ = item["name"];
        rule.type_ = item["type"];
        rule.rule_ = item["rule"];
        
        if (item.contains("true")) {
            rule.trueValue_ = item["true"];
        }
        if (item.contains("false")) {
            rule.falseValue_ = item["false"];
        }
        
        configuration_.rules_.push_back(rule);
    }

    for (const auto& item : config["extractors"]) {
        Extractor extractor;
        extractor.sensor_ = item["sensor"];
        for (const auto& rule_name : item["rules"]) {
            extractor.rules_.push_back(rule_name);
        }
        configuration_.extractors_.push_back(extractor);
    }

    if (!configuration_.sensors_.size() || !configuration_.rules_.size() || !configuration_.sensors_.size()) {
        cerr << "The configuration " << configuration << " is not fully loaded." << endl;
        
        return false;
    }

    cout << "The configuration " << configuration << " loaded" << endl;

    return true;
}

}