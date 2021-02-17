/*
 * =====================================================================================
 *
 *       Filename:  BaseEvent.hpp
 *
 *    Description:  Defines an abstract base event object
 *
 *        Version:  1.0
 *        Created:  17.02.2021 19:08:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cedric Schwyter (D3PSI)
 *
 * =====================================================================================
 */
#ifndef __FRAMERAT_CORE_WINDOWING_EVENTS_BASEEVENT_HPP
#define __FRAMERAT_CORE_WINDOWING_EVENTS_BASEEVENT_HPP

namespace framerat::core::windowing::events {
    template <typename T> class BaseEvent {
      public:
        BaseEvent(void) = delete;
        ~BaseEvent(void) = delete;

        BaseEvent(T _event);

      private:
        T m_event;
    };
} // namespace framerat::core::windowing::events

#endif // __FRAMERAT_CORE_WINDOWING_EVENTS_BASEEVENT_HPP
