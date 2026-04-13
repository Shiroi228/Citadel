#ifndef SENSORITEM_H
#define SENSORITEM_H

#include <map>
#include <memory>
#include <string>

#include "rules.hpp"

namespace base {
    
using namespace std;

class SensorParametersSet {
public:
    SensorParametersSet(StateRule state, TempRule temp, SpeedRule speed);

private:
    StateRule state_;
    TempRule temp_;
    SpeedRule speed_;
};

class SensorModel {
public:
    void append(const string &fileName, SensorParametersSet set);

private:
    multimap<string, SensorParametersSet> data_;
};

class Sensor {
public:
    Sensor(const string &name, const string &rule);
    ~Sensor() = default;

    void setModel(shared_ptr<SensorModel> model);

    string name() const;
    string rule() const;

private:
    string name_;
    string rule_;

    shared_ptr<SensorModel> model_;
};

}
#endif //SENSORITEM_H
