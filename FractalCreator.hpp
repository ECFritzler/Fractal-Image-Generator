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
#include <cstdint>
#include <memory>
#include <math.h>
#include <vector>
#include "Zoom.h"
#include "Mandelbrot.hpp"
#include "Bitmap.h"
#include "ZoomList.hpp"
#include "Colouring.hpp"


namespace bit {
    
    class FractalCreator {
    private:
        int width;
        int height;
        unique_ptr<int[]> histo_ptr;
        unique_ptr<int[]> fractal_ptr;
        Bitmap bitmap;
        ZoomList zoomList;
        int total { 0 };
        
        vector<int> range;
        vector<Colouring> colours;
        vector<int> numOfRanges;
        
        bool firstRange{false};
        
    private:
        void calcIter();
        void totalIter();
        void rangeTotal();
        void drawFrac();
        void writeBitmap(string name);
        int getRange(int it) const;
        
    public:
        FractalCreator(int width, int height);
        void addRange(double rangeEnd, const Colouring& c);
        void addZoom(const Zoom& zoom);
        virtual ~FractalCreator();
        void run(string name);
    };
    
}

#endif
