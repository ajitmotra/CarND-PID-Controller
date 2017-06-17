#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double total_error;

  /*
  * External parameter
  */
  double v_;

  /*
  * cross track error components
  */
  double cte_;
  double cte_prev_;
  double cte_mem_;

  /*
  * Coefficients
  */ 
  double Kp, Ki, Kd;
  double Kp0, Ki0, Kd0;
  double alpha_p, alpha_i, alpha_d;

  double mem_frac;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp0, double Ki0, double Kd0, double alpha_p, double alpha_i,double alpha_d, double v, double mem_frac);

  /*
  * Update PID coefficients.
  */
  void modifCoeffs(double Kp0, double Ki0, double Kd0, double alpha_p, double alpha_i,double alpha_d, double v);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
