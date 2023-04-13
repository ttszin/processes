#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include<time.h>

int sum_vec(int *v1, int *v2, int len){
    int soma[len];

    printf("Calculando a soma dos numeros: \n\n");
    
    for (int i=0;i<len;i++){
        
        soma[i] = v1[i]*v2[i];
        printf("\t\t%d x %d = %d\n", v1[i], v2[i], soma[i]);
        sleep(2);

    }
    printf("\n\nvetor final:\t\t");

    for (int i = 0; i < len; i++)
    {
        printf("%d ", soma[i]);
    }
    

    printf("\n\n");
    return 0;

}


int main()
{
    int n1 = 0;    
    pid_t newPid, me, parent, x;


    int status;
    //Troca o numero da semente do rand()
    srand(time(NULL));

    newPid = fork();

    me = getpid();
    parent = getppid();

    printf("%d, %d, %d\n", me, parent, newPid);

    if (newPid != 0)
    {
        printf("Esperando filho pid %d\n", newPid);
        x = waitpid(newPid, &status, 0);
        printf("--> Filho %d terminou\n", x);
    }
    else
    {
        printf("Sou o filho\n");
        printf("Digite o range dos vetores: \n");
        scanf("%d", &n1);
        printf("Seu numero eh: %d\n", n1);
        int arr1[n1], arr2[n1];

        for (int i = 0; i < n1; i++)
        {
            arr1[i] = rand() % 1000;
            arr2[i] = rand() % 1000;
        }
        printf("Seu vetor 1 eh:\t\t");
        for (int i=0; i < n1;i++){
            printf("%d ", arr1[i]);
        }
        printf("\n");
        printf("Seu vetor 2 eh:\t\t");
        for (int i=0; i < n1;i++){
            printf("%d ", arr2[i]);
        }
        printf("\n");
        //int n2 = 0;
        int len = 0;

        len = sizeof(arr1)/sizeof(int);
        printf("len - novo metodo %d\n", len);
        

        sleep(5);
        sum_vec(arr1,arr2,len);
    }
    
    return 0;
}