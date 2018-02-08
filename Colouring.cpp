//
//  Colouring.cpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-07.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#include "Colouring.hpp"


namespace bit {
    
    Colouring::Colouring(double r, double g, double b): r(r), g(g), b(b) {}
    
    Colouring operator-(const Colouring& first, const Colouring& second)
    {
        return Colouring(first.r - second.r, first.g - second.g, first.b - second.b);
    }
    
}
