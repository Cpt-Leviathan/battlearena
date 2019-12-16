//
// Created by jmarierr on 2019-12-11.
//

#ifndef BATTLEARENA_FLOW_H
#define BATTLEARENA_FLOW_H

#include "../utils/includes.h"

class flow {
protected:
    bool isRunning;
    SDL_Event event;
    const Uint8 *state;
    setup* settings;
public:
    flow();
    ~flow();
    virtual void initialize(setup* _settings);
    virtual void updateFlow();
    virtual void clearWindow();
    virtual void manageEvents();
    virtual void draw();
    virtual void pauseFrame();
    virtual void updateWindow();
    virtual void clearFlow();

    virtual bool getIsRunning() const;
};


#endif //BATTLEARENA_FLOW_H
