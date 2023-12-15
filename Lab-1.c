#include<stdio.h>

//sorting
void sortArray(int arr[][10],int r,int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			for(int k=0;k<c-1;k++){
				if(arr[i][k]>arr[i][k+1]){
					int temp=arr[i][k];
					arr[i][k]=arr[i][k+1];
					arr[i][k+1]=temp;
				}
			}
		}
	}
}
//traversal
void displayArray(int arr[][10],int r, int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}
//searching
void Searching(int arr[][10],int m,int n,int ele){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==ele){
				printf("your protien intake is at %d,%d position:%d\n",i,j,arr[i][j]);

			}
		}
	}
}
// Insertion
void insertElement(int arr[][10], int r, int c, int row, int col, int element) {
    if (row >= 0 && row < r && col >= 0 && col < c) {
        arr[row][col] = element;
        printf("Element %d inserted at position (%d, %d)\n", element, row, col);
    } else {
        printf("Invalid position for insertion.\n");
    }
}

// Deletion
void deleteElement(int arr[][10], int r, int c, int row, int col) {
    if (row >= 0 && row < r && col >= 0 && col < c) {
        printf("Element %d deleted from position (%d, %d)\n", arr[row][col], row, col);

        // Mark the deleted element with a special value, e.g., -1
        arr[row][col] = NULL;
    } else {
        printf("Invalid position for deletion.\n");
    }
}

// Matrix Addition
void matrixAddition(int arr1[][10], int arr2[][10], int result[][10], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

// Matrix Subtraction
void matrixSubtraction(int arr1[][10], int arr2[][10], int result[][10], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
}

int main() {
    printf("\t\t\t**********Calorie Counter**************");
    int arr1[10][10], arr2[10][10], result[10][10], m, n, ele, row, col, element, choice;

    // Read matrix 1
    printf("\nEnter row and col for matrix 1:");
    scanf("%d%d", &m, &n);
    printf("\nEnter element for matrix 1:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }

    // Read matrix 2
    printf("\nEnter row and col for matrix 2:");
    scanf("%d%d", &m, &n);
    printf("\nEnter element for matrix 2:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    do {
        printf("\nMenu:\n");
        printf("1. Display Matrix 1\n");
        printf("2. Display Matrix 2\n");
        printf("3. Matrix Addition\n");
        printf("4. Matrix Subtraction\n");
        printf("5. Search Element\n");
        printf("6. Insert Element\n");
        printf("7. Delete Element\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nMatrix 1:\n");
                displayArray(arr1, m, n);
                break;
            case 2:
                printf("\nMatrix 2:\n");
                displayArray(arr2, m, n);
                break;
            case 3:
                printf("Matrix addition result:\n");
                matrixAddition(arr1, arr2, result, m, n);
                displayArray(result, m, n);
                break;
            case 4:
                printf("Matrix subtraction result:\n");
                matrixSubtraction(arr1, arr2, result, m, n);
                displayArray(result, m, n);
                break;
            case 5:
                printf("Enter the element to be searched: ");
                scanf("%d", &ele);
                Searching(arr1, m, n, ele);
                break;
            case 6:
                printf("Enter the row and column to insert an element: ");
                scanf("%d%d", &row, &col);
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertElement(arr1, m, n, row, col, element);
                displayArray(arr1, m, n);
                break;
            case 7:
                printf("Enter the row and column to delete an element: ");
                scanf("%d%d", &row, &col);
                deleteElement(arr1, m, n, row, col);
                displayArray(arr1, m, n);
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}