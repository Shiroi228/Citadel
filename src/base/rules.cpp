#include "rules.hpp"

namespace base {

/*
 * StateRule
 *
 */

string StateRule::type() const {
    return name();
}

StateRule::StateRule(const string &state) {
    !state.compare("включен") ? state_ = true : state_ = false;
}

string StateRule::name() {
    return string("state");
}

string StateRule::toString() const {
    return state_ ? "включен" : "выключен";
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

string TempRule::name() {
    return string("temp");
}

string TempRule::type() const {
    return name();
}

string TempRule::toString() const {
    stringstream ss;
    ss << fixed << setprecision(1) << temp_;

    return ss.str();
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

SpeedRule::SpeedRule(const float &bps) : speed_(bps) {

}

float SpeedRule::convertToBitsPerSecond(float value, const string &unit) {
    if (unit == "bit/s"  || unit == "bits") return value;
    if (unit == "Kbit/s" || unit == "Kbits") return value * 1000;
    if (unit == "Mbit/s" || unit == "Mbits") return value * 1000000;
    if (unit == "Gbit/s" || unit == "Gbits") return value * 1000000000;
    return value;
}

string SpeedRule::formatSpeed(float bps) {
    stringstream ss;

    if (bps >= 1000000000) {
        ss << fixed << setprecision(1) << bps / 1000000000;
        return ss.str() + " Gbit/s";
    } else if (bps >= 1000000) {
        ss << fixed << setprecision(1) << bps / 1000000;
        return ss.str() + " Mbit/s";
    } else if (bps >= 1000) {
        ss << fixed << setprecision(1) << bps / 1000;
        return ss.str() + " Kbit/s";
    } else {
        return to_string(static_cast<int>(bps)) + " bit/s";
    }
}

string SpeedRule::type() const {
    return name();
}

string SpeedRule::toString() const {
    return formatSpeed(speed_);
}

string SpeedRule::name() {
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