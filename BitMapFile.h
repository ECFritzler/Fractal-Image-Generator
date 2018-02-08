//
//  BitMapFile.hpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-05.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#ifndef BitmapFile_H_
#define BitmapFile_H_

#include <cstdint>


#pragma pack(2)

namespace bit {
    
    struct BitmapFile {
        char header[2] { 'B', 'M' };
        int32_t fileSize;
        int32_t reserved { 0 };
        int32_t dataOffset;
    };
    
}

#endif /* BitMapFile_hpp */
