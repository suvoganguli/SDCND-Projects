#include "PID.h"
#include <iostream>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
	Kp = Kp_;
  	Ki = Ki_;
  	Kd = Kd_;
  	p_error = 0;
  	i_error = 0;
    d_error = 0;
  
  	//error = 0;
  	//total_error = 0;
  	best_error = 1E10;
  	dp_tol = 0.1;
  
  	i = 0;
  	counter = 1; // first create error
  	counter_max = 4;
    
  	p = {Kp, Ki, Kd};
    dp = {0.1, 0.1, 0.1};
  	prev_cte = 0;
  
  	sum_dp = dp[0] + dp[1] + dp[2];
  
  	first_pass = 0;
  	second_pass = 0;
  
  	twiddle = 0;
  
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  
  	if (twiddle == 0){
  		p_error = cte;
  		d_error = cte - prev_cte;
  		i_error += cte;  
      	prev_cte = cte;
      	return;
    }

  	  
  	if ((twiddle==1) && (counter % counter_max < counter_max) && (i==0)){
      	p_error = cte;
  		d_error = cte - prev_cte;
  		i_error += cte;  
      	prev_cte = cte;
    	if (counter > counter_max/2){
        	error += cte*cte;
        }
      
        std::cout << "counter (error) = " << counter << std::endl;
        counter++;
      	
      	if (counter == counter_max){
          	error = error/counter_max;
        }
      
    }	
    
  
	if ((twiddle==1) && (sum_dp > dp_tol) && (counter % counter_max == 0)) { // if 0

      
      	std::cout << "counter (tune) = " << counter << std::endl;
      
      	std::cout << "i = " << i << std::endl;
		p[i] += dp[i];
 
      	std::cout << p[0] << " " << p[1] << " " << p[2] << std::endl;
        std::cout << dp[0] << " " << dp[1] << " " << dp[2] << std::endl;
      
  		if ((error < best_error) && (first_pass == 0)){ // if 1
          	first_pass = 1;
   			best_error = error;
    		dp[i] *= 1.1;
 			         
          	std::cout << "first pass" << std::endl;
              
		} // if 1
  		else{ // else 1
          
          	std::cout << "p " << p[0] << " " << p[1] << " " << p[2] << std::endl;
    		p[i] -= 2*dp[i];
            //std::cout << "p " << p[0] << " " << p[1] << " " << p[2] << std::endl;
          
    		if (error <  best_error){ // if 2
            	best_error = error;
                dp[i] *= 1.1;;
                std::cout << "p-if " << p[0] << " " << p[1] << " " << p[2] << std::endl;
    		} // if 2
            else{ // else 2
              	std::cout << "p' " << p[0] << " " << p[1] << " " << p[2] << std::endl;
            	p[i] += dp[i];
              	std::cout << "p-else " << p[0] << " " << p[1] << " " << p[2] << std::endl;
              	dp[i] *= 0.9;
              
            } //else 2
    	} //else 1

       
    	Kp = p[0];
		Ki = p[1];
    	Kd = p[2];
        //std::cout << "p " << p[0] << " " << p[1] << " " << p[2] << std::endl;
    	std::cout << "[Kp Ki Kd] = " << Kp << " " << Ki << " " << Kd << std::endl;       
      
    	sum_dp = dp[0] + dp[1] + dp[2];
    	
        if (i == 2){
          	i = 0;
            counter = 0;
            first_pass = 0;
        }
        else{
          	i++;
        }
    
	} // if 0
} // function
        
double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  
  total_error = Kp * p_error + Ki * i_error + Kd * d_error;
  
  return total_error;  // TODO: Add your total error calc here!
}