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
#include "../../Window.hpp"
#include "GLFWWindowDeleter.hpp"
#include <memory>

using namespace framerat::core::windowing;

namespace framerat::core::windowing::factory::glfw {
    GLFWWindowFactory::GLFWWindowFactory() : WindowFactory() {
        m_thread = std::async(std::launch::async, &GLFWWindowFactory::init, this);
    }

    GLFWWindowFactory::~GLFWWindowFactory() {}

    void GLFWWindowFactory::init() {
        glfwInit();
        defaultWindowHints();
        loop();
        glfwTerminate();
    }

    void GLFWWindowFactory::draw(std::shared_ptr<Window> _window) {}

    std::shared_ptr<Window> GLFWWindowFactory::create() {
        Window* window = nullptr;
        submitSynchronously(std::packaged_task<void()>([=]() mutable -> void {
            std::shared_ptr<GLFWwindow> glfwWindow = std::shared_ptr<GLFWwindow>(
                glfwCreateWindow(1280, 720, "Framerat by D3PSI", nullptr, nullptr),
                GLFWWindowDeleter()); // TODO: Make all these values function parameters of this factory
                                      // method and set them in the newly created Window object
            m_glfwWindows.push_back(glfwWindow);
            window = new Window(shared_from_this(), 1280, 720, "Framerat by D3PSI");
            m_windows.push_back(std::make_shared<Window>(*window));
        })).get();
        return std::make_shared<Window>(*window);
    }

    void GLFWWindowFactory::submit(std::packaged_task<void()> _task) { m_tasks.push(std::move(_task)); }

    std::shared_future<void> GLFWWindowFactory::submitSynchronously(std::packaged_task<void()> _task) {
        m_tasks.push(std::move(_task));
        return _task.get_future().share();
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
        while (!m_glfwWindows.empty() || m_initializing.load()) {
            while (!m_tasks.empty()) {
                std::packaged_task<void()> task = std::move(m_tasks.front());
                m_tasks.pop();
                task();
            }
        }
    }
} // namespace framerat::core::windowing::factory::glfw
