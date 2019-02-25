#include "FusionEKF.h"
#include <iostream>
#include "Eigen/Dense"
#include "tools.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::cout;
using std::endl;
using std::vector;
using std::sin;
using std::cos;

/**
 * Constructor.
 */
FusionEKF::FusionEKF() {
  is_initialized_ = false;

  previous_timestamp_ = 0;
  current_timestamp_ = previous_timestamp_;

  // initializing matrices
  R_laser_ = MatrixXd(2, 2);
  R_radar_ = MatrixXd(3, 3);
  H_laser_ = MatrixXd(2, 4);
  Hj_ = MatrixXd(3, 4);

  //measurement covariance matrix - laser
  R_laser_ << 0.0225, 0,
              0, 0.0225;

  //measurement covariance matrix - radar
  R_radar_ << 0.09, 0, 0,
              0, 0.0009, 0,
              0, 0, 0.09;

  /**
   * TODO: Finish initializing the FusionEKF.
   * TODO: Set the process and measurement noises
   */

  H_laser_ << 1, 0, 0, 0,
              0, 1, 0, 0;

  Hj_ << 0, 0, 0, 0,
         0, 0, 0, 0,
         0, 0, 0, 0;

  MatrixXd P(4, 4);
  P <<   1, 0, 0, 0,
	       0, 1, 0, 0,
         0, 0, 1000, 0,
         0, 0, 0, 1000;

  MatrixXd F = MatrixXd::Zero(4, 4);

  VectorXd x(4);
  x << 1, 1, 1, 1;

  MatrixXd Q = MatrixXd::Zero(4, 4);

  ekf_.Init( x, P, F, H_laser_, R_laser_, R_radar_, Q );

}

/**
 * Destructor.
 */
FusionEKF::~FusionEKF() {}

void FusionEKF::ProcessMeasurement(const MeasurementPackage &measurement_pack) {
  /**
   * Initialization
   */
  if (!is_initialized_) {
    /**
     * TODO: Initialize the state ekf_.x_ with the first measurement.
     * TODO: Create the covariance matrix.
     * You'll need to convert radar from polar to cartesian coordinates.
     */

    // first measurement
    cout << "EKF: " << endl;
    ekf_.x_ = VectorXd(4);
    ekf_.x_ << 1, 1, 1, 1;

    if (measurement_pack.sensor_type_ == MeasurementPackage::RADAR) {
      // TODO: Convert radar from polar to cartesian coordinates 
      //         and initialize state.
      VectorXd z = measurement_pack.raw_measurements_;
      float ro = z(0);
      float phi = z(1);
      float ro_dot = z(2);
      ekf_.x_(0) = ro*cos(phi);
      ekf_.x_(1) = ro*sin(phi);
      ekf_.x_(2) = ro_dot*cos(phi);
      ekf_.x_(3) = ro_dot*sin(phi);
    }
    else if (measurement_pack.sensor_type_ == MeasurementPackage::LASER) {
      // TODO: Initialize state.
      VectorXd z = measurement_pack.raw_measurements_;
      ekf_.x_(0) = z(0);
      ekf_.x_(1) = z(1);
      ekf_.x_(2) = 0;
      ekf_.x_(3) = 0;
    }

    current_timestamp_ = measurement_pack.timestamp_/1e6;

    // done initializing, no need to predict or update
    is_initialized_ = true;
    return;
  }

  /**
   * Prediction
   */

  /**
   * TODO: Update the state transition matrix F according to the new elapsed time.
   * Time is measured in seconds.
   * TODO: Update the process noise covariance matrix.
   * Use noise_ax = 9 and noise_ay = 9 for your Q matrix.
   */

  long long dt = current_timestamp_ - previous_timestamp_;
  previous_timestamp_ = current_timestamp_;

  ekf_.F_ << 1, 0, dt, 0,
            0, 1, 0, dt,
            0, 0, 1, 0,
            0, 0, 0, 1;


  long long dt4 = dt*dt*dt*dt;
  long long dt3 = dt*dt*dt;
  long long dt2 = dt*dt;
  float sx2 = 9;
  float sy2 = 9;

  ekf_.Q_<< dt4/4*sx2,      0,    dt3/2*sx2,  0,
            0,    dt4/4*sy2,   0,     dt3/2*sy2,
            dt3/2*sx2,      0,    dt2*sx2,    0,  
            0,    dt3/2*sy2,   0,     dt2*sy2;    

  ekf_.Predict();

  /**
   * Update
   */

  /**
   * TODO:
   * - Use the sensor type to perform the update step.
   * - Update the state and covariance matrices.
   */

  if (measurement_pack.sensor_type_ == MeasurementPackage::RADAR) {
    // TODO: Radar updates
    VectorXd z = measurement_pack.raw_measurements_;
    ekf_.UpdateEKF(z);


  } else {
    // TODO: Laser updates
    VectorXd z = measurement_pack.raw_measurements_;
    ekf_.Update(z);

  }

  // print the output
  //cout << "x_ = " << ekf_.x_ << endl;
  //cout << "P_ = " << ekf_.P_ << endl;
}
