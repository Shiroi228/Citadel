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

vector<Sensor> SensorManager::configurationSensors() const {
    return config_.sensors_;
}

void SensorManager::setConfiguration(const Config &config) {
    config_ = config;
}

}