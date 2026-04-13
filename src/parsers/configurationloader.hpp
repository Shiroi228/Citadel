#ifndef CONFIGURATORLOADER_H
#define CONFIGURATORLOADER_H

#include <fstream>
#include <string>

#include "../base/config.hpp"
#include "../libs/nlohmann/json.hpp"


namespace parsers {

using json = nlohmann::json;
using namespace std;

class ConfigurationLoader {
public:
    ConfigurationLoader() = default;
    ~ConfigurationLoader() = default;

    bool read(const string &configuration = string());
    base::Config configuration() const;

private:
    base::Config configuration_;
};

}

#endif //CONFIGURATORLOADER_H
