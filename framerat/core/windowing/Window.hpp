/*
 * =====================================================================================
 *
 *       Filename:  Window.hpp
 *
 *    Description:  Defines core Window functionality
 *
 *        Version:  1.0
 *        Created:  01/17/21 15:36:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cedric Schwyter (D3PSI)
 *
 * =====================================================================================
 */
#ifndef __FRAMERAT_CORE_WINDOWING_WINDOW_HPP
#define __FRAMERAT_CORE_WINDOWING_WINDOW_HPP

#include "../rendering/RenderingTarget.hpp"
#include <memory>
#include <stdint.h>
#include <string>

namespace framerat::core::windowing::factory {
    class WindowFactory;
}

using namespace framerat::core::rendering;
using namespace framerat::core::windowing::factory;

namespace framerat::core::windowing {
    class Window : public RenderingTarget, std::enable_shared_from_this<Window> {
      public:
        static std::shared_ptr<Window> create(std::shared_ptr<WindowFactory> _factory, uint32_t _width = 1280,
                                              uint32_t _height = 720, const std::string& _title = "Framerat by D3PSI",
                                              const std::string& _icon = "res/logo/framerat-logo-small.png",
                                              uint32_t _framerate = 60);

        Window(void) = delete;
        ~Window(void) = default;

        void draw(void) override;

      private:
        std::shared_ptr<WindowFactory> m_factory;
        uint32_t m_width;
        uint32_t m_height;
        std::string m_title;
        std::string m_icon;
        uint32_t m_framerate;

        explicit Window(std::shared_ptr<WindowFactory> _factory, uint32_t _width, uint32_t _height,
                        const std::string& _title, const std::string& _icon, uint32_t _framerate);
    };
} // namespace framerat::core::windowing

#endif // __FRAMERAT_CORE_WINDOWING_WINDOW_HPP
