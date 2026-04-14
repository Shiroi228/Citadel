#include <iostream>

#include "sensor.hpp"

namespace base {

Sensor::Sensor(const string &name, const string &rule) : name_(name), rule_(rule) {
    
}

void Sensor::info() {
    cout << endl << "Имя: " << rule() << endl; 

    for (auto item : data_) {
        cout << "filename: " << item.first << endl;
        cout << "\t" << item.second.state_.value() << endl;
        cout << "\t" << item.second.temp_.value() << endl;
        cout << "\t" << item.second.speed_.value() << endl;
    }

    cout << endl; 
}

string Sensor::name() const {
    return name_;
}

string Sensor::rule() const {
    return rule_;
}

void Sensor::append(const string &filename, const SensorParametersSet &set) {
    data_.insert({filename, set});
}

SensorParametersSet::SensorParametersSet(StateRule state, TempRule temp, SpeedRule speed) : state_(state), temp_(temp), speed_(speed) {
    
}

}