#include "PID.h"

using namespace std;


PID::PID() {}

PID::~PID() {}

void PID::modifCoeffs(double Kp0, double Ki0, double Kd0, double alpha_p, double alpha_i,double alpha_d, double v) {

	this->Kp0 = Kp0;
	this->Ki0 = Ki0;
	this->Kd0 = Kd0;

	this->alpha_p = alpha_p;
	this->alpha_i = alpha_i;
	this->alpha_d = alpha_d;

	v_ = v;

	this->Kp = Kp0 + alpha_p * v_;
	this->Ki = Ki0 + alpha_i * v_;
	this->Kd = Kd0 + alpha_d * v_;

	return;
}

void PID::Init(double Kp0, double Ki0, double Kd0, double alpha_p, double alpha_i,double alpha_d, double v, double mem_frac) {

	PID::modifCoeffs(Kp0,Ki0,Kd0,alpha_p,alpha_i,alpha_d,v);

	mem_frac = mem_frac;

	p_error= 0;
	i_error = 0;
	d_error = 0;
	total_error = 0;
	
	cte_ = 0;
	cte_prev_ = 0;
	cte_mem_ = 0;

	return;
}


void PID::UpdateError(double cte) {

	cte_prev_ = cte_;
	cte_ = cte;
	cte_mem_ = mem_frac * cte_mem_ + cte_;

	p_error = Kp* cte_;
	i_error = Ki * cte_mem_;
	d_error = Kd* (cte_-cte_prev_);

	return;

}

double PID::TotalError() {

	total_error= p_error + d_error + i_error;

	return total_error;

}
