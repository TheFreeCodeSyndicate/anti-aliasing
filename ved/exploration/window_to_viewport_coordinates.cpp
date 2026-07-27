#include <iostream>

struct point {
    int x, y;

    // point() : p0(0), p1(0), p2(0) {}
    point(int _x, int _y) : x(_x), y(_y) {}
};

struct canvas {
    int x_min, x_max, y_min, y_max;

    canvas(int a, int b, int c, int d) : x_min(a), x_max(b), y_min(c), y_max(d) {}
};

point W2V_transform(point w_p, canvas w, canvas v) {
    double S_x = double(v.x_max - v.x_min) / (w.x_max - w.x_min);
    double S_y = double(v.y_max - v.y_min) / (w.y_max - w.y_min);

    return point(
        v.x_min + double(w_p.x - w.x_min) * S_x,
        v.y_min + double(w_p.y - w.y_min) * S_y
    );
}

int main() {
    point p = point(30, 80);
    canvas w = canvas(20, 80, 40, 80);
    canvas v = canvas(30, 60, 40, 60);
    point v_p = W2V_transform(p, w, v);

    std::cout << "(" << v_p.x << ", " << v_p.y << ")" << '\n';
    return 0;
}