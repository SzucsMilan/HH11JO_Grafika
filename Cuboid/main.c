#include "cuboid.h"

#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
	Cuboid cuboid;
	double volume;
	double surface;
	double x,y,z;
	bool tartalmaz;

	set_size(&cuboid,x,y,z);
	volume = calc_volume(&cuboid);
    surface = calc_surface(&cuboid);
    tartalmaz = check_square(&cuboid);

	printf("Teglatest terfogata: %lf\n", volume);
	printf("Teglatest felszine: %lf\n", surface);

	if(tartalmaz == true)
    {
        printf("Van negyzet alaku lapja.");
    }
    else
    {
        printf("Nincs negyzet alaku lapja.");

    }

	return 0;
}
