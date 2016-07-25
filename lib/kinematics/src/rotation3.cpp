// Copyright 2016 Chih-Chung Chou
#include <iostream>
#include <math.h>

#include "kinematics/rotation3.h"

namespace kinematics {

Rotation3::Rotation3() {
  quat_ << 1.0, 0.0, 0.0, 0.0;
}

Rotation3::~Rotation3() {}

bool Rotation3::GetRotation3FromQuaternion(
    const Vector4d& quat, Rotation3* Rx) {
  if (Rx == nullptr) {
    std::cout <<
        "Rotation3::GetRotation3FromQuaternion: null output" << std::endl;
    return false;
  }
  return Rx->FromQuaternion(quat);
}

bool Rotation3::FromQuaternion(const Vector4d& quat) {
  if (fabs(quat.norm() - 1.0) > 1e-6) {
    std::cout << "Rotation3::FromQuaternion: invalid quaternion" << std::endl;
    return false;
  }
  quat_ = quat;
  return true;
}

Matrix3d Rotation3::GetRotationMatrix() const {
  Matrix3d Rm;
  const double& qw = quat_(0);
  const double& qx = quat_(1);
  const double& qy = quat_(2);
  const double& qz = quat_(3);

  Rm << 1 - 2*qy*qy - 2*qz*qz, 2*qx*qy - 2*qz*qw, 2*qx*qz + 2*qy*qw,
       2*qx*qy + 2*qz*qw, 1 - 2*qx*qx - 2*qz*qz, 2*qy*qz - 2*qx*qw,
       2*qx*qz - 2*qy*qw, 2*qy*qz + 2*qx*qw, 1 - 2*qx*qx - 2*qy*qy;

  return Rm;
}

}  // namespace kinematics
