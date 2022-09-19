#include <stdio.h>

double alpha = 0.7;
double n_samples = 500;
double x_esti, x_meas;
double low_pass_filter(double x_meas, double x_esti){
	double x_lpf;
	x_lpf = alpha * x_esti + (1 - alpha) * x_meas;
	
    return x_lpf;
}

int main(void){
	
	for(int i=0;i<n_samples;i++){
		printf("x : ");
		scanf("%lf",&x_meas);
		if (i == 0)
		{
			x_esti = x_meas;
		}
		else
		{
			x_esti = low_pass_filter(x_meas, x_esti);
		}
		printf("%lf\n",low_pass_filter(x_meas, x_esti));
	}
	
}