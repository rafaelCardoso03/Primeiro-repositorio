#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

//Estruturas
struct LINGUA {
	char lingua[15],
	tradutor[50];
	int ano_tra;
};\

typedef struct{
	char nome[70],
	estilo[15],
	autor[50],
	editora[25];
	int n_pags,
	ano;
	float preco;
	struct LINGUA lingua;
}LIVRO;

//Prot�tipo das Fun��es
void menu(LIVRO x[], int &quant);
void inserir(LIVRO x[], int &quant);
void individual(LIVRO x[], int &quant);
void anos(LIVRO x[], int &quant);
void preco(LIVRO x[], int &quant);
void registos(LIVRO x[], int &quant);
void escint(LIVRO x[], int &quant);
void escmenu(LIVRO x[], int &quant);
void escolha(LIVRO x[], int &quant);
void consultar(LIVRO x[], int &quant);
void eliminar(LIVRO x[], int &quant);
void atualizar(LIVRO x[], int &quant);
void mentip(LIVRO x[], int &quant);
void esctip(LIVRO x[], int &quant);
void nome(LIVRO x[], int &quant);
void autor(LIVRO x[], int &quant);
void editora(LIVRO x[], int &quant);
void estilo(LIVRO x[], int &quant);


//Programa-
int main(){
	char resp;
	int quant = 0;
	LIVRO livros[100];
	do{
		system("cls");
		setlocale (LC_ALL , "Portuguese");
		menu(livros, quant);
		escolha(livros, quant);
		cout<<"Deseja fazer mais alguma coisa?\n";
		cin>>resp;
	}while((resp!='n')||(resp!='N'));
	
}

//Implementa��o das Fun��es
void menu(LIVRO x[], int &quant){
	char a = 186, b = 201, c = 205, d = 200, e = 188, f = 187;
	setlocale(LC_ALL , "C");
	cout<<b<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<f<<"\n";
	cout<<a<<"                        "<<a<<"\n";
	cout<<a<<"      1 - Inserir       "<<a<<"\n";
	cout<<a<<"      2 - Consultar     "<<a<<"\n";
	cout<<a<<"      3 - Eliminar      "<<a<<"\n";
	cout<<a<<"      4 - Atualizar     "<<a<<"\n";
	cout<<a<<"      0 - Terminar      "<<a<<"\n";
	cout<<a<<"                        "<<a<<"\n";
	cout<<d<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<e<<"\n";
}

void escmenu(LIVRO x[], int &quant){
	setlocale(LC_ALL , "Portuguese");
	int esc;
	cout<<"Digite a sua escolha: ";
	cin>>esc;
	switch (esc){
		case 1:
			individual(x, quant);
			break;
		case 2:
			escint(x,quant);
			break; 
		case 3:
			mentip(x,quant);
			break;
		case 4:
			registos(x,quant);
			break;
		case 0:
			system("cls");
			break;
		default:
			system("cls");
			cout<<"Erro! Op��o inv�lida.";
			fflush(stdin);
			getchar();
			system("cls");
			consultar(x,quant);
			escmenu(x, quant);
	}
}

void inserir(LIVRO x[], int &quant){
	setlocale(LC_ALL , "Portuguese");
	int somalivros;
	system("cls");
	cout<<"Quantos livros quer inserir?\n";
	cin>>somalivros;
	for(int i=quant; i<somalivros+quant; i++){
		system("cls");
		cout<<"Nome do Livro:\n";
		fflush(stdin);
		gets(x[i].nome);
		fflush(stdin);
		cout<<"Nome do Autor:\n";
		gets(x[i].autor);
		fflush(stdin);
		cout<<"Nome da Editora:\n";
		gets(x[i].editora);
		fflush(stdin);
		cout<<"Estilo do livro:\n";
		gets(x[i].estilo);
		fflush(stdin);
		do{
			cout<<"N�mero de p�ginas:\n";
			cin>>x[i].n_pags;
			if(x[i].n_pags<0){
				system("cls");
				cout<<"Erro! N�mero inv�lido.\n\n";
			}	
		}while(x[i].n_pags<0);
			cout<<"Ano de lancamento:\n";
			cin>>x[i].ano;	
		fflush(stdin);
		cout<<"Qual a l�ngua do livro:\n";
		gets(x[i].lingua.lingua);
		fflush(stdin);
		if(stricmp(x[i].lingua.lingua, "portugues")!=0){
			cout<<"Nome do Tradutor:\n";
			gets(x[i].lingua.tradutor);
			fflush(stdin);
			do{
				cout<<"Ano de tradu��o:\n";
				cin>>x[i].lingua.ano_tra;
				if(x[i].lingua.ano_tra<x[i].ano){
					system("cls");
					cout<<"Erro! Ano de tradu��o inferior ao ano de lan�amento.\n\n";	
				}
			}while(x[i].lingua.ano_tra<x[i].ano);
		}
		do{
			cout<<"Qual o pre�o do livro:\n";
			cin>>x[i].preco;
			if(x[i].preco<0){
				system("cls");
			cout<<"Erro! N�mero inv�lido.\n\n";	
			}
		}while(x[i].preco<0);
	}
	quant+=somalivros;
}

void consultar(LIVRO x[], int &quant){
	system("cls");
	char a = 186, b = 201, c = 205, d = 200, e = 188, f = 187;
	setlocale(LC_ALL , "C");
	cout<<b<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<f<<"\n";
	cout<<a<<"                                     "<<a<<"\n";
	cout<<a<<"      1 - Individual                 "<<a<<"\n";
	cout<<a<<"      2 - Listagem por intervalo     "<<a<<"\n";
	cout<<a<<"      3 - Listagem por tipo          "<<a<<"\n";
	cout<<a<<"      4 - Todos os registos          "<<a<<"\n";
	cout<<a<<"      0 - Sair                       "<<a<<"\n";
	cout<<a<<"                                     "<<a<<"\n";
	cout<<d<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<e<<"\n";
	escmenu(x, quant);
}

void eliminar(LIVRO x[], int &quant){
	system("cls");
	int remover;
	cout<<"Qual o n�mero do livro que deseja eliminar.\n";
	cin>>remover;
	remover--;
	if((remover<0)||(remover>quant)){
		system("cls");
		cout<<"Erro! Digite um valor v�lido!\n";
		eliminar(x,quant);
	}
	for(int i=remover;i<quant;i++){
		x[i]= x[i+1];
	}
	quant--;
	cout<<"\n\n\nLIVRO REMOVIDO COM SUCESSO!\n\n";
}

void atualizar(LIVRO x[], int &quant){
	int atu;
	cout<<"Qual  n�mero do livro que deseja atualizar?\n";
	cin>>atu;
	atu--;
	system("cls");
	cout<<"Nome do Livro:\n";
	fflush(stdin);
	gets(x[atu].nome);
	fflush(stdin);
	cout<<"Nome do Autor:\n";
	gets(x[atu].autor);
	fflush(stdin);
	cout<<"Nome da Editora:\n";
	gets(x[atu].editora);
	fflush(stdin);
	cout<<"Estilo do livro:\n";
	gets(x[atu].estilo);
	fflush(stdin);
	do{
		cout<<"N�mero de p�ginas:\n";
		cin>>x[atu].n_pags;
		if(x[atu].n_pags<0){
			system("cls");
			cout<<"Erro! N�mero inv�lido.\n\n";
		}	
	}while(x[atu].n_pags<0);
		cout<<"Ano de lancamento:\n";
		cin>>x[atu].ano;
	fflush(stdin);
	cout<<"Qual a l�ngua do livro:\n";
	gets(x[atu].lingua.lingua);
	fflush(stdin);
	if(stricmp(x[atu].lingua.lingua, "portugues")!=0){
		cout<<"Nome do Tradutor:\n";
		gets(x[atu].lingua.tradutor);
		fflush(stdin);
		do{
			cout<<"Ano de tradu��o:\n";
			cin>>x[atu].lingua.ano_tra;
			if(x[atu].lingua.ano_tra<x[atu].ano){
				system("cls");
				cout<<"Erro! Ano de tradu��o inferior ao ano de lan�amento.\n\n";	
			}
		}while(x[atu].lingua.ano_tra<x[atu].ano);
	}	
	do{
		cout<<"Qual o pre�o do livro:\n";
		cin>>x[atu].preco;
		if(x[atu].preco<0){
			system("cls");
			cout<<"Erro! N�mero inv�lido.\n\n";	
		}
	}while(x[atu].preco<0);
}

void escolha(LIVRO x[], int &quant){
	setlocale(LC_ALL , "Portuguese");
	int esc;
	cout<<"Digite a sua escolha: ";
	cin>>esc;
	switch (esc){
		case 1:
			inserir(x, quant);
			break;
		case 2:
			consultar(x, quant);
			break; 
		case 3:
			eliminar(x, quant);
			break;
		case 4:
			atualizar(x, quant);
			break;
		case 0:
			break;
		default:
			system("pause");
			cout<<"Erro! Op��o inv�lida.";
			fflush(stdin);
			getchar();
			system("cls");
			menu(x, quant);
	}
}

void individual(LIVRO x[], int &quant){
	int pesq;
	setlocale(LC_ALL , "Portuguese");
	system("cls");
	cout<<"Qual o n�mero do livro que deseja pesquisar: ";
	cin>>pesq;
	pesq-=1;
	if((pesq<0)||(pesq>quant)){
		system("cls");
		cout<<"Erro! Digite um valor v�lido!\n";
		individual(x,quant);
	}
	system("cls");
		cout<<"Nome do Livro:\n";
		cout<<x[pesq].nome<<"\n";		
		cout<<"Nome do Autor:\n";
		cout<<x[pesq].autor<<"\n";	
		cout<<"Nome da Editora:\n";
		cout<<x[pesq].editora<<"\n";
		cout<<"Estilo do livro:\n";
		cout<<x[pesq].estilo<<"\n";
		cout<<"N�mero de p�ginas:\n";
		cout<<x[pesq].n_pags<<"\n";
		cout<<"Ano de lancamento:\n";
		cout<<x[pesq].ano<<"\n";
		cout<<"Qual a l�ngua do livro:\n";
		cout<<x[pesq].lingua.lingua<<"\n";
		if(stricmp(x[pesq ].lingua.lingua, "portugues")!=0){
			cout<<"Nome do Tradutor:\n";
			cout<<x[pesq].lingua.tradutor<<"\n";
			cout<<"Ano de tradu��o:\n";
			cout<<x[pesq].lingua.ano_tra<<"\n";
		}
		cout<<"Pre�o:\n";
		cout<<x[pesq].preco<<"\n";
}

void escint(LIVRO x[], int &quant){
	system("cls");
	char a = 186, b = 201, c = 205, d = 200, e = 188, f = 187;
	setlocale(LC_ALL , "C");
	cout<<b<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<f<<"\n";
	cout<<a<<"                          "<<a<<"\n";
	cout<<a;setlocale(LC_ALL , "Portuguese");cout<<"      1 - Pre�o           ";setlocale(LC_ALL , "C");cout<<a<<"\n";
	cout<<a<<"      2 - Ano             "<<a<<"\n";
	cout<<a<<"      0 - Sair            "<<a<<"\n";
	cout<<a<<"                          "<<a<<"\n";
	cout<<d<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<e<<"\n";
	setlocale(LC_ALL , "Portuguese");
	int esc;
	cout<<"Digite a sua escolha: ";
	cin>>esc;
	switch (esc){
		case 1:
			preco(x, quant);
			break;
		case 2:
			anos(x,quant);
			break; 
		case 0:
			system("cls");
			break;
		default:
			system("cls");
			cout<<"Erro! Op��o inv�lida.";
			fflush(stdin);
			getchar();
			system("cls");
			consultar(x,quant);
		}
}

void preco(LIVRO x[], int &quant){
	system("cls");
	float min, max;
	LIVRO y[100];
	int cont=0, certo=0;
	do{
		cout<<"Qual o pre�o m�nimo:\n";
		cin>>min;
		if(min<0){
			system("cls");
			cout<<"Erro! Valor inv�lido!\n";
		}
	}while(min<0);
	
	do{
		cout<<"Qual o pre�o m�ximo:\n";
		cin>>max;
		if(max<0){
			system("cls");
			cout<<"Erro! Valor inv�lido!\n";
		}
	}while(max<0);
	if (max<min){
		float aux;
		aux=max;
		max=min;
		min=aux;
	}
	for(int i=0;i<quant;i++){
		if((x[i].preco>=min)&&(x[i].preco<=max)){
			y[cont]=x[i];
			cont++;
		}
	}
		for(int i=0;i<cont-1;i++)
			for (int j=0;j<cont-i-1;j++)		
				if (y[j].preco > y[j+1].preco){
					LIVRO aux;
					aux = y[j];
					y[j]=y[j+1];
					y[j+1]=aux;
				}
			
	for(int i=0;i<cont;i++){
		if((x[i].preco>=min)&&(x[i].preco<=max)){
			cout<<"\n\n";
			cout<<"Nome do Livro:\n";
			cout<<y[i].nome<<"\n";		
			cout<<"Nome do Autor:\n";
			cout<<y[i].autor<<"\n";	
			cout<<"Pre�o:\n";
			cout<<y[i].preco<<"\n";
		}
	}
}

void anos(LIVRO x[], int &quant){
	system("cls");
	int min, max;
	LIVRO y[100];
	int cont =0;
	cout<<"Qual o ano m�nimo:\n";
	cin>>min;
	cout<<"Qual o ano m�ximo:\n";
	cin>>max;
	if (max<min){
		float aux;
		aux=max;
		max=min;
		min=aux;
	}
	for(int i=0;i<quant;i++){
		if((x[i].ano>=min)&&(x[i].ano<=max)){
			y[cont]=x[i];
			cont++;
		}
	}
		for(int i=0;i<cont-1;i++)
			for (int j=0;j<cont-i-1;j++)		
				if (y[j].ano > y[j+1].ano){
					LIVRO aux;
					aux = y[j];
					y[j]=y[j+1];
					y[j+1]=aux;
				}
			
	for(int i=0;i<cont;i++){
			cout<<"\n\n";
			cout<<"Nome do Livro:\n";
			cout<<y[i].nome<<"\n";		
			cout<<"Nome do Autor:\n";
			cout<<y[i].autor<<"\n";	
			cout<<"Ano:\n";
			cout<<y[i].ano<<"\n";
	}
}

void registos(LIVRO x[], int &quant){
	system("cls");
	char b=219;
	for(int i=0;i<quant;i++){
		setlocale(LC_ALL , "Portuguese");
		cout<<"Nome do Livro:\n";
		cout<<x[i].nome<<"\n";		
		cout<<"Nome do Autor:\n";
		cout<<x[i].autor<<"\n";	
		cout<<"Nome da Editora:\n";
		cout<<x[i].editora<<"\n";
		cout<<"Estilo do livro:\n";
		cout<<x[i].estilo<<"\n";
		cout<<"N�mero de p�ginas:\n";
		cout<<x[i].n_pags<<"\n";
		cout<<"Ano de lancamento:\n";
		cout<<x[i].ano<<"\n";
		cout<<"Qual a l�ngua do livro:\n";
		cout<<x[i].lingua.lingua<<"\n";
		if(stricmp(x[i].lingua.lingua, "portugues")!=0){
			cout<<"Nome do Tradutor:\n";
			cout<<x[i].lingua.tradutor<<"\n";
			cout<<"Ano de tradu��o:\n";
			cout<<x[i].lingua.ano_tra<<"\n";
		}
		cout<<"Pre�o:\n";
		cout<<x[i].preco<<"\n";
		setlocale(LC_ALL , "C");
		cout<<"\n"<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<"\n\n";
		
	}
}

void mentip(LIVRO x[], int &quant){
	system("cls");
	char a = 186, b = 201, c = 205, d = 200, e = 188, f = 187;
	setlocale(LC_ALL , "C");
	cout<<b<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<f<<"\n";
	cout<<a<<"                      "<<a<<"\n";
	cout<<a<<"      1 - Nome        "<<a<<"\n";
	cout<<a<<"      2 - Autor       "<<a<<"\n";
	cout<<a<<"      3 - Editora     "<<a<<"\n";
	cout<<a<<"      4 - Estilo      "<<a<<"\n";
	cout<<a<<"      0 - Sair        "<<a<<"\n";
	cout<<a<<"                      "<<a<<"\n";
	cout<<d<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<e<<"\n";
	esctip(x, quant);
} 

void esctip(LIVRO x[], int &quant){
	setlocale(LC_ALL , "Portuguese");
	int esc;
	cout<<"Digite a sua escolha: ";
	cin>>esc;
	switch (esc){
		case 1:
			nome(x, quant);
			break;
		case 2:
			autor(x, quant);
			break; 
		case 3:
			editora(x, quant);
			break;
		case 4:
			estilo(x, quant);
			break;
		case 0:
			break;
		default:
			system("pause");
			cout<<"Erro! Op��o inv�lida.";
			fflush(stdin);
			getchar();
			system("cls");
			mentip(x, quant);
	}	
}

void nome(LIVRO x[], int &quant){
	system("cls");
	char pesq[60], b=219;
	cout<<"Nome do livro que deseja procurar:\n";
	fflush(stdin);
	gets(pesq);
	cout<<"\n\n";
	for(int i=0; i<quant;i++)
		if(stricmp(x[i].nome,pesq)==0){
			setlocale(LC_ALL , "Portuguese");
			cout<<"Nome do Livro:\n";
			cout<<x[i].nome<<"\n";		
			cout<<"Nome do Autor:\n";
			cout<<x[i].autor<<"\n";
			cout<<"Nome da Editora:\n";
			cout<<x[i].editora<<"\n";
			cout<<"Pre�o:\n";
			cout<<x[i].preco<<"\n";
			setlocale(LC_ALL , "C");
	cout<<"\n"<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<"\n\n";
		}
}

void autor(LIVRO x[], int &quant){
	system("cls");
	char pesq[60], barra=219;
	cout<<"Nome do autor que deseja procurar:\n";
	fflush(stdin);
	gets(pesq);
	cout<<"\n\n";
	for(int i=0; i<quant;i++)
		if(stricmp(x[i].autor,pesq)==0){
			setlocale(LC_ALL , "Poruguese");
			cout<<"Nome do Livro:\n";
			cout<<x[i].nome<<"\n";		
			cout<<"Nome do Autor:\n";
			cout<<x[i].autor<<"\n";
			cout<<"Nome da Editora:\n";
			cout<<x[i].editora<<"\n";
			cout<<"Pre�o:\n";
			cout<<x[i].preco<<"\n";
			setlocale(LC_ALL , "C");
			cout<<"\n"<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<"\n\n";
		}
}

void editora(LIVRO x[], int &quant){
	system("cls");
	char pesq[60], barra=219;
	cout<<"Nome da editora que deseja procurar:\n";
	fflush(stdin);
	gets(pesq);
	cout<<"\n\n";
	for(int i=0; i<quant;i++)
		if(stricmp(x[i].editora,pesq)==0){
			setlocale(LC_ALL , "Poruguese");
			cout<<"Nome do Livro:\n";
			cout<<x[i].nome<<"\n";		
			cout<<"Nome do Autor:\n";
			cout<<x[i].autor<<"\n";
			cout<<"Nome da Editora:\n";
			cout<<x[i].editora<<"\n";
			cout<<"Pre�o:\n";
			cout<<x[i].preco<<"\n";
			setlocale(LC_ALL , "C");
			cout<<"\n"<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<"\n\n";
		}
}

void estilo(LIVRO x[], int &quant){
	system("cls");
	char pesq[60], barra=219;
	cout<<"Estilo que deseja procurar:\n";
	fflush(stdin);
	gets(pesq);
	cout<<"\n\n";
	for(int i=0; i<quant;i++)
		if(stricmp(x[i].estilo,pesq)==0){
			setlocale(LC_ALL , "Poruguese");
			cout<<"Nome do Livro:\n";
			cout<<x[i].nome<<"\n";		
			cout<<"Nome do Autor:\n";
			cout<<x[i].autor<<"\n";
			cout<<"Estilo do Livro:\n";
			cout<<x[i].estilo<<"\n";
			cout<<"Pre�o:\n";
			cout<<x[i].preco<<"\n";
			setlocale(LC_ALL , "C");
			cout<<"\n"<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<barra<<"\n\n";
		}
}
