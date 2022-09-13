#include <stdio.h>
#define time_end 6

int x_n[time_end] = {0,};
int x_n_index = 0;

double MovingAverageFilter()
{
    int i = 0;
    int sum = 0;

    for (i = 0; i < time_end; i++) {
    	sum += x_n[i];
    }
    return ((double)sum / time_end);
}
void insertIntoRawArray(int value)
{
    x_n[x_n_index] = value;

    x_n_index++;

    if (x_n_index >= time_end) {
    	x_n_index = 0;
    }
}

int main()
{
	insertIntoRawArray(0);
	insertIntoRawArray(10);
	insertIntoRawArray(20);
	insertIntoRawArray(30);
	insertIntoRawArray(40);
	insertIntoRawArray(50);
	printf("%f\r\n", MovingAverageFilter());

	insertIntoRawArray(50);
	printf("%f\r\n", MovingAverageFilter());

	insertIntoRawArray(40);
	printf("%f\r\n", MovingAverageFilter());

	insertIntoRawArray(30);
	printf("%f\r\n", MovingAverageFilter());

	insertIntoRawArray(20);
	printf("%f\r\n", MovingAverageFilter());
}