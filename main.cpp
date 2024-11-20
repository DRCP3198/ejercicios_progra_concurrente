#include <iostream>
#include <fmt/core.h>
#include <GLFW/glfw3.h>

static  GLFWwindow* window = nullptr;

void init() {
    fmt::print("Dillan Renato Coloma Pozo\n");
    fmt::print("Programación Paralela\n");
    //GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
       exit (-1);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "OpenGL C++", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(-1);
    }
    //La aplicacionn se cierra
    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);
    });

    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    std::string version = (char*)glGetString(GL_VERSION);
    std::string vendor = (char*)glGetString(GL_VENDOR);
    std::string renderer = (char*)glGetString(GL_RENDERER);
    fmt::print("OpenGL version supported {}\n", version);
    fmt::print("Vendor : {}\n", vendor);
    fmt::print("Renderer : {}\n", renderer);

    //Projeccion

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glfwSwapInterval(1);


}
void paint(){
    glBegin(GL_TRIANGLES);
    {
        glVertex2d(-1,-1);
        glVertex2d(0,0);
        glVertex2d(0,-1);
    }
    glEnd();



}
void loop() {
    glClearColor(0,0,0,0);
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the framebuffer

        //paintTriangulos();
        paint();
        glfwSwapBuffers(window); // Swap the color buffers

        // Poll for window events (e.g., key presses)
        glfwPollEvents();

    }
}
void run() {
    init();
    loop();
    glfwTerminate();

}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    /*fmt::print("Hello World fmt");

    return 0;*/
    run();
    return 0;

}
