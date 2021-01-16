/*
 * =====================================================================================
 *
 *       Filename:  RenderingBackend.hpp
 *
 *    Description:  Defines an enumeration for rendering backends
 *
 *        Version:  1.0
 *        Created:  01/16/21 18:00:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cedric Schwyter (D3PSI)
 *
 * =====================================================================================
 */
#ifndef __FRAMERAT_CORE_RENDERING_ENUMS_RENDERINGBACKEND_HPP
#define __FRAMERAT_CORE_RENDERING_ENUMS_RENDERINGBACKEND_HPP

namespace framerat::core::rendering::enums {
    typedef enum RenderingBackend { OPENGL, VULKAN } RenderingBackend;
}

#endif // __FRAMERAT_CORE_RENDERING_ENUMS_RENDERINGBACKEND_HPP
