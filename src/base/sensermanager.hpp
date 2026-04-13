#ifndef SENSERMANAGER_H
#define SENSERMANAGER_H

#include <list>

#include "config.hpp"
#include "senseritem.hpp"

namespace base {

using namespace std;

class SenserManager {
public:
    explicit SenserManager(const Config &config);

    list<SenserItem> sensers() const;
    
private:
    void createSensers();

private:
    const Config &config_;
    list<SenserItem> list_;

};

}

#endif //SENSERMANAGER_H
