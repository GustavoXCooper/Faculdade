#include <iostream>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <locale.h>



using namespace std;

bool playing = true;
int resultMatriz[10][3];

void clearScreen(){
  cout << "\033[2J\033[0;0H";
}

void showResults(int timesPlayed){
  cout << " ----- HISTÓRICO -----\n";
  cout << "=-=-=-=-=-=-=-=-=-=-=-=\n\n";
  cout << "- Você X PC ---- Resultado\n\n";
  
  for(int i = 0; i < timesPlayed; i++ ){
    for(int j = 0; j < 3; j++){
      switch(j){
      case 0:
        if(resultMatriz[i][j] == 0){
          cout << "Pedra X";
        } else if (resultMatriz[i][j] == 1){
          cout << "Papel X";
        } else {
          cout << "Tesoura X";
        }
      break;
      case 1:
        if(resultMatriz[i][j] == 0){
          cout << " Pedra";
        } else if (resultMatriz[i][j] == 1){
          cout << " Papel";
        } else {
          cout << " Tesoura";
        }
      break;
      case 2:
        if(resultMatriz[i][j] == 0){
          cout << " -- Você venceu!";
        } else if (resultMatriz[i][j] == 1){
          cout << " -- Empate!";
        } else {
          cout << " -- Você perdeu!";
        }
      break;
      cout << endl;
      }
    }
    cout << endl;
  }
}

void controlsOutOfGame(){
  cout << "1 - para continuar jogando\n2 - para parar de jogar\n\n";
  cout << "----------------------\n";
}
void controlsInGame(){
  cout << "Comandos:\n\n";
  cout << "1 - para pedra\n2 - para papel\n3 - para tesoura\n";
}
void controls(){
  controlsOutOfGame();
  controlsInGame();
}

void endGame(int timesPlayed){
  playing = false;
}

int compAction(int timesPlayed){
  int computerAction;
  
  computerAction = rand() % 3;
  
  resultMatriz[timesPlayed - 1][1] = computerAction;
  
  return computerAction;
}

void keepPlaying(int timesPlayed){
  int action;

  controlsOutOfGame();
  cout << "\nDeseja jogar novamente? ";
  cin >> action;
  
  switch (action){
    case 1:
      playing = true;
      clearScreen();
      if(timesPlayed == 10){
        cout << "\nMáximo de tentativas alcançadas.";
        endGame(timesPlayed);
      }
    break;
    case 2: 
     endGame(timesPlayed);
    break;
    default:
      cout << "\nVocê não digitou uma ação válida.";
      sleep(5);
      endGame(timesPlayed);
    break;
  }
}

void loadingScreen(){
  char loadDots[4] = {'.', '.', '.', '.'};
  
  clearScreen();
  
  cout.flush();
  cout << "Loading";
  
  for(int c = 0; c < 4; c++) {
    sleep(1);
    cout.flush(); // replit é linux, sleep é biblioteca do windows, então talvez por isso não tenha funcionado sem o flush();
    cout << loadDots[c];
  }
  sleep(2);
}

void resultScreen(int playerAction, int computerAction){
  string pA, cA;
  
  switch(playerAction){
    case 0:
      pA = "Pedra";
    break;
    case 1:
      pA = "Papel";
    break;
    case 2:
      pA = "Tesoura";
    break; 
  }

  switch(computerAction){
    case 0:
      cA = "Pedra";
    break;
    case 1:
      cA = "Papel";
    break;
    case 2:
      cA = "Tesoura";
    break; 
  }

  cout << "Você  X  PC\n";
  cout << "-------------\n\n";
  cout << pA << " X " << cA << endl << endl;
};

void resultDecision(int playerAction, int computerAction, int timesPlayed){
  
  if (
    (computerAction == 0 && playerAction == 1) ||
    (computerAction == 1 && playerAction == 2) ||
    ((computerAction == 2 && playerAction == 0))){
    cout << "Você venceu!\n";  
    
    resultMatriz[timesPlayed - 1][2] = 0;   
    
  }
  else if (computerAction == playerAction){
    cout << "Empate!\n";
    resultMatriz[timesPlayed - 1][2] = 1;   
  } else {
    cout << "Você perdeu :(\n";
    resultMatriz[timesPlayed - 1][2] = 2; 
  }
}

void result(int playerAction, int timesPlayed){ 
  
  int computerAction = compAction(timesPlayed);
  
  
  loadingScreen(); 
  clearScreen();
  
  resultScreen(playerAction, computerAction);
  resultDecision(playerAction, computerAction, timesPlayed);
  
  sleep(2);
  cout << endl;
  keepPlaying(timesPlayed);
  clearScreen();
  
}



void play(int timesPlayed){
  int playerAction;
  controlsInGame();
  cout << "\nInsira sua jogada: ";
  cin >> playerAction;

  playerAction = playerAction - 1;

  resultMatriz[timesPlayed - 1][0] = playerAction;

  if(playerAction == 0 || playerAction == 1 || playerAction == 2){
    result(playerAction, timesPlayed);
  } else {
    cout << "Você não digitou uma ação válida.";
    endGame(timesPlayed);
  }
}

void intro(int timesPlayed){
  if ( timesPlayed == 1){
    clearScreen();

    cout << "PEDRA, PAPEL OU TESOURA!\n";
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    sleep(2);
    clearScreen();
    sleep(2);
  }
}

int main() {
  setlocale(LC_ALL, "");
  srand(time(0));
  int timesPlayed = 0;
  
  while(playing == true){
    timesPlayed++; 
    intro(timesPlayed);
    play(timesPlayed);
  }

  showResults(timesPlayed);
}