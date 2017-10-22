#include"list.c"
#include<string.h>
#include<stdlib.h>

#define DFT "\e[m"
#define RED "\e[1;31m"
#define GREEN "\e[1;32m"
#define YELLOW "\e[1;33m"
#define BLUE "\e[1;34m"
#define MAGENTA "\e[1;35m"
#define CYAN "\e[1;36m"

#define BKGRED "\e[1;41m"
#define BKGGREEN "\e[1;42m"
#define BKGYELLOW "\e[1;43m"
#define BKGBLUE "\e[1;44m"
#define BKGMAGENTA "\e[1;45m"
#define BKGCYAN "\e[1;46m"

#define MAPAX 200
#define MAPAY 100

typedef struct{
   char c[MAPAY][MAPAX];
   int alt;
   int lar;
} MAPA;

typedef struct{
   int x;
   int y;
   char newChar;
} CHANGE;



void mem_zero(void* pointer, int size){
   for(size -= 1;size >= 0; size --)
      ((char*)pointer)[size] = 0;
}

void printMap(MAPA* mapa){
   int aux, aux1;
   for(aux = 0;aux < mapa->alt;aux ++){
      for(aux1 = 0;aux1 < mapa->lar; aux1 ++){
         printf("%c",mapa->c[aux][aux1]);
      }
      printf("\n");
   }
}

void mapa_create(MAPA *newMap, int lar, int alt){
   int aux, aux1;

   newMap->lar = lar;
   newMap->alt = alt;
}

/*CHANGE* change_create(){
   CHANGE* change;
   change = (CHANGE*)malloc(sizeof(CHANGE));
   mem_zero(change, sizeof(CHANGE));
}*/

/*void map_set(MAPA* map, int x, int y, char newChar){
   CHANGE* newChange;
   newChange = change_create();

   newChange->x = x;
   newChange->y = y;
   newChange->newChar = newChar;

   list_push(map->modifications, newChange);
   map->c[y][x] = newChar;
}*/

/*void map_updateModifications(MAPA* map){
   while(map->modifications->size > 0){
      CHANGE* change = list_shift(map->modifications);
      //set_cursor(change->x, change->y);
      printf("%c", change->newChar);
   }
}*/

MAPA* generateScreen(MAPA* map, MAPA* newMap, int player_x, int player_y){
  
   int aux, aux1;
   int offsetLeft = 0, offsetTop = 0;
   int offsetRight = 0, offsetBottom = 0;
   int terminal_x = 140;//get_terminal_x();
   int terminal_y = 40;//get_terminal_y();
  
   int map_initial_x;
   int map_initial_y;
   int map_final_x;
   int map_final_y;

   mapa_create(newMap, terminal_x, terminal_y);

   map_initial_x = player_x - terminal_x/2;
   map_initial_y = player_y - terminal_y/2;
   map_final_x = player_x + terminal_x/2;
   map_final_y = player_y + terminal_y/2;

   if(map_initial_x < 0){
      offsetLeft = map_initial_x * -1;
      map_initial_x = 0;
   }
   if(map_initial_y < 0){
      offsetTop = map_initial_y * -1;
      map_initial_y = 0;
   }
   if(map_final_x > map->lar){
      offsetRight = map_final_x - map->lar;
      map_final_x = map->lar;
   }
   if(map_final_y > map->alt){
      offsetBottom = map_final_y - map->alt;
      map_final_y = map->alt;
   }


   for(aux = 0;aux < offsetTop;aux ++){
      for(aux1 = 0;aux1 < newMap->lar;aux1 ++){
         newMap->c[aux][aux1] = '#';
      }
   }
   for(aux = map_initial_y; aux < map_final_y; aux ++){
      for(aux1 = 0;aux1 < offsetLeft;aux1 ++){
         newMap->c[aux - map_initial_y + offsetTop][aux1 - map_initial_x] = '#';
      }
      for(aux1 = map_initial_x; aux1 < map_final_x; aux1 ++){
         newMap->c[aux - map_initial_y + offsetTop][aux1 - map_initial_x + offsetLeft] = map->c[aux][aux1];
      }
      for(aux1 = 0;aux1 < offsetRight;aux1 ++){
         newMap->c[aux - map_initial_y + offsetTop][aux1 + map_final_x - map_initial_x + offsetLeft] = '.';
      }
   }
   for(aux = 0;aux < offsetBottom; aux ++){
      for(aux1 = 0;aux1 < newMap->lar;aux1 ++){
         newMap->c[aux + offsetTop + map_final_y - map_initial_y][aux1] = '#';
      }
   }
   return &newMap;
}

void mapa_copy(MAPA* newMap, MAPA* map){
	for (size_t i = 0; i < map->alt; i++)
	{
		for (size_t j = 0; j < map->lar; j++)
		{
			newMap->c[i][j] = map->c[i][j] + 1;
		}
	}

   newMap->lar = map->lar;
   newMap->alt = map->alt;
}

void set_cursor(int x, int y){
   //printf("\033[%d;%dH", y+1, x+1);
}

void drawScreen(MAPA* map, MAPA* oldScreen, int playerX, int playerY){
	MAPA newScreen;
	newScreen.lar = MAPAX;
	newScreen.alt = MAPAY;
	generateScreen(map, &newScreen, playerX, playerY);

   int x, y;
   for(y = 0;y < newScreen.alt; y ++){
      for(x = 0;x < newScreen.lar; x++){
         if(newScreen.c[y][x] != oldScreen->c[y][x]){
            set_cursor(x,y);
            printf("%c",newScreen.c[y][x]);
         }
      }
   }
   mapa_copy(oldScreen, &newScreen);
}
