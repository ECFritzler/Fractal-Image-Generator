//
//  FractalCreator.cpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-07.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#include "FractalCreator.hpp"
#include <math.h>

namespace bit{
    FractalCreator::FractalCreator(int w, int h):width(w), height(h), histo_prt(new int[Mandelbrot::MAX_ITER] {0}),fractal_ptr(new int[width * height] {0}), bitmap(width, height), zoomList(width, height), total(0)
    {
        zoomList.add(Zoom(width/2, height/2, 4.0/width));
    }
    
    void FractalCreator::calcIter()
    {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                pair<double, double> coord = zoomList.doZoom(x, y);
                
                
                int iter = Mandelbrot::getIter(coord.first, coord.second);
                
                fractal_ptr[y * width + x] = iter;
                
                if (iter != Mandelbrot::MAX_ITER) {
                    histo_prt[iter]++;
                }
                
            }
        }

    }
    
    void FractalCreator::totalIter()
    {
        for (int i = 0; i < Mandelbrot::MAX_ITER; i++)
        {
            total += histo_prt[i];
        }
    }
    
    void FractalCreator::drawFrac()
    {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                
                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;
                
                int iter = fractal_ptr[y * width + x];
                
                if (iter != Mandelbrot::MAX_ITER) {
                    
                    double hue = 0.0;
                    
                    for (int i = 0; i <= iter; i++) {
                        hue += ((double) histo_prt[i]) / total;
                    }
                    
                    //green = pow(200, hue);
                    blue = pow(200, hue);
                    red = pow(175, hue);
                }
                bitmap.setPixel(x, y, red, green, blue);
            }
        }
    }
    
    void FractalCreator::addZoom(const Zoom& zoom)
    {
        zoomList.add(zoom);
    }
    
    void FractalCreator::writeBitmap(std::string fileName)
    {
        bitmap.writeBMP(fileName);
    }
}
