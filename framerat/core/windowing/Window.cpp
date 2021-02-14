/*
 * =====================================================================================
 *
 *       Filename:  Window.cpp
 *
 *    Description:  Defines core Window functionality
 *
 *        Version:  1.0
 *        Created:  01/17/21 15:38:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cedric Schwyter (D3PSI)
 *
 * =====================================================================================
 */
#include "Window.hpp"
#include "factory/WindowFactory.hpp"

namespace framerat::core::windowing {

    std::shared_ptr<Window> Window::create(std::shared_ptr<WindowFactory> _factory, uint32_t _width, uint32_t _height,
                                           const std::string& _title, const std::string& _icon, uint32_t _framerate) {
        return std::shared_ptr<Window>(new Window(_factory, _width, _height, _title, _icon, _framerate));
    }

    Window::Window(std::shared_ptr<WindowFactory> _factory, uint32_t _width, uint32_t _height,
                   const std::string& _title, const std::string& _icon, uint32_t _framerate)
        : RenderingTarget(), m_factory(_factory), m_width(_width), m_height(_height), m_title(_title), m_icon(_icon),
          m_framerate(_framerate) {}

    void Window::draw() { m_factory->draw(shared_from_this()); }

} // namespace framerat::core::windowing
