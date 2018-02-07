//
//  FractalCreator.hpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-07.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#ifndef FractalCreator_hpp
#define FractalCreator_hpp

#include <string>
#include <stdio.h>
#include "Zoom.h"
#include "Bitmap.h"
#include "Mandelbrot.hpp"
#include "ZoomList.hpp"
#include "Colouring.hpp"
#include <vector>
namespace bit{
    class FractalCreator{
        
        // Member Variables
        int width;
        int height;
        Bitmap bitmap;
        unique_ptr<int[]> histo_prt;
        unique_ptr<int[]> fractal_ptr;
        ZoomList zoomList;
        int total;
        vector<double> range;
        vector<Colouring> colours;
        
        
        // Member Functions
        void calcIter();
        void totalIter();
        void drawFrac();
        void addZoom(const Zoom& zoom);
        void writeBitmap(std::string fileName);
        
    public:
        FractalCreator(int w, int h);
        void run(string name);
        void addRange(double rangeEnd, const Colouring& c);
        
        
    };
}
#endif /* FractalCreator_hpp */
