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
#define PRINT_ENTRY_EXIT(lvl, name)             \
  name() { print(lvl, #name"()"); }             \
  ~name() { print(lvl, "~"#name"()"); }

namespace sc = boost::statechart;

struct EvFmTune : sc::event<EvFmTune>{};
struct EvAmTune : sc::event<EvAmTune>{};
struct EvOn : sc::event<EvOn>{};
struct EvOff: sc::event<EvOff>{};

struct FmTuner;
struct AmTuner;
struct On;
struct Off;
struct RadioPlaying;

struct Machine : sc::state_machine<Machine, Off>
{
};

struct Off : sc::simple_state<Off, Machine>
{
    typedef sc::transition<EvOn, On> reactions;
    PRINT_ENTRY_EXIT(0, Off);
};
struct On : sc::simple_state<On, Machine, RadioPlaying>
{
    typedef sc::transition<EvOff, Off> reactions;
    PRINT_ENTRY_EXIT(0, On);
};

struct RadioPlaying : sc::simple_state<RadioPlaying, On, FmTuner>
{
    PRINT_ENTRY_EXIT(1, RadioPlaying);
    typedef sc::transition<EvFmTune, RadioPlaying> reactions;
};

struct FmTuner : sc::simple_state<FmTuner, RadioPlaying>
{
    PRINT_ENTRY_EXIT(1, FmTuner);

    typedef sc::transition<EvAmTune, AmTuner> reactions;

};

struct AmTuner : sc::simple_state<AmTuner, RadioPlaying>
{
    PRINT_ENTRY_EXIT(1, AmTuner);


    typedef sc::transition<EvFmTune, FmTuner> reactions;

};


int main()
{
    Machine machine;
    machine.initiate();
    
    machine.process_event(EvOn());
    machine.process_event(EvAmTune());
    machine.process_event(EvOff());

    return 0;
}