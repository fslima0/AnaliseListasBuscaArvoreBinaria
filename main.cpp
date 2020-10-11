#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "MinhasFuncoes.h"
#include <sys/time.h>

using namespace std;

int main(int argc, char** argv) {
    struct timeval start, end;
    double elapsed;
    int* vetor;
    int tamanho, numero, resultado;
    
    srand(time(NULL));
    
    cout << "Digite o tamanho do vetor: ";
    cin >> tamanho;
    
    vetor = new int[tamanho];

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % tamanho;
    }
    
    cout << "Digite um numero (chave): ";
    cin >> numero;
    
    gettimeofday(&start, NULL);    
    resultado = IsIn(numero, vetor, tamanho);
    gettimeofday(&end, NULL);
    elapsed = ((end.tv_sec - start.tv_sec) / 1000) + (end.tv_usec - start.tv_usec);        
    cout<<"Tempo de execução do IsIn() (milisegundos)="<< elapsed<< endl;
    
    sort(vetor, vetor+tamanho); 
    
    gettimeofday(&start, NULL);    
    resultado = IsInBinarioRecursivo(numero, vetor, 0, tamanho);
    gettimeofday(&end, NULL);
    elapsed = ((end.tv_sec - start.tv_sec) / 1000) + (end.tv_usec - start.tv_usec);    
    cout<<"Tempo de execução do isInBinarioRecursivo() (milisegundos)="<< elapsed<< endl;

    return EXIT_SUCCESS;
}

