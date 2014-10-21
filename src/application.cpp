#include <stdio.h>

#include "application.h"

Application::Application() { init(); }
Application::~Application()
{
    // TODO: Change this cleanup code for all windows
    delete mainWindow;

    glfwTerminate();
}

// TODO: Add default window that is mainWindow to application
int Application::init()
{
    // Initialize GLFW
    if(!glfwInit())
    {
        fprintf(stderr, "ERROR: GLFW Failed to Initialize"); // TODO: Print this to log file
        return GLFW_INIT_FAILURE; // TODO: Exit Application (Call Function)
    }
    
    // --- Set Window Hints ---
    
    // OpenGL Version (3.2)
    // TODO: Set This automatically
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    
    // Forward Compatibility for OSX
    // TODO: Figure out why this is required
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    // Core Profile (Not using deprecated functionality)
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Set OpenGL Error Callback
    glfwSetErrorCallback(glfwErrorCallback);
    
    // --- Initialize GLEW ---
    // TODO: Figure out where this needs to go, as it causes an error using before a window is created
    //       since an OpenGL context is created by GLFW along with the window
    
    // Experimental GLEW Required for OSX
    // TODO: Find out what to do about this and OSX/Other OSs
    //glewExperimental = GL_TRUE;
    
    // Initialize
    //if(glewInit())
    //    fprintf(stderr, "ERROR: Could Not Initialize GLEW"); // TODO: Exit Application (Call Function)
    
    return SUCCESS;
}

void Application::terminate(ErrorCode e)
{
    if(e != GLFW_INIT_FAILURE)
        glfwTerminate();
}

// TODO: Make this able to be used with multiple windows
Window * Application::addWindow(int height, int width, bool fullscreen, char * title, bool isMain)
{
    Window * w = new Window(height, width, fullscreen, title);

    // TODO: Make this compatible with multiple windows by setting mainWindow and adding to list of windows
    mainWindow = w;

    return w;
}

void Application::glfwErrorCallback(int error, const char * description)
{
    fprintf(stderr, "OpenGL Error %d: %s", error, description);
}