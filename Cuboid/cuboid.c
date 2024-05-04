#include "cuboid.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void set_size(Cuboid* cuboid, double x, double y, double z)
{

    double num;
    bool ok;
    char karakter;
    int i = 0;

    do
    {
    ok = true;
    printf("Add meg egy teglatest oldalat: ");


    if(scanf("%lf", &num) == 1)
    {
        if(num > 0.0)
        {
        ok = true;
        printf("Sikeres oldal rogzites\n");
        if(i == 0) { cuboid->x = num; }
        if(i == 1) { cuboid->y = num; }
        if(i == 2) { cuboid->z = num; }

        i++;
        }
        else
        {
            printf("0-tol nagyobb szamot adj meg!\n");
            ok = false;
        }

    }
    else
    {
        ok = false;
        printf("Sikertelen parameter\n");
    }while((karakter=getchar())!='\n');


    }while(!ok || i != 3);

}

double calc_volume(const Cuboid* cuboid)
{
	double volume = cuboid->x * cuboid->y * cuboid->z;
	return volume;
}


double calc_surface(const Cuboid* cuboid)
{
	double surface = 2 * ( cuboid->x * cuboid->y + cuboid->x * cuboid->z + cuboid->y * cuboid->z);
	return surface;
}

bool check_square(const Cuboid* cuboid)
{
    bool tartalmaz;
    if(cuboid->x == cuboid->y || cuboid->x == cuboid->z || cuboid->y == cuboid->z)
    {
        tartalmaz = true;
    }
    else
    {
        tartalmaz = false;
    }

    return tartalmaz;
}


