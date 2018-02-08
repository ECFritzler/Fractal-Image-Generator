//
//  Mandelbrot.cpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-06.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#include "Mandelbrot.hpp"
#include <complex>


using namespace std;

namespace bit {
    
    Mandelbrot::Mandelbrot() {}
    
    int Mandelbrot::getIter(double x, double y)
    {
        complex<double> z = 0;
        complex<double> c(x, y);
        
        int iter = 0;
        
        while(iter < MAX_ITER) {
            z = z*z + c;
            
            if(abs(z) > 2) {
                break;
            }
            
            iter++;
        }
        
        return iter;
    }
    
    Mandelbrot::~Mandelbrot() {}
    
    
}


