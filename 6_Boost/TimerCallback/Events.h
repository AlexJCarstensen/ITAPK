//
// Created by carty on 9/14/16.
//

#ifndef TIMERCALLBACK_EVENTS_H
#define TIMERCALLBACK_EVENTS_H


#include <chrono>
#include <ostream>
#include <ctime>

/**
 * Event
 */
class Event
{
public:
  Event()
    : creationTime_(std::chrono::system_clock::now())
  {
  }
  std::chrono::time_point<std::chrono::system_clock> creationTime() const
  {
    return creationTime_;
  }

private:
  std::chrono::time_point<std::chrono::system_clock> creationTime_;
};


/**
 * EventOther
 */
class EventOther : public Event {};

std::ostream& operator<<( std::ostream& os, const Event& ev )
{
    std::time_t creationTime = std::chrono::system_clock::to_time_t(ev.creationTime());
    os << std::ctime(&creationTime);

    return os;
}


#endif //TIMERCALLBACK_EVENTS_H
