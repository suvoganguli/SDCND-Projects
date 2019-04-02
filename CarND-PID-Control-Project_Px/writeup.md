# PID Controller

### Udacity Self Driving Car Nanodegree Project

------

### Compilation

The project can be compiled with `cmake .. && make`

### Implementation

I initially tried implementing with the twiddle algorithm. However, the challenge was that the twiddle algotihm reaquires to call the simulator several time during tuning as shown in the class example - this was challenging to do to in the implementation of twiddle. It was far easier and less time consuming to tune the PID control law with trial and error.

The main guidleline for tuning a PID control law is that:

- P control sets the "bandwidth" of the closed loop. Initially after some trial and error the value was chosen to be 0.075 (change later to 0.05) Another guibeline for tuning was the initialling was the initial steering angle. With a value of 0.05, the initial steering angle was around -0.04 ... near zero as expected. Howver, the car eventually was hitting the left lane boundary. This motivated the addition of the I control which is supposed to improve tracking.

- I control sets the traking performance. Starting with a value of 1, it was quickly realized that larger values resulted in oscillator response. Further that P control seems to be two low and the initial steering angle changed. With a few iterations it was observed that the P & I values of 0.05 and 0.001 produced better result - the car was more or less staying within the lane for the most of the time

- D control was added as the response of the PI control was still oscillary during the turns. After a couple of iterations, starting from 1, it was realized that a value of 2 was sufficient for lane keeping.

  The final values for the PID control are [0.05, 0.001, 2]                      

## Reflection

My experience is that an algorithm like twiddle, though interesting and powerful, is more suited for an application where the simulator can be called multiple times in a loop during tuning - as opposed the calling the function each time during the tuning. The former was not posslble in the project.

One of the goals for this lesson is exposure to the twiddle algorithm - which I already got from the quiz in the class. Hence I was not motivated to implement twiddle in this project. I did spend considerable to implement twiddle, but it was time consuming to debug, and given the time I had, I couldn't afford to spend more time, since I already for the solution using the iterative method.

PID tuning need not be a blind guesswork based iterative design. With some control backgound (which I have), it is posslble to linearize the model and look at the frequence response to tune the control to aid the design. The basic guideline is the use the P controt to set the speed of response, the I control for tracking, and the D control for increasing the damping.

The was the hyperparameters are chosen are described in the section above.

Note that a video of the simulator is added since the required code and instructions are not available. Also based upon the rubric, a submission was encouraged but not mandatorty.

------















