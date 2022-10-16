#version 460 core

layout (location = 0) in vec3 aPos;

out vec2 fragCoord;

void main()
{
	fragCoord = vec2((aPos.x + 1.0f) / 2.0f, (aPos.y + 1.0f) / 2.0f);
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}