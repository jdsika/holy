/*  HOly Walk walk.cpp
 *  Ways to move limbs that make the robot walk
 *  Laurenz & Simon 2015-05-29
 */

#ifndef _WALK_H_
#define _WALK_H_

#include "../poses/poses.h"
#include "fsm_defines.h"

class Core;

class Walk {
public:
    Walk(Core* core);

    void executeStateMachine();

    // FSMs
    typedef enum {iSHIFT_LEFT,iLIFT_RIGHT,iFWD_RIGHT,iDUAL_RIGHT, iSHIFT_FRONT_RIGHT} INIT_FSM;
    typedef enum {lLIFT_LEFT,lFWD_LEFT,lDUAL_LEFT,lSHIFT_FRONT_LEFT,lLIFT_RIGHT,lFWD_RIGHT,lDUAL_RIGHT,lSHIFT_FRONT_RIGHT} LOOP_FSM;
    typedef enum {sLIFT_LEFT,sFWD_LEFT,sLIFT_RIGHT,sFWD_RIGHT,sDEFAULT} STOP_FSM;

    Walk_FSM walk_fsm;
    INIT_FSM init_fsm;
    LOOP_FSM loop_fsm;
    STOP_FSM stop_fsm;

    // State machine
    void StateMachine();

    void init_StateMachine();


private:
    Core* core;
    // poses object
    Poses walk_poses;

};

#endif
