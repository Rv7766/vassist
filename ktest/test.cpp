#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    Display *d = XOpenDisplay(NULL);
    if (d == NULL) {
        printf("Unable to open display\n");
        return -1;
    }

    int s = DefaultScreen(d);
    int width = 600;
    int height = 200;

    Window w = XCreateSimpleWindow(d, RootWindow(d, s), 50, 30, width, height, 1,
                                   BlackPixel(d, s), WhitePixel(d, s));

    XSelectInput(d, w, ExposureMask | KeyPressMask);
    XMapWindow(d, w);

    GC gc = XCreateGC(d, w, 0, NULL);
    XSetForeground(d, gc, BlackPixel(d, s));

    XEvent e;
    while (1) {
        XNextEvent(d, &e);

        if (e.type == Expose) {
            // Draw a dot at (20, 20)
            XDrawPoint(d, w, gc, 20, 20);

            // Draw a line from (50, 50) to (150, 50)
            XDrawLine(d, w, gc, 50, 50, 150, 50);

            // Draw a square with top-left at (200, 50) and size 50x50
            XDrawRectangle(d, w, gc, 200, 50, 50, 50);

            // Draw a rectangle with top-left at (300, 50), width 100, height 50
            XDrawRectangle(d, w, gc, 300, 50, 100, 50);
        }

        if (e.type == KeyPress)
            break;
    }

    XCloseDisplay(d);
    return 0;
}
