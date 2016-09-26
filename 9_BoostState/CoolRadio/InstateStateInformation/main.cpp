#include <iostream>
#include <string>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/statechart/custom_reaction.hpp>


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

struct EvFmTuner : sc::event<EvFmTuner>{};
struct EvAmTuner : sc::event<EvAmTuner>{};
struct EvOn : sc::event<EvOn>{};
struct EvOff : sc::event<EvOff>{};
struct EvTuner : sc::event<EvTuner> {};
struct EvCD : sc::event<EvCD> {};
struct EvCDInserted : sc::event<EvCDInserted> {};
struct EvEject : sc::event<EvEject> {};
struct EvCDState : sc::event<EvCDState> {
    EvCDState(bool isCD): isCD_(isCD){};


    bool isCD_;
};

struct FmTuner;
struct AmTuner;
struct On;
struct Off;
struct RadioPlaying;
struct CDLoading;
struct CDPlaying;

struct Machine : sc::state_machine<Machine, Off>
{
    bool cdIn_;
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
    /* typedef boost::mpl::list<sc::transition<EvCDInserted, CDLoading>,
             sc::transition<EvCD, CDPlaying>
     >reactions;*/

    typedef sc::custom_reaction<EvCD> reactions;
    sc::result react(const EvCD&);
};

sc::result RadioPlaying::react(const EvCD&)
{

    if(!context<Machine>().cdIn_)
        return discard_event();
    else
        return transit<CDPlaying>();
}
struct FmTuner : sc::simple_state<FmTuner, RadioPlaying>
{
    PRINT_ENTRY_EXIT(2, FmTuner);

    typedef sc::transition<EvAmTuner, AmTuner> reactions;

};

struct AmTuner : sc::simple_state<AmTuner, RadioPlaying>
{
    PRINT_ENTRY_EXIT(2, AmTuner);

    typedef sc::transition<EvFmTuner, FmTuner> reactions;

};

struct CDLoading : sc::simple_state<CDLoading, On>
{
    /* Missing code */

    typedef boost::mpl::list<sc::custom_reaction<EvCDState>, sc::transition<EvEject, RadioPlaying > > reactions;
    PRINT_ENTRY_EXIT(1, CDLoading);



    /* Missing code */

    sc::result react(const EvCDState & ev){
        if(ev.isCD_)
            return transit<CDPlaying>();
        else
            return transit<RadioPlaying>();
    }



};

struct CDPlaying : sc::simple_state<CDPlaying, On>
{
    typedef sc::transition<EvTuner, RadioPlaying > reactions;

    PRINT_ENTRY_EXIT(1, CDPlaying);
};
int main()
{
    Machine myMachine;
    myMachine.initiate();

    myMachine.process_event(EvOn());
    myMachine.process_event(EvAmTuner());
    myMachine.process_event(EvCDInserted());
    myMachine.process_event(EvCDState(true));
    myMachine.process_event(EvTuner());

    myMachine.cdIn_ = true;
    myMachine.process_event(EvCD());

    myMachine.process_event(EvOff());
    myMachine.process_event(EvOn());
    myMachine.process_event(EvTuner());

    return 0;
}