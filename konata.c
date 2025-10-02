#include <cairo/cairo.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

void draw_hair(cairo_t *cr) {
    // Draw hair
    cairo_set_source_rgb(cr, 0.5, 0.2, 0.1); // Brown
    cairo_move_to(cr, 300, 100);
    cairo_curve_to(cr, 350, 50, 450, 50, 500, 100);
    cairo_line_to(cr, 500, 300);
    cairo_curve_to(cr, 450, 250, 350, 250, 300, 300);
    cairo_fill(cr);
}

void draw_face(cairo_t *cr) {
    // Draw face
    cairo_set_source_rgb(cr, 1, 0.8, 0.6); // Skin tone
    cairo_arc(cr, 400, 250, 100, 0, 2 * M_PI);
    cairo_fill(cr);
}

void draw_eyes(cairo_t *cr) {
    // Draw eyes
    cairo_set_source_rgb(cr, 0, 0, 0); // Black
    cairo_arc(cr, 350, 200, 20, 0, 2 * M_PI);
    cairo_fill(cr);
    cairo_arc(cr, 450, 200, 20, 0, 2 * M_PI);
    cairo_fill(cr);
}

void draw_mouth(cairo_t *cr) {
    // Draw mouth
    cairo_set_source_rgb(cr, 0, 0, 0); // Black
    cairo_move_to(cr, 375, 300);
    cairo_curve_to(cr, 400, 320, 425, 300, 450, 300);
    cairo_set_line_width(cr, 5);
    cairo_stroke(cr);
}

int main() {
    cairo_surface_t *surface;
    cairo_t *cr;

    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
    cr = cairo_create(surface);

    draw_hair(cr);
    draw_face(cr);
    draw_eyes(cr);
    draw_mouth(cr);

    cairo_surface_write_to_png(surface, "konata.png");

    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return 0;
}
