#include "scene.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene, Objects* objects)
{
    glClearColor(0.0, 0.0, 1.0, 0.0);
	
	scene->fan_rotation = 0;
	scene->lighting_level = 0.7;
	
	init_vehicles(&(scene->vehicles));
	 
	load_model(&(scene->grass), "assets/models/grass.obj");
    scene->grass_texture_id = load_texture("assets/textures/grass.jpg");
	
	load_model(&(objects->road), "assets/models/road.obj");
    objects->road_texture_id = load_texture("assets/textures/originall.png");
	
    load_model(&(scene->tree), "assets/models/palmafa.obj");
    scene->tree_texture_id = load_texture("assets/textures/palmafa.jpg");
	
	load_model(&(scene->fronttree), "assets/models/fronttree.obj");
    scene->fronttree_texture_id = load_texture("assets/textures/fronttree.jpg");
	
	load_model(&(scene->barrier), "assets/models/container.obj");
    scene->barrier_texture_id = load_texture("assets/textures/container.jpg");

    load_model(&(scene->building), "assets/models/building.obj");
    scene->building_texture_id = load_texture("assets/textures/building.jpg");

    load_model(&(scene->fence), "assets/models/fence.obj");
    scene->fence_texture_id = load_texture("assets/textures/fence.jpg");

    load_model(&(scene->roundhedge), "assets/models/roundhedge.obj");
    scene->roundhedge_texture_id = load_texture("assets/textures/roundhedge.jpg");

    scene->material.ambient.red = 0.0;
    scene->material.ambient.green = 0.0;
    scene->material.ambient.blue = 0.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 11.0;
	
	scene->fogColor[0]=0.5f;
	scene->fogColor[1]=0.5f;
	scene->fogColor[2]=0.5f;
	scene->fogColor[3]=1.0f;
	
	glEnable(GL_FOG);
	glFogf(GL_FOG_DENSITY, scene->fog_level);
	glFogfv(GL_FOG_COLOR, scene->fogColor);
	
	set_lighting(scene->lighting_level);
}

void set_lighting(float lighting_level)
{
    float ambient_light[] = { lighting_level, lighting_level, lighting_level, 1.0f };
    float diffuse_light[] = { lighting_level, lighting_level, lighting_level, 1.0f };
    float specular_light[] = { lighting_level, lighting_level, lighting_level, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene* scene, double times)
{

}


void render_scene(const Scene* scene, const Objects* objects)
{

	set_material(&(scene->material));
    set_lighting(scene->lighting_level);
    glPushMatrix();

    float fronttreeSpacing = 8.0;
    for (int i = -3; i < 5; i++) {
        glPushMatrix();
        glScalef(0.7,0.7,0.7);
        glTranslatef(i * fronttreeSpacing, -1.5, 0.0);
        glBindTexture(GL_TEXTURE_2D, scene->fronttree_texture_id);
        draw_model(&(scene->fronttree));
        glPopMatrix();
    }
    glPopMatrix();	
	
	glPushMatrix();
    glTranslatef(scene->vehicles.position.x, scene->vehicles.position.y, scene->vehicles.position.z);
    glScalef(1,1,1);
    glRotatef(180,0,0,1);
    glBindTexture(GL_TEXTURE_2D, scene->vehicles.vehicles_texture_id);
	draw_model(&(scene->vehicles.model));
    glPopMatrix();

	glPushMatrix();
    float treeSpacing = 15.0;  
    for (int i = 0; i < 3; i++) {
        glPushMatrix();
        glScalef(0.3, 0.3, 0.3);
        glTranslatef(i * treeSpacing, 15.0, 0.0);
        glBindTexture(GL_TEXTURE_2D, scene->tree_texture_id);
        draw_model(&(scene->tree));
        glPopMatrix();
    }
    
    float roundhedgeSpacing = 8.0;  
    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glScalef(0.3, 0.3, 0.3);
        glTranslatef(i * roundhedgeSpacing, 10.0, 0.0);
        glBindTexture(GL_TEXTURE_2D, scene->roundhedge_texture_id);
        draw_model(&(scene->roundhedge));
        glPopMatrix();
    }

    for (int i = -3; i < 3; i++) {
        glPushMatrix();
        glScalef(0.3, 0.3, 0.3);
        glTranslatef(i * -treeSpacing+1, -11.0, 0.0);
        glBindTexture(GL_TEXTURE_2D, scene->tree_texture_id);
        draw_model(&(scene->tree));
        glPopMatrix();
    }
    glPopMatrix();	
        
    glPushMatrix();
    glTranslatef(0, 1, -0.03);
    glScalef(0.3, 0.3, 0.3);

    for (int i = 0; i < 20; i++) {
        glPushMatrix();
        glTranslatef(i * 5, 0.0, 0.0); 
        glBindTexture(GL_TEXTURE_2D, objects->road_texture_id);
        draw_model(&(objects->road));
        glPopMatrix();
    }
    for (int i = 0; i < 20; i++) {
        glPushMatrix();
        glTranslatef(-i * 5, 0.0, 0.0);
        glBindTexture(GL_TEXTURE_2D, objects->road_texture_id);
        draw_model(&(objects->road));
        glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-26,-10,0);
    glScalef(0.01, 0.01, 0.001);

    float offset = 200.0;
    float startX = -offset;
    float startY = -offset;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 28; j++) {
            glPushMatrix();
            glTranslatef(startX + j * offset, startY + i * offset, -10);
            glBindTexture(GL_TEXTURE_2D, scene->grass_texture_id);
            draw_model(&(scene->grass));
            glPopMatrix();
        }
    }
    glPopMatrix();

        
    glPushMatrix();
    int i=0;
    for(i=0;i<2;i++){
        glPushMatrix();
        glTranslatef(14, i+0.5, 0); 
        glScalef(0.6, 0.6, 0.6);
        glBindTexture(GL_TEXTURE_2D, scene->barrier_texture_id);
        draw_model(&(scene->barrier));
        glPopMatrix();
    }
    glPopMatrix();


    glPushMatrix();
    i=0;
    for(i=0;i<2;i++){
        glPushMatrix();
        glTranslatef(-12.5, i+0.5, 0);
        glScalef(0.6, 0.6, 0.6);
        glBindTexture(GL_TEXTURE_2D, scene->barrier_texture_id);
        draw_model(&(scene->barrier));
        glPopMatrix();
    }
    glPopMatrix();	

        glPushMatrix();

    float buildingSpacing = 6.5;    
    i=0;
    for(i=0;i<2;i++){
        glPushMatrix();
        glTranslatef(i*buildingSpacing-9.5, 5.0, 0.0);
        glScalef(0.6, 0.6, 0.6);
        glBindTexture(GL_TEXTURE_2D, scene->building_texture_id);
        draw_model(&(scene->building));
        glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix();

    float fenceSpacing = 1.2;
    i=0;
    for(i=0;i<3;i++){
        glPushMatrix();
        glTranslatef(i*fenceSpacing-7.5, 4.0, 0.0);
        glScalef(0.6, 0.6, 0.6);
        glBindTexture(GL_TEXTURE_2D, scene->fence_texture_id);
        draw_model(&(scene->fence));
        glPopMatrix();
    }
    glPopMatrix();

}

