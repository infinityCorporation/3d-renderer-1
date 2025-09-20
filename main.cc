#include "color.h"
#include "vec3.h"

#include <iostream>

int main() {
    // Image

    int image_width = 256;
    int image_height = 256;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines Remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i=0; i < image_width; i++) {
            // We define a color class (which is rly just vec3 with the write color override method)
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);

            // Then we write the color using our color method
            write_color(std::cout, pixel_color);
        }
    }
}