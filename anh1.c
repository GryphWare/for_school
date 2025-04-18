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
    puts(" ");
  }
  
  return 0;
}
