//
//  BitMapFile.hpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-05.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#ifndef BitMapFile_h
#define BitMapFile_h

#include <stdio.h>
#include <cstdint> // Use 32 bit int
 // Get rid of hidden padding
#pragma pack(2) // Make c++ align everything on 2Byte boundaries

using namespace std;

struct BitMapFile{
  
    char header[2]{'B', 'M'};
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset;
    
};

#endif /* BitMapFile_hpp */
