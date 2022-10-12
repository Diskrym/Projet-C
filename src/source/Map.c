
#include "../header/proto.h"
 
 
Map map;
 
 
void initMaps(void)
{
// Charge l'image du fond (background)
map.background = loadImage("src/Graphics/background.png");
//On initialise le timer
map.mapTimer = TIME_BETWEEN_2_FRAMES * 3;
map.tileSetNumber = 0;
}
 
 
SDL_Texture *getBackground(void)
{
return map.background;
}
 
 
void cleanMaps(void)
{
// Libère la texture du background
if (map.background != NULL)
{
SDL_DestroyTexture(map.background);
map.background = NULL;
}
 
}


void loadMap(char *name)
{
int x, y;
FILE *fp;
int err;
 
//Ouvre le fichier en lecture (renvoie une erreur s'il n'existe pas)
if ((err = fopen_s(&fp, name, "rb")) != 0)
    {
    printf("Le fichier map n'a pas pu etre ouvert.\n");
    exit(1);
    }
 
/* Lit les données du fichier dans la map */
 
/* Lit les coordonnées de début du joueur */
fscanf_s(fp, "%d", &map.beginx);
fscanf_s(fp, "%d", &map.beginy);
 
/* Read the number of the tileset */
fscanf_s(fp, "%d", &map.tilesetAffiche);
 
map.maxX = map.maxY = 0;
 
 
for (y = 0; y < MAX_MAP_Y; y++)
    {
    for (x = 0; x < MAX_MAP_X; x++)
        {
        /* On lit le numéro de la tile et on le copie dans notre tableau */
        fscanf_s(fp, "%d", &map.tile[y][x]);
 
        /* Permet de déterminer la taille de la map (voir plus bas) */
        if (map.tile[y][x] > 0)
            {
            if (x > map.maxX)
                {
                map.maxX = x;
                }
 
            if (y > map.maxY)
                {
                map.maxY = y;
                }
            }
        }
    }
 
//Deuxième couche de tiles
for (y = 0; y < MAX_MAP_Y; y++)
    {
    for (x = 0; x < MAX_MAP_X; x++)
        {
        /* On lit le numéro de la tile et on le copie dans notre tableau */
        fscanf_s(fp, "%d", &map.tile2[y][x]);
        }
    }
 
//Troisième couche de tiles
for (y = 0; y < MAX_MAP_Y; y++)
    {
    for (x = 0; x < MAX_MAP_X; x++)
        {
        /* On lit le numéro de la tile et on le copie dans notre tableau */
        fscanf_s(fp, "%d", &map.tile3[y][x]);
        }
    }
 
/* maxX et maxY sont les coordonnées de fin de la map.
On les trouve dès qu'il n'y a plus que des zéros à la suite.
Comme ça, on peut faire des maps de tailles différentes avec la même
structure de fichier. */
map.maxX = (map.maxX + 1) * TILE_SIZE;
map.maxY = (map.maxY + 1) * TILE_SIZE;
 
/* Et on referme le fichier */
fclose(fp);
 
}