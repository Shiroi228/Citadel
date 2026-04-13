#include "rules.hpp"

namespace base {

/*
 * StateRule
 *
 */

StateRule::StateRule(bool state, const string &tStr, const string &fStr) : state_(state), trueStr_(tStr), falseStr_(fStr) {

}

string StateRule::name() const {
    return string("state");
}

string StateRule::toString() const {
    return state_ ? trueStr_ : falseStr_;
}

bool StateRule::value() {
    return state_;
}

bool StateRule::operator<(const BaseRule &other) const {
    const auto* otherBool = dynamic_cast<const StateRule*>(&other);
    if (otherBool) {
        return state_ < otherBool->state_;
    }
    
    return false;
}

bool StateRule::operator>(const BaseRule &other) const {
    const auto* otherBool = dynamic_cast<const StateRule*>(&other);
    if (otherBool) {
        return state_ > otherBool->state_;
    }
    
    return false;
}

/*
 * TempRule
 *
 */

TempRule::TempRule(const float &temp) : temp_(temp) {

}

float TempRule::value() const {
    return temp_;
}

string TempRule::name() const {
    return string("temp");
}

string TempRule::toString() const {
    return to_string(temp_);
}

bool TempRule::operator<(const BaseRule &other) const {
    const auto* otherBool = dynamic_cast<const TempRule*>(&other);
    if (otherBool) {
        return temp_ < otherBool->temp_;
    }
    
    return false;
}

bool TempRule::operator>(const BaseRule &other) const {
    const auto* otherBool = dynamic_cast<const TempRule*>(&other);
    if (otherBool) {
        return temp_ > otherBool->temp_;
    }
    
    return false;
}

/*
 * SpeedRule
 *
 */

SpeedRule::SpeedRule(const float &speed, const string &unit) : speed_(convertToBitsPerSecond(speed, unit)) {

}

SpeedRule::SpeedRule(float bps) : speed_(bps) {

}

float SpeedRule::value() const {
    return speed_;
}

float SpeedRule::convertToBitsPerSecond(float value, const string &unit) {
    if (unit == "bit" || unit == "bits") return value;
    if (unit == "Kbit") return value * 1000;
    if (unit == "Mbit") return value * 1000000;
    if (unit == "Gbit") return value * 1000000000;
    return value;
}

string SpeedRule::formatSpeed(float bps) {
    if (bps >= 1000000000) {
        return to_string(bps / 1000000000) + " Gbit/s";
    } else if (bps >= 1000000) {
        return to_string(bps / 1000000) + " Mbit/s";
    } else if (bps >= 1000) {
        return to_string(bps / 1000) + " Kbit/s";
    } else {
        return to_string(static_cast<int>(bps)) + " bit/s";
    }
}

string SpeedRule::toString() const {
    return formatSpeed(speed_);
}

string SpeedRule::name() const {
    return string("speed");
}

bool SpeedRule::operator<(const BaseRule &other) const {
    const auto* otherBool = dynamic_cast<const SpeedRule*>(&other);
    if (otherBool) {
        return speed_ < otherBool->speed_;
    }

    return false;
}

bool SpeedRule::operator>(const BaseRule &other) const {
    const auto* otherBool = dynamic_cast<const SpeedRule*>(&other);
    if (otherBool) {
        return speed_ > otherBool->speed_;
    }

    return false;
}

}