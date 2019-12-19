#include "../utils/includes.h"
#include "gameflow.h"


//attention il faudrait mettre des majuscule au nom des objet
int main(int argc, char **args) {
    setup *settings = new setup();
    gameflow *flow = new gameflow(2, 800, 600);

    settings->initialize(800, 600);
    flow->initialize(settings);

    while(flow->getIsRunning()){
        flow->updateFlow();
    }

    flow->clearFlow();
    settings->clear();

    return 0;
}