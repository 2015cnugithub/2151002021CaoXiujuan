#include<iostream>
using namespace std;
class CGoods5
{
private:
	long no;
	char *p_name;
	double price;

	static int count;
	
public:

	CGoods(long no1=0,char *p_name1=" ",double price1=0)	//构造函数
	{
		no=no1;
		p_name=p_name1;
		price=price1;

		count++;
	};
	
	CGoods(CGoods& goods)	//拷贝构造函数
	{
		no=goods.getNo();
		p_name=goods.getPName();
		price=goods.getPrice();

		count++;
	};

	~CGoods(){
		cout<<"CGoods died."<<endl;
	};

	long getNo(){
		return no;
	}

	char* getPName(){
		return p_name;
	}

	double getPrice(){
		return price;
	}

	static int getCount(){
		return count;
	}

	void print()
	{
		cout<<no<<"  "<<p_name<<"  "<<price<<endl;
	}

	friend char* getName(CGoods& goods);

	virtual void usedFor(){
		//
	}
};

int CGoods::count = 0;

char* getName(CGoods& goods){
	return goods.p_name;
}

bool operator < (CGoods& goods1, CGoods& goods2){
	bool result = false;
	if(goods1.getPrice()<goods2.getPrice()){
		result = true;
	}
	return result;
}

bool operator >= (CGoods& goods1, CGoods& goods2){
	bool result = false;
	if(goods1.getPrice()>=goods2.getPrice()){
		result = true;
	}
	return result;
}

class CClothes: public CGoods{
private:
	char* p_brand;
public:
	CClothes(long,char*,double,char*);

	CClothes(CClothes& clothes): CGoods(clothes){
		p_brand = clothes.getPBrand();
	}

	char* getPBrand(){
		return p_brand;
	}

	void usedFor(){
		cout<<"CClothes"<<endl;
	}

	~CClothes(){
		cout<<"CClothes died."<<endl;
	}
};

CClothes::CClothes(long n, char* pN, double pr, char* pB):CGoods(n,pN,pr){
	p_brand = pB;
}

class CFood: public CGoods{
private:
	char* p_brand;
public:
	CFood(long,char*,double,char*);

	CFood(CFood& food):CGoods(food){
		p_brand = food.getPBrand();
	}

	char* getPBrand(){
		return p_brand;
	}

	void usedFor(){
		cout<<"CFood"<<endl;
	}

	~CFood(){
		cout<<"CFood died."<<endl;
	}
};

CFood::CFood(long n, char* pN, double pr, char* pB):CGoods(n,pN,pr){
	p_brand = pB;
}

int main()
{
	CGoods goods1(1001,"apple",2.51);
	goods1.print();

	CGoods goods2(goods1);
	goods2.print();

	cout<<"Count: "<<CGoods::getCount()<<endl;

	cout<<"Name: "<<getName(goods1)<<endl;

	CGoods goods3(1003, "pear", 3.0);

	if(goods1<goods3){
		cout<<"The apple is little than pear."<<endl;
	}
	
	if(goods1>=goods2){
		cout<<"The goods1 is more or equals goods2."<<endl;
	}

	CClothes clothes1(1101, "clothes1", 1000, "wear");
	clothes1.print();

	CFood food1(1201, "food1", 200, "eat");
	food1.print();

	CGoods* pGoods;
	if(clothes1<food1){
		pGoods = &clothes1;
	}else{
		pGoods = &food1;
	}
	pGoods->usedFor();

	CClothes clothes2(clothes1);
	clothes2.print();

	cout<<"--------------------"<<endl;

	return 0;
}