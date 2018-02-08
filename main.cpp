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
#include "Zoom.h"

using namespace std;
using namespace bit;

int main() {
    
    FractalCreator fractalCreator(800, 600);
    
    fractalCreator.addRange(0.0, Colouring(0, 0, 255));
    fractalCreator.addRange(0.05, Colouring(255, 99, 71));
    fractalCreator.addRange(0.08, Colouring(255, 215, 0));
    fractalCreator.addRange(1.0, Colouring(255, 255, 255));
    
    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));
    fractalCreator.run("colourRanges.bmp");
    
    cout << "Finished." << endl;
    return 0;
}
