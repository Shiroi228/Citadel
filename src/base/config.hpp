#ifndef CONFIG_H
#define CONFIG_H

#include <regex>
#include <string>
#include <vector>

namespace base {

using namespace std;

class Sensor;

struct Rule {
    Rule(const string& name, const string& type, const string& rule)
        : name_(name), type_(type), rule_(rule) {}
    Rule() = default;

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

}

#endif //CONFIG_H
