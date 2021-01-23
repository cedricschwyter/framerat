/*
 * =====================================================================================
 *
 *       Filename:  RenderingMode.hpp
 *
 *    Description:  Defines an enumeration for rendering modes
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
#ifndef __FRAMERAT_CORE_RENDERING_ENUMS_RENDERINGMODE_HPP
#define __FRAMERAT_CORE_RENDERING_ENUMS_RENDERINGMODE_HPP

namespace framerat::core::rendering::enums {
    typedef enum RenderingMode { DETACHED, SINGULAR, SYNCHRONIZED, HEADLESS } RenderingMode;
}

#endif // __FRAMERAT_CORE_RENDERING_ENUMS_RENDERINGMODE_HPP
