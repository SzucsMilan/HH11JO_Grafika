#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "vehicles.h"


#include <obj/model.h>

typedef struct Scene
{
    Vehicles vehicles;
	
	Model grass;
	Model fronttree;
	Model tree;
	Model building;
	Model fence;
	Model roundhedge;
	
	GLuint barrier_texture_id;
	
	Model barrier;
	
	float lighting_level;
	float fog_level;
	int fan_rotation;
    Material material;
	
	GLuint fan_texture_id;
	GLuint grass_texture_id;
	GLuint fronttree_texture_id;
	GLuint tree_texture_id;
	GLuint building_texture_id;
	GLuint fence_texture_id;
	GLuint roundhedge_texture_id;
	
	GLfloat fogColor[4];

	
} Scene;

typedef struct Objects
{

	Model road;
	GLuint road_texture_id;

	
} Objects;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene, Objects* objects);


/**
 * Set the lighting of the scene.
 */
void set_lighting(float lighting_level);

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
void update_scene(Scene* scene, double time);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene, const Objects* objects);

/**
 * Draw the origin of the world coordinate system.
 */


#endif /* SCENE_H */
