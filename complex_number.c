#include <stdio.h>
#include <stdlib.h>

typedef struct{
	float real;
	float imag;
}Complex;

void getComplexNum(Complex *c1, Complex *c2);
void getAddResult(Complex *c1, Complex *c2, Complex *res);
void getSubResult(Complex *c1, Complex *c2, Complex *res);
void getMultResult(Complex *c1, Complex *c2, Complex *res);
void getDivResult(Complex *c1, Complex *c2, Complex *res);

int main() {
	Complex c1;
	Complex c2;
	Complex res;
	getComplexNum(&c1, &c2);
	printf("Two complex number is:\n%.1f + (%.1f)i\n%.1f + (%.1f)i\n", c1.real, c1.imag, c2.real, c2.imag);
	getAddResult(&c1, &c2, &res);
	printf("Result of Addition: %.1f + (%.1f)i\n", res.real, res.imag);
	getSubResult(&c1, &c2, &res);
	printf("Result of Subtraction: %.1f + (%.1f)i\n", res.real, res.imag);
	getMultResult(&c1, &c2, &res);
	printf("Result of Multiplicaion: %.1f + (%.1f)i\n", res.real, res.imag);
	getDivResult(&c1, &c2, &res);
	printf("Result of Division: %.1f + (%.1f)i\n", res.real, res.imag);

}
void getComplexNum(Complex *c1, Complex *c2) {
	printf("1st complex [real|imaginary]: ");
	scanf("%f %f", &c1->real, &c1->imag);
	printf("2nd complex [real|imaginary]: ");
	scanf("%f %f", &c2->real, &c2->imag);
}

void getAddResult(Complex *c1, Complex *c2, Complex *res) {
	res->real = c1->real + c2->real;
	res->imag = c1->imag + c2->imag;
}
void getSubResult(Complex *c1, Complex *c2, Complex *res) {
	res->real = c1->real - c2->real;
	res->imag = c1->imag - c2->imag;
}
void getMultResult(Complex *c1, Complex *c2, Complex *res) {
	res->real = c1->real * c2->real - c1->imag * c2->imag;
	res->imag = c1->imag * c2->real + c1->real * c2->imag;
}
void getDivResult(Complex *c1, Complex *c2, Complex *res) {
	res->real = (c1->real * c2->real + c1->imag * c2->imag)/
		(c2->real*c2->real + c2->imag*c2->imag);
	res->imag = (c1->imag * c2->real - c1->real * c2->imag)/
		(c2->real*c2->real + c2->imag*c2->imag);
}

