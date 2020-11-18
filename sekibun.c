#include<stdio.h>
#include <math.h>
double f1(double x){
	return x*x*x*x-2*x*x*x+x*x-3*x+1;
}
double f2(double x){
	return 1/x;
}

int main(){
	double A1 = 0.0;
	double B1 = 3.0;
	double A2 = 1.0;
	double B2 = 2.0;
	int N = 10;
	int i;
	double delta;
	double value;
	double x;

	printf("微小区分　%d\n" ,N);
	delta = (B1-A1)/N;
	value = 0.0;

	for(i=0; i<N; i++){
		x = A1 + i * delta;
		value += (f1(x)+f1(x+delta))*delta/2.0;  
	}

	printf("x^4-2x^3+x^2-3x+1\n");
	printf("台形法結果%lf\n",value);
	
	delta = (B1 - A1) / N;
	value = 0.0;

	for(i=0; i<N; i++) {
		x = A1 + i * delta;
		value += (f1(x) + f1(x+delta) + 4.0 * f1(x+delta/2.0)) * delta / 6.0;
	}
	printf("シンプソン法結果%lf\n",value);
	printf("\n1/x\n");
        delta = (B2-A2)/N;
        value = 0.0;

        for(i=0; i<N; i++){
                x = A2 + i * delta;
                value += (f2(x)+f2(x+delta))*delta/2.0;
        }
	printf("台形法結果%lf\n",value);
	delta = (B2 - A2) / N;
        value = 0.0;

        for(i=0; i<N; i++) {
                x = A2 + i * delta;
                value += (f2(x) + f2(x+delta) + 4.0 * f2(x+    delta/2.0)) * delta / 6.0;
        }
        printf("シンプソン法結果%lf\n",value);

		
	return 0;
}
