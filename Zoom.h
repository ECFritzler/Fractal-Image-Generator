//
//  Zoom.h
//  Fractal Image Generator
//
//  Created by Claire Fritzler on 2018-02-06.
//  Copyright © 2018 Claire Fritzler. All rights reserved.
//

#ifndef Zoom_h
#define Zoom_h


namespace bit {
    struct Zoom{
        Zoom(int x, int y, double scale): x(x), y(y), scale(scale){}
        int x{0};
        int y{0};
        double scale{0.0};
    };
}

#endif /* Zoom_h */
