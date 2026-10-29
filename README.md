# OpenGL

A small C++ OpenGL 3.3 project for Windows that loads a 3D model from an OBJ file and renders it, with a camera controlled by the mouse.

## Overview

The program opens a 1600 x 900 window titled "My OpenGL Game", loads the Blender "Suzanne" monkey head from `Game/monkey_mesh.obj`, and draws it with a simple shader that colours each fragment by its transformed normal. Each frame, the mouse position moves the camera, after which the cursor is returned to the centre of the window.

## Features

- **Window and context** (`display.h`/`.cpp`): creates the window with GLFW, initialises GLEW, enables depth testing and back-face culling, and clears to black each frame.
- **OBJ loading** (`obj_loader.h`/`.cpp`): parses vertex positions, texture coordinates, normals and faces (triangles and quads), merges them into an indexed model, and calculates normals when the file has none.
- **Meshes** (`mesh.h`/`.cpp`): uploads positions, texture coordinates, normals and indices to a vertex array object and vertex buffers, and draws them as indexed triangles.
- **Shaders** (`shader.h`/`.cpp`): reads, compiles and links a vertex and fragment shader from files, printing any compiler or linker log.
- **Camera** (`camera.h`/`.cpp`): a perspective projection and a look-at view matrix, with methods to move along the x and z axes.
- **Transform** (`transform.h`/`.cpp`): builds a model matrix from translation, rotation and scale. It is compiled but not yet used by `main.cpp`.
- **Shaders** (`test_vertex.vs`, `test_fragment.fs`): GLSL 3.30 shaders that apply a single `MVP` matrix and output the normal as a colour.

## Tech stack

- C++
- OpenGL 3.3 (GLSL `#version 330`)
- [GLFW](https://www.glfw.org/) 3.2 for the window, context and input
- [GLEW](http://glew.sourceforge.net/) for loading OpenGL functions
- [GLM](https://github.com/g-truc/glm) 0.9 for vector and matrix maths
- Visual Studio 2017 (platform toolset v141, Windows 10 SDK 10.0.17134.0)

## Getting started

### Prerequisites

- Windows
- Visual Studio 2017, or a later version with the v141 toolset installed (or retargeted to a newer toolset)
- A GPU and driver supporting OpenGL 3.3

The GLEW, GLFW and GLM headers and the 32-bit GLEW and GLFW import libraries are bundled in `Dependencies/`, so nothing else needs installing.

### Build

1. Open `Game.sln` in Visual Studio.
2. Select the **x86** (Win32) platform. Only the Win32 configurations have the `Dependencies` include and library directories and the GLEW, GLFW and OpenGL libraries configured; the x64 configurations will not link as they stand.
3. Build the solution. The executable is written to `Debug\Game.exe` (or `Release\Game.exe`).

### Run

- The program loads `monkey_mesh.obj`, `test_vertex.vs` and `test_fragment.fs` by relative path, so the working directory must be `Game/`. This is Visual Studio's default when running from the IDE.
- `glew32.dll` and `glfw3.dll` must be next to the executable or on the `PATH`. Copies are in `Debug/`; for a Release build, copy them into `Release/`.

## Usage

| Input | Effect |
| --- | --- |
| Move the mouse left or right | Moves the camera sideways |
| Move the mouse up or down | Moves the camera away from or towards the model |

The cursor is hidden and held at the centre of the window, so close the window with Alt+F4. There are no keyboard controls.

To display a different model, change the file name passed to `Mesh` in `Game/main.cpp`.

## Project structure

```
.
├── Game.sln                  # Visual Studio solution
├── Game/
│   ├── Game.vcxproj          # Project: sources, include and library paths, linked libraries
│   ├── main.cpp              # Entry point: sets up the scene and runs the render loop
│   ├── display.h/.cpp        # GLFW window and GLEW initialisation
│   ├── camera.h/.cpp         # Projection and view matrices, camera movement
│   ├── mesh.h/.cpp           # Vertex array and buffer set-up and drawing
│   ├── obj_loader.h/.cpp     # Wavefront OBJ parser and indexed-model builder
│   ├── shader.h/.cpp         # Shader loading, compilation and linking
│   ├── transform.h/.cpp      # Model matrix from translation, rotation and scale (unused)
│   ├── test_vertex.vs        # Vertex shader
│   ├── test_fragment.fs      # Fragment shader
│   └── *.obj                 # Sample models (see below)
├── Dependencies/
│   ├── include/              # GLEW, GLFW and GLM headers
│   └── lib/                  # GLEW and GLFW import and static libraries (32-bit)
└── Debug/                    # Committed debug build, including glew32.dll and glfw3.dll
```

### Sample models

| File | Contents |
| --- | --- |
| `monkey_mesh.obj` | Blender's Suzanne monkey head (the model the program loads) |
| `test_mesh.obj` | A UV sphere exported from Blender |
| `bunny.obj`, `bunny.obj.txt` | A bunny mesh (two copies of the same model) |
| `utahteapot.obj`, `utahteapot.mtl` | The Utah teapot |
| `IronMan.obj` | An Iron Man model; its referenced `IronMan.mtl` material file is not included |

## Status and limitations

This is an early learning project; the commit history ends at controlling the monkey head with the mouse.

- The project builds for Windows and 32-bit (x86) only.
- `ASPECT_RATIO` in `main.cpp` is computed with integer division (`1600 / 900`, giving 1), so the image is stretched horizontally.
- The camera field of view is passed to `glm::perspective` as `70.0f`, which GLM interprets as radians rather than degrees.
- `obj_loader.h` includes GLM with a lower-case `glm/` path while the directory is `GLM/`, which relies on Windows' case-insensitive file system.
- The repository includes build output (`Debug/`, `Game/Debug/`) and Visual Studio cache files (`.vs/`). `Game/Debug/` contains object files for `Player`, `VAO` and `VBO` sources that are no longer in the repository.

## Acknowledgements

- The shader-loading code in `shader.cpp` is adapted from the [opengl-tutorial.org](http://www.opengl-tutorial.org/) tutorials.
- Bundled third-party libraries in `Dependencies/`, each distributed under its upstream project's licence:
  - GLEW: Modified BSD Licence (with MIT-licensed Mesa 3-D and Khronos portions)
  - GLFW 3.2: zlib/libpng Licence
  - GLM: Happy Bunny Licence or MIT Licence
