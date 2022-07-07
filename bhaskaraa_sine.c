#include <stdio.h>
#include <math.h>

double reduce_angle(double angle) {
	if (angle>=360)
			while (angle>=360) angle-=360;
	if (angle>=90 && angle<270) return 180-angle;
	else if (angle>=270 && angle<360) return angle-360;
	return angle;
}

int main() {
	double x;
	scanf("%lf", &x);

	double angle = fabs(reduce_angle(x));
	double sine = (4*angle*(180-angle))/(40500-angle*(180-angle));
	if (x>=270)
		printf("%0.10lf\n", 0-sine);
	else
		printf("%0.10lf\n", sine);
}
