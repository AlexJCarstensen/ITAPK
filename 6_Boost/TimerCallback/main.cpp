#include <iostream>
#include "Timer.h"
#include "BindFunction.h"

int main()
{
    // Try to make several timers with different callbacks
    Timer t1( 4 );
    t1.attach( freeFunction );



    // The threads run naturally in the background (no clean up has been added for the threads)


    // You might wanna change the loop below such that you can extract the value of called_
    //  from your instance of ReferenceObj
    for(;;)
    {
        std::chrono::milliseconds sleepFor(1000);
        std::this_thread::sleep_for(sleepFor);
    }


    return EXIT_SUCCESS;
}