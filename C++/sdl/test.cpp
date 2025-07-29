//C++ Standard Libraries
#include <iostream>
#include<stdlib.h>
//Third-party library
#include<SDL2/SDL.h>

int main(int argc,char* argv[]){

    if(SDL_Init(SDL_INIT_VIDEO)<0){
        std::cout << "SDL could not be initialized" <<
                SDL_GetError();
    }else{
        std::cout <<"SDL video system is ready to go\n";
    }

    return EXIT_SUCCESS;
}