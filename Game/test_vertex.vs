#version 430

in vec3 position;
in vec3 vertexColor;

uniform mat4 transformMatrix;

out vec3 color;

void main()
{
	gl_Position = transformMatrix * vec4(position, 1.0);
	color = vertexColor;
}