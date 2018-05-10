#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::strlen;
using std::strcpy;
using std::min;
using std::copy;

template<typename T>
void ChangeSize1D(T*& array,const int oldSize, const int newSize){
	T* temp=new T[newSize];
	int number=min(oldSize,newSize);
	copy(array,array+number,temp);
	delete[] array;
	array = temp;
}

//Bag
template<typename T>
class Bag{

	T* array; //용량 부족하면 1D 함수 호출하기 위해서
	int capacity; //용량
	int top; //가장 최근 인덱스

public:
	Bag(int bagCapacity=3) :capacity(bagCapacity)//생성자 오버로딩
	{
		array = new T[capacity];
		top=-1;
	}
	~Bag() {delete[] array;	}//소멸자
	
	int Size() const {return top+1;}//bag안에 요소 개수 리턴
	
	bool isEmpty() const {return Size() == 0;}//bag 이 비었으면 true
	
	T& Element() const throw(char const*)//bag안의 요소를 리턴
	{
		if(isEmpty()) 
				throw "Bag is Empty";
		return array[rand()%Size()];
	}
	void Push(const T& x) //bag에 넣기
	{
		if(capacity == (top+1)) {//꽉찼으면 2배로 늘리기
			ChangeSize1D(array,capacity,2*capacity);
			capacity *=2;
		}
		array[++top] = x;
	}
	void Pop() //bag에서 꺼내기
	{
		if(isEmpty()) throw "Bag is empty, cannot delete";
		int deletePos=rand()%Size();
		if(deletePos != top)
			copy(array+deletePos+1,array+top+1,array+deletePos); //앞으로 땡기기
		array[top--].~T();//하나 삭제되서

	}
};

//Bizcard
class Bizcard {

char* name;
char* phone;

void setPointerField(char*& field, const char* input){
	field=new char[strlen(input)+1];
	strcpy(field,input);
}

public:
Bizcard() {} //초기화 생성자
Bizcard(const char* name, const char* phone) //초기화 생성자 오버로딩
{
	setPointerField(this->name,name);
	setPointerField(this->phone,phone);
}
~Bizcard()//소멸자
{
	if(name!=NULL)

	{

	delete[] name;

	name=NULL;

	}

	if(phone!=NULL)

	{

	delete[] phone;

	phone=NULL;

	}
}
Bizcard(const Bizcard& copy) //복사 생성자
{
	setPointerField(this->name,copy.name);
	setPointerField(this->phone,copy.phone);
}

Bizcard& operator=(const Bizcard& copy) //대입 연산자
{
	delete[] name;
	delete[] phone;
	setPointerField(this->name,copy.name);
	setPointerField(this->phone,copy.phone);
	return *this;
}

void showInfo()//이름과 전화번호 출력
{
	cout<<"name : "<<name<<endl;
	cout<<"phone : "<<phone<<endl;
}

};



/************************* main() **************************/



int main(void){

	Bag<Bizcard> BizBag;

	cout<<"===== 빈 Bag 결과 확인 ====="<<endl;
	cout<<"Size() : "<<BizBag.Size()<<endl;
	cout<<"isEmpty() : "<<BizBag.isEmpty()<<endl;
	try{
	cout<<"Element() : "<<endl; BizBag.Element().showInfo(); 
	}catch(char const* e){
		cout<<e<<endl;
	}
	// try{
	// BizBag.Pop();
	// }catch(char const* e){
	// 	cout<<e<<endl;
	// }

	Bizcard So("so","010");
	Bizcard Hye("hye","5507");
	Bizcard Bin("bin","4148");
	BizBag.Push(So);
	BizBag.Push(Hye);
	BizBag.Push(Bin);

	cout<<"===== 객체 3개 추가 후 결과 확인 ====="<<endl;
	cout<<"Size() : "<<BizBag.Size()<<endl;
	cout<<"isEmpty() : "<<BizBag.isEmpty()<<endl;
	cout<<"Element() : "<<endl; BizBag.Element().showInfo();
	
	Bizcard Kim("kim","02");
	Bizcard Ik("ik","820");
	Bizcard Su("su","0926");
	Bizcard Plorer("plorer","1004");
	BizBag.Push(Kim);
	BizBag.Push(Ik);
	BizBag.Push(Su);
	BizBag.Push(Plorer);

	cout<<"===== 객체 4개 추가 후 결과 확인 ====="<<endl;
	cout<<"Size() : "<<BizBag.Size()<<endl;
	cout<<"isEmpty() : "<<BizBag.isEmpty()<<endl;
	cout<<"Element() : "<<endl; BizBag.Element().showInfo();

	try{
		BizBag.Pop();
		BizBag.Pop();
		cout<<"===== 객체 2개 삭제 후 결과 확인 ====="<<endl;
		cout<<"Size() : "<<BizBag.Size()<<endl;
		cout<<"isEmpty() : "<<BizBag.isEmpty()<<endl;
		cout<<"Element() : "<<endl; BizBag.Element().showInfo();

	}catch(char const* e){
		cout<<e<<endl;
	}
	
	return 0;
}


