#version 450
layout(location = 0) out vec4 fragColor;

layout(binding = 0) uniform sampler2D source;

layout(set = 0, binding = 1) uniform UniformBlock {
    vec4 rectColor;
    float blurRadius;
} ubo;

layout(location = 0) in vec2 qt_TexCoord0;

void main() {
    vec2 texCoord = qt_TexCoord0;
    vec4 sum = vec4(0.0);

    for (int x = -4; x <= 4; x++) {
        for (int y = -4; y <= 4; y++) {
            sum += texture(source, texCoord + vec2(x, y) * 0.002 * ubo.blurRadius);
        }
    }
    sum /= 81.0;
    fragColor = mix(sum, ubo.rectColor, ubo.rectColor.a);
}
