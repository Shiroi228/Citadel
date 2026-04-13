#include "sensoritem.hpp"

namespace base {

Sensor::Sensor(const string &name, const string &rule) : name_(name), rule_(rule) {
    
}

void Sensor::setModel(shared_ptr<SensorModel> model) {
    model_ = model;
}

string Sensor::name() const {
    return name_;
}

string Sensor::rule() const {
    return rule_;
}

SensorParametersSet::SensorParametersSet(StateRule state, TempRule temp, SpeedRule speed) : state_(state), temp_(temp), speed_(speed) {
    
}

void SensorModel::append(const string &fileName, SensorParametersSet set) {
    data_.insert({fileName, set}); 
}
    
}