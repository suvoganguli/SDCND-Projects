#include "kalman_filter.h"
#include "tools.h"
#define PI 3.14159265

using Eigen::MatrixXd;
using Eigen::VectorXd;

/* 
 * Please note that the Eigen library does not initialize 
 *   VectorXd or MatrixXd objects with zeros upon creation.
 */

KalmanFilter::KalmanFilter() {}

KalmanFilter::~KalmanFilter() {}

void KalmanFilter::Init(VectorXd &x_in, MatrixXd &P_in, MatrixXd &F_in,
                        MatrixXd &H_in, MatrixXd &R_in,  MatrixXd &R2_in, 
                        MatrixXd &Q_in) {
  x_ = x_in;
  P_ = P_in;
  F_ = F_in;
  H_ = H_in;
  R_ = R_in;
  R2_ = R2_in;
  Q_ = Q_in;
}

void KalmanFilter::Predict() {
  /**
   * TODO: predict the state
   */

    x_ = F_ * x_;
    MatrixXd F_t = F_.transpose();
    P_ = F_ * P_ * F_t + Q_;

}

void KalmanFilter::Update(const VectorXd &z) {
  /**
   * TODO: update the state by using Kalman Filter equations
   */
  
  MatrixXd I_ = MatrixXd::Identity(4, 4);

  VectorXd y_ = z - H_ * x_;
  MatrixXd H_t = H_.transpose();
  MatrixXd S_ = H_ * P_ * H_t + R_;
  MatrixXd S_i = S_.inverse();
  MatrixXd K_ =  P_ * H_t * S_i;

  x_ = x_ + (K_ * y_);
  P_ = (I_ - K_ * H_) * P_;
  
}

void KalmanFilter::UpdateEKF(const VectorXd &z) {
  /**
   * TODO: update the state by using Extended Kalman Filter equations
   */

  Tools tools;
  float px = x_[0];
  float py = x_[1];
  float vx = x_[2];
  float vy = x_[3];
  
  MatrixXd I_ = MatrixXd::Identity(4,4);
  MatrixXd Hj_ = MatrixXd::Zero(3,4);
  
  Hj_= tools.CalculateJacobian(x_);

  VectorXd hx(3);
  float rho = sqrt( px*px + py*py );
  if (rho != 0){
    hx << rho, atan2( py, px ), ( px*vx + py*vy )/rho;
  }
  else {
    hx << rho, atan2( py, px ), 0;
  }

  VectorXd y_ = z - hx;

  if( y_[1] > PI )
    y_[1] -= 2*PI;
  if( y_[1] < -PI )
    y_[1] += 2*PI;

  MatrixXd Hj_t = Hj_.transpose();
  MatrixXd S_ = Hj_ * P_ * Hj_t + R2_;
  MatrixXd S_i = S_.inverse();
  MatrixXd K_ =  P_ * Hj_t * S_i;

  x_ = x_ + (K_ * y_);
  P_ = (I_ - K_ * Hj_) * P_;


}

