#include "rules.hpp"

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

bool StateRule::operator<(const Rule &other) const {
    const auto* otherBool = dynamic_cast<const StateRule*>(&other);
    if (otherBool) {
        return state_ < otherBool->state_;
    }
    
    return false;
}

bool StateRule::operator>(const Rule &other) const {
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

TempRule::TempRule(const double &temp) : temp_(temp) {

}

string TempRule::name() const {
    return string("temp");
}

string TempRule::toString() const {
    return to_string(temp_);
}

bool TempRule::operator<(const Rule &other) const {
    const auto* otherBool = dynamic_cast<const TempRule*>(&other);
    if (otherBool) {
        return temp_ < otherBool->temp_;
    }
    
    return false;
}

bool TempRule::operator>(const Rule &other) const {
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

SpeedRule::SpeedRule(const double &speed) : speed_(speed) {

}

string SpeedRule::toString() const {
    return to_string(speed_);
}

string SpeedRule::name() const {
    return string("speed");
}

bool SpeedRule::operator<(const Rule &other) const {
    const auto* otherBool = dynamic_cast<const SpeedRule*>(&other);
    if (otherBool) {
        return speed_ < otherBool->speed_;
    }
    
    return false;
}

bool SpeedRule::operator>(const Rule &other) const {
    const auto* otherBool = dynamic_cast<const SpeedRule*>(&other);
    if (otherBool) {
        return speed_ > otherBool->speed_;
    }
    
    return false;
}
