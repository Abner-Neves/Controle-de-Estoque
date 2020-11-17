#include<stdio.h>
#include<locale.h>
#include <stdlib.h>
#include <string.h>

struct estoque
{
	int cod, qnt, ex;
	float pre;
};

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	int hi, a, b, c, d, e, cnt, itot, i, j, spc, plus, mnus, nvlue, lcod, code, found; 
	char nome[100][5000];
	float vtot, givm, trc;
	char srch[100];
	
	struct estoque produto[5000];
	
	printf("Olá, obrigado por testar o meu programa, deseja começar com alguns produtos já em estoque ?\n");
	printf("1 - SIM | 2 - NÃO, vou adicionar meus próprios produtos\n");
	scanf("%i", &hi);
	
	if (hi == 2){
		system("cls");
		itot = 1;
	}
	
	else {
		strcpy(nome[2], "arroz branco 5kg");
		produto[2].ex = 1;
		produto[2].pre = 25;
		produto[2].qnt = 100;
		produto[2].cod = 2;
		
		strcpy(nome[3], "arroz branco 1kg");
		produto[3].ex = 1;
		produto[3].pre = 5;
		produto[3].qnt = 45;
		produto[3].cod = 3;
		
		strcpy(nome[4], "arroz integral 1kg");
		produto[4].ex = 1;
		produto[4].pre = 10;
		produto[4].qnt = 25;
		produto[4].cod = 4;
		
		strcpy(nome[5], "feijao 1kg");
		produto[5].ex = 1;
		produto[5].pre = 8.5;
		produto[5].qnt = 94;
		produto[5].cod = 5;
		
		strcpy(nome[6], "cafe 500g");
		produto[6].ex = 1;
		produto[6].pre = 6;
		produto[6].qnt = 75;
		produto[6].cod = 6;
		
		strcpy(nome[7], "sal refinado 1kg");
		produto[7].ex = 1;
		produto[7].pre = 2.5;
		produto[7].qnt = 32;
		produto[7].cod = 7;
		
		strcpy(nome[8], "barra de chocolate 120g");
		produto[8].ex = 1;
		produto[8].pre = 7;
		produto[8].qnt = 84;
		produto[8].cod = 8;
		
		itot = 8;
		
		system("cls");
	}
		
	while (1){
		
		vtot = 0;
		a = 0;
		b = 0;	
		c = 0;
		d = 0;
		e = 0;
		found = 0;
		
		printf("1 - Gerenciar estoque | 2 - Caixa\n");
		scanf("%i", &a);
		
		//ESTOQUE
		if (a == 1){
			
			printf("Código\t\t  Produto\t\t\t\t Quantidade\t\tValor Unitário\n\n");
			
			for(i =0; i <= itot+1; i++){
				
				if (produto[i].ex == 1) {
					printf("%i\t          %s", produto[i].cod, nome[i]);
					
					spc = 40 - strlen(nome[i]);					
					for (j = 0; j <= spc; j++){
						printf(" ");
					} 
					
					printf("%i\t\t\t     %0.2f\n", produto[i].qnt, produto[i].pre);
				}
			}  
			
			printf("\nDigite o código do produto que deseja alterar | 1 - para adicionar um novo produto \n0 - Para procurar um produto pelo nome | Ou -1 para cancelar\n");
			scanf("%i", &b);
							
				if (b == 1){
					
					printf("Insira o nome do produto\n");
					scanf(" %[^\n]s", &nome[itot+1]);
					
					printf("Insira a quantidade do produto\n");
					scanf("%i", &produto[itot+1].qnt);
					
					printf("Insira o valor unitário do produto(no formato xx,xx)\n");
					scanf("%f", &produto[itot+1].pre);
					
					produto[itot + 1].cod = itot + 1;
					produto[itot + 1].ex = 1;
					
					printf("Produto adicionado com sucesso\n");
					itot++;
					
				}
				else if (b == 0){
					if (itot == 1){
						printf("Nenhum produto cadastrado\n");
					}
					else {
						
					printf("Digite o nome do produto\n");
					scanf(" %[^\n]s", &srch);
						
						for(i=0; i<=itot;i++){
							if (strstr(nome[i], srch)!=0 && produto[i].ex == 1){
								found = 1;
								printf("%i\t          %s", produto[i].cod, nome[i]);
								
								spc = 40 - strlen(nome[i]);					
								for (j = 0; j <= spc; j++){
									printf(" ");
								} 
								
								printf("%i\t\t\t     %0.2f\n", produto[i].qnt, produto[i].pre);
							}
						} 
						
						if (found != 1){
							printf("Nenhum item encontrado\n");
						}
						
						else {
							
							printf("Digite o código do produto | 0 - Para cancelar\n");
							scanf("%i",&i);
												
								if (produto[i].ex == 1)
									found = 2;								
							 
							
							if (found == 2){
							
								printf("%s \n", nome[i]);
								printf("O que deseja alterar nesse produto?\n");
								printf("1 - Adicionar unidades| 2 - Remover unidades | 3 - Alterar valor unitário | 4 - Renomear | 5 - Deletar\n0 - Cancelar\n");
								scanf("%i", &c);
							}
							
							else if(i == 0){
							}
							
							else {
								printf("Produto não encontrado\n");
							}
						}
					}
				}	
							
				else if (b != (-1)) {
					for(i=0; i <= itot+1; i++){
						if (produto[i].cod == b && produto[i].ex == 1){
							found = 1;
							break;
						}
					} 
					if (found != 1){
						printf("Produto não encontrado\n");
					}
					
					else {
						printf("%s \n", nome[i]);
						printf("O que deseja alterar nesse produto?\n");
						printf("1 - Adicionar unidades | 2 - Remover unidades | 3 - Alterar valor unitário | 4 - Renomear | 5 - Deletar\n0 - Cancelar\n");
						scanf("%i", &c);
					}
				}					
				
				if (c == 1){
					printf("Quantidade atual: %i\t - Quanto deseja adicionar?\n", produto[i].qnt);
					scanf("%i", &plus);
					
					produto[i].qnt = produto[i].qnt + plus;
					
					printf("Adicionado com sucesso\n");
				}
				
				else if (c == 2){
					printf("Quantidade atual: %i\t - Quanto deseja retirar?\n", produto[i].qnt);
					scanf("%i", &mnus);
					
					produto[i].qnt = produto[i].qnt - mnus;
					
					printf("Retirado com sucesso\n");
				}
				
				else if (c == 3){
					printf("Valor atual: %0.2f\t - Qual será o novo valor?\n", produto[i].pre);
					scanf("%f", &produto[i].pre);
					
					printf("Valor alterado com sucesso\n");
				}
				
				else if (c == 4){
				
					printf("Digite um novo nome para o produto\n");
					scanf(" %[^\n]s", &nome[i]);
					
					printf("Nome alterado com sucesso\n");
				}
				
				else if (c == 5){
										
					printf("Tem certeza que quer deletar %s?\n", nome[i]);
					printf("1 - Sim | 2 - Não\n");
					scanf("%i", &d);
					
					if (d == 1){
						itot--;
						produto[i].ex = 0;
					}
				}
			
		}
		
		//CAIXA
	
		else if (a ==2){
			
			if (itot > 1){
				
				printf("Digite o código do produto | 1 - Finalizar compra | 0 - Cancelar\n\n");
				
				while(1) {

					scanf("%i", &lcod);
					
					if (lcod == 0)
						break;
					
					else if (lcod == 1){
						if (vtot > 0){
							
							printf("Total a pagar: %0.2f\n", vtot);
							
							printf("Insira o valor recebido\n");
							scanf("%f", &givm);
							
							trc = givm - vtot;
							
							printf("Devolver R$%0.2f \n", trc);					
							break;	
						}
						else 
							break;					
					}
					
					else {
						for (i= 0; i <= itot+1; i++){
							if (lcod == produto[i].cod && produto[i].ex == 1){
								cnt = 1;
								break;
							}
							else 
								cnt = 0;						
						}
						if (cnt == 1){
							
							printf("\t\t\tVlr. Uni.\t\t\t\tTOTAL\n");
							for (i=0; i<= itot; i++){
								if (produto[i].cod == lcod){
																			
									vtot = vtot + produto[i].pre;
									printf("%s", nome[i]);		
												
									spc = 25 - strlen(nome[i]);	
													
									for (j = 0; j <= spc; j++){
										printf(" ");
									} 
															
									printf("%0.2f\t\t\t\t\t%0.2f\n", produto[i].pre, vtot);	
								}
							}
						}
						else 
							printf("Produto não encontrado\n");					
					}
				}				
			}	
			
			else {
				printf("Não há produtos cadastrados no estoque\n");
			}
		}
		
			getch();
			system("cls");
		}
}
