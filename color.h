#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

// Similar to point3, color is just an alias of vec3
using color = vec3;

// We can store vector locations or colors in vec3, here we will store a color.
// This method will allow us to access and write that color based on the double value in the vec3 x,y,z values
void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Translate the [0, 1] component values to the byte range [0,255] for rgb
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif