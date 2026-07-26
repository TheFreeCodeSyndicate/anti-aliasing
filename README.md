<div align="center">

# Computer Graphics From Scratch

*A collaborative learning project by The Free Code Syndicate.*

![C](https://img.shields.io/badge/C-Language-blue)
![SDL2](https://img.shields.io/badge/SDL3-Library-green)
![OpenGL](https://img.shields.io/badge/OpenGL-API-orange)
![Status](https://img.shields.io/badge/Status-Early_Development-red)

</div>

This repository contains the source code, technical documentation, and programming exercises for the study of computer graphics. We build a software renderer from first principles. We define the mathematical structures before we use the SDL3 and OpenGL libraries. We introduce each abstraction only after we explain the underlying mechanics.

**Curriculum**
The material assumes basic knowledge of C. You do not need previous experience with computer graphics. The study sequence progresses from mathematical preliminaries to modern rendering techniques. We examine Euclidean geometry, linear algebra, coordinate systems, and affine transformations. We then implement camera models, projection, clipping, and rasterization. Finally, we apply these concepts to hardware-accelerated rendering with OpenGL and GLSL. 

Each module provides the mathematical background, the theoretical framework, the software implementation, and practical exercises. The code implementation always follows the theory.

**Repository Structure**
*   **`docs/`**: Technical documentation and bibliographic references.
*   **`src/`**: Source code for the mathematics library, the renderer, and the hardware abstractions.
*   **`exercises/`**: Practical programming tasks.
*   **`assets/`**: Three-dimensional models, textures, and project resources.
*   **`tools/`**: Utility programs for the development workflow.

**Build Requirements**
The project uses C23, CMake, SDL3, and OpenGL. You must not use compiler-specific extensions unless they are strictly necessary.

**Engineering Standards**
All source code must compile without warnings. You must keep functions small, use descriptive names, and document all public interfaces. You must remove unused code before you submit a pull request. 

The technical documentation operates as an extension of the source code. Each document must define its purpose, explain the theory, describe the implementation, and list its references. Mathematical notation must remain consistent across all files.

**Contributions**
We accept contributions from the community. Before you submit a change, you must compile the project, verify the example code, review the documentation, and test the modifications. You must discuss large structural changes before you write the code. 

**License and Organization**
This project operates under the MIT License. The Free Code Syndicate maintains this repository as a collaborative effort to study computer science through rigorous software engineering.
