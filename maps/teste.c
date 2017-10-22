#include<stdlib.h>
#include<stdio.h>
#include<time.h>



#define MAPAX 200
#define MAPAY 100

typedef struct {
	char c[MAPAY][MAPAX];
	int alt;
	int lar;
} MAPA;

typedef struct {
	int x;
	int y;
	char newChar;
} CHANGE;

void clampPosition(int* x, int* y, int maxX, int maxY){
   if(*x > maxX) *x = maxX;
   if(*x < 0) *x = 0;
   if(*y > maxY) *y = maxY;
   if(*y < 0) *y = 0;
}

void go_to(int* x, int* y){
   int newX, newY;
   scanf_s("%d%d", &newX, &newY);
   *x = newX;
   *y = newY;
}

int main(){
   MAPA mapa;
   MAPA oldScreen;
   int aux, aux1;
   int monsterX, monsterY;
 
   int heroX = MAPAX/2, heroY = MAPAY/2;
   
   mapa.lar = MAPAX;
   mapa.alt = MAPAY;
   oldScreen.lar = MAPAX;
   oldScreen.alt = MAPAY;
   for (size_t i = 0; i < MAPAY; i++)
   {
	   for (size_t j = 0; j < MAPAX; j++)
	   {
		   mapa.c[i][j] = '.';
	   }

   }
   mapa_copy(&oldScreen, &mapa);

   monsterX = heroX + rand()%10 + 3;
   monsterY = heroY + rand()%10 + 3;
   mapa.c[heroY][heroX] = 'H';
   while(1){
      char command;
      drawScreen(&mapa, &oldScreen, heroX,heroY);

      scanf_s("%c",&command);

      mapa.c[heroY][heroX] = ' ';

      if(command == 'w'){
         heroY--;
      }
      else if(command == 'a'){
         heroX--;
      }
      else if(command == 's'){
         heroY++;
      }
      else if(command == 'd'){
         heroX++;
      }
      else if(command == 'g'){
         go_to(&heroX, &heroY);
      }
      clampPosition(&heroX,&heroY, MAPAX-1, MAPAY-1);
      mapa.c[heroY][heroX] = 'H';

      mapa.c[monsterY][monsterX] = ' ';
      monsterX += rand()%3 - 1;
      monsterY += rand()%3 - 1;
      mapa.c[monsterY][monsterX] = 'T';
   }
}
