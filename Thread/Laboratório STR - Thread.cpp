/*

Instituto Federal de Educação, Ciência e Tecnologia do Ceará
Campus: Fortaleza
Disciplina: Sistemas de Tempo-Real
Professor: Paulo Regis Carneiro de Araujo
Aluno: Moises Moura Rabelo
Data: 15/09/2021

Atividade: Laboratório 1
	Elabore um programa que crie 3 threads: thread A, thread B e thread C;
	Cada thread deve acessar um array do tipo char (listachar[]) com 30 elementos (variável global).
	Esse array deve ser preenchido na seguinte ordem: o índice 0 do array deve receber o caracter “A”, da thread A;
	o índice 1 do array deve receber o caracter “B”, da thread B; o índice 2 do array deve receber o caracter “C”, da thread C;
	e assim sucessivamente até todo o array ser preenchido.
	Após o preenchimento do vetor, a thread C deverá imprimir na tela a sequência dos caracteres armazenados.
	Verifique se a ordem dos caracteres obedeceu o esperado.
	
*/

#include <stdio.h>
#include <process.h>

char listachar[30];
int flagA = 1;
int flagB = 0;
int flagC = 0;
int i = 0;

/* ----------------------------------------------------------------------------------------------------------- */

void threadA(void *Thread);
void threadB(void *Thread);
void threadC(void *Thread);
void start_thread();

/* ----------------------------------------------------------------------------------------------------------- */

int main()
{
	start_thread();
	getchar();
	return 0;
}

/* ----------------------------------------------------------------------------------------------------------- */

void threadA(void *Thread)
{
	while(i <= 27)
	{
		while(flagA == 0);
		listachar[i] = 'A';
		i++;
		flagA = 0;
		flagB = 1;
	}
	return;
}

/* ----------------------------------------------------------------------------------------------------------- */

void threadB(void *Thread)
{
	while(i <= 28)
	{
		while(flagB == 0);
		listachar[i] = 'B';
		i++;
		flagB = 0;
		flagC = 1;
	}
	return;
}

/* ----------------------------------------------------------------------------------------------------------- */

void threadC(void *Thread)
{
	while(i <= 29)
	{
		while(flagC == 0);
		listachar[i] = 'C';
		i++;
		flagC = 0;
		
		if (i == 30)
		{
			printf("\nArray: ");
			for (int j = 0; j < 29; j++) printf("%c-", listachar[j]);
			printf("%c", listachar[29]);
		}
		else flagA = 1;
	}
	return;
}

/* ----------------------------------------------------------------------------------------------------------- */

void start_thread()
{
	int thread_id;
	/*
	
	Por meu sistema ser 64 bits validei pelo -1,
	mas caso fosse 32, deveria ser validado por "(unsigned long) -1"
	
	*/	
	//Criação da thread A
	if ((thread_id = _beginthread(threadA, 4096, NULL)) == -1) 
	{
		printf("Sem capacidade de criar a thread A.\n");
		return;
	}
	printf("Thread A criada.\n");
	
	//Criação da thread B
	if((thread_id = _beginthread(threadB, 4096, NULL)) == -1)
	{
		printf("Sem capacidade de criar a thread B.\n");
		return;
	}
	printf("Thread B criada.\n");
	
	//Criação da thread C
	if((thread_id = _beginthread(threadC, 4096, NULL)) == -1)
	{
		printf("Sem capacidade de criar a thread C.\n");
		return;
	}
	printf("Thread C criada.\n");
}

