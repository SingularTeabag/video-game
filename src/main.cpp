#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(void) {
    printf("Hello, World!\n");

    if (!glfwInit()) { //glfw initialization
        printf("Failed to initialize GLFW\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //use openGL v3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //use openGL v3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //disable old openGL features

    GLFWwindow* window; //pointer to glfw window object
    window = glfwCreateWindow(800, 600, "Game", NULL, NULL); //giving the window properties

    if (!window) { //makes sure the window is created
        printf("Failed to create window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window); //makes opengl context current

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { //glad initialization
        printf("Failed to initialize GLAD\n");
        return -1;
    }
    /*--------------------------------Initialization end-----------------------------*/

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    // An array of 3 vectors which represents 3 vertices
    GLfloat g_vertex_buffer_data[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f,
     };
    // This will identify our vertex buffer
    GLuint vertexbuffer;
    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);




    //Rendering loop
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT); //clear the screen

        // 1st attribute buffer : vertices
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
           0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
           3,                  // size
           GL_FLOAT,           // type
           GL_FALSE,           // normalized?
           0,                  // stride
           (void*)0            // array buffer offset
        );
        // Draw the triangle !
        glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
        glDisableVertexAttribArray(0);

        glfwSwapBuffers(window); //rendering opengl window
        glfwPollEvents(); //updating opengl window
    }

    glfwTerminate(); // terminates the window
    return 0;
}