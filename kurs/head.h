#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class s4et4ik						//шаблон
{
private:
	double V;						//расход в секунду
	double energy;					//потребляемая энергия
	double V_1;						//расход за сутки
public:
	int T1_enter = 50;
	int T2_exit = 65;
	s4et4ik();						//конструктор по умолчанию
	s4et4ik(double v_per_sec, double Energy, double v_per_day) { // конструктор для счетчиков
		V = v_per_sec;
		V_1 = v_per_day;
		energy = Energy;
	}
	void setV(int);					//изменение расхода в секунду
	void setEnergy(int);			//изменение потребляемой энергии
	void setV_1(int);				//изменение расхода в сутки
	double get_V();					//получение значения мгновенного расхода
	double get_energy();			//получение потребляемой энергии
	double get_V_1();				//получение расхода за сутки
	int get_t1();					//получение температуры на входе
	int get_t2();					//получение температуры на выходе
	void t1_enter(int);				//температура на входе
	void t2_exit(int);					//температура на выходе
	virtual void save();			//сохранение полученных значений
	virtual void show_info()=0;		//отображение данных

	virtual ~s4et4ik() {}
};
class GVS : public s4et4ik {		//счетчик горячей воды
private:
	double Q;						//Гигокаллории
public:
	GVS();							//конструктор по умолчанию
	GVS(double v_per_sec, double v_per_day, double energy) : s4et4ik(v_per_sec, energy, v_per_day) { // конструктор для ГВС

	}

	void show_info();				//отображение данных
	double ggcall();				//расчет гигокаллорий
	void save();
	~GVS();


};

class HV : public s4et4ik {
public:
	HV();							//конструктор по умолчанию
	HV(double v_per_sec, double v_per_day, double energy) : s4et4ik(v_per_sec, energy, v_per_day) {}//конструктор для ХВ
	void show_info();
	void save();
	~HV();

};
