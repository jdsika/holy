/*  HOly Walk walk.cpp
 *  Ways to move limbs that make the robot walk
 *  Laurenz & Simon 2015-05-29
 */

#ifndef _WALK_H_
#define _WALK_H_


#include <geometry_msgs/Pose.h>

#include "core.h"

class Walk {
public:
    Walk(Core* core);
    ~Walk();

    struct pose {
        double roll, pitch, yaw, x, y, z;
    };

    struct pose getDefaultPose();
    struct pose getActualPose();

    geometry_msgs::Pose transformToPlan(Core::Limb limb, struct pose pose);


private:

    Core* core;


};

#endif
