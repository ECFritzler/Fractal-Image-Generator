//
//  Mandelbrot.cpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-06.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#include <complex>
#include "Mandelbrot.hpp"

using namespace std;

namespace bit {
    
    Mandelbrot::Mandelbrot() {
        // TODO Auto-generated constructor stub
        
    }
    
    Mandelbrot::~Mandelbrot() {
        // TODO Auto-generated destructor stub
    }
    
    int Mandelbrot::getIter(double x, double y) {
        
        complex<double> z = 0;
        complex<double> c(x, y);
        
        int it = 0;
        
        while(it < MAX_ITER) {
            z = z*z + c;
            
            if(abs(z) > 2) {
                break;
            }
            it++;
        }
        return it;
    }
    
}


