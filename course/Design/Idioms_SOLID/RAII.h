//
//  RAII.h
//  Test2019
//
//  Created by Risukhin Denys on 3/1/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef RAII_h
#define RAII_h

// RAII (Resource Acquisition(Получение ресурсов) Is Initialization) is a popular C++ programming idiom used for managing resources in a deterministic manner
// RAII is a widely used technique in game development in C++ to manage resources such as memory, file handles, graphics objects, and more. Here are a few examples from different aspects of game development:

// 1 Memory Management:
class Texture
{
public:
    // Constructor loads the texture
    Texture(const std::string& filename) : texture(nullptr)
    {
        texture = IMG_LoadTexture(renderer, filename.c_str());
        if (!texture)
        {
            throw std::runtime_error("Failed to load texture");
        }
    }

    // Destructor releases the texture
    ~Texture()
    {
        if (texture)
        {
            SDL_DestroyTexture(texture);
        }
    }
    
private:
    SDL_Texture* texture;
};

// 2 File Handling
// the FileReader class manages file reading operations. The constructor opens the file, and the destructor closes it. This ensures that the file is properly closed when the FileReader object goes out of scope, preventing resource leaks.
class FileReader
{
public:
    // Constructor opens the file
    FileReader(const std::string& filename) : file(filename)
    {
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file");
        }
    }

    // Destructor closes the file
    ~FileReader()
    {
        if (file.is_open())
        {
            file.close();
        }
    }

    // Method to read data from the file
    std::string read()
    {
        std::string data;
        std::getline(file, data);
        return data;
    }
    
private:
    std::ifstream file;
};

// 3 Graphics Resource Management.
// the Mesh class manages OpenGL buffers for rendering a mesh. The constructor initializes the OpenGL buffers, and the destructor releases them. This ensures that the OpenGL resources are properly managed and cleaned up when the Mesh object goes out of scope.

// These examples demonstrate how RAII can be used in game development to manage various resources efficiently and safely.

class Mesh
{
public:
    // Constructor initializes OpenGL buffers
    Mesh(const std::vector<Vertex>& vertices) {
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
        // Setup vertex attributes
        // ...
    }

    // Destructor releases OpenGL buffers
    ~Mesh() {
        glDeleteBuffers(1, &vbo);
        glDeleteVertexArrays(1, &vao);
    }
    
private:
    GLuint vao;
    GLuint vbo;
};


#endif /* RAII_h */
