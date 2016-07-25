// Copyright 2016 Chih-Chung Chou
#ifndef KINEMATICS_MATRIX_TYPES_H_
#define KINEMATICS_MATRIX_TYPES_H_

#include <Eigen/Dense>

namespace kinematics {

  typedef Eigen::Matrix<double, 1, 1> Vector1d;
  typedef Eigen::Matrix<double, 2, 1> Vector2d;
  typedef Eigen::Matrix<double, 3, 1> Vector3d;
  typedef Eigen::Matrix<double, 4, 1> Vector4d;
  typedef Eigen::Matrix<double, 5, 1> Vector5d;
  typedef Eigen::Matrix<double, 6, 1> Vector6d;
  typedef Eigen::Matrix<double, 7, 1> Vector7d;
  typedef Eigen::Matrix<double, 8, 1> Vector8d;
  typedef Eigen::Matrix<double, 9, 1> Vector9d;

  typedef Eigen::Matrix<double, 1, 1> Matrix1d;
  typedef Eigen::Matrix<double, 2, 2> Matrix2d;
  typedef Eigen::Matrix<double, 3, 3> Matrix3d;
  typedef Eigen::Matrix<double, 4, 4> Matrix4d;
  typedef Eigen::Matrix<double, 5, 5> Matrix5d;
  typedef Eigen::Matrix<double, 6, 6> Matrix6d;
  typedef Eigen::Matrix<double, 7, 7> Matrix7d;
  typedef Eigen::Matrix<double, 8, 8> Matrix8d;
  typedef Eigen::Matrix<double, 9, 9> Matrix9d;
} // namespace kinematics

#endif // KINEMATICS_MATRIX_TYPES_H_
