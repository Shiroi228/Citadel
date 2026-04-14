#ifndef RULES_H
#define RULES_H

#include <string>

namespace base {

using namespace std;

class BaseRule {
public:
    BaseRule() = default;
    ~BaseRule() = default;

    virtual string type() const = 0;
    virtual string toString() const = 0;

    virtual bool operator<(const BaseRule& other) const = 0;
    virtual bool operator>(const BaseRule& other) const = 0;
};

class StateRule : public BaseRule {
public:
    StateRule(const string &state);
    StateRule() = default;
    
    ~StateRule() = default;
    
    static string name();
    string type() const override;
    string toString() const override;

    bool value();

    bool operator<(const BaseRule& other) const override;
    bool operator>(const BaseRule& other) const override;

private:
    bool state_;
};

class TempRule : public BaseRule {
public:
    explicit TempRule(const float &temp);
    TempRule() = default;

    static string name();
    string type() const override;
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
    explicit SpeedRule(const float &bps);
    SpeedRule() = default;

    static string name();
    string type() const override;
    string toString() const override;

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
