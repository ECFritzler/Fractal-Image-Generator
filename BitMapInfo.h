//
//  BitMapInfo.h
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-05.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#ifndef BitMapInfo_h
#define BitMapInfo_h

#include <cstdint>

using namespace std;

#pragma pack(2)

struct BitMapInfo{
    int32_t headerSize{40};
    int32_t width;
    int32_t height;
    int16_t planes{1};
    int16_t bitsPerPixel{24};
    int32_t compression{0};
    int32_t dataSize{0};
    int32_t horizontalRes{2400};
    int32_t verticalRes{2400};
    int32_t colours{0};
    int32_t importantColours{0};
    
};
#endif /* BitMapInfo_h */
