//
//  FractalCreator.cpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-07.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#include "FractalCreator.hpp"
#include <math.h>
#include <assert.h>
#include <iostream>

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
        bitmap.writeBMP(name);
        calcRangeTotal();
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
                
                int iterations = fractal_ptr[y * width + x];
                
                int ran = getRange(iterations);
                std::cout<<iterations << std::endl;
                int rangeTotal = numRange[ran];
                int rangeStart = range[ran];
                
                Colouring& startColor = colours[ran];
                Colouring& endColor = colours[ran + 1];
                Colouring colorDiff = endColor - startColor;
                
                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;
                
                if (iterations != Mandelbrot::MAX_ITER) {
                    
                    int totalPixels = 0;
                    
                    for (int i = rangeStart; i <= iterations; i++) {
                        totalPixels += histo_prt[i];
                    }
                    
                    red = startColor.r
                    + colorDiff.r * (double) totalPixels / rangeTotal;
                    green = startColor.g
                    + colorDiff.g * (double) totalPixels / rangeTotal;
                    blue = startColor.b
                    + colorDiff.b * (double) totalPixels / rangeTotal;
                    
                }
                
                bitmap.setPixel(x, y, red, green, blue);
            }
        }
    }
    
    void FractalCreator::addZoom(const Zoom& zoom)
    {
        zoomList.add(zoom);
    }
    
    
    void FractalCreator::addRange(double rangeEnd, const Colouring& c)
    {
        range.push_back(rangeEnd*Mandelbrot::MAX_ITER);
        colours.push_back(c);
        
        if(rangeStart){numRange.push_back(0);}
        rangeStart = true;
        
    }
    
    void FractalCreator::calcRangeTotal()
    {
        int rangeIndex = 0;
        
        for(int i = 0; i < Mandelbrot::MAX_ITER; i++)
        {
            int pixel = histo_prt[i];
            if (i >= range[rangeIndex + 1]) {
                rangeIndex++;
            }
            
            numRange[rangeIndex] += pixel;
        }
    }
    
    int FractalCreator::getRange(int iterations) const
    {
        int r = 0;
        
        for (int i = 1; i < range.size(); i++) {
            r = i;
            if (range[i] > iterations) {
                break;
            }
            
        }
        
        r--;
        
        assert(r > -1);
        assert(r < range.size());
       
        return r;
    
    }
    
}
