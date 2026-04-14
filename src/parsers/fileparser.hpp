#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <mutex>
#include <memory>

#include "../libs/nlohmann/json.hpp"
#include "../base/sensormanager.hpp"

#include "configurationloader.hpp"

namespace parsers {

using json = nlohmann::json;
using namespace std;

class FilesParser {
public:
    explicit FilesParser(const base::Config& config);
    ~FilesParser() = default;

    void parseFile(const string &filename);
    void parseValue(const string &line);

    void info();

private:
    base::Config config_;

    base::StateRule state_;
    base::TempRule temp_;
    base::SpeedRule speed_;

    shared_ptr<base::SensorManager> manager_;
    mutex mutex_;
};

}

#endif //CONFIGURATORLOADER_H
