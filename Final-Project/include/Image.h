#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include "Geometry.h"
#ifndef __IMAGE_H__
#define __IMAGE_H__

class Image{
public:
	unsigned int fbo; // framebuffer object
	unsigned int tbo; // texture buffer object
	int width;
	int height;
	std::vector<glm::vec3> pixels;
	void init(int width, int height);
	void draw( void );
};


#endif