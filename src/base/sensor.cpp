#include <iostream>

#include "sensor.hpp"

namespace base {

Sensor::Sensor(const string &name, const string &rule) : name_(name), rule_(rule) {
    
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

void Sensor::maxMinInfo(const vector<Extractor> &extractors) {
    cout << endl << name_ << ":" << endl;
    for (const Extractor &extractor : extractors) {
        if (name_.compare(extractor.sensor_)) { continue; }

        for (const string &rule : extractor.rules_) {
            cout << "\t" << maxMin(rule) << endl;
        }
    }
}

string Sensor::maxMin(const string &rule) {
    string minFilename, maxFilename;
    shared_ptr<BaseRule> minValue, maxValue;

    shared_ptr<StateRule> minState, maxState;
    shared_ptr<TempRule> minTemp, maxTemp;
    shared_ptr<SpeedRule> minSpeed, maxSpeed;

    for (pair<const string, SensorParametersSet> &p : data_) {
        if (!rule.compare(StateRule::name())) {
            if (!minState && !maxState) {
                minState = make_shared<StateRule>(p.second.state_);
                maxState = make_shared<StateRule>(p.second.state_);

                minFilename = p.first;
                maxFilename = p.first;

                continue;
            }
            
            if (p.second.state_ < *minState) {
                *minState = p.second.state_;
                minFilename = p.first;
            }

            if (p.second.state_ > *maxState) {
                *maxState = p.second.state_;
                maxFilename = p.first;
            }

            minValue = minState;
            maxValue = maxState;

        } else if (!rule.compare(TempRule::name())) {
            if (!minTemp && !maxTemp) {
                minTemp = make_shared<TempRule>(p.second.temp_);
                maxTemp = make_shared<TempRule>(p.second.temp_);

                minFilename = p.first;
                maxFilename = p.first;

                continue;
            }
            
            if (p.second.temp_ < *minTemp) {
                *minTemp = p.second.temp_;
                minFilename = p.first;
            }

            if (p.second.temp_ > *maxTemp) {
                *maxTemp = p.second.temp_;
                maxFilename = p.first;
            }

            minValue = minTemp;
            maxValue = maxTemp;

        } else if (!rule.compare(SpeedRule::name())) {
            if (!minSpeed && !maxSpeed) {
                minSpeed = make_shared<SpeedRule>(p.second.speed_);
                maxSpeed = make_shared<SpeedRule>(p.second.speed_);

                minFilename = p.first;
                maxFilename = p.first;

                continue;
            }

            if (p.second.speed_ < *minSpeed) {
                *minSpeed = p.second.speed_;
                minFilename = p.first;
            }

            if (p.second.speed_ > *maxSpeed) {
                *maxSpeed = p.second.speed_;
                maxFilename = p.first;
            }

            minValue = minSpeed;
            maxValue = maxSpeed;
        }
    }

    return string(rule + ": max = " + maxValue->toString() + " (" + maxFilename + "), min = " + minValue->toString() + " (" + minFilename + ")");
}

SensorParametersSet::SensorParametersSet(StateRule state, TempRule temp, SpeedRule speed) : state_(state), temp_(temp), speed_(speed) {
    
}

}