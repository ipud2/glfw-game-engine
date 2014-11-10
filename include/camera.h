#pragma once

#include <list>

#include "entity.h"
#include "glm.hpp"

// Class that represents camera
class Camera : public Entity
{
public:
    // Constructor
    Camera();
    // Destructor
    ~Camera();

    // Switch to this camera
    Camera * use();

    // Get current camera
    static Camera * getCurrentCamera();

    // Getter for viewMatrix
    glm::mat4 getViewMatrix();

    // Override movement functions
    glm::vec4 move(glm::vec4 translation);
    glm::vec4 setPosition(glm::vec4 newPosition);

private:
    // Camera that is currently being used
    static Camera * currentCamera;
    // List of active cameras for switching
    static std::list<Camera*> activeCameras;

    // View matrix for this camera
    glm::mat4 viewMatrix;
};