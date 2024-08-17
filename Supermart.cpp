#include<iostream>
#include<fstream>
using namespace std;

class shopping
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		
	public:
		void menu();
		void administrator();
		void buyer();
		void add();
		void edit();
		void remove();
		void list();
		void receipt();
};
void shopping::menu()
{
	m:
	int choice;
	string email;
	string password;
	
	cout<<"\___________________________________________\n";
	cout<<"\                                           \n";
	cout<<"\         =====Super Market=====    \n";
	cout<<"\___________________________________________\n";
	cout<<"\t\n";
	cout<<"\ |    1) Administrator                     |\n";
	cout<<"\ |                                         |\n";
	cout<<"\ |    2) Buyer                             |\n";
	cout<<"\ |                                         |\n";
	cout<<"\ |    3) Exit                              |\n";
	cout<<"\ |                                         |\n";
	cout<<"\  =====Select the choice=====              \n";
	cin>>choice;	
	switch(choice)
	{
		case 1:
			cout<<" =====please login below===== \n";
			cout<<"\n" ;
			cout<<" Enter your Email:" <<endl;
			cin>>email;
			cout<<"\n" ;
			cout<<" Enter your password:"<<endl;
			cin>>password;
			cout<<"\n" ;
			cout<<"\n" ;
			cout<<"\n" ;
			if(email=="123" && password=="123")
			{
				administrator();
			}
			else
			{
				cout<<"***Invalid  creditionals by user***"<<endl;
				cout<<"Please try again" ;
				cout<<"\n" ;
				cout<<"\n" ;
				break;
			}
			
		case 2:
			{
				buyer();
			}
		case 3:
			{
				exit(0);
			}
		default :
			{
				cout<<"\n" ;
				cout<<"*****please select from the given option*****"<<endl;
			}
	}
	goto m;
}


void shopping::administrator(){
	m:
	int ch;
	cout<<"\___________________________________________\n";
	cout<<"\                                           \n";
	cout<<"\       =====Administrator Menu=====        \n";
	cout<<"\___________________________________________\n";
	cout<<"\n|     1)Add new products                |\n";
	cout<<"\n|                                       |\n";
	cout<<"\n|     2)Modify the product              |\n";
	cout<<"\n|                                       |\n";
	cout<<"\n|     3)Delete the product              |\n";
	cout<<"\n|                                       |\n";
	cout<<"\n|     4)Back to main menu               |\n";
	
	cout<<"\n =====Enter your choice===== "<<endl;
	cin>>ch;
	
	switch(ch){
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			remove();
			break;
		case 4:
			menu();
			break;
		default :
			cout<<"\n";
			cout<<"\n";
			cout<<"     ****Invalid choice****";
			cout<<"\n";
	}
	goto m;
	
}

void shopping::buyer()
{
	m:
	int choice;
	cout<<"\n\n\n\n  Buyer Menu"<<endl;
	cout<<"\n|_______________________________________|\n";
	cout<<"\n|                                       |\n";
	cout<<"\n|                                       |\n";
	cout<<"\n|     1)Buy product                     |";
	cout<<"\n|                                       |\n";
	cout<<"\n|                                       |\n";
	cout<<"\n|     2) Back to main menu              |\n";
	
	cout<<"\n Enter your choice "<<endl;
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
		case 2:
			menu();
		default:
			cout<<"Invalid Choice \n";
	}
	goto m;		
}

void shopping::add() {
    fstream data;
    int c;
    float p;
    float d;
    string n;
    bool productExists = false;
    
    cout << "\n___________________________________________\n";
    cout << "\n       Add new product                     \n";
    cout << "___________________________________________\n";

    cout << "Enter product code: ";
    cin >> pcode;
    cout << "Enter Price of the product: ";
    cin >> price;
    cout << "Enter Discount on product: ";
    cin >> dis;
    cout << "Enter Product name: ";
    cin.ignore();
    getline(cin, pname); 
    data.open("database.txt", ios::in);
    if (data.is_open()) {
        while (data >> c >> n >> p >> d) {
            if (c == pcode) {
                productExists = true;
                break;
            }
        }
        data.close();
    }
    if (!productExists) {
        data.open("database.txt", ios::app | ios::out);
        if (data.is_open()) {
            data << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
            cout << "Successfully inserted" << endl;
        } else {
            cout << "Unable to open file for writing" << endl;
        }
    } else {
        cout << "Product code already exists. Please use a different code." << endl;
    }
}

void shopping::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"Modify the product"<<endl;
	cout<<"product code"<<endl;
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"File does not exist"<<endl;
	}
	else{
		data1.open("database.txt",ios::app|ios::out);
		
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"product new code"<<endl;
				cin>>c;
				cout<<"Enter name of the product"<<endl;
				cin>>n;
				cout<<"Enter price"<<endl;
				cin>>p;
				cout<<"Enter discount"<<endl;
				cin>>d;
				
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				
				cout<<"updated successfully the record in database"<<endl;
				token++;
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		
		// remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"Record does not found"<<endl;
		}
	}
	
}
void shopping::remove()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"Delete product"<<endl;
	
	cout<<"Enter product code"<<endl;
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"File does not "<<endl;
	}
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t product deleted successfully"<<endl;
				token++;
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		// remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0)
		{
			cout<<"\n\n Record not found";
		}
	}
}

void shopping::list()
{
	fstream data;
	data.open("database.txt",ios::in);
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<""<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}	
	data.close();
}

void shopping::receipt() {
    m:
    fstream data;
    
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float disc = 0;
    float total = 0;

    cout << "Receipt Note Display" << endl;
    data.open("database.txt", ios::in);

    if (!data) {
        cout << "\n\n Empty Database" << endl;
    } else {
        data.close(); // Close the file immediately as it is only checked for existence
        list(); // Display the list of products

        cout << "Please order" << endl;
        do {
            cout << "Enter the product code: " << endl;
            cin >> arrc[c];
            cout << "Enter product quantity" << endl;
            cin >> arrq[c];

            // Check for duplicate product codes
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "Duplicate product code. Please try again" << endl;
                    goto m; // Go to the start of the function
                }
            }
            c++;

            cout << "Do you want to buy another product (Y/N)" << endl;
            cin >> choice;

            // Convert input to lowercase to handle both 'Y' and 'y'
            while (choice != 'Y' && choice != 'N') {
                cout << "Invalid choice. Please enter Y or N: ";
                cin >> choice;
            }
        } while (choice == 'Y' || choice == 'y'); // Correct loop condition for repeating

        // Process the purchased products
        for (int i = 0; i < c; i++) {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    disc = amount - (amount * dis / 100);
                    total += disc;
                    cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << disc;
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }
    }
    cout << "Total amount: " << total << endl; // Added 'endl' for newline
}
int main()
{
	shopping s;
	s.menu();
}
