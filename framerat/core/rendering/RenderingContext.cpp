/*
 * =====================================================================================
 *
 *       Filename:  RenderingContext.cpp
 *
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
#include "RenderingContext.hpp"

namespace framerat::core::rendering {
    RenderingContext::RenderingContext(RenderingBackend _renderingBackend,
                                       std::shared_ptr<RenderingTarget> _renderingTarget, RenderingMode _renderingMode)
        : m_renderingBackend(_renderingBackend), m_renderingTarget(_renderingTarget), m_renderingMode(_renderingMode) {
        m_thread = std::async(std::launch::async, &RenderingContext::main, this);
    }

    void RenderingContext::main() {}

    RenderingBackend RenderingContext::getRenderingBackend() { return m_renderingBackend; }

    void RenderingContext::setRenderingBackend(RenderingBackend _renderingBackend) {
        m_renderingBackend = _renderingBackend;
    }

    std::shared_ptr<RenderingTarget> RenderingContext::getRenderingTarget() { return m_renderingTarget; }

    void RenderingContext::setRenderingTarget(std::shared_ptr<RenderingTarget> _renderingTarget) {
        m_renderingTarget = _renderingTarget;
    }

    RenderingMode RenderingContext::getRenderingMode() { return m_renderingMode; }

    void RenderingContext::setRenderingMode(RenderingMode _renderingMode) { m_renderingMode = _renderingMode; }

    std::function<void()> RenderingContext::getRenderCallback() { return m_renderCallback; }

    void RenderingContext::setRenderCallback(std::function<void()> _renderCallback) {
        m_renderCallback = _renderCallback;
    }

    std::shared_future<void> RenderingContext::submit(std::packaged_task<void()> _task) {
        return _task.get_future().share();
    }

    void RenderingContext::submitSynchronously(std::packaged_task<void()> _task) {}
} // namespace framerat::core::rendering
