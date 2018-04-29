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
void ChangeSize1D(T*& array,const int oldSize, const int newSize);

template<typename T>
class Bag{

	T* array; //용량 부족하면 1D 함수 호출하기 위해서
	int capacity =3; //용량
	int top; //가장 최근 인덱스

public:
	Bag();//생성자
	Bag(int bagCapacity); //생성자 오버로딩
	~Bag(); //소멸자

	int Size() const; //bag안에 요소 개수 리턴
	bool isEmpty() const; //bag 이 비었으면 true
	T& Element() const; //bag안의 요소를 리턴

	void Push(const T&); //bag에 정수 넣기
	void Pop(); //bag에서 정수 꺼내기
};

template<typename T>
Bag<T>::Bag(){
	array = new T[capacity];
	top=-1;
}
template<typename T>
Bag<T>::Bag(int bagCapacity):capacity(bagCapacity){
	array = new T[capacity];
	top=-1;
}
template<typename T>
Bag<T>::~Bag() {
	delete[] array;
}
template<typename T>
inline int Bag<T>::Size() const {return top+1;}
template<typename T>
inline bool Bag<T>::isEmpty() const {return Size() == 0;}
template<typename T>
inline T& Bag<T>::Element() const {
	if(isEmpty()) throw "Bag is Empty";
	return array[rand()%Size()];
}
template<typename T>
void Bag<T>::Push(const T& x){
	if(capacity == top+1) ChangeSize1D(array,capacity,2*capacity); //꽉찼으면 2배로 늘리기
	capacity *=2;
	array[++top] = x;
}
template<typename T>
void Bag<T>::Pop(){
	int deletePos=rand()%Size();
	if(deletePos != top)
		copy(array+deletePos+1,array+top+1,array+deletePos); //앞으로 땡기기
	array[--top].~T();//하나 삭제되서
}

template<class T>
void ChangeSize1D(T*& array,const int oldSize, const int newSize){
	T* temp=new T[newSize];
	int number=min(oldSize,newSize);
	copy(array,array+number,temp);
	delete [] array;
	array = temp;
}

//Bizcard
class Bizcard {

char* name;
char* phone;

void FieldInitializer(char*& field, const char* input);

public:

Bizcard(const char* name, const char* phone); //초기화 생성자
~Bizcard();//소멸자
Bizcard(const Bizcard& copy); //복사 생성자

Bizcard& operator=(const Bizcard& copy); //대입 연산자

void showInfo();//이름과 전화번호 출력

};

/************************* main() **************************/

int main(void){
	/************ test ***************
	Bizcard myCard("hyebeen","010");
	Bizcard copyCard(myCard);
	Bizcard yourCard("so","5507");
	myCard.showInfo();
	copyCard.showInfo();
	yourCard.showInfo();

	//myCard.setName("hello");
	myCard.showInfo();
	copyCard.showInfo();
	yourCard.showInfo();

	copyCard=yourCard;
	myCard.showInfo();
	copyCard.showInfo();
	yourCard.showInfo();
	************************************/
	Bag <Bizcard>BizBag();
	Bizcard* A = new Bizcard("so","010");
	BizBag.Push(A);




	return 0;
}

/*********************** Bizcard 정의부 ************************/

void Bizcard::FieldInitializer(char*& field, const char* input){
	field=new char[strlen(input)+1];
	strcpy(field,input);
}

Bizcard::Bizcard(const char* name, const char* phone) //초기화 생성자
{
	FieldInitializer(this->name,name);
	FieldInitializer(this->phone,phone);
}
Bizcard::~Bizcard(){//소멸자
	delete [] name;
	delete [] phone;
	cout<<"소멸자 호출"<<endl;
}
Bizcard::Bizcard(const Bizcard& copy) //복사 생성자
{
	FieldInitializer(this->name,copy.name);
	FieldInitializer(this->phone,copy.phone);
}
Bizcard& Bizcard::operator=(const Bizcard& copy) //대입 연산자
{	
	delete [] name;
	FieldInitializer(this->name,copy.name);
	FieldInitializer(this->phone,copy.phone);
	return *this;
}
void Bizcard::showInfo(){
	cout<<"name : "<<name<<endl;
	cout<<"phone : "<<phone<<endl;
}

/************************* Bag 정의부 **************************/

