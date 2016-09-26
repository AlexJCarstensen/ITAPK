#include <iostream>
#include <string>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>

using namespace std;

void print(unsigned int lvl, const std::string &name)
{
    for (unsigned int i = 0; i < lvl; ++i)
        std::cout << "*";
    std::cout << " " << name << std::endl;
}

namespace sc = boost::statechart;

struct EvFmTune : sc::event<EvFmTune>{};
struct EvAmTune : sc::event<EvAmTune>{};

struct FmTuner;
struct AmTuner;

struct Machine : sc::state_machine<Machine, FmTuner>
{
};

struct FmTuner : sc::simple_state<FmTuner, Machine>
{
    FmTuner()
    { cout << __PRETTY_FUNCTION__ << endl; }

    ~FmTuner()
    { cout << __PRETTY_FUNCTION__ << endl; }

    typedef sc::transition<EvAmTune, AmTuner> reactions;

};

struct AmTuner : sc::simple_state<AmTuner, Machine>
{
    AmTuner()
    { cout << __PRETTY_FUNCTION__ << endl; }

    ~AmTuner()
    { cout << __PRETTY_FUNCTION__ << endl; }

    typedef sc::transition<EvFmTune, FmTuner> reactions;

};

int main()
{
    Machine machine;
    machine.initiate();


    machine.process_event(EvAmTune());
    machine.process_event(EvFmTune());
    return 0;
}