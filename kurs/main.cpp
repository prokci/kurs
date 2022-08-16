#include "head.h"
#include <conio.h>
void show(s4et4ik&, s4et4ik&);
void update_data(s4et4ik&, s4et4ik&);
void save_data(s4et4ik&, s4et4ik&);
int main() {
	setlocale(LC_ALL, "Russian");
	int choose(0);
	s4et4ik *one = new GVS(50, 20, 100);
	s4et4ik *two = new HV(10, 20, 50);	
	do {
		system("cls");
		cout << "1.���������� ���������" << endl
			<< "2.������ ����� ������" << endl
			<< "3.��������� ��������" << endl
			<< "4.�����" << endl;
		cin >> choose;
		switch (choose) {
		case 1: show(*one, *two);
			break;
		case 2: update_data(*one, *two);
			break;
		case 3: save_data(*one, *two);
			break;
		case 4: break;
		
		}
	} while (choose != 4);
		system("cls");
	
	delete one;
	delete two;
	return 0;
}
void show(s4et4ik &one, s4et4ik &two) {
	int choose;
	do {
		system("cls");
		one.show_info();
		cout << endl << endl;
		two.show_info();
		cout << endl << endl <<
			"0.�����" << endl;
		cin >> choose;
	} while (choose != 0);
}
void update_data(s4et4ik &one, s4et4ik &two) {
	int energy, vGVS, v_1GVS, t1_GVS, t2_GVS, vHV, v_1HV, t_HV;
	system("cls");
	cout << "������� ������������ �������: ";
	cin >> energy;
	cout << "������� ����������� ������ ��� ���: ";
	cin >> vGVS;
	cout << "������� �������� ������ ��� ���: ";
	cin >> v_1GVS;
	cout << "������� ����������� �� ����� ��� ���: ";
	cin >> t1_GVS;
	cout << "������� ����������� �� ������ ��� ���: ";
	cin >> t2_GVS;
	cout << "������� ���������� ������ ��� ��: ";
	cin >> vHV;
	cout << "������� �������� ������ ��� ��: ";
	cin >> v_1HV;
	cout << "������� ����������� ��� ��: ";
	cin >> t_HV;
	one.setV(vGVS);
	one.setEnergy(energy);
	one.setV_1(v_1GVS);
	one.t1_enter(t1_GVS);
	one.t2_exit(t2_GVS);
	two.setV(vHV);
	two.setV_1(v_1HV);
	two.t1_enter(t_HV);

}
void save_data(s4et4ik &one, s4et4ik &two) {
	one.save();
	two.save();
}