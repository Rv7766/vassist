#include<stdio.h>
#include <X11/Xlib.h>
#include<iostream>

int main(){

    Display *d=XOpenDisplay(NULL);
    /*
    Connecting to the Screen

    Display *d=XOpenDisplay(NULL);

    This line tells the program to connect to your computer's main screen.

    XOpenDisplay(NULL) says, "Open the default display." The result is stored in d, which acts like a remote control for 
    your screen.*/


    if(d == NULL)
    {
        printf("unable to open window\n");

        return 7;
    }

    /*
    This part is supposed to check if the connection to the screen failed.

    However, there's a mistake here! The code says if(NULL), which is always false, so the error message unable to open 
    window will never be printed, even if there's a problem.

    It should have been written as if(d == NULL) to correctly check if our "remote control" d is working.
    */

    int s = DefaultScreen(d);


    int height=200;
    int width=600;
    int test1=50;
    int test2=30;

    /*
    int s = DefaultScreen(d);: Gets the main screen to draw on.

    The other lines are just setting up numbers for our window:

    width=600: The window will be 600 pixels wide.

    height=200: It will be 200 pixels tall.

    test1=50, test2=30: It will appear 50 pixels from the left edge and 30 pixels from the top edge of your screen.
    */

    Window w = XCreateSimpleWindow(d,RootWindow(d,s),test1,test2,width,height,5,
                            WhitePixel(d,s),BlackPixel(d,s));


    /*
    This is the main command! It's like filling out an order form to create the window.

    XCreateSimpleWindow: The command to "create a simple window."

    It uses all the numbers we set up before (width, height, etc.) and also defines:

    Border width: 5 (the border will be 5 pixels thick).

    Border color: BlackPixel (the border will be black).

    Background color: WhitePixel (the inside of the window will be white).
    */                            
    XMapWindow(d,w);

    XPending(d);

    /*
    XMapWindow(d, w): Creating the window is not enough; you have to tell the computer to actually show it. This command makes the window appear on the screen.

    XPending(d): This is a command to process any pending requests. A more common command here would be XFlush(d) to ensure the drawing command is sent immediately.
    */

    getchar();

    /*
    This is a very important line. It tells the program to stop and wait until you press the Enter key in the terminal where you ran the program.

    Without this, the program would create the window and then close it instantly, so you'd never see it!
    */

    printf("Exiting\n");

    return 0;


    /*
    Once you press Enter, getchar() lets the program continue.

    printf("Exiting\n"); prints a message to tell you the program is closing.

    return 0; ends the program, and the window disappears.
    */

}
