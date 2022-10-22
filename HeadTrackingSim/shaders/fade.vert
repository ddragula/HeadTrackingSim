#version 460 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 tcs;

uniform mat4 vp;
uniform mat4 model;

out vec2 fragCoord;

void main()
{
	fragCoord = tcs;
	gl_Position = vp * model * vec4(pos, 1.0);
}