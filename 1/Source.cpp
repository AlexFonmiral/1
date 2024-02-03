#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<Windows.h>
#include<fstream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	//ScientistName#preparation#date#components
	string ScientistName, preparation, date, components;
	ifstream f("scientist.txt");
	vector<vector<string>> v(503, vector<string>(4));
	int i = 0;
	while (f.good()) {
		getline(f, ScientistName, '#');
		getline(f, preparation, '#');
		getline(f, date, '#');
		getline(f, components, '\n');
		v[i][2] = ScientistName;
		v[i][1] = preparation;
		v[i][0] = date;
		v[i][3] = components;
		i++;
		//cout << v[i][0] << endl;
	}

	//	cout << v[500][0];
	ofstream f2;
	cout << "�������������� ������������ ���� ����� ����:" << endl;
	f2.open("scientist_origin.txt");
	sort(v.begin(), v.end());
	string fio = v[1][0], comp = v[1][1];
	f2 << "ScientistName" << "-" << "date" << '\n';
	f2 << v[1][2] << "-" << v[0][0] << '\n';
	for (int i = 2; i <= 500; i++) {
		if (comp != v[i][1]) {
			f2 << v[i][2] << "-" << v[i][0] << '\n';
			comp = v[i][1];
		}
		else {
		cout<< v[i][2] << "-" << v[i][0] << '\n';
		}
	}
 }