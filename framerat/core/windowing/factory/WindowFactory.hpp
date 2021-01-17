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

namespace framerat::core::windowing::factory {
    class WindowFactory {
      public:
        WindowFactory(void) = default;
        ~WindowFactory(void) = default;

        virtual void init(void) = 0;
        virtual void draw(void) = 0;
    };
} // namespace framerat::core::windowing::factory

#endif // __FRAMERAT_CORE_WINDOWING_FACTORY_WINDOWFACTORY_HPP
