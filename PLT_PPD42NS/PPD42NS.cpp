/*
MIT License

Copyright (c) [2024] 
Organization: Perlatecnica APS ETS
Author: Mauro D'Angelo
Example to use the LSM6DSV16X Wake Up Detection

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#include "PPD42NS.h"

PPD42NS::PPD42NS(PinName pin) : _interrupt(pin) {
    _pulseCount = 0;
    _timer.start();
    _interrupt.rise(callback(this, &PPD42NS::_pulseDetected));
}

PPD42NS::~PPD42NS() {
    _timer.stop();
}

void PPD42NS::_pulseDetected() {
    _pulseCount++;
}

float PPD42NS::readDustDensity() {
    // Calculate dust density based on pulse count
    // This is an example calculation and may require accurate calibration
    const float samplingTime = 30.0; // Sampling time in seconds
    const float lowPulseOccupancy = _pulseCount * 10.0; // Time in milliseconds
    const float ratio = lowPulseOccupancy / (samplingTime * 1000.0);
    const float concentration = 1.1 * pow(ratio, 3) - 3.8 * pow(ratio, 2) + 520 * ratio + 0.62; // in particles per 0.01 cubic feet

    _pulseCount = 0; // Reset pulse count for the next reading
    _timer.reset();

    return concentration;
}
