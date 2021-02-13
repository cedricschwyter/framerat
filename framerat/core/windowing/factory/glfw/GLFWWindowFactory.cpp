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
#include <chrono>
#include <memory>

using namespace framerat::core::windowing;

namespace framerat::core::windowing::factory::glfw {
    std::shared_ptr<GLFWWindowFactory> GLFWWindowFactory::create() {
        return std::shared_ptr<GLFWWindowFactory>(new GLFWWindowFactory());
    }

    GLFWWindowFactory::GLFWWindowFactory() : WindowFactory() {
        m_thread = std::async(std::launch::async, &GLFWWindowFactory::init, this);
    }

    GLFWWindowFactory::~GLFWWindowFactory() { m_thread.get(); }

    void GLFWWindowFactory::init() {
        glfwInit();
        defaultWindowHints();
        loop();
        glfwTerminate();
    }

    void GLFWWindowFactory::draw(std::shared_ptr<Window> _window) {}

    std::shared_ptr<Window> GLFWWindowFactory::spawn() {
        std::shared_ptr<Window> window;
        std::shared_future<void> fut = submit(std::packaged_task<void()>([=]() mutable -> void {
            std::shared_ptr<GLFWwindow> glfwWindow = std::shared_ptr<GLFWwindow>(
                glfwCreateWindow(1280, 720, "Framerat by D3PSI", nullptr, nullptr),
                GLFWWindowDeleter()); // TODO: Make all these values function parameters of this factory
                                      // method and set them in the newly created Window object
            m_glfwWindows.push_back(glfwWindow);
            if (m_initializing.load()) {
                m_initializing = false;
            }
            window = Window::create(shared_from_this(), 1280, 720, "Framerat by D3PSI");
            m_windows.push_back(window);
        }));
        fut.get();
        return window;
    }

    std::shared_future<void> GLFWWindowFactory::submit(std::packaged_task<void()> _task) {
        while (m_glfwInitializing.load()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        m_tasks.push(&_task);
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
        m_glfwInitializing = false;
        while (!m_glfwWindows.empty() || m_initializing.load()) {
            while (!m_tasks.empty()) {
                std::packaged_task<void()> task = std::move(*(m_tasks.front()));
                m_tasks.pop();
                task();
            }
            for (std::shared_ptr<GLFWwindow> win : m_glfwWindows) {
                glfwSwapBuffers(win.get());
            }
        }
    }

    void GLFWWindowFactory::shutdown() { m_thread.get(); }
} // namespace framerat::core::windowing::factory::glfw
