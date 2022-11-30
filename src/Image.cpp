#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <Image.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GL/glut.h>
using namespace glm;

void Image::init(int width, int height){
	int width = width;
	int height = height;
	std::vector<glm::vec3> pixels;
	pixels.resize(width * height);

	unsigned int fbo; // framebuffer object
	unsigned int tbo; // texture buffer object

	glGenFramebuffers(1, &fbo);
	glGenTextures(1, &tbo);
}
void Image::draw() {
	glBindTexture(GL_TEXTURE_2D, tbo);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, // load texture
		0, GL_RGB, GL_FLOAT, &pixels[0][0]);
	glBindFramebuffer(GL_READ_FRAMEBUFFER, fbo);
	glFramebufferTexture2D(GL_READ_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
		GL_TEXTURE_2D, tbo, 0);// attach texture and the read frame
	//glBindFramebuffer(GL_WRITE_FRAMEBUFFER, 0); // if not already so
	glBlitFramebuffer(0, 0, width, height, 0, 0, width, height, GL_COLOR_BUFFER_BIT,
		GL_NEAREST); // copy framebuffer from read to write
}
