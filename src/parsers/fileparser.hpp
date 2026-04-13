#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <mutex>
#include <memory>

#include "../libs/nlohmann/json.hpp"
#include "../base/sensermanager.hpp"

#include "configurationloader.hpp"

namespace parsers {

using json = nlohmann::json;
using namespace std;

class FilesParser {
public:
    explicit FilesParser(const base::Config& config);
    ~FilesParser() = default;

    void parseFile(const string &filename);

private:
    const base::Config& config_;
    shared_ptr<base::SenserManager> manager_;
    mutex mutex_;
};

}

#endif //CONFIGURATORLOADER_H
