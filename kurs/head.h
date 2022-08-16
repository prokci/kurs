#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class s4et4ik						//������
{
private:
	double V;						//������ � �������
	double energy;					//������������ �������
	double V_1;						//������ �� �����
public:
	int T1_enter = 50;
	int T2_exit = 65;
	s4et4ik();						//����������� �� ���������
	s4et4ik(double v_per_sec, double Energy, double v_per_day) { // ����������� ��� ���������
		V = v_per_sec;
		V_1 = v_per_day;
		energy = Energy;
	}
	void setV(int);					//��������� ������� � �������
	void setEnergy(int);			//��������� ������������ �������
	void setV_1(int);				//��������� ������� � �����
	double get_V();					//��������� �������� ����������� �������
	double get_energy();			//��������� ������������ �������
	double get_V_1();				//��������� ������� �� �����
	int get_t1();					//��������� ����������� �� �����
	int get_t2();					//��������� ����������� �� ������
	void t1_enter(int);				//����������� �� �����
	void t2_exit(int);					//����������� �� ������
	virtual void save();			//���������� ���������� ��������
	virtual void show_info()=0;		//����������� ������

	virtual ~s4et4ik() {}
};
class GVS : public s4et4ik {		//������� ������� ����
private:
	double Q;						//������������
public:
	GVS();							//����������� �� ���������
	GVS(double v_per_sec, double v_per_day, double energy) : s4et4ik(v_per_sec, energy, v_per_day) { // ����������� ��� ���

	}

	void show_info();				//����������� ������
	double ggcall();				//������ ������������
	void save();
	~GVS();


};

class HV : public s4et4ik {
public:
	HV();							//����������� �� ���������
	HV(double v_per_sec, double v_per_day, double energy) : s4et4ik(v_per_sec, energy, v_per_day) {}//����������� ��� ��
	void show_info();
	void save();
	~HV();

};
