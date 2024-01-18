#ifndef ii_LedArray_H
#define ii_LedArray_H

#include <Adafruit_NeoPixel.h>
#include "colors.h"
#include "pixel.h"

class ii_LedArray
{
private:
    Adafruit_NeoPixel strip;

    int brightness;
    void changed();
    int patternstart;
    bool patterndir;
    int selectedpattern;
    bool blurmode;
    Pixel *pixels = nullptr;
    bool filled_;
    bool _changedb;

    // Function to allocate memory for the pixel array
    void allocatePixelsArray(int size);

public:
    Colors colors;
    // Constructor
    ii_LedArray();
    ii_LedArray(int pin, int ledcount);

    // Initialize the LED strip
    void begin();

    // Set blur mode for pixel effects
    void setBlurMode(bool bmode);

    // Test the LED strip with color transitions
    void test();

    // Test the LED strip with all available colors
    void testAll();

    // Clear all colors on the LED strip
    void clear();

    // Show the current LED colors
    void show();

    // Update the LED strip with any pixel animations
    bool update();

    // Set the brightness of the LED strip
    void setBrightness(int bright); // Brightness range: 0-100

    // Get the brightness of the LED strip
    int getBrightness();

    // Get the color of a specific LED
    uint32_t getColor(int index);

    // Create a pattern with all available colors
    void _patternAllColors(bool changedir);

    // Move colors in the LED strip in a specified direction
    void move(bool direction);

    bool isFilled() const;

    void setFilled(bool filled);

    // Get the number of LEDs in the strip
    int getLength();

    // Set the color of a specific LED using a 32-bit color value
    void setColor(uint8_t index, uint32_t color);

    // Set the color of a specific LED using RGB values
    void setColor(uint8_t index, uint8_t red, uint8_t green, uint8_t blue);

    //
    void setColor(uint32_t color);

    // Set the same color for all LEDs
    void setColor(uint8_t red, uint8_t green, uint8_t blue);

    //////////////////////////////////////////////////////////////////////

    // Set the color of a specific LED with a start time and duration using a 32-bit color value
    void setColorTrans(uint8_t index, uint32_t color, long start, long duration);

    // Set the color of a specific LED with a start time and duration
    void setColorTrans(uint8_t index, uint8_t red, uint8_t green, uint8_t blue, long start, long duration);

    //
    void setColorTrans(uint32_t color, long start, long duration);

    // Set the same color for all LEDs with a start time and duration
    void setColorTrans(uint8_t red, uint8_t green, uint8_t blue, long start, long duration);

    // validations
    bool checkRange(int n);
};

#endif
