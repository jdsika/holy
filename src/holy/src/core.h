/*  HOly Walk Core.cpp
 *  Talk to MoveIt Planner and talk to Bioloid motors
 *  Laurenz & Simon 2015-05-29
 */

#ifndef _CORE_H_
#define _CORE_H_

#include <map>

#include <moveit/robot_model/robot_model.h>
#include <moveit/planning_scene/planning_scene.h>
#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_interface/planning_interface.h>

// Forward declarations
namespace ros{
class NodeHandle;
}
namespace tf{
class TransformListener;
class StampedTransform;
}



class Core {
public:
    Core(int argc, char **argv);
    ~Core();

    enum class Limb {LEFT_HAND, RIGHT_HAND, LEFT_FOOT, RIGHT_FOOT};

    tf::StampedTransform* getTF(Limb limb);

    void setPoseTarget(Limb limb, geometry_msgs::Pose pose);
    std::string getLimbString(Core::Limb limb) const;
    void move();
    void moveto_default_state();

private:

    ros::NodeHandle *node_handle;

    moveit::planning_interface::MoveGroup *group;

    tf::TransformListener *listener;
    std::map<Limb, tf::StampedTransform*> transforms;


};

#endif
