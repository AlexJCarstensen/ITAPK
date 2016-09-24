//
// Created by carty on 9/14/16.
//

#ifndef TIMERCALLBACK_BINDFUNCTION_H
#define TIMERCALLBACK_BINDFUNCTION_H


/*****************************************/
/* Copyright: DevelEdu 2013              */
/* Author: sha                           */
/*****************************************/

// bindanyfunction.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <mutex>
#include <functional>
#include "Events.h"
#include "Timer.h"

std::mutex stdioProt;


void freeFunction( const std::shared_ptr<Event>& event )
{
   // Protecting stdio since its not thread safe
  std::lock_guard<std::mutex> lock(stdioProt );

    /* MISSING EVENT PRINT OUT */

}


void withAnExtra(const std::shared_ptr<Event>& event, const std::string text)
{
   // Protecting stdio since its not thread safe
  std::lock_guard<std::mutex> lock(stdioProt );

  /* MISSING EVENT PRINT OUT */

}


class ReferenceObj
{
public:
   ReferenceObj() : called_(0)
   {
   }

  void call( const std::shared_ptr<Event>& event )
  {
    // Protecting stdio since its not thread safe
    std::lock_guard<std::mutex> lock(stdioProt );

    /* MISSING EVENT PRINT OUT */

    ++called_;
  }

   int gotCalled()
   {
      return called_;
   }

private:
   int   called_;
};






#endif //TIMERCALLBACK_BINDFUNCTION_H
