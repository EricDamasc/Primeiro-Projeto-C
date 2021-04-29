#include <stdio.h> 				//
#include <stdlib.h>				//
#include <locale.h>				//chamada de bibliotecas
#include <conio.h>				//				
#include <time.h>				//
#include <math.h>				//

FILE* Ponteiro; //cria uma variável global do tipo FILE de nome ponteiro

typedef struct { //Cria um novo tipo (que são a classe a qual pertence determinada variável. Inteiro, Caracteres e reais são exemplos)
	int Qtd_Dormitorio, Qtd_Suite, Qtd_Sala, Qtd_Sala_de_Estar, ID, Qtd_Cozinha, Qtd_Banheiro, andar;
	//o novo tipo possuirá variáveis do tipo inteiro 
	char infraestrutura[1000], Area_de_Lazer[4], endereco[200], n_telefone[15];
	//do tipo caracteres
	float valor_do_imovel, Area_do_terreno, Area_construida_total;  
	//do tipo real
}Ficha_Tecnica_Imovel; //e irá se chamar Ficha_Tecnica_Imovel

typedef struct { //Cria um novo tipo (que são a classe a qual pertence determinada variável. Inteiro, Caracteres e reais são exemplos)
	char nome[200], data_contratacao[14], data_nascimento[14], senha[12];
	//do tipo caracteres
	int idade, imoveis_vendidos, numero_do_cracha;
	//o novo tipo possuirá variáveis do tipo inteiro 
	float salario_b, comissao_pvenda, salario_l;
	//do tipo real
}Corretor; //e irá se chamar Corretor

void alugar_imovel() //cria uma função de nome alugar_imovel que irá alugar imóveis cadastrados para aluguel
{
			int op, cracha, id = 0, vf = 0; //cria variáveis do tipo inteiro que servirão de parâmetros de comparação futuramente
			
			Ficha_Tecnica_Imovel Info; //cria uma variável do tipo Ficha_Tecnica_Imovel
			
			Corretor Info2, Info3;  //cria variáveis do tipo Corretor de nome Info2;
			
			FILE* Ponteiro; //cria uma variável do tipo FILE —que possibilita a manipulação de arquivos— de nome Ponteiro;
			FILE* PonteiroNovo; //idem acima
			FILE* PonteiroNovo2; //idem acima
			
			
			
			puts("<1> :::  Apartamentos");
			puts("<2> :::  Casas");
			puts("<3> :::  Chácaras");
			puts("<4> :::  Terrenos");
			puts("<5+> ::: Sair"); printf("Operação: "); scanf("%i", &op); puts("");
			//exibe um menu e pergunta qual operação deseja fazer —Neste caso, que imóvel deseja alugar
			//lê o valor digitado e armazena na variável op
			
			system("cls");
			//Limpa a tela 
			
			switch (op) //compare (variável op)
			{
				case 1: // se variável op for igual a 1
				
					printf("::: Alugar Apartamentos :::\n\n");
					printf("<1> ::: Listar Apartamento disponíveis para Aluguel:\n<2> ::: Continuar sem listar\n "); printf("Operação: "); scanf("%i", &op); puts("\n");
					//Exibe a opção que foi escolhida no menu anterior e pergunta se o usuário
					//deseja ver os apartamentos disponíveis para aluguel
					//deseja continuar sem lista
					//lê o valor digitado e armazena na variável op
					
					if(op == 1) // se op for igual a 1
					{
						system("cls"); // limpa a tela
						
						Ponteiro = fopen("AlugarApartamentos.txt", "r");  //Variável Ponteiro = Abra ("AlugarApartamentos.txt", "no modo de leitura de informações"); 
						
						while (!feof(Ponteiro)) //enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em("AlugarApartamentos.txt"));
						{
			
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
							// Lê as informações contidas no arquivo 
							
							printf("ID: %i \n", Info.ID);												
							printf("Andar: %i\n", Info.andar);														
							printf("Quantidade de Dormitório(s): %i \n", Info.Qtd_Dormitorio);   		
							printf("Quantidade de Suíte(s): %i \n", Info.Qtd_Suite);					
							printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);						
							printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);	    
							printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);				
							printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);				//   EXIBE TODAS AS INFORMAÇÔES SOBRE TODOS OS APARTAMENTOS REGISTRADOS E DISPONÍVEIS
							ColocarEspaco(Info.infraestrutura);											// 	 PARA ALUGUEL
							printf("Informações da Infraestrutura: %s \n", Info.infraestrutura);			 
							ColocarEspaco(Info.endereco);												 	
							printf("Endereço: %s \n", Info.endereco);									
							printf("Possui área de lazer?: %s\n", Info.Area_de_Lazer);					
							printf("Área total: %.2f\n", Info.Area_do_terreno);							
							printf("Terreno total construído: %.2f\n", Info.Area_construida_total);			
							printf("Valor do Imóvel: %.2f\n", Info.valor_do_imovel);					
							printf("Nº de telefone: %s\n\n", Info.n_telefone);							
		 			 }
		  			 fclose(Ponteiro);  //feche (AlugarApartamentos.txt);
		  			 printf("Listagem concluída!\n\n"); //Coloque em tela("Listagem concluída");
				}

		
				cracha:    //Ponto usado em conjunto ao comando goto, usado posteriormente
				
				PonteiroNovo = fopen("Corretores.txt", "r");  // variável PonteiroNovo é igual a Abra("Corretores.txt", "modo leitura");
				
				Info3.numero_do_cracha = 0;  //variável Info3.numero_do_crachá recebe 0 como valor
				
				printf("Por favor informe o crachá: "); scanf("%i", &cracha); puts(""); //pede ao usuário que informe seu crachá, Lê e armazena na variável cracha
				
				while(!feof(PonteiroNovo)) //enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "Corretores.txt");
				{
				
					fscanf(PonteiroNovo, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);		
					// Lê as informações contidas no arquivo 
					
					if(Info2.numero_do_cracha == cracha) 		// Aqui ocorre o teste condicional. Previamente definimos a variável Info3.numero_do_crachá como 0
					{											// Se (variável Info2.numero_do_cracha for igual a variável cracha) 	
						Info3.numero_do_cracha = cracha;		// Info3.numero_do_crachá recebe o valor da variável crachá. Sendo assim, se não houver nenhum 
					}											// crachá registrado igual ao crachá informado, será emitida uma mensagem de erro.
				
				} //fim do laço de repetição
				
				fclose(PonteiroNovo); //feche(Corretores.txt);
				
				if (Info3.numero_do_cracha == 0)  //se (Info3.numero_do_cracha for igual a 0) significa que o crachá informado não foi encontrado
				{
					printf("Crachá não existe/não registrado!\n\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o crachá não existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// lê o valor e armazena na variável op
					
					if (op == 1) //se op for igual a 1
					{
						goto cracha; //volta no ponto cracha, definido previamente na linha 100
					} 
					else //se não
					{
						goto fim; // vai até o ponto fim, definido posteriormente na linha 
					}
				} //fim da comparação 
				
				
				

				id: 	//Ponto usado em conjunto ao comando goto, usado posteriormente
				
				printf("Digite o ID do apartamento: "); scanf("%i", &id); puts("\n"); //pede ao usuário que informe seu id, lê e armazena na variável id
				
				Ponteiro = fopen("AlugarApartamentos.txt", "r"); // variável PonteiroNovo é igual a Abra("AlugarApartamentos.txt", "modo leitura");
				
				while(!feof(Ponteiro)) //enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "AlugarApartamentos.txt");
				{
																
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// Lê as informações contidas no arquivo "Corretores.txt"
									
					if(id == Info.ID) // se Info.ID for igual a varável id (Se algum ID no arquivo "AlugarApartamentos.txt" for igual ao id informado para aluguel
					{
						vf = 1; //vf é igual a 1 (servirá para comparação posteriormente)
						
						PonteiroNovo2 = fopen("ApartamentosAlugados.txt", "a+"); // variável PonteiroNovo2 é igual a Abra("ApartamentosAlugados.txt", "modo escrita");
						
						fprintf(PonteiroNovo2, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info3.numero_do_cracha, Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);					
						//insira no arquivo(ApartamentosAlugados.txt, "as informações contidas no arquivo "AlugarApartamentos + o crachá
						// do corretor responsável por intermediar a operação.
						
						fclose(PonteiroNovo2); //fecha (ApartamentosAlugados.txt)
					}
				
				}
				fclose(Ponteiro); //fecha (AlugarApartamentos.txt)
				
				
				//vf foi definido previamente como 0.
				if (vf == 0) //se (vf for igual a 0) significa que o id informado não foi encontrado
				{			
					printf("ID não existe/não registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o id não existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// lê o valor e armazena na variável op
					
					if (op == 1) //se op for igual a 1
					{
						goto id; //volta no ponto id, definido previamente na linha 144
					} 
					else //se não
					{
						goto fim; // vai até o ponto fim, definido posteriormente na linha 
					}
				}//fim da comparação 
				
				
					
				
				Ponteiro = fopen("AlugarApartamentos.txt","r");  // variável Ponteiro é igual a Abra("AlugarApartamentos.txt", "modo leitura");
				FILE* PonteiroNovo = fopen("AlugarApartamentos_novo.txt", "w"); // variável PonteiroNovo é igual a Abra("AlugarApartamentos_novo.txt", "modo escrita");
						
						while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "AlugarApartamentos.txt");
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 
							// Lê as informações contidas no arquivo "AlugarApartamentos.txt.txt"
							
							if (Info.ID != id) // se Info.ID for diferente da varável id (Se algum ID no arquivo "AlugarApartamentos.txt" for diferente do id informado para aluguel
							{	
								fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
								//insira no arquivo(AlugarApartamentos_novo.txt, "as informações contidas no arquivo "AlugarApartamentos)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del AlugarApartamentos.txt"); //sistema (delete AlugarApartamentos.txt)
						system("rename AlugarApartamentos_novo.txt AlugarApartamentos.txt"); //sistema (renomeie AlugarApartamentos_novo.txt com o nome AlugarApartamentos.txt)
						break; //fim do primeiro case		
			
			
			case 2:
					printf("::: Alugar Casas :::\n\n");
					printf("<1> ::: Listar Casas disponíveis para aluguel:\n<2> ::: Continuar sem listar\n "); printf("Operação: "); scanf("%i", &op); puts("/n"); system("cls");
					//Exibe a opção que foi escolhida no menu anterior e pergunta se o usuário
					//deseja ver os casas disponíveis para aluguel
					//deseja continuar sem lista
					//lê o valor digitado e armazena na variável op
					
					if(op == 1) // se op for igual a 1
					{
						system("cls"); // limpa a tela
					
						Ponteiro = fopen("AlugarCasa.txt", "r"); //Variável Ponteiro = Abra ("AlugarCasa.txt", "no modo de leitura de informações"); 
						
						while (!feof(Ponteiro)) //enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em("AlugarCasa.txt"));
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
							// Lê as informações contidas no arquivo 
							
							printf("ID: %i \n", Info.ID);
							printf("Quantidade de Dormitório(s): %i \n", Info.Qtd_Dormitorio);
							printf("Quantidade de Suíte(s): %i \n", Info.Qtd_Suite);
							printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
							printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
							printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
							printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
							ColocarEspaco(Info.infraestrutura);												//EXIBE TODAS AS INFORMAÇÔES SOBRE TODOS AS CASAS REGISTRADOS E DISPONÍVEIS
							printf("Informações da Infraestrutura: %s \n", Info.infraestrutura);			//PARA ALUGUEL
							ColocarEspaco(Info.endereco);
							printf("Endereço: %s \n", Info.endereco);
							printf("Possui área de lazer?: %s\n", Info.Area_de_Lazer);
							printf("Área total: %.2f\n", Info.Area_do_terreno);
							printf("Terreno total construído: %.2f\n", Info.Area_construida_total);
							printf("Valor do Imóvel: %.2f\n", Info.valor_do_imovel);	
							printf("Nº de telefone: %s\n\n", Info.n_telefone);
		 			 }
		  			 fclose(Ponteiro); //feche (AlugarCasa.txt);
		  			 printf("Listagem concluída!\n\n"); //Coloque em tela("Listagem concluída");
				}

			
				Info3.numero_do_cracha = 0; //variável Info3.numero_do_crachá recebe 0 como valor

				
				cracha_2: //Ponto usado em conjunto ao comando goto, usado posteriormente
				
				PonteiroNovo = fopen("Corretores.txt", "r"); // variável PonteiroNovo é igual a Abra("Corretores.txt", "modo leitura");
				
				printf("Por favor informe o crachá: "); scanf("%i", &cracha); puts(""); //pede ao usuário que informe seu crachá, Lê e armazena na variável cracha
				
				while(!feof(PonteiroNovo))	//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "Corretores.txt");
				{
				
					fscanf(PonteiroNovo, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);		
					// Lê as informações contidas no arquivo 
					
					//Previamente definimos a variável Info3.numero_do_cracha como 0
					
					if(Info2.numero_do_cracha == cracha)// Se (variável Info2.numero_do_cracha for igual a variável cracha)
					{										
						Info3.numero_do_cracha = cracha;  // Info3.numero_do_crachá recebe o valor da variável crachá. 
					}
				}//fim do laço de repetição
				
				fclose(PonteiroNovo); //feche(Corretores.txt);
				
				if (Info3.numero_do_cracha == 0)//se (Info3.numero_do_cracha for igual a 0) significa que o crachá informado não foi encontrado
				{
					printf("Crachá não existe/não registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o crachá não existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// lê o valor e armazena na variável op
					
					if (op == 1) //se op for igual a 1
					{
						goto cracha_2;  //volta no ponto cracha, definido previamente na linha 100
					} 
					else //se não 
					{
						goto fim; // vai até o ponto fim, definido posteriormente na linha 657
					}
				} //fim da comparação
				
				
				

				id_2://Ponto usado em conjunto ao comando goto, usado posteriormente
				printf("Digite o ID do apartamento: "); scanf("%i", &id); puts("\n");//pede ao usuário que informe seu id, lê e armazena na variável id
				
				Ponteiro = fopen("AlugarCasa.txt", "r");
				// variável Ponteiro é igual a Abra("AlugarCasa.txt", "modo leitura");
				
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "AlugarCasa.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// Lê as informações contidas no arquivo 
					
					if(id == Info.ID)// se Info.ID for igual a varável id (Se algum ID no arquivo for igual ao id informado para aluguel
					{	
						vf = 1;//vf é igual a 1 (servirá para comparação posteriormente)
						PonteiroNovo2 = fopen("CasaAlugados.txt", "a+");
						fprintf(PonteiroNovo2, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info3.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
						//insira no arquivo(ApartamentosAlugados.txt, "as informações contidas no arquivo "AlugarApartamentos + o crachá
				//do corretor responsável por intermediar a operação.
						
						fclose(PonteiroNovo2);
						//fecha (ApartamentosAlugados.txt)
					}	
				}
				fclose(Ponteiro);//fecha (AlugarApartamentos.txt)
				
				
				if (vf == 0)//se (vf for igual a 0) significa que o id informado não foi encontrado
				{
					printf("ID não existe/não registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o id não existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// lê o valor e armazena na variável op
					
					if (op == 1)//se op for igual a 1
					{
						goto id_2; //volta no ponto id, definido previamente na linha 144
					} 
					else //se não
					{
						goto fim; // vai até o ponto fim, definido posteriormente na linha 657
					}
				} //fim da comparação
				
					
				
				Ponteiro = fopen("AlugarCasa.txt","r"); // variável Ponteiro é igual a Abra("AlugarCasa.txt", "modo leitura");
				PonteiroNovo = fopen("AlugarCasa_novo.txt", "w"); // variável PonteiroNovo é igual a Abra("AlugarCasa_novo.txt", "modo escrita");
						
						while(!feof(Ponteiro)) //enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "AlugarCasa.txt");
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 
							// Lê as informações contidas no arquivo 
							
							if (Info.ID != id) // se Info.ID for diferente da varável id (Se algum ID no arquivo for diferente do id informado para aluguel
							{	
								fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
								//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del AlugarCasa.txt"); //sistema (delete arquivo ----.txt)
						system("rename AlugarCasa_novo.txt AlugarCasa.txt");//sistema (renomeie ----.txt para ---.txt)
						break;//fim do segundo case
						
			case 3:
					printf("::: Alugar Chácaras :::\n\n");
					printf("<1> ::: Listar Chácaras disponíveis para aluguel:\n<2> ::: Continuar sem listar\n "); printf("Operação: "); scanf("%i", &op); puts("/n"); system("cls");
					//Exibe a opção que foi escolhida no menu anterior e pergunta se o usuário
					//deseja ver os chácaras disponíveis para aluguel
					//deseja continuar sem lista
					//lê o valor digitado e armazena na variável op
					
					if(op == 1) // se op for igual a 1
					{
						system("cls"); // limpa a tela
					
						Ponteiro = fopen("AlugarChacaras.txt", "r"); //Variável Ponteiro = Abra ("AlugarChacaras.txt", "no modo de leitura de informações"); 
						
						while (!feof(Ponteiro)) //enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em("AlugarChacaras.txt"));
						{
							
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
							// Lê as informações contidas no arquivo 
							
							printf("ID: %i \n", Info.ID);
							printf("Quantidade de Dormitório(s): %i \n", Info.Qtd_Dormitorio);
							printf("Quantidade de Suíte(s): %i \n", Info.Qtd_Suite);
							printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
							printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
							printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
							printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
							ColocarEspaco(Info.infraestrutura);
							printf("Informações da Infraestrutura: %s \n", Info.infraestrutura); 	//   EXIBE TODAS AS INFORMAÇÔES SOBRE TODOS OS APARTAMENTOS REGISTRADOS E DISPONÍVEIS PARA ALUGUEL
							ColocarEspaco(Info.endereco);
							printf("Endereço: %s \n", Info.endereco);
							printf("Possui área de lazer?: %s\n", Info.Area_de_Lazer);
							printf("Área total: %.2f\n", Info.Area_do_terreno);
							printf("Terreno total construído: %.2f\n", Info.Area_construida_total);
							printf("Valor do Imóvel: %.2f\n", Info.valor_do_imovel);	
							ColocarEspaco(Info.n_telefone);
							printf("nº de telefone: %s\n", Info.n_telefone);
		 			 }
		  			 fclose(Ponteiro);	//feche (---.txt);
		  			 printf("Listagem concluída!\n\n");	//Coloque em tela("Listagem concluída");
				}


				cracha_3: //Ponto usado em conjunto ao comando goto, usado posteriormente
				
				PonteiroNovo = fopen("Corretores.txt", "r");
				
				printf("Por favor informe o crachá: "); scanf("%i", &cracha); puts("");
				
				while(!feof(PonteiroNovo))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
				{
				
					fscanf(PonteiroNovo, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);		
					// Lê as informações contidas no arquivo 
					
					//Previamente definimos a variável Info3.numero_do_cracha como 0
					if(Info2.numero_do_cracha == cracha) // Se (variável Info2.numero_do_cracha for igual a variável cracha) 
 	
					{
						Info3.numero_do_cracha = cracha; // Info3.numero_do_crachá recebe o valor da variável crachá.  
					}
				}//fim do laço de repetição
				fclose(PonteiroNovo);//feche(----.txt);
				
				if (Info3.numero_do_cracha == 0)//se (Info3.numero_do_cracha for igual a 0) significa que o crachá informado não foi encontrado
				{
					printf("Crachá não existe/não registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o crachá não existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// lê o valor e armazena na variável op			
					
					if (op == 1)//se op for igual a 1
					{
						goto cracha_3;//volta no ponto cracha, definido previamente na linha 100
					} 
					else//se não
					{
						goto fim;// vai até o ponto fim, definido posteriormente na linha 657
					}
				}//fim da comparação 
				
				
				

				id_3://Ponto usado em conjunto ao comando goto, usado posteriormente
				printf("Digite o ID da Chácara: "); scanf("%i", &id); puts("\n"); //pede ao usuário que informe seu id, lê e armazena na variável id
				
				Ponteiro = fopen("AlugarChacaras.txt", "r");// variável Ponteiro é igual a Abra("----.txt", "modo leitura");
				
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em Ponteiro);
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// Lê as informações contidas no arquivo
					if(id == Info.ID)// se Info.ID for igual a varável id (Se algum ID no arquivo for igual ao id informado para aluguel)
					{
						vf = 1;//vf é igual a 1 (servirá para comparação posteriormente)
						PonteiroNovo2 = fopen("ChacarasAlugados.txt", "a+"); // variável PonteiroNovo2 é igual a Abra("----.txt", "modo escrita");
						fprintf(PonteiroNovo2, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info3.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
						//insira no arquivo(PonteiroNovo2, "as informações contidas em Ponteiro + o número do crachá do corretor intermediário da operação

						fclose(PonteiroNovo2);//fecha (PonteiroNovo2)
						
					}	
				}
				fclose(Ponteiro);//fecha (Ponteiro)
				
				//vf foi definido previamente como 0.
				if (vf == 0)//se (vf for igual a 0) significa que o id informado não foi encontrado
				{
					printf("ID não existe/não registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o id não existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// lê o valor e armazena na variável op
					
					if (op == 1)//se op for igual a 1
					{
						goto id_3;//volta no ponto id, definido previamente na linha 144
					} 
					else//se não
					{
						goto fim;// vai até o ponto fim, definido posteriormente na linha 657
					}
				}//fim da comparação 
				
				
					
				
				Ponteiro = fopen("AlugarChacaras.txt","r"); // variável Ponteiro é igual a Abra("---.txt", "modo leitura");
				PonteiroNovo = fopen("AlugarChacaras_novo.txt", "w"); // variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
						
						while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 							 //acessar os d    "%i %i %i %i %i %i %i %i %s %s %s %f %f %f\n"
							// Lê as informações contidas no arquivo
							
							if (Info.ID != id) // se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{	
								fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
								//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del AlugarChacaras.txt");//sistema (delete arquivo ----.txt)
						system("rename AlugarChacaras_novo.txt AlugarChacaras.txt");//sistema (renomeie ----.txt para ---.txt)
						break;	//fim do terceiro case

			case 4:
					printf("::: Alugar Terrenos :::\n\n");
					printf("<1> ::: Listar Terrenos disponíveis para aluguel:\n<2> ::: Continuar sem listar\n "); printf("Operação: "); scanf("%i", &op); puts("/n"); system("cls");
					//Exibe a opção que foi escolhida no menu anterior e pergunta se o usuário
					//deseja ver os Terrenos disponíveis para aluguel
					//deseja continuar sem lista
					//lê o valor digitado e armazena na variável op
					
					if(op == 1) // se op for igual a 1
					{
						system("cls"); // limpa a tela
					
						Ponteiro = fopen("AlugarTerrenos.txt", "r"); //Variável Ponteiro = Abra ("AlugarTerenos.txt", "no modo de leitura de informações"); 
					
						while (!feof(Ponteiro)) //enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em("AlugarTerenos.txt"));
						{
			
						    fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
							// Lê as informações contidas no arquivo 
							
							printf("ID: %i \n", Info.ID);
							printf("Área total: %.2f\n", Info.Area_do_terreno);
							printf("Valor do Imóvel: %.2f\n", Info.valor_do_imovel);//   EXIBE TODAS AS INFORMAÇÔES SOBRE TODOS OS TERRENOS REGISTRADOS E DISPONÍVEIS PARA ALUGUEL
							printf("Endereço: %s\n\n", Info.endereco);	
							printf("nº de telefone: %s", Info.n_telefone);
		 			 	}
		  			 	fclose(Ponteiro);//feche (---.txt);
		  				 printf("Listagem concluída!\n\n");//Coloque em tela("Listagem concluída");
					}


		
				
				cracha_4://Ponto usado em conjunto ao comando goto, usado posteriormente
				Info3.numero_do_cracha = 0;//variável Info3.numero_do_cracha recebe 0 como valor
				PonteiroNovo = fopen("Corretores.txt", "r");// variável PonteiroNovo é igual a Abra("---.txt", "modo leitura");
				
				printf("Por favor informe o crachá: "); scanf("%i", &cracha); puts("");//pede ao usuário que informe seu crachá, Lê e armazena na variável cracha
			
				while(!feof(PonteiroNovo))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
				{
				
					fscanf(PonteiroNovo, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);		
					// Lê as informações contidas no arquivo 
					
					//Previamente definimos a variável Info3.numero_do_cracha como 0
					if(Info2.numero_do_cracha == cracha)// Se (variável Info2.numero_do_cracha for igual a variável cracha) 	
					{
						Info3.numero_do_cracha = cracha;// Info3.numero_do_crachá recebe o valor da variável crachá.
					}
				}//fim do laço de repetição
				fclose(PonteiroNovo);//feche(----.txt);
				
				if (Info3.numero_do_cracha == 0)//se (Info3.numero_do_cracha for igual a 0) significa que o crachá informado não foi encontrado
				{
					printf("Crachá não existe/não registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o crachá não existe e o questiona 
					// tentar novamente 
					// sair 2+
					// lê o valor e armazena na variável op					
					
					if (op == 1)//se op for igual a 1
					{
						goto cracha_4; //volta no ponto cracha, definido previamente na linha 100
					} 
					else//se não
					{
						goto fim;// vai até o ponto fim, definido posteriormente na linha 657
					}
				}//fim da comparação 
				
				
				

				id_4://Ponto usado em conjunto ao comando goto, usado posteriormente
				printf("Digite o ID do apartamento: "); scanf("%i", &id); puts(""); //pede ao usuário que informe seu id, lê e armazena na variável id
				Ponteiro = fopen("AlugarTerrenos.txt", "r");// variável Ponteiro é igual a Abra("----.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em Ponteiro);
				{
					fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
					// Lê as informações contidas no arquivo
					if(id == Info.ID)// se Info.ID for igual a varável id (Se algum ID no arquivo for igual ao id informado para aluguel)
					{
						vf = 1;//vf é igual a 1 (servirá para comparação posteriormente)
						PonteiroNovo2 = fopen("TerrenosAlugados.txt", "a+");// variável PonteiroNovo2 é igual a Abra("----.txt", "modo leitura");
						fprintf(PonteiroNovo2, "%i %i %f %f %s %s\n", Info.ID, Info3.numero_do_cracha, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);
						//insira no arquivo(PonteiroNovo2, "as informações contidas em Ponteiro + o número do crachá do corretor intermediário da operação
						fclose(PonteiroNovo2);
						//fecha (PonteiroNovo2)
					}	
				}
				fclose(Ponteiro);	//fecha (Ponteiro)
				
				//vf foi definido previamente como 0.
				if (vf == 0)//se (vf for igual a 0) significa que o id informado não foi encontrado
				{
					printf("ID não existe/não registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o id não existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// lê o valor e armazena na variável op
					
					if (op == 1)//se op for igual a 1
					{
						goto id_4;//volta no ponto id, definido previamente na linha 144
					} 
					else//se não
					{
						goto fim;// vai até o ponto fim, definido posteriormente na linha 657
					}
				}//fim da comparação 

				
				Ponteiro = fopen("AlugarTerrenos.txt","r"); // variável Ponteiro é igual a Abra("---.txt", "modo leitura");
				PonteiroNovo = fopen("AlugarTerrenos_novo.txt", "w"); // variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
						
						while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
						{
							fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
							// Lê as informações contidas no arquivo
							if (Info.ID != id) // se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{	
								fprintf(PonteiroNovo, "%i %f %f %s\n", Info.ID, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);
								//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del AlugarTerrenos.txt");//sistema (delete arquivo ----.txt)
						system("rename AlugarTerrenos_novo.txt AlugarTerrenos.txt");//sistema (renomeie ----.txt para ---.txt)
						break;		//fim do quarto case				
			default: //se nenhum case correspondeu a o número informado pelo usuário significa que ele deseja sair da tela.
					//default é a opção que o programa escolhe quando todas os case foram testados e nenhum correspondeu	
				break;
				
			}// Fim switch
			fim:		//Ponto usado em conjunto ao comando goto, usado previamente
		printf("Operação Finalizada!\n\n"); //coloque em tela ("---------");
}

int login(int x)//cria uma função do tipo inteiro de nome login(que irá receber uma variável do tipo inteiro e retornar um valor a ela)
{
	Corretor Info; //Cria uma variável do tipo Corretor de nome info
	char senha[12]; // cria uma variável do tipo caracteres de nome senha[com 12 espaços]
	int cracha, op = -1, op2 = 0, vf; //cria variáveis do tipo inteiro de nomes cracha, op com valor -1, op2 com valor 0, e vf;
	FILE* Ponteiro; //cria uma variável do tipo FILE de nome Ponteiro —O tipo file permite ao usuário manipular arquivos

	inicio: //Ponto usado em conjunto ao comando goto, usado posteriormente
	system("cls"); //limpa a tela
	puts("<1> ::: Login"); 
	puts("<2> ::: Cadastrar");
	puts("<3+> ::: Sair");
	printf("Operação: "); scanf("%i", &op); puts("");
	// o sistema exibe um menu pedindo que o usuário informe:
	// se deseja fazer login 
	// se deseja cadastrar corretor
	//Lê o valor digitado e armazena na variável op
	
	system("cls"); //limpa tela
	
	switch(op)//compare (variável op)
	{
		case 1: //se variável op = 1
			puts("\n::: Login :::\n\n"); //coloque em tela ("----------"); OBS: \n serve para quebrar linha e puts é uma função que coloca uma string em tela
		
			 
			printf("Crachá: "); scanf("%i", &cracha); puts("");//Lê o valor digitado e armazena na variável cracha
		
			Ponteiro = fopen("Corretores.txt", "r");//Variável Ponteiro = Abra ("-----.txt", "no modo de leitura de informações"); 
			
		
			
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em(Ponteiro));
				{
					fscanf(Ponteiro, "%i %s %s %s %i %f %f\n", &Info.numero_do_cracha, Info.nome, Info.data_contratacao, Info.data_nascimento, &Info.idade, &Info.salario_b, &Info.comissao_pvenda);
					// Lê as informações contidas no arquivo 
					
					if(cracha == Info.numero_do_cracha)// Se (variável cracha for igual a variável Info.numero_do_cracha ) 	
					{
						op2 = 1; //variável op2 recebe 1		
					}	//fim da comparação	
					
				}
				
			fclose(Ponteiro); //fecha(----.txt)
			
			if (op2 == 0)
			{
				printf("Crachá não registrado\n\nTentar Novamente?\n\n<1> ::: Sim\n<2> ::: Não\n\n");
				puts("Operação: "); scanf("%i", &op); puts("\n");
				// o sistema exibe uma mensagem informando que o crachá não está cadastrado e o questiona 
				// tentar novamente 
				// sair 2+
				// lê o valor e armazena na variável op
				
				if (op == 1)//se op = 1
				{
					system("cls"); //limpa tela
					goto inicio; //volta no ponto início —linha 669
				}
				else//se não
				{
					return op2; //retorne op2. O valor de op2 servirá como parâmetro para comparação do sucesso ou não do login —o comando encerra o uso da função
				}
			} // fim da comparção
			break;//fim do case 1
		
		case 2://caso op = 2
			corretor(); //Chama função de cadastro de corretores —corretor()
			printf("Cadastro Concluído!\n\nPressione uma tecla para continuar: "); //coloque em tela ("------");
			getch(); //Lê a tecla e retorna para o sistema
			goto inicio; //volta para o ponto da linha 669
			break;//fim do case2
			
	}
	return op2; //retorna valor de op2.	
}

void listarcorretores ()//cria uma função do tipo vazio de nome listarcorretores()
{
	Corretor Info;  //Cria variável do tipo Corretor de nome Info
	printf("::: Listar Corretores :::\n\n");    //coloque em tela(" ------ ");
	Ponteiro = fopen("Corretores.txt", "r");   //Variável Ponteiro = abra("Corretores.txt", "em modo de leitura");
		
		while(!feof(Ponteiro))   //enquanto(todas as informações no arquivo não forem lidas(leia "Corretores.txt"));
		{
			if(Info.numero_do_cracha == NULL) //se (Info.numero_do_cracha for igual a NULO)
			{
				printf("Não existem registros!\n\n"); //significa que não há informações cadastradas
				return 0;
			} 
		
			fscanf(Ponteiro, "%i %s %s %s %i %f %f\n", &Info.numero_do_cracha, Info.nome, Info.data_contratacao, Info.data_nascimento, &Info.idade, &Info.salario_b, &Info.comissao_pvenda);
				//leia(as informações contidas em "Corretores.txt", "valor inteiro, string ...", contidas nas variáveis de nome, Info.numero_do_cracha...);
			   // É importante pontuar aqui que, a maneira que as informações são gravadas tem de ser em qualquer tipo de leitura das informações.
		  	  //  EX: Supondo que as informações foram gravadas assim: fprintf(Ponteiro, "%i\n", x); elas terão de ser lidas da mesma forma
		 	 //   ou seja: fscanf("Ponteiro, "%i\n", &x);
		
			printf("Crachá: %i\n", Info.numero_do_cracha);									   //
			ColocarEspaco(Info.nome);														  //		
			printf("Nome: %s\n", Info.nome);											     //	
			printf("Data de nascimento: %s\n", Info.data_nascimento);					 	// IMPRIME AS INFORMAÇÔES CONTIDAS
			printf("Data de Contratação: %s\n", Info.data_contratacao);					   // NO ARQUIVO "Corretores.txt"
			printf("Idade: %i\n", Info.idade);											  //
			printf("Salário Bruto: %0.2f\n", Info.salario_b);							 //
			printf("Comissão por venda: %0.2f\n\n", Info.comissao_pvenda);				//
		
		}   //Volta no loop —laço de repetição — até que todas as informações tenham sido lidas
		
		fclose(Ponteiro);   //Feche (---.txt)
		puts("Fim da listagem!\n\n"); //coloque em tela (" ---- ");
		return 0;						  
}

void TirarEspaco(char texto[]) //cria uma função de nome TirarEspaco(que irá receber uma variável do tipo caractere em matriz e irá retornar a mesma modificada)
{
	int i; //cria uma variável do tipo inteiro de nome i
    for (i=0;i<strlen(texto);i++) //para (i=0; enquanto i for menor que o tamanho(do texto enviado); i++)
    {
		if (texto[i]==' ')//se (texto(na posição x da matriz) for igual a um espaço
		{
			texto[i]='+'; //ele insere o sinal +
		}
	}//volta no loop até que se ache a última posição de texto
}//fim da função

void ColocarEspaco(char texto[])//cria uma função de nome TirarEspaco(que irá receber uma variável do tipo caractere em matriz e irá retornar a mesma modificada)
{
	int i;//cria uma variável do tipo inteiro de nome i
	for (i=0;i<strlen(texto);i++)//para (i=0; enquanto i for menor que o tamanho(do texto enviado); i++)
	{
		if (texto[i]=='+')//se (texto(na posição x da matriz) for igual a um +
		{
			texto[i]=' ';//ele insere um espaço
		}
	}//volta no loop até que se ache a última posição de texto
}//fim da função

void SimulacaoFinanciamento ()//cria uma função do tipo vazio de nome SimulacaoFinanciamento()
{
		int op;//cria uma vairável do tipo inteiro de nome op
		
		float juros=0, juros_c=0, saldo_devedor=0, amortizacao = 0, valor_parcela=0, valor_parcela_aux, tempo=0, parcela = 0;
		//cria variáveis do tiop real de nomes ...;	
		
		Ficha_Tecnica_Imovel Info; //cria uma variável do tipo Ficha_Tecnica_Imovel de nome Info


		puts("<1> ::: SAC");
		puts("<2> ::: PRICE");
		puts("<3+> ::: Sair");
		printf("Operação: "); scanf("%i", &op); puts("");
		system("cls");
		// o sistema exibe um menu questionando que operação o usuário deseja executar
		// 1 Tabela SAC
		// 2 TABELA PRICE
		//3+ Sair
		// lê o valor e armazena na variável op
		
		switch (op) //compare op
		{
			case 1: //caso op = 1
				printf("::: Financiamento SAC :::\n\n");//exibe a opção escolhida pelo usuário
				printf("Digite o valor do imóvel: "); //pede ao usuário que informe o valor do imóvel
				scanf("%f", &Info.valor_do_imovel);//Lê o valor e armazena na variável ----
				printf("Digite o juros: ");//pede ao usuário que informe a taxa de juros 
				scanf("%f", &juros);//Lê o valor e armazena na variável ----
				printf("Tempo em meses: ");//pede ao usuário que informe o tempo em meses
				scanf("%f", &tempo); puts("\n\n");//Lê o valor e armazena na variável ---- pula duas linhas
				
				juros = juros / 100; //transforma o número digitado em decimal
				amortizacao = Info.valor_do_imovel/tempo; //variável amortizacao é igual a divisão das variáveis --- / ---
				saldo_devedor = Info.valor_do_imovel; //variável saldo_devedor = ---

				printf(":Mês:\t:Amortizacao:\t:Juros:\t:Parcela:\t:Saldo:\n"); //exibe as guias da tabela
				printf(" %0.2f \t %0.2f \t%0.2f \t%0.2f   \t\t%0.2f\n", parcela, amortizacao, juros_c, valor_parcela, saldo_devedor); 
				//exibe a primeira linha (com quase todos os valores em 0
				
					while (parcela < tempo) //enquanto parcela —que é igual a 0— for menor que o tempo
					{
						saldo_devedor = saldo_devedor - amortizacao; //saldo_devedor = --- - ---;
						juros_c = juros * saldo_devedor; //juros_c = --- * ---;
						valor_parcela = juros_c + amortizacao; //valor_parcela = --- + ---;
						parcela = parcela + 1; //parcela recebe + 1;
						printf("%0.2f  \t%0.2f  \t%0.2f  \t%0.2f   \t%0.2f\n", parcela, amortizacao, juros_c, valor_parcela, saldo_devedor);
						//exibe os valores dos cálculos realizados
					}//volta no loop. quando parcela for igual a tempo, a execução para
				break;//saia do swich
			case 2:
				printf("::: Financiamento PRICE :::\n\n");//exibe a opção escolhida pelo usuário
				printf("Digite o valor: ");//pede ao usuário que informe o valor do imóvel
				scanf("%f", &Info.valor_do_imovel);//Lê o valor e armazena na variável ----
				printf("Digite o juros: ");//pede ao usuário que informe a taxa de juros 
				scanf("%f", &juros);//Lê o valor e armazena na variável ----
				printf("Tempo em meses: ");//pede ao usuário que informe o tempo em meses
				scanf("%f", &tempo); puts("\n\n");//Lê o valor e armazena na variável ----; pula duas linhas;
				
				juros = (juros / 100)+1; //juros = (--- / 100)+1;
				
				
				saldo_devedor = Info.valor_do_imovel; //saldo_devedor = ---;
				valor_parcela = (pow (juros, tempo)-1); //valor_parcela = (eleve (---- a ----)-1);
				valor_parcela_aux = pow (juros, tempo) * (juros - 1); //valor_parcela_aux = eleve (---- a ----) vezes (--- - 1);
				valor_parcela = (valor_parcela_aux / valor_parcela) * Info.valor_do_imovel; //valor_parcela = (---- / ----) vezes ----;
				juros = juros -1; //juros = --- - 1;
				saldo_devedor = Info.valor_do_imovel;//saldo_devedor = ----;
				
				printf(":Mês:\t:Amortizacao:\t:Juros:\t:Parcela:\t:Saldo:\n"); //exibe as guias da tabela
				printf(" %0.2f \t %0.2f \t\t%0.2f \t%0.2f  \t%0.2f\n", parcela, amortizacao, juros_c, valor_parcela, saldo_devedor);
				//exibe a primeira linha (com quase todos os valores em 0
					
					while (parcela < tempo)//enquanto parcela —que é igual a 0— for menor que o tempo
					{
						parcela = parcela + 1; //parcela recebe + 1;
						juros_c = juros * saldo_devedor; //juros_c = --- vezes ----;
						amortizacao = valor_parcela - juros_c;//amortizacao = --- menos ---;
						saldo_devedor = saldo_devedor - amortizacao;//saldo_vedor = --- - ---;
						printf(" %0.2f\t %0.2f \t%0.2f \t%0.2f \t\t%0.2f\n", parcela, amortizacao, juros_c, valor_parcela, saldo_devedor);
						//exibe os valores dos cálculos realizados
					}//volta no loop. quando parcela for igual a tempo, a execução para
			break;//saia do switch
			
			default://se nenhum dos case comparados deram certo
				 break;	//saia do switch
		}//fim do switch
	puts("\n");
	return 0; //retorne 0;
}


void ListagemVendas ()//cria uma função do tipo vazio de nome SimulacaoFinanciamento()
{
	int op; //cria uma variável do tipo inteiro de nome op
	Ficha_Tecnica_Imovel Info, Info2; //cria variáveis do tipo Ficha_Tecnica_Imovel de nomes ...;
	Corretor Info3;//Cria uma variável do tipo Corretor de nome Info3
	printf("::: Listagem de Cadastro dos Imóveis à venda :::\n\n");
	
	
	puts("<1> ::: Para listar Apartamentos");
	puts("<2> ::: Para listar casas");
	puts("<3> ::: Para listar chácaras");
	puts("<4> ::: Para listar Terrenos");
	puts("<5> ::: Para listar Imóveis Vendidos");
	puts("<6+> ::: Sair");
	printf("Operação: "); scanf("%i", &op); puts("");
	system("cls");
	//exibe um menu questionando que imóvel o usuário deseja listar
	//lê o valor e insere na variável op
	//quebra linha
	//limpa tela
	
	switch (op) //compare op
	{
		case 1: //se op = 1
		    printf("::: Listar Apartamentos :::\n\n"); //exibe a opção que o usuário digitou
		    Ponteiro = fopen("Apartamentos.txt", "r"); //variável Ponteiro é igual a Abra("---.txt", "modo leitura");
			
			while (!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
			{
			
				fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
				// Lê as informações contidas no arquivo
				
				if (Info.ID == NULL) //se Info.ID for igual a um valor NULO significa que não há registros, logo:
				{
					printf("Não há registros! \n\n"); //exibe uma mensagem informando o usuário
					return 0; //e sai da função
					
				} //se Info.ID tiver um valor, a comparação ocorre, e nada acontece
				
				printf("ID: %i \n", Info.ID);
				printf("Andar: %i\n", Info.andar);
				printf("Quantidade de Dormitório(s): %i \n", Info.Qtd_Dormitorio);
				printf("Quantidade de Suíte(s): %i \n", Info.Qtd_Suite);
				printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
				printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
				printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);               //EXIBE AS INFORMAÇÕES CADASTRADAS
				printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
				ColocarEspaco(Info.infraestrutura); 
				//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
				printf("Informações da Infraestrutura: %s \n", Info.infraestrutura);
				ColocarEspaco(Info.endereco);
				//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
				printf("Endereço: %s \n", Info.endereco);
				printf("Possui área de lazer?: %s\n", Info.Area_de_Lazer);
				printf("Área total: %.2f\n", Info.Area_do_terreno);
				printf("Terreno total construído: %.2f\n", Info.Area_construida_total);
				printf("Valor do Imóvel: %.2f\n", Info.valor_do_imovel);	
		  		printf("Nº de telefone: %s\n\n", Info.n_telefone);
		  }
		  fclose(Ponteiro); //fecha (---.txt)
		  printf("Listagem concluída!\n\n"); //coloque em tela ("---------");
		  break;//saia do switch
	 
	  case 2://se op = 2
	  		printf("::: Listar Casas :::\n\n");//exibe a opção que o usuário digitou
	  		
			Ponteiro = fopen("Casa.txt", "r");//variável Ponteiro é igual a Abra("---.txt", "modo leitura");
			while (!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
			{
				
				fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
				// Lê as informações contidas no arquivo
				if (Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que não há registros, logo:
				{
					printf("Não há registros! \n\n");//exibe uma mensagem informando o usuário
					return 0;//e sai da função
						
				}//se Info.ID tiver um valor, a comparação ocorre, e nada acontece
				printf("ID: %i \n", Info.ID);
				printf("Quantidade de Dormitório(s): %i \n", Info.Qtd_Dormitorio);
				printf("Quantidade de Suíte(s): %i \n", Info.Qtd_Suite);
				printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
				printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
				printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
				printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
				ColocarEspaco(Info.infraestrutura);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
				printf("Informações da Infraestrutura: %s \n", Info.infraestrutura);//EXIBE AS INFORMAÇÕES CADASTRADAS
				ColocarEspaco(Info.endereco);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
				printf("Endereço: %s \n", Info.endereco);
				ColocarEspaco(Info.Area_de_Lazer);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
				printf("Possui área de lazer?: %s\n", Info.Area_de_Lazer);
				printf("Área total: %0.2f\n", Info.Area_do_terreno);
				printf("Terreno total construído: %0.2f\n", Info.Area_construida_total);
				printf("Valor do Imóvel: %0.2f\n", Info.valor_do_imovel);	
				printf("Nº de telefone: %s\n\n", Info.n_telefone);
		  }
		  fclose(Ponteiro);//fecha (---.txt)
		  printf("Listagem concluída!\n\n");//coloque em tela ("---------");
		  break;//saia do switch
	  
	case 3://se op = 3
		printf("::: Listar Chácaras :::\n\n");//exibe a opção que o usuário digitou
		Ponteiro = fopen("Chacaras.txt", "r");//variável Ponteiro é igual a Abra("---.txt", "modo leitura");
		while (!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
		{
			
			fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);				
			// Lê as informações contidas no arquivo
			if (Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que não há registros, logo:
			{
				printf("Não há registros! \n\n");//exibe uma mensagem informando o usuário
				return 0;//e sai da função		
			}//se Info.ID tiver um valor, a comparação ocorre, e nada acontece			
			printf("ID: %i \n", Info.ID);
			printf("Quantidade de Dormitório(s): %i \n", Info.Qtd_Dormitorio);
			printf("Quantidade de Suíte(s): %i \n", Info.Qtd_Suite);
			printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
			printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
			printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
			printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
			ColocarEspaco(Info.infraestrutura);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
			printf("Informações da Infraestrutura: %s \n", Info.infraestrutura);		//EXIBE AS INFORMAÇÕES CADASTRADAS
			ColocarEspaco(Info.endereco);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
			printf("Endereço: %s \n", Info.endereco);
			printf("Possui área de lazer?: %s\n", Info.Area_de_Lazer);
			printf("Área total: %.2f\n", Info.Area_do_terreno);
			printf("Terreno total construído: %.2f\n", Info.Area_construida_total);
			printf("Valor do Imóvel: %.2f\n", Info.valor_do_imovel);	
	  		printf("Nº de telefone: %s\n\n", Info.n_telefone);
	  }
	  fclose(Ponteiro);//fecha (---.txt)
	  printf("Listagem concluída!\n\n");//coloque em tela ("---------");
	  break;//saia do switch

	case 4:	//se op = 4
		printf("::: Listar Terrenos :::\n\n");//exibe a opção que o usuário digitou
		Ponteiro = fopen("Terrenos.txt", "r");//variável Ponteiro é igual a Abra("---.txt", "modo leitura");
		while (!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
		{
			
			fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
			// Lê as informações contidas no arquivo
			if (Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que não há registros, logo:
			{
				printf("Não há registros! \n\n");//exibe uma mensagem informando o usuário
				return 0;//e sai da função
					
			}//se Info.ID tiver um valor, a comparação ocorre, e nada acontece		
			printf("ID: %i \n", Info.ID);
			printf("Área total: %.2f\n", Info.Area_do_terreno);//EXIBE AS INFORMAÇÕES CADASTRADAS
			printf("Valor do Imóvel: %.2f\n", Info.valor_do_imovel);	
			printf("Nº de telefone: %s\n\n", Info.n_telefone);
	  	}
	  	fclose(Ponteiro);//fecha (---.txt)
	  	printf("Listagem concluída!\n\n");//coloque em tela ("---------");
	  	break;//saia do switch
	
	case 5:
		printf("::: Listar Imóveis Vendidos :::\n\n");//exibe a opção que o usuário digitou
		puts("<1> ::: Para listar Apartamentos");
		puts("<2> ::: Para listar casas");
		puts("<3> ::: Para listar chácaras");
		puts("<4> ::: Para listar Terrenos");  printf("Operação: "); scanf("%i", &op);  puts(""); 
		system("cls");
		//exibe um menu questionando que imóvel o usuário deseja listar
		//lê o valor e insere na variável op
		//quebra linha
		//limpa tela		
		switch (op)//compare (op)
		{
			case 1://se op = 1
				printf("::: Apartamentos Vendidos :::\n\n");//exibe a opção que o usuário digitou
				Ponteiro = fopen("ApartamentosVendidos.txt", "r");//variável Ponteiro é igual a Abra("---.txt", "modo leitura");								
				
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info3.numero_do_cracha, &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// Lê as informações contidas no arquivo
					if (Info3.numero_do_cracha == NULL)//se Info3.numero_do_cracha for igual a um valor NULO significa que não há registros, logo:
					{
					printf("Não há registros! \n\n");//exibe uma mensagem informando o usuário
					return 0;//e sai da função	
							
					}//se Info.ID tiver um valor, a comparação ocorre, e nada acontece	
					
					//EXIBE AS INFORMAÇÕES CADASTRADAS			
					printf("ID: %i\n", Info.ID);
					printf("Andar: %i\n", Info.andar);
					printf("Crachá do Vendedor: %i\n", Info3.numero_do_cracha);
					printf("Dormitório<s>: %i\n", Info.Qtd_Dormitorio);
					printf("Suíte<s>: %i\n", Info.Qtd_Suite);
					printf("Sala<s>: %i\n", Info.Qtd_Sala);				
					printf("Sala<s> de estar: %i\n", Info.Qtd_Sala_de_Estar);
					printf("Cozinha<s>: %i\n", Info.Qtd_Cozinha);
					printf("Banheiro<s>: %i\n", Info.Qtd_Banheiro);
					ColocarEspaco(Info.infraestrutura);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
					ColocarEspaco(Info.endereco);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
					ColocarEspaco(Info.Area_de_Lazer);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
					printf("Infraestrutura: %s\n", Info.infraestrutura);
					printf("Endereço: %s\n", Info.endereco);
					printf("Area de Lazer: %s\n", Info.Area_de_Lazer);
					printf("Área do Terreno: %0.2f\n", Info.Area_do_terreno);
					printf("Área Construída Total: %0.2f\n", Info.Area_construida_total);
					printf("Valor do Apartamento: %0.2f\n", Info.valor_do_imovel);
					printf("Nº de telefone: %s\n\n", Info.n_telefone);
					
				}	
				fclose(Ponteiro);//fecha (---.txt);
				printf("Listagem concluída!\n\n");//coloque em tela ("---------");
				break;//saia do switch
		
			case 2://se op = 2
				printf("\nCasas Vendidas\n\n");	//exibe a opção que o usuário digitou
				Ponteiro = fopen("CasaVendidos.txt", "r");//variável Ponteiro é igual a Abra("---.txt", "modo leitura");
				
				
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info3.numero_do_cracha, &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);
					// Lê as informações contidas no arquivo
					
					if (Info3.numero_do_cracha == NULL)//se Info3.numero_do_cracha for igual a um valor NULO significa que não há registros, logo:
					{
					printf("Não há registros! \n\n");//exibe uma mensagem informando o usuário
					return 0;//e sai da função
						
					}//se Info3.numero_do_cracha tiver um valor, a comparação ocorre, e nada acontece
					
					//EXIBE AS INFORMAÇÕES CADASTRADAS
					printf("ID: %i\n", Info.ID);
					printf("Crachá do Vendedor: %i\n", Info3.numero_do_cracha);
					printf("Dormitório<s>: %i\n", Info.Qtd_Dormitorio);
					printf("Suíte<s>: %i\n", Info.Qtd_Suite);
					printf("Sala<s>: %i\n", Info.Qtd_Sala);
					printf("Sala<s> de estar: %i\n", Info.Qtd_Sala_de_Estar);
					printf("Cozinha<s>: %i\n", Info.Qtd_Cozinha);
					printf("Banheiro<s>: %i\n", Info.Qtd_Banheiro);
					ColocarEspaco(Info.infraestrutura);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
					ColocarEspaco(Info.endereco);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
					ColocarEspaco(Info.Area_de_Lazer);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
					printf("Infraestrutura: %s\n", Info.infraestrutura);
					printf("Endereço: %s\n", Info.endereco);
					printf("Area de Lazer: %s\n", Info.Area_de_Lazer);
					printf("Área do Terreno: %0.2f\n", Info.Area_do_terreno);
					printf("Área Construída Total: %0.2f\n", Info.Area_construida_total);
					printf("Valor do Apartamento: %0.2f\n", Info.valor_do_imovel);
					printf("Nº de telefone: %s\n\n", Info.n_telefone);
					
				}	
				fclose(Ponteiro);//fecha (---.txt)
				printf("Listagem concluída!\n\n");//coloque em tela ("---------");
				break;//saia do switch
		
			case 3://se op = 3
				printf("\nChácaras Vendidas\n\n");	//exibe a opção que o usuário digitou
				Ponteiro = fopen("ChacarasVendidos.txt", "r");//variável Ponteiro é igual a Abra("---.txt", "modo leitura");
				
				
			
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info3.numero_do_cracha, &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);
					// Lê as informações contidas no arquivo
					
					if (Info3.numero_do_cracha == NULL)//se Info3.numero_do_cracha for igual a um valor NULO significa que não há registros, logo:
					{
					printf("Não há registros! \n\n");//exibe uma mensagem informando o usuário
					return 0;//e sai da função
						
					}//se Info3.numero_do_cracha tiver um valor, a comparação ocorre, e nada acontece
					
					
					//EXIBE AS INFORMAÇÕES CADASTRADAS
					printf("ID: %i\n", Info.ID);
					printf("Crachá do Vendedor: %i\n", Info3.numero_do_cracha);
					printf("Dormitório<s>: %i\n", Info.Qtd_Dormitorio);
					printf("Suíte<s>: %i\n", Info.Qtd_Suite);
					printf("Sala<s>: %i\n", Info.Qtd_Sala);
					printf("Sala<s> de estar: %i\n", Info.Qtd_Sala_de_Estar);
					printf("Cozinha<s>: %i\n", Info.Qtd_Cozinha);
					printf("Banheiro<s>: %i\n", Info.Qtd_Banheiro);
					ColocarEspaco(Info.infraestrutura);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
					ColocarEspaco(Info.endereco);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
					ColocarEspaco(Info.Area_de_Lazer);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
					printf("Infraestrutura: %s\n", Info.infraestrutura);
					printf("Endereço: %s\n", Info.endereco);
					printf("Area de Lazer: %s\n", Info.Area_de_Lazer);
					printf("Área do Terreno: %0.2f\n", Info.Area_do_terreno);
					printf("Área Construída Total: %0.2f\n", Info.Area_construida_total);
					printf("Valor do Apartamento: %0.2f\n", Info.valor_do_imovel);
					printf("Nº de telefone: %s\n\n", Info.n_telefone);
					
				}	
				fclose(Ponteiro);//fecha (---.txt)	
				printf("Listagem concluída!\n\n");//coloque em tela ("---------");
				break;//saia do switch

			
			case 4://se op = 4
				printf("\nTerrenos Vendidos\n\n");	//exibe a opção que o usuário digitou
				Ponteiro = fopen("TerrenosVendidos.txt", "r");//variável Ponteiro é igual a Abra("---.txt", "modo leitura");
				
				
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %f %f %s %s\n", &Info3.numero_do_cracha, &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);	
					// Lê as informações contidas no arquivo
					if (Info3.numero_do_cracha == NULL)//se Info3.numero_do_cracha for igual a um valor NULO significa que não há registros, logo:
					{
						printf("Não há registros! \n\n");//exibe uma mensagem informando o usuário
						return 0;//e sai da função
					}//se Info3.numero_do_cracha tiver um valor, a comparação ocorre, e nada acontece
					
					//EXIBE AS INFORMAÇÕES CADASTRADAS
					printf("ID: %i\n", Info.ID);
					printf("Crachá do Vendedor: %i\n", Info3.numero_do_cracha);
					printf("Valor do Apartamento: %0.2f\n", Info.valor_do_imovel);
					printf("Area do Terreno: %0.2f\n", Info.valor_do_imovel);
					ColocarEspaco(Info.endereco);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
					printf("Endereço: %s\n", Info.endereco);
					printf("Nº de telefone: %s\n\n", Info.n_telefone);
				}	
				fclose(Ponteiro);//fecha (---.txt)
				printf("Listagem concluída!\n\n");//coloque em tela ("---------");
				break;//saia do switch
			
			default: //se nenhum dos case corresponder
				break; // sai do programa
		}//fim switch vendidos			  	 	 
	}//fim switch principal		
}//fim função


void Imovel()//cria uma função do tipo vazio de nome Imovel()
{
	int op, id; //cria variáveis do tipo inteiro de nomes ...;
	Ficha_Tecnica_Imovel Info, Info2; //cria variáveis do tipo Ficha_Tecnica_Imovel de nomes ...;
	
	puts("<1> ::: Cadastrar p. venda");
	puts("<2> ::: Cadastrar p. locação");
	puts("<3+> ::: Sair"); printf("Operação: "); scanf("%i", &op); puts("\n");
	system("cls");
	//exibe um menu questionando que tarefa o usuário deseja executar
	//Cadastrar p. Venda
	//Cadastras p. Locação
	//lê valor e armazena na vairiável op
	//pula 2 linhas
	//limpa a tela
	
	switch (op)//compare (op)
	{
		case 1://se op = 1
			
		printf("::: Cadastro p. Venda :::\n\n"); 
		printf("Informe o tipo de imóvel para venda: \n\n");
		puts("<1> ::: Apartamento");
		puts("<2> ::: Casa");
		puts("<3> ::: Chácara");
		puts("<4> ::: Terreno");
		puts("<5+> ::: Sair");
		printf("Operação: "); scanf("%i", &op); puts("");
		system("cls");
		//exibe um menu questionando que atividade o usuário deseja executar
		//lê valor e armazena na variável op
		//limpa a tela
		switch (op)
		{
			case 1: //se op = 1
				printf("::: Apartamento p. venda :::\n\n"); //mostra a opção escolhida pelo usário
				printf("Informe o ID: ");
				scanf("%i", &id);
				puts("");
				//pede que o usuário informe o ID que irá identificar o imóvel respectivo
				//lê e armazena na variável id
				//pula 2 linhas
				
				p://Ponto usado em conjunto ao comando goto, usado posteriormente
				Ponteiro = fopen("Apartamentos.txt","r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");
				
				while(!feof(Ponteiro)) //enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// Lê as informações contidas no arquivo
					if (Info.ID == NULL) //se Info.ID for igual a um valor Nulo, significa que não há informações no arquivo logo:
					{
						Info.ID == id; //Info.ID é igual ao valor de id
					}//fim da comparação
					
					if (id != Info.ID)//se id for diferente de Info.ID (Se o id registrado for diferente dos ID's lidos no arquivo)
					{
						Info.ID = id;//Info.ID é igual ao valor de id
					
					}
					else//se não
					{
						while(id == Info.ID) //enquanto (id == Info.ID)
						{
							printf("ID já utilizado. Informar novo ID: "); 
							scanf("%i", &id);	
							puts("");
							//pede ao usuário que digite um valor
							//lê o valor e armazena na variável id
							//pula 1 linha
						}//volta no loop e verifica a condição
						
						Info.ID = id;//Info.ID é igual ao valor de id
						fclose(Ponteiro);//feche (---.txt);
						goto p;//vá para o ponto p;
					}
				}
				fclose(Ponteiro);//feche(---.txt);
				
				//Adquire todas as informações do imóvel
				printf("Informe o Andar: ");
				scanf("%i", &Info.andar);
				printf("Informe a Quantidade de Dormitórios: ");
				scanf("%i", &Info.Qtd_Dormitorio);
				printf("Informe a Quantidade de Suítes: ");
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
				TirarEspaco(Info.infraestrutura);//Chama função para tirar espaço da variável ---;
				printf("Informe o Endereço: ");
				gets(Info.endereco);
				TirarEspaco(Info.endereco);
				printf("Possui área de lazer? Sim ou Não: ");
				gets(Info.Area_de_Lazer);
				TirarEspaco(Info.Area_de_Lazer);
				printf("Informe a área do terreno: ");
				scanf("%f", &Info.Area_do_terreno);
				printf("Informe a área construída total: ");
				scanf("%f", &Info.Area_construida_total);
				printf("Informe o valor do imóvel: ");
				scanf("%f",&Info.valor_do_imovel);	
				getchar();
				printf("Número de telefone: ");
				gets(Info.n_telefone);
				TirarEspaco(Info.n_telefone);
				
				Ponteiro = fopen("Apartamentos.txt","a+");// variável Ponteiro é igual a Abra("---.txt", "modo escrita");
				fprintf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone, Info.n_telefone);
				//insere no arquivo todas as informações adquiridas
				fclose(Ponteiro);//feche (---.txt);
				
				printf("Registrado!\n\n");//coloque na tela ("---");
				goto fim;//vá para o ponto fim.
			
			case 2://se op = 2
				printf("::: Casa p. venda :::\n\n");//mostra a opção escolhida pelo usário
				
				
				printf("Informe o ID: ");
				scanf("%i", &id);
				puts("");
				//pede que o usuário informe o ID que irá identificar o imóvel respectivo
				//lê e armazena na variável id
				//pula 2 linhas
				
				p2://Ponto usado em conjunto ao comando goto, usado posteriormente
				
				Ponteiro = fopen("Casa.txt", "r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info2.ID, &Info2.Qtd_Dormitorio, &Info2.Qtd_Suite, &Info2.Qtd_Sala, &Info2.Qtd_Sala_de_Estar, &Info2.Qtd_Cozinha, &Info2.Qtd_Banheiro, Info2.infraestrutura, Info2.endereco, Info2.Area_de_Lazer, &Info2.Area_do_terreno, &Info2.Area_construida_total, &Info2.valor_do_imovel, Info.n_telefone);	
					// Lê as informações contidas no arquivo
					if(Info2.ID == NULL)//se Info.ID for igual a um valor Nulo, significa que não há informações no arquivo logo:
					{
						Info.ID = id;//Info2.ID é igual ao valor de id
					}//fim da comparação
					
					if (id != Info2.ID)//se id for diferente de Info2.ID (Se o id registrado for diferente dos ID's lidos no arquivo)
					{
						Info.ID = id;//Info.ID é igual ao valor de id
					}
					else//se não
					{
						while(id == Info2.ID)//enquanto (id == Info2.ID)
						{
							printf("ID já utilizado. Informar novo ID: ");
							scanf("%i", &id);
							puts("");
							//pede ao usuário que digite um valor
							//lê o valor e armazena na variável id
							//pula 1 linha
						}//volta no loop e verifica a condição
						Info.ID = id;//Info.ID é igual ao valor de id
						fclose(Ponteiro);//feche (---.txt);
						goto p2;//vá para o ponto p;
					}
				}
				fclose(Ponteiro);//feche(---.txt);
				
				
				//Adquire todas as informações do imóvel
				printf("Informe a Quantidade de Dormitórios: ");
				scanf("%i", &Info.Qtd_Dormitorio);
				printf("Informe a Quantidade de Suítes: ");
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
				TirarEspaco(Info.infraestrutura);//Chama função para tirar espaço da variável ---;
				printf("Informe o Endereço: ");
				gets(Info.endereco);
				TirarEspaco(Info.endereco);//Chama função para tirar espaço da variável ---;
				printf("Possui área de lazer? Sim ou Não: ");
				gets(Info.Area_de_Lazer);
				printf("Informe a área do terreno: ");
				scanf("%f", &Info.Area_do_terreno);
				printf("Informe a área construída total: ");
				scanf("%f", &Info.Area_construida_total);
				printf("Informe o valor do imóvel: ");
				scanf("%f", &Info.valor_do_imovel);	
				getchar();
				printf("Número de telefone: ");
				gets(Info.n_telefone);
				TirarEspaco(Info.n_telefone);//Chama função para tirar espaço da variável ---;
					
		
				Ponteiro = fopen("Casa.txt","a+");// variável Ponteiro é igual a Abra("---.txt", "modo escrita");
				fprintf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
				//insere no arquivo todas as informações adquiridas no arquivo
				fclose(Ponteiro);//feche (---.txt);
				
				printf("Registrado!\n\n");//coloque na tela ("---");
				goto fim;//vá para o ponto fim.
			
			
			case 3://se op = 3
				printf("::: Chácaras p. venda :::\n\n");//mostra a opção escolhida pelo usário
				
				printf("Informe o ID: ");
				scanf("%i", &id);
				puts("");
				//pede que o usuário informe o ID que irá identificar o imóvel respectivo
				//lê e armazena na variável id
				//pula 2 linhas				
				
				p3://Ponto usado em conjunto ao comando goto, usado posteriormente
				Ponteiro = fopen("Chacaras.txt", "r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// Lê as informações contidas no arquivo
					if(Info.ID == NULL)//se Info.ID for igual a um valor Nulo, significa que não há informações no arquivo logo:
					{
						Info.ID = id;//Info.ID é igual ao valor de id
					}//fim da comparação
					
					if (id != Info.ID)//se Info.ID for igual a um valor Nulo, significa que não há informações no arquivo logo:
					{
						Info.ID = id;//Info.ID é igual ao valor de id
					}
					else//se não
					{
						while(id == Info.ID)//enquanto (id == Info.ID)
						{
							printf("ID já utilizado. Informar novo ID: ");
							scanf("%i", &id);
							puts("");
							//pede ao usuário que digite um valor
							//lê o valor e armazena na variável id
							//pula 1 linha						
						}//volta no loop e verifica a condição
						Info.ID = id;//Info.ID é igual ao valor de id
						fclose(Ponteiro);//feche (---.txt);
						goto p3;//vá para o ponto p;
					}
				}
				fclose(Ponteiro);//feche(---.txt);
				
				//Adquire todas as informações do imóvel
				printf("Informe a Quantidade de Dormitórios: ");
				scanf("%i", &Info.Qtd_Dormitorio);
				printf("Informe a Quantidade de Suítes: ");
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
				TirarEspaco(Info.infraestrutura);//Chama função para tirar espaço da variável ---;
				printf("Informe o Endereço: ");
				gets(Info.endereco);
				TirarEspaco(Info.endereco);//Chama função para tirar espaço da variável ---;
				printf("Possui área de lazer? Sim ou Não: ");
				gets(Info.Area_de_Lazer);
				printf("Informe a área do terreno: ");
				scanf("%f", &Info.Area_do_terreno);
				printf("Informe a área construída total: ");
				scanf("%f", &Info.Area_construida_total);
				printf("Informe o valor do imóvel: ");
				scanf("%f",&Info.valor_do_imovel);		
				getchar();
				printf("Número de telefone: ");
				gets(Info.n_telefone);
				TirarEspaco(Info.n_telefone);//Chama função para tirar espaço da variável ---;

				Ponteiro = fopen("Chacaras.txt","a+");// variável Ponteiro é igual a Abra("---.txt", "modo escrita");
				fprintf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
				//insere no arquivo todas as informações adquiridas no arquivo
				fclose(Ponteiro);//feche (---.txt);
				
				printf("Registrado!\n\n");//coloque na tela ("---");
				return 0;//vá para o ponto fim.
				
			case 4://se op = 4
				printf("::: Terrenos p. Venda :::\n\n");//mostra a opção escolhida pelo usário
				
				printf("Informe o ID: ");
				scanf("%i", &id);
				puts("");
				//pede que o usuário informe o ID que irá identificar o imóvel respectivo
				//lê e armazena na variável id
				//pula 2 linhas
				
				p4://Ponto usado em conjunto ao comando goto, usado posteriormente
				Ponteiro = fopen("Terrenos.txt", "r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");

				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);	
					// Lê as informações contidas no arquivo
				
					if(Info.ID == NULL)//se Info.ID for igual a um valor Nulo, significa que não há informações no arquivo logo:
					{
						Info.ID = id;//Info.ID é igual ao valor de id
					}//fim da comparação					
					
					if (id != Info.ID)//se id for diferente de Info.ID (Se o id registrado for diferente dos ID's lidos no arquivo)
					{
						Info.ID = id;//Info.ID é igual ao valor de id
					}
					else//se não
					{
						while(id == Info.ID)//enquanto (id == Info.ID)
						{
							printf("ID já utilizado. Informar novo ID: ");
							scanf("%i", &id);
							puts("");
						//pede ao usuário que digite um valor
						//lê o valor e armazena na variável id
						//pula 1 linha
						}//volta no loop e verifica a condição
						Info.ID = id;//Info.ID é igual ao valor de id
						fclose(Ponteiro);//feche (---.txt);
						goto p4;//vá para o ponto p;
					}
				}
				fclose(Ponteiro);//feche(---.txt);
				
				//Adquire todas as informações do imóvel
				printf("Informe a área do terreno: ");
				scanf("%f", &Info.Area_do_terreno);
				printf("Informe o valor do imóvel: ");
				scanf("%f",&Info.valor_do_imovel);
				getchar();
				printf("Informe o endereço: ");
				gets(Info.endereco);
				TirarEspaco(Info.endereco);//Chama função para tirar espaço da variável ---;
				printf("Número de telefone: ");
				gets(Info.n_telefone);
				TirarEspaco(Info.n_telefone);//Chama função para tirar espaço da variável ---;

				
				Ponteiro = fopen("Terrenos.txt", "a+");// variável Ponteiro é igual a Abra("---.txt", "modo escrita");
				fprintf(Ponteiro, "%i %f %f %s %s\n", Info.ID, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);
				//insere no arquivo todas as informações adquiridas no arquivo
				fclose(Ponteiro);//feche (---.txt);
				printf("Registrado!\n\n");//coloque na tela ("---");
				goto fim;//vá para o ponto fim
			
			default:
					 break;
					 return 0;
		}//Fim do switch de venda
	
		case 2: //Locação de Imóveis
			printf("::: Cadastro p. Locação :::\n\n");
			printf("Informe o tipo de imóvel para locação: \n\n");
			puts("<1> ::: Apartamento");
			puts("<2> ::: Casa");
			puts("<3> ::: Chácara");
			puts("<4> ::: Terreno");
			puts("<5+> ::: Sair");
			printf("Operação: "); scanf("%i", &op); puts("");
			system("cls");
			//exibe um menu questionando que atividade o usuário deseja executar
			//lê valor e armazena na variável op
			//limpa a tela	
					
			switch (op)//compare (op)
			{
				case 1: //se op = 1
					
					printf("::: Apartamentos p. alugar :::\n\n");//mostra a opção escolhida pelo usário
					printf("Informe o ID: ");
					scanf("%i", &id);
					puts("");
					//pede que o usuário informe o ID que irá identificar o imóvel respectivo
					//lê e armazena na variável id
					//pula 2 linhas					
					
					p5://Ponto usado em conjunto ao comando goto, usado posteriormente
					Ponteiro = fopen("AlugarApartamentos.txt","r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");
					
					while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
					{
						fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info2.ID, &Info2.andar, &Info2.Qtd_Dormitorio, &Info2.Qtd_Suite, &Info2.Qtd_Sala, &Info2.Qtd_Sala_de_Estar, &Info2.Qtd_Cozinha, &Info2.Qtd_Banheiro, Info2.infraestrutura, Info2.endereco, Info2.Area_de_Lazer, &Info2.Area_do_terreno, &Info2.Area_construida_total, &Info2.valor_do_imovel, Info.n_telefone);	
						// Lê as informações contidas no arquivo
						
						if (Info2.ID == NULL) //se Info.ID for igual a um valor Nulo, significa que não há informações no arquivo logo:
						{
							Info.ID == id; //Info.ID é igual ao valor de id
						}//fim da comparação						
						
						if (id != Info2.ID)	//se id for diferente de Info.ID (Se o id registrado for diferente dos ID's lidos no arquivo)
						{
							Info.ID = id;//Info.ID é igual ao valor de id
						
						}
						else//se não
						{
							while(id == Info2.ID)//enquanto (id == Info.ID)
							{
								printf("ID já utilizado. Informar novo ID: ");
								scanf("%i", &id);
								puts("");
								//pede ao usuário que digite um valor
								//lê o valor e armazena na variável id
								//pula 1 linha
							}//volta no loop e verifica a condição
							Info.ID = id;//Info.ID é igual ao valor de id
							fclose(Ponteiro);//feche (---.txt);
							goto p5;//vá para o ponto p;
						}
					}
					fclose(Ponteiro);//feche(---.txt);
					
					//Adquire todas as informações do imóvel
					printf("Informe o Andar: ");
					scanf("%i", &Info.andar);
					printf("Informe a Quantidade de Dormitórios: ");
					scanf("%i", &Info.Qtd_Dormitorio);
					printf("Informe a Quantidade de Suítes: ");
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
					TirarEspaco(Info.infraestrutura);//Chama função para tirar espaço da variável ---;
					printf("Informe o Endereço: ");
					gets(Info.endereco);
					TirarEspaco(Info.endereco);//Chama função para tirar espaço da variável ---;
					printf("Possui área de lazer? Sim ou Não: ");
					gets(Info.Area_de_Lazer);
					TirarEspaco(Info.Area_de_Lazer);//Chama função para tirar espaço da variável ---;
					printf("Informe a área do terreno: ");
					scanf("%f", &Info.Area_do_terreno);
					printf("Informe a área construída total: ");
					scanf("%f", &Info.Area_construida_total);
					printf("Informe o valor do Aluguel: ");
					scanf("%f",&Info.valor_do_imovel);
					getchar();		
					printf("Número de telefone: ");
					gets(Info.n_telefone);
					TirarEspaco(Info.n_telefone);//Chama função para tirar espaço da variável ---;
				
					Ponteiro = fopen("AlugarApartamentos.txt","a+");// variável Ponteiro é igual a Abra("---.txt", "modo escrita");
					fprintf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
					//insere no arquivo todas as informações adquiridas no arquivo
					fclose(Ponteiro);//feche (---.txt);
					
					printf("Registrado!\n\n");//coloque na tela ("---");
				
					break;//vá para o fim.
					
				case 2://se op = 2
					printf("::: Casas p. alugar :::\n\n");//mostra a opção escolhida pelo usário
					printf("Informe o ID: ");
					scanf("%i", &id);
					puts("");
					//pede que o usuário informe o ID que irá identificar o imóvel respectivo
					//lê e armazena na variável id
					//pula 1 linha
					
					p6://Ponto usado em conjunto ao comando goto, usado posteriormente
					Ponteiro = fopen("AlugarCasa.txt","r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");
					while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
					{
						fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info2.ID, &Info2.Qtd_Dormitorio, &Info2.Qtd_Suite, &Info2.Qtd_Sala, &Info2.Qtd_Sala_de_Estar, &Info2.Qtd_Cozinha, &Info2.Qtd_Banheiro, Info2.infraestrutura, Info2.endereco, Info2.Area_de_Lazer, &Info2.Area_do_terreno, &Info2.Area_construida_total, &Info2.valor_do_imovel, Info.n_telefone);	
						// Lê as informações contidas no arquivo
						
						if (id != Info2.ID)//se id for diferente de Info.ID (Se o id registrado for diferente dos ID's lidos no arquivo)
						{
							Info.ID = id;//Info.ID é igual ao valor de id
							
						}
						else//se não
						{
							while(id == Info.ID)//enquanto (id == Info.ID)
							{
								printf("ID já utilizado. Informar novo ID: ");
								scanf("%i", &id); 
								puts("");
								//pede ao usuário que digite um valor
								//lê o valor e armazena na variável id
								//pula 1 linha
							}//volta no loop e verifica a condição
							Info.ID = id;//Info.ID é igual ao valor de id
							fclose(Ponteiro);//feche (---.txt);
							goto p6;//vá para o ponto p;
						}
					}
								
					fclose(Ponteiro);//feche(---.txt);
					
					//Adquire todas as informações do imóvel
					printf("Informe a Quantidade de Dormitórios: ");
					scanf("%i", &Info.Qtd_Dormitorio);
					printf("Informe a Quantidade de Suítes: ");
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
					TirarEspaco(Info.infraestrutura);//Chama função para tirar espaço da variável ---;
					printf("Informe o Endereço: ");
					gets(Info.endereco);
					TirarEspaco(Info.endereco);//Chama função para tirar espaço da variável ---;
					printf("Possui área de lazer? Sim ou Não: ");
					gets(Info.Area_de_Lazer);
					printf("Informe a área do terreno: ");
					scanf("%f", &Info.Area_do_terreno);
					printf("Informe a área construída total: ");
					scanf("%f", &Info.Area_construida_total);
					printf("Informe o valor do aluguel: ");
					scanf("%f",&Info.valor_do_imovel);	
					getchar();	
					printf("Número de telefone: ");
					gets(Info.n_telefone);
					TirarEspaco(Info.n_telefone);//Chama função para tirar espaço da variável ---;
	
			
					Ponteiro = fopen("AlugarCasa.txt","w");// variável Ponteiro é igual a Abra("---.txt", "modo escrita");
					fprintf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
					//insere no arquivo todas as informações adquiridas no arquivo
					fclose(Ponteiro);//feche (---.txt);
					
					printf("Registrado!\n\n");//coloque na tela ("---");
					goto fim;//vá para o ponto fim.
					break;//vá para o ponto fim.
				
				
				case 3://se op = 3
					printf("::: Chácaras p. alugar :::\n\n");//mostra a opção escolhida pelo usário

					
					printf("Informe o ID: ");
					scanf("%i", &id);
					puts("");
					//pede que o usuário informe o ID que irá identificar o imóvel respectivo
					//lê e armazena na variável id
					//pula 2 linhas
					
					p7://Ponto usado em conjunto ao comando goto, usado posteriormente
					Ponteiro = fopen("AlugarChacaras.txt", "r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");
					
					while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
					{
						fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info2.ID, &Info2.Qtd_Dormitorio, &Info2.Qtd_Suite, &Info2.Qtd_Sala, &Info2.Qtd_Sala_de_Estar, &Info2.Qtd_Cozinha, &Info2.Qtd_Banheiro, Info2.infraestrutura, Info2.endereco, Info2.Area_de_Lazer, &Info2.Area_do_terreno, &Info2.Area_construida_total, &Info2.valor_do_imovel, Info.n_telefone);	
						// Lê as informações contidas no arquivo
						if (Info2.ID == NULL) //se Info.ID for igual a um valor Nulo, significa que não há informações no arquivo logo:
						{
							Info.ID == id; //Info.ID é igual ao valor de id
						}//fim da comparação
						
						if (id != Info2.ID)//se id for diferente de Info.ID (Se o id registrado for diferente dos ID's lidos no arquivo)
						{
							Info.ID = id;//Info.ID é igual ao valor de id
							
						}
						else//se não
						{
							while(id == Info2.ID)//enquanto (id == Info.ID)
							{
								printf("ID já utilizado. Informar novo ID: ");
								scanf("%i", &id);
								puts("");
								//pede ao usuário que digite um valor
								//lê o valor e armazena na variável id
								//pula 1 linha								
							}//volta no loop e verifica a condição
							Info.ID = id;//Info.ID é igual ao valor de id
							fclose(Ponteiro);//feche (---.txt);
							goto p7;//vá para o ponto p;
						}
					}
					fclose(Ponteiro);//feche(---.txt);
					
					//Adquire todas as informações do imóvel
					printf("Informe a Quantidade de Dormitórios: ");
					scanf("%i", &Info.Qtd_Dormitorio);
					printf("Informe a Quantidade de Suítes: ");
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
					TirarEspaco(Info.infraestrutura);//Chama função para tirar espaço da variável ---;
					printf("Informe o Endereço: ");
					gets(Info.endereco);
					TirarEspaco(Info.endereco);//Chama função para tirar espaço da variável ---;
					printf("Possui área de lazer? Sim ou Não: ");
					gets(Info.Area_de_Lazer);
					printf("Informe a área do terreno: ");
					scanf("%f", &Info.Area_do_terreno);
					printf("Informe a área construída total: ");
					scanf("%f", &Info.Area_construida_total);
					printf("Informe o valor do aluguel: ");
					scanf("%f",&Info.valor_do_imovel);	
					getchar();	
					printf("Número de telefone: ");
					gets(Info.n_telefone);
					TirarEspaco(Info.n_telefone);//Chama função para tirar espaço da variável ---;
	
					
					Ponteiro = fopen("AlugarChacaras.txt","a+");// variável Ponteiro é igual a Abra("---.txt", "modo escrita");
					fprintf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
					//insere no arquivo todas as informações adquiridas no arquivo
					fclose(Ponteiro);//feche (---.txt);
					
					printf("Registrado!\n\n");//coloque na tela ("---");
					break;//coloque na tela ("---");
					
				case 4://se op = 4
					printf("::: Terrenos p. alugar :::\n\n");
									
					printf("Informe o ID: ");
					scanf("%i", &id);
					puts("");
					//pede que o usuário informe o ID que irá identificar o imóvel respectivo
					//lê e armazena na variável id
					//pula 2 linhas
					
					p8://Ponto usado em conjunto ao comando goto, usado posteriormente
					Ponteiro = fopen("AlugarTerrenos.txt", "r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");
					while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
					{
						fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);	
						if (Info.ID == NULL) //se Info.ID for igual a um valor Nulo, significa que não há informações no arquivo logo:
						{
							Info.ID == id; //Info.ID é igual ao valor de id
						}//fim da comparação
						
						if (id != Info.ID)//se id for diferente de Info.ID (Se o id registrado for diferente dos ID's lidos no arquivo)
						{
							Info.ID = id;//Info.ID é igual ao valor de id
						}
						else//se não
						{
							while(id == Info.ID)//enquanto (id == Info.ID)
							{
								printf("ID já utilizado. Informar novo ID: ");
								scanf("%i", &id);
								puts("");
								//pede ao usuário que digite um valor
								//lê o valor e armazena na variável id
								//pula 1 linha								
							}//volta no loop e verifica a condição
							Info.ID = id;//Info.ID é igual ao valor de id
							fclose(Ponteiro);//feche (---.txt);
							goto p8;//vá para o ponto p;
						}
					}
					fclose(Ponteiro);//feche(---.txt);
	
					//Adquire todas as informações do imóvel			
					printf("Informe a área do terreno: ");
					scanf("%f", &Info.Area_do_terreno);
					printf("Informe o valor do aluguel: ");
					scanf("%f",&Info.valor_do_imovel);
					getchar();
					printf("Informe o endereço: ");
					gets(Info.endereco);
					TirarEspaco(Info.endereco);//Chama função para tirar espaço da variável ---;
					printf("Número de telefone: ");
					gets(Info.n_telefone);
					TirarEspaco(Info.n_telefone);//Chama função para tirar espaço da variável ---;
	
					
					Ponteiro = fopen("AlugarTerrenos.txt", "a+");// variável Ponteiro é igual a Abra("---.txt", "modo escrita");
					fprintf(Ponteiro, "%i %f %f %s %s\n", Info.ID, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);
					//insere no arquivo todas as informações adquiridas no arquivo
					fclose(Ponteiro);//feche (---.txt);
					printf("Registrado!\n\n");//coloque na tela ("---");
					break;//vá para o ponto fim.
			}// Fim do switch Locação
	}// Fim do switch
	fim://p://Ponto usado em conjunto ao comando goto, usado prevamente
	printf("Operação Finalizada!\n\n");//coloque na tela ("---");
	return 0;
  }


void listaraluguel()//cria uma função do tipo vazio de nome Imovel()
{
	int op;//cria uma variável do tipo inteiro de nome op
	Ficha_Tecnica_Imovel Info;//cria uma variável do tipo Ficha_Tecnica_Imovel de nome Info
	Corretor Info2;//cria uma variável de nome Info2 do tipo Corretor
	
	printf("::: Listagem de Cadastro dos Imóveis p. aluguel :::\n\n");
	puts("<1> ::: Apartamento");
	puts("<2> ::: Casa");
	puts("<3> ::: Chácara");
	puts("<4> ::: Terreno");
	puts("<5> ::: Imóveis Alugados");
	puts("<6+> ::: Sair");
	printf("Operação: "); scanf("%i", &op); puts("");
	system("cls");
	//exibe um menu questionando que imóvel o usuário deseja listar
	//lê o valor e insere na variável op
	//quebra linha
	//limpa tela
	

		switch(op)//compare (op)
		{
			case 1://se op = 1
				printf("::: Listar Apartamento<s> :::\n\n");//exibe a opção que o usuário digitou
				Ponteiro = fopen("AlugarApartamentos.txt", "r");//variável Ponteiro é igual a Abra("---.txt", "modo leitura");
				
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// Lê as informações contidas no arquivo
					if(Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que não há registros, logo:
					{
						puts("Não há registros!\n");//exibe uma mensagem informando o usuário
						return 0;//e sai da função
					}//se Info.ID tiver um valor, a comparação ocorre, e nada acontece
					
					//EXIBE AS INFORMAÇÕES CADASTRADAS
					printf("ID: %i \n", Info.ID);
					printf("Andar: %i\n", Info.andar);
					printf("Quantidade de Dormitório(s): %i \n", Info.Qtd_Dormitorio);
					printf("Quantidade de Suíte(s): %i \n", Info.Qtd_Suite);
					printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
					printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
					printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
					printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
					ColocarEspaco(Info.infraestrutura);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
					printf("Informações da Infraestrutura: %s \n", Info.infraestrutura);
					ColocarEspaco(Info.endereco);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
					printf("Endereço: %s \n", Info.endereco);
					printf("Possui área de lazer?: %s\n", Info.Area_de_Lazer);
					printf("Área total: %.2f\n", Info.Area_do_terreno);
					printf("Terreno total construído: %.2f\n", Info.Area_construida_total);
					printf("Valor do Aluguel: %.2f\n", Info.valor_do_imovel);
					printf("Nº de telefone: %s\n\n", Info.n_telefone);
				}
				fclose(Ponteiro);//fecha (---.txt)
				printf("Listagem concluída!\n\n");//coloque em tela ("---------");
				break;//saia do switch
				
			case 2://se op = 2
				printf("::: Listar Casa<s> :::\n\n");//exibe a opção que o usuário digitou
				Ponteiro = fopen("AlugarCasa.txt", "r");//variável Ponteiro é igual a Abra("---.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// Lê as informações contidas no arquivo
					if(Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que não há registros, logo:
					{
						puts("Não há registros!\n");//exibe uma mensagem informando o usuário
						return 0;//e sai da função
					}//se Info.ID tiver um valor, a comparação ocorre, e nada acontece
					
					//EXIBE AS INFORMAÇÕES CADASTRADAS
					printf("ID: %i \n", Info.ID);
					printf("Quantidade de Dormitório(s): %i \n", Info.Qtd_Dormitorio);
					printf("Quantidade de Suíte(s): %i \n", Info.Qtd_Suite);
					printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
					printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
					printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
					printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
					ColocarEspaco(Info.infraestrutura);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
					printf("Informações da Infraestrutura: %s \n", Info.infraestrutura);
					ColocarEspaco(Info.endereco);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
					printf("Endereço: %s \n", Info.endereco);
					printf("Possui área de lazer?: %s\n", Info.Area_de_Lazer);
					printf("Área total: %.2f\n", Info.Area_do_terreno);
					printf("Terreno total construído: %.2f\n", Info.Area_construida_total);
					printf("Valor do Aluguel: %.2f\n\n", Info.valor_do_imovel);
					printf("Nº de telefone: %s", Info.n_telefone);
				}
				fclose(Ponteiro);//fecha (---.txt)
				printf("Listagem concluída!\n\n");//coloque em tela ("---------");
				break;//saia do switch
				
			case 3://se op = 3
				printf("::: Listar Chácara<s> :::\n\n");//exibe a opção que o usuário digitou
				Ponteiro = fopen("AlugarChacaras.txt", "r");//variável Ponteiro é igual a Abra("---.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// Lê as informações contidas no arquivo
					if(Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que não há registros, logo:
					{
						puts("Não há registros!\n");//exibe uma mensagem informando o usuário
						return 0;//e sai da função
					}
					
					//EXIBE AS INFORMAÇÕES CADASTRADAS
					printf("ID: %i \n", Info.ID);
					printf("Quantidade de Dormitório(s): %i \n", Info.Qtd_Dormitorio);
					printf("Quantidade de Suíte(s): %i \n", Info.Qtd_Suite);
					printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
					printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
					printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
					printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
					ColocarEspaco(Info.infraestrutura);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
					printf("Informações da Infraestrutura: %s \n", Info.infraestrutura);
					ColocarEspaco(Info.endereco);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
					printf("Endereço: %s \n", Info.endereco);
					printf("Possui área de lazer?: %s\n", Info.Area_de_Lazer);
					printf("Área total: %.2f\n", Info.Area_do_terreno);
					printf("Terreno total construído: %.2f\n", Info.Area_construida_total);
					printf("Valor do Aluguel: %.2f\n\n", Info.valor_do_imovel);
					printf("Nº de telefone: %s", Info.n_telefone);
				}
				fclose(Ponteiro);//fecha (---.txt)
				printf("Listagem concluída!\n\n");//coloque em tela ("---------");
				break;//saia do switch
				
			case 4://se op = 4
				printf("::: Listar Terreno<s> :::\n\n");//exibe a opção que o usuário digitou
				Ponteiro = fopen("AlugarTerrenos.txt", "r");//variável Ponteiro é igual a Abra("---.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
				{
					fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);	
					// Lê as informações contidas no arquivo
					
					if(Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que não há registros, logo:
					{
						puts("Não há registros!\n");//exibe uma mensagem informando o usuário
						return 0;//e sai da função
					}
					
					//EXIBE AS INFORMAÇÕES CADASTRADAS
					printf("ID: %i \n", Info.ID);
					printf("Área total: %0.2f\n", Info.Area_do_terreno);
					printf("Valor do Aluguel: %0.2f\n", Info.valor_do_imovel);
					ColocarEspaco(Info.endereco);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
					printf("Endereço: %s\n\n", Info.endereco);
					printf("Nº de telefone: %s", Info.n_telefone);
				}
				fclose(Ponteiro);//fecha (---.txt)
				printf("Listagem concluída!\n\n");//coloque em tela ("---------");
				break;//saia do switch

			case 5: 
				printf("::: Listar Imóvei<s> Alugado<s> :::\n\n");
				puts("<1> ::: Apartamento");
				puts("<2> ::: Casa");
				puts("<3> ::: Chácara");
				puts("<4> ::: Terreno");
				puts("<5+> ::: Sair");
				printf("Operação: "); scanf("%i", &op); puts("");
				system("cls");
				//exibe um menu questionando que imóvel o usuário deseja listar
				//lê o valor e insere na variável op
				//quebra linha
				//limpa tela		
				
						switch (op)//compare (op)
						{
							case 1://se op = 1
								printf("::: Listar Apartamento<s> Alugado<s> :::\n\n");//exibe a opção que o usuário digitou
								Ponteiro = fopen("ApartamentosAlugados.txt", "r");//variável Ponteiro é igual a Abra("---.txt", "modo leitura");
								
								while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
								{
									
									fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info2.numero_do_cracha, &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);
									// Lê as informações contidas no arquivo
									if(Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que não há registros, logo:
									{
										puts("Não há registros!\n");//exibe uma mensagem informando o usuário
										return 0;//e sai da função
									}//se Info.ID tiver um valor, a comparação ocorre, e nada acontece
									
									//EXIBE AS INFORMAÇÕES CADASTRADAS			
									printf("ID: %i \n", Info.ID);
									printf("Crachá: %i\n", Info2.numero_do_cracha);
									printf("Andar: %i\n", Info.andar);
									printf("Quantidade de Dormitório(s): %i \n", Info.Qtd_Dormitorio);
									printf("Quantidade de Suíte(s): %i \n", Info.Qtd_Suite);
									printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
									printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
									printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
									printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
									ColocarEspaco(Info.infraestrutura);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
									printf("Informações da Infraestrutura: %s \n", Info.infraestrutura);
									ColocarEspaco(Info.endereco);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
									printf("Endereço: %s \n", Info.endereco);
									printf("Possui área de lazer?: %s\n", Info.Area_de_Lazer);
									printf("Área total: %.2f\n", Info.Area_do_terreno);
									printf("Terreno total construído: %.2f\n", Info.Area_construida_total);
									printf("Valor do Imóvel: %.2f\n", Info.valor_do_imovel);	
		 			 				printf("Nº de telefone: %s\n\n", Info.n_telefone);
								}
								fclose(Ponteiro);//fecha (---.txt)
								printf("Listagem concluída!\n\n");//coloque em tela ("---------");
								break;//saia do switch
								
							case 2://se op = 2
								printf("::: Listar Casa<s> Alugada<s> :::\n\n");//exibe a opção que o usuário digitou
								Ponteiro = fopen("CasaAlugados.txt", "r");//variável Ponteiro é igual a Abra("---.txt", "modo leitura");
								
								while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
								{
									
									fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info2.numero_do_cracha, &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);
									// Lê as informações contidas no arquivo
									if(Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que não há registros, logo:
									{
										puts("Não há registros!\n");//exibe uma mensagem informando o usuário
										return 0;//e sai da função
									}//se Info.ID tiver um valor, a comparação ocorre, e nada acontece
									
									//EXIBE AS INFORMAÇÕES CADASTRADAS
									printf("ID: %i \n", Info.ID);
									printf("Crachá: %i\n", Info2.numero_do_cracha);
									printf("Quantidade de Dormitório(s): %i \n", Info.Qtd_Dormitorio);
									printf("Quantidade de Suíte(s): %i \n", Info.Qtd_Suite);
									printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
									printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
									printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
									printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
									ColocarEspaco(Info.infraestrutura);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
									printf("Informações da Infraestrutura: %s \n", Info.infraestrutura);
									ColocarEspaco(Info.endereco);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
									printf("Endereço: %s \n", Info.endereco);
									printf("Possui área de lazer?: %s\n", Info.Area_de_Lazer);
									printf("Área total: %.2f\n", Info.Area_do_terreno);
									printf("Terreno total construído: %.2f\n", Info.Area_construida_total);
									printf("Valor do Imóvel: %.2f\n", Info.valor_do_imovel);	
		 			 				printf("Nº de telefone: %s\n\n", Info.n_telefone);
								}
								fclose(Ponteiro);//fecha (---.txt)
								printf("Listagem concluída!\n\n");//coloque em tela ("---------");
								break;//saia do switch
								
								
							case 3://se op = 3
								printf("::: Listar Chácara<s> Alugada<s> :::\n\n");//exibe a opção que o usuário digitou
								Ponteiro = fopen("ChacaraAlugados.txt", "r");//variável Ponteiro é igual a Abra("---.txt", "modo leitura");
								
								while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
								{
									
									fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info2.numero_do_cracha, &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);
									// Lê as informações contidas no arquivo
									if(Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que não há registros, logo:
									{
										puts("Não há registros!\n");//exibe uma mensagem informando o usuário
										return 0;//e sai da função
									}//se Info.ID tiver um valor, a comparação ocorre, e nada acontece
									
									//EXIBE AS INFORMAÇÕES CADASTRADAS
									printf("ID: %i \n", Info.ID);
									printf("Crachá: %i\n", Info2.numero_do_cracha);
									printf("Quantidade de Dormitório(s): %i \n", Info.Qtd_Dormitorio);
									printf("Quantidade de Suíte(s): %i \n", Info.Qtd_Suite);
									printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
									printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
									printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
									printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
									ColocarEspaco(Info.infraestrutura);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
									printf("Informações da Infraestrutura: %s \n", Info.infraestrutura);
									ColocarEspaco(Info.endereco);//chama a função ColocarEspaco(para colocar espaço na informação contida em ---);
									printf("Endereço: %s \n", Info.endereco);
									printf("Possui área de lazer?: %s\n", Info.Area_de_Lazer);
									printf("Área total: %.2f\n", Info.Area_do_terreno);
									printf("Terreno total construído: %.2f\n", Info.Area_construida_total);
									printf("Valor do Imóvel: %.2f\n", Info.valor_do_imovel);	
		 			 				printf("Nº de telefone: %s\n\n", Info.n_telefone);
								}
								fclose(Ponteiro);//fecha (---.txt)
								printf("Listagem concluída!\n\n");//coloque em tela ("---------");
								break;//saia do switch
								
							case 4://se op = 4
								printf("::: Listar Terreno<s> Alugado<s> :::\n\n");//exibe a opção que o usuário digitou
								Ponteiro = fopen("TerrenosAlugados.txt", "r");//variável Ponteiro é igual a Abra("---.txt", "modo leitura");
								
								while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
								{
									fprintf(Ponteiro, "%i %i %f %f %s %s\n", &Info.ID, &Info2.numero_do_cracha, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
									// Lê as informações contidas no arquivo
									if(Info.ID == NULL)//se Info.ID for igual a um valor NULO significa que não há registros, logo:
									{
										puts("Não há registros!\n");//exibe uma mensagem informando o usuário
										return 0;//e sai da função
									}//se Info.ID tiver um valor, a comparação ocorre, e nada acontece
									
									//EXIBE AS INFORMAÇÕES CADASTRADAS
									printf("ID: %i \n", Info.ID);
									printf("Crachá: %i\n", Info2.numero_do_cracha);
									printf("Área total: %.2f\n", Info.Area_do_terreno);
									printf("Valor do Imóvel: %.2f\n", Info.valor_do_imovel);	
									printf("Endereço: %s\n", Info.endereco);
									printf("Nº de telefone: %s\n\n", Info.n_telefone);
								}
								fclose(Ponteiro);//fecha (---.txt)
								printf("Listagem concluída!\n\n");//coloque em tela ("---------");
								break;//saia do switch
							
							default://caso nenhum dos case corresponda, ele sai do switch e do programa
								break; 	//saia do switch
						}//Listar Imóveis alugados
			default://caso nenhum dos case corresponda, ele sai do switch e do programa
				break;		
		}
}

void corretor()//cria uma função do tipo vazio de nome Imovel()
{
	int i;//cria uma variável do tipo inteiro de nome i
	Corretor Info;//cria uma variável do tipo Corretor de nome Info
	getchar();//pega um caractere digitado e retorna para o sistema
	printf("::: Cadastrar Corretor :::\n\n"); //exibe o título da função
	printf("Informe o crachá: "); scanf("%i", &i); //pede ao usuário que informe um crachá para 
	
	ponto://Ponto usado em conjunto ao comando goto, usado posteriormente
	Ponteiro = fopen("Corretores.txt", "r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");
	
		while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
		{
			fscanf(Ponteiro, "%i %s %s %s %i %f %f\n", &Info.numero_do_cracha, Info.nome, Info.data_contratacao, Info.data_nascimento, &Info.idade, &Info.salario_b, &Info.comissao_pvenda);	
			// Lê as informações contidas no arquivo
			if(Info.numero_do_cracha == NULL)//se Info.numero_do_cracha for igual a um valor Nulo, significa que não há informações no arquivo logo:
			{
				Info.numero_do_cracha = i;//Info.numero_do_cracha é igual ao valor de id
			}
			
			if(i != Info.numero_do_cracha)//se i for diferente de Info.numero_do_cracha (Se o cracha informado for diferente dos crachás registrados)
			{
				Info.numero_do_cracha = i;//Info.numero_do_cracha é igual ao valor de id
			}
			else//se não
			{
				while(i == Info.numero_do_cracha)//enquanto (id for igual a Info.numero_do_cracha)
				{
					printf("Crachá já utilizado, tente novamente: "); scanf("%i", &i); puts("");
					//pede ao usuário que digite um valor
					//lê o valor e armazena na variável i
					//pula 1 linha
				}
				Info.numero_do_cracha = i;//Info.ID é igual ao valor de id
				fclose(Ponteiro);//feche (---.txt);
				goto ponto;//vá para o ponto ponto:
			}
		}
	fclose(Ponteiro);//feche (---.txt);
	
	getchar();
	//Adquire todas as informações do Corretor
	printf("Nome do Corretor: ");	gets(Info.nome);	TirarEspaco(Info.nome); puts("");//Chama função para tirar espaço da variável ---; pula uma linha
	printf("Data de contracação: ");	gets(Info.data_contratacao); TirarEspaco(Info.data_contratacao); puts("");//Chama função para tirar espaço da variável ---; pula uma linha
	printf("Data de Nascimento: ");		gets(Info.data_nascimento); TirarEspaco(Info.data_nascimento);puts("");//Chama função para tirar espaço da variável ---; pula uma linha
	printf("Informe a Idade: ");	scanf("%i",&Info.idade); puts("");
	printf("Salário Bruto: ");		scanf("%f", &Info.salario_b); puts("");
	printf("Comissão por venda: ");		scanf("%f", &Info.comissao_pvenda); puts("");
	
	Ponteiro = fopen("Corretores.txt", "a+");// variável Ponteiro é igual a Abra("---.txt", "modo escrita");
	fprintf(Ponteiro, "%i %s %s %s %i %f %f\n", Info.numero_do_cracha, Info.nome, Info.data_contratacao, Info.data_nascimento, Info.idade, Info.salario_b, Info.comissao_pvenda);
	//insere no arquivo todas as informações adquiridas no arquivo
	fclose(Ponteiro);//feche (---.txt);	
}//fim da função

void venda_imovel()//cria uma função do tipo vazio de nome venda_imovel()
{
	Ficha_Tecnica_Imovel Info; //cria uma variável do tipo Ficha_Tecnica_Imovel de nome Info
	Corretor Info2, Info3;//cria variáveis do tipo corretor de nomes ...
	Info3.numero_do_cracha = 0; //define o valor da variável Info3.numero_do_cracha como 0
	FILE* PonteiroNovo; //cria uma variável do tipo FILE de nome PonteiroNovo
	FILE* PonteiroNovo2;//idem acima
	int op, id, cracha, vf = 0;//cria variáveis do tipo inteiro de nomes ...
	

			printf("::: Vender Imóveis :::\n\n");
			printf("Informe o tipo de imóvel a vender: \n\n");
			puts("<1> :::  Apartamentos");
			puts("<2> :::  Casas");
			puts("<3> :::  Chácaras");
			puts("<4> :::  Terrenos");
			puts("<5+> ::: Sair"); printf("Operação: "); scanf("%i", &op); puts("");
			system("cls");
			//exibe um menu interrogando o usuário a respeito da operação desejada
			//lê o valor e armazena na variável op
			//limpa a tela
			switch (op)//compare (op)
			{
				case 1://se op = 1
					printf("<1> ::: Listar Apartamento disponíveis para venda:\n<2> ::: Continuar sem listar\n "); printf("Operação: "); scanf("%i", &op); puts("\n");
					//pergunta ao usuário a respeito da operação desejada. l	
					if(op == 1)
					{
						system("cls");// limpa a tela
						
						Ponteiro = fopen("Apartamentos.txt", "r");//Variável Ponteiro = Abra ("---.txt", "no modo de leitura de informações");
						while (!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em("---.txt"));
						{
			
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
							// Lê as informações contidas no arquivo 
							
							printf("ID: %i \n", Info.ID);
							printf("Andar: %i\n", Info.andar);
							printf("Quantidade de Dormitório(s): %i \n", Info.Qtd_Dormitorio);
							printf("Quantidade de Suíte(s): %i \n", Info.Qtd_Suite);
							printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
							printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
							printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
							printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);  //EXIBE TODAS AS INFORMAÇÔES SOBRE TODOS OS IMÓVEIS REGISTRADOS E DISPONÍVEIS PARA VENDA
							ColocarEspaco(Info.infraestrutura);//chama função ColocarEspaco para colocar espaço nas variáveis
							printf("Informações da Infraestrutura: %s \n", Info.infraestrutura);
							ColocarEspaco(Info.endereco);//chama função ColocarEspaco para colocar espaço nas variáveis
							printf("Endereço: %s \n", Info.endereco);
							printf("Possui área de lazer?: %s\n", Info.Area_de_Lazer);
							printf("Área total: %.2f\n", Info.Area_do_terreno);
							printf("Terreno total construído: %.2f\n", Info.Area_construida_total);
							printf("Valor do Imóvel: %.2f\n", Info.valor_do_imovel);	
							printf("Nº de telefone: %s\n\n", Info.n_telefone);
		 			 }
		  			 fclose(Ponteiro);//feche (---.txt);
		  			 printf("Listagem concluída!\n\n");//Coloque em tela("----");
				}

		
				cracha://Ponto usado em conjunto ao comando goto, usado posteriormente
				PonteiroNovo = fopen("Corretores.txt", "r");// variável PonteiroNovo é igual a Abra("---.txt", "modo leitura");
				printf("Por favor informe o crachá: "); scanf("%i", &cracha); puts("");//pede ao usuário que informe seu crachá, Lê e armazena na variável cracha
				while(!feof(PonteiroNovo))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "---.txt");
				{
				
					fscanf(PonteiroNovo, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);		
					// Lê as informações contidas no arquivo 
					
					if(Info2.numero_do_cracha == cracha)// Se (variável Info2.numero_do_cracha for igual a variável cracha) Info3.numero_do_crachá recebe o valor da variável crachá.
					{
						Info3.numero_do_cracha = cracha; //Info3.numero-do_cracha recebe valor da variável crachá
					}
				}//fim do laço de repetição
				fclose(PonteiroNovo);//feche(Corretores.txt);
				
				if (Info3.numero_do_cracha == 0)//se (Info3.numero_do_cracha for igual a 0) significa que o crachá informado não foi encontrado
				{
					printf("Crachá não existe/não registrado!\n\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o crachá não existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// lê o valor e armazena na variável op
					if (op == 1)//se op for igual a 1
					{
						goto cracha;//volta no ponto cracha, definido previamente 
					} 
					else//se não
					{
						goto fim;// vai até o ponto fim, definido posteriormente 
					}
				}//fim da comparação 	
				

				id://Ponto usado em conjunto ao comando goto, usado posteriormente
				printf("Digite o ID do apartamento: "); scanf("%i", &id); puts("\n"); //pede ao usuário que informe seu id, lê e armazena na variável id
				Ponteiro = fopen("Apartamentos.txt", "r");// variável Ponteiro é igual a Abra("----.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em Ponteiro);
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// Lê as informações contidas no arquivo
									
					if(id == Info.ID)// se Info.ID for igual a varável id (Se algum ID no arquivo for igual ao id informado para aluguel)
					{
						vf = 1;//vf é igual a 1 (servirá para comparação posteriormente)
						PonteiroNovo2 = fopen("ApartamentosVendidos.txt", "a+");// variável PonteiroNovo2 é igual a Abra("----.txt", "modo escrita");
						fprintf(PonteiroNovo2, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info3.numero_do_cracha, Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
						//insira no arquivo(PonteiroNovo2, "as informações contidas em Ponteiro + o número do crachá do corretor intermediário da operação
						fclose(PonteiroNovo2);
						//fecha (PonteiroNovo2)
					}	
				}
				fclose(Ponteiro);//fecha (Ponteiro)
				
				//vf foi definido previamente como 0.
				if (vf == 0)//se (vf for igual a 0) significa que o id informado não foi encontrado
				{
					printf("ID não existe/não registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o id não existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// lê o valor e armazena na variável op
					if (op == 1)//se op for igual a 1
					{
						goto id;//volta no ponto id, definido previamente
					} 
					else//se não
					{
						goto fim;// vai até o ponto fim, definido posteriormente 
					}
				}//fim da comparação 
				
				
				Ponteiro = fopen("Apartamentos.txt","r"); // variável Ponteiro é igual a Abra("---.txt", "modo leitura");
				FILE* PonteiroNovo = fopen("Apartamentos_novo.txt", "w"); // variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
						
						while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 
							// Lê as informações contidas no arquivo
							
							
							if (Info.ID != id) // se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{	
								fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
								//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del Apartamentos.txt");//sistema (delete arquivo ----.txt)
						system("rename Apartamentos_novo.txt Apartamentos.txt");//sistema (renomeie ----.txt para ---.txt
						break;	//saia do switch	
			
			
			case 2://se op = 2
					printf("<1> ::: Listar Apartamento disponíveis para venda:\n<2> ::: Continuar sem listar\n "); printf("Operação: "); scanf("%i", &op); puts("/n"); system("cls");
					//pergunta ao usuário a respeito da operação desejada. 
					// limpa a tela
					
					if(op == 1)//se op = 1
					{
						system("cls");// limpa a tela
						Ponteiro = fopen("Casa.txt", "r");//Variável Ponteiro = Abra ("---.txt", "no modo de leitura de informações");
						while (!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em("---.txt"));
						{
			
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
							// Lê as informações contidas no arquivo 
							
							printf("ID: %i \n", Info.ID);
							printf("Quantidade de Dormitório(s): %i \n", Info.Qtd_Dormitorio);
							printf("Quantidade de Suíte(s): %i \n", Info.Qtd_Suite);
							printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
							printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
							printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);			 //EXIBE TODAS AS INFORMAÇÔES SOBRE TODOS OS IMÓVEIS REGISTRADOS E DISPONÍVEIS PARA VENDA
							printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro);
							ColocarEspaco(Info.infraestrutura);	//chama função ColocarEspaco para colocar espaço nas variáveis								
							printf("Informações da Infraestrutura: %s \n", Info.infraestrutura);
							ColocarEspaco(Info.endereco);//chama função ColocarEspaco para colocar espaço nas variáveis
							printf("Endereço: %s \n", Info.endereco);
							printf("Possui área de lazer?: %s\n", Info.Area_de_Lazer);
							printf("Área total: %.2f\n", Info.Area_do_terreno);
							printf("Terreno total construído: %.2f\n", Info.Area_construida_total);
							printf("Valor do Imóvel: %.2f\n\n", Info.valor_do_imovel);	
							printf("Nº de telefone: %s", Info.n_telefone);
		 			 }
		  			 fclose(Ponteiro);//feche (---.txt);
		  			 printf("Listagem concluída!\n\n");//Coloque em tela("---");
				}

		

				cracha2://Ponto usado em conjunto ao comando goto, usado posteriormente
				PonteiroNovo = fopen("Corretores.txt", "r");// variável PonteiroNovo é igual a Abra("---.txt", "modo leitura");
				printf("Por favor informe o crachá: "); scanf("%i", &cracha); puts("");//pede ao usuário que informe seu crachá, Lê e armazena na variável cracha
				while(!feof(PonteiroNovo))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "---.txt");
				{
				
					fscanf(PonteiroNovo, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);		
					// Lê as informações contidas no arquivo 
					
					
					if(Info2.numero_do_cracha == cracha)// Se (variável Info2.numero_do_cracha for igual a variável cracha) Info3.numero_do_crachá recebe o valor da variável crachá.
					{
						Info3.numero_do_cracha = cracha;//Info3.numero-do_cracha recebe valor da variável cracha
					}
				}//fim do laço de repetição
				fclose(PonteiroNovo);//feche(Corretores.txt);
				
				if (Info3.numero_do_cracha == 0)//se (Info3.numero_do_cracha for igual a 0) significa que o crachá informado não foi encontrado
				{
					printf("Crachá não existe/não registrado!\n\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o crachá não existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// lê o valor e armazena na variável op
					
					if (op == 1)//se op for igual a 1
					{
						goto cracha2;//volta no ponto cracha, definido previamente
					} 
					else//se não
					{
						goto fim;// vai até o ponto fim, definido posteriormente 
					}
				}	//fim da comparação 

				id2://Ponto usado em conjunto ao comando goto, usado posteriormente
				printf("Digite o ID do apartamento: "); scanf("%i", &id); puts("\n"); //pede ao usuário que informe seu id, lê e armazena na variável id
				Ponteiro = fopen("Casa.txt", "r");// variável Ponteiro é igual a Abra("----.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em Ponteiro);
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// Lê as informações contidas no arquivo
					if(id == Info.ID)// se Info.ID for igual a varável id (Se algum ID no arquivo for igual ao id informado para aluguel)
					{
						vf = 1; //vf é igual a 1 (servirá para comparação posteriormente)
						PonteiroNovo2 = fopen("CasaVendidos.txt", "a+");// variável PonteiroNovo2 é igual a Abra("----.txt", "modo escrita");
						fprintf(PonteiroNovo2, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info3.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
						//insira no arquivo(PonteiroNovo2, "as informações contidas em Ponteiro + o número do crachá do corretor intermediário da operação
						fclose(PonteiroNovo2);//fecha (PonteiroNovo2)
					}	
				}
				fclose(Ponteiro);//fecha (Ponteiro)
				
				//vf foi definido previamente como 0.
				if (vf == 0)//se (vf for igual a 0) significa que o id informado não foi encontrado
				{
					printf("ID não existe/não registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o id não existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// lê o valor e armazena na variável op
					if (op == 1)//se op for igual a 1
					{
						goto id2;//volta no ponto id, definido previamente
					} 
					else//se não
					{
						goto fim;// vai até o ponto fim, definido posteriormente 
					}
				}//fim da comparação 

					
				
				Ponteiro = fopen("Casa.txt","r"); // variável Ponteiro é igual a Abra("---.txt", "modo leitura");
				PonteiroNovo = fopen("Casa_novo.txt", "w"); // variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
						
						while(!feof(Ponteiro))// variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 
							// Lê as informações contidas no arquivo
							
							if (Info.ID != id) // se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{	
								fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
								//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del Casa.txt");//sistema (delete arquivo ----.txt)
						system("rename Casa_novo.txt Casa.txt");//sistema (renomeie ----.txt para ---.txt)
						break; //saia do switch
						
			case 3://se op = 3
					printf("<1> ::: Listar Chácaras disponíveis para venda:\n<2> ::: Continuar sem listar\n "); printf("Operação: "); scanf("%i", &op); puts("/n"); system("cls");
					//pergunta ao usuário a respeito da operação desejada. 
					
					if(op == 1)
					{
						system("cls");// limpa a tela
					
						Ponteiro = fopen("Chacaras.txt", "r");//Variável Ponteiro = Abra ("---.txt", "no modo de leitura de informações")
						while (!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em("---.txt"));
						{
			
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
							// Lê as informações contidas no arquivo 
							
							
							printf("ID: %i \n", Info.ID);
							printf("Quantidade de Dormitório(s): %i \n", Info.Qtd_Dormitorio);
							printf("Quantidade de Suíte(s): %i \n", Info.Qtd_Suite);
							printf("Quantidade de Sala(s): %i \n", Info.Qtd_Sala);
							printf("Quantidade de Sala(s) de Estar: %i \n", Info.Qtd_Sala_de_Estar);
							printf("Quantidade de Cozinha(s): %i \n", Info.Qtd_Cozinha);
							printf("Quantidade de Banheiro(s): %i \n", Info.Qtd_Banheiro); //EXIBE TODAS AS INFORMAÇÔES SOBRE TODOS OS IMÓVEIS REGISTRADOS E DISPONÍVEIS PARA VENDA
							ColocarEspaco(Info.infraestrutura);//chama função ColocarEspaco para colocar espaço nas variáveis
							printf("Informações da Infraestrutura: %s \n", Info.infraestrutura);
							ColocarEspaco(Info.endereco);//chama função ColocarEspaco para colocar espaço nas variáveis
							printf("Endereço: %s \n", Info.endereco);
							printf("Possui área de lazer?: %s\n", Info.Area_de_Lazer);
							printf("Área total: %.2f\n", Info.Area_do_terreno);
							printf("Terreno total construído: %.2f\n", Info.Area_construida_total);
							printf("Valor do Imóvel: %.2f\n", Info.valor_do_imovel);	
							printf("Nº de telefone: %s\n\n", Info.n_telefone);
		 			 }
		  			 fclose(Ponteiro);//feche (---.txt);
		  			 printf("Listagem concluída!\n\n");//Coloque em tela("---");
				}


				cracha3://Ponto usado em conjunto ao comando goto, usado posteriormente
				PonteiroNovo = fopen("Corretores.txt", "r");// variável PonteiroNovo é igual a Abra("---.txt", "modo leitura");
				printf("Por favor informe o crachá: "); scanf("%i", &cracha); puts("");//pede ao usuário que informe seu crachá, Lê e armazena na variável cracha
				while(!feof(PonteiroNovo))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "---.txt");
				{
				
					fscanf(PonteiroNovo, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);		
					// Lê as informações contidas no arquivo 
					
					if(Info2.numero_do_cracha == cracha)// Se (variável Info2.numero_do_cracha for igual a variável cracha) Info3.numero_do_crachá recebe o valor da variável crachá.
					{
						Info3.numero_do_cracha = cracha;//Info3.numero-do_cracha recebe valor da variável cracha
					}
				}//fim do laço de repetição
				fclose(PonteiroNovo);//feche(Corretores.txt);
				
				if (Info3.numero_do_cracha == 0)//se (Info3.numero_do_cracha for igual a 0) significa que o crachá informado não foi encontrado
				{
					printf("Crachá não existe/não registrado!\n\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o crachá não existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// lê o valor e armazena na variável op
					
					if (op == 1)//se op for igual a 1
					{
						goto cracha3;//volta no ponto cracha, definido previamente
					} 
					else//se não
					{
						goto fim;// vai até o ponto fim, definido posteriormente 
					}
				}	//fim da comparação 

				id3://Ponto usado em conjunto ao comando goto, usado posteriormente
				printf("Digite o ID do apartamento: "); scanf("%i", &id); puts("\n");//pede ao usuário que informe seu id, lê e armazena na variável id
				Ponteiro = fopen("Chacaras.txt", "r");// variável Ponteiro é igual a Abra("----.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em Ponteiro);
				{
					fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
					// Lê as informações contidas no arquivo
					
					if(id == Info.ID)// se Info.ID for igual a varável id (Se algum ID no arquivo for igual ao id informado para aluguel)
					{
						
						vf = 1;//vf é igual a 1 (servirá para comparação posteriormente)
						PonteiroNovo2 = fopen("ChacarasVendidos.txt", "a+");// variável PonteiroNovo2 é igual a Abra("----.txt", "modo escrita");
						fprintf(PonteiroNovo2, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info3.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
						fclose(PonteiroNovo2);
					}	
				}
				fclose(Ponteiro);//fecha (---.txt)
				
				//vf foi definido previamente como 0.	
				if (vf == 0)//se (vf for igual a 0) significa que o id informado não foi encontrado
				{
					printf("ID não existe/não registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o id não existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// lê o valor e armazena na variável op
					if (op == 1)//se op for igual a 1
					{
						goto id3;//volta no ponto id, definido previamente
					} 
					else//se não
					{
						goto fim;// vai até o ponto fim, definido posteriormente 
					}
				}//fim da comparação 
				
				Ponteiro = fopen("Chacaras.txt","r"); // variável Ponteiro é igual a Abra("---.txt", "modo leitura");
				PonteiroNovo = fopen("Chacaras_novo.txt", "w"); // variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
						
						while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 
							// Lê as informações contidas no arquivo
							
							if (Info.ID != id) // se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{	
								fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
								//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del Chacaras.txt");//sistema (delete arquivo ----.txt)
						system("rename Chacaras_novo.txt Chacaras.txt");//sistema (renomeie ----.txt para ---.txt)
						break;	//saia do switch

			case 4://se op = 4
					printf("<1> ::: Listar Terrenos disponíveis para venda:\n<2> ::: Continuar sem listar\n "); printf("Operação: "); scanf("%i", &op); puts("/n"); system("cls");
					//pergunta ao usuário a respeito da operação desejada. 
					if(op == 1)
					{
						system("cls"); // limpa a tela
					
						Ponteiro = fopen("Terrenos.txt", "r");//Variável Ponteiro = Abra ("---.txt", "no modo de leitura de informações");
						while (!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em("---.txt"));
						{
						    fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
							// Lê as informações contidas no arquivo 
							
							printf("ID: %i \n", Info.ID);
							printf("Área total: %.2f\n", Info.Area_do_terreno);
							printf("Valor do Imóvel: %.2f\n", Info.valor_do_imovel); //EXIBE TODAS AS INFORMAÇÔES SOBRE TODOS OS IMÓVEIS REGISTRADOS E DISPONÍVEIS PARA VENDA	
							printf("Endereço: %s\n", Info.endereco);
							printf("Nº de telefone: %s\n\n", Info.n_telefone);
		 			 	}
		  			 	fclose(Ponteiro);//feche (---.txt);
		  				 printf("Listagem concluída!\n\n");//Coloque em tela("---");
					}


		
			
				cracha4://Ponto usado em conjunto ao comando goto, usado posteriormente
				PonteiroNovo = fopen("Corretores.txt", "r");// variável PonteiroNovo é igual a Abra("---.txt", "modo leitura");
				printf("Por favor informe o crachá: "); scanf("%i", &cracha); puts("");//pede ao usuário que informe seu crachá, Lê e armazena na variável cracha
				while(!feof(PonteiroNovo))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "---.txt");
				{
				
					fscanf(PonteiroNovo, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);		
					// Lê as informações contidas no arquivo 
					
					
					if(Info2.numero_do_cracha == cracha)// Se (variável Info2.numero_do_cracha for igual a variável cracha) Info3.numero_do_crachá recebe o valor da variável crachá.
					{
						Info3.numero_do_cracha = cracha;//Info3.numero-do_cracha recebe valor da variável cracha
					}
				}//fim do laço de repetição
				
				fclose(PonteiroNovo);//feche(Corretores.txt);
				
				if (Info3.numero_do_cracha == 0)//se (Info3.numero_do_cracha for igual a 0) significa que o crachá informado não foi encontrado
				{
					printf("Crachá não existe/não registrado!\n\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o crachá não existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// lê o valor e armazena na variável op
					
					if (op == 1)//se op for igual a 1
					{
						goto cracha4;//volta no ponto cracha, definido previamente
					} 
					else//se não
					{
						goto fim;// vai até o ponto fim, definido posteriormente 
					}
				}	//fim da comparação 

				id4://Ponto usado em conjunto ao comando goto, usado posteriormente
				printf("Digite o ID do apartamento: "); scanf("%i", &id); puts(""); //pede ao usuário que informe seu id, lê e armazena na variável id
				Ponteiro = fopen("Terrenos.txt", "r");// variável Ponteiro é igual a Abra("----.txt", "modo leitura");
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em Ponteiro);
				{
					fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
					// Lê as informações contidas no arquivo
					
					if(id == Info.ID)// se Info.ID for igual a varável id (Se algum ID no arquivo for igual ao id informado para aluguel)
					{
						vf = 1;//vf é igual a 1 (servirá para comparação posteriormente)
						PonteiroNovo2 = fopen("TerrenosVendidos.txt", "a+");// variável PonteiroNovo2 é igual a Abra("----.txt", "modo escrita")
						fprintf(PonteiroNovo2, "%i %i %f %f %s %s\n", Info.ID, Info3.numero_do_cracha, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);
						//insira no arquivo(PonteiroNovo2, "as informações contidas em Ponteiro + o número do crachá do corretor intermediário da operação
						
						fclose(PonteiroNovo2);//fecha (PonteiroNovo2)
					}	
				}
				fclose(Ponteiro);//fecha (Ponteiro)
				
				//vf foi definido previamente como 0.
				if (vf == 0)//se (vf for igual a 0) significa que o id informado não foi encontrado
				{
					printf("ID não existe/não registrado!\n<1> ::: Tentar Novamente?\n<2+> ::: Sair "); scanf ("%i", &op); system("cls");
					// o sistema exibe uma mensagem informando que o id não existe e o questiona 
					// tentar novamente 1
					// sair 2+
					// lê o valor e armazena na variável op
					
					if (op == 1)//se op for igual a 1
					{
						goto id4;//volta no ponto id, definido previamente
					} 
					else//se não
					{
						goto fim;// vai até o ponto fim, definido posteriormente 
					}
				}	//fim da comparação 
				
				Ponteiro = fopen("Terrenos.txt","r"); // variável Ponteiro é igual a Abra("---.txt", "modo leitura");
				PonteiroNovo = fopen("Terrenos_novo.txt", "w"); // variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
						
						while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
						{
							fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
							// Lê as informações contidas no arquivo
							if (Info.ID != id) // se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{	
								fprintf(PonteiroNovo, "%i %f %f %s %s\n", Info.ID, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);	
								//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del Terrenos.txt");//sistema (delete arquivo ----.txt)
						system("rename Terrenos_novo.txt Terrenos.txt");//sistema (renomeie ----.txt para ---.txt)
						break;	//saia do switch					
			default://se nenhuma comparação correspondeu
				break;//saia do switch
				
			}	//fim do switch		
		fim://Ponto usado em conjunto ao comando goto, usado previamente
		printf("Operação Finalizada!\n\n");//Coloque em tela("---");
		
		return 0;//retorne 0

}
	
			

	
void excluir_registros()//cria uma função do tipo vazio de nome Excluir Registros()
{
	Corretor Info2; //cria uma variável do tipo Corretor de nome Info2
	Ficha_Tecnica_Imovel Info; //cria uma variável do tipo Ficha_Tecnica_Imovel de nome Info
	int id, op, vf = 0, op3 = -1; //cria variávei do tipo inteiro de nomes...;
	FILE* PonteiroNovo;	//cria uma variável do tipo FILE de nome PonteiroNovo
	
	printf("::: Excluir Registros ::;\n\n"); //c
	puts("<1> ::: Excluir Imóvel à venda");
	puts("<2> ::: Excluir Corretor");
	puts("<3> ::: Excluir Imóvel Vendido");
	puts("<4> ::: Excluir Imóvel à alugar");
	puts("<5> ::: Excluir Imóvel alugado");
	puts("<6+> :::Sair");
	printf("Operação: "); scanf("%i", &op); puts("");
	system("cls");
	//exibe um menu e pergunta ao usuário que operação deseja realizar
	//lê o valor e armazena na variável op
	//limpa a tela
	
	switch (op)//compare (op)
	{
		case 1://se op = 1
			printf("::: Excluir Imóvel à venda :::\n\n");
			puts("<1> ::: Apartamento");
			puts("<2> ::: Casa");
			puts("<3> ::: Chácara");
			puts("<4> ::: Terreno");
			puts("<5+> ::: Sair");
			printf("Operação: "); scanf("%i", &op); puts("");
			system("cls");
			//Mostra opção que o usuário escolheu anteriormente
			//exibe um menu e pergunta ao usuário que operação deseja realizar
			//limpa a tela
			
				switch (op)
				{	
					case 1://se op = 1
						printf("::: Excluir apartamento<s> à venda :::\n\n");//Mostra opção que o usuário escolheu anteriormente
						r://Ponto usado em conjunto ao comando goto, usado posteriormente
	
						printf("Informe o ID do apartamento que deseja remover: "); scanf("%i", &id); puts("");
						//pede ao usuário que digite o id do imovel que deseja excluir
						Ponteiro = fopen("Apartamentos.txt", "r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");
						FILE* PonteiroNovo = fopen("Apartamentos_novo.txt","w"); // variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
		
						while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas em "----.txt");
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 
							// Lê as informações contidas no arquivo
							
							//vf foi definido previamente como 0.
							if (Info.ID == id) //se Info.ID for igual a id (significa que o programa achou a informação a ser excluída)
							{
								vf = 1;	//vf recebe 1 
							}	
							
							if (id != Info.ID) // se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{
								fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
								//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
							}					      
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo); // fechar o uso do arquivo
	
						system("del Apartamentos.txt");//sistema (delete arquivo ----.txt)
						system("rename Apartamentos_novo.txt Apartamentos.txt");//sistema (renomeie ----.txt para ---.txt)
					    if (vf == 0) //se vf for igual a 0(significa que o sistema não achou nenhum dado a ser excluído, portanto nada foi feito)
						{ 
							printf("Erro! Id informado não existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
							printf("Operação: "); scanf("%i", &op); puts("\n");
							//exibe uma mensagem informando o usuário 
							//Lê o valor inserido e armazena na variável op
							//pula 2 linhas
							
							if (op == 1)//se op for igual a 1
							{
								goto r;//vá para o ponto r
							}//se op for igual a 2, a verificação acontece e o sistema volta a tela inicial	
						}
						goto fim;//vá para o ponto fim
					
						
					case 2://se op = 2
						printf("::: Excluir casa<s> à venda :::\n\n");//exibe opção escolhida pelo usuário anteriormente
						
						r2://Ponto usado em conjunto ao comando goto, usado posteriormente
						
						printf("Informe o ID que deseja remover: "); scanf("%i", &id); puts("");//pede ao usuário que digite o id do imóvel que deseja excluir
						
						Ponteiro = fopen("Casa.txt","r"); // variável Ponteiro é igual a Abra("---.txt", "modo leitura");
						FILE* PonteiroNovo2 = fopen("Casa_novo.txt","w"); // variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
						
						while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 
							// Lê as informações contidas no arquivo]
							
							if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informação a ser excluída)
							{
								vf = 1;	//vf recebe 1 
							}	
							
							if (Info.ID != id) // se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{
								fprintf(PonteiroNovo2, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
				 				//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo2); // fechar o uso do arquivo
						
						system("del Casa.txt");//sistema (delete arquivo ----.txt)
						system("rename Casa_novo.txt Casa.txt");//sistema (renomeie ----.txt para ---.txt)

						if (vf == 0)//se vf for igual a 0(significa que o sistema não achou nenhum dado a ser excluído, portanto nada foi feito)
						{ 
							printf("Erro! Id informado não existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
							printf("Operação: "); scanf("%i", &op); puts("\n");
							//exibe uma mensagem informando o usuário 
							//Lê o valor inserido e armazena na variável op
							//pula 2 linhas

							//se op for igual a 1
							if (op == 1)
							{
								goto r2;//vá para o ponto r2
							}//se op for igual a 2, a verificação acontece e o sistema volta a tela inicial	
						}
						goto fim;//vá para o ponto fim
						
					case 3://se op = 3
						printf("::: Excluir chácara<s> à venda :::\n\n");//exibe opção escolhida pelo usuário anteriormente
						r3://Ponto usado em conjunto ao comando goto, usado posteriormente
						printf("Informe o ID que deseja remover: "); scanf("%i", &id); puts("");//pede ao usuário que digite o id do imóvel que deseja excluir
	
						Ponteiro = fopen("Chacaras.txt","r"); // variável Ponteiro é igual a Abra("---.txt", "modo leitura");

						FILE* PonteiroNovo3 = fopen("Chacaras_novo.txt","w"); // variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
		
						while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
						{
							fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	 
							// Lê as informações contidas no arquivo
							
							if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informação a ser excluída)
							{
								vf = 1;	//vf recebe 1 
							}	
							if (Info.ID != id) // se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{
								fprintf(PonteiroNovo3, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone); 
								//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo3); // fechar o uso do arquivo
	
						system("del Chacaras.txt");//sistema (delete arquivo ----.txt)
						system("rename Chacaras_novo.txt Chacaras.txt");//sistema (renomeie ----.txt para ---.txt)
					
						if (vf == 0)//se vf for igual a 0(significa que o sistema não achou nenhum dado a ser excluído, portanto nada foi feito)
						{ 
							printf("Erro! Id informado não existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
							printf("Operação: "); scanf("%i", &op); puts("\n");
							//exibe uma mensagem informando o usuário 
							//Lê o valor inserido e armazena na variável op
							//pula 2 linhas
						
							if (op == 1)//se op for igual a 1
							{
								goto r3;//vá para o ponto r3								
							}	//se op for igual a 2, a verificação acontece e o sistema volta a tela inicial
						}
						goto fim;//vá para o ponto fim
					
					case 4://se op = 4
						printf("::: Excluir terreno<s> à venda :::\n\n");//exibe opção escolhida pelo usuário anteriormente
						r4:
						printf("Informe o ID que deseja remover: "); scanf("%i", &id); puts("");//pede ao usuário que digite o id do imóvel que deseja excluir
	
						Ponteiro = fopen("Terrenos.txt","r"); // variável Ponteiro é igual a Abra("---.txt", "modo leitura");
						FILE* PonteiroNovo4 = fopen("Terrenos_novo.txt","w"); // variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
		
						while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
						{
							fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
							// Lê as informações contidas no arquivo
							if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informação a ser excluída)
							{
								vf = 1;	//vf recebe 1 							
							}	
							
							if (Info.ID != id) // se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
							{
								fprintf(PonteiroNovo4, "%i %f %f %s %s\n", Info.ID, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);
								//insira no arquivo(PonteiroNovo4, "as informações contidas no arquivo " Ponteiro)
							}
						}
						fclose(Ponteiro); // fechar o uso do arquivo
						fclose(PonteiroNovo4); // fechar o uso do arquivo
						
						system("del Terrenos.txt");//sistema (delete arquivo ----.txt)
						system("rename Terrenos_novo.txt Terrenos.txt");//sistema (renomeie ----.txt para ---.txt)
						if (vf == 0)//se vf for igual a 0(significa que o sistema não achou nenhum dado a ser excluído, portanto nada foi feito)
						{ 
							printf("Erro! Id informado não existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
							printf("Operação: "); scanf("%i", &op); puts("\n");
							//exibe uma mensagem informando o usuário 
							//Lê o valor inserido e armazena na variável op
							//pula 2 linhas
							
							if (op == 1)//se op for igual a 1
							{
								goto r4;//vá para o ponto r4
							}	
						}
						goto fim;//vá para o ponto fim
						
					default://se nenhum dos case corresponder:
						goto fim;//vá para o ponto fim
				}
	
		case 2://se op = 2
				puts("\n::: Excluir Corretor :::\n\n ");//exibe opção escolhida pelo usuário anteriormente
				r5://Ponto usado em conjunto ao comando goto, usado posteriormente
				printf("Informe o crachá do Corretor que deseja remover: "); scanf("%i", &id); puts("");
				//pede ao usuário que digite o cracha do corretor que deseja excluir
				Ponteiro = fopen("Corretores.txt","r"); // variável Ponteiro é igual a Abra("---.txt", "modo leitura");
				FILE* PonteiroNovo5 = fopen("Corretores_novo.txt","w"); // variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
				while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
				{
					fscanf(Ponteiro, "%i %s %s %s %i %f %f\n", &Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, &Info2.idade, &Info2.salario_b, &Info2.comissao_pvenda);
					// Lê as informações contidas no arquivo
					
					if (Info2.numero_do_cracha == id)//se Info.ID for igual a id (significa que o programa achou a informação a ser excluída)
					{
						vf = 1;//vf recebe 1 
					}
					if (Info2.numero_do_cracha != id) // se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
					{
						fprintf(PonteiroNovo5, "%i %s %s %s %i %f %f\n", Info2.numero_do_cracha, Info2.nome, Info2.data_contratacao, Info2.data_nascimento, Info2.idade, Info2.salario_b, Info2.comissao_pvenda);
						//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
					}
				}
				fclose(Ponteiro); // fechar o uso do arquivo
				fclose(PonteiroNovo5);// fechar o uso do arquivo
		
				system("del Corretores.txt");//sistema (delete arquivo ----.txt)
				system("rename Corretores_novo.txt Corretores.txt");	//sistema (renomeie ----.txt para ---.txt)
				if (vf == 0)//se vf for igual a 0(significa que o sistema não achou nenhum dado a ser excluído, portanto nada foi feito)
				{ 
					printf("Erro! Crachá informado não existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
					printf("Operação: "); scanf("%i", &op); puts("\n");
					//exibe uma mensagem informando o usuário 
					//Lê o valor inserido e armazena na variável op
					//pula 2 linhas				
				
					if (op == 1)//se op for igual a 1
					{
						goto r5;//vá para o ponto r5
					}//se op for igual a 2, a verificação acontece e o sistema volta a tela inicial	
				}
				goto fim;//vá para o ponto fim
		
		case 3:  //se op = 3
				printf("::: Excluir Imóvel Vendido :::\n\n");//exibe opção escolhida pelo usuário anteriormente
				puts("<1> :::  Apartamentos");
				puts("<2> :::  Casa");
				puts("<3> :::  Chácara");
				puts("<4> :::  Terreno");
				puts("<5+> ::: Sair"); printf("Operação: "); scanf("%i", &op); puts("");
				system("cls");
				//Mostra opção que o usuário escolheu anteriormente
				//exibe um menu e pergunta ao usuário que operação deseja realizar
				//le o valor informado e armazena na variável op
				//limpa a tela
			
				switch (op)//compare(op)
				{
						case 1://se op = 1
							printf("::: Excluir Apartamento<s> Vendido<s> :::\n\n");//exibe opção escolhida pelo usuário anteriormente
							r6://Ponto usado em conjunto ao comando goto, usado posteriormente
							puts("Informe o ID do apartamento a ser excluído: "); printf("Operação: "); scanf("%i", &id); puts(""); 
							//pede ao usuário que digite o id do imóvel que deseja excluir
							
							Ponteiro = fopen("ApartamentosVendidos.txt", "r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");
							FILE* PonteiroNovo = fopen("ApartamentosVendidos_Novo.txt", "w");// variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
							
							while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
							{
					
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n",&Info2.numero_do_cracha, &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
								// Lê as informações contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informação a ser excluída)
								{
									vf = 1;//vf recebe 1 
								}
								if(id != Info.ID)// se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info2.numero_do_cracha, Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
								}	
							}
							fclose(PonteiroNovo);// fechar o uso do arquivo
							fclose(Ponteiro);// fechar o uso do arquivo
							system("del ApartamentosVendidos.txt");//sistema (delete arquivo ----.txt)
							system("rename ApartamentosVendidos_novo.txt ApartamentosVendidos.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema não achou nenhum dado a ser excluído, portanto nada foi feito)
							{ 
								printf("Erro! Crachá informado não existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Operação: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usuário 
								//Lê o valor inserido e armazena na variável op
								//pula 2 linhas
								
								if (op == 1)//se op for igual a 1
								{
									goto r6;//vá para o ponto r6

								}//se op for igual a 2, a verificação acontece e o sistema volta a tela inicial		
							}
							
							goto fim;//vá para o ponto fim
						
						case 2://se op = 2
							printf("::: Remover casa<s> vendida<s> :::\n\n");//exibe opção escolhida pelo usuário anteriormente
							r7://Ponto usado em conjunto ao comando goto, usado posteriormente
							puts("Informe o ID do apartamento a ser excluído: "); printf("Operação: "); scanf("%i", &id); puts(""); 
							//pede ao usuário que digite o id do imóvel que deseja excluir
							
							Ponteiro = fopen("CasaVendidos.txt", "r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");
							PonteiroNovo = fopen("Casavendidos_Novo.txt", "w");// variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
							
							while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
							{
					
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n",&Info2.numero_do_cracha, &Info.ID,  &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
								// Lê as informações contidas no arquivo

								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informação a ser excluída)
								{
									vf = 1;//vf recebe 1 
								}
								
								if(id != Info.ID)// se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info2.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);			
									//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
								}	
							}
							fclose(PonteiroNovo);// fechar o uso do arquivo
							fclose(Ponteiro);// fechar o uso do arquivo
							system("del Casavendidos.txt");//sistema (delete arquivo ----.txt)
							system("rename Casavendidos_novo.txt CasaVendidos.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema não achou nenhum dado a ser excluído, portanto nada foi feito)
							{ 
								printf("Erro! Crachá informado não existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Operação: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usuário 
								//Lê o valor inserido e armazena na variável op
								//pula 2 linhas
								if (op == 1)//se op for igual a 1
								{
									goto r7;//vá para o ponto r7
								}//se op for igual a 2, a verificação acontece e o sistema volta a tela inicial	
							}
							
							goto fim;//vá para o ponto fim
					
						case 3://se op = 3
							printf("::: Remover Chácara<s> Vendida<s> :::\n\n");//exibe opção escolhida pelo usuário anteriormente
							r8://Ponto usado em conjunto ao comando goto, usado posteriormente
							puts("Informe o ID do apartamento a ser excluído: "); printf("Operação: "); scanf("%i", &id); puts(""); 
							//pede ao usuário que digite o id do imóvel que deseja excluir
							Ponteiro = fopen("ChacarasVendidos.txt", "r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");
							PonteiroNovo = fopen("Chacarasvendidos_Novo.txt", "w");// variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
							
							while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
							{
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n",&Info2.numero_do_cracha, &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
								// Lê as informações contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informação a ser excluída)
								{
									vf = 1;//vf recebe 1 
								}

								if(id != Info.ID)// se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info2.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
								}	
							}
							fclose(PonteiroNovo);// fechar o uso do arquivo
							fclose(Ponteiro);// fechar o uso do arquivo
							system("del Chacarasvendidos.txt");//sistema (delete arquivo ----.txt)
							system("rename Chacarasvendidos_novo.txt ChacarasVendidos.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema não achou nenhum dado a ser excluído, portanto nada foi feito)
							{ 
								printf("Erro! Crachá informado não existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Operação: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usuário 
								//Lê o valor inserido e armazena na variável op
								//pula 2 linhas
								
								if (op == 1)//se op for igual a 1
								{
									goto r8;//vá para o ponto r8
								}	//se op for igual a 2, a verificação acontece e o sistema volta a tela inicial
							}
							
							
							goto fim;//vá para o ponto fim
							
						case 4:
							printf("::: Remover Terreno<s> Vendido<s> :::\n\n");//exibe opção escolhida pelo usuário anteriormente
							r9://Ponto usado em conjunto ao comando goto, usado posteriormente
							printf("Informe o ID que deseja remover: "); scanf("%i", &id); puts("");//pede ao usuário que digite o id do imóvel que deseja excluir
	
							Ponteiro = fopen("TerrenosVendidos.txt","r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");
							FILE* PonteiroNovo4 = fopen("TerrenosVendidos_novo.txt","w"); // variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
		
							while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
							{
								fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
								// Lê as informações contidas no arquivo

								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informação a ser excluída)
								{
									vf = 1;//vf recebe 1
								}
							
								if (Info.ID != id) // se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo4, "%i %f %f %s %s\n", Info.ID, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);	
									//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
								}
							}
							fclose(Ponteiro); // fechar o uso do arquivo
							fclose(PonteiroNovo4); // fechar o uso do arquivo
						
							system("del TerrrenosVendidos.txt");//sistema (delete arquivo ----.txt)
							system("rename TerrenosVendidos_novo.txt TerrenosVendidos.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema não achou nenhum dado a ser excluído, portanto nada foi feito)
							{ 
								printf("Erro! Crachá informado não existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Operação: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usuário 
								//Lê o valor inserido e armazena na variável op
								//pula 2 linhas
								if (op == 1)//se op for igual a 1
								{
									goto r9;//vá para o ponto r9
								}	//se op for igual a 2, a verificação acontece e o sistema volta a tela inicial
							}
							
							goto fim;//vá para o ponto fim
				
				}//Fim do switch para exclusão de artigos vendidos
			
		case 4: 
				puts("\n::: Excluir Imóvel à alugar :::\n\n");
				puts("<1> :::  Terreno");
				puts("<2> :::  Casa");
				puts("<3> :::  Chácara");
				puts("<4> :::  Apartamento");
				puts("<5+> ::: Sair"); printf("Operação: "); scanf("%i", &op); puts("");
				system("cls");
			
				//Mostra opção que o usuário escolheu anteriormente
				//exibe um menu e pergunta ao usuário que operação deseja realizar
				//le o valor informado e armazena na variável op
				//limpa a tela
				FILE* PonteiroNovo4; //cria uma variável do tipo File de nome PonteiroNovo4
				switch(op) //compare op
				{
					case 1://se op = 1
							printf("::: Excluir Terreno<s> à alugar :::\n\n");//exibe opção escolhida pelo usuário anteriormente
							r10://Ponto usado em conjunto ao comando goto, usado posteriormente
							printf("Informe o ID que deseja remover: "); scanf("%i", &id); puts("");//pede ao usuário que digite o id do imóvel que deseja excluir
	
							Ponteiro = fopen("AlugarTerrenos.txt","r"); // variável Ponteiro é igual a Abra("---.txt", "modo leitura");
							PonteiroNovo4 = fopen("AlugarTerrenos_novo.txt","w"); // variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
		
							while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
							{
								fscanf(Ponteiro, "%i %f %f %s %s\n", &Info.ID, &Info.Area_do_terreno, &Info.valor_do_imovel, Info.endereco, Info.n_telefone);
								// Lê as informações contidas no arquivo
								
								//se Info.ID for igual a id (significa que o programa achou a informação a ser excluída)
								if (Info.ID == id)
								{
									vf = 1;	//vf recebe 1 
								}	
								if (Info.ID != id)// se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo4, "%i %f %f %s %s\n", Info.ID, Info.Area_do_terreno, Info.valor_do_imovel, Info.endereco, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
								}
							}
							fclose(Ponteiro); // fechar o uso do arquivo
							fclose(PonteiroNovo4);// fechar o uso do arquivo
						
							system("del AlugarTerrenos.txt");//sistema (delete arquivo ----.txt)
							system("rename AlugarTerrenos_novo.txt AlugarTerrenos.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema não achou nenhum dado a ser excluído, portanto nada foi feito)
							{ 
								printf("Erro! Crachá informado não existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Operação: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usuário
								//Lê o valor inserido e armazena na variável op
								//pula 2 linhas
								if (op == 1)//se op for igual a 1
								{
									goto r10;//vá para o ponto r10

								}	//se op for igual a 2, a verificação acontece e o sistema volta a tela inicial	
							}
							
							goto fim;//vá para o ponto fim
				
					case 2://se op = 2
							printf("::: Excluir Casa<s> à alugar :::\n\n");//exibe opção escolhida pelo usuário anteriormente
							r11://Ponto usado em conjunto ao comando goto, usado posteriormente
							printf("Informe o ID que deseja remover: "); scanf("%i", &id); puts("");//pede ao usuário que digite o id do imóvel que deseja excluir
	
							Ponteiro = fopen("AlugarCasa.txt","r"); // variável Ponteiro é igual a Abra("---.txt", "modo leitura");
							PonteiroNovo4 = fopen("AlugarCasa_novo.txt","w"); // variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
		
							while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
							{
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);
								// Lê as informações contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informação a ser excluída)
								{
									vf = 1;	//vf recebe 1
								}	
								
								if (Info.ID != id) // se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
								}
							}
							fclose(Ponteiro); // fechar o uso do arquivo
							fclose(PonteiroNovo4); // fechar o uso do arquivo
						
							system("del AlugarCasa.txt");//sistema (delete arquivo ----.txt)
							system("rename AlugarCasa_novo.txt AlugarCasa.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema não achou nenhum dado a ser excluído, portanto nada foi feito)
							{ 
								printf("Erro! Crachá informado não existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Operação: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usuário 
								//Lê o valor inserido e armazena na variável op
								//pula 2 linhas
								
								if (op == 1)//se op for igual a 1
								{
									goto r11;//vá para o ponto r11
								}	
							}//se op for igual a 2, a verificação acontece e o sistema volta a tela inicial
							
							goto fim;//vá para o ponto fim
					
					case 3://se op = 3
							printf("::: Excluir Chácara<s> à alugar :::\n\n");//exibe opção escolhida pelo usuário anteriormente
							r12://Ponto usado em conjunto ao comando goto, usado posteriormente
							printf("Informe o ID que deseja remover: "); scanf("%i", &id); puts("");//pede ao usuário que digite o id do imóvel que deseja excluir
	
							Ponteiro = fopen("AlugarChacaras.txt","r"); // variável Ponteiro é igual a Abra("---.txt", "modo leitura");
							PonteiroNovo4 = fopen("AlugarChacaras_novo.txt","w"); // variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
		
							while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
							{
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);
								// Lê as informações contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informação a ser excluída)
								{
									vf = 1;	//vf recebe 1 
								}	
								
								if (Info.ID != id) // se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(Ponteiro, "%i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
								}
							}
							fclose(Ponteiro); // fechar o uso do arquivo
							fclose(PonteiroNovo4); // fechar o uso do arquivo
						
							system("del AlugarChacaras.txt");//sistema (delete arquivo ----.txt)
							system("rename AlugarChacaras_novo.txt AlugarChacaras.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema não achou nenhum dado a ser excluído, portanto nada foi feito)
							{ 
								printf("Erro! Crachá informado não existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Operação: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usuário 
								//Lê o valor inserido e armazena na variável op
								//pula 2 linhas
								
								if (op == 1)//se op for igual a 1
								{
									goto r12;//vá para o ponto r12
								}	//se op for igual a 2, a verificação acontece e o sistema volta a tela inicial	
							}
							
							goto fim;//vá para o ponto fim
					
					case 4://se op = 4
							printf("::: Excluir Apartamento<s> à alugar :::\n\n");//exibe opção escolhida pelo usuário anteriormente
							r13://Ponto usado em conjunto ao comando goto, usado posteriormente
							printf("Informe o ID que deseja remover: "); scanf("%i", &id); puts("");//pede ao usuário que digite o id do imóvel que deseja excluir
	
							Ponteiro = fopen("AlugarApartamentos.txt","r"); // variável Ponteiro é igual a Abra("---.txt", "modo leitura");
							PonteiroNovo4 = fopen("AlugarApartamentos_novo.txt","w"); // variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
		
							while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
							{
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);
								// Lê as informações contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informação a ser excluída)
								{
									vf = 1;	//vf recebe 1 
								}	
								
								if (Info.ID != id)// se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
								}
							}
							fclose(Ponteiro); // fechar o uso do arquivo
							fclose(PonteiroNovo4); // fechar o uso do arquivo
						
							system("del AlugarApartamentos.txt");//sistema (delete arquivo ----.txt)
							system("rename AlugarApartamentos_novo.txt AlugarApartamentos.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema não achou nenhum dado a ser excluído, portanto nada foi feito
							{ 
								printf("Erro! Crachá informado não existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Operação: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usuário 
								//Lê o valor inserido e armazena na variável op
								//pula 2 linhas
								
								if (op == 1)//se op for igual a 1
								{
									goto r13;//vá para o ponto r13
								}	//se op for igual a 2, a verificação acontece e o sistema volta a tela inicial
							}
							
							goto fim;//vá para o ponto fim

					
					default://se nenhum dos case corresponder
						goto fim;//vá para o ponto fim
											
				}			
				
		case 5://se op = 5
				puts("\n::: Excluir Imóvel alugado :::\n\n");
				puts("<1> :::  Apartamento");
				puts("<2> :::  Casa");
				puts("<3> :::  Chácara");
				puts("<4> :::  Terreno");
				puts("<5+> ::: Sair"); printf("Operação: "); scanf("%i", &op); puts("");
				system("cls");
				//Mostra opção que o usuário escolheu anteriormente
				//exibe um menu e pergunta ao usuário que operação deseja realizar
				//le o valor informado e armazena na variável op
				//limpa a tela
				switch (op)//compare (op)
				{
					case 1://se op = 1
							printf("::: Excluir Apartamento alugado :::\n\n");//exibe opção escolhida pelo usuário anteriormente
							r14://Ponto usado em conjunto ao comando goto, usado posteriormente
							puts("Informe o ID do apartamento a ser excluído: "); printf("Operação: "); scanf("%i", &id); puts(""); //pede ao usuário que digite o id do imóvel que deseja excluir
							
							Ponteiro = fopen("ApartamentosAlugados.txt", "r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");
							PonteiroNovo = fopen("ApartamentosAlugados_Novo.txt", "w");// variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
							
							while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
							{
					
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n",&Info2.numero_do_cracha, &Info.ID, &Info.andar, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
								// Lê as informações contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informação a ser excluíd
								{
									vf = 1;//vf recebe 1 
								}
								if(id != Info.ID)// se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info2.numero_do_cracha, Info.ID, Info.andar, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
								}	
							}
							fclose(PonteiroNovo);// fechar o uso do arquivo
							fclose(Ponteiro);// fechar o uso do arquivo
							system("del ApartamentosAlugados.txt");//sistema (delete arquivo ----.txt)
							system("rename ApartamentosAlugados_novo.txt ApartamentosAlugados.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema não achou nenhum dado a ser excluído, portanto nada foi feito)
							{ 
								printf("Erro! ID informado não existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Operação: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usuário 
								//Lê o valor inserido e armazena na variável op
								//pula 2 linhas

								
								
								if (op == 1)//se op for igual a 1
								{
									goto r14;//vá para o ponto r14
								}	//se op for igual a 2, a verificação acontece e o sistema volta a tela inicial
							}
							
							goto fim;//vá para o ponto fim

					case 2:	//se op = 2			
							printf("::: Excluir Casa alugada :::\n\n");//exibe opção escolhida pelo usuário anteriormente
							r15://Ponto usado em conjunto ao comando goto, usado posteriormente
							puts("Informe o ID do apartamento a ser excluído: "); printf("Operação: "); scanf("%i", &id); puts(""); //pede ao usuário que digite o id do imóvel que deseja excluir

							
							Ponteiro = fopen("CasaAlugados.txt", "r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");
							PonteiroNovo = fopen("CasaAlugados_Novo.txt", "w");// variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
							
							while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
							{
					
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n",&Info2.numero_do_cracha, &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
								// Lê as informações contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informação a ser excluída)
								{
									vf = 1;//vf recebe 1 
								}
								if(id != Info.ID)// se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info2.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
								}						  
							}
							fclose(PonteiroNovo);// fechar o uso do arquivo
							fclose(Ponteiro);// fechar o uso do arquivo
							system("del CasaAlugados.txt");//sistema (delete arquivo ----.txt)
							system("rename CasaAlugados_novo.txt CasaAlugados.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema não achou nenhum dado a ser excluído, portanto nada foi feito)
							{ 
								printf("Erro! ID informado não existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Operação: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usuário 
								//Lê o valor inserido e armazena na variável op
								//pula 2 linhas
								
								if (op == 1)//se op for igual a 1
								{
									goto r15;//vá para o ponto r15
								}	
							}//se op for igual a 2, a verificação acontece e o sistema volta a tela inicial
	
							goto fim;//vá para o ponto fim

					case 3://se op = 1		
							printf("::: Excluir Chácara alugada :::\n\n");//exibe opção escolhida pelo usuário anteriormente
							r16://Ponto usado em conjunto ao comando goto, usado posteriormente
							puts("Informe o ID do apartamento a ser excluído: "); printf("Operação: "); scanf("%i", &id); puts(""); //pede ao usuário que digite o id do imóvel que deseja excluir
							
							Ponteiro = fopen("ChacarasAlugados.txt", "r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");
							PonteiroNovo = fopen("ChacarasAlugados_Novo.txt", "w");// variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
							
							while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
							{
					
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n",&Info2.numero_do_cracha, &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
								// Lê as informações contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informação a ser excluída)
								{
									vf = 1;//vf recebe 1 
								}
								if(id != Info.ID)// se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info2.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
								}						  
							}
							fclose(PonteiroNovo);// fechar o uso do arquivo
							fclose(Ponteiro);// fechar o uso do arquivo
							system("del ChacarasAlugados.txt");//sistema (delete arquivo ----.txt)
							system("rename ChacarasAlugados_novo.txt ChacarasAlugados.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema não achou nenhum dado a ser excluído, portanto nada foi feito)
							{ 
								printf("Erro! ID informado não existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Operação: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usuário 
								//Lê o valor inserido e armazena na variável op
								//pula 2 linhas
								
								if (op == 1)//se op for igual a 1
								{
									goto r16;//vá para o ponto r16
								}	//se op for igual a 2, a verificação acontece e o sistema volta a tela inicial	
							}
	
							goto fim;//vá para o ponto fim
					
					case 4:	//se op = 4
							printf("::: Excluir terreno alugado :::\n\n");//exibe opção escolhida pelo usuário anteriormente
							r17://Ponto usado em conjunto ao comando goto, usado posteriormente
							puts("Informe o ID do apartamento a ser excluído: "); printf("Operação: "); scanf("%i", &id); puts(""); //pede ao usuário que digite o id do imóvel que deseja excluir
							
							Ponteiro = fopen("TerrenosAlugados.txt", "r");// variável Ponteiro é igual a Abra("---.txt", "modo leitura");
							PonteiroNovo = fopen("TerrenosAlugados_Novo.txt", "w");// variável PonteiroNovo é igual a Abra("---.txt", "modo escrita");
							
							while(!feof(Ponteiro))//enquanto (o sistema não chegar ao fim do arquivo (leia as informações contidas Ponteiro);
							{
					
								fscanf(Ponteiro, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n",&Info2.numero_do_cracha, &Info.ID, &Info.Qtd_Dormitorio, &Info.Qtd_Suite, &Info.Qtd_Sala, &Info.Qtd_Sala_de_Estar, &Info.Qtd_Cozinha, &Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, &Info.Area_do_terreno, &Info.Area_construida_total, &Info.valor_do_imovel, Info.n_telefone);	
								// Lê as informações contidas no arquivo
								
								if (Info.ID == id)//se Info.ID for igual a id (significa que o programa achou a informação a ser excluída)
								{
									vf = 1;//vf recebe 1 
								}
								if(id != Info.ID)// se Info.ID for diferente da varável id (Se algum ID no arquivo Ponteiro for diferente do id informado para aluguel)
								{
									fprintf(PonteiroNovo, "%i %i %i %i %i %i %i %i %s %s %s %f %f %f %s\n", Info2.numero_do_cracha, Info.ID, Info.Qtd_Dormitorio, Info.Qtd_Suite, Info.Qtd_Sala, Info.Qtd_Sala_de_Estar, Info.Qtd_Cozinha, Info.Qtd_Banheiro, Info.infraestrutura, Info.endereco, Info.Area_de_Lazer, Info.Area_do_terreno, Info.Area_construida_total, Info.valor_do_imovel, Info.n_telefone);
									//insira no arquivo(PonteiroNovo, "as informações contidas no arquivo " Ponteiro)
								}						  
							}
							fclose(PonteiroNovo);// fechar o uso do arquivo
							fclose(Ponteiro);// fechar o uso do arquivo
							system("del TerrenosAlugados.txt");//sistema (delete arquivo ----.txt)
							system("rename TerrenosAlugados_novo.txt TerrenosAlugados.txt");//sistema (renomeie ----.txt para ---.txt)
							if (vf == 0)//se vf for igual a 0(significa que o sistema não achou nenhum dado a ser excluído, portanto nada foi feito)
							{ 
								printf("Erro! ID informado não existe!\n<1> ::: Tentar Novamente\n<2> ::: Sair\n");
								printf("Operação: "); scanf("%i", &op); puts("\n");
								//exibe uma mensagem informando o usuário 
								//Lê o valor inserido e armazena na variável op
								//pula 2 linhas
								if (op == 1)//se op for igual a 1
								{
									goto r17;//vá para o ponto r17
								}	//se op for igual a 2, a verificação acontece e o sistema volta a tela inicial
							}
	
							goto fim;//vá para o ponto fim
					
					default://se nenhum dos case foi compatível
							goto fim;	//vá para o ponto fim
															
				}
		
		default://se nenhum dos case foi compatível, vá para o ponto fim
				return 0;	
				
	}//Switch fim para imóveis á venda
	fim://Ponto usado em conjunto ao comando goto, usado previamente
	system("cls");//limpa a tela
	printf("Fim da exclusão!\n\n");//coloque na tela("------");
}//Função Fim



int main()
{
	setlocale(LC_ALL, "Portuguese");
	 

    
	int operacao = -1; // cria uma variável do tipo inteiro com valor -1. o valor servirá para dar entrada no loop

	int i = login(i); // cria uma variável do tipo inteiro de nome i que será igual ao resultado das operações				
				     // descritas na função login(i);			
	
	system("cls"); //limpa a tela
	
	if (i == 0) // se (i for igual a 0)
	{
		return 0; //significa que o usuário desistiu de fazer login, e pediu para fechar o programa, sendo assim, o programa fecha.
				
	}

	while (operacao < 8) // cria um loop. enquanto(operacao for < 8) ele executa o corpo principal
	{	
		puts("::: Menu Principal :::\n\n");
		puts("<1> ::: Cadastrar Imóvel"); 
		puts("<2> ::: Cadastrar Corretor"); 
		puts("<3> ::: Simulação Financiamento");
		puts("<4> ::: Listar registrados");
		puts("<5> ::: Vender Imovel");
		puts("<6> ::: Alugar Imóvel");
		puts("<7> ::: Apagar Registros");
		puts("<8+> ::: Sair");
		//Lista um menu e pede para o usuário digitar uma das opções
		printf("Operação: ");
	
		scanf("%i", &operacao); puts("");    //leia ("valor inteiro", e coloque na variável operacao), que serve 
											//justamente para a comparação do while. 
		system("cls");	
		
		switch (operacao) //Compare (operacao)
		{
			case 1: //caso operacao seja igual a 1:     
			
				printf ("::: Cadastrar Imóvel :::\n\n"); //coloque na tela("::: Cadastrar Imóvel ::: \quebra de linha\quebra de linha");
			
				Imovel();  //chama a função Imovel();
			
				break;	//após feita a operação, o programa sai do switch com o comando break;	O mesmo processo se repete nas linhas abaixo.
			case 2: 
				
				corretor();			
				break;
			case 3:
				printf("::: Simulação Financiamento :::\n\n");
				SimulacaoFinanciamento();
				break;
			case 4:
				printf("::: Listar Registrados :::\n\n");
				printf("<1> ::: Imóveis p. Venda\n<2> ::: Imoveis p. Aluguel\n<3> ::: Corretores\n<4+> ::: Sair\nOperação: "); 
				// pede para o usuário digitar qual tipo imóvel deseja listar. 
			
				scanf("%i", &operacao); //lê e armazena na variável operacao
			
				system("cls"); //sistema ("limpa a tela");
			
				switch(operacao) //compare(operacao)
				{
					case 1: //caso operacao seja igual a 1. OBS: mesma lógica aplicada nas linhas abaixo.
			
						ListagemVendas(); // chama a função listagemVendas();
						break;
					case 2: 
						listaraluguel();
						break;
					case 3:
						listarcorretores();
						break;
					default: //se o switch comparou opercao com todos os case e nenhum foi compatível, ele vem até o comando default
			
						break;	//e sai da operação 
				}
				break;
				
			case 5:
				printf("::: Venda de Imóveis :::\n\n");
				venda_imovel();
				break;
			case 6:
				printf("::: Aluguel de Imóveis :::\n\n");
				alugar_imovel();
				break;
			case 7:
				printf("::: Exclusão de registros :::\n\n");
				excluir_registros();
				break;
			default:
				break;
		}
	printf("Pressione uma tecla para continuar:\n\n "); //Independente da operação requerida esta mensagem aparece e pede ao usuário para pressionar uma tecla
	getch(); //pegue(caractere digitado) e retorne ao sistema
	system("cls"); //limpa a tela
	} //Aqui o loop retorna até o while na linha 2629. se operacao for menor que 8 o programa
	 //deve repetir todo o processo descrito até aqui. se operacao for 8 ou maior o programa 
	//sai do loop e encerra o programa.
	return 0; //encerra as operações
}//Fim do corpo principal do programa
