#include<stdlib.h>
#include<stdio.h>
#include "jean.c"
#include<time.h>

#define MAPAX 200
#define MAPAY 100

void clampPosition(int* x, int* y, int maxX, int maxY){
   if(*x > maxX) *x = maxX;
   if(*x < 0) *x = 0;
   if(*y > maxY) *y = maxY;
   if(*y < 0) *y = 0;
}

void go_to(int* x, int* y){
   int newX, newY;
   scanf("%d%d", &newX, &newY);
   *x = newX;
   *y = newY;
}

int main(){
   MAPA* mapa;
   int aux, aux1;
   int monsterX, monsterY;
 
   int heroX = MAPAX/2, heroY = MAPAY/2;

   mapa = mapa_create(MAPAX, MAPAY);
   oldScreen = mapa_create(MAPAX, MAPAY);

   for(aux = 0;aux < mapa->alt; aux ++){
      for(aux1 = 0;aux1 < mapa->lar;aux1 ++){
         mapa->c[aux][aux1] = '.';// + rand()%2;
      }
   }

   mapa_copy(oldScreen, mapa);

   
   monsterX = heroX + rand()%10 + 3;
   monsterY = heroY + rand()%10 + 3;
   mapa->c[heroY][heroX] = 'H';
   while(1){
      char command;
      draw(mapa, heroX,heroY);

      scanf("%c",&command);

      mapa->c[heroY][heroX] = ' ';

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
      mapa->c[heroY][heroX] = 'H';

      mapa->c[monsterY][monsterX] = ' ';
      monsterX += rand()%3 - 1;
      monsterY += rand()%3 - 1;
      mapa->c[monsterY][monsterX] = 'T';
   }
}
