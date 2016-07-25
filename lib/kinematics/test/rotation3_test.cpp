// Copyright 2016 Chih-Chung Chou
#include <algorithm>
#include <iostream>
#include "gtest/gtest.h"

#include "kinematics/rotation3.h"

using kinematics::Matrix3d;
using kinematics::Rotation3;
using kinematics::Vector4d;

TEST(Rotation3Test, TestNullPtr) {
  Rotation3 Rx;
  Vector4d quat;
  quat << 1.0, 0.0, 0.0, 0.0;
  EXPECT_TRUE(Rotation3::GetRotation3FromQuaternion(quat, &Rx));
  EXPECT_FALSE(Rotation3::GetRotation3FromQuaternion(quat, nullptr));
}

TEST(Rotation3Test, TestQuaternion) {
  // A ground truth from http://www.energid.com/resources/quaternion-calculator/
  Vector4d quat;
  Matrix3d Rt;
  quat << 0.18260418, 0.36510837, -0.54771256, 0.73031674;
  Rt << -0.666703178340727, -0.666666666666667, 0.333260299984754,
        -0.133231088645414, -0.333333333333334, -0.933347934002774,
        0.733318722663434, -0.666666666666667, 0.133413667016633;

  Rotation3 Rx;
  Rx.FromQuaternion(quat);
  Matrix3d Rm = Rx.GetRotationMatrix();
  EXPECT_TRUE((Rm - Rt).norm() < 1e-6);
}
