//modules
#define GLFW_INCLUDE_NONE // define or else you'll have to metnion glew before glfw
#include<GLFW/glfw3.h>
#include<gl/glew.h>
#include<iostream>
#include<string>
using namespace std;


void init(GLFWwindow* window) {

}

void display(GLFWwindow* window, double currentTime) {
    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main() {
    //Iniialize GLFW
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    //Window creation
    glfwWindowHint(GLFW_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_VERSION_MINOR, 6);
    GLFWwindow* window = glfwCreateWindow(640, 480, "Cube", NULL, NULL);
    if (!window) {
        exit(EXIT_FAILURE);
        glfwTerminate();
    }
    //Select current context
    glfwMakeContextCurrent(window);

    //Initialize GLEW
    if (glewInit() != GLEW_OK) {
        exit(EXIT_FAILURE);
    }
    //avoid screen tear useful for High-motion-conten-graphics(vsync)
    glfwSwapInterval(1);

    //Setup to display color
    init(window);
    while (!glfwWindowShouldClose(window)) {
        display(window, glfwGetTime());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //Destory Window
    glfwDestroyWindow(window);
    // Terminate GLFW
    glfwTerminate();
    exit(EXIT_SUCCESS);
}