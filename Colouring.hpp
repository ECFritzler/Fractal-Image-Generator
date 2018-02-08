//
//  Colouring.hpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-07.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#ifndef Colouring_hpp
#define Colouring_hpp

namespace bit {
    
    struct Colouring {
        double r;
        double g;
        double b;
        
        Colouring(double r, double g, double b);
    };
    
    Colouring operator-(const Colouring& first, const Colouring& second);
    
}

#endif
