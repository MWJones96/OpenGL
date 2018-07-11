#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 vertexNormal;

out vec3 normal0;

uniform mat4 MVP;

void main()
{
	gl_Position = MVP * vec4(position, 1.0);
	normal0 = (MVP * vec4(vertexNormal, 1.0)).xyz;
}