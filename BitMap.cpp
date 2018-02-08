//
//  Bitmap.cpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-05.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#include <fstream>
#include "Bitmap.h"
#include "BitMapInfo.h"
#include "BitMapFile.h"

using namespace bit;
using namespace std;

namespace bit {
    
    Bitmap::Bitmap(int width, int height) :width(width), height(height), pPixels(new uint8_t[width * height * 3] { })
    {
        
    }
    
    bool Bitmap::writeBMP(string filename)
    {
        
        BitmapFile fileHeader;
        BitmapInfo infoHeader;
        
        fileHeader.fileSize = sizeof(BitmapFile) + sizeof(BitmapInfo)
        + width * height * 3;
        fileHeader.dataOffset = sizeof(BitmapFile) + sizeof(BitmapInfo);
        
        infoHeader.width = width;
        infoHeader.height = height;
        
        ofstream file;
        file.open(filename, ios::out | ios::binary);
        
        if (!file) {return false;}
        
        file.write((char *) &fileHeader, sizeof(fileHeader));
        file.write((char *) &infoHeader, sizeof(infoHeader));
        file.write((char *) pPixels.get(), width * height * 3);
        
        file.close();
        
        if (!file) { return false; }
        
        return true;
    }
    
    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
    {
        uint8_t *pixel = pPixels.get();
        
        pixel += (y * 3) * width + (x * 3);
        
        pixel[0] = blue;
        pixel[1] = green;
        pixel[2] = red;
    }
    
    Bitmap::~Bitmap()
    {}
    
}









