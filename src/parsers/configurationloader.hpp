#ifndef CONFIGURATORLOADER_H
#define CONFIGURATORLOADER_H

#include <fstream>
#include <vector>
#include <string>
#include <regex>

#include "../libs/nlohmann/json.hpp"

namespace parsers {

using json = nlohmann::json;
using namespace std;

struct Sensor {
    string name_;
    string rule_;
};

struct Rule {
    string name_;
    string type_;
    string rule_;
    string trueValue_;
    string falseValue_;
};

struct Extractor {
    string sensor_;
    vector<string> rules_;
};

struct Config {
    vector<Sensor> sensors_;
    vector<Rule> rules_;
    vector<Extractor> extractors_;
};

class ConfigurationLoader {
public:
    ConfigurationLoader() = default;
    ~ConfigurationLoader() = default;

    bool read(const string &configuration = string());

private:
    Config configuration_;
};

}

#endif //CONFIGURATORLOADER_H
