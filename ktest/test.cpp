#include<stdio.h>
#include <X11/Xlib.h>
#include<iostream>

int main(){

    Display *d=XOpenDisplay(NULL);
    if(NULL)
    {
        printf("unable to open window\n");

        return -1;
    }

    int s = DefaultScreen(d);


    int height=200;
    int width=600;
    int test1=50;
    int test2=30;

    Window w = XCreateSimpleWindow(d,RootWindow(d,s),test1,test2,width,height,5,
                            BlackPixel(d,s),WhitePixel(d,s));

    XMapWindow(d,w);

    XPending(d);

    getchar();

    printf("Exiting\n");

    return 0;

}
