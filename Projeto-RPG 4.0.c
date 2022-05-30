#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct ARMA{
	int categoria;
	int dano;
}arma;
arma weapon;

typedef struct VILAO{
	int pv_adv;
	int dano;
	int defesa;
	int agilidade;
	char *nomeAdv;
	
}adversario;
adversario vilao1[3];
adversario vilao2[2];
adversario vilao3;

typedef struct PERSONAGEM
{
	int pv;
	char nome[50];
	int forca;
	int cons;
	int agilidade;
	int destreza;
	arma weapon;
	int armadura;
	int pontos;
	int nivel;
} USUARIO;
USUARIO personagem;

int x = 0;
int j = 0;
int v = 0;
int d6_1, d6_2, d6_3, d4, d12;
int pocao = 0, pocaoAdv = 0;
int endBattle = 0;

void addPontos();
void armaArmadura();
void addPv();
void resultados();
void confronto1();
void confronto2();
void confronto3();

int main()
{
	personagem.pontos = 15;
	vilao1[0].nomeAdv = NULL;
	vilao1[1].nomeAdv = NULL;
	vilao1[2].nomeAdv = NULL;
	vilao2[0].nomeAdv = NULL;
	vilao2[1].nomeAdv = NULL;
	vilao3.nomeAdv = NULL;
	printf("\n\nVamos criar seu personagem!\nDigite o nome do seu personagem: ");
	scanf("%s", &personagem.nome);
	do{
	addPontos();
	}while(personagem.pontos > 0);                      
	Sleep(2000);
	
	addPv();
	
	Sleep(5000);
	system("cls");
	 
	armaArmadura();
	
	Sleep(5000);
	
	resultados();
	
	Sleep(5000);
	
	confronto1();
	
	Sleep(5000);
	
	confronto2();
	
	Sleep(5000);
	
	confronto3();
		
	return 0;
}


void addPontos()
{
	printf("\nVoce tem %d pontos para distribuir entre os seguintes atributos:\n\n[1] -> Forca\n[2] ->Constituicao\n[3] -> Agilidade\n[4] -> Destreza", personagem.pontos);
	printf("\n\nDigite o numero do atributo que voce quer adicionando pontos: ");	
	fflush(stdin);
	scanf("	%d", &x);
	if(x >= 1 && x <= 4)
	{
		switch(x)
		{
		case 1:
			printf("\nDigite a quantidadade de pontos que voce deseja adicionar em Forca: ");
			scanf(" %d", &j);
			if (j <= personagem.pontos)
			{
				personagem.forca = personagem.forca + j;
				personagem.pontos = personagem.pontos - j;
				printf("Agora voce tem %d pontos de Forca\n\n", personagem.forca);
			}
			else
			{
			
			}
			break;
	
		case 2:
			printf("\nDigite a quantidadade de pontos que voce deseja adicionar em Constituicao: ");
			scanf(" %d", &j);
			if (j <= personagem.pontos)
			{
				personagem.cons = personagem.cons + j;
				personagem.pontos = personagem.pontos - j;
				printf("Agora voce tem %d pontos de Constituicao\n\n", personagem.cons);
			}
			break;
	
		case 3:
			printf("\nDigite a quantidadade de pontos que voce deseja adicionar em Agilidade: ");
			scanf(" %d", &j);
			if (j <= personagem.pontos)
			{
				personagem.agilidade = personagem.agilidade + j;
				personagem.pontos = personagem.pontos - j;
				printf("Agora voce tem %d pontos de Agilidade\n\n", personagem.agilidade);
			}
			break;

		case 4:
			printf("\nDigite a quantidadade de pontos que voce deseja adicionar em Destreza: ");
			scanf(" %d", &j);
			if (j <= personagem.pontos)
			{
				personagem.destreza = personagem.destreza + j;
				personagem.pontos = personagem.pontos - j;
				printf("\nAgora voce tem %d pontos de Destreza\n\n", personagem.destreza);
			}
			break;
		default:
			printf("Invalido");
			break;
		}
	} 
	else
	{
		printf("\n\n Escolha Invalida.");
	}
}	
void armaArmadura()
{
	
	printf("\n-> Agora voce deve escolher qual arma voce quer usar.");
	printf("\n\nVoce tem acesso a dois tipos de arma: pesada e leve.\nCaso escolha uma arma pesada, o valor do seu dano sera definido a partir da rolagem de um dado de 12 lados + K + 50%% da sua forca.");
	printf("\nCaso escolha uma arma leve, o valor de seu dano sera definido por 2 rolagens de um dado de 6 lados + uma rolagem de um dado de 4 lados + K + Destreza");
	printf("\n[1] -> Katana(Pesada, K = 10)\n[2] -> Adaga(leve, K = 4.5)\n[3] -> Machado(Pesado, K = 8)");
	printf("Escolha a sua arma: ");
	fflush(stdin);
	scanf("%d", &j);
	switch(j)
	{
		case 1:
			srand(time(NULL));
			d12 = 1 + rand() % 12;
			if(d12 == 13)
			{
				d12 = d12 - 1;
			}
			personagem.weapon.categoria = 1;
			personagem.weapon.dano = d12 + 10 + 1.5*personagem.forca;

			printf("\n -> Voce escolheu a Katana.\n -> O Valor do dado eh %d.\n -> O valor do dano da sua arma eh %d", d12, personagem.weapon.dano);
		break;

		case 2: 
			srand(time(NULL));
			d6_1 = 1 + rand() % 6;
			d6_2 = 1 + rand() % 6;
			d4 = 1 + rand() % 4;
			if(d6_1 == 7)
			{
				d6_1 = d6_1 - 1;
			}
			if(d6_2 == 7)
			{
				d6_2 = d6_2 - 1;
			}
			if(d4 == 5)
			{
				d4 = d4 - 1;
			}
			personagem.weapon.categoria = 0;
			personagem.weapon.dano = d6_1 + d6_2 + d4 + 4 + personagem.destreza;

			printf("\n -> Voce escolheu a Adaga.\n -> O Valor do dado eh %d e %d e %d.\n -> O valor da destreza eh %d. \n -> O valor do dano da sua arma eh %d", d6_1, d6_2, d4, personagem.destreza, personagem.weapon.dano);
			printf("\n\n%d", personagem.destreza);
		break; 

		case 3:
			srand(time(NULL));
			d12 = 1 + rand() % 12;
			if(d12 == 13)
			{
				d12 = d12 - 1;
			}
			personagem.weapon.categoria = 1;
			personagem.weapon.dano = d12 + 8 + 1.5*personagem.forca;

			printf("\n -> Voce escolheu o machado.\n -> O Valor do dado eh %d.\n -> O valor da sua forca eh %d.\n -> O valor do dano da sua arma eh %d", d12, personagem.forca, personagem.weapon.dano);
		break;
	}

	printf("\n\n -> Escolha qual armadura voce quer usar:  ");
	printf("\n\n[1] -> Tunica do Aldeao(K = 4).\n[2] -> Farrapos da Vila(K = 2).\n [3] -> Armadura de Couro(K = 3).");
	printf("\nEscolha o numero da sua armadura: ");
	scanf("%d", &j);
	switch(j)
	{
		case 1:
			personagem.armadura = 4 + 1.5*personagem.cons;
			printf(" -> Voce escolheu a armadura Tunica do Aldeao.\n O valor da sua constituicao eh %d.\n -> O valor de defesa da sua armadura eh %d",personagem.cons, personagem.armadura);
		break;

		case 2: 
			personagem.armadura = 2 + 1.5*personagem.cons;
			printf(" -> Voce escolheu a armadura Farrapos da Vila.\n O valor da sua constituicao eh %d.\n -> O valor de defesa da sua armadura eh %d",personagem.cons, personagem.armadura);
		break; 

		case 3:
			personagem.armadura = 3 + 1.5*personagem.cons;
			printf(" -> Voce escolheu a armadura Armadura de Couro.\n O valor da sua constituicao eh %d.\n -> O valor de defesa da sua armadura eh %d",personagem.cons, personagem.armadura);
		break;
	}
}
void resultados()
{
	system("cls");
	printf("\n -> O seu nome eh %s.\n -> Sua vida eh %d.\n -> Sua forca eh %d.", personagem.nome, personagem.pv, personagem.forca);
	printf("\n -> Sua constituicao eh %d.\n -> Sua agilidade eh de %d.\n -> Sua destreza eh de %d.", personagem.cons, personagem.agilidade, personagem.destreza);
	if(personagem.weapon.categoria = 1)
	{
		printf("\n -> Sua arma eh do tipo pesada. O seu dano eh %d", personagem.weapon.dano);
	}
	if(personagem.weapon.categoria = 0)
	{
		printf("\n -> Sua arma eh do tipo leve. O seu dano eh %d", personagem.weapon.dano);
	}
	printf("\n -> O valor de defesa da sua armadura eh %d", personagem.armadura);
	printf("\n -> Voce tem %d pontos disponiveis.", personagem.pontos);
}
void addPv()
{
	srand(time(NULL));
		d6_1 = 1 + rand() % 12;
		d6_2 = 1 + rand() % 12;
		d6_3 = 1 + rand() % 12;
		if(d6_1 == 7)
		{
			d6_1 = d6_1 - 1;
		}
		if(d6_2 == 7)
		{
			d6_2 = d6_2 - 1;
		}
		if(d6_3 == 7)
		{
			d6_3 = d6_3 - 1;
		}
		personagem.pv = d6_1 + d6_2 + d6_3 + personagem.cons;
		system("cls");
		printf("\n -> Seus Pontos de Vida (P.V) acabaram de ser calculados. Dado 1 = %d, Dado 2 = %d, Dado 3 = %d. Voce tem %d Pontos de Vida.",d6_1, d6_2, d6_3, personagem.pv);
}

void confronto1()
{	
	vilao1[0].nomeAdv = "Beasty";
	vilao1[0].defesa = 15;
	vilao1[0].dano = 8;
	vilao1[0].agilidade = 2;
	vilao1[0].pv_adv = 10;	
	
	vilao1[1].nomeAdv= "NewBeasty";
	vilao1[1].defesa = 15;
	vilao1[1].dano = 8;
	vilao1[1].agilidade = 2;
	vilao1[1].pv_adv = 12;
	
	vilao1[2].nomeAdv = "OldBeasty";
	vilao1[2].defesa = 15;
	vilao1[2].dano = 8;
	vilao1[2].agilidade = 2;
	vilao1[2].pv_adv = 8;
	
	printf("\n\n%s achou um covil de 3 monstros, e para sair vivo dessa enrascada, tera que derrotar algum deles! Vamos inicar a primeira batalha!", personagem.nome);
	srand(time(NULL));
	v = rand() % 3;
	printf("\n\nO adversario que voce ira enfrentar vai ser %s!", vilao1[v].nomeAdv);
	printf("\nOs atributos do adversario sao:\n -> Defesa = %d\n -> Dano = %d\n -> Agilidade = %d\n P.V = %d", vilao1[v].defesa, vilao1[v].dano, vilao1[v].agilidade, vilao1[v].pv_adv);
	do{
	if(personagem.agilidade > vilao1[v].agilidade)
	{
		printf("\n\nO turno da vez eh do %s", personagem.nome);
		printf("\nVoce tem 3 opcoes. Voce pode:\n[1] -> Atacar\n[2] -> Defender\n[3] -> Usar Pocao ");
		scanf("%d", &j);
		
		switch(j)
		{
			case 1:
				printf("\n\nVoce escolheu atacar!");
				vilao1[v].pv_adv = vilao1[v].pv_adv - (abs(personagem.weapon.dano - vilao1[v].defesa))  ;
				printf("\nO dano causado foi de %d. A vida restante do adversario eh %d", personagem.weapon.dano - vilao1[v].defesa, vilao1[v].pv_adv); 
				printf("%d, %d", vilao1[v].defesa, vilao1[v].pv_adv);
			break;
			
			case 2:
				printf("\n\nVoce escolheu defender!");
				personagem.armadura = personagem.armadura * 2;
				printf("\nSua defesa agora eh %d", personagem.armadura);	
			break;
			
			case 3:
				if(pocao != 3)
				{
					printf("\n\nVoce escolheu usar pocao!");
					srand(time(NULL));
					d6_1 = 1 + rand() % 6, d6_2 = 1 + rand() % 6, d6_3 = 1 + rand() % 6;
					
					if(d6_1 == 7)
					{
						d6_1 = d6_1 - 1;
					}
					if(d6_2 == 7)
					{
						d6_2 = d6_2 - 1;
					}
					if(d6_3 == 7)
					{
						d6_3 = d6_3 - 1;
					}
					
					personagem.pv = personagem.pv + d6_1 + d6_2 + d6_3;
					pocao = pocao + 1;
					
					printf("\n\n -> Apos usar a pocao, seu PV agora eh %d", personagem.pv);
				}
				else
				{
					printf("\nVoce usou todas as pocoes disponiveis no combate");
				}
			break;
		}
		printf("\n\nO turno da vez eh do adversario %s", vilao1[v].nomeAdv);
		printf("\nEle ira escolher entre:\n[0] -> Atacar\n[1] -> Defender\n[2] -> Usar Pocao");
		srand(time(NULL));
		x = rand() % 3;
		printf("%d", x);
		switch(x)
		{
			case 0:
				printf("\n\nAdversario escolheu atacar!");
				personagem.pv = personagem.pv - (abs(vilao1[v].dano - personagem.armadura)) ;
				printf("\nO dano causado foi de %d. A vida restante do %s eh %d", vilao1[v].dano - personagem.armadura, personagem.nome, personagem.pv); 
				printf("%d, %d", personagem.armadura, personagem.pv);
			break;
			
			case 1:
				printf("\n\nAdversario escolheu defender!");
				vilao1[v].defesa = vilao1[v].defesa * 2;
				printf("\nA defesa do adversario agora eh %d", vilao1[v].defesa);	
			break;
			
			case 2:
				if(pocao != 3)
				{
					printf("\n\nAdversario escolheu usar pocao!");
					srand(time(NULL));
					d6_1 = 1 + rand() % 6, d6_2 = 1 + rand() % 6, d6_3 = 1 + rand() % 6;
					
					if(d6_1 == 7)
					{
						d6_1 = d6_1 - 1;
					}
					if(d6_2 == 7)
					{
						d6_2 = d6_2 - 1;
					}
					if(d6_3 == 7)
					{
						d6_3 = d6_3 - 1;
					}
					
					vilao1[v].pv_adv = vilao1[v].pv_adv + d6_1 + d6_2 + d6_3;
					pocaoAdv = pocaoAdv+1;
					
					printf("\n\n -> Apos usar a pocao, o PV do adversario agora eh %d", vilao1[v].pv_adv);
				}
				else
				{
					printf("\n\nUsou todas as pocoes disponiveis no combate.");
				}
			break;
		}
	}
	else
	{
		printf("\n\nO turno da vez eh do adversario %s", vilao1[v].nomeAdv);
		printf("\nEle ira escolher entre:\n[0] -> Atacar\n[1] -> Defender\n[2] -> Usar Pocao");
		srand(time(NULL));
		x = rand() % 3;
		switch(x)
		{
			case 1:
				printf("\n\nAdversario escolheu atacar!");
				personagem.pv = personagem.pv - (abs(vilao1[v].dano - personagem.armadura));
				printf("\nO dano causado foi de %d. A vida restante do %s eh %d", vilao1[v].dano - personagem.armadura, personagem.nome, personagem.pv); 
			break;
			
			case 2:
				printf("\n\nAdversario escolheu defender!");
				vilao1[v].defesa = vilao1[v].defesa * 2;
				printf("\nA defesa do adversario agora eh %d", vilao1[v].defesa);	
			break;
			
			case 3:
				if(pocao != 3)
				{
					printf("\n\nAdversario escolheu usar pocao!");
					srand(time(NULL));
					d6_1 = 1 + rand() % 6, d6_2 = 1 + rand() % 6, d6_3 = 1 + rand() % 6;
					
					if(d6_1 == 7)
					{
						d6_1 = d6_1 - 1;
					}
					if(d6_2 == 7)
					{
						d6_2 = d6_2 - 1;
					}
					if(d6_3 == 7)
					{
						d6_3 = d6_3 - 1;
					}
					
					vilao1[v].pv_adv = vilao1[v].pv_adv + d6_1 + d6_2 + d6_3;
					pocaoAdv = pocaoAdv + 1;
					
					printf("\n\n -> Apos usar a pocao, o PV do adversario agora eh %d", vilao1[v].pv_adv);
				}
				else
				{
					printf("\n\nUsou todas as pocoes disponiveis no combate.");
				}
			break;
		}
		
		printf("\n\nO turno da vez eh do %s", personagem.nome);
		printf("\nVoce tem 3 opcoes. Voce pode:\n[1] -> Atacar\n[2] -> Defender\n[3] -> Usar Pocao ");
		scanf("%d", &j);
		
		switch(j)
		{
			case 1:
				printf("\n\nVoce escolheu atacar!");
				vilao1[v].pv_adv = vilao1[v].pv_adv - (abs(personagem.weapon.dano - vilao1[v].defesa));
				printf("\nO dano causado foi de %d. A vida restante do adversario eh %d", personagem.weapon.dano - vilao1[v].defesa, vilao1[v].pv_adv); 
			break;
			
			case 2:
				printf("\nVoce escolheu defender!");
				personagem.armadura = personagem.armadura * 2;
				printf("\nSua defesa agora eh %d", personagem.armadura);	
			break;
			
			case 3:
				if(pocao != 3)
				{
					printf("\n\nVoce escolheu usar pocao!");
					srand(time(NULL));
					d6_1 = 1 + rand() % 6, d6_2 = 1 + rand() % 6, d6_3 = 1 + rand() % 6;
					
					if(d6_1 == 7)
					{
						d6_1 = d6_1 - 1;
					}
					if(d6_2 == 7)
					{
						d6_2 = d6_2 - 1;
					}
					if(d6_3 == 7)
					{
						d6_3 = d6_3 - 1;
					}
					
					personagem.pv = personagem.pv + d6_1 + d6_2 + d6_3;
					pocao = pocao + 1;
					
					printf("\n\n -> Apos usar a pocao, seu PV agora eh %d", personagem.pv);
				}
				else
				{
					printf("\nVoce usou todas as pocoes disponiveis no combate");
				}
			break;
			
		}
	}
	
	if(j == 2)
	{
		personagem.armadura = personagem.armadura / 2;
	}
	if (x == 1)
	{
		vilao1[v].defesa = vilao1[v].defesa / 2;
	}
	
	
	if(personagem.pv <= 0 || vilao1[v].pv_adv <= 0)
	{
		if(personagem.pv <= 0)
		{
		printf("\nInfelizmente %s morreu. Reiniciando Jogo....", personagem.nome);
		Sleep(3000);
		system("cls");
		return main();
		}
		if(vilao1[v].pv_adv <= 0);
		{
			printf("\n%s foi derrotado! Muito Bem!", vilao1[v].nomeAdv);
			personagem.pontos = personagem.pontos + 5;
			personagem.cons = personagem.cons + 3;
			personagem.pv = personagem.pv + 3;
			endBattle = 1;
			printf("\n\n Agora voce tem mais 5 pontos para distribuir entre os atributos");
			printf("Voce ganhou mais 3 pontos de constituicao, sem gastar dos disponiveis, aumentando a sua vida.");
		
			addPontos();
			
			printf("\n-> Agora voce deve escolher uma arma nova para voce.");
			printf("\nCaso escolha uma arma pesada, o valor do seu dano sera definido a partir da rolagem de um dado de 12 lados + K + 50%% da sua forca.");
			printf("\nCaso escolha uma arma leve, o valor de seu dano sera definido por 2 rolagens de um dado de 6 lados + uma rolagem de um dado de 4 lados + K + Destreza");
			printf("\n[1] -> Espada de Safira(Pesada, K = 13)\n[2] -> Double Sai(leve, K = 8)\n[3] -> Wakisashi(Pesado, K = 15)");
			printf("Escolha a sua arma: ");
			fflush(stdin);
			scanf("%d", &j);
			switch(j)
			{
				case 1:
					srand(time(NULL));
					d12 = 1 + rand() % 12;
					if(d12 == 13)
					{
						d12 = d12 - 1;
					}
					personagem.weapon.categoria = 1;
					personagem.weapon.dano = d12 + 13 + 1.5*personagem.forca;
		
					printf("\n -> Voce escolheu a Espada de Safira.\n -> O Valor do dado eh %d.\n -> O valor do dano da sua arma eh %d", d12, personagem.weapon.dano);
				break;
		
				case 2: 
					srand(time(NULL));
					d6_1 = 1 + rand() % 6;
					d6_2 = 1 + rand() % 6;
					d4 = 1 + rand() % 4;
					if(d6_1 == 7)
					{
						d6_1 = d6_1 - 1;
					}
					if(d6_2 == 7)
					{
						d6_2 = d6_2 - 1;
					}
					if(d4 == 5)
					{
						d4 = d4 - 1;
					}
					personagem.weapon.categoria = 0;
					personagem.weapon.dano = d6_1 + d6_2 + d4 + 8 + personagem.destreza;
		
					printf("\n -> Voce escolheu a Sai.\n -> O Valor do dado eh %d e %d e %d.\n -> O valor da destreza eh %d. \n -> O valor do dano da sua arma eh %d", d6_1, d6_2, d4, personagem.destreza, personagem.weapon.dano);
					printf("\n\n%d", personagem.destreza);
				break; 
		
				case 3:
					srand(time(NULL));
					d12 = 1 + rand() % 12;
					if(d12 == 13)
					{
						d12 = d12 - 1;
					}
					personagem.weapon.categoria = 1;
					personagem.weapon.dano = d12 + 15 + 1.5*personagem.forca;
		
					printf("\n -> Voce escolheu a Wakisashi.\n -> O Valor do dado eh %d.\n -> O valor da sua forca eh %d.\n -> O valor do dano da sua arma eh %d", d12, personagem.forca, personagem.weapon.dano);
				break;
			}
		}
	}
	else
	{
		printf("\n\n Ninguem foi derrotado. Comecando outro round...");
	}
	}while(endBattle != 1);
}	

void confronto2()
{
	pocao = 0;
	pocaoAdv = 0;
	vilao2[0].nomeAdv = "LittleSlice";
	vilao2[0].defesa = 18;
	vilao2[0].dano = 13;
	vilao2[0].agilidade = 2;
	vilao2[0].pv_adv = 14;	
	
	vilao2[1].nomeAdv= "DeathSlice";
	vilao2[1].defesa = 18;
	vilao2[1].dano = 12;
	vilao2[1].agilidade = 2;
	vilao2[1].pv_adv = 16;
		
	printf("\n\n%s entrou numa caverna e encontrou 2 monstros, e para sair vivo dessa enrascada, tera que derrotar algum deles! Vamos inicar a segunda batalha!", personagem.nome);
	srand(time(NULL));
	v = rand() % 2;
	printf("\n\nO adversario que voce ira enfrentar vai ser %s!", vilao2[v].nomeAdv);
	printf("\nOs atributos do adversario sao:\n -> Defesa = %d\n -> Dano = %d\n -> Agilidade = %d\n P.V = %d", vilao2[v].defesa, vilao2[v].dano, vilao2[v].agilidade, vilao2[v].pv_adv);
	do{
	if(personagem.agilidade > vilao2[v].agilidade || personagem.agilidade == vilao2[v].agilidade)
	{
		printf("\n\nO turno da vez eh do %s", personagem.nome);
		printf("\nVoce tem 3 opcoes. Voce pode:\n[1] -> Atacar\n[2] -> Defender\n[3] -> Usar Pocao ");
		scanf("%d", &j);
		
		switch(j)
		{
			case 1:
				printf("\n\nVoce escolheu atacar!");
				vilao2[v].pv_adv = vilao2[v].pv_adv - (abs(personagem.weapon.dano - vilao2[v].defesa));
				printf("\nO dano causado foi de %d. A vida restante do adversario eh %d", personagem.weapon.dano - vilao2[v].defesa, vilao2[v].pv_adv); 
				printf("%d, %d", vilao2[v].defesa, vilao2[v].pv_adv);
			break;
			
			case 2:
				printf("\n\nVoce escolheu defender!");
				personagem.armadura = personagem.armadura * 2;
				printf("\nSua defesa agora eh %d", personagem.armadura);	
			break;
			
			case 3:
				if(pocao != 3)
				{
					printf("\n\nVoce escolheu usar pocao!");
					srand(time(NULL));
					d6_1 = 1 + rand() % 6, d6_2 = 1 + rand() % 6, d6_3 = 1 + rand() % 6;
					
					if(d6_1 == 7)
					{
						d6_1 = d6_1 - 1;
					}
					if(d6_2 == 7)
					{
						d6_2 = d6_2 - 1;
					}
					if(d6_3 == 7)
					{
						d6_3 = d6_3 - 1;
					}
					
					personagem.pv = personagem.pv + d6_1 + d6_2 + d6_3;
					pocao = pocao + 1;
					
					printf("\n\n -> Apos usar a pocao, seu PV agora eh %d", personagem.pv);
				}
				else
				{
					printf("\nVoce usou todas as pocoes disponiveis no combate");
				}
			break;
		}
		printf("\n\nO turno da vez eh do adversario %s", vilao2[v].nomeAdv);
		printf("\nEle ira escolher entre:\n[0] -> Atacar\n[1] -> Defender\n[2] -> Usar Pocao");
		srand(time(NULL));
		x = rand() % 3;
		printf("%d", x);
		switch(x)
		{
			case 0:
				printf("\n\nAdversario escolheu atacar!");
				personagem.pv = personagem.pv - (abs(vilao2[v].dano - personagem.armadura)) ;
				printf("\nO dano causado foi de %d. A vida restante do %s eh %d", abs(vilao2[v].dano - personagem.armadura), personagem.nome, personagem.pv); 
				printf("%d, %d", personagem.armadura, personagem.pv);
			break;
			
			case 1:
				printf("\n\nAdversario escolheu defender!");
				vilao2[v].defesa = vilao2[v].defesa * 2;
				printf("\nA defesa do adversario agora eh %d", vilao2[v].defesa);	
			break;
			
			case 2:
				if(pocao != 3)
				{
					printf("\n\nAdversario escolheu usar pocao!");
					srand(time(NULL));
					d6_1 = 1 + rand() % 6, d6_2 = 1 + rand() % 6, d6_3 = 1 + rand() % 6;
					
					if(d6_1 == 7)
					{
						d6_1 = d6_1 - 1;
					}
					if(d6_2 == 7)
					{
						d6_2 = d6_2 - 1;
					}
					if(d6_3 == 7)
					{
						d6_3 = d6_3 - 1;
					}
					
					vilao2[v].pv_adv = vilao2[v].pv_adv + d6_1 + d6_2 + d6_3;
					pocaoAdv = pocaoAdv+1;
					
					printf("\n\n -> Apos usar a pocao, o PV do adversario agora eh %d", vilao2[v].pv_adv);
				}
				else
				{
					printf("\n\nUsou todas as pocoes disponiveis no combate.");
				}
			break;
		}
	}
	else
	{
		printf("\n\nO turno da vez eh do adversario %s", vilao2[v].nomeAdv);
		printf("\nEle ira escolher entre:\n[0] -> Atacar\n[1] -> Defender\n[2] -> Usar Pocao");
		srand(time(NULL));
		x = rand() % 3;
		switch(x)
		{
			case 1:
				printf("\n\nAdversario escolheu atacar!");
				personagem.pv = personagem.pv - (abs(vilao2[v].dano - personagem.armadura));
				printf("\nO dano causado foi de %d. A vida restante do %s eh %d", abs(vilao2[v].dano - personagem.armadura), personagem.nome, personagem.pv); 
			break;
			
			case 2:
				printf("\n\nAdversario escolheu defender!");
				vilao2[v].defesa = vilao2[v].defesa * 2;
				printf("\nA defesa do adversario agora eh %d", vilao2[v].defesa);	
			break;
			
			case 3:
				if(pocao != 3)
				{
					printf("\n\nAdversario escolheu usar pocao!");
					srand(time(NULL));
					d6_1 = 1 + rand() % 6, d6_2 = 1 + rand() % 6, d6_3 = 1 + rand() % 6;
					
					if(d6_1 == 7)
					{
						d6_1 = d6_1 - 1;
					}
					if(d6_2 == 7)
					{
						d6_2 = d6_2 - 1;
					}
					if(d6_3 == 7)
					{
						d6_3 = d6_3 - 1;
					}
					
					vilao2[v].pv_adv = vilao2[v].pv_adv + d6_1 + d6_2 + d6_3;
					pocaoAdv = pocaoAdv + 1;
					
					printf("\n\n -> Apos usar a pocao, o PV do adversario agora eh %d", vilao2[v].pv_adv);
				}
				else
				{
					printf("\n\nUsou todas as pocoes disponiveis no combate.");
				}
			break;
		}
		
		printf("\n\nO turno da vez eh do %s", personagem.nome);
		printf("\nVoce tem 3 opcoes. Voce pode:\n[1] -> Atacar\n[2] -> Defender\n[3] -> Usar Pocao ");
		scanf("%d", &j);
		
		switch(j)
		{
			case 1:
				printf("\n\nVoce escolheu atacar!");
				vilao2[v].pv_adv = vilao2[v].pv_adv - (abs(personagem.weapon.dano - vilao2[v].defesa));
				printf("\nO dano causado foi de %d. A vida restante do adversario eh %d", abs(personagem.weapon.dano - vilao2[v].defesa), vilao2[v].pv_adv); 
			break;
			
			case 2:
				printf("\nVoce escolheu defender!");
				personagem.armadura = personagem.armadura * 2;
				printf("\nSua defesa agora eh %d", personagem.armadura);	
			break;
			
			case 3:
				if(pocao != 3)
				{
					printf("\n\nVoce escolheu usar pocao!");
					srand(time(NULL));
					d6_1 = 1 + rand() % 6, d6_2 = 1 + rand() % 6, d6_3 = 1 + rand() % 6;
					
					if(d6_1 == 7)
					{
						d6_1 = d6_1 - 1;
					}
					if(d6_2 == 7)
					{
						d6_2 = d6_2 - 1;
					}
					if(d6_3 == 7)
					{
						d6_3 = d6_3 - 1;
					}
					
					personagem.pv = personagem.pv + d6_1 + d6_2 + d6_3;
					pocao = pocao + 1;
					
					printf("\n\n -> Apos usar a pocao, seu PV agora eh %d", personagem.pv);
				}
				else
				{
					printf("\nVoce usou todas as pocoes disponiveis no combate");
				}
			break;
			
		}
	}
	
	if(j == 2)
	{
		personagem.armadura = personagem.armadura / 2;
	}
	if (x == 1)
	{
		vilao2[v].defesa = vilao2[v].defesa / 2;
	}
	
	
	if(personagem.pv <= 0 || vilao2[v].pv_adv <= 0)
	{
		if(personagem.pv <= 0)
		{
		printf("\nInfelizmente %s morreu. Reiniciando Jogo....", personagem.nome);
		Sleep(3000);
		system("cls");
		return main();
		}
		if(vilao2[v].pv_adv <= 0);
		{
			printf("\n%s foi derrotado! Muito Bem!", vilao2[v].nomeAdv);
			personagem.pontos = personagem.pontos + 5;
			personagem.cons = personagem.cons + 3;
			personagem.pv = personagem.pv + 3;
			endBattle = 2;
			printf("\n\n Agora voce tem mais 5 pontos para distribuir entre os atributos");
			printf("Voce ganhou mais 3 pontos de constituicao, sem gastar dos disponiveis, aumentando a sua vida.");
			
			addPontos();
			
			printf("\n\n -> Escolha qual armadura voce quer usar:  ");
			printf("\n\n[1] -> Traje de Utgard(K = 12).\n[2] -> Armadura de Diamante(K = 10).\n [3] -> Traje de Ferro(K = 9).");
			printf("\nEscolha o numero da sua armadura: ");
			scanf("%d", &j);
			switch(j)
			{
				case 1:
					personagem.armadura = 12 + 1.5*personagem.cons;
					printf(" -> Voce escolheu o Traje de Utgard.\n O valor da sua constituicao eh %d.\n -> O valor de defesa da sua armadura eh %d",personagem.cons, personagem.armadura);
				break;
		
				case 2: 
					personagem.armadura = 10 + 1.5*personagem.cons;
					printf(" -> Voce escolheu a Armadura de Diamante.\n O valor da sua constituicao eh %d.\n -> O valor de defesa da sua armadura eh %d",personagem.cons, personagem.armadura);
				break; 
		
				case 3:
					personagem.armadura = 9 + 1.5*personagem.cons;
					printf(" -> Voce escolheu o Traje de Ferro.\n O valor da sua constituicao eh %d.\n -> O valor de defesa da sua armadura eh %d",personagem.cons, personagem.armadura);
				break;
			}
		}
	}
	else
	{
		printf("\n\n Ninguem foi derrotado. Comecando outro round...");
	}
	}while(endBattle != 2);
}

void confronto3()
{
	pocao = 0;
	pocaoAdv = 0;
	vilao3.nomeAdv = "MidnightCreature";
	vilao3.defesa = 24;
	vilao3.dano = 17;
	vilao3.agilidade = 2;
	vilao3.pv_adv = 22;	
		
	printf("\n\n%s encontrou a criatura mais forte ja vista nessa realidade. Eh impossivel fugir, ele tera que derrota-lo! Vamos inicar a ultima batalha!", personagem.nome);
	printf("\n\nO adversario que voce ira enfrentar vai ser %s!", vilao3.nomeAdv);
	printf("\nOs atributos do adversario sao:\n -> Defesa = %d\n -> Dano = %d\n -> Agilidade = %d\n P.V = %d", vilao3.defesa, vilao3.dano, vilao3.agilidade, vilao3.pv_adv);
	do{
	if(personagem.agilidade > vilao3.agilidade || personagem.agilidade == vilao3.agilidade)
	{
		printf("\n\nO turno da vez eh do %s", personagem.nome);
		printf("\nVoce tem 3 opcoes. Voce pode:\n[1] -> Atacar\n[2] -> Defender\n[3] -> Usar Pocao ");
		scanf("%d", &j);
		
		switch(j)
		{
			case 1:
				printf("\n\nVoce escolheu atacar!");
				vilao3.pv_adv = vilao3.pv_adv - (abs(personagem.weapon.dano - vilao3.defesa));
				printf("\nO dano causado foi de %d. A vida restante do adversario eh %d", personagem.weapon.dano - vilao3.defesa, vilao3.pv_adv); 
				printf("%d, %d", vilao3.defesa, vilao3.pv_adv);
			break;
			
			case 2:
				printf("\n\nVoce escolheu defender!");
				personagem.armadura = personagem.armadura * 2;
				printf("\nSua defesa agora eh %d", personagem.armadura);	
			break;
			
			case 3:
				if(pocao != 3)
				{
					printf("\n\nVoce escolheu usar pocao!");
					srand(time(NULL));
					d6_1 = 1 + rand() % 6, d6_2 = 1 + rand() % 6, d6_3 = 1 + rand() % 6;
					
					if(d6_1 == 7)
					{
						d6_1 = d6_1 - 1;
					}
					if(d6_2 == 7)
					{
						d6_2 = d6_2 - 1;
					}
					if(d6_3 == 7)
					{
						d6_3 = d6_3 - 1;
					}
					
					personagem.pv = personagem.pv + d6_1 + d6_2 + d6_3;
					pocao = pocao + 1;
					
					printf("\n\n -> Apos usar a pocao, seu PV agora eh %d", personagem.pv);
				}
				else
				{
					printf("\nVoce usou todas as pocoes disponiveis no combate");
				}
			break;
		}
		printf("\n\nO turno da vez eh do adversario %s", vilao3.nomeAdv);
		printf("\nEle ira escolher entre:\n[0] -> Atacar\n[1] -> Defender\n[2] -> Usar Pocao");
		srand(time(NULL));
		x = rand() % 3;
		printf("%d", x);
		switch(x)
		{
			case 0:
				printf("\n\nAdversario escolheu atacar!");
				personagem.pv = personagem.pv - (abs(vilao3.dano - personagem.armadura)) ;
				printf("\nO dano causado foi de %d. A vida restante do %s eh %d", abs(vilao3.dano - personagem.armadura), personagem.nome, personagem.pv); 
				printf("%d, %d", personagem.armadura, personagem.pv);
			break;
			
			case 1:
				printf("\n\nAdversario escolheu defender!");
				vilao3.defesa = vilao3.defesa * 2;
				printf("\nA defesa do adversario agora eh %d", vilao3.defesa);	
			break;
			
			case 2:
				if(pocao != 3)
				{
					printf("\n\nAdversario escolheu usar pocao!");
					srand(time(NULL));
					d6_1 = 1 + rand() % 6, d6_2 = 1 + rand() % 6, d6_3 = 1 + rand() % 6;
					
					if(d6_1 == 7)
					{
						d6_1 = d6_1 - 1;
					}
					if(d6_2 == 7)
					{
						d6_2 = d6_2 - 1;
					}
					if(d6_3 == 7)
					{
						d6_3 = d6_3 - 1;
					}
					
					vilao3.pv_adv = vilao3.pv_adv + d6_1 + d6_2 + d6_3;
					pocaoAdv = pocaoAdv+1;
					
					printf("\n\n -> Apos usar a pocao, o PV do adversario agora eh %d", vilao3.pv_adv);
				}
				else
				{
					printf("\n\nUsou todas as pocoes disponiveis no combate.");
				}
			break;
		}
	}
	else
	{
		printf("\n\nO turno da vez eh do adversario %s", vilao3.nomeAdv);
		printf("\nEle ira escolher entre:\n[0] -> Atacar\n[1] -> Defender\n[2] -> Usar Pocao");
		srand(time(NULL));
		x = rand() % 3;
		switch(x)
		{
			case 1:
				printf("\n\nAdversario escolheu atacar!");
				personagem.pv = personagem.pv - (abs(vilao3.dano - personagem.armadura));
				printf("\nO dano causado foi de %d. A vida restante do %s eh %d", abs(vilao3.dano - personagem.armadura), personagem.nome, personagem.pv); 
			break;
			
			case 2:
				printf("\n\nAdversario escolheu defender!");
				vilao3.defesa = vilao3.defesa * 2;
				printf("\nA defesa do adversario agora eh %d", vilao3.defesa);	
			break;
			
			case 3:
				if(pocao != 3)
				{
					printf("\n\nAdversario escolheu usar pocao!");
					srand(time(NULL));
					d6_1 = 1 + rand() % 6, d6_2 = 1 + rand() % 6, d6_3 = 1 + rand() % 6;
					
					if(d6_1 == 7)
					{
						d6_1 = d6_1 - 1;
					}
					if(d6_2 == 7)
					{
						d6_2 = d6_2 - 1;
					}
					if(d6_3 == 7)
					{
						d6_3 = d6_3 - 1;
					}
					
					vilao3.pv_adv = vilao3.pv_adv + d6_1 + d6_2 + d6_3;
					pocaoAdv = pocaoAdv + 1;
					
					printf("\n\n -> Apos usar a pocao, o PV do adversario agora eh %d", vilao3.pv_adv);
				}
				else
				{
					printf("\n\nUsou todas as pocoes disponiveis no combate.");
				}
			break;
		}
		
		printf("\n\nO turno da vez eh do %s", personagem.nome);
		printf("\nVoce tem 3 opcoes. Voce pode:\n[1] -> Atacar\n[2] -> Defender\n[3] -> Usar Pocao ");
		scanf("%d", &j);
		
		switch(j)
		{
			case 1:
				printf("\n\nVoce escolheu atacar!");
				vilao3.pv_adv = vilao3.pv_adv - (abs(personagem.weapon.dano - vilao3.defesa));
				printf("\nO dano causado foi de %d. A vida restante do adversario eh %d", abs(personagem.weapon.dano - vilao3.defesa), vilao3.pv_adv); 
			break;
			
			case 2:
				printf("\nVoce escolheu defender!");
				personagem.armadura = personagem.armadura * 2;
				printf("\nSua defesa agora eh %d", personagem.armadura);	
			break;
			
			case 3:
				if(pocao != 3)
				{
					printf("\n\nVoce escolheu usar pocao!");
					srand(time(NULL));
					d6_1 = 1 + rand() % 6, d6_2 = 1 + rand() % 6, d6_3 = 1 + rand() % 6;
					
					if(d6_1 == 7)
					{
						d6_1 = d6_1 - 1;
					}
					if(d6_2 == 7)
					{
						d6_2 = d6_2 - 1;
					}
					if(d6_3 == 7)
					{
						d6_3 = d6_3 - 1;
					}
					
					personagem.pv = personagem.pv + d6_1 + d6_2 + d6_3;
					pocao = pocao + 1;
					
					printf("\n\n -> Apos usar a pocao, seu PV agora eh %d", personagem.pv);
				}
				else
				{
					printf("\nVoce usou todas as pocoes disponiveis no combate");
				}
			break;
			
		}
	}
	
	if(j == 2)
	{
		personagem.armadura = personagem.armadura / 2;
	}
	if (x == 1)
	{
		vilao3.defesa = vilao3.defesa / 2;
	}
	
	
	if(personagem.pv <= 0 || vilao3.pv_adv <= 0)
	{
		if(personagem.pv <= 0)
		{
		printf("\nInfelizmente %s morreu. Reiniciando Jogo....", personagem.nome);
		Sleep(3000);
		system("cls");
		return main();
		}
		if(vilao3.pv_adv <= 0);
		{
			printf("\n%s foi derrotado! Muito Bem!", vilao3.nomeAdv);
			printf("\n\nPARABENS, VOCE DERROTOU O ULTIMO CHEFE DO JOGO! ORBIGADO POR JOGAR!");
			endBattle = 3;
		}
	}
	else
	{
	printf("\n\n Ninguem foi derrotado. Comecando outro round...");
	}
	}while(endBattle != 3);
}

//Daniel passou por aqui
