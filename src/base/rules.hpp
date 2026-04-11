#ifndef RULES_H
#define RULES_H

#include <string>

using namespace std;

class Rule {
public:
    Rule() = default;
    ~Rule() = default;

    virtual string name() const = 0;
    virtual string toString() const = 0;

    virtual bool operator<(const Rule& other) const = 0;
    virtual bool operator>(const Rule& other) const = 0;
};

class StateRule : public Rule {
public:
    StateRule(bool state, const string &tStr, const string &fStr);
    ~StateRule() = default;
    
    string name() const override;
    string toString() const override;

    bool value();

    bool operator<(const Rule& other) const override;
    bool operator>(const Rule& other) const override;

private:
    bool state_;
    string trueStr_;
    string falseStr_;
};

class TempRule : public Rule {
public:
    TempRule(const double &temp);

    string name() const override;
    string toString() const override;

    bool operator<(const Rule& other) const override;
    bool operator>(const Rule& other) const override;

private:
    double temp_;
};

class SpeedRule : public Rule {
public:
    SpeedRule(const double &speed);

    string toString() const override;
    string name() const override;

    bool operator<(const Rule& other) const override;
    bool operator>(const Rule& other) const override;

private:
    double speed_;
};



#endif //RULES_H
