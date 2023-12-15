#include<stdio.h>


void main()
{
	int m,n,p,q;
	
	printf("Enter the number of rows and column of first matrix");
	scanf("%d%d",&m,&n);
	printf("\nEnter the number of rows and column of second matrix");
	scanf("%d%d",&p,&q);
	
	int a[m][n],b[p][q],c[m][q];
	
	printf("\nEnter the value of matrix a");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("\nEnter the value of matrix b");
	for(int i=0;i<p;i++){
		for(int j=0;j<q;j++){
			scanf("%d",&b[i][j]);
		}
	}
	
	if(n!=p){
		printf("\nMatrix multiplication is not possible");
	}else{
		for(int i=0;i<m;i++){
			for(int j=0;j<q;j++){
				int sum=0;
				for(int k=0;k<m;k++){
					sum=sum+a[i][k]*b[k][j];
				}
				c[i][j]=sum;
			}
		}
		
			printf("\n Printing value of matrix multiplication\n");
		for(int i=0;i<m;i++){
			for(int j=0;j<q;j++){
				printf("%d\t",c[i][j]);
			}
			printf("\n");
		}
	}
	

}