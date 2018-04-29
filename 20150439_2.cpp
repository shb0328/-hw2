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
	cout<<"temp 생성 !"<<endl;//test 용 코드 삭제 요망!!!!!!!!!!!!!!!!
	int number=min(oldSize,newSize);
	temp = copy(array,array+number,temp);
	cout<<"copy 성공 ! "<<endl;//test 용 코드 삭제 요망!!!!!!!!!!!!!!!!
	temp[0].showInfo();//test 용 코드 삭제 요망!!!!!!!!!!!!!!!!
	//error 복사가 제대로 안됬나?
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
		cout<<"Bag 생성"<<endl; //test 용 코드 삭제 요망!!!!!!!!!!!!!!!!
	}
	~Bag() {delete[] array;}//소멸자
	
	int Size() const {return top+1;}//bag안에 요소 개수 리턴
	
	bool isEmpty() const {return Size() == 0;}//bag 이 비었으면 true
	
	T& Element() const //bag안의 요소를 리턴
	{
		if(isEmpty()) throw "Bag is Empty";
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
		int deletePos=rand()%Size();
		if(deletePos != top)
			array=copy(array+deletePos+1,array+top+1,array+deletePos); //앞으로 땡기기
		array[--top].~T();//하나 삭제되서
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
Bizcard() {cout<<"초기화 생성자 사용!"<<endl;} //초기화 생성자
Bizcard(const char* name, const char* phone) //초기화 생성자 오버로딩
{
	this->name=new char[strlen(name)+1];
	strcpy(this->name,name);
	this->phone=new char[strlen(phone)+1];
	strcpy(this->phone,phone);
	cout<<"오버로딩된 초기화 생성자 사용!"<<endl;
}
~Bizcard()//소멸자
{
	delete [] name;
	delete [] phone;
	cout<<"소멸자 호출"<<endl; //test 용 코드 삭제 요망!!!!!!!!!!!!!!!!
}
Bizcard(const Bizcard& copy) //복사 생성자
{
	name=new char[strlen(copy.name)+1];
	strcpy(name,copy.name);
	phone=new char[strlen(copy.phone)+1];
	strcpy(phone,copy.phone);
	cout<<"복사 생성자 사용"<<endl;//test 용 코드 삭제 요망!!!!!!!!!!!!!!!!
}

Bizcard& operator=(const Bizcard& copy) //대입 연산자
{
	delete[] name;
	delete[] phone;
	setPointerField(this->name,copy.name);
	cout<<name<<endl;//test 용 코드 삭제 요망!!!!!!!!!!!!!!!!
	setPointerField(this->phone,copy.phone);
	cout<<"=사용"<<endl;//test 용 코드 삭제 요망!!!!!!!!!!!!!!!!
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
	// Bizcard So("so","010");
	// Bizcard Hye("hye","5507");
	// Bizcard Bin("bin","4148");
	// BizBag.Push(So);
	// BizBag.Push(Hye);
	// BizBag.Push(Bin);
	BizBag.Push(Bizcard("so","010"));
	BizBag.Push(Bizcard("hye","5507"));
	BizBag.Push(Bizcard("bin","4148"));
	cout<<"===== 객체 3개 추가 후 결과 확인 ====="<<endl;
	cout<<"Size() : "<<BizBag.Size()<<endl;
	cout<<"isEmpty() : "<<BizBag.isEmpty()<<endl;
	cout<<"Element() : "<<endl; BizBag.Element().showInfo();
	
	// Bizcard Kim("kim","02");
	// Bizcard Ik("ik","820");
	// Bizcard Su("su","0926");
	// Bizcard Plorer("plorer","1004");
	// BizBag.Push(Kim);
	// BizBag.Push(Ik);
	// BizBag.Push(Su);
	// BizBag.Push(Plorer);
	BizBag.Push(Bizcard("kim","02"));
	BizBag.Push(Bizcard("ik","820"));
	BizBag.Push(Bizcard("su","0926"));
	BizBag.Push(Bizcard("plorer","1004"));
	cout<<"===== 객체 4개 추가 후 결과 확인 ====="<<endl;
	cout<<"Size() : "<<BizBag.Size()<<endl;
	cout<<"isEmpty() : "<<BizBag.isEmpty()<<endl;
	cout<<"Element() : "<<endl; BizBag.Element().showInfo();
	
	BizBag.Pop();
	BizBag.Pop();
	cout<<"===== 객체 2개 삭제 후 결과 확인 ====="<<endl;
	cout<<"Size() : "<<BizBag.Size()<<endl;
	cout<<"isEmpty() : "<<BizBag.isEmpty()<<endl;
	cout<<"Element() : "<<endl; BizBag.Element().showInfo();


	return 0;
}


