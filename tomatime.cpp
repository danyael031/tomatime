/* Temporizador basado en la técnica Pomodoro para organización de tiempo
 * 
 */

#include <iostream>
#include <ctime>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

int tomatime(){
	return 0;
}

int main(int argc, char *argv[]){
	clock_t iniTiempo = clock();
	for (int i = 0; i<=1000000; i++){
		cout<<i<<endl;
	}
	
	double segundos = (clock() - iniTiempo) / (double) CLOCKS_PER_SEC;
	cout << segundos << endl;	
}

int procArg(int numArg, char args[]){
	
	for (int i = 0; i < numArg; i++){
		
		cout<<args[i]<<endl;
	}
	cout<<"Primer proyecto subido a github"<<endl;
	return 0;

}
