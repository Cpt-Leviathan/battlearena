//
// Created by okotcham on 12/11/2019.
//

#include "CameraManager.h"

CameraManager::CameraManager() {
    camera=new Camera();
}

CameraManager::~CameraManager() {
    delete camera;
}

void CameraManager::update(float angle) {
    camera->changerPosition(angle);
}

void CameraManager::initialiser() {
    camera->initialiser();
}

Camera *CameraManager::getCamera() const {
    return camera;
}
