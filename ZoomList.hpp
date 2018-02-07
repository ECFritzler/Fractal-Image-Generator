//
//  ZoomList.hpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-07.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#ifndef ZoomList_hpp
#define ZoomList_hpp

#include <stdio.h>
#include "Zoom.h"
#include <vector>
#include <utility>

namespace bit{
    
    class ZoomList{
        
        int sHeight{0};
        int sWidth{0};
        std::vector<Zoom> zooms;
        
    public:
        ZoomList(int w, int h);
        void add(const Zoom& zoom);
        std::pair<double, double> doZoom(int x, int y);
    };
}

#endif /* ZoomList_hpp */
