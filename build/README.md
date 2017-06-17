# CarND-Controls-PID

## Self-Driving Car Engineer Nanodegree Program
### PID Control

A proportional–integral–derivative controller (PID controller) is a control loop feedback mechanism (controller) commonly used in industrial control systems. A PID controller continuously calculates an error value e ( t ) {\displaystyle e(t)} e(t) as the difference between a desired setpoint and a measured process variable and applies a correction based on proportional, integral, and derivative terms (sometimes denoted P, I, and D respectively) which give their name to the controller type.

### Intialization phase
* At initialized phase we need to provide p_error, i_error and d_error as 0. Also initialized coffecients as zero are provided.
* Smoothening parameters alphas's are all set as very small values here.


### Update phase
* Initially velocity is zero
* Coeffecients are set based on small velocity
 >> 	Kp = Kp0 + alpha_p * v_;
	Ki = Ki0 + alpha_i * v_;
	Kd = Kd0 + alpha_d * v_;
* Error is tuned as
	p_error = Kp* cte_;
	i_error = Ki * cte_mem_;
	d_error = Kd* (cte_-cte_prev_);
  where cte_ is current cross track error
        cte_mem_ is intergral value
        cte_prev_ is the previous value and used for differential 

* Total error is nothing but 
   total_error= p_error + d_error + i_error;


### Hyperparameter Tuning
* I started with smaller values of alpha_* and played with various values. Eventually I could get the values which work in my case and whole track is crosses multiple times.
* I tried twiddle as taught in lessons but I could not make much use of it.
* I tried playing with only P and my car gets struck
* Effect of adding just defferential part helped me cross car at low speed. 
* Eventually I could achieve a higher speed after few attritions.

* Watch P only [P_only]  ./only_pid/model.h5.ogv
* Watch P an D in ./build/only_pd/model.h5.ogv
* Watch P an D in ./build/all_pid/model.h5.ogv

## Conclusion
I have mostly applied what is being taught in the lessons. I could not experiment twiddle part much because I have already missed the deadline. I will revisit this at later point of time.
