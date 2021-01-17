/*
 * =====================================================================================
 *
 *       Filename:  RenderingTarget.hpp
 *    Description:  Defines an abstract object for where to render to
 *
 *        Version:  1.0
 *        Created:  01/16/21 14:53:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cedric Schwyter (D3PSI)
 *
 * =====================================================================================
 */
#ifndef __FRAMERAT_CORE_RENDERING_RENDERINGTARGET_HPP
#define __FRAMERAT_CORE_RENDERING_RENDERINGTARGET_HPP

namespace framerat::core::rendering {
    class RenderingTarget {
      public:
        RenderingTarget(void) = default;
        ~RenderingTarget(void) = default;
        virtual void draw(void) = 0;
    };
} // namespace framerat::core::rendering

#endif // __FRAMERAT_CORE_RENDERING_TARGET_HPP
