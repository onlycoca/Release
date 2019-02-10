#include <stdio.h>
struct CoinBox{
	int n500;
	int n100;
	int n50;
	int n10;
};
void main() {
	struct CoinBox sum ,n;

	printf("Input money : ");
	scanf("%d", &sum.n500);
	n.n500 = sum.n500 / 500;
	n.n100 = (sum.n500 - n.n500 * 500) / 100; 
	n.n50 = (sum.n500 - (n.n500 * 500) - (n.n100 * 100)) / 50;
	n.n10 = (sum.n500 - n.n500 * 500 - n.n100 * 100 - n.n50 * 50) / 10;
	printf("# of 500 = %d\n", n.n500);
	printf("# of 100 = %d\n", n.n100);
	printf("# of 50 = %d\n", n.n50);
	printf("# of 10 = %d\n", n.n10);
}