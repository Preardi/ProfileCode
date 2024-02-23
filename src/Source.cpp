#include <stdio.h>
#include <iostream>
#include "general_objects.h"
#include "idw_interpolator.h"
#include "utilities.h"
#include <nlohmann/json.hpp>

int main() {
    auto mesh =  buildMesh();
    nlohmann::json jsonObj;
    IDWInterpolator interpolator;
    interpolator.setMesh(&mesh);
    std::vector<geometry_objects::Point2D> target_points = {
        {10,200},
        {200, 10}
    };
    auto calcValues = interpolator.runInterpolation(target_points);
    std::cout << "complete";
}