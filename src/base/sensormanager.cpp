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

void SensorManager::extractorInfo() {
    if (!sensors_.size() || !extractors_.size()) { return; }

    for (Sensor &item : sensors_) {
        item.maxMinInfo(extractors_);
    }
}

void SensorManager::setConfiguration(const Config &config) {
    sensors_.clear();
    extractors_.clear();

    sensors_ = config.sensors_;
    extractors_ = config.extractors_;
}

}