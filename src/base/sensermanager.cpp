#include "sensermanager.hpp"

namespace base {

SenserManager::SenserManager(const Config &config) : config_(config) {
    createSensers();
}

void SenserManager::createSensers() {
    for (auto sensor : config_.sensors_) {
        SenserItem item(sensor.name_, sensor.rule_);
        list_.push_back(item);
    }
}

list<SenserItem> SenserManager::sensers() const {
    return list_;
}

}