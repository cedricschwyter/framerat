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
    class GLFWWindowFactory : public WindowFactory, std::enable_shared_from_this<GLFWWindowFactory> {
      public:
        GLFWWindowFactory(void);
        ~GLFWWindowFactory(void);

        std::shared_ptr<Window> create(void);
        void submit(std::packaged_task<void()> _task);
        std::shared_future<void> submitSynchronously(std::packaged_task<void()> _task);

        void init(void);
        void draw(std::shared_ptr<Window> _window);

      private:
        std::future<void> m_thread;
        std::vector<std::shared_ptr<GLFWwindow>> m_glfwWindows;
        std::queue<std::packaged_task<void()>> m_tasks;
        std::atomic<bool> m_initializing = true;

        void defaultWindowHints(void);
        void loop(void);
    };
} // namespace framerat::core::windowing::factory::glfw

#endif // __FRAMERAT_CORE_WINDOWING_FACTORY_GLFW_GLFWWINDOWFACTORY_HPP
