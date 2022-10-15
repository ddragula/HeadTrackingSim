#version 460 core

in vec2 fragCoord;

out vec4 FragColor;

void main()
{
    FragColor = vec4(fragCoord.x, fragCoord.x, fragCoord.x, 1.0f);
}