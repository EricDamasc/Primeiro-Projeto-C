#include <stdio.h> 				//
#include <stdlib.h>				//
#include <locale.h>				//chamada de bibliotecas
#include <conio.h>				//				
#include <time.h>				//
#include <math.h>				//

FILE* Ponteiro; //cria uma vari�vel global do tipo FILE de nome ponteiro

typedef struct { //Cria um novo tipo (que s�o a classe a qual pertence determinada vari�vel. Inteiro, Caracteres e reais s�o exemplos)
	int Qtd_Dormitorio, Qtd_Suite, Qtd_Sala, Qtd_Sala_de_Estar, ID, Qtd_Cozinha, Qtd_Banheiro, andar;
	//o novo tipo possuir� vari�veis do tipo inteiro 
	char infraestrutura[1000], Area_de_Lazer[4], endereco[200], n_telefone[15];
	//do tipo caracteres
	float valor_do_imovel, Area_do_terreno, Area_construida_total;  
	//do tipo real
}Ficha_Tecnica_Imovel; //e ir� se chamar Ficha_Tecnica_Imovel

typedef struct { //Cria um novo tipo (que s�o a classe a qual pertence determinada vari�vel. Inteiro, Caracteres e reais s�o exemplos)
	char nome[200], data_contratacao[14], data_nascimento[14], senha[12];
	//do tipo caracteres
	int idade, imoveis_vendidos, numero_do_cracha;
	//o novo tipo possuir� vari�veis do tipo inteiro 
	float salario_b, comissao_pvenda, salario_l;
	//do tipo real
}Corretor; //e ir� se chamar Corretor

void alugar_imovel() //cria uma fun��o de nome alugar_imovel que ir� alugar im�veis cadastrados para aluguel
{
			int op, cracha, id = 0, vf = 0; //cria vari�veis do tipo inteiro que servir�o de par�metros de compara��o futuramente
			
			Ficha_Tecnica_Imovel Info; //cria uma vari�vel do tipo Ficha_Tecnica_Imovel
			
			Corretor Info2, Info3;  //cria vari�veis do tipo Corretor de nome Info2;
			
			FILE* Ponteiro; //cria uma vari�vel do tipo FILE �que possibilita a manipula��o de arquivos� de nome Ponteiro;
			FILE* PonteiroNovo; //idem acima
			FILE* PonteiroNovo2; //idem acima
			
			
			
			puts("<1> :::  Apartamentos");
			puts("<2> :::  Casas");
			puts("<3> :::  Ch�caras");
			puts("<4> :::  Terrenos");
			puts("<5+> ::: Sair"); printf("Opera��o: "); scanf("%i", &op); puts("");
			//exibe um menu e pergunta qual opera��o deseja fazer �Neste caso, que im�vel deseja alugar
			//l� o valor digitado e armazena na vari�vel op
			
			system("cls");
			//Limpa a tela 
			
			switch (op) //compare (vari�vel op)
			{
				case 1: // se vari�vel op for igual a 1
				
					printf("::: Alugar Apartamentos :::\n\n");
					printf("<1> ::: Listar Apartamento dispon�veis para Aluguel:\n<2> ::: Continuar sem listar\n "); printf("Opera��o: "); scanf("%i", &op); puts("\n");
					//Exibe a op��o que foi escolhida no menu anterior e pergunta se o usu�rio
					//deseja ver os apartamentos dispon�veis para aluguel
					//deseja continuar sem lista
					//l� o valor digitado e armazena na vari�vel op
					
					if(op == 1) // se op for igual a 1
					{
						system("cls"); // limpa a tela
						
						Ponteiro = fopen("AlugarApartamentos.txt", "r");  //Vari�vel Ponteiro = Abra ("AlugarApartamentos.txt", "no modo de leitura de informa��es"); 
						
						while (!feof(Ponteiro)) //enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em("AlugarApartamentos.txt"));
						{
			
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
							// L� as informa��es contidas no arquivo 
							
							printf("ID: %i \n", Info.ID);												
							printf("Andar: %i\n", Info.andar);														
							printf("Quantidade de Dormit�rio(s): %i \n", Info.Qtd_Dormitorio);   		
							printf("Quantidade de Su�te(s): %i \n", Info.Qtd_Suite);					
							printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);						
							printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);	    
							printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);				
							printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);				//   EXIBE TODAS AS INFORMA��ES SOBRE TODOS OS APARTAMENTOS REGISTRADOS E DISPON�VEIS
							ColocarEspaco(Info.infraestrutura);											// 	 PARA ALUGUEL
							printf("Informa��es da Infraestrutura: %s \n", Info.infraestrutura);			 
							ColocarEspaco(Info.endereco);												 	
							printf("Endere�o: %s \n", Info.endereco);									
							printf("Possui �rea de lazer?: %s\n", Info.Area_de_Lazer);					
							printf("�rea total: %.2f\n", Info.Area_do_terreno);							
							printf("Terreno total constru�do: %.2f\n", Info.Area_construida_total);			
							printf("Valor do Im�vel: %.2f\n", Info.valor_do_imovel);					
							printf("N� de telefone: %s\n\n", Info.n_telefone);							
		 			 }
		  			 fclose(Ponteiro);  //feche (AlugarApartamentos.txt);
		  			 printf("Listagem conclu�da!\n\n"); //Coloque em tela("Listagem conclu�da");
				}

		
				cracha:    //Ponto usado em conjunto ao comando goto, usado posteriormente
				
				PonteiroNovo = fopen("Corretores.txt", "r");  // vari�vel PonteiroNovo � igual a Abra("Corretores.txt", "modo leitura");
				
				Info3.numero_do_cracha = 0;  //vari�vel Info3.numero_do_crach� recebe 0 como valor
				
				printf("Por favor informe o crach�: "); scanf("%i", &cracha); puts(""); //pede ao usu�rio que informe seu crach�, L� e armazena na vari�vel cracha
				
				while(!feof(PonteiroNovo)) //enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "Corretores.txt");
				{
				
					fscanf(PonteiroNovo, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);		
					// L� as informa��es contidas no arquivo 
					
					if(Info2.numero_do_cracha == cracha) 		// Aqui ocorre o teste condicional. Previamente definimos a vari�vel Info3.numero_do_crach� como 0
					{											// Se (vari�vel Info2.numero_do_cracha for igual a vari�vel cracha) 	
						Info3.numero_do_cracha = cracha;		// Info3.numero_do_crach� recebe o valor da vari�vel crach�. Sendo assim, se n�o houver nenhum 
					}											// crach� registrado igual ao crach� informado, ser� emitida uma mensagem de erro.
				
				} //fim do la�o de repeti��o
				
				fclose(PonteiroNovo); //feche(Corretores.txt);
				
				if (Info3.numero_do_cracha == 0)  //se (Info3.numero_do_cracha for igual a 0) significa que o crach� informado n�o foi encontrado
				{
					printf("Crach� n�o existe/n�o registrado!\n\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o crach� n�o existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// l� o valor e armazena na vari�vel op
					
					if (op == 1) //se op for igual a 1
					{
						goto cracha; //volta no ponto cracha, definido previamente na linha 100
					} 
					else //se n�o
					{
						goto fim; // vai at� o ponto fim, definido posteriormente na linha 
					}
				} //fim da compara��o 
				
				
				

				id: 	//Ponto usado em conjunto ao comando goto, usado posteriormente
				
				printf("Digite o ID do apartamento: "); scanf("%i", &id); puts("\n"); //pede ao usu�rio que informe seu id, l� e armazena na vari�vel id
				
				Ponteiro = fopen("AlugarApartamentos.txt", "r"); // vari�vel PonteiroNovo � igual a Abra("AlugarApartamentos.txt", "modo leitura");
				
				while(!feof(Ponteiro)) //enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "AlugarApartamentos.txt");
				{
																
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// L� as informa��es contidas no arquivo "Corretores.txt"
									
					if(id == Info.ID) // se Info.ID for igual a var�vel id (Se algum ID no arquivo "AlugarApartamentos.txt" for igual ao id informado para aluguel
					{
						vf = 1; //vf � igual a 1 (servir� para compara��o posteriormente)
						
						PonteiroNovo2 = fopen("ApartamentosAlugados.txt", "a+"); // vari�vel PonteiroNovo2 � igual a Abra("ApartamentosAlugados.txt", "modo escrita");
						
						fprintf(PonteiroNovo2, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info3.numero_do_cracha, Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);					
						//insira no arquivo(ApartamentosAlugados.txt, "as informa��es contidas no arquivo "AlugarApartamentos + o crach�
						// do corretor respons�vel por intermediar a opera��o.
						
						fclose(PonteiroNovo2); //fecha (ApartamentosAlugados.txt)
					}
				
				}
				fclose(Ponteiro); //fecha (AlugarApartamentos.txt)
				
				
				//vf foi definido previamente como 0.
				if (vf == 0) //se (vf for igual a 0) significa que o id informado n�o foi encontrado
				{			
					printf("ID n�o existe/n�o registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o id n�o existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// l� o valor e armazena na vari�vel op
					
					if (op == 1) //se op for igual a 1
					{
						goto id; //volta no ponto id, definido previamente na linha 144
					} 
					else //se n�o
					{
						goto fim; // vai at� o ponto fim, definido posteriormente na linha 
					}
				}//fim da compara��o 
				
				
					
				
				Ponteiro = fopen("AlugarApartamentos.txt","r");  // vari�vel Ponteiro � igual a Abra("AlugarApartamentos.txt", "modo leitura");
				FILE* PonteiroNovo = fopen("AlugarApartamentos_novo.txt", "w"); // vari�vel PonteiroNovo � igual a Abra("AlugarApartamentos_novo.txt", "modo escrita");
						
						while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "AlugarApartamentos.txt");
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 
							// L� as informa��es contidas no arquivo "AlugarApartamentos.txt.txt"
							
							if (Info.ID != id) // se Info.ID for diferente da var�vel id (Se algum ID no arquivo "AlugarApartamentos.txt" for diferente do id informado para aluguel
							{	
								fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
								//insira no arquivo(AlugarApartamentos_novo.txt, "as informa��es contidas no arquivo "AlugarApartamentos)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del AlugarApartamentos.txt"); //sistema (delete AlugarApartamentos.txt)
						system("rename AlugarApartamentos_novo.txt AlugarApartamentos.txt"); //sistema (renomeie AlugarApartamentos_novo.txt com o nome AlugarApartamentos.txt)
						break; //fim do primeiro case		
			
			
			case 2:
					printf("::: Alugar Casas :::\n\n");
					printf("<1> ::: Listar Casas dispon�veis para aluguel:\n<2> ::: Continuar sem listar\n "); printf("Opera��o: "); scanf("%i", &op); puts("/n"); system("cls");
					//Exibe a op��o que foi escolhida no menu anterior e pergunta se o usu�rio
					//deseja ver os casas dispon�veis para aluguel
					//deseja continuar sem lista
					//l� o valor digitado e armazena na vari�vel op
					
					if(op == 1) // se op for igual a 1
					{
						system("cls"); // limpa a tela
					
						Ponteiro = fopen("AlugarCasa.txt", "r"); //Vari�vel Ponteiro = Abra ("AlugarCasa.txt", "no modo de leitura de informa��es"); 
						
						while (!feof(Ponteiro)) //enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em("AlugarCasa.txt"));
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
							// L� as informa��es contidas no arquivo 
							
							printf("ID: %i \n", Info.ID);
							printf("Quantidade de Dormit�rio(s): %i \n", Info.Qtd_Dormitorio);
							printf("Quantidade de Su�te(s): %i \n", Info.Qtd_Suite);
							printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
							printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
							printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
							printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
							ColocarEspaco(Info.infraestrutura);												//EXIBE TODAS AS INFORMA��ES SOBRE TODOS AS CASAS REGISTRADOS E DISPON�VEIS
							printf("Informa��es da Infraestrutura: %s \n", Info.infraestrutura);			//PARA ALUGUEL
							ColocarEspaco(Info.endereco);
							printf("Endere�o: %s \n", Info.endereco);
							printf("Possui �rea de lazer?: %s\n", Info.Area_de_Lazer);
							printf("�rea total: %.2f\n", Info.Area_do_terreno);
							printf("Terreno total constru�do: %.2f\n", Info.Area_construida_total);
							printf("Valor do Im�vel: %.2f\n", Info.valor_do_imovel);	
							printf("N� de telefone: %s\n\n", Info.n_telefone);
		 			 }
		  			 fclose(Ponteiro); //feche (AlugarCasa.txt);
		  			 printf("Listagem conclu�da!\n\n"); //Coloque em tela("Listagem conclu�da");
				}

			
				Info3.numero_do_cracha = 0; //vari�vel Info3.numero_do_crach� recebe 0 como valor

				
				cracha_2: //Ponto usado em conjunto ao comando goto, usado posteriormente
				
				PonteiroNovo = fopen("Corretores.txt", "r"); // vari�vel PonteiroNovo � igual a Abra("Corretores.txt", "modo leitura");
				
				printf("Por favor informe o crach�: "); scanf("%i", &cracha); puts(""); //pede ao usu�rio que informe seu crach�, L� e armazena na vari�vel cracha
				
				while(!feof(PonteiroNovo))	//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "Corretores.txt");
				{
				
					fscanf(PonteiroNovo, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);		
					// L� as informa��es contidas no arquivo 
					
					//Previamente definimos a vari�vel Info3.numero_do_cracha como 0
					
					if(Info2.numero_do_cracha == cracha)// Se (vari�vel Info2.numero_do_cracha for igual a vari�vel cracha)
					{										
						Info3.numero_do_cracha = cracha;  // Info3.numero_do_crach� recebe o valor da vari�vel crach�. 
					}
				}//fim do la�o de repeti��o
				
				fclose(PonteiroNovo); //feche(Corretores.txt);
				
				if (Info3.numero_do_cracha == 0)//se (Info3.numero_do_cracha for igual a 0) significa que o crach� informado n�o foi encontrado
				{
					printf("Crach� n�o existe/n�o registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o crach� n�o existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// l� o valor e armazena na vari�vel op
					
					if (op == 1) //se op for igual a 1
					{
						goto cracha_2;  //volta no ponto cracha, definido previamente na linha 100
					} 
					else //se n�o 
					{
						goto fim; // vai at� o ponto fim, definido posteriormente na linha 657
					}
				} //fim da compara��o
				
				
				

				id_2://Ponto usado em conjunto ao comando goto, usado posteriormente
				printf("Digite o ID do apartamento: "); scanf("%i", &id); puts("\n");//pede ao usu�rio que informe seu id, l� e armazena na vari�vel id
				
				Ponteiro = fopen("AlugarCasa.txt", "r");
				// vari�vel Ponteiro � igual a Abra("AlugarCasa.txt", "modo leitura");
				
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "AlugarCasa.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// L� as informa��es contidas no arquivo 
					
					if(id == Info.ID)// se Info.ID for igual a var�vel id (Se algum ID no arquivo for igual ao id informado para aluguel
					{	
						vf = 1;//vf � igual a 1 (servir� para compara��o posteriormente)
						PonteiroNovo2 = fopen("CasaAlugados.txt", "a+");
						fprintf(PonteiroNovo2, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info3.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
						//insira no arquivo(ApartamentosAlugados.txt, "as informa��es contidas no arquivo "AlugarApartamentos + o crach�
				//do corretor respons�vel por intermediar a opera��o.
						
						fclose(PonteiroNovo2);
						//fecha (ApartamentosAlugados.txt)
					}	
				}
				fclose(Ponteiro);//fecha (AlugarApartamentos.txt)
				
				
				if (vf == 0)//se (vf for igual a 0) significa que o id informado n�o foi encontrado
				{
					printf("ID n�o existe/n�o registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o id n�o existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// l� o valor e armazena na vari�vel op
					
					if (op == 1)//se op for igual a 1
					{
						goto id_2; //volta no ponto id, definido previamente na linha 144
					} 
					else //se n�o
					{
						goto fim; // vai at� o ponto fim, definido posteriormente na linha 657
					}
				} //fim da compara��o
				
					
				
				Ponteiro = fopen("AlugarCasa.txt","r"); // vari�vel Ponteiro � igual a Abra("AlugarCasa.txt", "modo leitura");
				PonteiroNovo = fopen("AlugarCasa_novo.txt", "w"); // vari�vel PonteiroNovo � igual a Abra("AlugarCasa_novo.txt", "modo escrita");
						
						while(!feof(Ponteiro)) //enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "AlugarCasa.txt");
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 
							// L� as informa��es contidas no arquivo 
							
							if (Info.ID != id) // se Info.ID for diferente da var�vel id (Se algum ID no arquivo for diferente do id informado para aluguel
							{	
								fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
								//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del AlugarCasa.txt"); //sistema (delete arquivo ----.txt)
						system("rename AlugarCasa_novo.txt AlugarCasa.txt");//sistema (renomeie ----.txt para ---.txt)
						break;//fim do segundo case
						
			case 3:
					printf("::: Alugar Ch�caras :::\n\n");
					printf("<1> ::: Listar Ch�caras dispon�veis para aluguel:\n<2> ::: Continuar sem listar\n "); printf("Opera��o: "); scanf("%i", &op); puts("/n"); system("cls");
					//Exibe a op��o que foi escolhida no menu anterior e pergunta se o usu�rio
					//deseja ver os ch�caras dispon�veis para aluguel
					//deseja continuar sem lista
					//l� o valor digitado e armazena na vari�vel op
					
					if(op == 1) // se op for igual a 1
					{
						system("cls"); // limpa a tela
					
						Ponteiro = fopen("AlugarChacaras.txt", "r"); //Vari�vel Ponteiro = Abra ("AlugarChacaras.txt", "no modo de leitura de informa��es"); 
						
						while (!feof(Ponteiro)) //enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em("AlugarChacaras.txt"));
						{
							
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
							// L� as informa��es contidas no arquivo 
							
							printf("ID: %i \n", Info.ID);
							printf("Quantidade de Dormit�rio(s): %i \n", Info.Qtd_Dormitorio);
							printf("Quantidade de Su�te(s): %i \n", Info.Qtd_Suite);
							printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
							printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
							printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
							printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
							ColocarEspaco(Info.infraestrutura);
							printf("Informa��es da Infraestrutura: %s \n", Info.infraestrutura); 	//   EXIBE TODAS AS INFORMA��ES SOBRE TODOS OS APARTAMENTOS REGISTRADOS E DISPON�VEIS PARA ALUGUEL
							ColocarEspaco(Info.endereco);
							printf("Endere�o: %s \n", Info.endereco);
							printf("Possui �rea de lazer?: %s\n", Info.Area_de_Lazer);
							printf("�rea total: %.2f\n", Info.Area_do_terreno);
							printf("Terreno total constru�do: %.2f\n", Info.Area_construida_total);
							printf("Valor do Im�vel: %.2f\n", Info.valor_do_imovel);	
							ColocarEspaco(Info.n_telefone);
							printf("n� de telefone: %s\n", Info.n_telefone);
		 			 }
		  			 fclose(Ponteiro);	//feche (---.txt);
		  			 printf("Listagem conclu�da!\n\n");	//Coloque em tela("Listagem conclu�da");
				}


				cracha_3: //Ponto usado em conjunto ao comando goto, usado posteriormente
				
				PonteiroNovo = fopen("Corretores.txt", "r");
				
				printf("Por favor informe o crach�: "); scanf("%i", &cracha); puts("");
				
				while(!feof(PonteiroNovo))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
				{
				
					fscanf(PonteiroNovo, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);		
					// L� as informa��es contidas no arquivo 
					
					//Previamente definimos a vari�vel Info3.numero_do_cracha como 0
					if(Info2.numero_do_cracha == cracha) // Se (vari�vel Info2.numero_do_cracha for igual a vari�vel cracha) 
 	
					{
						Info3.numero_do_cracha = cracha; // Info3.numero_do_crach� recebe o valor da vari�vel crach�.  
					}
				}//fim do la�o de repeti��o
				fclose(PonteiroNovo);//feche(----.txt);
				
				if (Info3.numero_do_cracha == 0)//se (Info3.numero_do_cracha for igual a 0) significa que o crach� informado n�o foi encontrado
				{
					printf("Crach� n�o existe/n�o registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o crach� n�o existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// l� o valor e armazena na vari�vel op			
					
					if (op == 1)//se op for igual a 1
					{
						goto cracha_3;//volta no ponto cracha, definido previamente na linha 100
					} 
					else//se n�o
					{
						goto fim;// vai at� o ponto fim, definido posteriormente na linha 657
					}
				}//fim da compara��o 
				
				
				

				id_3://Ponto usado em conjunto ao comando goto, usado posteriormente
				printf("Digite o ID da Ch�cara: "); scanf("%i", &id); puts("\n"); //pede ao usu�rio que informe seu id, l� e armazena na vari�vel id
				
				Ponteiro = fopen("AlugarChacaras.txt", "r");// vari�vel Ponteiro � igual a Abra("----.txt", "modo leitura");
				
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em Ponteiro);
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// L� as informa��es contidas no arquivo
					if(id == Info.ID)// se Info.ID for igual a var�vel id (Se algum ID no arquivo for igual ao id informado para aluguel)
					{
						vf = 1;//vf � igual a 1 (servir� para compara��o posteriormente)
						PonteiroNovo2 = fopen("ChacarasAlugados.txt", "a+"); // vari�vel PonteiroNovo2 � igual a Abra("----.txt", "modo escrita");
						fprintf(PonteiroNovo2, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info3.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
						//insira no arquivo(PonteiroNovo2, "as informa��es contidas em Ponteiro + o n�mero do crach� do corretor intermedi�rio da opera��o

						fclose(PonteiroNovo2);//fecha (PonteiroNovo2)
						
					}	
				}
				fclose(Ponteiro);//fecha (Ponteiro)
				
				//vf foi definido previamente como 0.
				if (vf == 0)//se (vf for igual a 0) significa que o id informado n�o foi encontrado
				{
					printf("ID n�o existe/n�o registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o id n�o existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// l� o valor e armazena na vari�vel op
					
					if (op == 1)//se op for igual a 1
					{
						goto id_3;//volta no ponto id, definido previamente na linha 144
					} 
					else//se n�o
					{
						goto fim;// vai at� o ponto fim, definido posteriormente na linha 657
					}
				}//fim da compara��o 
				
				
					
				
				Ponteiro = fopen("AlugarChacaras.txt","r"); // vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
				PonteiroNovo = fopen("AlugarChacaras_novo.txt", "w"); // vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
						
						while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 							 //acessar os d    "%i %i %i %i %i %i %i %i %s %s %s %f %f %f\n"
							// L� as informa��es contidas no arquivo
							
							if (Info.ID != id) // se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{	
								fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
								//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del AlugarChacaras.txt");//sistema (delete arquivo ----.txt)
						system("rename AlugarChacaras_novo.txt AlugarChacaras.txt");//sistema (renomeie ----.txt para ---.txt)
						break;	//fim do terceiro case

			case 4:
					printf("::: Alugar Terrenos :::\n\n");
					printf("<1> ::: Listar Terrenos dispon�veis para aluguel:\n<2> ::: Continuar sem listar\n "); printf("Opera��o: "); scanf("%i", &op); puts("/n"); system("cls");
					//Exibe a op��o que foi escolhida no menu anterior e pergunta se o usu�rio
					//deseja ver os Terrenos dispon�veis para aluguel
					//deseja continuar sem lista
					//l� o valor digitado e armazena na vari�vel op
					
					if(op == 1) // se op for igual a 1
					{
						system("cls"); // limpa a tela
					
						Ponteiro = fopen("AlugarTerrenos.txt", "r"); //Vari�vel Ponteiro = Abra ("AlugarTerenos.txt", "no modo de leitura de informa��es"); 
					
						while (!feof(Ponteiro)) //enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em("AlugarTerenos.txt"));
						{
			
						    fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
							// L� as informa��es contidas no arquivo 
							
							printf("ID: %i \n", Info.ID);
							printf("�rea total: %.2f\n", Info.Area_do_terreno);
							printf("Valor do Im�vel: %.2f\n", Info.valor_do_imovel);//   EXIBE TODAS AS INFORMA��ES SOBRE TODOS OS TERRENOS REGISTRADOS E DISPON�VEIS PARA ALUGUEL
							printf("Endere�o: %s\n\n", Info.endereco);	
							printf("n� de telefone: %s", Info.n_telefone);
		 			 	}
		  			 	fclose(Ponteiro);//feche (---.txt);
		  				 printf("Listagem conclu�da!\n\n");//Coloque em tela("Listagem conclu�da");
					}


		
				
				cracha_4://Ponto usado em conjunto ao comando goto, usado posteriormente
				Info3.numero_do_cracha = 0;//vari�vel Info3.numero_do_cracha recebe 0 como valor
				PonteiroNovo = fopen("Corretores.txt", "r");// vari�vel PonteiroNovo � igual a Abra("---.txt", "modo leitura");
				
				printf("Por favor informe o crach�: "); scanf("%i", &cracha); puts("");//pede ao usu�rio que informe seu crach�, L� e armazena na vari�vel cracha
			
				while(!feof(PonteiroNovo))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
				{
				
					fscanf(PonteiroNovo, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);		
					// L� as informa��es contidas no arquivo 
					
					//Previamente definimos a vari�vel Info3.numero_do_cracha como 0
					if(Info2.numero_do_cracha == cracha)// Se (vari�vel Info2.numero_do_cracha for igual a vari�vel cracha) 	
					{
						Info3.numero_do_cracha = cracha;// Info3.numero_do_crach� recebe o valor da vari�vel crach�.
					}
				}//fim do la�o de repeti��o
				fclose(PonteiroNovo);//feche(----.txt);
				
				if (Info3.numero_do_cracha == 0)//se (Info3.numero_do_cracha for igual a 0) significa que o crach� informado n�o foi encontrado
				{
					printf("Crach� n�o existe/n�o registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o crach� n�o existe e o questiona 
					// tentar novamente 
					// sair 2+
					// l� o valor e armazena na vari�vel op					
					
					if (op == 1)//se op for igual a 1
					{
						goto cracha_4; //volta no ponto cracha, definido previamente na linha 100
					} 
					else//se n�o
					{
						goto fim;// vai at� o ponto fim, definido posteriormente na linha 657
					}
				}//fim da compara��o 
				
				
				

				id_4://Ponto usado em conjunto ao comando goto, usado posteriormente
				printf("Digite o ID do apartamento: "); scanf("%i", &id); puts(""); //pede ao usu�rio que informe seu id, l� e armazena na vari�vel id
				Ponteiro = fopen("AlugarTerrenos.txt", "r");// vari�vel Ponteiro � igual a Abra("----.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em Ponteiro);
				{
					fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
					// L� as informa��es contidas no arquivo
					if(id == Info.ID)// se Info.ID for igual a var�vel id (Se algum ID no arquivo for igual ao id informado para aluguel)
					{
						vf = 1;//vf � igual a 1 (servir� para compara��o posteriormente)
						PonteiroNovo2 = fopen("TerrenosAlugados.txt", "a+");// vari�vel PonteiroNovo2 � igual a Abra("----.txt", "modo leitura");
						fprintf(PonteiroNovo2, "%i %i %f %f %s %s\n", Info.ID, Info3.numero_do_cracha, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);
						//insira no arquivo(PonteiroNovo2, "as informa��es contidas em Ponteiro + o n�mero do crach� do corretor intermedi�rio da opera��o
						fclose(PonteiroNovo2);
						//fecha (PonteiroNovo2)
					}	
				}
				fclose(Ponteiro);	//fecha (Ponteiro)
				
				//vf foi definido previamente como 0.
				if (vf == 0)//se (vf for igual a 0) significa que o id informado n�o foi encontrado
				{
					printf("ID n�o existe/n�o registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o id n�o existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// l� o valor e armazena na vari�vel op
					
					if (op == 1)//se op for igual a 1
					{
						goto id_4;//volta no ponto id, definido previamente na linha 144
					} 
					else//se n�o
					{
						goto fim;// vai at� o ponto fim, definido posteriormente na linha 657
					}
				}//fim da compara��o 

				
				Ponteiro = fopen("AlugarTerrenos.txt","r"); // vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
				PonteiroNovo = fopen("AlugarTerrenos_novo.txt", "w"); // vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
						
						while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
						{
							fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
							// L� as informa��es contidas no arquivo
							if (Info.ID != id) // se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{	
								fprintf(PonteiroNovo, "%i %f %f %s\n", Info.ID, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);
								//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del AlugarTerrenos.txt");//sistema (delete arquivo ----.txt)
						system("rename AlugarTerrenos_novo.txt AlugarTerrenos.txt");//sistema (renomeie ----.txt para ---.txt)
						break;		//fim do quarto case				
			default: //se nenhum case correspondeu a o n�mero informado pelo usu�rio significa que ele deseja sair da tela.
					//default � a op��o que o programa escolhe quando todas os case foram testados e nenhum correspondeu	
				break;
				
			}// Fim switch
			fim:		//Ponto usado em conjunto ao comando goto, usado previamente
		printf("Opera��o Finalizada!\n\n"); //coloque em tela ("---------");
}

int login(int x)//cria uma fun��o do tipo inteiro de nome login(que ir� receber uma vari�vel do tipo inteiro e retornar um valor a ela)
{
	Corretor Info; //Cria uma vari�vel do tipo Corretor de nome info
	char senha[12]; // cria uma vari�vel do tipo caracteres de nome senha[com 12 espa�os]
	int cracha, op = -1, op2 = 0, vf; //cria vari�veis do tipo inteiro de nomes cracha, op com valor -1, op2 com valor 0, e vf;
	FILE* Ponteiro; //cria uma vari�vel do tipo FILE de nome Ponteiro �O tipo file permite ao usu�rio manipular arquivos

	inicio: //Ponto usado em conjunto ao comando goto, usado posteriormente
	system("cls"); //limpa a tela
	puts("<1> ::: Login"); 
	puts("<2> ::: Cadastrar");
	puts("<3+> ::: Sair");
	printf("Opera��o: "); scanf("%i", &op); puts("");
	// o sistema exibe um menu pedindo que o usu�rio informe:
	// se deseja fazer login 
	// se deseja cadastrar corretor
	//L� o valor digitado e armazena na vari�vel op
	
	system("cls"); //limpa tela
	
	switch(op)//compare (vari�vel op)
	{
		case 1: //se vari�vel op = 1
			puts("\n::: Login :::\n\n"); //coloque em tela ("----------"); OBS: \n serve para quebrar linha e puts � uma fun��o que coloca uma string em tela
		
			 
			printf("Crach�: "); scanf("%i", &cracha); puts("");//L� o valor digitado e armazena na vari�vel cracha
		
			Ponteiro = fopen("Corretores.txt", "r");//Vari�vel Ponteiro = Abra ("-----.txt", "no modo de leitura de informa��es"); 
			
		
			
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em(Ponteiro));
				{
					fscanf(Ponteiro, "%i %s %s %s %i %f %f\n", &Info.numero_do_cracha, Info.nome, Info.data_contratacao, Info.data_nascimento, &Info.idade, &Info.salario_b, &Info.comissao_pvenda);
					// L� as informa��es contidas no arquivo 
					
					if(cracha == Info.numero_do_cracha)// Se (vari�vel cracha for igual a vari�vel Info.numero_do_cracha ) 	
					{
						op2 = 1; //vari�vel op2 recebe 1		
					}	//fim da compara��o	
					
				}
				
			fclose(Ponteiro); //fecha(----.txt)
			
			if (op2 == 0)
			{
				printf("Crach� n�o registrado\n\nTentar Novamente?\n\n<1> ::: Sim\n<2> ::: N�o\n\n");
				puts("Opera��o: "); scanf("%i", &op); puts("\n");
				// o sistema exibe uma mensagem informando que o crach� n�o est� cadastrado e o questiona 
				// tentar novamente 
				// sair 2+
				// l� o valor e armazena na vari�vel op
				
				if (op == 1)//se op = 1
				{
					system("cls"); //limpa tela
					goto inicio; //volta no ponto in�cio �linha 669
				}
				else//se n�o
				{
					return op2; //retorne op2. O valor de op2 servir� como par�metro para compara��o do sucesso ou n�o do login �o comando encerra o uso da fun��o
				}
			} // fim da compar��o
			break;//fim do case 1
		
		case 2://caso op = 2
			corretor(); //Chama fun��o de cadastro de corretores �corretor()
			printf("Cadastro Conclu�do!\n\nPressione uma tecla para continuar: "); //coloque em tela ("------");
			getch(); //L� a tecla e retorna para o sistema
			goto inicio; //volta para o ponto da linha 669
			break;//fim do case2
			
	}
	return op2; //retorna valor de op2.	
}

void listarcorretores ()//cria uma fun��o do tipo vazio de nome listarcorretores()
{
	Corretor Info;  //Cria vari�vel do tipo Corretor de nome Info
	printf("::: Listar Corretores :::\n\n");    //coloque em tela(" ------ ");
	Ponteiro = fopen("Corretores.txt", "r");   //Vari�vel Ponteiro = abra("Corretores.txt", "em modo de leitura");
		
		while(!feof(Ponteiro))   //enquanto(todas as informa��es no arquivo n�o forem lidas(leia "Corretores.txt"));
		{
			if(Info.numero_do_cracha == NULL) //se (Info.numero_do_cracha for igual a NULO)
			{
				printf("N�o existem registros!\n\n"); //significa que n�o h� informa��es cadastradas
				return 0;
			} 
		
			fscanf(Ponteiro, "%i %s %s %s %i %f %f\n", &Info.numero_do_cracha, Info.nome, Info.data_contratacao, Info.data_nascimento, &Info.idade, &Info.salario_b, &Info.comissao_pvenda);
				//leia(as informa��es contidas em "Corretores.txt", "valor inteiro, string ...", contidas nas vari�veis de nome, Info.numero_do_cracha...);
			   // � importante pontuar aqui que, a maneira que as informa��es s�o gravadas tem de ser em qualquer tipo de leitura das informa��es.
		  	  //  EX: Supondo que as informa��es foram gravadas assim: fprintf(Ponteiro, "%i\n", x); elas ter�o de ser lidas da mesma forma
		 	 //   ou seja: fscanf("Ponteiro, "%i\n", &x);
		
			printf("Crach�: %i\n", Info.numero_do_cracha);									   //
			ColocarEspaco(Info.nome);														  //		
			printf("Nome: %s\n", Info.nome);											     //	
			printf("Data de nascimento: %s\n", Info.data_nascimento);					 	// IMPRIME AS INFORMA��ES CONTIDAS
			printf("Data de Contrata��o: %s\n", Info.data_contratacao);					   // NO ARQUIVO "Corretores.txt"
			printf("Idade: %i\n", Info.idade);											  //
			printf("Sal�rio Bruto: %0.2f\n", Info.salario_b);							 //
			printf("Comiss�o por venda: %0.2f\n\n", Info.comissao_pvenda);				//
		
		}   //Volta no loop �la�o de repeti��o � at� que todas as informa��es tenham sido lidas
		
		fclose(Ponteiro);   //Feche (---.txt)
		puts("Fim da listagem!\n\n"); //coloque em tela (" ---- ");
		return 0;						  
}

void TirarEspaco(char texto[]) //cria uma fun��o de nome TirarEspaco(que ir� receber uma vari�vel do tipo caractere em matriz e ir� retornar a mesma modificada)
{
	int i; //cria uma vari�vel do tipo inteiro de nome i
    for (i=0;i<strlen(texto);i++) //para (i=0; enquanto i for menor que o tamanho(do texto enviado); i++)
    {
		if (texto[i]==' ')//se (texto(na posi��o x da matriz) for igual a um espa�o
		{
			texto[i]='+'; //ele insere o sinal +
		}
	}//volta no loop at� que se ache a �ltima posi��o de texto
}//fim da fun��o

void ColocarEspaco(char texto[])//cria uma fun��o de nome TirarEspaco(que ir� receber uma vari�vel do tipo caractere em matriz e ir� retornar a mesma modificada)
{
	int i;//cria uma vari�vel do tipo inteiro de nome i
	for (i=0;i<strlen(texto);i++)//para (i=0; enquanto i for menor que o tamanho(do texto enviado); i++)
	{
		if (texto[i]=='+')//se (texto(na posi��o x da matriz) for igual a um +
		{
			texto[i]=' ';//ele insere um espa�o
		}
	}//volta no loop at� que se ache a �ltima posi��o de texto
}//fim da fun��o

void SimulacaoFinanciamento ()//cria uma fun��o do tipo vazio de nome SimulacaoFinanciamento()
{
		int op;//cria uma vair�vel do tipo inteiro de nome op
		
		float juros=0, juros_c=0, saldo_devedor=0, amortizacao = 0, valor_parcela=0, valor_parcela_aux, tempo=0, parcela = 0;
		//cria vari�veis do tiop real de nomes ...;	
		
		Ficha_Tecnica_Imovel Info; //cria uma vari�vel do tipo Ficha_Tecnica_Imovel de nome Info


		puts("<1> ::: SAC");
		puts("<2> ::: PRICE");
		puts("<3+> ::: Sair");
		printf("Opera��o: "); scanf("%i", &op); puts("");
		system("cls");
		// o sistema exibe um menu questionando que opera��o o usu�rio deseja executar
		// 1 Tabela SAC
		// 2 TABELA PRICE
		//3+ Sair
		// l� o valor e armazena na vari�vel op
		
		switch (op) //compare op
		{
			case 1: //caso op = 1
				printf("::: Financiamento SAC :::\n\n");//exibe a op��o escolhida pelo usu�rio
				printf("Digite o valor do im�vel: "); //pede ao usu�rio que informe o valor do im�vel
				scanf("%f", &Info.valor_do_imovel);//L� o valor e armazena na vari�vel ----
				printf("Digite o juros: ");//pede ao usu�rio que informe a taxa de juros 
				scanf("%f", &juros);//L� o valor e armazena na vari�vel ----
				printf("Tempo em meses: ");//pede ao usu�rio que informe o tempo em meses
				scanf("%f", &tempo); puts("\n\n");//L� o valor e armazena na vari�vel ---- pula duas linhas
				
				juros = juros / 100; //transforma o n�mero digitado em decimal
				amortizacao = Info.valor_do_imovel/tempo; //vari�vel amortizacao � igual a divis�o das vari�veis --- / ---
				saldo_devedor = Info.valor_do_imovel; //vari�vel saldo_devedor = ---

				printf(":M�s:\t:Amortizacao:\t:Juros:\t:Parcela:\t:Saldo:\n"); //exibe as guias da tabela
				printf(" %0.2f \t %0.2f \t%0.2f \t%0.2f   \t\t%0.2f\n", parcela, amortizacao, juros_c, valor_parcela, saldo_devedor); 
				//exibe a primeira linha (com quase todos os valores em 0
				
					while (parcela < tempo) //enquanto parcela �que � igual a 0� for menor que o tempo
					{
						saldo_devedor = saldo_devedor - amortizacao; //saldo_devedor = --- - ---;
						juros_c = juros * saldo_devedor; //juros_c = --- * ---;
						valor_parcela = juros_c + amortizacao; //valor_parcela = --- + ---;
						parcela = parcela + 1; //parcela recebe + 1;
						printf("%0.2f  \t%0.2f  \t%0.2f  \t%0.2f   \t%0.2f\n", parcela, amortizacao, juros_c, valor_parcela, saldo_devedor);
						//exibe os valores dos c�lculos realizados
					}//volta no loop. quando parcela for igual a tempo, a execu��o para
				break;//saia do swich
			case 2:
				printf("::: Financiamento PRICE :::\n\n");//exibe a op��o escolhida pelo usu�rio
				printf("Digite o valor: ");//pede ao usu�rio que informe o valor do im�vel
				scanf("%f", &Info.valor_do_imovel);//L� o valor e armazena na vari�vel ----
				printf("Digite o juros: ");//pede ao usu�rio que informe a taxa de juros 
				scanf("%f", &juros);//L� o valor e armazena na vari�vel ----
				printf("Tempo em meses: ");//pede ao usu�rio que informe o tempo em meses
				scanf("%f", &tempo); puts("\n\n");//L� o valor e armazena na vari�vel ----; pula duas linhas;
				
				juros = (juros / 100)+1; //juros = (--- / 100)+1;
				
				
				saldo_devedor = Info.valor_do_imovel; //saldo_devedor = ---;
				valor_parcela = (pow (juros, tempo)-1); //valor_parcela = (eleve (---- a ----)-1);
				valor_parcela_aux = pow (juros, tempo) * (juros - 1); //valor_parcela_aux = eleve (---- a ----) vezes (--- - 1);
				valor_parcela = (valor_parcela_aux / valor_parcela) * Info.valor_do_imovel; //valor_parcela = (---- / ----) vezes ----;
				juros = juros -1; //juros = --- - 1;
				saldo_devedor = Info.valor_do_imovel;//saldo_devedor = ----;
				
				printf(":M�s:\t:Amortizacao:\t:Juros:\t:Parcela:\t:Saldo:\n"); //exibe as guias da tabela
				printf(" %0.2f \t %0.2f \t\t%0.2f \t%0.2f  \t%0.2f\n", parcela, amortizacao, juros_c, valor_parcela, saldo_devedor);
				//exibe a primeira linha (com quase todos os valores em 0
					
					while (parcela < tempo)//enquanto parcela �que � igual a 0� for menor que o tempo
					{
						parcela = parcela + 1; //parcela recebe + 1;
						juros_c = juros * saldo_devedor; //juros_c = --- vezes ----;
						amortizacao = valor_parcela - juros_c;//amortizacao = --- menos ---;
						saldo_devedor = saldo_devedor - amortizacao;//saldo_vedor = --- - ---;
						printf(" %0.2f\t %0.2f \t%0.2f \t%0.2f \t\t%0.2f\n", parcela, amortizacao, juros_c, valor_parcela, saldo_devedor);
						//exibe os valores dos c�lculos realizados
					}//volta no loop. quando parcela for igual a tempo, a execu��o para
			break;//saia do switch
			
			default://se nenhum dos case comparados deram certo
				 break;	//saia do switch
		}//fim do switch
	puts("\n");
	return 0; //retorne 0;
}


void ListagemVendas ()//cria uma fun��o do tipo vazio de nome SimulacaoFinanciamento()
{
	int op; //cria uma vari�vel do tipo inteiro de nome op
	Ficha_Tecnica_Imovel Info, Info2; //cria vari�veis do tipo Ficha_Tecnica_Imovel de nomes ...;
	Corretor Info3;//Cria uma vari�vel do tipo Corretor de nome Info3
	printf("::: Listagem de Cadastro dos Im�veis � venda :::\n\n");
	
	
	puts("<1> ::: Para listar Apartamentos");
	puts("<2> ::: Para listar casas");
	puts("<3> ::: Para listar ch�caras");
	puts("<4> ::: Para listar Terrenos");
	puts("<5> ::: Para listar Im�veis Vendidos");
	puts("<6+> ::: Sair");
	printf("Opera��o: "); scanf("%i", &op); puts("");
	system("cls");
	//exibe um menu questionando que im�vel o usu�rio deseja listar
	//l� o valor e insere na vari�vel op
	//quebra linha
	//limpa tela
	
	switch (op) //compare op
	{
		case 1: //se op = 1
		    printf("::: Listar Apartamentos :::\n\n"); //exibe a op��o que o usu�rio digitou
		    Ponteiro = fopen("Apartamentos.txt", "r"); //vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
			
			while (!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
			{
			
				fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
				// L� as informa��es contidas no arquivo
				
				if (Info.ID == NULL) //se Info.ID for igual a um valor NULO significa que n�o h� registros, logo:
				{
					printf("N�o h� registros! \n\n"); //exibe uma mensagem informando o usu�rio
					return 0; //e sai da fun��o
					
				} //se Info.ID tiver um valor, a compara��o ocorre, e nada acontece
				
				printf("ID: %i \n", Info.ID);
				printf("Andar: %i\n", Info.andar);
				printf("Quantidade de Dormit�rio(s): %i \n", Info.Qtd_Dormitorio);
				printf("Quantidade de Su�te(s): %i \n", Info.Qtd_Suite);
				printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
				printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
				printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);               //EXIBE AS INFORMA��ES CADASTRADAS
				printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
				ColocarEspaco(Info.infraestrutura); 
				//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
				printf("Informa��es da Infraestrutura: %s \n", Info.infraestrutura);
				ColocarEspaco(Info.endereco);
				//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
				printf("Endere�o: %s \n", Info.endereco);
				printf("Possui �rea de lazer?: %s\n", Info.Area_de_Lazer);
				printf("�rea total: %.2f\n", Info.Area_do_terreno);
				printf("Terreno total constru�do: %.2f\n", Info.Area_construida_total);
				printf("Valor do Im�vel: %.2f\n", Info.valor_do_imovel);	
		  		printf("N� de telefone: %s\n\n", Info.n_telefone);
		  }
		  fclose(Ponteiro); //fecha (---.txt)
		  printf("Listagem conclu�da!\n\n"); //coloque em tela ("---------");
		  break;//saia do switch
	 
	  case 2://se op = 2
	  		printf("::: Listar Casas :::\n\n");//exibe a op��o que o usu�rio digitou
	  		
			Ponteiro = fopen("Casa.txt", "r");//vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
			while (!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
			{
				
				fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
				// L� as informa��es contidas no arquivo
				if (Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que n�o h� registros, logo:
				{
					printf("N�o h� registros! \n\n");//exibe uma mensagem informando o usu�rio
					return 0;//e sai da fun��o
						
				}//se Info.ID tiver um valor, a compara��o ocorre, e nada acontece
				printf("ID: %i \n", Info.ID);
				printf("Quantidade de Dormit�rio(s): %i \n", Info.Qtd_Dormitorio);
				printf("Quantidade de Su�te(s): %i \n", Info.Qtd_Suite);
				printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
				printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
				printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
				printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
				ColocarEspaco(Info.infraestrutura);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
				printf("Informa��es da Infraestrutura: %s \n", Info.infraestrutura);//EXIBE AS INFORMA��ES CADASTRADAS
				ColocarEspaco(Info.endereco);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
				printf("Endere�o: %s \n", Info.endereco);
				ColocarEspaco(Info.Area_de_Lazer);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
				printf("Possui �rea de lazer?: %s\n", Info.Area_de_Lazer);
				printf("�rea total: %0.2f\n", Info.Area_do_terreno);
				printf("Terreno total constru�do: %0.2f\n", Info.Area_construida_total);
				printf("Valor do Im�vel: %0.2f\n", Info.valor_do_imovel);	
				printf("N� de telefone: %s\n\n", Info.n_telefone);
		  }
		  fclose(Ponteiro);//fecha (---.txt)
		  printf("Listagem conclu�da!\n\n");//coloque em tela ("---------");
		  break;//saia do switch
	  
	case 3://se op = 3
		printf("::: Listar Ch�caras :::\n\n");//exibe a op��o que o usu�rio digitou
		Ponteiro = fopen("Chacaras.txt", "r");//vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
		while (!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
		{
			
			fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);				
			// L� as informa��es contidas no arquivo
			if (Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que n�o h� registros, logo:
			{
				printf("N�o h� registros! \n\n");//exibe uma mensagem informando o usu�rio
				return 0;//e sai da fun��o		
			}//se Info.ID tiver um valor, a compara��o ocorre, e nada acontece			
			printf("ID: %i \n", Info.ID);
			printf("Quantidade de Dormit�rio(s): %i \n", Info.Qtd_Dormitorio);
			printf("Quantidade de Su�te(s): %i \n", Info.Qtd_Suite);
			printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
			printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
			printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
			printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
			ColocarEspaco(Info.infraestrutura);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
			printf("Informa��es da Infraestrutura: %s \n", Info.infraestrutura);		//EXIBE AS INFORMA��ES CADASTRADAS
			ColocarEspaco(Info.endereco);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
			printf("Endere�o: %s \n", Info.endereco);
			printf("Possui �rea de lazer?: %s\n", Info.Area_de_Lazer);
			printf("�rea total: %.2f\n", Info.Area_do_terreno);
			printf("Terreno total constru�do: %.2f\n", Info.Area_construida_total);
			printf("Valor do Im�vel: %.2f\n", Info.valor_do_imovel);	
	  		printf("N� de telefone: %s\n\n", Info.n_telefone);
	  }
	  fclose(Ponteiro);//fecha (---.txt)
	  printf("Listagem conclu�da!\n\n");//coloque em tela ("---------");
	  break;//saia do switch

	case 4:	//se op = 4
		printf("::: Listar Terrenos :::\n\n");//exibe a op��o que o usu�rio digitou
		Ponteiro = fopen("Terrenos.txt", "r");//vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
		while (!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
		{
			
			fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
			// L� as informa��es contidas no arquivo
			if (Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que n�o h� registros, logo:
			{
				printf("N�o h� registros! \n\n");//exibe uma mensagem informando o usu�rio
				return 0;//e sai da fun��o
					
			}//se Info.ID tiver um valor, a compara��o ocorre, e nada acontece		
			printf("ID: %i \n", Info.ID);
			printf("�rea total: %.2f\n", Info.Area_do_terreno);//EXIBE AS INFORMA��ES CADASTRADAS
			printf("Valor do Im�vel: %.2f\n", Info.valor_do_imovel);	
			printf("N� de telefone: %s\n\n", Info.n_telefone);
	  	}
	  	fclose(Ponteiro);//fecha (---.txt)
	  	printf("Listagem conclu�da!\n\n");//coloque em tela ("---------");
	  	break;//saia do switch
	
	case 5:
		printf("::: Listar Im�veis Vendidos :::\n\n");//exibe a op��o que o usu�rio digitou
		puts("<1> ::: Para listar Apartamentos");
		puts("<2> ::: Para listar casas");
		puts("<3> ::: Para listar ch�caras");
		puts("<4> ::: Para listar Terrenos");  printf("Opera��o: "); scanf("%i", &op);  puts(""); 
		system("cls");
		//exibe um menu questionando que im�vel o usu�rio deseja listar
		//l� o valor e insere na vari�vel op
		//quebra linha
		//limpa tela		
		switch (op)//compare (op)
		{
			case 1://se op = 1
				printf("::: Apartamentos Vendidos :::\n\n");//exibe a op��o que o usu�rio digitou
				Ponteiro = fopen("ApartamentosVendidos.txt", "r");//vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");								
				
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info3.numero_do_cracha, &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// L� as informa��es contidas no arquivo
					if (Info3.numero_do_cracha == NULL)//se Info3.numero_do_cracha for igual a um valor NULO significa que n�o h� registros, logo:
					{
					printf("N�o h� registros! \n\n");//exibe uma mensagem informando o usu�rio
					return 0;//e sai da fun��o	
							
					}//se Info.ID tiver um valor, a compara��o ocorre, e nada acontece	
					
					//EXIBE AS INFORMA��ES CADASTRADAS			
					printf("ID: %i\n", Info.ID);
					printf("Andar: %i\n", Info.andar);
					printf("Crach� do Vendedor: %i\n", Info3.numero_do_cracha);
					printf("Dormit�rio<s>: %i\n", Info.Qtd_Dormitorio);
					printf("Su�te<s>: %i\n", Info.Qtd_Suite);
					printf("Sala<s>: %i\n", Info.Qtd_Sala);				
					printf("Sala<s> de estar: %i\n", Info.Qtd_Sala_de_Estar);
					printf("Cozinha<s>: %i\n", Info.Qtd_Cozinha);
					printf("Banheiro<s>: %i\n", Info.Qtd_Banheiro);
					ColocarEspaco(Info.infraestrutura);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
					ColocarEspaco(Info.endereco);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
					ColocarEspaco(Info.Area_de_Lazer);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
					printf("Infraestrutura: %s\n", Info.infraestrutura);
					printf("Endere�o: %s\n", Info.endereco);
					printf("Area de Lazer: %s\n", Info.Area_de_Lazer);
					printf("�rea do Terreno: %0.2f\n", Info.Area_do_terreno);
					printf("�rea Constru�da Total: %0.2f\n", Info.Area_construida_total);
					printf("Valor do Apartamento: %0.2f\n", Info.valor_do_imovel);
					printf("N� de telefone: %s\n\n", Info.n_telefone);
					
				}	
				fclose(Ponteiro);//fecha (---.txt);
				printf("Listagem conclu�da!\n\n");//coloque em tela ("---------");
				break;//saia do switch
		
			case 2://se op = 2
				printf("\nCasas Vendidas\n\n");	//exibe a op��o que o usu�rio digitou
				Ponteiro = fopen("CasaVendidos.txt", "r");//vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
				
				
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info3.numero_do_cracha, &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);
					// L� as informa��es contidas no arquivo
					
					if (Info3.numero_do_cracha == NULL)//se Info3.numero_do_cracha for igual a um valor NULO significa que n�o h� registros, logo:
					{
					printf("N�o h� registros! \n\n");//exibe uma mensagem informando o usu�rio
					return 0;//e sai da fun��o
						
					}//se Info3.numero_do_cracha tiver um valor, a compara��o ocorre, e nada acontece
					
					//EXIBE AS INFORMA��ES CADASTRADAS
					printf("ID: %i\n", Info.ID);
					printf("Crach� do Vendedor: %i\n", Info3.numero_do_cracha);
					printf("Dormit�rio<s>: %i\n", Info.Qtd_Dormitorio);
					printf("Su�te<s>: %i\n", Info.Qtd_Suite);
					printf("Sala<s>: %i\n", Info.Qtd_Sala);
					printf("Sala<s> de estar: %i\n", Info.Qtd_Sala_de_Estar);
					printf("Cozinha<s>: %i\n", Info.Qtd_Cozinha);
					printf("Banheiro<s>: %i\n", Info.Qtd_Banheiro);
					ColocarEspaco(Info.infraestrutura);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
					ColocarEspaco(Info.endereco);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
					ColocarEspaco(Info.Area_de_Lazer);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
					printf("Infraestrutura: %s\n", Info.infraestrutura);
					printf("Endere�o: %s\n", Info.endereco);
					printf("Area de Lazer: %s\n", Info.Area_de_Lazer);
					printf("�rea do Terreno: %0.2f\n", Info.Area_do_terreno);
					printf("�rea Constru�da Total: %0.2f\n", Info.Area_construida_total);
					printf("Valor do Apartamento: %0.2f\n", Info.valor_do_imovel);
					printf("N� de telefone: %s\n\n", Info.n_telefone);
					
				}	
				fclose(Ponteiro);//fecha (---.txt)
				printf("Listagem conclu�da!\n\n");//coloque em tela ("---------");
				break;//saia do switch
		
			case 3://se op = 3
				printf("\nCh�caras Vendidas\n\n");	//exibe a op��o que o usu�rio digitou
				Ponteiro = fopen("ChacarasVendidos.txt", "r");//vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
				
				
			
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info3.numero_do_cracha, &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);
					// L� as informa��es contidas no arquivo
					
					if (Info3.numero_do_cracha == NULL)//se Info3.numero_do_cracha for igual a um valor NULO significa que n�o h� registros, logo:
					{
					printf("N�o h� registros! \n\n");//exibe uma mensagem informando o usu�rio
					return 0;//e sai da fun��o
						
					}//se Info3.numero_do_cracha tiver um valor, a compara��o ocorre, e nada acontece
					
					
					//EXIBE AS INFORMA��ES CADASTRADAS
					printf("ID: %i\n", Info.ID);
					printf("Crach� do Vendedor: %i\n", Info3.numero_do_cracha);
					printf("Dormit�rio<s>: %i\n", Info.Qtd_Dormitorio);
					printf("Su�te<s>: %i\n", Info.Qtd_Suite);
					printf("Sala<s>: %i\n", Info.Qtd_Sala);
					printf("Sala<s> de estar: %i\n", Info.Qtd_Sala_de_Estar);
					printf("Cozinha<s>: %i\n", Info.Qtd_Cozinha);
					printf("Banheiro<s>: %i\n", Info.Qtd_Banheiro);
					ColocarEspaco(Info.infraestrutura);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
					ColocarEspaco(Info.endereco);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
					ColocarEspaco(Info.Area_de_Lazer);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
					printf("Infraestrutura: %s\n", Info.infraestrutura);
					printf("Endere�o: %s\n", Info.endereco);
					printf("Area de Lazer: %s\n", Info.Area_de_Lazer);
					printf("�rea do Terreno: %0.2f\n", Info.Area_do_terreno);
					printf("�rea Constru�da Total: %0.2f\n", Info.Area_construida_total);
					printf("Valor do Apartamento: %0.2f\n", Info.valor_do_imovel);
					printf("N� de telefone: %s\n\n", Info.n_telefone);
					
				}	
				fclose(Ponteiro);//fecha (---.txt)	
				printf("Listagem conclu�da!\n\n");//coloque em tela ("---------");
				break;//saia do switch

			
			case 4://se op = 4
				printf("\nTerrenos Vendidos\n\n");	//exibe a op��o que o usu�rio digitou
				Ponteiro = fopen("TerrenosVendidos.txt", "r");//vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
				
				
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %f %f %s %s\n", &Info3.numero_do_cracha, &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);	
					// L� as informa��es contidas no arquivo
					if (Info3.numero_do_cracha == NULL)//se Info3.numero_do_cracha for igual a um valor NULO significa que n�o h� registros, logo:
					{
						printf("N�o h� registros! \n\n");//exibe uma mensagem informando o usu�rio
						return 0;//e sai da fun��o
					}//se Info3.numero_do_cracha tiver um valor, a compara��o ocorre, e nada acontece
					
					//EXIBE AS INFORMA��ES CADASTRADAS
					printf("ID: %i\n", Info.ID);
					printf("Crach� do Vendedor: %i\n", Info3.numero_do_cracha);
					printf("Valor do Apartamento: %0.2f\n", Info.valor_do_imovel);
					printf("Area do Terreno: %0.2f\n", Info.valor_do_imovel);
					ColocarEspaco(Info.endereco);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
					printf("Endere�o: %s\n", Info.endereco);
					printf("N� de telefone: %s\n\n", Info.n_telefone);
				}	
				fclose(Ponteiro);//fecha (---.txt)
				printf("Listagem conclu�da!\n\n");//coloque em tela ("---------");
				break;//saia do switch
			
			default: //se nenhum dos case corresponder
				break; // sai do programa
		}//fim switch vendidos			  	 	 
	}//fim switch principal		
}//fim fun��o


void Imovel()//cria uma fun��o do tipo vazio de nome Imovel()
{
	int op, id; //cria vari�veis do tipo inteiro de nomes ...;
	Ficha_Tecnica_Imovel Info, Info2; //cria vari�veis do tipo Ficha_Tecnica_Imovel de nomes ...;
	
	puts("<1> ::: Cadastrar p. venda");
	puts("<2> ::: Cadastrar p. loca��o");
	puts("<3+> ::: Sair"); printf("Opera��o: "); scanf("%i", &op); puts("\n");
	system("cls");
	//exibe um menu questionando que tarefa o usu�rio deseja executar
	//Cadastrar p. Venda
	//Cadastras p. Loca��o
	//l� valor e armazena na vairi�vel op
	//pula 2 linhas
	//limpa a tela
	
	switch (op)//compare (op)
	{
		case 1://se op = 1
			
		printf("::: Cadastro p. Venda :::\n\n"); 
		printf("Informe o tipo de im�vel para venda: \n\n");
		puts("<1> ::: Apartamento");
		puts("<2> ::: Casa");
		puts("<3> ::: Ch�cara");
		puts("<4> ::: Terreno");
		puts("<5+> ::: Sair");
		printf("Opera��o: "); scanf("%i", &op); puts("");
		system("cls");
		//exibe um menu questionando que atividade o usu�rio deseja executar
		//l� valor e armazena na vari�vel op
		//limpa a tela
		switch (op)
		{
			case 1: //se op = 1
				printf("::: Apartamento p. venda :::\n\n"); //mostra a op��o escolhida pelo us�rio
				printf("Informe o ID: ");
				scanf("%i", &id);
				puts("");
				//pede que o usu�rio informe o ID que ir� identificar o im�vel respectivo
				//l� e armazena na vari�vel id
				//pula 2 linhas
				
				p://Ponto usado em conjunto ao comando goto, usado posteriormente
				Ponteiro = fopen("Apartamentos.txt","r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
				
				while(!feof(Ponteiro)) //enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// L� as informa��es contidas no arquivo
					if (Info.ID == NULL) //se Info.ID for igual a um valor Nulo, significa que n�o h� informa��es no arquivo logo:
					{
						Info.ID == id; //Info.ID � igual ao valor de id
					}//fim da compara��o
					
					if (id != Info.ID)//se id for diferente de Info.ID (Se o id registrado for diferente dos ID's lidos no arquivo)
					{
						Info.ID = id;//Info.ID � igual ao valor de id
					
					}
					else//se n�o
					{
						while(id == Info.ID) //enquanto (id == Info.ID)
						{
							printf("ID j� utilizado. Informar novo ID: "); 
							scanf("%i", &id);	
							puts("");
							//pede ao usu�rio que digite um valor
							//l� o valor e armazena na vari�vel id
							//pula 1 linha
						}//volta no loop e verifica a condi��o
						
						Info.ID = id;//Info.ID � igual ao valor de id
						fclose(Ponteiro);//feche (---.txt);
						goto p;//v� para o ponto p;
					}
				}
				fclose(Ponteiro);//feche(---.txt);
				
				//Adquire todas as informa��es do im�vel
				printf("Informe o Andar: ");
				scanf("%i", &Info.andar);
				printf("Informe a Quantidade de Dormit�rios: ");
				scanf("%i", &Info.Qtd_Dormitorio);
				printf("Informe a Quantidade de Su�tes: ");
				scanf("%i", &Info.Qtd_Suite);
				printf("Informe a Quantidade de Salas: ");
				scanf("%i", &Info.Qtd_Sala);
				printf("Informe a Quantidade de Salas de Estar: ");
				scanf("%i", &Info.Qtd_Sala_de_Estar);
				printf("Informe a Quantidade de Cozinhas: ");
				scanf("%i", &Info.Qtd_Cozinha);
				printf("Informe a Quantidade de Banheiros: ");
				scanf("%i", &Info.Qtd_Banheiro);
				getchar();
				printf("Descreva brevemente a infraestrutura do local: ");
				gets(Info.infraestrutura);
				TirarEspaco(Info.infraestrutura);//Chama fun��o para tirar espa�o da vari�vel ---;
				printf("Informe o Endere�o: ");
				gets(Info.endereco);
				TirarEspaco(Info.endereco);
				printf("Possui �rea de lazer? Sim ou N�o: ");
				gets(Info.Area_de_Lazer);
				TirarEspaco(Info.Area_de_Lazer);
				printf("Informe a �rea do terreno: ");
				scanf("%f", &Info.Area_do_terreno);
				printf("Informe a �rea constru�da total: ");
				scanf("%f", &Info.Area_construida_total);
				printf("Informe o valor do im�vel: ");
				scanf("%f",&Info.valor_do_imovel);	
				getchar();
				printf("N�mero de telefone: ");
				gets(Info.n_telefone);
				TirarEspaco(Info.n_telefone);
				
				Ponteiro = fopen("Apartamentos.txt","a+");// vari�vel Ponteiro � igual a Abra("---.txt", "modo escrita");
				fprintf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone, Info.n_telefone);
				//insere no arquivo todas as informa��es adquiridas
				fclose(Ponteiro);//feche (---.txt);
				
				printf("Registrado!\n\n");//coloque na tela ("---");
				goto fim;//v� para o ponto fim.
			
			case 2://se op = 2
				printf("::: Casa p. venda :::\n\n");//mostra a op��o escolhida pelo us�rio
				
				
				printf("Informe o ID: ");
				scanf("%i", &id);
				puts("");
				//pede que o usu�rio informe o ID que ir� identificar o im�vel respectivo
				//l� e armazena na vari�vel id
				//pula 2 linhas
				
				p2://Ponto usado em conjunto ao comando goto, usado posteriormente
				
				Ponteiro = fopen("Casa.txt", "r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info2.ID, &Info2.Qtd_Dormitorio, &Info2.Qtd_Suite, &Info2.Qtd_Sala, &Info2.Qtd_Sala_de_Estar, &Info2.Qtd_Cozinha, &Info2.Qtd_Banheiro, Info2.infraestrutura, Info2.endereco, Info2.Area_de_Lazer, &Info2.Area_do_terreno, &Info2.Area_construida_total, &Info2.valor_do_imovel, Info.n_telefone);	
					// L� as informa��es contidas no arquivo
					if(Info2.ID == NULL)//se Info.ID for igual a um valor Nulo, significa que n�o h� informa��es no arquivo logo:
					{
						Info.ID = id;//Info2.ID � igual ao valor de id
					}//fim da compara��o
					
					if (id != Info2.ID)//se id for diferente de Info2.ID (Se o id registrado for diferente dos ID's lidos no arquivo)
					{
						Info.ID = id;//Info.ID � igual ao valor de id
					}
					else//se n�o
					{
						while(id == Info2.ID)//enquanto (id == Info2.ID)
						{
							printf("ID j� utilizado. Informar novo ID: ");
							scanf("%i", &id);
							puts("");
							//pede ao usu�rio que digite um valor
							//l� o valor e armazena na vari�vel id
							//pula 1 linha
						}//volta no loop e verifica a condi��o
						Info.ID = id;//Info.ID � igual ao valor de id
						fclose(Ponteiro);//feche (---.txt);
						goto p2;//v� para o ponto p;
					}
				}
				fclose(Ponteiro);//feche(---.txt);
				
				
				//Adquire todas as informa��es do im�vel
				printf("Informe a Quantidade de Dormit�rios: ");
				scanf("%i", &Info.Qtd_Dormitorio);
				printf("Informe a Quantidade de Su�tes: ");
				scanf("%i", &Info.Qtd_Suite);
				printf("Informe a Quantidade de Salas: ");
				scanf("%i", &Info.Qtd_Sala);
				printf("Informe a Quantidade de Salas de Estar: ");
				scanf("%i", &Info.Qtd_Sala_de_Estar);
				printf("Informe a Quantidade de Cozinhas: ");
				scanf("%i", &Info.Qtd_Cozinha);
				printf("Informe a Quantidade de Banheiros: ");
				scanf("%i", &Info.Qtd_Banheiro);
				getchar();
				printf("Descreva brevemente a infraestrutura do local: ");
				gets(Info.infraestrutura);
				TirarEspaco(Info.infraestrutura);//Chama fun��o para tirar espa�o da vari�vel ---;
				printf("Informe o Endere�o: ");
				gets(Info.endereco);
				TirarEspaco(Info.endereco);//Chama fun��o para tirar espa�o da vari�vel ---;
				printf("Possui �rea de lazer? Sim ou N�o: ");
				gets(Info.Area_de_Lazer);
				printf("Informe a �rea do terreno: ");
				scanf("%f", &Info.Area_do_terreno);
				printf("Informe a �rea constru�da total: ");
				scanf("%f", &Info.Area_construida_total);
				printf("Informe o valor do im�vel: ");
				scanf("%f", &Info.valor_do_imovel);	
				getchar();
				printf("N�mero de telefone: ");
				gets(Info.n_telefone);
				TirarEspaco(Info.n_telefone);//Chama fun��o para tirar espa�o da vari�vel ---;
					
		
				Ponteiro = fopen("Casa.txt","a+");// vari�vel Ponteiro � igual a Abra("---.txt", "modo escrita");
				fprintf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
				//insere no arquivo todas as informa��es adquiridas no arquivo
				fclose(Ponteiro);//feche (---.txt);
				
				printf("Registrado!\n\n");//coloque na tela ("---");
				goto fim;//v� para o ponto fim.
			
			
			case 3://se op = 3
				printf("::: Ch�caras p. venda :::\n\n");//mostra a op��o escolhida pelo us�rio
				
				printf("Informe o ID: ");
				scanf("%i", &id);
				puts("");
				//pede que o usu�rio informe o ID que ir� identificar o im�vel respectivo
				//l� e armazena na vari�vel id
				//pula 2 linhas				
				
				p3://Ponto usado em conjunto ao comando goto, usado posteriormente
				Ponteiro = fopen("Chacaras.txt", "r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// L� as informa��es contidas no arquivo
					if(Info.ID == NULL)//se Info.ID for igual a um valor Nulo, significa que n�o h� informa��es no arquivo logo:
					{
						Info.ID = id;//Info.ID � igual ao valor de id
					}//fim da compara��o
					
					if (id != Info.ID)//se Info.ID for igual a um valor Nulo, significa que n�o h� informa��es no arquivo logo:
					{
						Info.ID = id;//Info.ID � igual ao valor de id
					}
					else//se n�o
					{
						while(id == Info.ID)//enquanto (id == Info.ID)
						{
							printf("ID j� utilizado. Informar novo ID: ");
							scanf("%i", &id);
							puts("");
							//pede ao usu�rio que digite um valor
							//l� o valor e armazena na vari�vel id
							//pula 1 linha						
						}//volta no loop e verifica a condi��o
						Info.ID = id;//Info.ID � igual ao valor de id
						fclose(Ponteiro);//feche (---.txt);
						goto p3;//v� para o ponto p;
					}
				}
				fclose(Ponteiro);//feche(---.txt);
				
				//Adquire todas as informa��es do im�vel
				printf("Informe a Quantidade de Dormit�rios: ");
				scanf("%i", &Info.Qtd_Dormitorio);
				printf("Informe a Quantidade de Su�tes: ");
				scanf("%i", &Info.Qtd_Suite);
				printf("Informe a Quantidade de Salas: ");
				scanf("%i", &Info.Qtd_Sala);
				printf("Informe a Quantidade de Salas de Estar: ");
				scanf("%i", &Info.Qtd_Sala_de_Estar);
				printf("Informe a Quantidade de Cozinhas: ");
				scanf("%i", &Info.Qtd_Cozinha);
				printf("Informe a Quantidade de Banheiros: ");
				scanf("%i", &Info.Qtd_Banheiro);
				getchar();
				printf("Descreva brevemente a infraestrutura do local: ");
				gets(Info.infraestrutura);
				TirarEspaco(Info.infraestrutura);//Chama fun��o para tirar espa�o da vari�vel ---;
				printf("Informe o Endere�o: ");
				gets(Info.endereco);
				TirarEspaco(Info.endereco);//Chama fun��o para tirar espa�o da vari�vel ---;
				printf("Possui �rea de lazer? Sim ou N�o: ");
				gets(Info.Area_de_Lazer);
				printf("Informe a �rea do terreno: ");
				scanf("%f", &Info.Area_do_terreno);
				printf("Informe a �rea constru�da total: ");
				scanf("%f", &Info.Area_construida_total);
				printf("Informe o valor do im�vel: ");
				scanf("%f",&Info.valor_do_imovel);		
				getchar();
				printf("N�mero de telefone: ");
				gets(Info.n_telefone);
				TirarEspaco(Info.n_telefone);//Chama fun��o para tirar espa�o da vari�vel ---;

				Ponteiro = fopen("Chacaras.txt","a+");// vari�vel Ponteiro � igual a Abra("---.txt", "modo escrita");
				fprintf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
				//insere no arquivo todas as informa��es adquiridas no arquivo
				fclose(Ponteiro);//feche (---.txt);
				
				printf("Registrado!\n\n");//coloque na tela ("---");
				return 0;//v� para o ponto fim.
				
			case 4://se op = 4
				printf("::: Terrenos p. Venda :::\n\n");//mostra a op��o escolhida pelo us�rio
				
				printf("Informe o ID: ");
				scanf("%i", &id);
				puts("");
				//pede que o usu�rio informe o ID que ir� identificar o im�vel respectivo
				//l� e armazena na vari�vel id
				//pula 2 linhas
				
				p4://Ponto usado em conjunto ao comando goto, usado posteriormente
				Ponteiro = fopen("Terrenos.txt", "r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");

				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);	
					// L� as informa��es contidas no arquivo
				
					if(Info.ID == NULL)//se Info.ID for igual a um valor Nulo, significa que n�o h� informa��es no arquivo logo:
					{
						Info.ID = id;//Info.ID � igual ao valor de id
					}//fim da compara��o					
					
					if (id != Info.ID)//se id for diferente de Info.ID (Se o id registrado for diferente dos ID's lidos no arquivo)
					{
						Info.ID = id;//Info.ID � igual ao valor de id
					}
					else//se n�o
					{
						while(id == Info.ID)//enquanto (id == Info.ID)
						{
							printf("ID j� utilizado. Informar novo ID: ");
							scanf("%i", &id);
							puts("");
						//pede ao usu�rio que digite um valor
						//l� o valor e armazena na vari�vel id
						//pula 1 linha
						}//volta no loop e verifica a condi��o
						Info.ID = id;//Info.ID � igual ao valor de id
						fclose(Ponteiro);//feche (---.txt);
						goto p4;//v� para o ponto p;
					}
				}
				fclose(Ponteiro);//feche(---.txt);
				
				//Adquire todas as informa��es do im�vel
				printf("Informe a �rea do terreno: ");
				scanf("%f", &Info.Area_do_terreno);
				printf("Informe o valor do im�vel: ");
				scanf("%f",&Info.valor_do_imovel);
				getchar();
				printf("Informe o endere�o: ");
				gets(Info.endereco);
				TirarEspaco(Info.endereco);//Chama fun��o para tirar espa�o da vari�vel ---;
				printf("N�mero de telefone: ");
				gets(Info.n_telefone);
				TirarEspaco(Info.n_telefone);//Chama fun��o para tirar espa�o da vari�vel ---;

				
				Ponteiro = fopen("Terrenos.txt", "a+");// vari�vel Ponteiro � igual a Abra("---.txt", "modo escrita");
				fprintf(Ponteiro, "%i %f %f %s %s\n", Info.ID, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);
				//insere no arquivo todas as informa��es adquiridas no arquivo
				fclose(Ponteiro);//feche (---.txt);
				printf("Registrado!\n\n");//coloque na tela ("---");
				goto fim;//v� para o ponto fim
			
			default:
					 break;
					 return 0;
		}//Fim do switch de venda
	
		case 2: //Loca��o de Im�veis
			printf("::: Cadastro p. Loca��o :::\n\n");
			printf("Informe o tipo de im�vel para loca��o: \n\n");
			puts("<1> ::: Apartamento");
			puts("<2> ::: Casa");
			puts("<3> ::: Ch�cara");
			puts("<4> ::: Terreno");
			puts("<5+> ::: Sair");
			printf("Opera��o: "); scanf("%i", &op); puts("");
			system("cls");
			//exibe um menu questionando que atividade o usu�rio deseja executar
			//l� valor e armazena na vari�vel op
			//limpa a tela	
					
			switch (op)//compare (op)
			{
				case 1: //se op = 1
					
					printf("::: Apartamentos p. alugar :::\n\n");//mostra a op��o escolhida pelo us�rio
					printf("Informe o ID: ");
					scanf("%i", &id);
					puts("");
					//pede que o usu�rio informe o ID que ir� identificar o im�vel respectivo
					//l� e armazena na vari�vel id
					//pula 2 linhas					
					
					p5://Ponto usado em conjunto ao comando goto, usado posteriormente
					Ponteiro = fopen("AlugarApartamentos.txt","r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
					
					while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
					{
						fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info2.ID, &Info2.andar, &Info2.Qtd_Dormitorio, &Info2.Qtd_Suite, &Info2.Qtd_Sala, &Info2.Qtd_Sala_de_Estar, &Info2.Qtd_Cozinha, &Info2.Qtd_Banheiro, Info2.infraestrutura, Info2.endereco, Info2.Area_de_Lazer, &Info2.Area_do_terreno, &Info2.Area_construida_total, &Info2.valor_do_imovel, Info.n_telefone);	
						// L� as informa��es contidas no arquivo
						
						if (Info2.ID == NULL) //se Info.ID for igual a um valor Nulo, significa que n�o h� informa��es no arquivo logo:
						{
							Info.ID == id; //Info.ID � igual ao valor de id
						}//fim da compara��o						
						
						if (id != Info2.ID)	//se id for diferente de Info.ID (Se o id registrado for diferente dos ID's lidos no arquivo)
						{
							Info.ID = id;//Info.ID � igual ao valor de id
						
						}
						else//se n�o
						{
							while(id == Info2.ID)//enquanto (id == Info.ID)
							{
								printf("ID j� utilizado. Informar novo ID: ");
								scanf("%i", &id);
								puts("");
								//pede ao usu�rio que digite um valor
								//l� o valor e armazena na vari�vel id
								//pula 1 linha
							}//volta no loop e verifica a condi��o
							Info.ID = id;//Info.ID � igual ao valor de id
							fclose(Ponteiro);//feche (---.txt);
							goto p5;//v� para o ponto p;
						}
					}
					fclose(Ponteiro);//feche(---.txt);
					
					//Adquire todas as informa��es do im�vel
					printf("Informe o Andar: ");
					scanf("%i", &Info.andar);
					printf("Informe a Quantidade de Dormit�rios: ");
					scanf("%i", &Info.Qtd_Dormitorio);
					printf("Informe a Quantidade de Su�tes: ");
					scanf("%i", &Info.Qtd_Suite);
					printf("Informe a Quantidade de Salas: ");
					scanf("%i", &Info.Qtd_Sala);
					printf("Informe a Quantidade de Salas de Estar: ");
					scanf("%i", &Info.Qtd_Sala_de_Estar);
					printf("Informe a Quantidade de Cozinhas: ");
					scanf("%i", &Info.Qtd_Cozinha);
					printf("Informe a Quantidade de Banheiros: ");
					scanf("%i", &Info.Qtd_Banheiro);
					getchar();
					printf("Descreva brevemente a infraestrutura do local: ");
					gets(Info.infraestrutura);
					TirarEspaco(Info.infraestrutura);//Chama fun��o para tirar espa�o da vari�vel ---;
					printf("Informe o Endere�o: ");
					gets(Info.endereco);
					TirarEspaco(Info.endereco);//Chama fun��o para tirar espa�o da vari�vel ---;
					printf("Possui �rea de lazer? Sim ou N�o: ");
					gets(Info.Area_de_Lazer);
					TirarEspaco(Info.Area_de_Lazer);//Chama fun��o para tirar espa�o da vari�vel ---;
					printf("Informe a �rea do terreno: ");
					scanf("%f", &Info.Area_do_terreno);
					printf("Informe a �rea constru�da total: ");
					scanf("%f", &Info.Area_construida_total);
					printf("Informe o valor do Aluguel: ");
					scanf("%f",&Info.valor_do_imovel);
					getchar();		
					printf("N�mero de telefone: ");
					gets(Info.n_telefone);
					TirarEspaco(Info.n_telefone);//Chama fun��o para tirar espa�o da vari�vel ---;
				
					Ponteiro = fopen("AlugarApartamentos.txt","a+");// vari�vel Ponteiro � igual a Abra("---.txt", "modo escrita");
					fprintf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
					//insere no arquivo todas as informa��es adquiridas no arquivo
					fclose(Ponteiro);//feche (---.txt);
					
					printf("Registrado!\n\n");//coloque na tela ("---");
				
					break;//v� para o fim.
					
				case 2://se op = 2
					printf("::: Casas p. alugar :::\n\n");//mostra a op��o escolhida pelo us�rio
					printf("Informe o ID: ");
					scanf("%i", &id);
					puts("");
					//pede que o usu�rio informe o ID que ir� identificar o im�vel respectivo
					//l� e armazena na vari�vel id
					//pula 1 linha
					
					p6://Ponto usado em conjunto ao comando goto, usado posteriormente
					Ponteiro = fopen("AlugarCasa.txt","r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
					while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
					{
						fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info2.ID, &Info2.Qtd_Dormitorio, &Info2.Qtd_Suite, &Info2.Qtd_Sala, &Info2.Qtd_Sala_de_Estar, &Info2.Qtd_Cozinha, &Info2.Qtd_Banheiro, Info2.infraestrutura, Info2.endereco, Info2.Area_de_Lazer, &Info2.Area_do_terreno, &Info2.Area_construida_total, &Info2.valor_do_imovel, Info.n_telefone);	
						// L� as informa��es contidas no arquivo
						
						if (id != Info2.ID)//se id for diferente de Info.ID (Se o id registrado for diferente dos ID's lidos no arquivo)
						{
							Info.ID = id;//Info.ID � igual ao valor de id
							
						}
						else//se n�o
						{
							while(id == Info.ID)//enquanto (id == Info.ID)
							{
								printf("ID j� utilizado. Informar novo ID: ");
								scanf("%i", &id); 
								puts("");
								//pede ao usu�rio que digite um valor
								//l� o valor e armazena na vari�vel id
								//pula 1 linha
							}//volta no loop e verifica a condi��o
							Info.ID = id;//Info.ID � igual ao valor de id
							fclose(Ponteiro);//feche (---.txt);
							goto p6;//v� para o ponto p;
						}
					}
								
					fclose(Ponteiro);//feche(---.txt);
					
					//Adquire todas as informa��es do im�vel
					printf("Informe a Quantidade de Dormit�rios: ");
					scanf("%i", &Info.Qtd_Dormitorio);
					printf("Informe a Quantidade de Su�tes: ");
					scanf("%i", &Info.Qtd_Suite);
					printf("Informe a Quantidade de Salas: ");
					scanf("%i", &Info.Qtd_Sala);
					printf("Informe a Quantidade de Salas de Estar: ");
					scanf("%i", &Info.Qtd_Sala_de_Estar);
					printf("Informe a Quantidade de Cozinhas: ");
					scanf("%i", &Info.Qtd_Cozinha);
					printf("Informe a Quantidade de Banheiros: ");
					scanf("%i", &Info.Qtd_Banheiro);
					getchar();
					printf("Descreva brevemente a infraestrutura do local: ");
					gets(Info.infraestrutura);
					TirarEspaco(Info.infraestrutura);//Chama fun��o para tirar espa�o da vari�vel ---;
					printf("Informe o Endere�o: ");
					gets(Info.endereco);
					TirarEspaco(Info.endereco);//Chama fun��o para tirar espa�o da vari�vel ---;
					printf("Possui �rea de lazer? Sim ou N�o: ");
					gets(Info.Area_de_Lazer);
					printf("Informe a �rea do terreno: ");
					scanf("%f", &Info.Area_do_terreno);
					printf("Informe a �rea constru�da total: ");
					scanf("%f", &Info.Area_construida_total);
					printf("Informe o valor do aluguel: ");
					scanf("%f",&Info.valor_do_imovel);	
					getchar();	
					printf("N�mero de telefone: ");
					gets(Info.n_telefone);
					TirarEspaco(Info.n_telefone);//Chama fun��o para tirar espa�o da vari�vel ---;
	
			
					Ponteiro = fopen("AlugarCasa.txt","w");// vari�vel Ponteiro � igual a Abra("---.txt", "modo escrita");
					fprintf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
					//insere no arquivo todas as informa��es adquiridas no arquivo
					fclose(Ponteiro);//feche (---.txt);
					
					printf("Registrado!\n\n");//coloque na tela ("---");
					goto fim;//v� para o ponto fim.
					break;//v� para o ponto fim.
				
				
				case 3://se op = 3
					printf("::: Ch�caras p. alugar :::\n\n");//mostra a op��o escolhida pelo us�rio

					
					printf("Informe o ID: ");
					scanf("%i", &id);
					puts("");
					//pede que o usu�rio informe o ID que ir� identificar o im�vel respectivo
					//l� e armazena na vari�vel id
					//pula 2 linhas
					
					p7://Ponto usado em conjunto ao comando goto, usado posteriormente
					Ponteiro = fopen("AlugarChacaras.txt", "r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
					
					while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
					{
						fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info2.ID, &Info2.Qtd_Dormitorio, &Info2.Qtd_Suite, &Info2.Qtd_Sala, &Info2.Qtd_Sala_de_Estar, &Info2.Qtd_Cozinha, &Info2.Qtd_Banheiro, Info2.infraestrutura, Info2.endereco, Info2.Area_de_Lazer, &Info2.Area_do_terreno, &Info2.Area_construida_total, &Info2.valor_do_imovel, Info.n_telefone);	
						// L� as informa��es contidas no arquivo
						if (Info2.ID == NULL) //se Info.ID for igual a um valor Nulo, significa que n�o h� informa��es no arquivo logo:
						{
							Info.ID == id; //Info.ID � igual ao valor de id
						}//fim da compara��o
						
						if (id != Info2.ID)//se id for diferente de Info.ID (Se o id registrado for diferente dos ID's lidos no arquivo)
						{
							Info.ID = id;//Info.ID � igual ao valor de id
							
						}
						else//se n�o
						{
							while(id == Info2.ID)//enquanto (id == Info.ID)
							{
								printf("ID j� utilizado. Informar novo ID: ");
								scanf("%i", &id);
								puts("");
								//pede ao usu�rio que digite um valor
								//l� o valor e armazena na vari�vel id
								//pula 1 linha								
							}//volta no loop e verifica a condi��o
							Info.ID = id;//Info.ID � igual ao valor de id
							fclose(Ponteiro);//feche (---.txt);
							goto p7;//v� para o ponto p;
						}
					}
					fclose(Ponteiro);//feche(---.txt);
					
					//Adquire todas as informa��es do im�vel
					printf("Informe a Quantidade de Dormit�rios: ");
					scanf("%i", &Info.Qtd_Dormitorio);
					printf("Informe a Quantidade de Su�tes: ");
					scanf("%i", &Info.Qtd_Suite);
					printf("Informe a Quantidade de Salas: ");
					scanf("%i", &Info.Qtd_Sala);
					printf("Informe a Quantidade de Salas de Estar: ");
					scanf("%i", &Info.Qtd_Sala_de_Estar);
					printf("Informe a Quantidade de Cozinhas: ");
					scanf("%i", &Info.Qtd_Cozinha);
					printf("Informe a Quantidade de Banheiros: ");
					scanf("%i", &Info.Qtd_Banheiro);
					getchar();
					printf("Descreva brevemente a infraestrutura do local: ");
					gets(Info.infraestrutura);
					TirarEspaco(Info.infraestrutura);//Chama fun��o para tirar espa�o da vari�vel ---;
					printf("Informe o Endere�o: ");
					gets(Info.endereco);
					TirarEspaco(Info.endereco);//Chama fun��o para tirar espa�o da vari�vel ---;
					printf("Possui �rea de lazer? Sim ou N�o: ");
					gets(Info.Area_de_Lazer);
					printf("Informe a �rea do terreno: ");
					scanf("%f", &Info.Area_do_terreno);
					printf("Informe a �rea constru�da total: ");
					scanf("%f", &Info.Area_construida_total);
					printf("Informe o valor do aluguel: ");
					scanf("%f",&Info.valor_do_imovel);	
					getchar();	
					printf("N�mero de telefone: ");
					gets(Info.n_telefone);
					TirarEspaco(Info.n_telefone);//Chama fun��o para tirar espa�o da vari�vel ---;
	
					
					Ponteiro = fopen("AlugarChacaras.txt","a+");// vari�vel Ponteiro � igual a Abra("---.txt", "modo escrita");
					fprintf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
					//insere no arquivo todas as informa��es adquiridas no arquivo
					fclose(Ponteiro);//feche (---.txt);
					
					printf("Registrado!\n\n");//coloque na tela ("---");
					break;//coloque na tela ("---");
					
				case 4://se op = 4
					printf("::: Terrenos p. alugar :::\n\n");
									
					printf("Informe o ID: ");
					scanf("%i", &id);
					puts("");
					//pede que o usu�rio informe o ID que ir� identificar o im�vel respectivo
					//l� e armazena na vari�vel id
					//pula 2 linhas
					
					p8://Ponto usado em conjunto ao comando goto, usado posteriormente
					Ponteiro = fopen("AlugarTerrenos.txt", "r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
					while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
					{
						fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);	
						if (Info.ID == NULL) //se Info.ID for igual a um valor Nulo, significa que n�o h� informa��es no arquivo logo:
						{
							Info.ID == id; //Info.ID � igual ao valor de id
						}//fim da compara��o
						
						if (id != Info.ID)//se id for diferente de Info.ID (Se o id registrado for diferente dos ID's lidos no arquivo)
						{
							Info.ID = id;//Info.ID � igual ao valor de id
						}
						else//se n�o
						{
							while(id == Info.ID)//enquanto (id == Info.ID)
							{
								printf("ID j� utilizado. Informar novo ID: ");
								scanf("%i", &id);
								puts("");
								//pede ao usu�rio que digite um valor
								//l� o valor e armazena na vari�vel id
								//pula 1 linha								
							}//volta no loop e verifica a condi��o
							Info.ID = id;//Info.ID � igual ao valor de id
							fclose(Ponteiro);//feche (---.txt);
							goto p8;//v� para o ponto p;
						}
					}
					fclose(Ponteiro);//feche(---.txt);
	
					//Adquire todas as informa��es do im�vel			
					printf("Informe a �rea do terreno: ");
					scanf("%f", &Info.Area_do_terreno);
					printf("Informe o valor do aluguel: ");
					scanf("%f",&Info.valor_do_imovel);
					getchar();
					printf("Informe o endere�o: ");
					gets(Info.endereco);
					TirarEspaco(Info.endereco);//Chama fun��o para tirar espa�o da vari�vel ---;
					printf("N�mero de telefone: ");
					gets(Info.n_telefone);
					TirarEspaco(Info.n_telefone);//Chama fun��o para tirar espa�o da vari�vel ---;
	
					
					Ponteiro = fopen("AlugarTerrenos.txt", "a+");// vari�vel Ponteiro � igual a Abra("---.txt", "modo escrita");
					fprintf(Ponteiro, "%i %f %f %s %s\n", Info.ID, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);
					//insere no arquivo todas as informa��es adquiridas no arquivo
					fclose(Ponteiro);//feche (---.txt);
					printf("Registrado!\n\n");//coloque na tela ("---");
					break;//v� para o ponto fim.
			}// Fim do switch Loca��o
	}// Fim do switch
	fim://p://Ponto usado em conjunto ao comando goto, usado prevamente
	printf("Opera��o Finalizada!\n\n");//coloque na tela ("---");
	return 0;
  }


void listaraluguel()//cria uma fun��o do tipo vazio de nome Imovel()
{
	int op;//cria uma vari�vel do tipo inteiro de nome op
	Ficha_Tecnica_Imovel Info;//cria uma vari�vel do tipo Ficha_Tecnica_Imovel de nome Info
	Corretor Info2;//cria uma vari�vel de nome Info2 do tipo Corretor
	
	printf("::: Listagem de Cadastro dos Im�veis p. aluguel :::\n\n");
	puts("<1> ::: Apartamento");
	puts("<2> ::: Casa");
	puts("<3> ::: Ch�cara");
	puts("<4> ::: Terreno");
	puts("<5> ::: Im�veis Alugados");
	puts("<6+> ::: Sair");
	printf("Opera��o: "); scanf("%i", &op); puts("");
	system("cls");
	//exibe um menu questionando que im�vel o usu�rio deseja listar
	//l� o valor e insere na vari�vel op
	//quebra linha
	//limpa tela
	

		switch(op)//compare (op)
		{
			case 1://se op = 1
				printf("::: Listar Apartamento<s> :::\n\n");//exibe a op��o que o usu�rio digitou
				Ponteiro = fopen("AlugarApartamentos.txt", "r");//vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
				
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// L� as informa��es contidas no arquivo
					if(Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que n�o h� registros, logo:
					{
						puts("N�o h� registros!\n");//exibe uma mensagem informando o usu�rio
						return 0;//e sai da fun��o
					}//se Info.ID tiver um valor, a compara��o ocorre, e nada acontece
					
					//EXIBE AS INFORMA��ES CADASTRADAS
					printf("ID: %i \n", Info.ID);
					printf("Andar: %i\n", Info.andar);
					printf("Quantidade de Dormit�rio(s): %i \n", Info.Qtd_Dormitorio);
					printf("Quantidade de Su�te(s): %i \n", Info.Qtd_Suite);
					printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
					printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
					printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
					printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
					ColocarEspaco(Info.infraestrutura);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
					printf("Informa��es da Infraestrutura: %s \n", Info.infraestrutura);
					ColocarEspaco(Info.endereco);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
					printf("Endere�o: %s \n", Info.endereco);
					printf("Possui �rea de lazer?: %s\n", Info.Area_de_Lazer);
					printf("�rea total: %.2f\n", Info.Area_do_terreno);
					printf("Terreno total constru�do: %.2f\n", Info.Area_construida_total);
					printf("Valor do Aluguel: %.2f\n", Info.valor_do_imovel);
					printf("N� de telefone: %s\n\n", Info.n_telefone);
				}
				fclose(Ponteiro);//fecha (---.txt)
				printf("Listagem conclu�da!\n\n");//coloque em tela ("---------");
				break;//saia do switch
				
			case 2://se op = 2
				printf("::: Listar Casa<s> :::\n\n");//exibe a op��o que o usu�rio digitou
				Ponteiro = fopen("AlugarCasa.txt", "r");//vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// L� as informa��es contidas no arquivo
					if(Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que n�o h� registros, logo:
					{
						puts("N�o h� registros!\n");//exibe uma mensagem informando o usu�rio
						return 0;//e sai da fun��o
					}//se Info.ID tiver um valor, a compara��o ocorre, e nada acontece
					
					//EXIBE AS INFORMA��ES CADASTRADAS
					printf("ID: %i \n", Info.ID);
					printf("Quantidade de Dormit�rio(s): %i \n", Info.Qtd_Dormitorio);
					printf("Quantidade de Su�te(s): %i \n", Info.Qtd_Suite);
					printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
					printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
					printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
					printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
					ColocarEspaco(Info.infraestrutura);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
					printf("Informa��es da Infraestrutura: %s \n", Info.infraestrutura);
					ColocarEspaco(Info.endereco);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
					printf("Endere�o: %s \n", Info.endereco);
					printf("Possui �rea de lazer?: %s\n", Info.Area_de_Lazer);
					printf("�rea total: %.2f\n", Info.Area_do_terreno);
					printf("Terreno total constru�do: %.2f\n", Info.Area_construida_total);
					printf("Valor do Aluguel: %.2f\n\n", Info.valor_do_imovel);
					printf("N� de telefone: %s", Info.n_telefone);
				}
				fclose(Ponteiro);//fecha (---.txt)
				printf("Listagem conclu�da!\n\n");//coloque em tela ("---------");
				break;//saia do switch
				
			case 3://se op = 3
				printf("::: Listar Ch�cara<s> :::\n\n");//exibe a op��o que o usu�rio digitou
				Ponteiro = fopen("AlugarChacaras.txt", "r");//vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// L� as informa��es contidas no arquivo
					if(Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que n�o h� registros, logo:
					{
						puts("N�o h� registros!\n");//exibe uma mensagem informando o usu�rio
						return 0;//e sai da fun��o
					}
					
					//EXIBE AS INFORMA��ES CADASTRADAS
					printf("ID: %i \n", Info.ID);
					printf("Quantidade de Dormit�rio(s): %i \n", Info.Qtd_Dormitorio);
					printf("Quantidade de Su�te(s): %i \n", Info.Qtd_Suite);
					printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
					printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
					printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
					printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
					ColocarEspaco(Info.infraestrutura);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
					printf("Informa��es da Infraestrutura: %s \n", Info.infraestrutura);
					ColocarEspaco(Info.endereco);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
					printf("Endere�o: %s \n", Info.endereco);
					printf("Possui �rea de lazer?: %s\n", Info.Area_de_Lazer);
					printf("�rea total: %.2f\n", Info.Area_do_terreno);
					printf("Terreno total constru�do: %.2f\n", Info.Area_construida_total);
					printf("Valor do Aluguel: %.2f\n\n", Info.valor_do_imovel);
					printf("N� de telefone: %s", Info.n_telefone);
				}
				fclose(Ponteiro);//fecha (---.txt)
				printf("Listagem conclu�da!\n\n");//coloque em tela ("---------");
				break;//saia do switch
				
			case 4://se op = 4
				printf("::: Listar Terreno<s> :::\n\n");//exibe a op��o que o usu�rio digitou
				Ponteiro = fopen("AlugarTerrenos.txt", "r");//vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);	
					// L� as informa��es contidas no arquivo
					
					if(Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que n�o h� registros, logo:
					{
						puts("N�o h� registros!\n");//exibe uma mensagem informando o usu�rio
						return 0;//e sai da fun��o
					}
					
					//EXIBE AS INFORMA��ES CADASTRADAS
					printf("ID: %i \n", Info.ID);
					printf("�rea total: %0.2f\n", Info.Area_do_terreno);
					printf("Valor do Aluguel: %0.2f\n", Info.valor_do_imovel);
					ColocarEspaco(Info.endereco);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
					printf("Endere�o: %s\n\n", Info.endereco);
					printf("N� de telefone: %s", Info.n_telefone);
				}
				fclose(Ponteiro);//fecha (---.txt)
				printf("Listagem conclu�da!\n\n");//coloque em tela ("---------");
				break;//saia do switch

			case 5: 
				printf("::: Listar Im�vei<s> Alugado<s> :::\n\n");
				puts("<1> ::: Apartamento");
				puts("<2> ::: Casa");
				puts("<3> ::: Ch�cara");
				puts("<4> ::: Terreno");
				puts("<5+> ::: Sair");
				printf("Opera��o: "); scanf("%i", &op); puts("");
				system("cls");
				//exibe um menu questionando que im�vel o usu�rio deseja listar
				//l� o valor e insere na vari�vel op
				//quebra linha
				//limpa tela		
				
						switch (op)//compare (op)
						{
							case 1://se op = 1
								printf("::: Listar Apartamento<s> Alugado<s> :::\n\n");//exibe a op��o que o usu�rio digitou
								Ponteiro = fopen("ApartamentosAlugados.txt", "r");//vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
								
								while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
								{
									
									fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info2.numero_do_cracha, &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);
									// L� as informa��es contidas no arquivo
									if(Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que n�o h� registros, logo:
									{
										puts("N�o h� registros!\n");//exibe uma mensagem informando o usu�rio
										return 0;//e sai da fun��o
									}//se Info.ID tiver um valor, a compara��o ocorre, e nada acontece
									
									//EXIBE AS INFORMA��ES CADASTRADAS			
									printf("ID: %i \n", Info.ID);
									printf("Crach�: %i\n", Info2.numero_do_cracha);
									printf("Andar: %i\n", Info.andar);
									printf("Quantidade de Dormit�rio(s): %i \n", Info.Qtd_Dormitorio);
									printf("Quantidade de Su�te(s): %i \n", Info.Qtd_Suite);
									printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
									printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
									printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
									printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
									ColocarEspaco(Info.infraestrutura);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
									printf("Informa��es da Infraestrutura: %s \n", Info.infraestrutura);
									ColocarEspaco(Info.endereco);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
									printf("Endere�o: %s \n", Info.endereco);
									printf("Possui �rea de lazer?: %s\n", Info.Area_de_Lazer);
									printf("�rea total: %.2f\n", Info.Area_do_terreno);
									printf("Terreno total constru�do: %.2f\n", Info.Area_construida_total);
									printf("Valor do Im�vel: %.2f\n", Info.valor_do_imovel);	
		 			 				printf("N� de telefone: %s\n\n", Info.n_telefone);
								}
								fclose(Ponteiro);//fecha (---.txt)
								printf("Listagem conclu�da!\n\n");//coloque em tela ("---------");
								break;//saia do switch
								
							case 2://se op = 2
								printf("::: Listar Casa<s> Alugada<s> :::\n\n");//exibe a op��o que o usu�rio digitou
								Ponteiro = fopen("CasaAlugados.txt", "r");//vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
								
								while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
								{
									
									fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info2.numero_do_cracha, &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);
									// L� as informa��es contidas no arquivo
									if(Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que n�o h� registros, logo:
									{
										puts("N�o h� registros!\n");//exibe uma mensagem informando o usu�rio
										return 0;//e sai da fun��o
									}//se Info.ID tiver um valor, a compara��o ocorre, e nada acontece
									
									//EXIBE AS INFORMA��ES CADASTRADAS
									printf("ID: %i \n", Info.ID);
									printf("Crach�: %i\n", Info2.numero_do_cracha);
									printf("Quantidade de Dormit�rio(s): %i \n", Info.Qtd_Dormitorio);
									printf("Quantidade de Su�te(s): %i \n", Info.Qtd_Suite);
									printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
									printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
									printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
									printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
									ColocarEspaco(Info.infraestrutura);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
									printf("Informa��es da Infraestrutura: %s \n", Info.infraestrutura);
									ColocarEspaco(Info.endereco);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
									printf("Endere�o: %s \n", Info.endereco);
									printf("Possui �rea de lazer?: %s\n", Info.Area_de_Lazer);
									printf("�rea total: %.2f\n", Info.Area_do_terreno);
									printf("Terreno total constru�do: %.2f\n", Info.Area_construida_total);
									printf("Valor do Im�vel: %.2f\n", Info.valor_do_imovel);	
		 			 				printf("N� de telefone: %s\n\n", Info.n_telefone);
								}
								fclose(Ponteiro);//fecha (---.txt)
								printf("Listagem conclu�da!\n\n");//coloque em tela ("---------");
								break;//saia do switch
								
								
							case 3://se op = 3
								printf("::: Listar Ch�cara<s> Alugada<s> :::\n\n");//exibe a op��o que o usu�rio digitou
								Ponteiro = fopen("ChacaraAlugados.txt", "r");//vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
								
								while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
								{
									
									fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info2.numero_do_cracha, &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);
									// L� as informa��es contidas no arquivo
									if(Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que n�o h� registros, logo:
									{
										puts("N�o h� registros!\n");//exibe uma mensagem informando o usu�rio
										return 0;//e sai da fun��o
									}//se Info.ID tiver um valor, a compara��o ocorre, e nada acontece
									
									//EXIBE AS INFORMA��ES CADASTRADAS
									printf("ID: %i \n", Info.ID);
									printf("Crach�: %i\n", Info2.numero_do_cracha);
									printf("Quantidade de Dormit�rio(s): %i \n", Info.Qtd_Dormitorio);
									printf("Quantidade de Su�te(s): %i \n", Info.Qtd_Suite);
									printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
									printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
									printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
									printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
									ColocarEspaco(Info.infraestrutura);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
									printf("Informa��es da Infraestrutura: %s \n", Info.infraestrutura);
									ColocarEspaco(Info.endereco);//chama a fun��o ColocarEspaco(para colocar espa�o na informa��o contida em ---);
									printf("Endere�o: %s \n", Info.endereco);
									printf("Possui �rea de lazer?: %s\n", Info.Area_de_Lazer);
									printf("�rea total: %.2f\n", Info.Area_do_terreno);
									printf("Terreno total constru�do: %.2f\n", Info.Area_construida_total);
									printf("Valor do Im�vel: %.2f\n", Info.valor_do_imovel);	
		 			 				printf("N� de telefone: %s\n\n", Info.n_telefone);
								}
								fclose(Ponteiro);//fecha (---.txt)
								printf("Listagem conclu�da!\n\n");//coloque em tela ("---------");
								break;//saia do switch
								
							case 4://se op = 4
								printf("::: Listar Terreno<s> Alugado<s> :::\n\n");//exibe a op��o que o usu�rio digitou
								Ponteiro = fopen("TerrenosAlugados.txt", "r");//vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
								
								while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
								{
									fprintf(Ponteiro, "%i %i %f %f %s %s\n", &Info.ID, &Info2.numero_do_cracha, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
									// L� as informa��es contidas no arquivo
									if(Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que n�o h� registros, logo:
									{
										puts("N�o h� registros!\n");//exibe uma mensagem informando o usu�rio
										return 0;//e sai da fun��o
									}//se Info.ID tiver um valor, a compara��o ocorre, e nada acontece
									
									//EXIBE AS INFORMA��ES CADASTRADAS
									printf("ID: %i \n", Info.ID);
									printf("Crach�: %i\n", Info2.numero_do_cracha);
									printf("�rea total: %.2f\n", Info.Area_do_terreno);
									printf("Valor do Im�vel: %.2f\n", Info.valor_do_imovel);	
									printf("Endere�o: %s\n", Info.endereco);
									printf("N� de telefone: %s\n\n", Info.n_telefone);
								}
								fclose(Ponteiro);//fecha (---.txt)
								printf("Listagem conclu�da!\n\n");//coloque em tela ("---------");
								break;//saia do switch
							
							default://caso nenhum dos case corresponda, ele sai do switch e do programa
								break; 	//saia do switch
						}//Listar Im�veis alugados
			default://caso nenhum dos case corresponda, ele sai do switch e do programa
				break;		
		}
}

void corretor()//cria uma fun��o do tipo vazio de nome Imovel()
{
	int i;//cria uma vari�vel do tipo inteiro de nome i
	Corretor Info;//cria uma vari�vel do tipo Corretor de nome Info
	getchar();//pega um caractere digitado e retorna para o sistema
	printf("::: Cadastrar Corretor :::\n\n"); //exibe o t�tulo da fun��o
	printf("Informe o crach�: "); scanf("%i", &i); //pede ao usu�rio que informe um crach� para 
	
	ponto://Ponto usado em conjunto ao comando goto, usado posteriormente
	Ponteiro = fopen("Corretores.txt", "r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
	
		while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
		{
			fscanf(Ponteiro, "%i %s %s %s %i %f %f\n", &Info.numero_do_cracha, Info.nome, Info.data_contratacao, Info.data_nascimento, &Info.idade, &Info.salario_b, &Info.comissao_pvenda);	
			// L� as informa��es contidas no arquivo
			if(Info.numero_do_cracha == NULL)//se Info.numero_do_cracha for igual a um valor Nulo, significa que n�o h� informa��es no arquivo logo:
			{
				Info.numero_do_cracha = i;//Info.numero_do_cracha � igual ao valor de id
			}
			
			if(i != Info.numero_do_cracha)//se i for diferente de Info.numero_do_cracha (Se o cracha informado for diferente dos crach�s registrados)
			{
				Info.numero_do_cracha = i;//Info.numero_do_cracha � igual ao valor de id
			}
			else//se n�o
			{
				while(i == Info.numero_do_cracha)//enquanto (id for igual a Info.numero_do_cracha)
				{
					printf("Crach� j� utilizado, tente novamente: "); scanf("%i", &i); puts("");
					//pede ao usu�rio que digite um valor
					//l� o valor e armazena na vari�vel i
					//pula 1 linha
				}
				Info.numero_do_cracha = i;//Info.ID � igual ao valor de id
				fclose(Ponteiro);//feche (---.txt);
				goto ponto;//v� para o ponto ponto:
			}
		}
	fclose(Ponteiro);//feche (---.txt);
	
	getchar();
	//Adquire todas as informa��es do Corretor
	printf("Nome do Corretor: ");	gets(Info.nome);	TirarEspaco(Info.nome); puts("");//Chama fun��o para tirar espa�o da vari�vel ---; pula uma linha
	printf("Data de contraca��o: ");	gets(Info.data_contratacao); TirarEspaco(Info.data_contratacao); puts("");//Chama fun��o para tirar espa�o da vari�vel ---; pula uma linha
	printf("Data de Nascimento: ");		gets(Info.data_nascimento); TirarEspaco(Info.data_nascimento);puts("");//Chama fun��o para tirar espa�o da vari�vel ---; pula uma linha
	printf("Informe a Idade: ");	scanf("%i",&Info.idade); puts("");
	printf("Sal�rio Bruto: ");		scanf("%f", &Info.salario_b); puts("");
	printf("Comiss�o por venda: ");		scanf("%f", &Info.comissao_pvenda); puts("");
	
	Ponteiro = fopen("Corretores.txt", "a+");// vari�vel Ponteiro � igual a Abra("---.txt", "modo escrita");
	fprintf(Ponteiro, "%i %s %s %s %i %f %f\n", Info.numero_do_cracha, Info.nome, Info.data_contratacao, Info.data_nascimento, Info.idade, Info.salario_b, Info.comissao_pvenda);
	//insere no arquivo todas as informa��es adquiridas no arquivo
	fclose(Ponteiro);//feche (---.txt);	
}//fim da fun��o

void venda_imovel()//cria uma fun��o do tipo vazio de nome venda_imovel()
{
	Ficha_Tecnica_Imovel Info; //cria uma vari�vel do tipo Ficha_Tecnica_Imovel de nome Info
	Corretor Info2, Info3;//cria vari�veis do tipo corretor de nomes ...
	Info3.numero_do_cracha = 0; //define o valor da vari�vel Info3.numero_do_cracha como 0
	FILE* PonteiroNovo; //cria uma vari�vel do tipo FILE de nome PonteiroNovo
	FILE* PonteiroNovo2;//idem acima
	int op, id, cracha, vf = 0;//cria vari�veis do tipo inteiro de nomes ...
	

			printf("::: Vender Im�veis :::\n\n");
			printf("Informe o tipo de im�vel a vender: \n\n");
			puts("<1> :::  Apartamentos");
			puts("<2> :::  Casas");
			puts("<3> :::  Ch�caras");
			puts("<4> :::  Terrenos");
			puts("<5+> ::: Sair"); printf("Opera��o: "); scanf("%i", &op); puts("");
			system("cls");
			//exibe um menu interrogando o usu�rio a respeito da opera��o desejada
			//l� o valor e armazena na vari�vel op
			//limpa a tela
			switch (op)//compare (op)
			{
				case 1://se op = 1
					printf("<1> ::: Listar Apartamento dispon�veis para venda:\n<2> ::: Continuar sem listar\n "); printf("Opera��o: "); scanf("%i", &op); puts("\n");
					//pergunta ao usu�rio a respeito da opera��o desejada. l	
					if(op == 1)
					{
						system("cls");// limpa a tela
						
						Ponteiro = fopen("Apartamentos.txt", "r");//Vari�vel Ponteiro = Abra ("---.txt", "no modo de leitura de informa��es");
						while (!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em("---.txt"));
						{
			
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
							// L� as informa��es contidas no arquivo 
							
							printf("ID: %i \n", Info.ID);
							printf("Andar: %i\n", Info.andar);
							printf("Quantidade de Dormit�rio(s): %i \n", Info.Qtd_Dormitorio);
							printf("Quantidade de Su�te(s): %i \n", Info.Qtd_Suite);
							printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
							printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
							printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
							printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);  //EXIBE TODAS AS INFORMA��ES SOBRE TODOS OS IM�VEIS REGISTRADOS E DISPON�VEIS PARA VENDA
							ColocarEspaco(Info.infraestrutura);//chama fun��o ColocarEspaco para colocar espa�o nas vari�veis
							printf("Informa��es da Infraestrutura: %s \n", Info.infraestrutura);
							ColocarEspaco(Info.endereco);//chama fun��o ColocarEspaco para colocar espa�o nas vari�veis
							printf("Endere�o: %s \n", Info.endereco);
							printf("Possui �rea de lazer?: %s\n", Info.Area_de_Lazer);
							printf("�rea total: %.2f\n", Info.Area_do_terreno);
							printf("Terreno total constru�do: %.2f\n", Info.Area_construida_total);
							printf("Valor do Im�vel: %.2f\n", Info.valor_do_imovel);	
							printf("N� de telefone: %s\n\n", Info.n_telefone);
		 			 }
		  			 fclose(Ponteiro);//feche (---.txt);
		  			 printf("Listagem conclu�da!\n\n");//Coloque em tela("----");
				}

		
				cracha://Ponto usado em conjunto ao comando goto, usado posteriormente
				PonteiroNovo = fopen("Corretores.txt", "r");// vari�vel PonteiroNovo � igual a Abra("---.txt", "modo leitura");
				printf("Por favor informe o crach�: "); scanf("%i", &cracha); puts("");//pede ao usu�rio que informe seu crach�, L� e armazena na vari�vel cracha
				while(!feof(PonteiroNovo))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "---.txt");
				{
				
					fscanf(PonteiroNovo, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);		
					// L� as informa��es contidas no arquivo 
					
					if(Info2.numero_do_cracha == cracha)// Se (vari�vel Info2.numero_do_cracha for igual a vari�vel cracha) Info3.numero_do_crach� recebe o valor da vari�vel crach�.
					{
						Info3.numero_do_cracha = cracha; //Info3.numero-do_cracha recebe valor da vari�vel crach�
					}
				}//fim do la�o de repeti��o
				fclose(PonteiroNovo);//feche(Corretores.txt);
				
				if (Info3.numero_do_cracha == 0)//se (Info3.numero_do_cracha for igual a 0) significa que o crach� informado n�o foi encontrado
				{
					printf("Crach� n�o existe/n�o registrado!\n\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o crach� n�o existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// l� o valor e armazena na vari�vel op
					if (op == 1)//se op for igual a 1
					{
						goto cracha;//volta no ponto cracha, definido previamente 
					} 
					else//se n�o
					{
						goto fim;// vai at� o ponto fim, definido posteriormente 
					}
				}//fim da compara��o 	
				

				id://Ponto usado em conjunto ao comando goto, usado posteriormente
				printf("Digite o ID do apartamento: "); scanf("%i", &id); puts("\n"); //pede ao usu�rio que informe seu id, l� e armazena na vari�vel id
				Ponteiro = fopen("Apartamentos.txt", "r");// vari�vel Ponteiro � igual a Abra("----.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em Ponteiro);
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// L� as informa��es contidas no arquivo
									
					if(id == Info.ID)// se Info.ID for igual a var�vel id (Se algum ID no arquivo for igual ao id informado para aluguel)
					{
						vf = 1;//vf � igual a 1 (servir� para compara��o posteriormente)
						PonteiroNovo2 = fopen("ApartamentosVendidos.txt", "a+");// vari�vel PonteiroNovo2 � igual a Abra("----.txt", "modo escrita");
						fprintf(PonteiroNovo2, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info3.numero_do_cracha, Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
						//insira no arquivo(PonteiroNovo2, "as informa��es contidas em Ponteiro + o n�mero do crach� do corretor intermedi�rio da opera��o
						fclose(PonteiroNovo2);
						//fecha (PonteiroNovo2)
					}	
				}
				fclose(Ponteiro);//fecha (Ponteiro)
				
				//vf foi definido previamente como 0.
				if (vf == 0)//se (vf for igual a 0) significa que o id informado n�o foi encontrado
				{
					printf("ID n�o existe/n�o registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o id n�o existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// l� o valor e armazena na vari�vel op
					if (op == 1)//se op for igual a 1
					{
						goto id;//volta no ponto id, definido previamente
					} 
					else//se n�o
					{
						goto fim;// vai at� o ponto fim, definido posteriormente 
					}
				}//fim da compara��o 
				
				
				Ponteiro = fopen("Apartamentos.txt","r"); // vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
				FILE* PonteiroNovo = fopen("Apartamentos_novo.txt", "w"); // vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
						
						while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 
							// L� as informa��es contidas no arquivo
							
							
							if (Info.ID != id) // se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{	
								fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
								//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del Apartamentos.txt");//sistema (delete arquivo ----.txt)
						system("rename Apartamentos_novo.txt Apartamentos.txt");//sistema (renomeie ----.txt para ---.txt
						break;	//saia do switch	
			
			
			case 2://se op = 2
					printf("<1> ::: Listar Apartamento dispon�veis para venda:\n<2> ::: Continuar sem listar\n "); printf("Opera��o: "); scanf("%i", &op); puts("/n"); system("cls");
					//pergunta ao usu�rio a respeito da opera��o desejada. 
					// limpa a tela
					
					if(op == 1)//se op = 1
					{
						system("cls");// limpa a tela
						Ponteiro = fopen("Casa.txt", "r");//Vari�vel Ponteiro = Abra ("---.txt", "no modo de leitura de informa��es");
						while (!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em("---.txt"));
						{
			
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
							// L� as informa��es contidas no arquivo 
							
							printf("ID: %i \n", Info.ID);
							printf("Quantidade de Dormit�rio(s): %i \n", Info.Qtd_Dormitorio);
							printf("Quantidade de Su�te(s): %i \n", Info.Qtd_Suite);
							printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
							printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
							printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);			 //EXIBE TODAS AS INFORMA��ES SOBRE TODOS OS IM�VEIS REGISTRADOS E DISPON�VEIS PARA VENDA
							printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
							ColocarEspaco(Info.infraestrutura);	//chama fun��o ColocarEspaco para colocar espa�o nas vari�veis								
							printf("Informa��es da Infraestrutura: %s \n", Info.infraestrutura);
							ColocarEspaco(Info.endereco);//chama fun��o ColocarEspaco para colocar espa�o nas vari�veis
							printf("Endere�o: %s \n", Info.endereco);
							printf("Possui �rea de lazer?: %s\n", Info.Area_de_Lazer);
							printf("�rea total: %.2f\n", Info.Area_do_terreno);
							printf("Terreno total constru�do: %.2f\n", Info.Area_construida_total);
							printf("Valor do Im�vel: %.2f\n\n", Info.valor_do_imovel);	
							printf("N� de telefone: %s", Info.n_telefone);
		 			 }
		  			 fclose(Ponteiro);//feche (---.txt);
		  			 printf("Listagem conclu�da!\n\n");//Coloque em tela("---");
				}

		

				cracha2://Ponto usado em conjunto ao comando goto, usado posteriormente
				PonteiroNovo = fopen("Corretores.txt", "r");// vari�vel PonteiroNovo � igual a Abra("---.txt", "modo leitura");
				printf("Por favor informe o crach�: "); scanf("%i", &cracha); puts("");//pede ao usu�rio que informe seu crach�, L� e armazena na vari�vel cracha
				while(!feof(PonteiroNovo))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "---.txt");
				{
				
					fscanf(PonteiroNovo, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);		
					// L� as informa��es contidas no arquivo 
					
					
					if(Info2.numero_do_cracha == cracha)// Se (vari�vel Info2.numero_do_cracha for igual a vari�vel cracha) Info3.numero_do_crach� recebe o valor da vari�vel crach�.
					{
						Info3.numero_do_cracha = cracha;//Info3.numero-do_cracha recebe valor da vari�vel cracha
					}
				}//fim do la�o de repeti��o
				fclose(PonteiroNovo);//feche(Corretores.txt);
				
				if (Info3.numero_do_cracha == 0)//se (Info3.numero_do_cracha for igual a 0) significa que o crach� informado n�o foi encontrado
				{
					printf("Crach� n�o existe/n�o registrado!\n\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o crach� n�o existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// l� o valor e armazena na vari�vel op
					
					if (op == 1)//se op for igual a 1
					{
						goto cracha2;//volta no ponto cracha, definido previamente
					} 
					else//se n�o
					{
						goto fim;// vai at� o ponto fim, definido posteriormente 
					}
				}	//fim da compara��o 

				id2://Ponto usado em conjunto ao comando goto, usado posteriormente
				printf("Digite o ID do apartamento: "); scanf("%i", &id); puts("\n"); //pede ao usu�rio que informe seu id, l� e armazena na vari�vel id
				Ponteiro = fopen("Casa.txt", "r");// vari�vel Ponteiro � igual a Abra("----.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em Ponteiro);
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// L� as informa��es contidas no arquivo
					if(id == Info.ID)// se Info.ID for igual a var�vel id (Se algum ID no arquivo for igual ao id informado para aluguel)
					{
						vf = 1; //vf � igual a 1 (servir� para compara��o posteriormente)
						PonteiroNovo2 = fopen("CasaVendidos.txt", "a+");// vari�vel PonteiroNovo2 � igual a Abra("----.txt", "modo escrita");
						fprintf(PonteiroNovo2, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info3.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
						//insira no arquivo(PonteiroNovo2, "as informa��es contidas em Ponteiro + o n�mero do crach� do corretor intermedi�rio da opera��o
						fclose(PonteiroNovo2);//fecha (PonteiroNovo2)
					}	
				}
				fclose(Ponteiro);//fecha (Ponteiro)
				
				//vf foi definido previamente como 0.
				if (vf == 0)//se (vf for igual a 0) significa que o id informado n�o foi encontrado
				{
					printf("ID n�o existe/n�o registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o id n�o existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// l� o valor e armazena na vari�vel op
					if (op == 1)//se op for igual a 1
					{
						goto id2;//volta no ponto id, definido previamente
					} 
					else//se n�o
					{
						goto fim;// vai at� o ponto fim, definido posteriormente 
					}
				}//fim da compara��o 

					
				
				Ponteiro = fopen("Casa.txt","r"); // vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
				PonteiroNovo = fopen("Casa_novo.txt", "w"); // vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
						
						while(!feof(Ponteiro))// vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 
							// L� as informa��es contidas no arquivo
							
							if (Info.ID != id) // se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{	
								fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
								//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del Casa.txt");//sistema (delete arquivo ----.txt)
						system("rename Casa_novo.txt Casa.txt");//sistema (renomeie ----.txt para ---.txt)
						break; //saia do switch
						
			case 3://se op = 3
					printf("<1> ::: Listar Ch�caras dispon�veis para venda:\n<2> ::: Continuar sem listar\n "); printf("Opera��o: "); scanf("%i", &op); puts("/n"); system("cls");
					//pergunta ao usu�rio a respeito da opera��o desejada. 
					
					if(op == 1)
					{
						system("cls");// limpa a tela
					
						Ponteiro = fopen("Chacaras.txt", "r");//Vari�vel Ponteiro = Abra ("---.txt", "no modo de leitura de informa��es")
						while (!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em("---.txt"));
						{
			
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
							// L� as informa��es contidas no arquivo 
							
							
							printf("ID: %i \n", Info.ID);
							printf("Quantidade de Dormit�rio(s): %i \n", Info.Qtd_Dormitorio);
							printf("Quantidade de Su�te(s): %i \n", Info.Qtd_Suite);
							printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
							printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
							printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
							printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro); //EXIBE TODAS AS INFORMA��ES SOBRE TODOS OS IM�VEIS REGISTRADOS E DISPON�VEIS PARA VENDA
							ColocarEspaco(Info.infraestrutura);//chama fun��o ColocarEspaco para colocar espa�o nas vari�veis
							printf("Informa��es da Infraestrutura: %s \n", Info.infraestrutura);
							ColocarEspaco(Info.endereco);//chama fun��o ColocarEspaco para colocar espa�o nas vari�veis
							printf("Endere�o: %s \n", Info.endereco);
							printf("Possui �rea de lazer?: %s\n", Info.Area_de_Lazer);
							printf("�rea total: %.2f\n", Info.Area_do_terreno);
							printf("Terreno total constru�do: %.2f\n", Info.Area_construida_total);
							printf("Valor do Im�vel: %.2f\n", Info.valor_do_imovel);	
							printf("N� de telefone: %s\n\n", Info.n_telefone);
		 			 }
		  			 fclose(Ponteiro);//feche (---.txt);
		  			 printf("Listagem conclu�da!\n\n");//Coloque em tela("---");
				}


				cracha3://Ponto usado em conjunto ao comando goto, usado posteriormente
				PonteiroNovo = fopen("Corretores.txt", "r");// vari�vel PonteiroNovo � igual a Abra("---.txt", "modo leitura");
				printf("Por favor informe o crach�: "); scanf("%i", &cracha); puts("");//pede ao usu�rio que informe seu crach�, L� e armazena na vari�vel cracha
				while(!feof(PonteiroNovo))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "---.txt");
				{
				
					fscanf(PonteiroNovo, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);		
					// L� as informa��es contidas no arquivo 
					
					if(Info2.numero_do_cracha == cracha)// Se (vari�vel Info2.numero_do_cracha for igual a vari�vel cracha) Info3.numero_do_crach� recebe o valor da vari�vel crach�.
					{
						Info3.numero_do_cracha = cracha;//Info3.numero-do_cracha recebe valor da vari�vel cracha
					}
				}//fim do la�o de repeti��o
				fclose(PonteiroNovo);//feche(Corretores.txt);
				
				if (Info3.numero_do_cracha == 0)//se (Info3.numero_do_cracha for igual a 0) significa que o crach� informado n�o foi encontrado
				{
					printf("Crach� n�o existe/n�o registrado!\n\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o crach� n�o existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// l� o valor e armazena na vari�vel op
					
					if (op == 1)//se op for igual a 1
					{
						goto cracha3;//volta no ponto cracha, definido previamente
					} 
					else//se n�o
					{
						goto fim;// vai at� o ponto fim, definido posteriormente 
					}
				}	//fim da compara��o 

				id3://Ponto usado em conjunto ao comando goto, usado posteriormente
				printf("Digite o ID do apartamento: "); scanf("%i", &id); puts("\n");//pede ao usu�rio que informe seu id, l� e armazena na vari�vel id
				Ponteiro = fopen("Chacaras.txt", "r");// vari�vel Ponteiro � igual a Abra("----.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em Ponteiro);
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// L� as informa��es contidas no arquivo
					
					if(id == Info.ID)// se Info.ID for igual a var�vel id (Se algum ID no arquivo for igual ao id informado para aluguel)
					{
						
						vf = 1;//vf � igual a 1 (servir� para compara��o posteriormente)
						PonteiroNovo2 = fopen("ChacarasVendidos.txt", "a+");// vari�vel PonteiroNovo2 � igual a Abra("----.txt", "modo escrita");
						fprintf(PonteiroNovo2, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info3.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
						fclose(PonteiroNovo2);
					}	
				}
				fclose(Ponteiro);//fecha (---.txt)
				
				//vf foi definido previamente como 0.	
				if (vf == 0)//se (vf for igual a 0) significa que o id informado n�o foi encontrado
				{
					printf("ID n�o existe/n�o registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o id n�o existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// l� o valor e armazena na vari�vel op
					if (op == 1)//se op for igual a 1
					{
						goto id3;//volta no ponto id, definido previamente
					} 
					else//se n�o
					{
						goto fim;// vai at� o ponto fim, definido posteriormente 
					}
				}//fim da compara��o 
				
				Ponteiro = fopen("Chacaras.txt","r"); // vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
				PonteiroNovo = fopen("Chacaras_novo.txt", "w"); // vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
						
						while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 
							// L� as informa��es contidas no arquivo
							
							if (Info.ID != id) // se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{	
								fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
								//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del Chacaras.txt");//sistema (delete arquivo ----.txt)
						system("rename Chacaras_novo.txt Chacaras.txt");//sistema (renomeie ----.txt para ---.txt)
						break;	//saia do switch

			case 4://se op = 4
					printf("<1> ::: Listar Terrenos dispon�veis para venda:\n<2> ::: Continuar sem listar\n "); printf("Opera��o: "); scanf("%i", &op); puts("/n"); system("cls");
					//pergunta ao usu�rio a respeito da opera��o desejada. 
					if(op == 1)
					{
						system("cls"); // limpa a tela
					
						Ponteiro = fopen("Terrenos.txt", "r");//Vari�vel Ponteiro = Abra ("---.txt", "no modo de leitura de informa��es");
						while (!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em("---.txt"));
						{
						    fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
							// L� as informa��es contidas no arquivo 
							
							printf("ID: %i \n", Info.ID);
							printf("�rea total: %.2f\n", Info.Area_do_terreno);
							printf("Valor do Im�vel: %.2f\n", Info.valor_do_imovel); //EXIBE TODAS AS INFORMA��ES SOBRE TODOS OS IM�VEIS REGISTRADOS E DISPON�VEIS PARA VENDA	
							printf("Endere�o: %s\n", Info.endereco);
							printf("N� de telefone: %s\n\n", Info.n_telefone);
		 			 	}
		  			 	fclose(Ponteiro);//feche (---.txt);
		  				 printf("Listagem conclu�da!\n\n");//Coloque em tela("---");
					}


		
			
				cracha4://Ponto usado em conjunto ao comando goto, usado posteriormente
				PonteiroNovo = fopen("Corretores.txt", "r");// vari�vel PonteiroNovo � igual a Abra("---.txt", "modo leitura");
				printf("Por favor informe o crach�: "); scanf("%i", &cracha); puts("");//pede ao usu�rio que informe seu crach�, L� e armazena na vari�vel cracha
				while(!feof(PonteiroNovo))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "---.txt");
				{
				
					fscanf(PonteiroNovo, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);		
					// L� as informa��es contidas no arquivo 
					
					
					if(Info2.numero_do_cracha == cracha)// Se (vari�vel Info2.numero_do_cracha for igual a vari�vel cracha) Info3.numero_do_crach� recebe o valor da vari�vel crach�.
					{
						Info3.numero_do_cracha = cracha;//Info3.numero-do_cracha recebe valor da vari�vel cracha
					}
				}//fim do la�o de repeti��o
				
				fclose(PonteiroNovo);//feche(Corretores.txt);
				
				if (Info3.numero_do_cracha == 0)//se (Info3.numero_do_cracha for igual a 0) significa que o crach� informado n�o foi encontrado
				{
					printf("Crach� n�o existe/n�o registrado!\n\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o crach� n�o existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// l� o valor e armazena na vari�vel op
					
					if (op == 1)//se op for igual a 1
					{
						goto cracha4;//volta no ponto cracha, definido previamente
					} 
					else//se n�o
					{
						goto fim;// vai at� o ponto fim, definido posteriormente 
					}
				}	//fim da compara��o 

				id4://Ponto usado em conjunto ao comando goto, usado posteriormente
				printf("Digite o ID do apartamento: "); scanf("%i", &id); puts(""); //pede ao usu�rio que informe seu id, l� e armazena na vari�vel id
				Ponteiro = fopen("Terrenos.txt", "r");// vari�vel Ponteiro � igual a Abra("----.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em Ponteiro);
				{
					fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
					// L� as informa��es contidas no arquivo
					
					if(id == Info.ID)// se Info.ID for igual a var�vel id (Se algum ID no arquivo for igual ao id informado para aluguel)
					{
						vf = 1;//vf � igual a 1 (servir� para compara��o posteriormente)
						PonteiroNovo2 = fopen("TerrenosVendidos.txt", "a+");// vari�vel PonteiroNovo2 � igual a Abra("----.txt", "modo escrita")
						fprintf(PonteiroNovo2, "%i %i %f %f %s %s\n", Info.ID, Info3.numero_do_cracha, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);
						//insira no arquivo(PonteiroNovo2, "as informa��es contidas em Ponteiro + o n�mero do crach� do corretor intermedi�rio da opera��o
						
						fclose(PonteiroNovo2);//fecha (PonteiroNovo2)
					}	
				}
				fclose(Ponteiro);//fecha (Ponteiro)
				
				//vf foi definido previamente como 0.
				if (vf == 0)//se (vf for igual a 0) significa que o id informado n�o foi encontrado
				{
					printf("ID n�o existe/n�o registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o id n�o existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// l� o valor e armazena na vari�vel op
					
					if (op == 1)//se op for igual a 1
					{
						goto id4;//volta no ponto id, definido previamente
					} 
					else//se n�o
					{
						goto fim;// vai at� o ponto fim, definido posteriormente 
					}
				}	//fim da compara��o 
				
				Ponteiro = fopen("Terrenos.txt","r"); // vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
				PonteiroNovo = fopen("Terrenos_novo.txt", "w"); // vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
						
						while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
						{
							fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
							// L� as informa��es contidas no arquivo
							if (Info.ID != id) // se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{	
								fprintf(PonteiroNovo, "%i %f %f %s %s\n", Info.ID, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);	
								//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del Terrenos.txt");//sistema (delete arquivo ----.txt)
						system("rename Terrenos_novo.txt Terrenos.txt");//sistema (renomeie ----.txt para ---.txt)
						break;	//saia do switch					
			default://se nenhuma compara��o correspondeu
				break;//saia do switch
				
			}	//fim do switch		
		fim://Ponto usado em conjunto ao comando goto, usado previamente
		printf("Opera��o Finalizada!\n\n");//Coloque em tela("---");
		
		return 0;//retorne 0

}
	
			

	
void excluir_registros()//cria uma fun��o do tipo vazio de nome Excluir Registros()
{
	Corretor Info2; //cria uma vari�vel do tipo Corretor de nome Info2
	Ficha_Tecnica_Imovel Info; //cria uma vari�vel do tipo Ficha_Tecnica_Imovel de nome Info
	int id, op, vf = 0, op3 = -1; //cria vari�vei do tipo inteiro de nomes...;
	FILE* PonteiroNovo;	//cria uma vari�vel do tipo FILE de nome PonteiroNovo
	
	printf("::: Excluir Registros ::;\n\n"); //c
	puts("<1> ::: Excluir Im�vel � venda");
	puts("<2> ::: Excluir Corretor");
	puts("<3> ::: Excluir Im�vel Vendido");
	puts("<4> ::: Excluir Im�vel � alugar");
	puts("<5> ::: Excluir Im�vel alugado");
	puts("<6+> :::Sair");
	printf("Opera��o: "); scanf("%i", &op); puts("");
	system("cls");
	//exibe um menu e pergunta ao usu�rio que opera��o deseja realizar
	//l� o valor e armazena na vari�vel op
	//limpa a tela
	
	switch (op)//compare (op)
	{
		case 1://se op = 1
			printf("::: Excluir Im�vel � venda :::\n\n");
			puts("<1> ::: Apartamento");
			puts("<2> ::: Casa");
			puts("<3> ::: Ch�cara");
			puts("<4> ::: Terreno");
			puts("<5+> ::: Sair");
			printf("Opera��o: "); scanf("%i", &op); puts("");
			system("cls");
			//Mostra op��o que o usu�rio escolheu anteriormente
			//exibe um menu e pergunta ao usu�rio que opera��o deseja realizar
			//limpa a tela
			
				switch (op)
				{	
					case 1://se op = 1
						printf("::: Excluir apartamento<s> � venda :::\n\n");//Mostra op��o que o usu�rio escolheu anteriormente
						r://Ponto usado em conjunto ao comando goto, usado posteriormente
	
						printf("Informe o ID do apartamento que deseja remover: "); scanf("%i", &id); puts("");
						//pede ao usu�rio que digite o id do imovel que deseja excluir
						Ponteiro = fopen("Apartamentos.txt", "r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
						FILE* PonteiroNovo = fopen("Apartamentos_novo.txt","w"); // vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
		
						while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas em "----.txt");
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 
							// L� as informa��es contidas no arquivo
							
							//vf foi definido previamente como 0.
							if (Info.ID == id) //se Info.ID for igual a id (significa que o programa achou a informa��o a ser exclu�da)
							{
								vf = 1;	//vf recebe 1 
							}	
							
							if (id != Info.ID) // se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{
								fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
								//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
							}					      
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del Apartamentos.txt");//sistema (delete arquivo ----.txt)
						system("rename Apartamentos_novo.txt Apartamentos.txt");//sistema (renomeie ----.txt para ---.txt)
					    if (vf == 0) //se vf for igual a 0(significa que o sistema n�o achou nenhum dado a ser exclu�do, portanto nada foi feito)
						{ 
							printf("Erro! Id informado n�o existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
							printf("Opera��o: "); scanf("%i", &op); puts("\n");
							//exibe uma mensagem informando o usu�rio 
							//L� o valor inserido e armazena na vari�vel op
							//pula 2 linhas
							
							if (op == 1)//se op for igual a 1
							{
								goto r;//v� para o ponto r
							}//se op for igual a 2, a verifica��o acontece e o sistema volta a tela inicial	
						}
						goto fim;//v� para o ponto fim
					
						
					case 2://se op = 2
						printf("::: Excluir casa<s> � venda :::\n\n");//exibe op��o escolhida pelo usu�rio anteriormente
						
						r2://Ponto usado em conjunto ao comando goto, usado posteriormente
						
						printf("Informe o ID que deseja remover: "); scanf("%i", &id); puts("");//pede ao usu�rio que digite o id do im�vel que deseja excluir
						
						Ponteiro = fopen("Casa.txt","r"); // vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
						FILE* PonteiroNovo2 = fopen("Casa_novo.txt","w"); // vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
						
						while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 
							// L� as informa��es contidas no arquivo]
							
							if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informa��o a ser exclu�da)
							{
								vf = 1;	//vf recebe 1 
							}	
							
							if (Info.ID != id) // se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{
								fprintf(PonteiroNovo2, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
				 				//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo2); // fechar o uso do arquivo
						
						system("del Casa.txt");//sistema (delete arquivo ----.txt)
						system("rename Casa_novo.txt Casa.txt");//sistema (renomeie ----.txt para ---.txt)

						if (vf == 0)//se vf for igual a 0(significa que o sistema n�o achou nenhum dado a ser exclu�do, portanto nada foi feito)
						{ 
							printf("Erro! Id informado n�o existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
							printf("Opera��o: "); scanf("%i", &op); puts("\n");
							//exibe uma mensagem informando o usu�rio 
							//L� o valor inserido e armazena na vari�vel op
							//pula 2 linhas

							//se op for igual a 1
							if (op == 1)
							{
								goto r2;//v� para o ponto r2
							}//se op for igual a 2, a verifica��o acontece e o sistema volta a tela inicial	
						}
						goto fim;//v� para o ponto fim
						
					case 3://se op = 3
						printf("::: Excluir ch�cara<s> � venda :::\n\n");//exibe op��o escolhida pelo usu�rio anteriormente
						r3://Ponto usado em conjunto ao comando goto, usado posteriormente
						printf("Informe o ID que deseja remover: "); scanf("%i", &id); puts("");//pede ao usu�rio que digite o id do im�vel que deseja excluir
	
						Ponteiro = fopen("Chacaras.txt","r"); // vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");

						FILE* PonteiroNovo3 = fopen("Chacaras_novo.txt","w"); // vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
		
						while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 
							// L� as informa��es contidas no arquivo
							
							if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informa��o a ser exclu�da)
							{
								vf = 1;	//vf recebe 1 
							}	
							if (Info.ID != id) // se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{
								fprintf(PonteiroNovo3, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
								//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo3); // fechar o uso do arquivo
	
						system("del Chacaras.txt");//sistema (delete arquivo ----.txt)
						system("rename Chacaras_novo.txt Chacaras.txt");//sistema (renomeie ----.txt para ---.txt)
					
						if (vf == 0)//se vf for igual a 0(significa que o sistema n�o achou nenhum dado a ser exclu�do, portanto nada foi feito)
						{ 
							printf("Erro! Id informado n�o existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
							printf("Opera��o: "); scanf("%i", &op); puts("\n");
							//exibe uma mensagem informando o usu�rio 
							//L� o valor inserido e armazena na vari�vel op
							//pula 2 linhas
						
							if (op == 1)//se op for igual a 1
							{
								goto r3;//v� para o ponto r3								
							}	//se op for igual a 2, a verifica��o acontece e o sistema volta a tela inicial
						}
						goto fim;//v� para o ponto fim
					
					case 4://se op = 4
						printf("::: Excluir terreno<s> � venda :::\n\n");//exibe op��o escolhida pelo usu�rio anteriormente
						r4:
						printf("Informe o ID que deseja remover: "); scanf("%i", &id); puts("");//pede ao usu�rio que digite o id do im�vel que deseja excluir
	
						Ponteiro = fopen("Terrenos.txt","r"); // vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
						FILE* PonteiroNovo4 = fopen("Terrenos_novo.txt","w"); // vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
		
						while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
						{
							fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
							// L� as informa��es contidas no arquivo
							if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informa��o a ser exclu�da)
							{
								vf = 1;	//vf recebe 1 							
							}	
							
							if (Info.ID != id) // se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{
								fprintf(PonteiroNovo4, "%i %f %f %s %s\n", Info.ID, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);
								//insira no arquivo(PonteiroNovo4, "as informa��es contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo4); // fechar o uso do arquivo
						
						system("del Terrenos.txt");//sistema (delete arquivo ----.txt)
						system("rename Terrenos_novo.txt Terrenos.txt");//sistema (renomeie ----.txt para ---.txt)
						if (vf == 0)//se vf for igual a 0(significa que o sistema n�o achou nenhum dado a ser exclu�do, portanto nada foi feito)
						{ 
							printf("Erro! Id informado n�o existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
							printf("Opera��o: "); scanf("%i", &op); puts("\n");
							//exibe uma mensagem informando o usu�rio 
							//L� o valor inserido e armazena na vari�vel op
							//pula 2 linhas
							
							if (op == 1)//se op for igual a 1
							{
								goto r4;//v� para o ponto r4
							}	
						}
						goto fim;//v� para o ponto fim
						
					default://se nenhum dos case corresponder:
						goto fim;//v� para o ponto fim
				}
	
		case 2://se op = 2
				puts("\n::: Excluir Corretor :::\n\n ");//exibe op��o escolhida pelo usu�rio anteriormente
				r5://Ponto usado em conjunto ao comando goto, usado posteriormente
				printf("Informe o crach� do Corretor que deseja remover: "); scanf("%i", &id); puts("");
				//pede ao usu�rio que digite o cracha do corretor que deseja excluir
				Ponteiro = fopen("Corretores.txt","r"); // vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
				FILE* PonteiroNovo5 = fopen("Corretores_novo.txt","w"); // vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
				while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
				{
					fscanf(Ponteiro, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);
					// L� as informa��es contidas no arquivo
					
					if (Info2.numero_do_cracha == id)//se Info.ID for igual a id (significa que o programa achou a informa��o a ser exclu�da)
					{
						vf = 1;//vf recebe 1 
					}
					if (Info2.numero_do_cracha != id) // se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
					{
						fprintf(PonteiroNovo5, "%i %s %s %s %i %f %f\n", Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, Info2.idade, Info2.salario_b, Info2.comissao_pvenda);
						//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
					}
				}
				fclose(Ponteiro); // fechar o uso do arquivo
				fclose(PonteiroNovo5);// fechar o uso do arquivo
		
				system("del Corretores.txt");//sistema (delete arquivo ----.txt)
				system("rename Corretores_novo.txt Corretores.txt");	//sistema (renomeie ----.txt para ---.txt)
				if (vf == 0)//se vf for igual a 0(significa que o sistema n�o achou nenhum dado a ser exclu�do, portanto nada foi feito)
				{ 
					printf("Erro! Crach� informado n�o existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
					printf("Opera��o: "); scanf("%i", &op); puts("\n");
					//exibe uma mensagem informando o usu�rio 
					//L� o valor inserido e armazena na vari�vel op
					//pula 2 linhas				
				
					if (op == 1)//se op for igual a 1
					{
						goto r5;//v� para o ponto r5
					}//se op for igual a 2, a verifica��o acontece e o sistema volta a tela inicial	
				}
				goto fim;//v� para o ponto fim
		
		case 3:  //se op = 3
				printf("::: Excluir Im�vel Vendido :::\n\n");//exibe op��o escolhida pelo usu�rio anteriormente
				puts("<1> :::  Apartamentos");
				puts("<2> :::  Casa");
				puts("<3> :::  Ch�cara");
				puts("<4> :::  Terreno");
				puts("<5+> ::: Sair"); printf("Opera��o: "); scanf("%i", &op); puts("");
				system("cls");
				//Mostra op��o que o usu�rio escolheu anteriormente
				//exibe um menu e pergunta ao usu�rio que opera��o deseja realizar
				//le o valor informado e armazena na vari�vel op
				//limpa a tela
			
				switch (op)//compare(op)
				{
						case 1://se op = 1
							printf("::: Excluir Apartamento<s> Vendido<s> :::\n\n");//exibe op��o escolhida pelo usu�rio anteriormente
							r6://Ponto usado em conjunto ao comando goto, usado posteriormente
							puts("Informe o ID do apartamento a ser exclu�do: "); printf("Opera��o: "); scanf("%i", &id); puts(""); 
							//pede ao usu�rio que digite o id do im�vel que deseja excluir
							
							Ponteiro = fopen("ApartamentosVendidos.txt", "r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
							FILE* PonteiroNovo = fopen("ApartamentosVendidos_Novo.txt", "w");// vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
							
							while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
							{
					
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n",&Info2.numero_do_cracha, &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
								// L� as informa��es contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informa��o a ser exclu�da)
								{
									vf = 1;//vf recebe 1 
								}
								if(id != Info.ID)// se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info2.numero_do_cracha, Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
								}	
							}
							fclose(PonteiroNovo);// fechar o uso do arquivo
							fclose(Ponteiro);// fechar o uso do arquivo
							system("del ApartamentosVendidos.txt");//sistema (delete arquivo ----.txt)
							system("rename ApartamentosVendidos_novo.txt ApartamentosVendidos.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema n�o achou nenhum dado a ser exclu�do, portanto nada foi feito)
							{ 
								printf("Erro! Crach� informado n�o existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Opera��o: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usu�rio 
								//L� o valor inserido e armazena na vari�vel op
								//pula 2 linhas
								
								if (op == 1)//se op for igual a 1
								{
									goto r6;//v� para o ponto r6

								}//se op for igual a 2, a verifica��o acontece e o sistema volta a tela inicial		
							}
							
							goto fim;//v� para o ponto fim
						
						case 2://se op = 2
							printf("::: Remover casa<s> vendida<s> :::\n\n");//exibe op��o escolhida pelo usu�rio anteriormente
							r7://Ponto usado em conjunto ao comando goto, usado posteriormente
							puts("Informe o ID do apartamento a ser exclu�do: "); printf("Opera��o: "); scanf("%i", &id); puts(""); 
							//pede ao usu�rio que digite o id do im�vel que deseja excluir
							
							Ponteiro = fopen("CasaVendidos.txt", "r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
							PonteiroNovo = fopen("Casavendidos_Novo.txt", "w");// vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
							
							while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
							{
					
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n",&Info2.numero_do_cracha, &Info.ID,  &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
								// L� as informa��es contidas no arquivo

								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informa��o a ser exclu�da)
								{
									vf = 1;//vf recebe 1 
								}
								
								if(id != Info.ID)// se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info2.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);			
									//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
								}	
							}
							fclose(PonteiroNovo);// fechar o uso do arquivo
							fclose(Ponteiro);// fechar o uso do arquivo
							system("del Casavendidos.txt");//sistema (delete arquivo ----.txt)
							system("rename Casavendidos_novo.txt CasaVendidos.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema n�o achou nenhum dado a ser exclu�do, portanto nada foi feito)
							{ 
								printf("Erro! Crach� informado n�o existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Opera��o: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usu�rio 
								//L� o valor inserido e armazena na vari�vel op
								//pula 2 linhas
								if (op == 1)//se op for igual a 1
								{
									goto r7;//v� para o ponto r7
								}//se op for igual a 2, a verifica��o acontece e o sistema volta a tela inicial	
							}
							
							goto fim;//v� para o ponto fim
					
						case 3://se op = 3
							printf("::: Remover Ch�cara<s> Vendida<s> :::\n\n");//exibe op��o escolhida pelo usu�rio anteriormente
							r8://Ponto usado em conjunto ao comando goto, usado posteriormente
							puts("Informe o ID do apartamento a ser exclu�do: "); printf("Opera��o: "); scanf("%i", &id); puts(""); 
							//pede ao usu�rio que digite o id do im�vel que deseja excluir
							Ponteiro = fopen("ChacarasVendidos.txt", "r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
							PonteiroNovo = fopen("Chacarasvendidos_Novo.txt", "w");// vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
							
							while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
							{
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n",&Info2.numero_do_cracha, &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
								// L� as informa��es contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informa��o a ser exclu�da)
								{
									vf = 1;//vf recebe 1 
								}

								if(id != Info.ID)// se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info2.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
								}	
							}
							fclose(PonteiroNovo);// fechar o uso do arquivo
							fclose(Ponteiro);// fechar o uso do arquivo
							system("del Chacarasvendidos.txt");//sistema (delete arquivo ----.txt)
							system("rename Chacarasvendidos_novo.txt ChacarasVendidos.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema n�o achou nenhum dado a ser exclu�do, portanto nada foi feito)
							{ 
								printf("Erro! Crach� informado n�o existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Opera��o: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usu�rio 
								//L� o valor inserido e armazena na vari�vel op
								//pula 2 linhas
								
								if (op == 1)//se op for igual a 1
								{
									goto r8;//v� para o ponto r8
								}	//se op for igual a 2, a verifica��o acontece e o sistema volta a tela inicial
							}
							
							
							goto fim;//v� para o ponto fim
							
						case 4:
							printf("::: Remover Terreno<s> Vendido<s> :::\n\n");//exibe op��o escolhida pelo usu�rio anteriormente
							r9://Ponto usado em conjunto ao comando goto, usado posteriormente
							printf("Informe o ID que deseja remover: "); scanf("%i", &id); puts("");//pede ao usu�rio que digite o id do im�vel que deseja excluir
	
							Ponteiro = fopen("TerrenosVendidos.txt","r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
							FILE* PonteiroNovo4 = fopen("TerrenosVendidos_novo.txt","w"); // vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
		
							while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
							{
								fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
								// L� as informa��es contidas no arquivo

								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informa��o a ser exclu�da)
								{
									vf = 1;//vf recebe 1
								}
							
								if (Info.ID != id) // se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo4, "%i %f %f %s %s\n", Info.ID, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);	
									//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
								}
							}
							fclose(Ponteiro); // fechar o uso do arquivo
							fclose(PonteiroNovo4); // fechar o uso do arquivo
						
							system("del TerrrenosVendidos.txt");//sistema (delete arquivo ----.txt)
							system("rename TerrenosVendidos_novo.txt TerrenosVendidos.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema n�o achou nenhum dado a ser exclu�do, portanto nada foi feito)
							{ 
								printf("Erro! Crach� informado n�o existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Opera��o: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usu�rio 
								//L� o valor inserido e armazena na vari�vel op
								//pula 2 linhas
								if (op == 1)//se op for igual a 1
								{
									goto r9;//v� para o ponto r9
								}	//se op for igual a 2, a verifica��o acontece e o sistema volta a tela inicial
							}
							
							goto fim;//v� para o ponto fim
				
				}//Fim do switch para exclus�o de artigos vendidos
			
		case 4: 
				puts("\n::: Excluir Im�vel � alugar :::\n\n");
				puts("<1> :::  Terreno");
				puts("<2> :::  Casa");
				puts("<3> :::  Ch�cara");
				puts("<4> :::  Apartamento");
				puts("<5+> ::: Sair"); printf("Opera��o: "); scanf("%i", &op); puts("");
				system("cls");
			
				//Mostra op��o que o usu�rio escolheu anteriormente
				//exibe um menu e pergunta ao usu�rio que opera��o deseja realizar
				//le o valor informado e armazena na vari�vel op
				//limpa a tela
				FILE* PonteiroNovo4; //cria uma vari�vel do tipo File de nome PonteiroNovo4
				switch(op) //compare op
				{
					case 1://se op = 1
							printf("::: Excluir Terreno<s> � alugar :::\n\n");//exibe op��o escolhida pelo usu�rio anteriormente
							r10://Ponto usado em conjunto ao comando goto, usado posteriormente
							printf("Informe o ID que deseja remover: "); scanf("%i", &id); puts("");//pede ao usu�rio que digite o id do im�vel que deseja excluir
	
							Ponteiro = fopen("AlugarTerrenos.txt","r"); // vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
							PonteiroNovo4 = fopen("AlugarTerrenos_novo.txt","w"); // vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
		
							while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
							{
								fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
								// L� as informa��es contidas no arquivo
								
								//se Info.ID for igual a id (significa que o programa achou a informa��o a ser exclu�da)
								if (Info.ID == id)
								{
									vf = 1;	//vf recebe 1 
								}	
								if (Info.ID != id)// se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo4, "%i %f %f %s %s\n", Info.ID, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
								}
							}
							fclose(Ponteiro); // fechar o uso do arquivo
							fclose(PonteiroNovo4);// fechar o uso do arquivo
						
							system("del AlugarTerrenos.txt");//sistema (delete arquivo ----.txt)
							system("rename AlugarTerrenos_novo.txt AlugarTerrenos.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema n�o achou nenhum dado a ser exclu�do, portanto nada foi feito)
							{ 
								printf("Erro! Crach� informado n�o existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Opera��o: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usu�rio
								//L� o valor inserido e armazena na vari�vel op
								//pula 2 linhas
								if (op == 1)//se op for igual a 1
								{
									goto r10;//v� para o ponto r10

								}	//se op for igual a 2, a verifica��o acontece e o sistema volta a tela inicial	
							}
							
							goto fim;//v� para o ponto fim
				
					case 2://se op = 2
							printf("::: Excluir Casa<s> � alugar :::\n\n");//exibe op��o escolhida pelo usu�rio anteriormente
							r11://Ponto usado em conjunto ao comando goto, usado posteriormente
							printf("Informe o ID que deseja remover: "); scanf("%i", &id); puts("");//pede ao usu�rio que digite o id do im�vel que deseja excluir
	
							Ponteiro = fopen("AlugarCasa.txt","r"); // vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
							PonteiroNovo4 = fopen("AlugarCasa_novo.txt","w"); // vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
		
							while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
							{
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);
								// L� as informa��es contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informa��o a ser exclu�da)
								{
									vf = 1;	//vf recebe 1
								}	
								
								if (Info.ID != id) // se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
								}
							}
							fclose(Ponteiro); // fechar o uso do arquivo
							fclose(PonteiroNovo4); // fechar o uso do arquivo
						
							system("del AlugarCasa.txt");//sistema (delete arquivo ----.txt)
							system("rename AlugarCasa_novo.txt AlugarCasa.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema n�o achou nenhum dado a ser exclu�do, portanto nada foi feito)
							{ 
								printf("Erro! Crach� informado n�o existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Opera��o: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usu�rio 
								//L� o valor inserido e armazena na vari�vel op
								//pula 2 linhas
								
								if (op == 1)//se op for igual a 1
								{
									goto r11;//v� para o ponto r11
								}	
							}//se op for igual a 2, a verifica��o acontece e o sistema volta a tela inicial
							
							goto fim;//v� para o ponto fim
					
					case 3://se op = 3
							printf("::: Excluir Ch�cara<s> � alugar :::\n\n");//exibe op��o escolhida pelo usu�rio anteriormente
							r12://Ponto usado em conjunto ao comando goto, usado posteriormente
							printf("Informe o ID que deseja remover: "); scanf("%i", &id); puts("");//pede ao usu�rio que digite o id do im�vel que deseja excluir
	
							Ponteiro = fopen("AlugarChacaras.txt","r"); // vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
							PonteiroNovo4 = fopen("AlugarChacaras_novo.txt","w"); // vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
		
							while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
							{
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);
								// L� as informa��es contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informa��o a ser exclu�da)
								{
									vf = 1;	//vf recebe 1 
								}	
								
								if (Info.ID != id) // se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
								}
							}
							fclose(Ponteiro); // fechar o uso do arquivo
							fclose(PonteiroNovo4); // fechar o uso do arquivo
						
							system("del AlugarChacaras.txt");//sistema (delete arquivo ----.txt)
							system("rename AlugarChacaras_novo.txt AlugarChacaras.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema n�o achou nenhum dado a ser exclu�do, portanto nada foi feito)
							{ 
								printf("Erro! Crach� informado n�o existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Opera��o: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usu�rio 
								//L� o valor inserido e armazena na vari�vel op
								//pula 2 linhas
								
								if (op == 1)//se op for igual a 1
								{
									goto r12;//v� para o ponto r12
								}	//se op for igual a 2, a verifica��o acontece e o sistema volta a tela inicial	
							}
							
							goto fim;//v� para o ponto fim
					
					case 4://se op = 4
							printf("::: Excluir Apartamento<s> � alugar :::\n\n");//exibe op��o escolhida pelo usu�rio anteriormente
							r13://Ponto usado em conjunto ao comando goto, usado posteriormente
							printf("Informe o ID que deseja remover: "); scanf("%i", &id); puts("");//pede ao usu�rio que digite o id do im�vel que deseja excluir
	
							Ponteiro = fopen("AlugarApartamentos.txt","r"); // vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
							PonteiroNovo4 = fopen("AlugarApartamentos_novo.txt","w"); // vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
		
							while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
							{
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);
								// L� as informa��es contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informa��o a ser exclu�da)
								{
									vf = 1;	//vf recebe 1 
								}	
								
								if (Info.ID != id)// se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
								}
							}
							fclose(Ponteiro); // fechar o uso do arquivo
							fclose(PonteiroNovo4); // fechar o uso do arquivo
						
							system("del AlugarApartamentos.txt");//sistema (delete arquivo ----.txt)
							system("rename AlugarApartamentos_novo.txt AlugarApartamentos.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema n�o achou nenhum dado a ser exclu�do, portanto nada foi feito
							{ 
								printf("Erro! Crach� informado n�o existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Opera��o: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usu�rio 
								//L� o valor inserido e armazena na vari�vel op
								//pula 2 linhas
								
								if (op == 1)//se op for igual a 1
								{
									goto r13;//v� para o ponto r13
								}	//se op for igual a 2, a verifica��o acontece e o sistema volta a tela inicial
							}
							
							goto fim;//v� para o ponto fim

					
					default://se nenhum dos case corresponder
						goto fim;//v� para o ponto fim
											
				}			
				
		case 5://se op = 5
				puts("\n::: Excluir Im�vel alugado :::\n\n");
				puts("<1> :::  Apartamento");
				puts("<2> :::  Casa");
				puts("<3> :::  Ch�cara");
				puts("<4> :::  Terreno");
				puts("<5+> ::: Sair"); printf("Opera��o: "); scanf("%i", &op); puts("");
				system("cls");
				//Mostra op��o que o usu�rio escolheu anteriormente
				//exibe um menu e pergunta ao usu�rio que opera��o deseja realizar
				//le o valor informado e armazena na vari�vel op
				//limpa a tela
				switch (op)//compare (op)
				{
					case 1://se op = 1
							printf("::: Excluir Apartamento alugado :::\n\n");//exibe op��o escolhida pelo usu�rio anteriormente
							r14://Ponto usado em conjunto ao comando goto, usado posteriormente
							puts("Informe o ID do apartamento a ser exclu�do: "); printf("Opera��o: "); scanf("%i", &id); puts(""); //pede ao usu�rio que digite o id do im�vel que deseja excluir
							
							Ponteiro = fopen("ApartamentosAlugados.txt", "r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
							PonteiroNovo = fopen("ApartamentosAlugados_Novo.txt", "w");// vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
							
							while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
							{
					
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n",&Info2.numero_do_cracha, &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
								// L� as informa��es contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informa��o a ser exclu�d
								{
									vf = 1;//vf recebe 1 
								}
								if(id != Info.ID)// se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info2.numero_do_cracha, Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
								}	
							}
							fclose(PonteiroNovo);// fechar o uso do arquivo
							fclose(Ponteiro);// fechar o uso do arquivo
							system("del ApartamentosAlugados.txt");//sistema (delete arquivo ----.txt)
							system("rename ApartamentosAlugados_novo.txt ApartamentosAlugados.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema n�o achou nenhum dado a ser exclu�do, portanto nada foi feito)
							{ 
								printf("Erro! ID informado n�o existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Opera��o: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usu�rio 
								//L� o valor inserido e armazena na vari�vel op
								//pula 2 linhas

								
								
								if (op == 1)//se op for igual a 1
								{
									goto r14;//v� para o ponto r14
								}	//se op for igual a 2, a verifica��o acontece e o sistema volta a tela inicial
							}
							
							goto fim;//v� para o ponto fim

					case 2:	//se op = 2			
							printf("::: Excluir Casa alugada :::\n\n");//exibe op��o escolhida pelo usu�rio anteriormente
							r15://Ponto usado em conjunto ao comando goto, usado posteriormente
							puts("Informe o ID do apartamento a ser exclu�do: "); printf("Opera��o: "); scanf("%i", &id); puts(""); //pede ao usu�rio que digite o id do im�vel que deseja excluir

							
							Ponteiro = fopen("CasaAlugados.txt", "r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
							PonteiroNovo = fopen("CasaAlugados_Novo.txt", "w");// vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
							
							while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
							{
					
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n",&Info2.numero_do_cracha, &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
								// L� as informa��es contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informa��o a ser exclu�da)
								{
									vf = 1;//vf recebe 1 
								}
								if(id != Info.ID)// se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info2.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
								}						  
							}
							fclose(PonteiroNovo);// fechar o uso do arquivo
							fclose(Ponteiro);// fechar o uso do arquivo
							system("del CasaAlugados.txt");//sistema (delete arquivo ----.txt)
							system("rename CasaAlugados_novo.txt CasaAlugados.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema n�o achou nenhum dado a ser exclu�do, portanto nada foi feito)
							{ 
								printf("Erro! ID informado n�o existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Opera��o: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usu�rio 
								//L� o valor inserido e armazena na vari�vel op
								//pula 2 linhas
								
								if (op == 1)//se op for igual a 1
								{
									goto r15;//v� para o ponto r15
								}	
							}//se op for igual a 2, a verifica��o acontece e o sistema volta a tela inicial
	
							goto fim;//v� para o ponto fim

					case 3://se op = 1		
							printf("::: Excluir Ch�cara alugada :::\n\n");//exibe op��o escolhida pelo usu�rio anteriormente
							r16://Ponto usado em conjunto ao comando goto, usado posteriormente
							puts("Informe o ID do apartamento a ser exclu�do: "); printf("Opera��o: "); scanf("%i", &id); puts(""); //pede ao usu�rio que digite o id do im�vel que deseja excluir
							
							Ponteiro = fopen("ChacarasAlugados.txt", "r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
							PonteiroNovo = fopen("ChacarasAlugados_Novo.txt", "w");// vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
							
							while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
							{
					
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n",&Info2.numero_do_cracha, &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
								// L� as informa��es contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informa��o a ser exclu�da)
								{
									vf = 1;//vf recebe 1 
								}
								if(id != Info.ID)// se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info2.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
								}						  
							}
							fclose(PonteiroNovo);// fechar o uso do arquivo
							fclose(Ponteiro);// fechar o uso do arquivo
							system("del ChacarasAlugados.txt");//sistema (delete arquivo ----.txt)
							system("rename ChacarasAlugados_novo.txt ChacarasAlugados.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema n�o achou nenhum dado a ser exclu�do, portanto nada foi feito)
							{ 
								printf("Erro! ID informado n�o existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Opera��o: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usu�rio 
								//L� o valor inserido e armazena na vari�vel op
								//pula 2 linhas
								
								if (op == 1)//se op for igual a 1
								{
									goto r16;//v� para o ponto r16
								}	//se op for igual a 2, a verifica��o acontece e o sistema volta a tela inicial	
							}
	
							goto fim;//v� para o ponto fim
					
					case 4:	//se op = 4
							printf("::: Excluir terreno alugado :::\n\n");//exibe op��o escolhida pelo usu�rio anteriormente
							r17://Ponto usado em conjunto ao comando goto, usado posteriormente
							puts("Informe o ID do apartamento a ser exclu�do: "); printf("Opera��o: "); scanf("%i", &id); puts(""); //pede ao usu�rio que digite o id do im�vel que deseja excluir
							
							Ponteiro = fopen("TerrenosAlugados.txt", "r");// vari�vel Ponteiro � igual a Abra("---.txt", "modo leitura");
							PonteiroNovo = fopen("TerrenosAlugados_Novo.txt", "w");// vari�vel PonteiroNovo � igual a Abra("---.txt", "modo escrita");
							
							while(!feof(Ponteiro))//enquanto (o sistema n�o chegar ao fim do arquivo (leia as informa��es contidas Ponteiro);
							{
					
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n",&Info2.numero_do_cracha, &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
								// L� as informa��es contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informa��o a ser exclu�da)
								{
									vf = 1;//vf recebe 1 
								}
								if(id != Info.ID)// se Info.ID for diferente da var�vel id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info2.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informa��es contidas no arquivo " Ponteiro)
								}						  
							}
							fclose(PonteiroNovo);// fechar o uso do arquivo
							fclose(Ponteiro);// fechar o uso do arquivo
							system("del TerrenosAlugados.txt");//sistema (delete arquivo ----.txt)
							system("rename TerrenosAlugados_novo.txt TerrenosAlugados.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema n�o achou nenhum dado a ser exclu�do, portanto nada foi feito)
							{ 
								printf("Erro! ID informado n�o existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Opera��o: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usu�rio 
								//L� o valor inserido e armazena na vari�vel op
								//pula 2 linhas
								if (op == 1)//se op for igual a 1
								{
									goto r17;//v� para o ponto r17
								}	//se op for igual a 2, a verifica��o acontece e o sistema volta a tela inicial
							}
	
							goto fim;//v� para o ponto fim
					
					default://se nenhum dos case foi compat�vel
							goto fim;	//v� para o ponto fim
															
				}
		
		default://se nenhum dos case foi compat�vel, v� para o ponto fim
				return 0;	
				
	}//Switch fim para im�veis � venda
	fim://Ponto usado em conjunto ao comando goto, usado previamente
	system("cls");//limpa a tela
	printf("Fim da exclus�o!\n\n");//coloque na tela("------");
}//Fun��o Fim



int main()
{
	setlocale(LC_ALL, "Portuguese");
	 

    
	int operacao = -1; // cria uma vari�vel do tipo inteiro com valor -1. o valor servir� para dar entrada no loop

	int i = login(i); // cria uma vari�vel do tipo inteiro de nome i que ser� igual ao resultado das opera��es				
				     // descritas na fun��o login(i);			
	
	system("cls"); //limpa a tela
	
	if (i == 0) // se (i for igual a 0)
	{
		return 0; //significa que o usu�rio desistiu de fazer login, e pediu para fechar o programa, sendo assim, o programa fecha.
				
	}

	while (operacao < 8) // cria um loop. enquanto(operacao for < 8) ele executa o corpo principal
	{	
		puts("::: Menu Principal :::\n\n");
		puts("<1> ::: Cadastrar Im�vel"); 
		puts("<2> ::: Cadastrar Corretor"); 
		puts("<3> ::: Simula��o Financiamento");
		puts("<4> ::: Listar registrados");
		puts("<5> ::: Vender Imovel");
		puts("<6> ::: Alugar Im�vel");
		puts("<7> ::: Apagar Registros");
		puts("<8+> ::: Sair");
		//Lista um menu e pede para o usu�rio digitar uma das op��es
		printf("Opera��o: ");
	
		scanf("%i", &operacao); puts("");    //leia ("valor inteiro", e coloque na vari�vel operacao), que serve 
											//justamente para a compara��o do while. 
		system("cls");	
		
		switch (operacao) //Compare (operacao)
		{
			case 1: //caso operacao seja igual a 1:     
			
				printf ("::: Cadastrar Im�vel :::\n\n"); //coloque na tela("::: Cadastrar Im�vel ::: \quebra de linha\quebra de linha");
			
				Imovel();  //chama a fun��o Imovel();
			
				break;	//ap�s feita a opera��o, o programa sai do switch com o comando break;	O mesmo processo se repete nas linhas abaixo.
			case 2: 
				
				corretor();			
				break;
			case 3:
				printf("::: Simula��o Financiamento :::\n\n");
				SimulacaoFinanciamento();
				break;
			case 4:
				printf("::: Listar Registrados :::\n\n");
				printf("<1> ::: Im�veis p. Venda\n<2> ::: Imoveis p. Aluguel\n<3> ::: Corretores\n<4+> ::: Sair\nOpera��o: "); 
				// pede para o usu�rio digitar qual tipo im�vel deseja listar. 
			
				scanf("%i", &operacao); //l� e armazena na vari�vel operacao
			
				system("cls"); //sistema ("limpa a tela");
			
				switch(operacao) //compare(operacao)
				{
					case 1: //caso operacao seja igual a 1. OBS: mesma l�gica aplicada nas linhas abaixo.
			
						ListagemVendas(); // chama a fun��o listagemVendas();
						break;
					case 2: 
						listaraluguel();
						break;
					case 3:
						listarcorretores();
						break;
					default: //se o switch comparou opercao com todos os case e nenhum foi compat�vel, ele vem at� o comando default
			
						break;	//e sai da opera��o 
				}
				break;
				
			case 5:
				printf("::: Venda de Im�veis :::\n\n");
				venda_imovel();
				break;
			case 6:
				printf("::: Aluguel de Im�veis :::\n\n");
				alugar_imovel();
				break;
			case 7:
				printf("::: Exclus�o de registros :::\n\n");
				excluir_registros();
				break;
			default:
				break;
		}
	printf("Pressione uma tecla para continuar:\n\n "); //Independente da opera��o requerida esta mensagem aparece e pede ao usu�rio para pressionar uma tecla
	getch(); //pegue(caractere digitado) e retorne ao sistema
	system("cls"); //limpa a tela
	} //Aqui o loop retorna at� o while na linha 2629. se operacao for menor que 8 o programa
	 //deve repetir todo o processo descrito at� aqui. se operacao for 8 ou maior o programa 
	//sai do loop e encerra o programa.
	return 0; //encerra as opera��es
}//Fim do corpo principal do programa
