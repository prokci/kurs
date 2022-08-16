#pragma once
#include "head.h"
void s4et4ik::setEnergy(int E) {
	this->energy = E;
}
void s4et4ik::setV(int v) {
	this->V = v;
}
void s4et4ik::setV_1(int v_1) {
	this->V_1 = v_1;
}
void GVS::show_info() {
	cout << "\t\t\tСчетчик горячей воды" << endl << endl
		<< "Мгновенный расход: " << this->get_V() << endl
		<< "Расход за сутки: " << this->get_V_1() << endl
		<< "Потребляемая энергия: " << this->get_energy() <<endl
		<< "Гигокаллории: " << this->ggcall() << endl;
}

double s4et4ik::get_energy() {
	return this->energy;
}

double s4et4ik::get_V() {
	return this->V;
}
double s4et4ik::get_V_1() {
	return this->V_1;
}

double GVS::ggcall() {
	this->Q = get_V() / (get_t2() - get_t1());
	return this->Q;
}

int s4et4ik::get_t2() {
	return T2_exit;
}

int s4et4ik::get_t1() {
	return T1_enter;
}

void HV::show_info() {
	cout << "\t\t\tСчетчик холодной воды\n\n" << "Температура воды: " << this->get_t1() << endl
		<< "Мгновенный расход: " << this->get_V() << endl
		<< "Расход за сутки: " << this->get_V_1() << endl;
}



void s4et4ik::t1_enter(int t1) {
	this->T1_enter = t1;
}

void s4et4ik::t2_exit(int t2) {
	this->T2_exit = t2;
}

void s4et4ik::save() {}

void GVS::save() {
	ofstream fout("data.txt");
	fout <<  "\t\t\tСчетчик горячей воды" << endl << endl
		<< "Мгновенный расход: " << this->get_V() << endl
		<< "Расход за сутки: " << this->get_V_1() << endl
		<< "Потребляемая энергия: " << this->get_energy() << endl
		<< "Гигокаллории: " << this->ggcall() << endl << endl;
	fout.close();
}

void HV::save() {

	ofstream fout("data.txt",ios_base::app);
	
	fout << "\t\t\tСчетчик холодной воды\n\n" << "Температура воды: " << this->get_t1() << endl
		<< "Мгновенный расход: " << this->get_V() << endl
		<< "Расход за сутки: " << this->get_V_1() << endl;
	fout.close();
}



GVS::GVS() {}
GVS::~GVS() {}

HV::HV() {}
HV::~HV() {}