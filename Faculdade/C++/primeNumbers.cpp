#include <iostream>
#include <locale.h>

using namespace std;

int primeNumbers[500], primeAmount = 0;


void fillArray(int number){
  primeNumbers[primeAmount] = number;
  primeAmount++;
}

bool isPrimeHighNumbers(int n){
  bool res = true;

  for(int i = 0; i < primeAmount; i++){
    if(n%primeNumbers[i] == 0){
      res = false;
    } 
  }
  if(res){
    fillArray(n);
  }

  return res;
}

bool isPrimeLowNumbers(int n){
  bool res = true;
  int c = n - 1;
  while(c > 1){
    if(n%c == 0){
      res = false;
    }
    c--;
  }
  if(res){
    fillArray(n);
  }
  return res;
}

bool isPrime(int n){ 
  bool result = true;
  int c;
  
  if(n<10){
    result = isPrimeLowNumbers(n);
  } else {
      if (isPrimeLowNumbers(n) && isPrimeHighNumbers(n)){
      result = true;
    }
  }
  
  return result;
}

int main() {
  
  int maxNumber;
  bool isItPrime;

  cout << "Achar numeros primos.\n";
  
  cout << "Digite um numero maximo: ";
  cin >> maxNumber;

  cout << "Numeros primos de 1 ate " << maxNumber << endl;

  for(int i = 2; i <= maxNumber; i++){
    isPrime(i);
  }

  for(int i = 0; i <= (primeAmount - 1); i++){
    cout << primeNumbers[i] << endl;
  }

  return 0;
}

