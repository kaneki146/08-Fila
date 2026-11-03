#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* inicio = NULL;
NO* fim = NULL;

// headers
void menu();
void inicializar();
void insere();
void remove();
void exibir();
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 5) {
		system("cls"); // somente no windows
		cout << "Menu Fila";
		cout << endl << endl;
		cout << "1 - Inicializar Fila \n";
		cout << "2 - Inserir elemento \n";
		cout << "3 - Remover elemento  \n";
		cout << "4 - Exibir elementos" << endl;
		cout << "5 - Sair \n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:insere();
			break;
		case 3: remove();
			break;
		case 4: exibir();
			break;
		case 5:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = inicio;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	inicio = NULL;
	fim = NULL;
	cout << "Fila inicializada \n";

}

void exibir()
{
	NO* aux = inicio;

	if (aux == NULL) {
		cout << "Fila vazia" << endl;
		return;
	}

	while (aux != NULL) {
		cout << aux->valor << endl;
		aux = aux->prox;
	}
	return;
}


void insere()
{
	NO* novo = (NO*)malloc(sizeof(NO));

	if (novo == NULL) {
		return;
	}

	cout << "Digite o elemento" << endl;
	cin >> novo->valor;
	novo->prox = NULL;

	if (inicio == NULL) {
		inicio = novo;
		fim = novo;
	}
	else {
		fim->prox = novo;
		fim = novo;
	}
}

void remove()
{
	NO* aux = inicio;

	if (inicio == NULL) {
		cout << "A lista esta vazia" << endl;
		return;
	}

	inicio = inicio->prox;
	free(aux);
}

