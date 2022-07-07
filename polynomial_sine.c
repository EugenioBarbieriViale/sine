#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double reduce_angle(double angle) {
	if (angle>=360)
			while (angle>=360) angle-=360;
	if (angle>=90 && angle<270) return 180-angle;
	else if (angle>=270 && angle<360) return angle-360;
	return angle;
}

int fact(int x) {
	if (x<=1) return 1;
	else return x*fact(x-1);
}

double calc_sine(double angle) {
	double sine = 0;
	for (int i=0; i<15; i++) {
		int exp = 2*i+1;
		sine += pow(-1,i)*pow(angle,exp)/fact(exp);
	}
	return sine;
}

double calc_cosine(double angle) {
	double cosine = 0;
	for (int i=0; i<15; i++) {
		int exp = 2*i;
		cosine += pow(-1,i)*pow(angle,exp)/fact(exp);
	}
	return cosine;
}

double to_radians(double angle) {
	return angle/180*M_PI;
}

int main() {
	double angle;
	scanf("%lf", &angle);
	double result;

	if (fabs(angle)<=45)
		result = calc_sine(to_radians(reduce_angle(angle)));
	else
		result = calc_cosine(to_radians(90-reduce_angle(angle)));

	printf("%0.10lf\n", result);
}
