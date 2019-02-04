#include <stdio.h>
#include <math.h>

typedef union {
	float f_exp;
	int i_exp;
}nVals;

typedef struct {
	float x;
	char flag;
	nVals exp;
}Values;

float power(Values v);

int main() {
	Values num;
	float check, res;
	printf("Enter a value for x: ");
	scanf("%f", &num.x);
	printf("Enter a value for n: ");
	scanf("%f", &check);


	if (num.x <= 0 && fmodf(check, 1) != 0) {
		printf("Error - Cannot raise a non-positive number to a floating-point power.\n");
		return 0;
	}
	else
	{
		if (fmodf(check, 1) == 0) {
			num.flag = 'i';
			num.exp.i_exp = check;
		}
		else {
			num.flag = 'f';
			num.exp.f_exp = check;
		}

		res = power(num);

		printf("y = %f\n", res);
	}
	return 0;
}

float power(Values v){
	float r=1;
	if (v.flag == 'i') {
		for (int i = 0; i < v.exp.i_exp; i++) {
			r *= v.x;
		}
		return r;
	}
	else {
		r = exp(v.exp.f_exp*log(v.x));
		return r;
	}
}
