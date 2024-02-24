#include <iostream>
#include <fstream>

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
       void adminisration();
       void buyer();
       void add();
       void edit(); 
       void rem();
       void list();
       void recipt();

};

void shopping :: menu()
{ 
  m:
  int choice;
  string email;
  string password;

  cout <<"\t\t\t\t.............................\n";
  cout <<"\t\t\t\t                             \n";
  cout <<"\t\t\t\t    SUPERMARKET MAIN MENU    \n";
  cout <<"\t\t\t\t                             \n";
  cout <<"\t\t\t\t.............................\n";
  cout <<"\t\t\t\t                             \n";

  cout<<"\t\t\t\t|    1) Administrator        |\n";
  cout<<"\t\t\t\t                              \n";
  cout<<"\t\t\t\t|    2) Buyer                |\n";
  cout<<"\t\t\t\t                              \n";
  cout<<"\t\t\t\t|    2) Exit                 |\n";
  cout<<"\t\t\t\t                              \n";

  cout<<"\n\t\t\t     Please select             ";

  cin>>choice;

  switch(choice)
    {
      case 1:
      cout<<"\t\t\t Please Login  \n";
      cout<<"\t\t\t Enter Email   \n";
      cin>>email;
      cout<<"\t\t\t Password      \n";
      cin>>password;


     if((email=="abcd@email.com" &&   password =="abc123"))
        {
          adminisration();
        }  
      else
      {
        cout<<"Invalid mail/password";
      }
      break;
    

    case 2:
    {
      buyer();
    }

   case 3:
    {
      exit(0);
    }

    defualt :
    {
      cout<<"Please select from the given options";
    }
  }   
  goto m;
}

void shopping :: adminisration()
{ 
  m:
  int choice;
  cout <<"\n\n\n\t\t  Administratot Menu " ;
  
  cout <<"\n\n\t\t|....  1) Add the product......|\n";
  cout <<"\n\n\t\t|                              |\n";
   cout <<"\n\n\t\t|....  2) Modify the product......|\n";
  cout <<"\n\n\t\t|                              |\n";
   cout <<"\n\n\t\t|....  3) Delete the product......|\n";
  cout <<"\n\n\t\t|                              |\n";
   cout <<"\n\n\t\t|....  4) Back to main menu......|\n";
  cout <<"\n\n\t\t|                              |\n";

  cout<<"\n\n\t Please enter your choice ";
  cin>>choice;

  switch(choice)
    {
      case 1:
          add();
      break;

      case 2:
        edit();
      break;
      
      case 3:
      rem();
      break;
      
      case 4:
      menu();
      break;

      default:
        cout<<"Invalid choice!";
      
      
      
    }
  goto m;
}


void shopping:: buyer()
{
  m:
  int choice;
  cout<<"\t\t\t  Buyer \n";

  cout<<"\t\t\t............   \n";
  cout<<"                       ";
  cout<<"\t\t\t1) Buy Product \n";
  cout<<"                       ";
  cout<<"\t\t\t2) Go Back     \n";
  cout<<"\t\t\t Enter your choice \n";

  cin>>choice;
  switch(choice)
    {
      case 1:
        recipt();
      break;

      case 2:
      menu();
      break;

      default:

      cout<<"Invalid choice";
    }
  goto m;
}


void shopping:: add()
{
  m:
   fstream data;
  int c;
  int token =0;
  float p;
  float d;
  string n;

  cout<<"\n\n\t\t\t Add new product ";
  cout<<"\n\n\t Product code of the prodeuct ";
  cin>>pcode;
  cout<<"\n\n\t Name of the product ";
  cin>>pname;
   cout<<"\n\n\t Price of the product ";
  cin>>price;
  cout<<"\n\n\t Discount of the product ";
  cin>>dis;

  data.open("database.txt",ios::in);

  if(!data)
  {
    data.open("databse.txt",ios::app | ios::out);
    data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
    data.close();
  }
  else
  {
    // Intializing the index of file
    
    data>>c>>n>>p>>d;
    
    while(!data.eof())
          {
            if(c == pcode)
            {
              token++;
              
            }
            //for iteration purpose reading from the file
            data>>c>>n>>p>>d;
          }
    data.close();
  

  if(token ==1)
    goto m;
  else
      {
         data.open("databse.txt",ios::app | ios::out);
    data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
    data.close();
      }
}
  cout<<"\n\n\t\t Record inserted !"; 

}

void shopping:: edit()
{
   fstream data , data1;
  int pkey;
  int token =0;
  float p;
  float d;
  int c;
  string n;

  cout<<"\n\n\t\t\t Modify the record ";
  cout<<"\n\n\t Product code  ";
  cin>>pkey;

  data.open("database.txt",ios::in);
  if(!data)
  {
    cout<<"\n\n File dosent exist!";
  }

  else{
    // we will save the edited data in this file
    
    data1.open("database1.txt",ios::app| ios::out);
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
      {
        if(pkey==pcode)
        {
          cout<<"\n\t\t Product new code : ";
          cin>>c;
          cout<<"\n\t\t Name of the product : ";
          cin>>n;
          cout<<"\n\t\t Price : ";
          cin>>p;
          cout<<"\n\t\t Discount : ";
          cin>>d;

          data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";       
          cout<<" \n\n\t\t Record Edited ";
          token++;
        }
          
        else
        {
           data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        }
        data>>pcode>>pname>>price>>dis;
      }
     data.close();
     data1.close();

      remove("database.txt");
      rename("database1.txt","datbase.txt");

    if(token == 0)
    {
      cout<<"\n\n Record not found sorry!"; 
    }
  }
}

// Remove function

void shopping:: rem()
{
    fstream data, data1;
   int token =0;
  int pkey;

  cout<<"\n\n\t Delete Product ";
  cout<<" \n\n\t Product code : ";
  cin>>pkey;

  data.open("database.txt",ios::in);
  
  if(!data)
    
  {
    cout<<"File dosent exist";
  }
  else
  {
    data1.open("dtabse1.txt",ios::app|ios::out);
    data>>pcode>>pname>>price>>dis;

     while(!data.eof())
      {
        if(pkey==pcode)
        {
          cout<<"\n\n\t Product deleted succesfully ";
          token++;
        }
          // HERE THE PKEY ENTERD BY THE ADMINTRATOR WILL CHECK FOR FIRST 
          //PRODUCT CODE IF IT MATCHES THE IF BLOCK EXECUTE 
        else
        {
            data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";  
        }
         data>>pcode>>pname>>price>>dis;
      }
    data.close();
    data1.close();
    remove("databse.txt");
    rename("database1.txt","database.txt");

    if(token == 0)
    {
      cout<<"\n\n  Record not found sorry!"; 
    }
  }
}

// LIST FUNCTION

void shopping:: list()
{
  fstream data;
  data.open("database.txt",ios::in);
  cout<<"\n\n|............................................\n";
  cout<<"PronNo\t\tName\t\tPrice \n";
  cout<<"\n\n|............................................\n";
  data>>pcode>>pname>>price>>dis;
  while(!data.eof())
    {
      cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
       data>>pcode>>pname>>price>>dis;
    }
  data.close();
}

// RECIPT FUNCTION

void shopping::recipt()
{
  // HERE WE WILL USE ARRAY WE HAVE TO STORE MULTIPE OBJECT AND VARIAABLE
   
  fstream data;
  int arrc[100];
  int arrq[100];
  char choice;
  int c=0;
  float amount =0;
  float dis= 0;
  float total =0;

  cout<<"\n\n\t\t\t\t  Recipt";
  data.open("databse.txt",ios::in);
  if(!data)
  {
    cout<<"\n\n  Empty Database";
    
  }
   else{
     data.close();
     list();

     cout<<"\n\n|............................................\n";
     cout<<"\n\n|                                            \n";
     cout<<"\n\n|       Please Place The Order               \n";
     cout<<"\n\n|                                            \n";
     cout<<"\n\n|............................................\n";
        
        do{
          m:
          cout<<"\n\n Enter product code :";
            cin>>arrc[c];
          cout<<"\n\n Enter the Quantity :";
            cin>>arrq[c];

          for(int i=0;i<c;i++)
            {
              if(arrc[c]==arrc[i])
              {
                cout<<"\n\n Duplicate product code enterd please try again";
                goto m;
              }
            }
          c++;
          cout<<"\n\n Do you want to buy another product? then press y esle no";
          cin>>choice;
          
        }   while(choice == 'y');

           cout<<"\n\n\t\t\t............. RECIPT................\n";
     cout<<"\nProduct No\t Product Name \t Product quantity \t price \t amount \t amount with discount ";

     for(int i=0;i<c;i++)
       {
         data.open("database.txt",ios::in);
         data>>pcode>>pname>>price>>dis;
         while(!data.eof())
           {
             if(pcode == arrc[i])
             {
               amount = price * arrq[i];
               dis = amount +(amount*dis/100);
               total = total +dis;
               cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
               
             }
             data>>pcode>>pname>>price>>dis;
           }
       }
     data.close();
     }
  cout<<"\n\n................................................";
  cout<<"\n  Total Amount  :"<< total;
   
}


int main()
{
  shopping s;
  s.menu();
}