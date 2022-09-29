#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int CopyArray2D(double *source, double *target, int n);
int InverseMatrix(double *work, double *result, int n);

int main() {
 	int i, j;
	int ROW = 0;
	int COL = 0;
    int userN = 0;
    int userM = 0;
	
	printf("n by n = ");
	scanf("%d", &userN);
	
	userM = userN - 1;
	
	double x1[userN][userN];
	double res[userN][userN];
	 for (i = 0; i < userN; i++) {
        for (j = 0; j < userN; j++) {
            printf("%d , %d =", i, j);
            scanf("%lf", &x1[i][j]);
        }
    }
	
	printf("\nOriginal Matrix\n");
	for (i=0; i<userN; i++) {
		for (j=0; j<userN; j++) {
			printf("%d%d : %f  ", i, j, x1[i][j]);
		}
		  printf("\n");
	}
	
	InverseMatrix(&x1[0][0], &res[0][0], userN);

	printf("\nInverse Matrix\n");
	for (i=0; i<userN; i++) {
		for (j=0; j<userN; j++) {
			printf("%d%d : %f  ", i, j, res[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int InverseMatrix(double *work, double *result, int n) {
	int i, j, k;
	double constant;
	double tmpWork[n][n];

	// 2차원 배열 복사
	CopyArray2D(work, &tmpWork[0][0], (n*n));

   
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			result[i*n+j] = (i == j) ? 1 : 0;

	/* 대각 요소를 0 이 아닌 수로 만듦 */
	for (i=0; i<n; i++) {
		for (k=0; k<n; k++) {
			for (j=0; j<n; j++) {
				tmpWork[i][j] += tmpWork[k][j];
				result[i*n+j] += result[k*n+j];
			}
		}
	}

   /* Gauss-Jordan elimination */
	for (i=0; i<n; i++) {
		// 대각 요소를 1로 만듦
		constant = tmpWork[i][i];      // 대각 요소의 값 저장
		for (j=0; j<n; j++) {
			tmpWork[i][j] /= constant;   // tmpWork[i][i] 를 1 로 만드는 작업
			result[i*n+j] /= constant;   // i 행 전체를 tmpWork[i][i] 로 나눔
		}

      // i 행을 제외한 k 행에서 tmpWork[k][i] 를 0 으로 만드는 단계
		for (k=0; k<n; k++) {
			if (k == i) continue;      // 자기 자신의 행은 건너뜀
			if (tmpWork[k][i] == 0) continue;   // 이미 0 이 되어 있으면 건너뜀
			
			// tmpWork[k][i] 행을 0 으로 만듦
			constant = tmpWork[k][i];
			for (j=0; j<n; j++) {
				tmpWork[k][j] = tmpWork[k][j] - tmpWork[i][j] * constant;
				result[k*n+j] = result[k*n+j] - result[i*n+j] * constant;
			}
		}
	}
   	return (0);
}
int CopyArray2D(double *source, double *target, int n) {
	if (n < 1) return (-1);

   	int i;
   	for (i=0; i<n; i++)
		target[i] = source[i];

   	return (0);
}