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
    
    void FractalCreator::run(string name)
    {
        addZoom(Zoom(295, height - 202, 0.1));
        addZoom(Zoom(312, height - 304, 0.1));
        calcIter();
        totalIter();
        drawFrac();
        writeBitmap(name);
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
        Colouring start(0,0,0);
        Colouring end(255, 101, 90);
        Colouring diff = end - start;
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
                    
                    green = start.g + diff.g * hue;
                    blue = start.b + diff.b * hue;
                    red = pow((start.r + diff.r), hue);
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
    
    void FractalCreator::addRange(double rangeEnd, const Colouring& c)
    {
        range.push_back(rangeEnd*Mandelbrot::MAX_ITER);
        colours.push_back(c);
    }
    
    
}
