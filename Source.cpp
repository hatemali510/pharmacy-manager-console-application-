#include<iostream>
#include<string>
#include <vector>
#include <fstream>
using namespace std;

class index
{
protected:
	string name;
	string id;
	string price;
	string numbers;
	string salary;
public:
	index();
	~index();
	void set_name(string temp);
	void set_id(string temp);
	void set_price(string temp);
	string get_name();
	string get_id();
	string get_price();
};


class depart
{
public:
	depart();
	~depart();

};

depart::depart()
{
}

depart::~depart()
{
}

class  employee :public index
{

public:
	pharm pharmacy;
	void searchs(string id);
	void add(string name);
	void del(string item);
	void updata(string id,string kk);
	void list_show();
};

class inventory:public index
{

public:
	void list_show();
	void add(string name);
	void searchs(string id);
	void del(string item);
	void updata(string id,string kk);
};

class order
{
public:
	order();
	~order();

private:

};

order::order()
{
}

order::~order()
{
}

class pharm
{
public:
	inventory inv;
	depart dep;
	order ord;
	void menu();
};


int main(){
	employee emp;
	char choice,choose;
	string all;
	do
	{
      cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n|A) To List Data               |\n";
	  cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n|B) To Search in Data          |\n";
	  cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n|C) To Add                     |\n";
	  cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n|D) To Update                  |\n";
	  cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n|E) To delete                  |\n";
	  cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n|0) To Exit From the inventory |\n";
	  cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n\n\tEnter your choice : ";
	  cin>>choice;
	  cout<<"\n";
	  if(choice=='A'||choice=='a'){
		  emp.pharmacy.inv.list_show();//ana kda ba3mel two relation assoiation(emp w pharmacy) w  aggre (pharmacy w inv)
	  }
	  if(choice=='B'||choice=='b'){
		  cout<<"The ID of product : ";
		  cin>>all;
		  emp.pharmacy.inv.searchs(all);
	  }
	  if (choice=='C'||choice=='c')
	  {
		  cout<<"Enter The product you want to add it : ";
		  cin>>all;
		  emp.pharmacy.inv.add(all);
	  }
	  if(choice=='D'||choice=='d'){
	      cout<<"Enter The ID of product to Updata it : ";
		  cin>>all;
		  cout<<"Enter the New product : ";
		  string up,dl,ds,mn;
		  cin>>up;
		  cin>>dl;
		  cin>>ds;
		  cin>>mn;
		  up+="\t";
		  for (int i = 0; i < dl.size(); i++)
		  {
			  up+=dl[i];
		  }
		  up+="\t\t\t";
		  for (int i = 0; i < ds.size(); i++)
		  {
			  up+=ds[i];
		  }
		  up+="\t";
		  for (int i = 0; i < mn.size(); i++)
		  {
			  up+=mn[i];
		  }
		  emp.pharmacy.inv.updata(all,up);
	  }
	  if(choice=='e'||choice=='E')
	  {
         	  cout<<"Enter the ID of product to delete it : ";
			  cin>>all;
			  emp.pharmacy.inv.del(all);
	  }
	  if(choice=='0'){
	       break;
	  }

	} while (choice!='0');


	return 0;
}



void employee::del(string item){
vector<string> file;
string temp;

ifstream infile("employee.txt");

while( !infile.eof() )
{
	getline(infile, temp);
	file.push_back(temp);
}
// done reading file
infile.close();

string line;
int offset;


for(int i = 0; i < (int)file.size(); ++i)
{
           if(file[i].substr(0, item.length()) == item)
	       {

                file.erase(file.begin() + i);
		        cout << "\nOrder erased!\n"<< endl;
		        i = 0;
		        break;
           }
		 // Reset search
}

//write new order list back out
ofstream out("employee.txt", ios::out | ios::trunc);

for(vector<string>::const_iterator i = file.begin(); i != file.end(); ++i)
{
	out << *i << endl;
}
out.close();
}


void employee::list_show()
{
      string line;
  ifstream myfile ("employee.txt" );
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << endl;
    }
    myfile.close();
  }

  else cerr << "Unable to open file";
}


void employee::add(string id)
{
	   string name,price;
       fstream fout;
	   string ida="employee.txt",number;
	   fout.open( ida ,  ios::out|ios::app);
	   cin>>name;
	   cin>>price;
	   cin>>number;
	   fout<<id<<"\t"<<name<<"\t\t\t"<<number<<"\t     "<<price<<"\n";

}


void employee::searchs(string id)
{
   int offset;
   string line;

   ifstream hassan;

   hassan.open("employee.txt");

   if(hassan.is_open())
   {
       while (!hassan.eof())
       {
           getline(hassan,line);
		   if ((offset = line.find(id,0)) != string::npos)
           {
			   cout << "The product is founded !" << endl ;
			   break;
           }
       }
       hassan.close();

   }
    else
		cerr << "could not open file" << endl ;

}



void employee::updata(string id,string kk){
   vector<string> file;
string temp;

ifstream infile("employee.txt");

while( !infile.eof() )
{
	getline(infile, temp);
	file.push_back(temp);
}
infile.close();
for(int i = 0; i < (int)file.size(); ++i)
{
	if(file[i].substr(0, id.length()) == id)
	{

		file[i]=kk;
		cout << "Order updata!"<< endl;
		i = 0;
		break;// Reset search
	}
}
//write new order list back out
ofstream out("employee.txt", ios::out | ios::trunc);

for(vector<string>::const_iterator i = file.begin(); i != file.end(); ++i)
{
	out << *i << endl;
}
out.close();
}

index::index()
{
	name="";
	id="";
	price="";
}

index::~index()
{
	name="";
	id="";
	price="";
}
void index::set_name(string temp)
{
	name=temp;
}
void index::set_id(string temp)
{
	id=temp;
}
void index::set_price(string temp)
{
	price=temp;
}
string index::get_name()
{
	return name;
}
string index::get_id()
{
	return id;
}
string index::get_price()
{
	return price;
}

bool sea=0,ad=0,de=0;


void inventory::del(string item){
vector<string> file;
string temp;

ifstream infile("pharmacy.txt");

while( !infile.eof() )
{
	getline(infile, temp);
	file.push_back(temp);
}
// done reading file
infile.close();

string line;
int offset;


for(int i = 0; i < (int)file.size(); ++i)
{
           if(file[i].substr(0, item.length()) == item)
	       {

                file.erase(file.begin() + i);
		        cout << "\nOrder erased!\n"<< endl;
		        i = 0;
		        break;
           }
		 // Reset search
}

//write new order list back out
ofstream out("pharmacy.txt", ios::out | ios::trunc);

for(vector<string>::const_iterator i = file.begin(); i != file.end(); ++i)
{
	out << *i << endl;
}
out.close();
}






void inventory::list_show()
{
      string line;
  ifstream myfile ("pharmacy.txt" );
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << endl;
    }
    myfile.close();
  }

  else cerr << "Unable to open file";
}




void inventory::add(string id)
{
       fstream fout;
	   string ida="pharmacy.txt",number;
	   fout.open( ida ,  ios::out|ios::app);
	   cin>>name;
	   cin>>price;
	   cin>>number;
	   fout<<id<<"\t"<<name<<"\t\t\t"<<number<<"\t     "<<price<<"\n";

}




void inventory::searchs(string id)
{
   int offset;
   string line;

   ifstream hassan;

   hassan.open("pharmacy.txt");

   if(hassan.is_open())
   {
       while (!hassan.eof())
       {
           getline(hassan,line);
		   if ((offset = line.find(id,0)) != string::npos)
           {
			   cout << "The product is founded !" << endl ;
			   break;
           }
       }
       hassan.close();

   }
    else
		cerr << "could not open file" << endl ;

}




void inventory::updata(string id,string kk){
   vector<string> file;
string temp;

ifstream infile("pharmacy.txt");

while( !infile.eof() )
{
	getline(infile, temp);
	file.push_back(temp);
}
infile.close();
for(int i = 0; i < (int)file.size(); ++i)
{
	if(file[i].substr(0, id.length()) == id)
	{

		file[i]=kk;
		cout << "Order updata!"<< endl;
		i = 0;
		break;// Reset search
	}
}
//write new order list back out
ofstream out("pharmacy.txt", ios::out | ios::trunc);

for(vector<string>::const_iterator i = file.begin(); i != file.end(); ++i)
{
	out << *i << endl;
}
out.close();
}

