#include <stdio.h>
#include <math.h>
typedef int Component;
typedef int* Vector_Components;
typedef double Vectorsize;
typedef double Distance;
typedef int Scalar;
typedef double Angle;

typedef struct {
	Vector_Components comps;
	int vec_size;
}Vector;

Vectorsize getSize(Vector V);
Distance getDistance(Vector V1, Vector V2);
Scalar getDotProduct(Vector V1, Vector V2);
Angle getAngle(Vector V1, Vector V2);

int main() {
	int i, j;
	Vector v1, v2;
	double d, a;
	int s;
	printf("Input size of Vector v1 : ");
	scanf("%d", &v1.vec_size);
	v1.comps = (Vector_Components)malloc(sizeof(Component)*v1.vec_size);
	printf("Input %d components of v1 : ", v1.vec_size);
	for (i = 0; i < v1.vec_size; i++) {
		scanf("%d", & v1.comps[i]);
	}
	printf("Input size of Vector v2 : ");
	scanf("%d", &v2.vec_size);
	v2.comps = (Vector_Components)malloc(sizeof(Component)*v2.vec_size);
	printf("Input %d components of v2 : ", v2.vec_size);
	for (j = 0; j < v2.vec_size; j++) {
		scanf("%d", &v2.comps[j]);
	}
	printf("\n\nResult\n");
	printf("Size of v1 = %.2lf\n", getSize(v1));
	printf("Size of v2 = %.2lf\n", getSize(v2));
	if (v1.vec_size == v2.vec_size) {
		d = getDistance(v1, v2);
		s = getDotProduct(v1, v2);
		a = getAngle(v1, v2);
		printf("Distance between v1 and v2 = %.3lf\n", d);
		printf("Dot Product v1 * v2 = %d\n",s );
		printf("Angle between v1 and v2 = %.2lf\n", a);
	}
	return 0;
}

Vectorsize getSize(Vector V) {
	double size=0;
	for (int i = 0; i < V.vec_size; i++) {
		size += V.comps[i] * V.comps[i];
	}
	size = sqrt(size);
	return size;
}
Distance getDistance(Vector V1, Vector V2) {
	double dis=0;
	for (int i = 0; i < V1.vec_size; i++) {
		dis += (V1.comps[i] - V2.comps[i])*(V1.comps[i] - V2.comps[i]);
	}
	return sqrt(dis);
}
Scalar getDotProduct(Vector V1, Vector V2) {
	int s=0;
	for (int i = 0; i < V1.vec_size; i++) {
		s += V1.comps[i] * V2.comps[i];
	}
	return s;
}
Angle getAngle(Vector V1, Vector V2) {
	double a = 0;
	a = acos(getDotProduct(V1, V2) / (getSize(V1)*getSize(V2)));
	return a * 180 / 3.141592;
}
