#ifndef __FRAMERAT_CORE_RENDERING_TARGET_HPP
#define __FRAMERAT_CORE_RENDERING_TARGET_HPP

namespace framerat::core::rendering {
    class Target {
      public:
        virtual void draw(void) = 0;
    };
} // namespace framerat::core::rendering

#endif // __FRAMERAT_CORE_RENDERING_TARGET_HPP
