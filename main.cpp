//
//  main.cpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-05.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#include <iostream>
#include "FractalCreator.hpp"
#include "Colouring.hpp"
using namespace std;
using namespace bit;

int main() {
    
    FractalCreator fractal(800, 600);
   
    fractal.addRange(0.0, Colouring(0, 0, 0));
    fractal.addRange(0.3, Colouring(255, 0, 0));
    fractal.addRange(0.5, Colouring(0,0,255));
    fractal.addRange(1.0, Colouring(0,255,0));
   

    
    fractal.run("colourRanges.bmp");
    
    cout << "finished" << endl;
    
    return 0;
}
