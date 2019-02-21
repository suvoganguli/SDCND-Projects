#include "kalman_filter.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;

/* 
 * Please note that the Eigen library does not initialize 
 *   VectorXd or MatrixXd objects with zeros upon creation.
 */

KalmanFilter::KalmanFilter() {}

KalmanFilter::~KalmanFilter() {}

void KalmanFilter::Init(VectorXd &x_in, MatrixXd &P_in, MatrixXd &F_in,
                        MatrixXd &H_in, MatrixXd &R_in, MatrixXd &Q_in) {
  x_ = x_in;
  P_ = P_in;
  F_ = F_in;
  H_ = H_in;
  R_ = R_in;
  Q_ = Q_in;
}

void KalmanFilter::Predict() {
  /**
   * TODO: predict the state
   */
    VectorXd u;	
    
    x_ = F_ * x_ + u;
    MatrixXd F_t = F_.transpose();
    P_ = F_ * P_ * F_t + Q_;
}

void KalmanFilter::Update(const VectorXd &z) {
  /**
   * TODO: update the state by using Kalman Filter equations
   */
    MatrixXd I_;

    VectorXd y_ = z - H_ * x_;
    MatrixXd H_t = H_.transpose();
    MatrixXd S_ = H_ * P_ * H_t + R_;
    MatrixXd S_i = S_.inverse();
    MatrixXd K_ =  P_ * H_t * S_i;

    I_ = MatrixXd::Identity(2, 2);

    x_ = x_ + (K_ * y_);
    P_ = (I_ - K_ * H_) * P_;


}

void KalmanFilter::UpdateEKF(const VectorXd &z) {
  /**
   * TODO: update the state by using Extended Kalman Filter equations
   */

  
}
