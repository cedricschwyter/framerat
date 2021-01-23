/*
 * =====================================================================================
 *
 *       Filename:  GLFWWindowDeleter.hpp
 *
 *    Description:  Defines a custom deleter for GLFWwindow smart pointers
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
#ifndef __FRAMERAT_CORE_WINDOWING_FACTORY_GLFW_GLFWWINDOWDELETER_HPP
#define __FRAMERAT_CORE_WINDOWING_FACTORY_GLFW_GLFWWINDOWDELETER_HPP

#include <GLFW/glfw3.h>

namespace framerat::core::windowing::factory::glfw {
    struct GLFWWindowDeleter {
        void operator()(GLFWwindow* _window);
    };
} // namespace framerat::core::windowing::factory::glfw

#endif // __FRAMERAT_CORE_WINDOWING_FACTORY_GLFW_GLFWWINDOWDELETER_HPP
