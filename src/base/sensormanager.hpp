#ifndef SENSERMANAGER_H
#define SENSERMANAGER_H

#include <memory>

#include "config.hpp"
#include "sensoritem.hpp"

namespace base {

using namespace std;

class SensorManager {
public:
    explicit SensorManager();

    static shared_ptr<SensorManager> instance();

    vector<Sensor> configurationSensors() const;
    void setConfiguration(const Config &config);

private:
    Config config_;

};

}

#endif //SENSERMANAGER_H
