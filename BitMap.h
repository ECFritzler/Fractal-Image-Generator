//
//  Bitmap.hpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-05.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#ifndef Bitmap_h
#define Bitmap_h


#include <string>
#include <cstdint>
#include <memory>
using namespace std;

namespace bit {
    
    class Bitmap {
    private:
        int width{0};
        int height{0};
        unique_ptr<uint8_t[]> pPixels{nullptr};
        
        
    public:
        Bitmap(int width, int height);
        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
        bool writeBMP(string filename);
        virtual ~Bitmap();
    };
    
}
#endif
