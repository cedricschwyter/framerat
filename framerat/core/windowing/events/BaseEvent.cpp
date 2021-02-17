/*
 * =====================================================================================
 *
 *       Filename:  BaseEvent.cpp
 *
 *    Description:  Defines an abstract base event object
 *
 *        Version:  1.0
 *        Created:  17.02.2021 19:07:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cedric Schwyter (D3PSI)
 *
 * =====================================================================================
 */
#include "BaseEvent.hpp"

namespace framerat::core::windowing::events {
    template <typename T> BaseEvent<T>::BaseEvent(T _event) : m_event(_event) {}
} // namespace framerat::core::windowing::events
