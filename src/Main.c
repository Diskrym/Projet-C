#include <SDL.h>
#include <stdio.h>

int main(int argc,char** argv){
    // printf("Hello world!");
    SDL_version nb;
    SDL_VERSION(&nb);
    printf("heeeeeeezeeeeeuhsdvodsfohlieeeeeee %d.%d.%d !\n",nb.major,nb.minor,nb.patch);
    return 0;
}
    //gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
    //bin\prog.exe