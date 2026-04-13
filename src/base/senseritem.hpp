#ifndef SENSERITEM_H
#define SENSERITEM_H

#include <map>
#include <memory>
#include <string>

#include "rules.hpp"

namespace base {
    
using namespace std;

class SenserParametersSet {
public:
    SenserParametersSet(StateRule state, TempRule temp, SpeedRule speed);

private:
    StateRule state_;
    TempRule temp_;
    SpeedRule speed_;
};

class SenserModel {
public:
    void append(const string &fileName, SenserParametersSet set);

private:
    multimap<string, SenserParametersSet> data_;
};

class SenserItem {
public:
    SenserItem(const string &name, const string &rule);
    ~SenserItem() = default;

    void setModel(shared_ptr<SenserModel> model);

    string name() const;
    string rule() const;

private:
    string name_;
    string rule_;

    shared_ptr<SenserModel> model_;
};

}
#endif //SENSERITEM_H
