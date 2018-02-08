/*
 * FractalCreator.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: johnpurcell
 */

#include "FractalCreator.hpp"



namespace bit {
    
    FractalCreator::FractalCreator(int width, int height) : width(width), height(height), histo_ptr(new int[Mandelbrot::MAX_ITER] { 0 }), fractal_ptr(new int[width * height] { 0 }), bitmap(width, height), zoomList(width, height)
    {
        zoomList.add(Zoom(width / 2, height / 2, 4.0 / width));
    }
    
    
    
    void FractalCreator::addRange(double rangeEnd, const Colouring& c)
    {
        range.push_back(rangeEnd * Mandelbrot::MAX_ITER);
        colours.push_back(c);
        
        if (firstRange) {numOfRanges.push_back(0);}
        
        firstRange = true;
    }
    
    int FractalCreator::getRange(int it) const
    {
        int ran = 0;
        
        for (int i = 1; i < range.size(); i++)
        {
            
            if (range[i] > it) {break;}
            
            ran = i;
        }
        return ran;
    }
    
    void FractalCreator::addZoom(const Zoom& zoom)
    {
        zoomList.add(zoom);
    }
    
    void FractalCreator::run(string name)
    {
        calcIter();
        totalIter();
        rangeTotal();
        drawFrac();
        writeBitmap(name);
        
    }
    
    
    void FractalCreator::calcIter()
    {
        
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                pair<double, double> coords = zoomList.doZoom(x, y);
                
                int it = Mandelbrot::getIter(coords.first,
                                             coords.second);
                
                fractal_ptr[y * width + x] = it;
                
                if (it != Mandelbrot::MAX_ITER) {
                    histo_ptr[it]++;
                }
                
            }
        }
    }
    
    void FractalCreator::rangeTotal()
    {
        
        int rangeIndex = 0;
        
        for (int i = 0; i < Mandelbrot::MAX_ITER; i++)
        {
            int pixels = histo_ptr[i];
            
            if (i >= range[rangeIndex + 1]) {rangeIndex++;}
            
            numOfRanges[rangeIndex] += pixels;
        }
    }
    
    void FractalCreator::totalIter()
    {
        
        for (int i = 0; i < Mandelbrot::MAX_ITER; i++)
        {
            total += histo_ptr[i];
        }
    }
    
    void FractalCreator::drawFrac()
    {
        
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++)
            {
                
                int it = fractal_ptr[y * width + x];
                
                int ran = getRange(it);
                int rangeTotal = numOfRanges[ran];
                int rangeStart = range[ran];
                
                Colouring& startColor = colours[ran];
                Colouring& endColor = colours[ran + 1];
                Colouring colorDiff = endColor - startColor;
                
                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;
                
                if (it != Mandelbrot::MAX_ITER) {
                    
                    int totalPixels = 0;
                    
                    for (int i = rangeStart; i <= it; i++) {totalPixels += histo_ptr[i];}
                    
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
    
    void FractalCreator::writeBitmap(string name)
    {
        bitmap.writeBMP(name);
    }
    
    
    FractalCreator::~FractalCreator(){}
    
}
