/*
 * =====================================================================================
 *
 *       Filename:  WindowFactory.hpp
 *
 *    Description:  Defines core WindowFactory functionality
 *
 *        Version:  1.0
 *        Created:  01/17/21 15:39:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cedric Schwyter (D3PSI)
 *
 * =====================================================================================
 */
#ifndef __FRAMERAT_CORE_WINDOWING_FACTORY_WINDOWFACTORY_HPP
#define __FRAMERAT_CORE_WINDOWING_FACTORY_WINDOWFACTORY_HPP

#include <memory>
#include <vector>

namespace framerat::core::windowing {
    class Window;
}

using namespace framerat::core::windowing;

namespace framerat::core::windowing::factory {
    class WindowFactory {
      public:
        WindowFactory(void) = default;
        virtual ~WindowFactory(void) = default;

        virtual std::shared_ptr<Window> create(void) = 0;

        virtual void init(void) = 0;
        virtual void draw(std::shared_ptr<Window> _window) = 0;

      protected:
        std::vector<std::shared_ptr<Window>> m_windows;
    };
} // namespace framerat::core::windowing::factory

#endif // __FRAMERAT_CORE_WINDOWING_FACTORY_WINDOWFACTORY_HPP
