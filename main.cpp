//
//  main.cpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-05.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#include <iostream>
#include "Bitmap.h"
#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Mandelbrot.hpp"
#include "Bitmap.h"


using namespace std;
using namespace bit;

int main() {
    
    int const WIDTH = 800;
    int const HEIGHT = 600;
    
    Bitmap bitmap(WIDTH, HEIGHT);
    
    double min = 999999;
    double max = -999999;
    
    unique_ptr<int[]> histo(new int[Mandelbrot::MAX_ITER] {});
    unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT] {});
    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double xFrac = (x - WIDTH / 2 - 200) * 2.0 / HEIGHT;
            double yFrac = (y - HEIGHT / 2) * 2.0 / HEIGHT;
            
            int iter = Mandelbrot::getIter(xFrac, yFrac);
            
            fractal[y * WIDTH + x] = iter;
            
            if (iter != Mandelbrot::MAX_ITER) {
                histo[iter]++;
            }
            
        }
    }
    
    int total = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITER; i++)
    {
        total += histo[i];
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;
            
            int iter = fractal[y * WIDTH + x];
            
            if (iter != Mandelbrot::MAX_ITER) {
                
                double hue = 0.0;
                
                for (int i = 0; i <= iter; i++) {
                    hue += ((double) histo[i]) / total;
                }
                
                green = pow(255, hue);
            }
            bitmap.setPixel(x, y, red, green, blue);
        }
    }
    
    bitmap.writeBMP("test1.bmp");
    
    cout << "finished" << endl;
    
    return 0;
}
