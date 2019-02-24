#include "tools.h"
#include <iostream>
#include <cmath>

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;
using std::cout;
using std::endl;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
   * TODO: Calculate the RMSE here.
   */

   VectorXd rmse(4);
   rmse << 0,0,0,0;

   // TODO: YOUR CODE HERE
   // check the validity of the following inputs:
   //  * the estimation vector size should not be zero
   //  * the estimation vector size should equal ground truth vector size

   
   if (estimations.size() != ground_truth.size()
      || estimations.size() == 0) {
      cout << "Invalid estimation or ground_truth data" << endl;
      return rmse;
   }

   // accumulate squared residuals
   for (unsigned int i=0; i < estimations.size(); ++i) {

      VectorXd residual = estimations[i] - ground_truth[i];

      // coefficient-wise multiplication
      residual = residual.array()*residual.array();
      rmse += residual;
   }

   // calculate the mean
   rmse = rmse/estimations.size();

   // calculate the squared root
   rmse = rmse.array().sqrt();
   

   // return the result
   return rmse;

}

MatrixXd Tools::CalculateJacobian(const VectorXd& x_state) {
  /**
   * TODO:
   * Calculate a Jacobian here.
   */

   MatrixXd H = MatrixXd::Zero(3,4);

   float px = x_state(0);
   float py = x_state(1);
   float vx = x_state(2);
   float vy = x_state(3);

   float den1 = sqrt(px*px + py*py);
   float den2 = px*px + py*py;
   float den3 = den1*den2;

   H(0,0) = px/den1;
   H(0,1) = py/den1;
   H(0,2) = 0;
   H(0,3) = 0;
   H(1,0) = -py/den2;
   H(1,1) = px/den2;
   H(1,2) = 0;
   H(1,3) = 0;
   H(2,0) = py*(vx*py - vy*px)/den3;
   H(2,1) = px*(vy*px - vx*py)/den3;
   H(2,2) = px/den1;
   H(2,3) = py/den1;
   
   return H;

}
