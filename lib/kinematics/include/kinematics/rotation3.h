// Copyright 2016 Chih-Chung Chou
#ifndef KINEMATICS_ROTATION3_H_
#define KINEMATICS_ROTATION3_H_

#include "kinematics/matrix_types.h"

namespace kinematics {

// A class defines the rotations in 3d spaces.
class Rotation3{
 public:
  // Default constructor.
  Rotation3();

  // Default destructor.
  ~Rotation3();

  // Set a Rotation3 object from a Quaternion.
  //
  // Param[in] quat: Input quaternion (w, x, y, z).
  //
  // Return True if the input quaternion is valid, false if not.
  bool FromQuaternion(const Vector4d& quat);

  // Set a Rotation3 object from a rotation matrix.
  //
  // Param[in] Rm: Input rotation matrix.
  //
  // Return True if the input quaternion is valid, false if not.
  bool FromRotationMatrix(const Matrix3d& Rm);

  // Create a Rotation3 object from a Quaternion.
  //
  // Param[in] quat: Input quaternion (w, x, y, z).
  // Param[out] Rx: Rotation3 object.
  //
  // Return True if the input quaternion is valid, false if not.
  static bool GetRotation3FromQuaternion(const Vector4d& quat, Rotation3* Rx);

  // Get a Rotation3 object from a rotation matrix.
  //
  // Param[in] Rm: Input rotation matrix.
  // Param[out] Rx: Rotation3 object.
  //
  // Return True if the input rotation matrix is valid, false if not.
  static bool GetRotation3FromRotationMatrix(const Matrix3d& Rm, Rotation3* Rx);

  // Get the rotation matrix.
  Matrix3d GetRotationMatrix() const;

  // Get the Quaternion.
  Vector4d GetQuaternion() const {return quat_;};

  // Rotate a 3d point.
  //
  // Param[in] px: The point data to be rotated.
  //
  // Return: The rotated point.
  Vector3d Rotate(const Vector3d& px) const;

  // Inversely rotate a 3d point.
  //
  // Param[in] px: The point data to be rotated.
  //
  // Return: The rotated point.
  Vector3d InverseRotate(const Vector3d& px) const;

 private:
  // Quaternion representation (w, x, y, z).
  Vector4d quat_;
};

}  // namespace kinematics

#endif  // KINEMATICS_ROTATION3_H_
