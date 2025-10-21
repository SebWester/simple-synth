#ifndef DISTORTION_H
#define DISTORTION_H

class Distortion {
    public:
        void toggleDist();
        float clipSignal(float input);

    private:
        bool distActive = false;
};

#endif