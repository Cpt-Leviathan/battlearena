//
// Created by okotcham on 12/11/2019.
//

#ifndef BATTLEARENA_CAMERAMANAGER_H
#define BATTLEARENA_CAMERAMANAGER_H


#include "../utils/includes.h"
#include "../entities/Camera.h"
class CameraManager {
private:
    Camera *camera;
public:
    CameraManager();
    ~CameraManager();
    void update(float angle);
    void initialiser();

    Camera *getCamera() const;
};


#endif //BATTLEARENA_CAMERAMANAGER_H
