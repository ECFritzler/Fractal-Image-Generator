//
//  Bitmap.cpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-05.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#include "Bitmap.h"
#include "BitMapInfo.h"
#include "BitMapFile.h"
#include <fstream>

using namespace bit;
using namespace std;

namespace bit{
    Bitmap::Bitmap(int w, int h):
    width(w), height(h), pPixel(new uint8_t[width*height*3]{})
    {
        
    }
    
    bool Bitmap::writeBMP(string filename)
    {
        BitmapInfo bitmapInfo;
        BitmapFile bitmapFile;
        
        bitmapFile.fileSize = sizeof(BitmapFile) + sizeof(BitmapInfo) +
            (width*height*3);
        bitmapFile.dataOffset = sizeof(BitmapFile) + sizeof(BitmapInfo);
        
        bitmapInfo.width = width;
        bitmapInfo.height = height;
        
        ofstream bmpFile;
        bmpFile.open(filename, ios::out|ios::binary);
        
        if(!bmpFile)
        {
            return false;
        }
        
        bmpFile.write((char*)&bitmapFile, sizeof(bitmapFile));
        bmpFile.write((char*)&bitmapInfo, sizeof(bitmapInfo));
        bmpFile.write((char*)pPixel.get(), width*height*3);
        
        bmpFile.close();
        if(!bmpFile)
        {
            return false;
        }
        
        return true;
    }
    
    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
    {
        uint8_t *pixel = pPixel.get();
        pixel += (y*3)  * width + (x*3);
        
        pixel[0] = blue;
        pixel[1] = green;
        pixel[2] = red;
        
        // 0xFF8833;
        
    }
    
    Bitmap::~Bitmap()
    {
        //delete[] pPixel;
    }
}









