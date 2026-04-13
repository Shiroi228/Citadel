#ifndef RULES_H
#define RULES_H

#include <string>

namespace base {

using namespace std;

class BaseRule {
public:
    BaseRule() = default;
    ~BaseRule() = default;

    virtual string name() const = 0;
    virtual string toString() const = 0;

    virtual bool operator<(const BaseRule& other) const = 0;
    virtual bool operator>(const BaseRule& other) const = 0;
};

class StateRule : public BaseRule {
public:
    StateRule(bool state, const string &tStr, const string &fStr);
    ~StateRule() = default;
    
    string name() const override;
    string toString() const override;

    bool value();

    bool operator<(const BaseRule& other) const override;
    bool operator>(const BaseRule& other) const override;

private:
    bool state_;
    string trueStr_;
    string falseStr_;
};

class TempRule : public BaseRule {
public:
    explicit TempRule(const float &temp);

    string name() const override;
    string toString() const override;

    float value() const;

    bool operator<(const BaseRule& other) const override;
    bool operator>(const BaseRule& other) const override;

private:
    float temp_;
};

class SpeedRule : public BaseRule {
public:
    SpeedRule(const float &speed, const string &unit);
    explicit SpeedRule(float bps);

    string toString() const override;
    string name() const override;

    float value() const;

    bool operator<(const BaseRule& other) const override;
    bool operator>(const BaseRule& other) const override;

private:
    static float convertToBitsPerSecond(float value, const string& unit);
    static string formatSpeed(float bps);

private:
    float speed_;
};

}

#endif //RULES_H
