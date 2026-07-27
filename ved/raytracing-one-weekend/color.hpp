#ifndef COLOR_HPP
#define COLOR_HPP

#include "vec3.hpp"
#include <iostream>

using color = vec3;

void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // [0, 1] -> [0, 255]
    int rb = int(255.999 * r);
    int gb = int(255.999 * g);
    int bb = int(255.999 * b);

    out << rb << ' ' << gb << ' ' << bb << '\n';
}

#endif