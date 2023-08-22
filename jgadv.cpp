#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
	cout << "_________________________" << endl;
	cout << "|Sejam Bem vidos ao jogo|" << endl;
	cout << "-------------------------" << endl;

	cout << "Escolha a dificuldade" << endl;
	cout << "Facil (F), Medio (M) OU Dificil (D)" << endl;

	char dificuldade;
	cin >> dificuldade;

	int numero_de_tentativas;

	if(dificuldade == 'F') {
		numero_de_tentativas = 15;
	}
	else if(dificuldade == 'M') {
		numero_de_tentativas = 10;
	}
	else{
		numero_de_tentativas = 5;
	}	
	
	srand(time(NULL));
	const int NUMERO_SECRETO = rand() %100;

	
	bool nao_acertou = true;
	int tentativas = 0;

	double pontos = 1000.0;
	
	for(tentativas = 1;tentativas <= numero_de_tentativas;tentativas++){
		int chute;
		cout << "tentativas" << tentativas << endl;
		cout << "Qual seu chute? ";
		cin >> chute;

		double lose_points = abs(chute - NUMERO_SECRETO)/ 2.0;
		pontos = pontos - lose_points;	

		bool Acertou = chute == NUMERO_SECRETO;
		bool Maior = chute > NUMERO_SECRETO;

		if (Acertou) {
			cout << "Parabéns! Você acertou o número secreto !" << endl;
			nao_acertou = false;
			break;

		}
		else if (Maior) {
			cout << "Seu chute foi maior que o número secreto !" << endl;

		}
		else
		{
			cout << "Seu chute foi menor que número secreto !" << endl;
		}

	}
	cout << "FIM DE JOGO" << endl;
	if (nao_acertou){
		cout << "Voce gastou todas as tentivas e o numero secreto era:"  << NUMERO_SECRETO << endl;
	}
	else
	{
		cout << "VOCE ACERTOU O NUMERO SECRETO EM" << tentativas << "TENTATIVAS" << endl;
		cout.precision(2);
		cout << fixed;
		cout << "SUA PONTUAÇAO FOI" << pontos << "PONTOS" << endl;
	}
}