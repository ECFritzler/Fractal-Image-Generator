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

namespace bit{
    class FractalCreator{
        int width;
        int height;
        Bitmap bitmap;
        unique_ptr<int[]> histo_prt;
        unique_ptr<int[]> fractal_ptr;
        ZoomList zoomList;
        int total;
        
    public:
        FractalCreator(int w, int h);
        void calcIter();
        void totalIter();
        void drawFrac();
        void addZoom(const Zoom& zoom);
        void writeBitmap(std::string fileName);
        
    };
}
#endif /* FractalCreator_hpp */
