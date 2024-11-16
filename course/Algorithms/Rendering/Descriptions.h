//
//  Rendering.h
//  Test2019
//
//  Created by Risukhin Denys on 3/10/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Descriptions_h
#define Descriptions_h

// 1. Rasterization
    This is the most common technique used in real-time rendering.
    It involves converting geometric primitives (like triangles) into pixels on the screen.

    // Pseudo code for rasterization
    for each triangle in scene:
        for each pixel in triangle's bounding box:
            if pixel is inside triangle:
                depth = interpolate_depth(pixel, triangle);
                if depth < depth_buffer[pixel]:
                    depth_buffer[pixel] = depth;
                    color = interpolate_color(pixel, triangle);
                    framebuffer[pixel] = color;

// 2. Ray Tracing
This technique simulates the way light rays interact with objects in a scene. It produces highly realistic images by tracing the path of rays as they bounce around the scene.

// Pseudo code for ray tracing
for each pixel in screen:
    ray = calculate_primary_ray(pixel);
    color = trace_ray(ray);
    framebuffer[pixel] = color;

Color trace_ray(Ray ray) {
    if (ray intersects with scene) {
        // Compute lighting, shadows, reflections, etc.
        return calculate_color_at_intersection(ray);
    } else {
        return background_color;
    }
}

// 3. Deferred(Отложенный) Rendering
Deferred rendering is a technique that defers the shading step until after rasterization. It involves rendering geometry into several buffers, such as a
    position buffer
    normal buffer
    color buffer
which are then used in a separate pass to calculate the final image.

// Pseudo code for deferred rendering
// First pass: Render geometry to G-buffer
for each object in scene:
    render_object_geometry_to_g_buffer(object);

// Second pass: Shading
for each pixel in screen:
    position = g_buffer_position[pixel];
    normal = g_buffer_normal[pixel];
    albedo = g_buffer_albedo[pixel];
    calculate_lighting(position, normal, albedo);

// 4. Forward Rendering
In contrast to deferred rendering, forward rendering calculates lighting and shading for each pixel during the rasterization step. It's simpler but can be less efficient for scenes with many lights.
s
// Pseudo code for forward rendering
for each pixel in screen:
    color = calculate_lighting_for_pixel(pixel);
    framebuffer[pixel] = color;

// 5. Global Illumination
Techniques like ambient occlusion, global illumination, and indirect lighting simulate the interaction of light with the environment to produce more realistic lighting effects.

Global illumination techniques like ambient occlusion and indirect lighting typically involve more complex algorithms and are often computed offline or using pre-computed data. Implementing these in real-time would require advanced techniques and optimizations.

// 6. Shadow Mapping
Shadow mapping is a technique used to simulate the shadows cast by objects in a scene. It involves rendering the scene from the perspective of the light source to create a depth map, which is then used to determine which areas are shadowed.

// Pseudo code for shadow mapping
// First pass: Render scene from light's perspective to depth map
render_scene_from_light();

// Second pass: Render scene from camera's perspective
for each pixel in screen:
    depth = calculate_depth_from_light(pixel);
    shadow = depth > depth_buffer[pixel] ? 1.0 : 0.0;
    color = calculate_lighting_with_shadows(pixel, shadow);
    framebuffer[pixel] = color;


// 7. Screen-Space Reflections (SSR)
SSR is a technique used to simulate reflections in real-time rendering. It involves tracing rays in screen space to determine what objects are reflected in a given pixel.

SSR involves tracing rays in screen space and is more complex to implement. Below is a simplified version:

// Pseudo code for screen-space reflections
for each pixel in screen:
    reflected_ray = calculate_reflected_ray(pixel);
    color = trace_ray(reflected_ray);
    framebuffer[pixel] = color;

// 8. Post-Processing Effects
Techniques like bloom, motion blur, depth of field, and HDR (High Dynamic Range) rendering are commonly used to enhance the final image quality.

Post-processing effects are typically applied after rendering the scene. Here's an example of applying a simple blur effect:

// Pseudo code for post-processing blur effect
for each pixel in screen:
    blurred_color = apply_blur(pixel);
    framebuffer[pixel] = blurred_color;


#endif /* Rendering_h */
