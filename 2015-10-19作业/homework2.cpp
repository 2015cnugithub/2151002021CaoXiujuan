#include<iostream.h>
#include<stdio.h>
#include<string>
using namespace std;

public class Worker
{
public:
	char name;
	int age;
	int sex;
	int pay_per_hour;

//	int hourly_paylevel;
//	int hours;
	//int compute_pay;

	void Compute_pay(double hours){
		//double compute_pay = hours * pay_per_hour;
	};

	void Name(){
		//�û�������Ϊ�û�ѡ��Ĳ˵���
	};


	friend ostream& operator<<(ostream& out,Worker& worker){
		cout<<"age:"<<worker.age<<"  sex:"<<worker.sex<<"  pay_per_hour:"<<worker.pay_per_hour<<"  compute_pay"<<worker.compute_pay<<endl;
	};



};

int hourly_paylevel;
int hours;
int compute_pay;

public class HourlyWorker : Worker
{
private:
	void Compute_pay(double hours){
		if(hours <= 40)
		{ int compute_pay = pay_per_hour * hours;}
		else
			compute_pay = pay_per_hour * 40 + 1.5 * pay_per_hour * (hours - 40);
	}
};

public class SalariedWorker : Worker
{
private:
	void Compute_pay(double hours){
		if(hours >= 35)
		{compute_pay = pay_per_hour * 40;}
		else
			compute_pay = pay_per_hour * hours + 0.5 * pay_per_hour * (35 - hours);
	}

};

void main()
{
	cout<<"�밴���¸�ʽ���빤����Ϣ�����������䣬�Ա����н��ȼ�"<<endl;
	Worker *workers[5];   
	
	for(int i=0;i<5;i++)
	{
		cin>>name>>age>>sex>>type>>paylevel;
		int pay_per_hour = 0;
		char name =" ";
		int age = 0;
		char sex = "Male";
		char type = "��ʱ����";
		int paylevel = "0";

		
		switch(paylevel)
		{
		case 1:
			pay_per_hour = 10;
			break;
		case 2:
			pay_per_hour = 20;
			break;
		case 3:
			pay_per_hour = 30;
			break;
		case 4:
			pay_per_hour = 40;
			break;
		case 5:
			pay_per_hour = 50;
			break;
		default:
			cout<<"н�ʵȼ�������������������";
		}

		if(type == "��ʱ����"&&paylevel == 10 || paylevel == 20 || paylevel == 40)
		{
			HourlyWorker* hourlyworker[i] = new HourlyWorker;
			&hourlyworker = workers[i];
		}
		else if(type == "н�ʹ���"&&paylevel == 30 || paylevel == 50)
		{
			SalariedWorker* salariedworker[i] = new SalariedWorker;
			salariedworker = workers[i];
		}
		else
			cout<<"�����������������"<<endl;

	}
}