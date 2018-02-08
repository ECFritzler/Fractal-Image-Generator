//
//  Mandelbrot.hpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-06.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#ifndef Mandelbrot_hpp
#define Mandelbrot_hpp

namespace bit {
    
    class Mandelbrot {
    public:
        static const int MAX_ITER = 1000;
        
    public:
        Mandelbrot();
        virtual ~Mandelbrot();
        
        static int getIter(double x, double y);
    };
    
}
#endif
