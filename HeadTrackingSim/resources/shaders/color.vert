#version 460 core

layout (location = 0) in vec3 pos;

uniform mat4 vp;
uniform mat4 model;
uniform vec3 color;

out vec3 Color;

void main()
{
	Color = color;
	gl_Position = vp * model * vec4(pos, 1.0);
}