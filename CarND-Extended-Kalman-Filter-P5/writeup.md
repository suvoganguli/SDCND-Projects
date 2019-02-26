# Extended Kalman Filter Project
**Self-Driving Car Engineer Nanodegree Program**



## Introduction

This document presents the details of the extended Kalman filter project for the self driving car nanodegree program. The goal of the project is to design a Kalman filter which tracks a car using Lidar and Radar measurements. The desired performance specification is to get the position root mean squared error (RMSE) error below 0.11 m and the velocity estimation RMSE error below 0.52 m. The picture below shows that the desired performance specification is met. 

The code for the project is located in [repo](https://github.com/suvoganguli/SDCND-Projects) in the folder "[CarND-Extended-Kalman-Filter-P5](https://github.com/suvoganguli/SDCND-Projects/tree/master/CarND-Extended-Kalman-Filter-P5)".

![EKF performance](/home/suvoganguli/Projects/Udacity/SDCND-Projects/CarND-Extended-Kalman-Filter-P5/EKF.png)

---

## Compiling

The github files can be compiled using "cmake .." and "make".



## Accuracy

The desired specification -  "px, py, vx, and vy RMSE should be less than or equal to the values [.11, .11, 0.52, 0.52]" - are met.



## Follows the Correction Algorithm

The code is developed based on the following steps:

- The states are initialized based on:
  - The R matrix are defined based on the default values provided in the project.
  - The H matrix for the Lidar is [[1 0 0 0], [0 1 0 0]] which selects the first two states px and py. The H matrix for the Radar is initialized as zero matrix, but the values are reset after the first Radar measurements are received.
  - The P matrix is selected as a diagonal matrix with 10 as the first two diagonal elements and 100 on the last two diagonal elements. The number 10 denotes a variance of 10 m for the positions, and 100 denotes a variance of 100 m/s for the velocities.
  - The F and Q matrices is set as a zero matrices before the first measurement are received.
  - The state estimate vector x is set to [1 1 0 0] before the first measurements are received.
- After the first measurements are received the following steps are used:
  - If the first measurements are from lidar then the position measurements are used to initialize the position estimates. The velocity estimates are set to zero. If the first measurements are from radar, the measurements are converted from polar and cartesian coordinates, and then used to initialize both the position and velocity estimates.
  - The term dt is set to zero initially.

- After initialization, the Kalman filter prediction and update equations are used to generate the position and velocity estimates. Note that for the lidar measurements the H matrix remains constant. However for the radar measurements the Jacobian of the measurement function h(x) is used, where h(x) denotes the function which converts the polar coordinate measurements to cartesian coordinates.



## Analysis

The project is also developed using Python to cross check the C++ results, and also to analyze based on plots for the position and velocity estimates. Specifically, the P matrix is used to calculate the standard deviation of the position and velocity estimates. The bounds for the state estimate errors are compared with 2 x standard deviations, which denotes 95% accuracy. 

The plots below shows:

- Position and velocity estimates
- Position and velocity estimate errors
- Position and velocity RMSEs 



![px, py ](/home/suvoganguli/Projects/Udacity/SDCND-Projects/CarND-Extended-Kalman-Filter-P5/position.png)



![vx, vy](/home/suvoganguli/Projects/Udacity/SDCND-Projects/CarND-Extended-Kalman-Filter-P5/velocity.png)

![pos-err](/home/suvoganguli/Projects/Udacity/SDCND-Projects/CarND-Extended-Kalman-Filter-P5/position-error.png)

![vel-err](/home/suvoganguli/Projects/Udacity/SDCND-Projects/CarND-Extended-Kalman-Filter-P5/velocity-error.png)

![rmse-pos](/home/suvoganguli/Projects/Udacity/SDCND-Projects/CarND-Extended-Kalman-Filter-P5/rmse-position.png)

![rmse-vel](/home/suvoganguli/Projects/Udacity/SDCND-Projects/CarND-Extended-Kalman-Filter-P5/rmse-velocity.png)

## Conclusion

It is a great experience completing this project, especially with my limited knowledge in C++.

