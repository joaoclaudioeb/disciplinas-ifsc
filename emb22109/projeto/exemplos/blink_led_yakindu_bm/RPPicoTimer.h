#ifndef RPPICOTIMER_H
#define RPPICOTIMER_H

#include "./src/sc_timer.h"
#include "hardware/timer.h"
#include <map>

class RPPicoTimer : public sc::timer::TimerServiceInterface {
public:
    void setTimer(sc::timer::TimedInterface* statemachine, sc_eventid event, sc_time time_ms, sc_boolean isPeriodic) override {
        absolute_time_t target_time = make_timeout_time_ms(time_ms);
        timers[event] = target_time;
        periodic[event] = isPeriodic;
        periods[event] = time_ms;
        machines[event] = statemachine;
    }

    void unsetTimer(sc::timer::TimedInterface* statemachine, sc_eventid event) override {
        timers.erase(event);
        periodic.erase(event);
        periods.erase(event);
        machines.erase(event);
    }

    void processTimers() {
        absolute_time_t now = get_absolute_time();
        for (auto it = timers.begin(); it != timers.end(); ) {
            if (absolute_time_diff_us(now, it->second) <= 0) {
                machines[it->first]->raiseTimeEvent(it->first);
                if (periodic[it->first]) {
                    it->second = make_timeout_time_ms(periods[it->first]);
                    ++it;
                } else {
                    periodic.erase(it->first);
                    periods.erase(it->first);
                    machines.erase(it->first);
                    it = timers.erase(it);
                }
            } else {
                ++it;
            }
        }
    }

private:
    std::map<sc_eventid, absolute_time_t> timers;
    std::map<sc_eventid, bool> periodic;
    std::map<sc_eventid, sc_time> periods;
    std::map<sc_eventid, sc::timer::TimedInterface*> machines;
};

#endif
