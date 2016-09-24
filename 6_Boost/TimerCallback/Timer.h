//
// Created by carty on 9/14/16.
//

#ifndef TIMERCALLBACK_TIMER_H
#define TIMERCALLBACK_TIMER_H

#include <iostream>
#include <string>
#include <map>
#include <thread>
#include <functional>
#include <chrono>
#include <boost/any.hpp>
#include "Events.h"

using namespace std;


class Timer
{
public:
    explicit Timer(int timer = 10) :
            eventTimer_(timer), terminator_(false)
    {
        thread_ = new thread(bind(&Timer::timerThreadFunction, this));
    }


    ~Timer()
    {
        terminator_ = true;
        thread_->join();
        delete thread_;
    }

    int attach(function<void(const shared_ptr<Event> &)>)
    {

    }

private:
    int timerThreadFunction()
    {
        int counter = 0;
        while (!terminator_)
        {
            chrono::milliseconds sleepFor(1000);
            this_thread::sleep_for(sleepFor);

            notifyAll(make_shared<Event>());
            if (++counter >= eventTimer_)
            {
                counter = 0;
                cout << "EventOther created..." << endl;

                notifyAll(make_shared<EventOther>());
            }
        }
        return 0;
    }

    void notifyAll(const shared_ptr<Event> &any)
    {

    }

private:
    int eventTimer_;
    thread *thread_;
    bool terminator_;
};


#endif //TIMERCALLBACK_TIMER_H
