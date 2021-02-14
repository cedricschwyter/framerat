/*
 * =====================================================================================
 *
 *       Filename:  GLFWWindowFactory.hpp
 *
 *    Description:  Defines core GLFWWindowFactory functionality
 *
 *        Version:  1.0
 *        Created:  01/17/21 15:45:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cedric Schwyter (D3PSI)
 *
 * =====================================================================================
 */
#ifndef __FRAMERAT_CORE_WINDOWING_FACTORY_GLFW_GLFWWINDOWFACTORY_HPP
#define __FRAMERAT_CORE_WINDOWING_FACTORY_GLFW_GLFWWINDOWFACTORY_HPP

#include "../WindowFactory.hpp"
#include <GLFW/glfw3.h>
#include <future>
#include <queue>

using namespace framerat::core::windowing::factory;

namespace framerat::core::windowing::factory::glfw {
    class GLFWWindowFactory : public WindowFactory, public std::enable_shared_from_this<GLFWWindowFactory> {
      public:
        static std::shared_ptr<GLFWWindowFactory> create(void);

        ~GLFWWindowFactory(void);

        std::shared_ptr<Window> spawn(uint32_t _width = 1280, uint32_t _height = 720,
                                      const std::string& _title = "Framerat by D3PSI",
                                      const std::string& _icon = "res/logo/framerat-logo-small.png",
                                      uint32_t _framerate = 60);
        void close(std::shared_ptr<Window> _window);
        std::shared_future<void> submit(std::packaged_task<void()> _task);

        void init(void);
        void draw(std::shared_ptr<Window> _window);
        void shutdown(void);

      private:
        std::future<void> m_thread;
        std::vector<std::shared_ptr<GLFWwindow>> m_glfwWindows;
        std::queue<std::packaged_task<void()>*> m_tasks;
        std::atomic<bool> m_initializing = true;
        std::atomic<bool> m_glfwInitializing = true;

        GLFWWindowFactory(void);

        void defaultWindowHints(void);
        void setCallbacks(void);
        void loop(void);
    };
} // namespace framerat::core::windowing::factory::glfw

#endif // __FRAMERAT_CORE_WINDOWING_FACTORY_GLFW_GLFWWINDOWFACTORY_HPP
