#include <stdio.h>
#include <iostream>
#include "general_objects.h"
#include "IDWInterpolator.h"
interpolators_objects::Mesh BuildMesh()
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
    std::cout << "build mesh complete";
    return interpolators_objects::Mesh(verts, values);
}
int main() {
    auto mesh = BuildMesh();
    IDWInterpolator interpolator;
    interpolator.setMesh(&mesh);
    std::vector<geometry_objects::Point2D> target_points = {
        {10,200},
        {200, 10}
    };
    auto calcValues = interpolator.runInterpolation(target_points);
    std::cout << "\nDone!";
}