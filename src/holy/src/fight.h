/*  HOly Fight Fight.cpp
 *  Ways to move limbs that make the robot Fight
 *  Laurenz & Simon 2015-05-29
 */

#ifndef _Fight_H_
#define _Fight_H_

#include "poses/poses.h"
#include "holy_fsm_defines.h"

class Core;

class Fight {
public:
    Fight(Core* core);
    ~Fight();

    Fight_FSM fight_fsm;

    // State machine
    void StateMachine();

    void init_StateMachine();

    typedef enum {RP_forward, RP_sideways, LP_forward, LP_sideways} LOOP_FSM;


private:
    Core* core;
    // poses object
    Poses fight_poses;
    LOOP_FSM loop_fsm;
};

#endif
