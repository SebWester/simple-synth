#ifndef GAIN_H
#define GAIN_H

class Gain {
    public:
        Gain(float l = 0.5f);
        float process(float input);
        void setLevel(float newLevel);

    private:
        float level;

};

#endif