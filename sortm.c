#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 40
int n,swap1=0,swap2=0,swapshell=0;
void generaterandomfile(const char *filename, int n){
        FILE *file = fopen(filename,"w");
        for (int i=0;i<n;i++){
                fprintf(file,"%d ",rand()%100);
        }
        fclose(file);
}
int readfromfile(int arr[],const char *filename){
        FILE *file = fopen(filename,"r");
        int n=0;
        while (fscanf(file,"%d",&arr[n])!=EOF){
                n++;
        }
        fclose(file);
        return n;
}
void insertionsort(int arr[],int n){
        for (int i=1;i<n;i++){
                int key = arr[i];
                int j=i-1;
                while (j>=0 && arr[j]>key){
                        arr[j+1]=arr[j];
                        j=j-1;
                        swap1++;
                }
                arr[j+1]=key;
                printf("Iteration : %d \n",i);
                for (int i=0;i<n;i++){
                        printf("%d ",arr[i]);
                }
                printf("\n");
        }
}
void shellsort(int arr[],int n){
        for (int gap=n/2;gap>0;gap/=2){
                printf("Gap : %d\n",gap);
                for (int i = gap; i<n;i++){
                        int key = arr[i];
                        int j=i;
                        while (j >= gap && arr[j-gap]>key){
                                arr[j]=arr[j-gap];
                                j-=gap;
                                swapshell++;
                        }
                        arr[j]=key;
                }
                for (int i=0;i<n;i++){
                        printf("%d ",arr[i]);
                }
                printf("\n");
        }
}
void mergesort(int arr[], int left, int right){
        if (left<right){
                int mid = (left + right)/2;
                mergesort(arr,left,mid);
                mergesort(arr,mid+1,right);
                int n1 = mid -left+1;
                int n2 = right-mid;
                int L[n1],R[n2];
                for (int i=0;i<n1;i++){
                        L[i]=arr[left+i];
                }
                for (int i=0;i<n2;i++){
                        R[i]=arr[mid+i+1];
                }
                int i=0,j=0,k=left;
                while (i<n1 && j<n2){
                        if (L[i]<=R[j]){
                                arr[k]=L[i];
                                i++;
                        }
                        else{
                                arr[k]=R[j];
                                j++;
                        }
                        k++;
                        swap2++;
                }
                while (i<n1){
                        arr[k]=L[i];
                        i++;
                        k++;
                }
                while (j<n2){
                        arr[k]=R[j];
                        j++;
                        k++;
                }
                printf("Mid : %d\n",mid);
                for (int i=0;i<n;i++){
                        printf("%d ",arr[i]);
                }
                printf("\n");
        }
}
int main(){
        const char *filename = "demo.txt";
        int arr[MAXSIZE];
        printf("Enter number of elements : ");
        scanf("%d",&n);
        generaterandomfile(filename,n);
        int n = readfromfile(arr,filename);
        printf("Insertion Sort : \n");
//        insertionsort(arr,n);
        printf("Number of swaps in insertion sort : %d\n",swap1);
        printf("Shell sort : \n");
        shellsort(arr,n);
        printf("Number of swaps in Shell sort : %d\n",swapshell);
        printf("Merge Sort : \n");
        mergesort(arr,0,n-1);
        printf("Number of swaps in merge sort : %d\n",swap2);
        return 0;

}
