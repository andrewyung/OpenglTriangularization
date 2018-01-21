#pragma once
#include <vector>

#include "Vertex.h"
#include "WindowCanvas.h"

class Model
{
public:
	Model(std::vector<Vertex> &vertexData, std::vector<int> &indexData) :
		vertexData(vertexData), indexData(indexData) {};

	std::vector<Vertex> vertexData;
	std::vector<int> indexData;

	GLuint shader;

	void scale(glm::vec3 scale)
	{
		if (vaoInfo != nullptr)
		{
			vaoInfo->transformation = glm::scale(vaoInfo->transformation, scale);
		}
	}

	void translate(glm::vec3 translateVector)
	{
		if (vaoInfo != nullptr)
		{
			vaoInfo->transformation = glm::translate(vaoInfo->transformation, translateVector);
		}
	}
	void translate(glm::vec3 translateVector, bool localSpace)
	{
		if (vaoInfo != nullptr)
		{
			if (!localSpace)
			{
				vaoInfo->transformation = glm::translate(glm::mat4(), translateVector) * vaoInfo->transformation;
			}
			else
			{
				vaoInfo->transformation = glm::translate(vaoInfo->transformation, translateVector);
			}
		}
	}

	void rotate(float angle, glm::vec3 axis)
	{
		if (vaoInfo != nullptr)
		{
			vaoInfo->transformation = glm::rotate(vaoInfo->transformation, glm::radians(angle), axis);
		}
	}
	
private:
	//Information used by WindowCanvas to manage Model
	GLsizeiptr vertexDataOffset = -1;
	GLsizeiptr indexDataOffset = -1;
	VAOInfo *vaoInfo;

	void setVertexBufferAndArrayData(GLsizeiptr vertexDataOffset, GLsizeiptr indexDataOffset)
	{
		this->vertexDataOffset = vertexDataOffset;
		this->indexDataOffset = indexDataOffset;
	}

	void setVAOInfo(VAOInfo &index)
	{
		this->vaoInfo = &index;
	}

	friend class WindowCanvas;
};

