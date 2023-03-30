#version 460 core

in vec2 fragCoord;

out vec4 FragColor;

vec3 hsv2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

float convCheck(vec2 p)
{
    int iterations = 50;
    int i = 0;
    
    vec2 z0 = vec2(0.0, 0.0);
    
    while (i < iterations)
    {
        vec2 z1 = vec2(z0.x * z0.x - z0.y * z0.y, 2.0 * z0.x * z0.y) + p;
        
        if (length(z1) >= 2.0)
        {
            break;
        }
        
        z0 = z1;
        i++;
    }
    
    return float(i) / float(iterations - 1);
}

void main()
{
    vec2 zmin = vec2(-2.0, -1.5);
    vec2 zmax = vec2(1.0, 1.5);

    vec2 uv = fragCoord;
    
    float zx = zmin.x + uv.x * (zmax.x - zmin.x);
    float zy = zmin.y + uv.y * (zmax.y - zmin.y);
    
    float c = convCheck(vec2(zx, zy));
    
    float val = 0.0;
    if (c < 0.999999)
        val = 1.0;

    FragColor = vec4(hsv2rgb(vec3(1.0 - c, 1.0, val)), 1.0);
}