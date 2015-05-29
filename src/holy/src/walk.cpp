#include "core.h"
#include "walk.h"

#include <geometry_msgs/Pose.h>

Walk::Walk(Core *core) : core{core}
{
    core->moveto_default_state();
    // wenn startpos erreicht, offset-TF speichern
}

Walk::~Walk()
{

}

Walk::pose Walk::getDefaultPose()
{
    struct pose p = {0,0,0,0,0,0};
    return p;
}

Walk::pose Walk::getActualPose()
{
    struct pose p = {0,0,0,0,0,0};
    return p;
}

geometry_msgs::Pose Walk::transformToPlan(Core::Limb limb, Walk::pose pose)
{
    geometry_msgs::Pose targetPose;
    tf::StampedTransform* transf = core->getTF(limb);
    tf::Matrix3x3 matrixZumDraufaddieren, matrixIstWerte;

    // winkel addieren
    matrixZumDraufaddieren.setRPY(pose.pitch, pose.roll, pose.yaw);
    matrixIstWerte.setRotation(transf->getRotation());
    matrixZumDraufaddieren *= matrixIstWerte;
    tf::Quaternion quat;
    matrixZumDraufaddieren.getRotation(quat);
    targetPose.orientation.x = quat.getX();
    targetPose.orientation.y = quat.getY();
    targetPose.orientation.z = quat.getZ();
    targetPose.orientation.w = quat.getW();

    // translation addieren
    targetPose.position.x = static_cast<double>(transf->getOrigin().x()) + pose.x;
    targetPose.position.y = static_cast<double>(transf->getOrigin().y()) + pose.y;
    targetPose.position.z = static_cast<double>(transf->getOrigin().z()) + pose.z;

    // Debug ausgabe
    double roll, pitch, yaw;
    matrixZumDraufaddieren.getRPY(roll, pitch, yaw);
    std::cout << "Transformation:\n  RPY: " << roll << " / " << pitch << " / " << yaw << "\n  XYZ: " << targetPose.position.x << " / " << targetPose.position.y  << " / " << targetPose.position.z << std::endl;

    return targetPose;
}
