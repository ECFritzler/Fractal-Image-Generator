//
//  BitMap.hpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-05.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#ifndef BitMap_h
#define BitMap_h

#include <stdio.h>
#include <string>
#include <cstdint>

using namespace std;

class Bitmap{
private:
    int width{0};
    int height{0};
    
public:
    Bitmap(int width, int height);
    virtual ~Bitmap();
    bool write(string fiename);
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
};


#endif /* BitMap_h */
