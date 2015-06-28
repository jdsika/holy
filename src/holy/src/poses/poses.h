/*  HOly Walk walk.cpp
 *  A number of poses that the robot can move to.
 *  Laurenz & Simon & Carlo 2015-06-11
 */

#ifndef _POSES_H_
#define _POSES_H_

#include "robopose.h"
#include "limbpose.h"

#include <vector>


class Poses
{

// R, P, Y, X, Y, Z
// Feet: Toes up(+) down(-) / ankles left(+) right(-) / twist left right / X / Y / Z
// Hands: Arms up down / ? / ? / (X) / (Y) / (Z)

// Invert for L/R:
// Feet:  No / Yes / Yes / Yes / No / No
// Hands: No / ?   / Yes / Yes / No / No


// The Poses class contains a number of poses that can be used in a state
// machine with the goal of having the robot fulfill its tasks.

private:
    double step_length,step_height,turning_angle;

    // Compute Z offset due to weight shifting
    static inline double compute_Z_off(double angle)
    {
        return tan(angle* M_PI / 180.0)*(0.078); // von der Mitte der Gelenke gemessen
    }

public:

    Poses();
    ~Poses();

    void update();

    static inline double d2r(const double degree)
    {
        return M_PI*degree/180.0;
    }

    static inline double r2d(const double radian)
    {
        return 180.0*radian/M_PI;
    }


    // The default pose is the basic pose that must be used as offset for other relatively defined poses
    static RoboPose pose_default;

    // POSES FOR WALKING
    RoboPose shift_toleft;
    RoboPose shift_toright;
    RoboPose lift_right;
    RoboPose lift_left;
    RoboPose turn_right;
    RoboPose turn_left;
    RoboPose fwd_right;
    RoboPose fwd_left;
    RoboPose dual_right;
    RoboPose dual_left;
    RoboPose arms_fwd_left_foot;
    RoboPose arms_fwd_right_foot;

    RoboPose init_shift_toleft;
    RoboPose init_lift_right;
    RoboPose init_fwd_right;
    RoboPose init_dual_right;
    RoboPose init_shift_frontright;

    RoboPose loop_lift_left;
    RoboPose loop_fwd_left;
    RoboPose loop_dual_left;
    RoboPose loop_shift_frontleft;
    RoboPose loop_lift_right;
    RoboPose loop_fwd_right;
    RoboPose loop_dual_right;
    RoboPose loop_shift_frontright;

    RoboPose stop_lift_left;
    RoboPose stop_fwd_left;
    RoboPose stop_lift_right;
    RoboPose stop_fwd_right;

    // POSES FOR FIGHTING
    RoboPose fight_stance;
    RoboPose fight_punch_right_forward;
    RoboPose fight_punch_left_forward;

    void set_step_length(double length);
    void set_step_height(double height);
    void set_turning_angle(double angle);

};

#endif
