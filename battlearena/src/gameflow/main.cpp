#include "../utils/includes.h"
#include "gameflow.h"

int main(int argc, char **args) {
    setup *settings = new setup();
    gameflow *flow = new gameflow();
    settings->initialize(800, 600);
    flow->initialize(settings);
    while(flow->getIsRunning()){
        flow->updateFlow();
    }
    settings->clear();
    flow->cleanFlow();
    return 0;
}