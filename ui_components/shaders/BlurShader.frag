#version 450 core

layout(location = 0) in vec2 v_texCoord;
layout(location = 0) out vec4 FragColor;

layout(binding = 1) uniform sampler2D u_texture;

layout(std140, binding = 0) uniform buf {
    float u_blurRadius;
    vec2 u_textureSize;
} ubuf;

void main() {
    vec4 color = vec4(0.0);
    float total = 0.0;

    int radius = int(ubuf.u_blurRadius);
    for (int x = -radius; x <= radius; x++) {
        for (int y = -radius; y <= radius; y++) {
            vec2 offset = vec2(float(x), float(y)) / ubuf.u_textureSize;
            color += texture(u_texture, v_texCoord + offset);
            total += 1.0;
        }
    }

    FragColor = color / total;
}
