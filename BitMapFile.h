//
//  BitMapFile.hpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-05.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#ifndef BitMapFile_h
#define BitMapFile_h

#include <cstdint>

using namespace std;

namespace bit {
    
#pragma pack(push, 2)
    
    struct BitmapFile {
        char header[2] { 'B', 'M' };
        int32_t fileSize;
        int32_t reserved { 0 };
        int32_t dataOffset;
    };
    
#pragma pack(pop)
    
}


#endif /* BitMapFile_hpp */
