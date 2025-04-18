#include <stdio.h>
#include <stdlib.h>

/*neu user nhap mang ma la char*/
void clearChar(){
  int c;
  while((c = getchar()) != '\n' && c != EOF);
}

/*ham xoa array khi sai hoac ket thuc*/
void freeArray(int **arr, int row){
  for(size_t i = 0; i < row; i++){
    free(*(arr + i));
  }
  free(arr);
}

int **getValidMatrix(int *row, int *column){
  /*user se nhap row & columb ow day*/
  if(scanf("%d %d", row, column) != 2 || *row <= 0 || *column <= 0){
    /*neu user co nhap char*/
    clearChar();

    /*nhap den khi nao ok thi thoi*/
    int stopped = 0;
    while(!stopped){
      if(scanf("%d %d", row, column) == 2 && *row >= 1 || *column >= 1){
	stopped = 1;
      } else {
	clearChar();
      }
    }
  }

  /*tao mang 2d*/
  int **arr = malloc(*row * sizeof(int*));
  /*kiem tra mang co toan tai*/
  if(!arr){
    fprintf(stderr, "Malloc bi loi");
    freeArray(arr, *row);
    return NULL;
  }
  
  for(size_t i = 0; i < *row; i++){
    *(arr + i) = malloc(*column * sizeof(int)); 
  }

  /*xem mang da ok?*/
  if(!arr){
    fprintf(stderr, "Array ko ton tai");
    freeArray(arr, *row);
    return arr;
  }

  /*nhap cac phan tu trong mang*/
  for(size_t i = 0; i < *row; i++){
    for(size_t j = 0; j < *column; j++){
      scanf("%d", *(arr + i) + j);
    }
  }

  /*tra ve*/
  return arr;
  
}

/*ham tinh trung binh*/
float findOddAndAverage(int **arr, int row, int column){

  /*ham nay tinh tong so le va f's so le*/
  float totalOfOdd, OddCount;
  totalOfOdd = OddCount = 0;

  for(size_t i = 0; i < row; i++){
    for(size_t j = 0; j < column; j++){
      if(*(*(arr + i) + j) % 2 != 0){
	totalOfOdd += *(*(arr + i) + j);
	OddCount++;
      }
    }
  }

  return totalOfOdd / OddCount;
}

/*ham kiem tra so hoan hao*/
int checkPerfect(int num){
  int sum = 0;
  for(size_t i = 1; i <= num / 2; i++){
    if(num % i == 0){
      sum += i;
    }
  }
  return num == sum;
}


int main(){

  int row, column;

  /*ham nhap row  & column vad tao luon mang */
  int **arr2d = getValidMatrix(&row, &column);

  /*what*/
  if(!arr2d){
    return 1;
  }

  /*in ra row & column && array*/
  printf("%d %d\n", row, column);
  for(size_t i = 0; i < row; i++){
    for(size_t j = 0; j < column; j++){
      printf("%d ", *(*(arr2d + i) + j));
    }
    puts("");
  }

  float average = findOddAndAverage(arr2d, row, column);
  printf("stb: %.5f\n", average);

  /*so cmmnr hao*/
  for(size_t i = 0; i < row; i++){
    if(*(*(arr2d + i) + i) > 0 && checkPerfect(*(*(arr2d + i) + i))){
      printf("cac so ok: %d ", *(*(arr2d + i) + i));
    }
  }
  
  return 0;
}
