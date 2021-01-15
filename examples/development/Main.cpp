/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  This program is used to test the features of the framerat libary
 *
 *        Version:  1.0
 *        Created:  11.11.2020 21:46:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cedric Schwyter (D3PSI)
 *
 * =====================================================================================
 */
#include "../../include/framerat/Framerat.hpp"
#include <memory>

using namespace framerat::util::window;
using namespace framerat::util::window::glfw;

int main() {
    WindowDetails windowDetails = {};
    windowDetails.m_width = 1280;
    windowDetails.m_height = 720;
    windowDetails.m_title = "Framerat by D3PSI - Main Development Example";
    GLFWController* controller = new GLFWController();
    std::shared_ptr<Window> window = Window::create(controller, windowDetails);
    return framerat::terminate();
}
