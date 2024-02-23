#include "utilities.h"
interpolators_objects::Mesh buildMesh()
{
    std::vector<geometry_objects::Point2D> verts = {
            {2000.00, -4000.00 },
            {8209.32, -2020.93},
            {7531.88, -3996.67},
            {6217.60, -1168.51},
            {1500.00, -1200.00},
            {4002.23, -2579.58},
    };

    auto values = {
        10.00,
        15.00,
        25.00,
        12.00,
        -1.00,
        48.00,
    };
    return interpolators_objects::Mesh(verts, values);
}

interpolators_objects::Mesh readMesh(std::string )
{
    std::vector<geometry_objects::Point2D> verts = {
               {2000.00, -4000.00 },
               {8209.32, -2020.93},
               {7531.88, -3996.67},
               {6217.60, -1168.51},
               {1500.00, -1200.00},
               {4002.23, -2579.58},
    };

    auto values = {
        10.00,
        15.00,
        25.00,
        12.00,
        -1.00,
        48.00,
    };
    
    return interpolators_objects::Mesh(verts, values);
}