#version 330

in vec3 normal0;

void main()
{
	gl_FragColor = vec4(normal0, 1.0);
}