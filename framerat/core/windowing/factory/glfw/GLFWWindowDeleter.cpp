/*
 * =====================================================================================
 *
 *       Filename:  GLFWWindowDeleter.cpp
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
#include "GLFWWindowDeleter.hpp"

namespace framerat::core::windowing::factory::glfw {
    void GLFWWindowDeleter::operator()(GLFWwindow* _window) { glfwDestroyWindow(_window); }
} // namespace framerat::core::windowing::factory::glfw
