#ifndef CAR_H
#define CAR_H

struct Car {
    int numberOfCylinders;
    double engineVolume;
    char tireMark;
    bool manualTransmission;
    char number[8];
    unsigned int yearsOfMaintenance[4];
};

#endif	// CAR_H
