#ifndef FILEPARSER_H
#define FILEPARSER_H

#include "../base/sensormanager.hpp"
#include "../libs/nlohmann/json.hpp"

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

private:
    base::Config config_;

    base::StateRule state_;
    base::TempRule temp_;
    base::SpeedRule speed_;

    shared_ptr<base::SensorManager> manager_;
};

}

#endif //CONFIGURATORLOADER_H
