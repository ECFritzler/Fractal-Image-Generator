//
//  ZoomList.cpp
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-07.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#include "ZoomList.hpp"

namespace bit{
    ZoomList::ZoomList(int w, int h): sWidth(w), sHeight(h)
    {
    
    }
   
    void ZoomList::add(const Zoom& zoom)
    {
        zooms.push_back(zoom);
    }
    
    std::pair<double, double> ZoomList::doZoom(int x, int y)
    {
        return std::pair<double, double>(0,0);
        
    }
    
}
