#include <SDL.h>
#include <stdio.h>

int main(int argc,char** argv){
    
    SDL_Window *window=NULL;

    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        SDL_Log("ERREUR > %s \n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    window=SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                            800,600, SDL_WINDOW_SHOWN);
                            
    if( window== NULL){
        SDL_Log("ERREUR CREATION FENETRE > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_Delay(5000);

    //programme
    SDL_Quit();
    return EXIT_SUCCESS;
}
    //gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
    //bin\prog.exe