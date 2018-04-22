#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DELTA_T 0.01

struct TCoord {
    double x;
    double y;
};

typedef struct TCoord Coord;

void actualizar(Coord *pos, Coord *vel, Coord acc){
    vel->x += acc.x * DELTA_T;
    vel->y += acc.y * DELTA_T;
    pos->x += vel->x * DELTA_T;
    pos->y += vel->y * DELTA_T;
}

void pintar(Coord pos, Coord vel){
    printf("%.2lfm(%.2lfm/s)\t%.2lfm(%.2lfm/s)\n", pos.x, vel.x, pos.y, vel.y);
}

int main(){
    struct TCoord pos = { 1., 1.  },
                  vel = { 40.2, 50.  },
                  acc = { 0., -40.80665  };


    do{
        actualizar(&pos, &vel, acc);
        pintar(pos, vel);
        usleep(100000);
    }
    while(pos.y >= 0);

    if (pos.x>99.9 and pos.x<101.00)
    {
    printf("Jugador 1 Gana\n");
    }

    return EXIT_SUCCESS;
}

