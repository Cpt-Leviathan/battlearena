//
// Created by okotcham on 12/11/2019.
//

#ifndef BATTLEARENA_CAMERA_H
#define BATTLEARENA_CAMERA_H

#include <math.h>

class Camera {
private:


public:
    float eyeX;
    float eyeY;
    float eyeZ;
    float cibleX;
    float cibleY;
    float cibleZ;
    void changerPosition(float angle);
    void initialiser();

};


#endif //BATTLEARENA_CAMERA_H
