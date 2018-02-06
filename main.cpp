//
//  main.cpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-05.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#include <iostream>
#include "Bitmap.h"


using namespace std;
using namespace bit;

int main() {
    
    int const WIDTH = 800;
    int const HEIGHT = 600;
    
    Bitmap bitmap(WIDTH, HEIGHT);
    
    bitmap.setPixel(WIDTH/2, HEIGHT/2, 255, 255, 255);
    
    bitmap.writeBMP("test1.bmp");
    
    cout << "finished" << endl;
    
    return 0;
}
