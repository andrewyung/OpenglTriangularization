#pragma once
#include <iostream>
#include <string>

#include <stdlib.h> 
#include <GL\glew.h>
#include <GL\freeglut.h>

#include "ShaderLoader.h"
class Model;
struct VAOInfo
{
	VAOInfo(GLuint vaoID, GLuint vboID, GLuint eboID, GLuint shaderID, int indexDataSize, int vertexDataSize, int nextAvailableVertexIndex) :
		vertexArrayID(vaoID), vertexBufferID(vboID), indexBufferID(eboID), shaderID(shaderID), indexDataByteSize(indexDataSize), vertexDataByteSize(vertexDataSize), nextAvailableVertexIndex(nextAvailableVertexIndex) {};

	bool instanced = false;
	GLuint vertexArrayID;
	GLuint vertexBufferID;
	GLuint indexBufferID;
	GLuint shaderID;

	//in bytes
	int vertexDataByteSize;
	int indexDataByteSize;
	int nextAvailableVertexIndex;

	glm::mat4 transformation = glm::mat4();
};

class WindowCanvas
{
public:
	static void initializeWindow(int argc, char ** argv);
	static void start(void(*gameLoopCallback)(), void(*gameInitializeCallback)());

	static void addModel(Model &model, bool forceNewVAO);
	static void setDefaultShader(GLuint shader);

	static int frames;
	static float deltaFrameTime;

	~WindowCanvas();
private:
	static GLuint defaultShader;

};