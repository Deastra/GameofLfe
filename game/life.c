#include "life.h"

void reset(){
    printf("\033[0m");
}

int** initiateMap(){
    int **map=(int**)malloc(sizeof(int)*SIZE*SIZE);
    for(int i=0;i<SIZE;i++){
        map[i]=(int*)malloc(sizeof(int)*SIZE);
        for(int j=0;j<SIZE;j++){
            map[i][j]=0;
        }
    }
    return map;
}

void printMap(int** map){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(map[i][j]==0){
                printf("\033[0;31m%d ",map[i][j]);
            }else{
                printf("\033[0;32m%d ",map[i][j]);
            }

        }
        reset();
        printf("\n");
    }  
}

int** firstDay(){
    int** newmap=initiateMap();
    srand(time(NULL));
    int f=0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            f=rand()%2;
            newmap[i][j]=f;
        }
    }
    return newmap;
}

int ifAllDead(int** map){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(map[i][j]==1){return 0;}
        }
    }
    // puts("Everybody Dead :(");
    return 1;
}

int countNeighborsCircular(int **map,int x,int y){
    int n=0;
    int x1=x;
    int y1=y;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(x+i==SIZE){x1=0;}
            else if(x+i==-1){x1=SIZE-1;}
            else{x1=x+i;}
            if(y+j==SIZE){y1=0;}
            else if(y+j==-1){y1=SIZE;}
            else{y1=y+j;}
            if(map[x1][y1]==1){n++;}
        }
    }
    return n-map[x][y];
}

int countNeighbors(int** map,int x, int y){
    int n=0;

    if(x>0 && x<5 && y>0 && y<5){
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(map[x+i][y+j]==1){n++;}
            }
        }        
    }
    else{
        int i1= (x==0 ? 0 : -1);
        int j1= (y==0 ? 0 : -1);
        int i2= (x==SIZE-1 ? 0 : 1);
        int j2= (y==SIZE-1 ? 0 : 1);
        for(int i=i1;i<=i2;i++){
            for(int j=j1;j<=j2;j++){
                if(map[x+i][y+j]==1){n++;}
            }
        }
    }

    return n-map[x][y]; // substitute the value of the current cell, as it also counted in iterations
     
}

int getNextState(int** map,int x,int y,int cf){
    int n;
    if(cf){n=countNeighborsCircular(map,x,y);}
    else{n=countNeighbors(map,x,y);}
    
    if(n==3){ return 1; }         // no matter, next is always alive
    if(n==2){ return map[x][y];}  // keeps current state
    else{return 0;}

}

int** nextDay(int** map,int cf){
    int **newmap=initiateMap();
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            newmap[i][j]=getNextState(map,i,j,cf);
        }
    }
    free(map);
    return newmap;
}



int** lifeDay(int cf,int **map){
    // int** map=firstDay();
    // printMap(map);
    // int count=0;

    // while(count!=10){
        // printf("----------------- %d\n",count);
        sleep(1);
        map=nextDay(map,cf);
        // printMap(map);
        
    //         count++;
    // }
   
    // puts("---------------------------------");
    return map;
 
}
