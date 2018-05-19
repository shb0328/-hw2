#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;




class LOPChain {

				class LocationOfProduct {
					public:
						string product;
						int location;
						LocationOfProduct * next;

						LocationOfProduct(string product, int row, int column){
							this->product = product;

							if(row%2 == 0) 
							location = row*5 + (column+1);
							else
							location = row*5 + (5-column);

							next = 0;
						}
						

						void show(){ //test function
							cout<<product<<" : "<<location<<endl;
						}
				};


	LocationOfProduct * first;

	void preInsert(LocationOfProduct* newNode, LocationOfProduct* node){
		if(node){
			newNode->next = node->next;
			node->next = newNode;
		}
		else
			first = newNode;
	}



public:
	LOPChain(){
		first =0;
	}

	void sortProduct(string item,int row,int column) {
		cout<<item<<endl;
		if(first){
			for(LocationOfProduct* p = first; p!=0;p=p->next){
				cout<<"check1"<<endl;
				if(0 == item.compare(p->product))
				{
					cout<<"check^^;"<<endl;
					break;
				}
				else
				{
					cout<<"check**"<<endl;
					LocationOfProduct* newNode = new LocationOfProduct(item,row,column);
					LocationOfProduct* tmp = first;
					for(LocationOfProduct* q = first; tmp!=0;q=q->next)
					{
						cout<<"check!!!!!!"<<endl;
						if(tmp->location < newNode->location){
							if(0 == q->next){
								tmp->next = newNode;
								break;
							}
						}	
						else
						{
							cout<<"check@@@@@"<<endl;
							preInsert(newNode,tmp);
						}
					tmp = q;
					}
				}
			}		
		}	
		else
		{
			cout<<"check5"<<endl;
			LocationOfProduct* newNode = new LocationOfProduct(item,row,column);
			preInsert(newNode,first);
		}	
	}
	void show(){
		for(LocationOfProduct* p = first;p!=0;p=p->next)
			cout<<p->product<<" ";
		cout<<endl;
	}
};


int main(void) {
	char const * productList[6][5] = {  "apple", "banana", "grape", "pear", "peach",
										"shampoo", "conditioner", "soap", "cleanser", "slipper",
										"earphone", "charger", "mouse", "minifan", "speaker",
										"chocolate", "chips", "gum", "jelly", "cracker",
										"chopsticks", "spoon", "fork", "cup", "knife",
										"beer", "soju", "wine", "cocktail", "liquor" };

	LOPChain* product = new LOPChain;
										
	int num;
	cout << "장 볼 물건의 개수를 입력하세요 : ";
	cin >> num;

	string* list = new string[num];
	
	for (int i = 0; i < num ; i++) {
		cout << i + 1 << "번째 물건을 입력하세요 : ";
		cin >> list[i];
	}

	int cnt[6] = {0};

	for(int i=0;i<6;i++){
		for(int j =0; j<5;j++){
			for(int k =0;k<num;k++){													
				if( 0 == list[k].compare(productList[i][j]) ){
					++cnt[i]; 
					product->sortProduct(list[k],i,j);
				}
			}
		}
	}

	for(int i =0;i<6;i++)
		cout<<cnt[i]<<" ";
	cout<<endl;
	
	cout<<"장 볼 순서 : ";
	product->show();

	return 0;
}

