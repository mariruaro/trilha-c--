#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  
#include <windows.h>  

int copiatrinca[16][3]= { {111,114, 117 },							//variaves globais para os valores serem mantidos, nunca sofre alteração só é usada para comparaçoes
                     {111,441, 771 },
                      {114,224, 334 },
                       {117,447, 777 },
                        {222,224, 226 },
                         {222,442, 662 },
                          {226,446, 666 },
                           {333,334, 335 },
                            {333,443, 553 },
                             {335,445, 555 },
                              {441,442, 443 },
                               {445,446, 447 },
                                {553,554, 555 },
                                 {554,664, 774 },
                                  {662,664, 666},
                                     {771,774,777}};
int copiaposicoestotais[24]={111,114,117,222,224,226,333,334,335,441,442,443,445,446,447,553,554,555,662,664,666,771,774,777};
int copiamatrizdeescrita[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};

int posicaovalida(int todasposicoes[24],int posicao, int i){
	
int controle;								//verifica se a posicao esta vaga
	for (;i<24;i++)
        if (todasposicoes[i]==posicao )
        	controle=1;

	if (controle==1)
		return 1;
	else
		return 0;

}

void movimento (int copiatrinca[16][3],int linha,int posicao,int posicaomovimento,int *pode){

	for (linha=0;linha<16;linha++){															//verifica se o movimento é possivel
		if (copiatrinca[linha][0]==posicaomovimento && copiatrinca[linha][1]==posicao)
				*pode=1;
		if ( copiatrinca[linha][1]==posicaomovimento && copiatrinca[linha][0]==posicao )
				*pode=1;
		if ( copiatrinca[linha][1]==posicaomovimento && copiatrinca[linha][2]==posicao)
				*pode=1;
		if (copiatrinca[linha][2]==posicaomovimento &&  copiatrinca[linha][1]==posicao)
				*pode=1;

	}
}

int vereficajogador (int numerojogador,int posicaomovimento,int todasposicoes[24]){

int i;														//na hora de fazer o movimento para verificar se a peça digitada pertence ao jogador da vez
	for (i=0;i<24;i++){
	
		if (posicaomovimento==copiaposicoestotais[i])
			if (numerojogador==todasposicoes[i])
				return 1;
			else 
				return 0;
	
	}			
}

int retirada(int posicoestotais[24],int posicaoretirada, int numerojogador){

int i;																//função pra verificar se a peça retirada da trinca pertence ao outro jogador
	for (i=0;i<25;i++){
		if (numerojogador==1){
			if (posicaoretirada==copiaposicoestotais[i])	
				if (posicoestotais[i]==2)
					return 1;
				else 
					return 0;
		}
		if (numerojogador==2){
			if (posicaoretirada==copiaposicoestotais[i])	
				if (posicoestotais[i]==1)
					return 1;
				else 
					return 0;
		}
	}

}

void contadordemovimento (int numerojogador,int trinca[16][3],int *contamovimentosrestantes){

int linha;																		//conta os movimentos pra verificar se continua o jogo
	for (linha=0;linha<16;linha++){
		if (trinca[linha][0]==numerojogador && trinca[linha][1]>2)
				*contamovimentosrestantes=*contamovimentosrestantes+1;
				
		if ( trinca[linha][1]==numerojogador && trinca[linha][0]>2)
				*contamovimentosrestantes=*contamovimentosrestantes+1;
		
		if ( trinca[linha][1]==numerojogador && trinca[linha][2]>2)
				*contamovimentosrestantes=*contamovimentosrestantes+1;
				
		if (trinca[linha][2]==numerojogador && trinca[linha][1]>2)
				*contamovimentosrestantes=*contamovimentosrestantes+1;
				
	}
}

int winner (int pecasjogador1,int pecasjogador2){					//verifica quantos peças o jogador ainda tem no tabuleiro (4 pq é 2x) 
	
	if (pecasjogador2==4|| pecasjogador1==4 )
		return 1;
	else 
		return 0;
}

void jogadas (int todasposicoes[24],int matrizdeescrita[24],int posicao,int numerojogador,int trinca[16][3],int *pecasjogador1,int *pecasjogador2,int tipodejogada,int posicaomovimento,char jogador1[10],char jogador2[10] )	{
	
system ("cls");
int i,linha,coluna,posicaoretirada;

	if (tipodejogada==1){									//tipodejogada==1 significa o inicio do jogo onde jogadores só distibuem as peças sem movimento
		for (i=0;i<25;i++){
			if (posicao==todasposicoes[i]){
				todasposicoes[i]=numerojogador;
				matrizdeescrita[i]=numerojogador;
			}
		}
	}
	
	if (tipodejogada==2){										//tipodejogada==2 faz as mudanças quando tem movimento voltando a seu valor inicial da peçademovimento e a nova posicao altera os vetores
   	 for (i=0;i<25;i++){
      	for (linha=0;linha<16;linha++)
			for (coluna=0;coluna<3;coluna++)
				if (posicaomovimento==copiaposicoestotais[i] && posicaomovimento==copiatrinca[linha][coluna] ){
						todasposicoes[i]=posicaomovimento;
                        matrizdeescrita[i]=0;
						trinca[linha][coluna]=posicaomovimento;
				}
				if(posicao==todasposicoes[i]){
					todasposicoes[i]=numerojogador;
                    matrizdeescrita[i]=numerojogador;
				}

	}

   }

	printf ("   1 2 3   4   5 6 7  \n");
	printf("11 %d%c%c%c%c%c%c%c%d%c%c%c%c%c%c%c%d\n",matrizdeescrita[0],196,196,196,196,196,196,196,matrizdeescrita[1],196,196,196,196,196,196,196,matrizdeescrita[2]);
	printf("22 %c%c%d%c%c%c%c%c%d%c%c%c%c%c%d%c%c\n",179,32,matrizdeescrita[3],196,196,196,196,196,matrizdeescrita[4],196,196,196,196,196,matrizdeescrita[5],32,179,32);
	printf("33 %c %c %d%c%c%c%d%c%c%c%d%c%c%c%c%c \n",179,179,matrizdeescrita[6],196,196,196,matrizdeescrita[7],196,196,196,matrizdeescrita[8],32,179,32,179);
	printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",179,32,179,32, 179,32,32,32,32,32,32,32,179,32,179,32,179,32,32);
	printf("44 %d%c%d%c%d%c%c%c%c%c%c%c%d%c%d%c%d%c\n",matrizdeescrita[9],196,matrizdeescrita[10],196,matrizdeescrita[11],32,32,32,32,32,32,32,matrizdeescrita[12],196,matrizdeescrita[13],196,matrizdeescrita[14],32);
	printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",179,32,179,32, 179,32,32,32,32,32,32,32,179,32,179,32,179,32,32);
	printf("55 %c%c%c%c%d%c%c%c%d%c%c%c%d%c%c%c%c \n",179,32,179,32,matrizdeescrita[15],196,196,196,matrizdeescrita[16],196,196,196,matrizdeescrita[17],32,179,32,179);
	printf("66 %c%c%d%c%c%c%c%c%d%c%c%c%c%c%d%c%c%c\n",179,32,matrizdeescrita[18],196,196,196,196,196,matrizdeescrita[19],196,196,196,196,196,matrizdeescrita[20],32,179,32);
	printf("77 %d%c%c%c%c%c%c%c%d%c%c%c%c%c%c%c%d\n",matrizdeescrita[21],196,196,196,196,196,196,196,matrizdeescrita[22],196,196,196,196,196,196,196,matrizdeescrita[23]);
	printf("\n");

	for (linha=0;linha<16;linha++)						//muda o valor quando posicao ocupada na matriz das trinca
		for (coluna=0;coluna<3;coluna++)
			if (trinca[linha][coluna]==posicao)
				trinca[linha][coluna]=numerojogador;

	for (linha=0;linha<16;linha++){								//inicio da condiçao pra verificar se é trinca
		if (trinca[linha][0]==numerojogador && trinca[linha][1]==numerojogador && trinca[linha][2]==numerojogador){
			if (copiatrinca[linha][0]==posicao || copiatrinca[linha][1]==posicao || copiatrinca[linha][2]==posicao){		//esse if serve pra usa trinca somente quando ela foi formada pela ultima jogada da pessoa
				do{
					printf("VOCE FEZ UMA TRINCA, DIGITE A PECA DO ADVERSARIO A SER RETIRADA:");
					scanf("%d",&posicaoretirada);
				}	
				while (retirada(todasposicoes,posicaoretirada,numerojogador)!=1 );	
				for (i=0;i<25;i++)
					for (linha=0;linha<16;linha++)
						for (coluna=0;coluna<3;coluna++)
							if (posicaoretirada==copiaposicoestotais[i] && posicaoretirada==copiatrinca[linha][coluna]){
								todasposicoes[i]=posicaoretirada;
								matrizdeescrita[i]=0;
								trinca[linha][coluna]=posicaoretirada;
								if (numerojogador==1)
									*pecasjogador2=*pecasjogador2-1; 	//diminui as peças no total dependendo de quem é o jogador
								if (numerojogador==2)
									*pecasjogador1=*pecasjogador1-1;
							}
			}
			system ("cls");			/// escreve o tabuleiro de novo com as alteraçoes
			printf ("   1 2 3   4   5 6 7  \n");
			printf("11 %d%c%c%c%c%c%c%c%d%c%c%c%c%c%c%c%d\n",matrizdeescrita[0],196,196,196,196,196,196,196,matrizdeescrita[1],196,196,196,196,196,196,196,matrizdeescrita[2]);
			printf("22 %c%c%d%c%c%c%c%c%d%c%c%c%c%c%d%c%c\n",179,32,matrizdeescrita[3],196,196,196,196,196,matrizdeescrita[4],196,196,196,196,196,matrizdeescrita[5],32,179,32);
			printf("33 %c %c %d%c%c%c%d%c%c%c%d%c%c%c%c%c \n",179,179,matrizdeescrita[6],196,196,196,matrizdeescrita[7],196,196,196,matrizdeescrita[8],32,179,32,179);
			printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",179,32,179,32, 179,32,32,32,32,32,32,32,179,32,179,32,179,32,32);
			printf("44 %d%c%d%c%d%c%c%c%c%c%c%c%d%c%d%c%d%c\n",matrizdeescrita[9],196,matrizdeescrita[10],196,matrizdeescrita[11],32,32,32,32,32,32,32,matrizdeescrita[12],196,matrizdeescrita[13],196,matrizdeescrita[14],32);
			printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",179,32,179,32, 179,32,32,32,32,32,32,32,179,32,179,32,179,32,32);
			printf("55 %c%c%c%c%d%c%c%c%d%c%c%c%d%c%c%c%c \n",179,32,179,32,matrizdeescrita[15],196,196,196,matrizdeescrita[16],196,196,196,matrizdeescrita[17],32,179,32,179);
			printf("66 %c%c%d%c%c%c%c%c%d%c%c%c%c%c%d%c%c%c\n",179,32,matrizdeescrita[18],196,196,196,196,196,matrizdeescrita[19],196,196,196,196,196,matrizdeescrita[20],32,179,32);
			printf("77 %d%c%c%c%c%c%c%c%d%c%c%c%c%c%c%c%d\n",matrizdeescrita[21],196,196,196,196,196,196,196,matrizdeescrita[22],196,196,196,196,196,196,196,matrizdeescrita[23]);
			printf("\n");
		}
	}
	
	int copiapecasjogador1=*pecasjogador1, copiapecasjogador2=*pecasjogador2;		 //copia os valores das peças 
	

	if (winner(copiapecasjogador1,copiapecasjogador2)==1){			//testa ve se tem ganhador 
		if (numerojogador==1){
			system("color 5B");
			tipodejogada=3;
			printf ("*************************************************************\n");
			printf ("PARABENS %s VOCE E DEMAIS E GANHOU ESSA SUPER PARTIDA\n", jogador1);
			printf ("*************************************************************\n");
			system("pause");
			exit(0);
		}
		if (numerojogador==2){
			system("color 5B");
			tipodejogada=3;
			printf ("*************************************************************\n");
			printf ("PARABENS %s VOCÊ E DEMAIS E GANHOU ESSA SUPER PARTIDA\n", jogador2);
			printf ("*************************************************************\n");
			system("pause");
			exit(0);
		}

	}
	
	
	int contamovimentosrestantes;			//só quando tem tipodejogada==2 pq precisa chegar na parte dos movimentos se jogador não tiver nenuhum já termina o jogo
		if (tipodejogada==2){
			contadordemovimento(numerojogador,trinca,&contamovimentosrestantes);
			if (contamovimentosrestantes==0){
				if (numerojogador==1){
					system("color 5B");
					printf ("*************************************************************\n");
					printf ("PARABENS %s VOCÊ E DEMAIS E GANHOU ESSA SUPER PARTIDA\n", jogador2);
					printf ("*************************************************************\n");
					system("pause");
					exit(0);
				}
				if (numerojogador==2){
					system("color 5B");
					printf ("*************************************************************\n");
					printf ("PARABENS %s VOCE E DEMAIS E GANHOU ESSA SUPER PARTIDA\n", jogador1);
					printf ("*************************************************************\n");
					system("pause");
					exit(0);
				}
			}
		}

}



void jogo (int menu){
	system("color 17");
int todasposicoes[24]={111,114,117,222,224,226,333,334,335,441,442,443,445,446,447,553,554,555,662,664,666,771,774,777};
int matrizdeescrita[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
int pecasjogador1=18,pecasjogador2=18;
int trinca[16][3]=  { {111,114, 117 },
                     {111,441, 771 },
                      {114,224, 334 },
                       {117,447, 777 },
                        {222,224, 226 },
                         {222,442, 662 },
                          {226,446, 666 },
                           {333,334, 335 },
                            {333,443, 553 },
                             {335,445, 555 },
                              {441,442, 443 },
                               {445,446, 447 },
                                {553,554, 555 },
                                 {554,664, 774 },
                                  {662,664, 666},
                                     {771,774,777}};
int tipodejogada, contjogador1,contjogador2;
int pode,linha,coluna,posicaomovimento,posicao,i=0;
char jogador1[10], jogador2[10];
	printf ("NOME DO PRIMEIRO JOGADOR:");
	scanf ("%s",jogador1);
	getchar();
	system ("cls");
	printf ("NOME DO SEGUNDO JOGADOR:");
	scanf ("%s",jogador2);
	fflush(stdin);
	system ("cls");
		
		printf ("   1 2 3   4   5 6 7  \n");
		printf("11 %d%c%c%c%c%c%c%c%d%c%c%c%c%c%c%c%d\n",matrizdeescrita[0],196,196,196,196,196,196,196,matrizdeescrita[1],196,196,196,196,196,196,196,matrizdeescrita[2]);
		printf("22 %c%c%d%c%c%c%c%c%d%c%c%c%c%c%d%c%c\n",179,32,matrizdeescrita[3],196,196,196,196,196,matrizdeescrita[4],196,196,196,196,196,matrizdeescrita[5],32,179,32);
		printf("33 %c %c %d%c%c%c%d%c%c%c%d%c%c%c%c%c \n",179,179,matrizdeescrita[6],196,196,196,matrizdeescrita[7],196,196,196,matrizdeescrita[8],32,179,32,179);
		printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",179,32,179,32, 179,32,32,32,32,32,32,32,179,32,179,32,179,32,32);
		printf("44 %d%c%d%c%d%c%c%c%c%c%c%c%d%c%d%c%d%c\n",matrizdeescrita[9],196,matrizdeescrita[10],196,matrizdeescrita[11],32,32,32,32,32,32,32,matrizdeescrita[12],196,matrizdeescrita[13],196,matrizdeescrita[14],32);
		printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",179,32,179,32, 179,32,32,32,32,32,32,32,179,32,179,32,179,32,32);
		printf("55 %c%c%c%c%d%c%c%c%d%c%c%c%d%c%c%c%c \n",179,32,179,32,matrizdeescrita[15],196,196,196,matrizdeescrita[16],196,196,196,matrizdeescrita[17],32,179,32,179);
		printf("66 %c%c%d%c%c%c%c%c%d%c%c%c%c%c%d%c%c%c\n",179,32,matrizdeescrita[18],196,196,196,196,196,matrizdeescrita[19],196,196,196,196,196,matrizdeescrita[20],32,179,32);
		printf("77 %d%c%c%c%c%c%c%c%d%c%c%c%c%c%c%c%d\n",matrizdeescrita[21],196,196,196,196,196,196,196,matrizdeescrita[22],196,196,196,196,196,196,196,matrizdeescrita[23]);
		printf("\n");
		
	for (contjogador1=1;contjogador1<=9;)		//botar as 9 peças de cada jogador
		for (contjogador2=1;contjogador2<=9;){
			do{
				printf("%s DIGITE A LINHA  E COLUNA (SEM ESPACO ENTRE AS MESMAS)\n",jogador1);
				printf ("PARA COLACAR SUA PECA:");
				scanf("%d",&posicao);
			}
			while (	posicaovalida (todasposicoes,posicao,i)!=1)	;   //até a pessoa escrever uma posicao valida
			jogadas(todasposicoes,matrizdeescrita,posicao,1,trinca,&pecasjogador1,&pecasjogador2,1,posicaomovimento,jogador1,jogador2);
			contjogador1++;
			do{
				printf("%s DIGITE A LINHA  E COLUNA (SEM ESPACO ENTRE AS MESMAS)\n",jogador2);
				printf ("PARA COLACAR SUA PECA:");
				scanf("%d",&posicao);
			}
			while (	posicaovalida (todasposicoes,posicao,i)!=1)	;  //até a pessoa escrever uma posicao valida
			jogadas(todasposicoes,matrizdeescrita,posicao,2,trinca,&pecasjogador1,&pecasjogador2,1,posicaomovimento,jogador1,jogador2);
			contjogador2++;
		}

	for (;tipodejogada!=3;){	//fazer os movimentos pro jogo continuar
		do{
			do{
				do{
					printf("%s DIGITE A LINHA  E COLUNA DA PECA QUE DESEJA MOVIMENTAR:",jogador1);
					scanf("%d",&posicaomovimento);
				}
				while (	posicaovalida (todasposicoes,posicaomovimento,i)!=0)	;	//ate pessoa escrever uma posicao que esta ocupada
				}
				while ( vereficajogador(1,posicaomovimento,todasposicoes)!=1);	//ate pessoa escrever uma posicao que esta ocupada com sua peça
				do{
					printf("%s DIGITE A LINHA  E COLUNA PARA ONDE ESSA PECA DEVE SE DESLOCAR::",jogador1);
					scanf("%d",&posicao);
				}
				while (	posicaovalida (todasposicoes,posicao,i)!=1);	//ate pessoa escrever posiçao vazia para fazer movimento
   				 movimento(copiatrinca,linha,posicao,posicaomovimento,&pode);
			}
			while (pode!=1);		//ate que a posiçao de retirada posso se movimentar para a posicao vazia 
		pode=0;			
		jogadas(todasposicoes,matrizdeescrita,posicao,1,trinca,&pecasjogador1,&pecasjogador2,2,posicaomovimento,jogador1,jogador2);	
		do{
			do{
				do{
					printf("%s DIGITE A LINHA  E COLUNA DA PECA QUE DESEJA MOVIMENTAR:",jogador2);
					scanf("%d",&posicaomovimento);
				}
				while (	posicaovalida (todasposicoes,posicaomovimento,i)!=0)	;
				}
				while ( vereficajogador(2,posicaomovimento,todasposicoes)!=1);
				do{
					printf("%s DIGITE A LINHA  E COLUNA PARA ONDE ESSA PECA DEVE SE DESLOCAR::",jogador2);
					scanf("%d",&posicao);
				}
				while (	posicaovalida (todasposicoes,posicao,i)!=1);
    			movimento(copiatrinca,linha,posicao,posicaomovimento,&pode );
			}
			while (pode!=1 );
		pode=0;
		jogadas(todasposicoes,matrizdeescrita,posicao,2,trinca,&pecasjogador1,&pecasjogador2,2,posicaomovimento,jogador1,jogador2);
	}
	
}


int main () {
	 int menu,novojogo;
	 system("color 0C");
	printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,194,196,196,196,196,196,196,196,191,32);
	printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",179,32,218,196,196,196,196,196,197,196,196,196,196,196,191,32,179,32);
	printf("   %c %c %c%c%c%c%c%c%c%c%c%c%c%c%c \n",179,179,218,196,196,196,193,196,196,196,191,32,179,32,179);
	printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",179,32,179,32, 179,32,32,32,32,32,32,32,179,32,179,32,179,32,32);
	printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",195,196,197,196,180,32,32,32,32,32,32,32,195,196,197,196,180);
	printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",179,32,179,32, 179,32,32,32,32,32,32,32,179,32,179,32,179,32,32);
	printf("   %c %c %c%c%c%c%c%c%c%c%c%c%c%c%c \n",179,179,192,196,196,196,194,196,196,196,217,32,179,32,179);
	printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",179,32,192,196,196,196,196,196,197,196,196,196,196,196,217,32,179,32);
	printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,193,196,196,196,196,196,196,196,217,32);
	printf("\n");
	printf("BEM VINDO AO JOGO TRILHA\n");
	printf("\n");
	printf("%c---------MENU----------\n",32);
	printf("%c 1 - NOVO JOGO \n",179);
	printf("%c 2 - COMO JOGAR \n",179);
	printf("%c 5 - SAIR DO JOGO \n",179);
	printf("%c-------------------------\n",32);
	printf("\n");
	printf("DIGITE SUA ESCOLHA:");
	scanf("%d",&menu);
	system ("cls");
	if (menu==1)
		jogo(menu);
	if (menu==5)
		system("pause");
	if (menu==2){
		printf("\n");
		printf ("O JOGO TRILHA TEM COMO OBJETIVO ELIMINAR\n");
		printf("\n");
		printf ("AS PECAS INIMIGAS ATE QUE SOBRE APENAS UMA\n");
		printf("\n");
		printf ("OU SEU ADVERSARIO FIQUE SEM MOVIMENTOS.\n");
		printf("\n");
		printf ("SEMPRE QUE O JOGADOR FORMAR UMA LINHA\n");
		printf("\n");
		printf ("HORIZONTAL OU UMA LINHA VERTICAL, COM TRES DE\n");
		printf("\n");
		printf ("SUAS PECAS, ELE TERA DIREITO DE ELIMINAR UMA PECA\n");
		printf("\n");
		printf ("DO SEU ADVERSARIO.\n");
		printf("\n");
		printf ("O JOGADOR 1 TERA SUAS PECAS INDICADAS PELO NUMERO 1.\n");
		printf("\n");
		printf ("O JOGADOR 2 TERA SUAS PECAS INDICADAS PELO NUMERO 2.\n");
		printf("\n");
		printf ("AS POSICOES COM 0 REPRESENTAM AS QUE ESTAO DISPONIVEIS.\n");
		printf("\n");
		printf("%c PARA UM NOVO JOGO PRESSIONE 1\n",179);
		printf ("%c PARA SAIR DO JOGO PRESSIONE 5\n",179);
		printf("\n");
		printf("DIGITE SUA ESCOLHA:");
		scanf("%d",&novojogo);
		system ("cls");
	if (novojogo==5)
		exit (0);
	if (novojogo==1)
		jogo(menu);
    }
	
system("pause");
}
