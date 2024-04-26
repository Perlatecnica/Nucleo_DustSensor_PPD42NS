/*
MIT License

Copyright (c) [2024] 
Organization: Perlatecnica APS ETS
Author: Mauro D'Angelo
Example to use the PPD42NS Dust Sensor
This code initializes a PPD42NS dust sensor object with pin D7 connected to the sensor. 
Inside the main loop, it continuously reads the dust density from the sensor using the readDustDensity() method. 
It then prints the dust density in particles per 0.01 cubic feet using printf(). 
After each reading, it waits for 30 seconds using ThisThread::sleep_for() before taking the next sample.

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


#include "mbed.h"
#include "PPD42NS.h"

PPD42NS dustSensor(D7); // Instantiate a PPD42NS object with pin D7 connected to the sensor

int main() {
    while (true) {
        // Read dust density from the sensor
        float dustDensity = dustSensor.readDustDensity();
        
        // Print the dust density in particles per 0.01 cubic feet
        printf("Dust Density: %.2f particles per 0.01 cubic feet\n", dustDensity);
        
        // Wait for 30 seconds before taking the next sample
        ThisThread::sleep_for(30000); // Sampling interval
    }
}
