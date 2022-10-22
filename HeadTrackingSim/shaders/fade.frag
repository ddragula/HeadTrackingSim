#version 460 core

in vec2 fragCoord;

out vec4 FragColor;

void main()
{
    FragColor = vec4(fragCoord.x, fragCoord.y, 0, 1.0f);
}