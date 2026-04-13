#include "senseritem.hpp"

namespace base {

SenserItem::SenserItem(const string &name, const string &rule) : name_(name), rule_(rule) {
    
}

void SenserItem::setModel(shared_ptr<SenserModel> model) {
    model_ = model;
}

string SenserItem::name() const {
    return name_;
}

string SenserItem::rule() const {
    return name_;
}

SenserParametersSet::SenserParametersSet(StateRule state, TempRule temp, SpeedRule speed) : state_(state), temp_(temp), speed_(speed) {
    
}

void SenserModel::append(const string &fileName, SenserParametersSet set) {
    data_.insert({fileName, set}); 
}
    
}