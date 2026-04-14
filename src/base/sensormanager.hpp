#ifndef SENSERMANAGER_H
#define SENSERMANAGER_H

#include <memory>
#include <list>

#include "config.hpp"
#include "sensor.hpp"

namespace base {

using namespace std;

class SensorManager {
public:
    SensorManager();

    static shared_ptr<SensorManager> instance();

    void updateData(const string &sensorName, const string &filename, const SensorParametersSet &set);
    void info();

    void setConfiguration(const Config &config);

private:
    list<Sensor> sensors_;

};

}

#endif //SENSERMANAGER_H
