/*
 * =====================================================================================
 *
 *       Filename:  RenderingContext.hpp
 *    Description:  Defines the core abstraction object for the graphics card
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
#ifndef __FRAMERAT_CORE_RENDERING_RENDERINGCONTEXT_HPP
#define __FRAMERAT_CORE_RENDERING_RENDERINGCONTEXT_HPP

#include "RenderingTarget.hpp"
#include "enums/RenderingBackend.hpp"
#include "enums/RenderingMode.hpp"
#include <functional>
#include <future>
#include <memory>

using namespace framerat::core::rendering::enums;

namespace framerat::core::rendering {
    class RenderingContext {
      public:
        RenderingContext(void) = delete;
        ~RenderingContext(void) = default;
        RenderingContext(RenderingBackend _renderingBackend,
                         std::shared_ptr<RenderingTarget>
                             _renderingTarget, // TODO: Add default argument for _renderingTarget and _renderingBackend
                         RenderingMode _renderingMode = SYNCHRONIZED);

        RenderingBackend getRenderingBackend(void);
        void setRenderingBackend(RenderingBackend _renderingBackend);

        std::shared_ptr<RenderingTarget> getRenderingTarget(void);
        void setRenderingTarget(std::shared_ptr<RenderingTarget> _renderingTarget);

        RenderingMode getRenderingMode(void);
        void setRenderingMode(RenderingMode _renderingMode);

        std::function<void()> getRenderCallback(void);
        void setRenderCallback(std::function<void()> _renderCallback);

        std::shared_future<void> submit(std::packaged_task<void()> _task);
        void submitSynchronously(std::packaged_task<void()> _task);

      private:
        RenderingBackend m_renderingBackend;
        std::shared_ptr<RenderingTarget> m_renderingTarget;
        RenderingMode m_renderingMode;
        std::function<void()> m_renderCallback;
        std::future<void> m_thread;

        void main(void);
    };
} // namespace framerat::core::rendering

#endif // __FRAMERAT_CORE_RENDERING_RENDERINGCONTEXT_HPP
