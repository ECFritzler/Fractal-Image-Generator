//
//  main.cpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-05.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#include <iostream>
#include "FractalCreator.hpp"

using namespace std;
using namespace bit;

int main() {
    
    int const height = 600;
    
    FractalCreator fractal(800, 600);
    
    fractal.addZoom(Zoom(295, height - 202, 0.1));
    fractal.addZoom(Zoom(312, height - 304, 0.1));
    fractal.calcIter();
    fractal.totalIter();
    fractal.drawFrac();
    fractal.writeBitmap("zoomIn.bmp");
    
    cout << "finished" << endl;
    
    return 0;
}
