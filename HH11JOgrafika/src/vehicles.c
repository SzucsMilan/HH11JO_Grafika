#include "vehicles.h"

void init_vehicles(Vehicles *vehicles)
{
    load_model(&(vehicles->model), "assets/models/taxi.obj");
    vehicles->vehicles_texture_id = load_texture("assets/textures/taxi.jpg");

    vehicles->position.x = 3.0;
    vehicles->position.y = 0.3;
    vehicles->position.z = 0.1;

    vehicles->speed.x = 0.0;
    vehicles->speed.y = 0.0;
    vehicles->speed.z = 0.0;
   
    vehicles->rotation.x = 0.0;
    vehicles->rotation.y = 0.0;
    vehicles->rotation.z = 0.0;
    vehicles->angle = 0.0;
  
}



void set_vehicles_position(Vehicles *vehicles, vec3 newPosition)
{
    vehicles->position.x += newPosition.x;
    vehicles->position.y += newPosition.y;
    vehicles->position.z += newPosition.z;
}

void set_vehicles_rotation_y (Vehicles *vehicles, double rotation)
{
    vehicles->rotation.y = rotation;
}

void set_vehicles_rotation_x (Vehicles *vehicles, double rotation)
{
    vehicles->rotation.x = rotation;
}
void set_vehicles_rotation_z (Vehicles *vehicles, double rotation)
{
    vehicles->rotation.z = rotation;
}

void set_vehicles_angle (Vehicles *vehicles, double angle)
{
    vehicles->angle = angle;
}


void set_vehicles_speed_y(Vehicles *vehicles, double speed)
{
    vehicles->speed.y = -speed;
}

void set_vehicles_speed_x(Vehicles *vehicles, double speed)
{
    vehicles->speed.x = speed;
}

void set_vehicles_speed_z(Vehicles *vehicles, double speed)
{
    vehicles->speed.z = speed;
}

void move_vehicles(Vehicles *vehicles, double time)
{
    vehicles->position.x += vehicles->speed.x * time;
    vehicles->position.y += vehicles->speed.y * time;
    vehicles->position.z += vehicles->speed.z * time;

}


