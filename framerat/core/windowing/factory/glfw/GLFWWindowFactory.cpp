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
        setCallbacks();
        loop();
        glfwTerminate();
    }

    void GLFWWindowFactory::draw(std::shared_ptr<Window> _window) {}

    std::shared_ptr<Window> GLFWWindowFactory::spawn(uint32_t _width, uint32_t _height, const std::string& _title,
                                                     const std::string& _icon, uint32_t _framerate) {
        std::shared_ptr<Window> window;
        submit(std::packaged_task<void()>([=, window = std::move(window)]() mutable -> void {
            // TODO: Load icon here
            std::shared_ptr<GLFWwindow> glfwWindow = std::shared_ptr<GLFWwindow>(
                glfwCreateWindow(_width, _height, _title.c_str(), nullptr, nullptr), GLFWWindowDeleter());
            m_glfwWindows.push_back(glfwWindow);
            if (m_initializing.load()) {
                m_initializing = false;
            }
            window = Window::create(shared_from_this(), _width, _height, _title, _icon, _framerate);
            m_windows.push_back(window);
        })).get();
        return window;
    }

    void GLFWWindowFactory::close(std::shared_ptr<Window> _window) {}

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

    void GLFWWindowFactory::setCallbacks() {}

    void GLFWWindowFactory::loop() {
        m_glfwInitializing = false;
        while (!m_glfwWindows.empty() || m_initializing.load()) {
            while (!m_tasks.empty()) {
                std::packaged_task<void()> task = std::move(*(m_tasks.front()));
                m_tasks.pop();
                task();
            }
            glfwPollEvents();
            for (std::shared_ptr<Window> win : m_windows) {
            }
            for (std::shared_ptr<GLFWwindow> win : m_glfwWindows) {
                if (glfwWindowShouldClose(win.get())) {
                }
                glfwSwapBuffers(win.get());
            }
        }
    }

    void GLFWWindowFactory::shutdown() { m_thread.get(); }
} // namespace framerat::core::windowing::factory::glfw
