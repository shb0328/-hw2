#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;




class SortedProductList {

				class LocationOfProduct {
					public:
						string product;
						int row;
						int location;
						LocationOfProduct * next;

						LocationOfProduct(string product, int row, int column){
							this->product = product;
							this->row = row;
							next = 0;

							if(row%2 == 0) 
							location = row*5 + (column+1);
							else
							location = row*5 + (5-column);
						}
						

						void show(){ //test function
							cout<<"*product : "<<product<<endl;
							cout<<"*line : "<<row+1<<endl;
							cout<<"*location : "<<location<<endl<<endl;
						}
				};


	LocationOfProduct * first;

	void Insert(LocationOfProduct* newNode){
		if(first){
			for(LocationOfProduct* p=first;p!=0;p=p->next){
			if ( p->next == 0 )
				{
					p->next = newNode;
					break;
				}
			}
		}
		else
			first = newNode;
	}



public:
	SortedProductList(){
		first =0;
	}

	void addSortedProductList(string item,int row,int column) {

			for(LocationOfProduct* p=first;p!=0;p=p->next)
			{
				if(0 == item.compare(p->product))
					return;
			}
			LocationOfProduct* newNode = new LocationOfProduct(item,row,column);
			Insert(newNode);
		
	}

	void show(){
		for(LocationOfProduct* p = first;p!=0;p=p->next)
			p->show();
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

	SortedProductList* sortedProductList = new SortedProductList;
										
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
		if(i%2 == 0)
		{
				for(int j =0; j<=4;j++){
					for(int k =0;k<num;k++){													
						if( 0 == list[k].compare(productList[i][j]) ){
							++cnt[i]; 
							sortedProductList->addSortedProductList(list[k],i,j);
						}
					}
				
			}
		}
		else
		{
			for(int j =4; j>=0;j--){
				for(int k =0;k<num;k++){													
					if( 0 == list[k].compare(productList[i][j]) ){
						++cnt[i]; 
						sortedProductList->addSortedProductList(list[k],i,j);
					}
				}
		}
}
	}

	cout<<endl<<"<line 당 사야할 물건 개수>"<<endl;
	for(int i =0;i<6;i++)
		cout<<" Line "<<i+1<<": "<<cnt[i]<<" 개"<<endl;
	cout<<endl;
	
	cout<<"<장 볼 순서>"<<endl;
	sortedProductList->show();

	return 0;
}

