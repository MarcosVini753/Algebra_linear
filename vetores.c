#include <stdio.h>

void lerVet(int n, float vet[]){
   for(int i = 0; i <n; i++){
      printf("digite a %d entrada: ", i+1);
      scanf("%f", &vet[i]);
   }
}

void imprimeVet(int n, float vet[]){
   printf("(");
   for(int i = 0; i <n; i++){
      i != n-1 ? printf("%.2f, ", vet[i]) : printf("%.2f)\n", vet[i]);
   }
}

void somarVet(int n, float a[], float b[], float s[]){
   for(int i = 0; i < n; i++){
      s[i] = a[i] + b[i];
   }
}

void multEscalar(int n, float e, float a[], float r[]){
   for(int i = 0; i < n; i++){
      r[i] = a[i] * e;
   }
}

float produtoEscalar(int n, float a[], float b[]){
   float p = 0;
   for(int i = 0; i < n; i++){
      p += a[i] * b[i];
   }
   return p;
}

float norma(int n, float a[]){
   return produtoEscalar(n, a, a);
}

float distancia(int n, float a[], float b[]){
   float qd = 0;
   for(int i = 0; i < n; i++){
      qd += (a[i] - b[i]) * (a[i] - b[i]);
   }
   return qd;
}

void menu(){
   printf("\nescolha a operacao que deseja realizar\n");
   printf("0 - encerrar execucao__________________\n");
   printf("1 - somar vetores_____________________\n");
   printf("2 - multiplicar vetor por escalar_____\n");
   printf("3 - realizar o produto escalar________\n");
   printf("4 - calcular a norma de um vetor______\n");
   printf("5 - calcular distancia entre vetores__\n");
}

int main(){

   int op = 1, n;
   printf("voce trabalhara com vetores de no maximo qual dimensao?\n");
   scanf("%d", &n);
   float a[n], b[n], s[n], r[n];
   while(op){
      menu();
      scanf("%d", &op);
      // limpar console
      switch(op){
         case 0:
            printf("execucao encerrada");
         break;
         case 1 :
            printf("digite a dimensao\n");
            scanf("%d", &n);
            printf("\ndigite as entradas do vetor 1:\n");
            lerVet(n, a);
            printf("\ndigite as entradas do vetor 2:\n");
            lerVet(n, b);
            somarVet(n, a, b, s);
            printf("resultado: ");
            imprimeVet(n, s);
         break;
         case 2 :
            printf("digite a dimensao e o escalar: ");
            int e;
            scanf("%d %d", &n, &e);
            printf("digite as entradas do vetor:\n");
            lerVet(n, a);
            multEscalar(n, e, a, r);
            printf("resultado: ");
            imprimeVet(n, r);
         break;
         case 3 :
            printf("digite a dimensao: ");
            scanf("%d", &n);
            printf("\ndigite as entradas do vetor 1:\n");
            lerVet(n, a);
            printf("\ndigite as entradas do vetor 2:\n");
            lerVet(n, b);
            printf("resultado: %.2f\n", produtoEscalar(n, a, b));
         break;
         case 4 :
            printf("digite a dimensao: ");
            scanf("%d", &n);
            printf("digite as entradas do vetor\n");
            lerVet(n, a);
            printf("Norma: raiz de %.2f\n", norma(n, a));
         break;
         case 5 :
            printf("digite a dimensao: ");
            scanf("%d", &n);
            printf("digite as entradas do vetor 1\n");
            lerVet(n, a);
            printf("digite as entradas do vetor 2\n");
            lerVet(n, b);
            printf("Distancia: raiz de %.2f\n", distancia(n, a, b));
         break;
         default:
         printf("opcao invalida");
      }
   }
   return 0;
}