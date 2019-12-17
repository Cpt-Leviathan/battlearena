//
// Created by okotcham on 12/11/2019.
//

#include "Camera.h"

void Camera::changerPosition(float angle) {
    eyeX=-cos((angle*M_PI)/180.0)*300;
    eyeZ=sin((angle*M_PI)/180.0)*300;
}

void Camera::initialiser() {
    eyeX=300;
    eyeY=700;
    eyeZ=0;
    cibleX=0;
    cibleY=0;
    cibleZ=0;

}
