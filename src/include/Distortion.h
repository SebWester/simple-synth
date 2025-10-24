#ifndef DISTORTION_H
#define DISTORTION_H

class Distortion {
    public:
        void toggleDist();
        void setThreshold(float t);
        float clipSignal(float input);

    private:
        bool distActive = false;
        float threshold = 0.3f;
};

#endif