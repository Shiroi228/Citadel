#ifndef SENSORITEM_H
#define SENSORITEM_H

#include <map>

#include "config.hpp"
#include "rules.hpp"

namespace base {
    
using namespace std;

struct SensorParametersSet {
    SensorParametersSet(StateRule state, TempRule temp, SpeedRule speed);

    StateRule state_;
    TempRule temp_;
    SpeedRule speed_;
};

class Sensor {
public:
    Sensor(const string &name = string(), const string &rule = string());

    string name() const;
    string rule() const;

    void append(const string &filename, const SensorParametersSet &set);
    void maxMinInfo(const vector<Extractor> &extractors);

private:
    string maxMin(const string &rule);

private:
    string name_;
    string rule_;

    multimap<string, SensorParametersSet> data_;
};

}
#endif //SENSORITEM_H
