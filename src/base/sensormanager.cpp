#include "sensormanager.hpp"

namespace base {

static shared_ptr<SensorManager> manager_ = {};

SensorManager::SensorManager() {

}

shared_ptr<SensorManager> SensorManager::instance() {
    if (manager_) { return manager_; }

    manager_ = shared_ptr<SensorManager>(new SensorManager);
    return manager_;
}

void SensorManager::updateData(const string &sensorName, const string &filename, const SensorParametersSet &set) {
    for (Sensor &sensor : sensors_) {
        if (sensor.name().compare(sensorName) == 0) {
            sensor.append(filename, set);
        }
    }
}

void SensorManager::info() {
    for (Sensor item : sensors_) {
        item.info();
    }
}

void SensorManager::setConfiguration(const Config &config) {
    sensors_.clear();

    for (Sensor item : config.sensors_) {
        sensors_.push_back(item);
    }
}

}