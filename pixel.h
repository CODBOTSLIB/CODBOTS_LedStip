#ifndef PIXEL_H
#define PIXEL_H

#include <Arduino.h>

class Pixel
{
public:
    // Constructor
    Pixel();

    // Getter functions for the RGB values
    byte getRed() const;
    byte getGreen() const;
    byte getBlue() const;

    byte getTRed() const;
    byte getTGreen() const;
    byte getTBlue() const;

    byte getLRed() const;
    byte getLGreen() const;
    byte getLBlue() const;

    // Get a specific color channel (0 for Red, 1 for Green, 2 for Blue)
    uint8_t getColor(int n);
    uint32_t getColor();
    uint8_t getLastColor(int n);
    uint8_t getTargetColor(int n);

    long getStart() const;
    long getDuration() const;
    bool isFilled() const;

    // Setter functions for RGB values
    void setColor(int index, uint8_t v);
    void setColor(uint8_t r, uint8_t g, uint8_t b);
    void setTargetColor(uint8_t r, uint8_t g, uint8_t b, long start, long duration);
    void setRed(byte r);
    void setGreen(byte g);
    void setBlue(byte b);
    void setStart(long start);
    void setDuration(long duration);
    void setFilled(bool filled);

    // Get the RGB values as an array
    uint8_t *getColorArray() const;

    uint8_t filter(int color);

private:
    byte tr_ = 0; // target Red
    byte tg_ = 0; // target Green
    byte tb_ = 0; // target Blue

    byte lr_ = 0; // Last Red
    byte lg_ = 0; // Last Green
    byte lb_ = 0; // Last Blue

    byte r_ = 0; // Last Red
    byte g_ = 0; // Last Green
    byte b_ = 0; // Last Blue

    long start_;
    long duration_;
    bool filled_;
};

#endif
