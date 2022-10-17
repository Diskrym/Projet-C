#include "../header/proto.h"
 
 
void gestionInputs(Input *input)
{
    //On gère le clavier (on rajoutera plus tard la gestion
    //des joysticks)
    getInput(input);
}
 
 
void getInput(Input *input)
{
    SDL_Event event;
 
    /* Keymapping : gère les appuis sur les touches et les enregistre
    dans la structure input */
 
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
 
            case SDL_QUIT:
                exit(0);
            break;
 
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        exit(0);
                    break;
 
                    case SDLK_DELETE:
                        input->erase = 1;
                    break;
 
                    case SDLK_c:
                        input->jump = 1;
                    break;
 
                    case SDLK_v:
                        input->attack = 1;
                    break;
 
                    case SDLK_LEFT:
                        input->left = 1;
                    break;
 
                    case SDLK_RIGHT:
                        input->right = 1;
                    break;
 
                    case SDLK_DOWN:
                        input->down = 1;
                    break;
 
                    case SDLK_UP:
                        input->up = 1;
                    break;
 
 
                    case SDLK_RETURN:
                        input->enter = 1;
                    break;
 
 
                    default:
                    break;
                }
            break;
 
            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_DELETE:
                        input->erase = 0;
                    break;
 
                    case SDLK_c:
                        input->jump = 0;
                    break;
 
                    case SDLK_LEFT:
                        input->left = 0;
                    break;
 
                    case SDLK_RIGHT:
                        input->right = 0;
                    break;
 
                    case SDLK_DOWN:
                        input->down = 0;
                    break;
 
                    case SDLK_UP:
                        input->up = 0;
                    break;
 
                    case SDLK_RETURN:
                        input->enter = 0;
                    break;
 
                    default:
                    break;
                }
            break;
 
        }
 
    }
}

void mouvement(Input *input, Pos *pos)
{
while ( input->down || input->up || input->right || input->left != 0)
{
    if (input->down == 1)
    {
        pos->posx+=10;
        printf("%d", pos->posx );
    }

    else if (input->up == 1)
    {
        pos->posx-=10;
    }

    else if (input->right == 1)
    {
        pos->posy+=10;
    }
    
    else if (input->left == 1)
    {
        pos->posy+=10;
    }
}
}


// int LargeurMap=640;
// int HauteurMap=384;
// int x=0;
// int y=1;
// int CoordonneesPerso={LargeurMap/2;HauteurMap/2};

// a = _getch();

// switch(a)
//     {
//     case 'z':
//         CoordonneesPerso[y]=CoordonneesPerso[y]-5;
//         break;
//     case 'q':
//         CoordonneesPerso[x]=CoordonneesPerso[x]-5;
//         break;
//     case 's':
//         CoordonneesPerso[y]=CoordonneesPerso[y]+5;
//         break;
//     case 'd':
//         CoordonneesPerso[x]=CoordonneesPerso[x]+5;
//         break;
// }