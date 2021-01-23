/*
 * =====================================================================================
 *
 *       Filename:  GLFWWindowFactory.cpp
 *
 *    Description:  Defines core GLFWWindowFactory functionality
 *
 *        Version:  1.0
 *        Created:  01/17/21 15:47:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cedric Schwyter (D3PSI)
 *
 * =====================================================================================
 */
#include "GLFWWindowFactory.hpp"
#include "GLFWWindowDeleter.hpp"
#include <memory>

namespace framerat::core::windowing::factory::glfw {
    GLFWWindowFactory::GLFWWindowFactory() : WindowFactory() {
        m_thread = std::async(std::launch::async, &GLFWWindowFactory::init, this);
    }

    void GLFWWindowFactory::init() {
        glfwInit();
        defaultWindowHints();
        loop();
        glfwTerminate();
    }

    void GLFWWindowFactory::draw(std::shared_ptr<Window> _window) {}

    std::shared_ptr<Window> GLFWWindowFactory::create() {
        std::shared_ptr<GLFWwindow> glfwWindow = std::shared_ptr<GLFWwindow>(
            glfwCreateWindow(1280, 720, "Framerat by D3PSI", nullptr, nullptr),
            GLFWWindowDeleter()); // TODO: Make all these values function parameters of this factory
                                  // method and set them in the newly created Window object
    }

    void GLFWWindowFactory::defaultWindowHints() {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(
            GLFW_OPENGL_PROFILE,
            GLFW_OPENGL_CORE_PROFILE); // TODO: Make this and the next call dynamic as this wont work for Vulkan
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif // __APPLE__
    }

    void GLFWWindowFactory::loop() {
        // TODO: Work down the submitted tasks on the GLFW thread
    }
} // namespace framerat::core::windowing::factory::glfw
