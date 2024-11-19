#version 450 core
layout(location = 0) out vec4 FragColor;
layout(binding = 0) uniform sampler2D u_tex0;
uniform vec2 u_resolution;
uniform vec2 u_tex0Resolution;

void main() {
    float screenAspect = u_resolution.x / u_resolution.y;
    float videoAspect = u_tex0Resolution.x / u_tex0Resolution.y;
    vec2 uv = gl_FragCoord.xy / u_resolution;
    vec2 center = vec2(0.5, 0.5);
    vec2 centered_uv = uv - center;
    centered_uv.x *= screenAspect;
    float dist = length(centered_uv);
    float radius = 0.4;
    float circle = 1.0 - smoothstep(radius - 0.01, radius, dist);
    vec2 video_uv = uv - center;
    float scale = max(1.0 / videoAspect, 1.0) * 1.25;
    video_uv *= scale;
    video_uv += center;
    vec4 videoColor = texture(u_tex0, video_uv);
    FragColor = vec4(videoColor.rgb, circle * videoColor.a);
}
