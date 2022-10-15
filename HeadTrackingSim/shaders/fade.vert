#version 460 core

layout (location = 0) in vec3 aPos;

out vec2 fragCoord;

void main()
{
	fragCoord = vec2((aPos.x + 1.0f) / 2.0f * 800, (aPos.y + 1.0f) / 2.0f * 600);
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}