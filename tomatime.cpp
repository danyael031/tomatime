/* Temporizador basado en la técnica Pomodoro para organización de tiempo
 * 
 */

#include <iostream>
#include <ctime>
#include <cmath>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;
using std::cin;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; 

const clock_t REFRSH_VEL = CLOCKS_PER_SEC/20;
//--------------------Area de pruebas--------------------
void pruebapun(){
	int a = 10;
	int *y = &a;
	*y = *y+1;
	cout<< *y << endl << a << endl;
	
}
//----------------Fin Area de pruebas--------------------

clock_t timeToTicks(int horas, int minutos, int segundos){
	clock_t resultado = ((horas*3600)+(minutos*60)+(segundos))*CLOCKS_PER_SEC;
	return resultado;
}

class backCron{
	private:
	clock_t ti,tf;
	clock_t restante;
	int hr, min, seg;
	int hrO, minO, segO;
	bool activo;

	public:
	backCron(int Horas, int Minutos, int Segundos){
		hr = hrO = Horas;
		min = minO = Minutos;
		seg = segO = Segundos;
	}
	
	void count(){
		bool flag = true;
		clock_t	refF = clock() + REFRSH_VEL;
		while(flag){
			restante = tf - clock();
			if (restante <= 0) {
				flag = false;
			}
			else if (clock() >= refF){
				cout << restante << endl;
			}
		}
	}
	void run(){
		activo = true;
		ti = clock();
		tf = ti + timeToTicks(hrO,minO,segO);
		count();
		}
};

struct PomSession { 
int focus = 25;   //Tiempo de enfoque
int shRest = 5;   //Duración del descanso corto
int lrgRest = 20; //Duración del descanso largo 
int pomoRest = 4; //cantidad de pomodoros antes de un descanso largo
}pomodoro, pomcontrol;
	
	
	
void tomatime(){
	backCron cronometro(0,0,10);	
	cronometro.run();
}

int main(int argc, char *argv[]){
	//tomatime();
	pruebapun();
}

