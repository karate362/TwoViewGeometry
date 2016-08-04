// Copyright 2016 Chih-Chung Chou
#include <algorithm>
#include <iostream>
#include "gtest/gtest.h"

#include "kinematics/rotation3.h"

using kinematics::Matrix3d;
using kinematics::Rotation3;
using kinematics::Vector3d;
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

TEST(Rotation3Test, TestRotation) {
  // A ground truth from Octave (https://www.gnu.org/software/octave/)
  Vector3d v3d_src;
  Vector3d v3d_tgt, v3d_result;
  Vector3d v3d_inv_tgt, v3d_inv_result;
  Matrix3d Rm;
  v3d_src << 123.531, 332.434, 5654.599;
  v3d_tgt << -3464.041646, 3458.651009, 2852.790003;
  v3d_inv_tgt << 1304.692128, -4478.85664, 3215.257963;

  Rm << 0.748304689, -0.2505358843, -0.6142246031,
        0.639361744, 0.5191751646, 0.5671628592,
        0.1767955109, -0.8171223404, 0.54868427;

  Rotation3 Rx;
  Rx.FromRotationMatrix(Rm);

  v3d_result = Rx.Rotate(v3d_src);
  v3d_inv_result = Rx.InverseRotate(v3d_src);
  EXPECT_TRUE((Rx.GetRotationMatrix()*v3d_src - v3d_tgt).norm() < 1e-6);
  EXPECT_TRUE((v3d_result - v3d_tgt).norm() < 1e-6);
  EXPECT_TRUE((v3d_inv_result - v3d_inv_tgt).norm() < 1e-6);
}
