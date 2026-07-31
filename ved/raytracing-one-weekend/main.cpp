#include <iostream>
#include "ray.hpp"
#include "color.hpp"
#include "vec3.hpp"

// [Chapter 5]: Adding a sphere
bool hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = center - r.origin();
    auto a = dot(r.direction(), r.direction());
    auto b = -2.0 * dot(r.direction(), oc);
    auto c = dot(oc, oc) - radius * radius;
    auto discriminant = b * b - 4 * a * c;
    return (discriminant >= 0);
}

color ray_color(const ray& r) {
    // return color(0, 0, 0);
    if (hit_sphere(point3(0, 0, -1), .2, r)) {
        return color(0, 1, 1);
    }
    vec3 unit_dir = unit_vector(r.direction());
    auto a = 0.7 * (unit_dir.y() + 1.0);
    return (1.0 - a) * color(1.0, 0, 1.2) + a * color(0.5, 0.8, 1.0);
}

int main() {
    double aspect_ratio = 16.0 / 9.0;
    int iw = 800, 
        ih = int(iw / aspect_ratio);
    ih = (ih < 1) ? 1 : ih;

    // [src]: viewport widths less than one are ok since they are real valued
    // auto vh = 2.0;
    // auto vw = vh * (double(iw) / ih);

    // camera
    auto focal_length       = 1.0;
    auto viewport_height    = 2.0;
    auto viewport_width     = viewport_height * (double(iw) / ih);
    auto camera_center      = point3(0, 0, 0);

    // vectors across the horizontal and down the vertical viewport edges
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // horizontal and vertical delta vectors from pixel to pixel
    auto pix_delta_u = viewport_u / iw;
    auto pix_delta_v = viewport_v / ih;

    // location of upper left pix.
    auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - (viewport_u / 2) - (viewport_v / 2); 
    auto pixel100_loc = viewport_upper_left + 0.5 * (pix_delta_u + pix_delta_v);
    // Render the image
    std::cout << "P3\n" << iw << ' ' << ih << "\n255\n";

    for (int j = 0; j < ih; j++) {
        std::clog << "\rScanlines remaining: " << (ih - j) << ' ' << std::flush;
        for (int i = 0; i < iw; i++) {
            auto pix_center = pixel100_loc + (i * pix_delta_u) + (j * pix_delta_v);
            auto ray_dir    = pix_center - camera_center;
            ray r(camera_center, ray_dir);

            // auto pc         = color(
            //     double(i) / (iw - 1),
            //     double(j) / (ih - 1),
            //     0
            // );

            color pix_color = ray_color(r);

            write_color(std::cout, pix_color);
        }
    }

    std::clog << "\rDone.                   \n";

    return 0;
}