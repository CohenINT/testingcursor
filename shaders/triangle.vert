#version 450

layout(location = 0) in vec2 inPosition;
layout(location = 1) in vec3 inColor;

layout(location = 0) out vec3 fragColor;

void main() {
    // Transform from screen coordinates (0,0 at top-left) to clip space (-1 to 1)
    vec2 clipPos = vec2(
        (inPosition.x / 800.0) * 2.0 - 1.0,  // Assuming 800 is window width
        -((inPosition.y / 600.0) * 2.0 - 1.0) // Assuming 600 is window height, flip Y
    );
    gl_Position = vec4(clipPos, 0.0, 1.0);
    fragColor = inColor;
} 