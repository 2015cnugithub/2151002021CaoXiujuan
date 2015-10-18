#include<iostream>
#include<string>

using namespace std;

class Worker {
private:
	string name;
	int age;
	string sex;
	double pay_per_hour;
public:
	Worker(string n, int a, string s, double p) {
		name = n;
		age = a;
		sex = s;
		pay_per_hour = p;
	}

	string getName() {
		return name;
	}

	int getAge() {
		return age;
	}

	string getSex() {
		return sex;
	}

	double getPayPerHour() {
		return pay_per_hour;
	}

	friend ostream& operator <<(ostream& out, Worker& worker);

	virtual void compute_pay(double hours) {
	}
};

class HourlyWorker: public Worker {
public:
	HourlyWorker(string n, int a, string s, double p) :
			Worker(n, a, s, p) {
	}
	void compute_pay(double hours) {
		double weekSala = 0;
		if (hours >= 40) {
			weekSala = getPayPerHour() * 40
					+ 1.5 * getPayPerHour() * (hours - 40);
		} else {
			weekSala = getPayPerHour() * hours;
		}
		cout << "�ù��˵���нΪ��" << weekSala << endl;
	}
};

class SalariedWorker: public Worker {
public:
	SalariedWorker(string n, int a, string s, double p) :
			Worker(n, a, s, p) {
	}
	void compute_pay(double hours) {
		int weekSala = 0;
		if (hours >= 35) {
			weekSala = getPayPerHour() * 40;
		} else {
			weekSala = getPayPerHour() * hours
					+ 0.5 * getPayPerHour() * (35 - hours);
		}
		cout << "�ù��˵���нΪ��" << weekSala << endl;
	}
};

ostream& operator <<(ostream& out, Worker& worker) {
	out << "����: " << worker.getName() << endl;
	out << "����: " << worker.getAge() << endl;
	out << "�Ա�: " << worker.getSex() << endl;
	out << "н�ʵȼ�: " << worker.getPayPerHour() << endl;
	return out;
}

int main() {
	cout << "���������������Ϣ" << endl;

	Worker* workers[5];

	int i = 0;
	for (; i < 5; i++) {
		cout << "�밴���¸�ʽ���빤����Ϣ�����������䣬�Ա����1.HourlyWorker 2.SalariedWorker����н��ȼ�"
				<< endl;
		string name;
		int age;
		string sex;
		int type;
		double paylevel;
		cin >> name >> age >> sex >> type >> paylevel;

		if (type == 1) {
			workers[i] = new HourlyWorker(name, age, sex, paylevel);
		} else {
			workers[i] = new SalariedWorker(name, age, sex, paylevel);
		}
	}

	while (true) {
		cout << "��ѡ��һ�����ˣ��������֣����˳�������exit��" << endl;
		for (i = 0; i < 5; i++) {
			cout << workers[i]->getName() << " ";
		}
		cout << endl;

		string selected;
		cin >> selected;

		if ("exit" == selected) {
			break;
		} else {
			bool found = false;
			for (i = 0; i < 5; i++) {
				string n = workers[i]->getName();
				if (selected == n) {
					found = true;
					break;
				}
			}

			if (found) {
				cout << *workers[i];
				cout << "������ù��˵�ʵ�ʹ�ʱ��" << endl;
				double hours;
				cin >> hours;
				workers[i]->compute_pay(hours);
			} else {
				cout << "����" << selected << "�����ڡ�" << endl;
			}
		}
	}

	for (i = 0; i < 5; i++) {
		delete workers[i];
	}

	cout << "����������ټ���" << endl;

	return 0;
}
