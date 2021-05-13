#include<iostream>
#include<cstring>
#include<cmath>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include <sstream> 
#include<fstream>


using namespace std;

void Management();
int UserFunction();
int displaymainmenu();
void inputchoice(int &choice, int lower, int upper); 
int ChoiceValidate(int choice);
void InputData(string &username, string&password);
int ManagementFunction();

int DisplayUserMainMenu();
int Validation(string &username, string &password);
void DisplayGenre();


class item{

	
	string name;
	string type;
	string origin;
	string artistname;
	string price;
	string pieces;
	string status;
	
	public:
		
		item()
		{} // default constructor
		
		item(string i_name, string i_type, string p_origin, string AN, string p, string pieces, string status) // constructor
		{
			name = i_name;
			type = i_type;
			origin = p_origin;
			artistname = AN;
			price = p;
			pieces = pieces;
		}
		
		void SetItem() 
		{
			bool correcttype = false;
			
			cout << "Enter Item Name: ";
			getline(cin, name);
			
			do
			{
			cout << "Enter Type (Nature Art - Object Art - Abstract Art): ";
			getline(cin, type);
			correcttype = (  (type == "Nature Art")  || (type == "Object Art")  )  || (type == "Abstract Art") ;
			
			if (correcttype == false)
			    {
				cout << endl << "Incorrect Type Entered - Please Try Again!" << endl << endl;
			    }			 
		    }
			while( correcttype != true );
			
			cout << "Enter Place of Origin: ";
			getline(cin, origin);
						
			cout << "Enter Artist Name: ";
			getline(cin, artistname);
			
			cout << "Enter Price: ";
			cin >> price;
			
			cout << "Enter Number of Pieces: ";
			cin >> pieces;				
		}
		
		void DisplayOutput()
		{
			system("cls");
			cout << "Item Name: " << name << endl;
			cout << "Item Type: " << type << endl;
			cout << "Country of Origin: " << origin << endl ;
			cout << "Artist Name: " << artistname << endl;
			cout << "Number of Pieces: " << pieces << endl;
			cout << "Price: " << price << endl;
			cout << "Status: " << status << endl;
		}
		
		string getstatus()
		{
			return status;
		}
	
	friend class management;
	friend class user;
};		  


class parent
{
	protected:
		
	string username, password;
	
	public:
		
	void login ()
    {
	int verify = 1;
	string u,p;
		
	while(verify)
	{
	cout << "Enter UserName: ";	
	getline(cin, u);
	
	cout << "Enter Password: ";
	getline(cin, p);
	
		
	
	verify = Validation(u, p);
    }
	
	username = u;
	password = p;
	
	system("cls");
    }
	
};

class management: public parent
{
	public:
		
	bool verifymanagementlogin()
    {
	bool isfound = false;
	management obj;
	
    ifstream managementfile; 
      
    managementfile.open("management.txt", ios::in); 
      
    while ( !managementfile.eof() ) 
	{ 
	
	    getline(managementfile, obj.username);
	    getline(managementfile, obj.password);
        
        if (  (obj.username == username) && (obj.password == password)  )
		{ 
            isfound = true;
        } 
    } 
    managementfile.close();
        
    if(isfound == false)
    {
    system("cls");
    cout << endl << "Incorrect Credentials Entered - Please Try Again!" << endl;
    }
    
    return isfound;	
    }	
    
    void AddItem()
	{
		item I;
		
		system("cls");
		
		cin.ignore();
		I.SetItem();
		
		
		ofstream galleryfile; 
      
         galleryfile.open("gallery.txt", ios::app); 
         
         galleryfile << "\n";  
         galleryfile << I.name;
         galleryfile << "\n";
         galleryfile << I.type;
         galleryfile << "\n";
         galleryfile << I.origin;
         galleryfile << "\n";
         galleryfile << I.artistname;
         galleryfile << "\n";
         galleryfile << I.price;
         galleryfile << "\n";
         galleryfile << I.pieces;
         galleryfile << "\n";
         galleryfile << "Available"; // Default Status
    
    galleryfile.close();
    
		
		system("cls");
		cout << "Data successfully added into files." << endl << endl;
	}
	
	void EditItem()
	{
		int input=-1;
		system("cls");
		
		item E,I ;
		bool found = false;
		
		cout << "Enter Name of Item to Edit: ";
		cin.ignore();
		getline(cin, E.name);
			
		cout << "1. Edit Item Type\n";
		cout << "2. Edit Place of Origin.\n";
		cout << "3. Edit Artist Name\n";
		cout << "4. Edit Price\n";
		cout << "5. Edit Number of Pieces Available\n";
		cout << "6. All Properties\n \n";
		
		inputchoice(input, 1 , 6);
		cin.ignore();
				
		ifstream gallery; 
		ofstream temp;
      
    gallery.open("gallery.txt", ios::in); 
    temp.open("temp.txt", ios::app); 
    
    int k = 0;
      
    while ( !gallery.eof() ) 
    
	{   	    
        getline(gallery, I.name);
	    getline(gallery, I.type);
	    getline(gallery, I.origin);
	    getline(gallery, I.artistname);
	    getline(gallery, I.price);
	    getline(gallery, I.pieces);
	    getline(gallery, I.status);
	    	    
	    if (  !(I.name == E.name) )
	    {
		if (k == 1)
	    temp << "\n";
			
	    else if( k == 0)	
	    k = 1;  
	    	
	     temp << I.name;
         temp << "\n";
         temp << I.type;
         temp << "\n";
         temp << I.origin;
         temp << "\n";
         temp << I.artistname;
         temp << "\n";
         temp << I.price;
         temp << "\n";
         temp << I.pieces;
         temp << "\n";
         temp << I.status;
	    }	
		else if (  (I.name == E.name) )	
		{
		found = true;	
			
		E.name = I.name;	
		E.type = I.type;
		E.origin = I.origin;
		E.artistname = I.artistname;
		E.price = I.price;
		E.pieces = I.pieces;
		E.status = I.status;
			
		if (k == 1)
	    temp << "\n";
			
	    else if( k == 0)	
	    k = 1;
	    
		switch(input)
		{
						
			case 1:
				{
				bool correcttype = false;				
			    do
			    {
			     cout << "Enter Type (Nature Art - Object Art - Abstract Art): ";
			     getline(cin, E.type);
			     correcttype = (  (E.type == "Nature Art")  || (E.type == "Object Art")  )  || (E.type == "Abstract Art") ;
			
			      if (correcttype == false)
			      {
				   cout << endl << "Incorrect Type Entered - Please Try Again!" << endl << endl;
			      }			 
		        }
		        while( correcttype != true );
				break;
			    }
			    
			case 2:
				{			
				cout << "Enter new Place of Origin: "; 
				getline(cin, E.origin);
				break;
			    }
			    
				
			case 3:
				{
				cout << "Enter new Artist Name: "; 
				getline(cin, E.artistname);
				break;
			    }
			    
						
			case 4:
				{
				cout << "Enter new Price: "; 
				getline(cin, E.price);
				break;
			    }
			    
			
			case 5:
				{
				cout << "Enter Pieces Available: "; 
				getline(cin, E.pieces);
				break;
			    }
			    
			
			case 6:
				{
				E.SetItem();
			    }
			    				
		};
		
		if(E.pieces != "0")
		E.status = "Available";
		else if(E.pieces == "0")
		E.status = "Sold";
						
		 temp << E.name;
         temp << "\n";
         temp << E.type;
         temp << "\n";
         temp << E.origin;
         temp << "\n";
         temp << E.artistname;
         temp << "\n";
         temp << E.price;
         temp << "\n";
         temp << E.pieces;
         temp << "\n";
         temp << E.status;
		     	
	    }
		
	} 
    gallery.close();
    temp.close();
    
    remove("gallery.txt");
    rename("temp.txt", "gallery.txt");	
	
	system("cls");
	
	if (found == true)
	cout << "Item Successfully Edited" << endl << endl;
	
	else if(found == false)
	cout << "Item Not Found" << endl << endl;
	
						
	}		
	
	
	void DeleteItem()
	{
		bool found = false;
		int k = 0;
		
		item I;
		
		ifstream gallery; 
		ofstream temp;
      
    gallery.open("gallery.txt", ios::in); 
    temp.open("temp.txt", ios::app); 
    
      
    while ( !gallery.eof() ) 
	{    
        getline(gallery, I.name);
	    getline(gallery, I.type);
	    getline(gallery, I.origin);
	    getline(gallery, I.artistname);
	    getline(gallery, I.price);
	    getline(gallery, I.pieces);
	    getline(gallery, I.status);
	    	    
	    if (  !(I.pieces == "0") )
	    {
	    if (k == 1)
	    temp << "\n";
			
	    else if( k == 0)	
	    k = 1;
	    
	    
	    	
	     temp << I.name;
         temp << "\n";
         temp << I.type;
         temp << "\n";
         temp << I.origin;
         temp << "\n";
         temp << I.artistname;
         temp << "\n";
         temp << I.price;
         temp << "\n";
         temp << I.pieces;
         temp << "\n";
         temp << I.status;	
	    }	
		else if (  (I.pieces == "0") )	
		{
		 found = true;	     	
	    }
		
	} 
    gallery.close();
    temp.close();
    
    remove("gallery.txt");
    rename("temp.txt", "gallery.txt");	
	
	system("cls");
	
	if (found == true)
	cout << "Items Successfully Deleted" << endl << endl;
	else if (found == false)
	cout << "No Item found with 0 pieces" << endl << endl;
						
	}	
	
};

class user: public parent
{
	public:
		
	bool verifyuserlogin()
{
	bool isfound = false;
	
	user obj;
	
	ifstream userfile; 
      
    userfile.open("user.txt", ios::in); 
      
    while ( !userfile.eof() ) 
	{ 
	
	    getline(userfile, obj.username);
	    getline(userfile, obj.password);
        
        if (  (obj.username == username) && (obj.password == password)  )
		{ 
            isfound = true;
        } 
    } 
    userfile.close();
    
    if(isfound == false)
    {
    system("cls");
    cout << endl << "Incorrect Credentials Entered - Please Try Again!" << endl;
    }
    else if(isfound == true)
    cout << "Account Login Successful!" << endl << endl;
    
    return isfound;	
}	
		
		
	void usersignup()
{	
	ofstream userfile; 
      
    userfile.open("user.txt", ios::app); 
           
    userfile << username;
    userfile << "\n";
    userfile << password;
    userfile << "\n";
    
    userfile.close();
    
    cout << "Account Signup Successful!" << endl << endl;
    
}	
	
	int SearchItems (string genre, item I[])
{
    bool found = false;
	int i = 0;
		
	ifstream gallery; 
      
    gallery.open("gallery.txt", ios::in); 
    
    system("cls");
    cout << "Displaying Results for Type: " << genre << endl << endl;
      
    while ( !gallery.eof() ) 
	{ 
	
	    getline(gallery, I[i].name);
	    getline(gallery, I[i].type);	    
	    getline(gallery, I[i].origin);
	    getline(gallery, I[i].artistname);
	    getline(gallery, I[i].price);
	    getline(gallery, I[i].pieces);
	    getline(gallery, I[i].status);
	    
        
        if (  (I[i].type == genre) )
		{ 
            cout << "Item Name: " << I[i].name << endl;
            found = true;
        } 
        
        i = i + 1;
    } 
    i = i - 1;
    
    gallery.close();
	cout << endl << endl;
	
	if(found == false)
	{
	cout << "Incorrect Type Entered - Please Try Again!" << endl << endl;
	return -1;	
    }
}
    
    item ViewItem(item I[], int arraybound)
{
	bool found = false;
	string name;
	int i;
	
	askname:
	
	i = 0;	
	
    cout << "Enter Item Name to View Details: ";
  	getline(cin, name);
  	
  	system("cls");
  	
  	ifstream gallery; 
      
    gallery.open("gallery.txt", ios::in); 
      
    while (  ( i < arraybound ) && !found  ) 
	{    
        if (  (I[i].name == name) )
		found = true;
		
		i = i + 1;
	} 
	i = i - 1;
	
    gallery.close();
    
    if (found == true)    
    I[i].DisplayOutput();
    
    else if(found == false)
    {
    cout << "Incorrect Name Entered - Please Try Again!" << endl << endl;
    goto askname;
	}
	
	return I[i];
    
}

void BuyItem(item I[], item &E, int arraybound)
{
	 int num;
	 
	 stringstream geek(E.pieces);
     geek >> num;
   
     num = num - 1;

     stringstream ss;
     ss << num;
     
     E.pieces = ss.str();
	 
	 if(E.pieces == "0")
	 E.status = "Sold";
	
	string address, phonenumber, framesize, wrapping;
	 
	system("cls"); 
	cin.ignore();
	
    cout << "Enter Shipment Address: ";
    getline(cin, address);
		
    cout << "Enter Phone Number: ";
    getline(cin, phonenumber);
		
    cout << "Enter Frame Size (0 for no Framing): ";
    getline(cin, framesize);
		
    cout << "Enter Gift Wrapping: ";
    getline(cin, wrapping);
    
    
		
    cout << endl << endl << "Checkout -  " << endl;
	cout << "Total Bill: " << "Rs " << E.price << endl;
	
	
	ifstream gallery; 
	ofstream temp;
	
	int k = 0, i = 0;
      
    temp.open("temp.txt", ios::app); 
          
    while ( i < arraybound ) 
	{    
        if (I[i].name != E.name)
	    {
	    if (k == 1)
	    temp << "\n";
			
	    else if( k == 0)	
	    k = 1;    
	    	
	     temp << I[i].name;
         temp << "\n";
         temp << I[i].type;
         temp << "\n";
         temp << I[i].origin;
         temp << "\n";
         temp << I[i].artistname;
         temp << "\n";
         temp << I[i].price;
         temp << "\n";
         temp << I[i].pieces;
         temp << "\n";
         temp << I[i].status;	
	    }
	    else if (I[i].name == E.name)
	    {
	    if (k == 1)
	    temp << "\n";
			
	    else if( k == 0)	
	    k = 1;    
	    	
	     temp << E.name;
         temp << "\n";
         temp << E.type;
         temp << "\n";
         temp << E.origin;
         temp << "\n";
         temp << E.artistname;
         temp << "\n";
         temp << E.price;
         temp << "\n";
         temp << E.pieces;
         temp << "\n";
         temp << E.status;	
	    }
	    
	    i = i + 1;
		
	} 
    gallery.close();
    temp.close();
    
    remove("gallery.txt");
    rename("temp.txt", "gallery.txt");		    
}

void Feedback()
{
	system("cls");
	cin.ignore();
	string feedback;
	
	cout << "Please type your feedback: ";
	getline(cin, feedback);
	
	system("cls");
	
	
}
		
};

int ManagementFunction2(management &M1);
int UserFunction2(user &U);


int main()
{
	
	int choice = 0;
	
	string username;
	string password;
	
	
	main:
	displaymainmenu();
	inputchoice(choice, 1, 3);
	
	system("cls");
	switch (choice)
	{
		case 1:
		{
			if (ManagementFunction() == -1)
			goto main;
			    
			break;      
	    }
			
		case 2:
		{
			if( UserFunction() == -1)
			goto main;
				 	
			break;
		}
			
		case 3:
		    exit(0);		
	}
		
}

int ManagementFunction()	
{
       management M1;	
       system("cls");
           
	   cin.ignore();     
       credentials:
           	
	   M1.login();
	   if(M1.verifymanagementlogin())
	    {
	   		if ( ManagementFunction2(M1) == -1)
	   		{
	   		system("cls");
	   		return -1;
		    }
		}
			        
	   else
	   goto credentials;	
}
	
int ManagementFunction2(management &M1)
{
	int input;
	
	display:
	cout << "~~~~~~~~~~~~~~~~~~\n";
	cout << "Add Item.......(1)\n";
	cout << "Edit Items ....(2)\n";
	cout << "Delete Items ..(3)\n";
	cout << "Log Out .......(4)\n";

    inputchoice(input, 1, 4);
	
	switch(input)
	{
		case 1: 
		{
			M1.AddItem();
			goto display;
			break;
	    }
		
		case 2:
		{
			M1.EditItem();
			goto display;
			break;
	    }
		
		case 3:
		{
			M1.DeleteItem();
			goto display;
			break;
	    }
			
		case 4:
		{
			return -1;
	    }
			
	}	
	
}
	
int UserFunction()
{
	    int choice, action = 1;
	    
		user U1;
	    
	    start:
        system("cls");
        
		DisplayUserMainMenu(); 
		inputchoice(choice, 1, 3);
		
		system("cls");	
		cin.ignore();
				
	         switch (choice)
	         {
		            case 1:
		            {
		            credentials:
						
			        U1.login();
			        if(U1.verifyuserlogin())
			        {
			        action = UserFunction2(U1);		         		
			        if( action == -1)
			          goto start;
			          
			        }
			        else
			        goto credentials;
			        
		         	break;      
            	    }
			
		             case 2:
		            {
					
		           	U1.login();
		           	U1.usersignup();
					action = UserFunction2(U1);		         		
			        if( action == -1)
			        {
			        goto start;			        
			        }
			        
		         	break;
	             	}
			
	             	case 3:
	             		system("cls");
		            return -1;		
	        }
	        return 0;
}	

int UserFunction2(user &U)
{
	int arraybound = 40;
	
	item I[arraybound], E;
	string genre;
	int userchoice;
	usermenu:
	cout << "User Menu - " << endl << endl;
	cout << "1- Search Category\n";
	cout << "2 - Log Out\n";
		
	inputchoice(userchoice, 1 , 2);
		
	switch(userchoice)
	{
		case 2:
			{			
			return -1;
		    }
		case 1:
		{	
		system("cls");	
		cin.ignore();
		
		displaygenre:
		DisplayGenre();
		
	    cout << "Please type your choice (as shown above) : ";     	
    	getline(cin, genre);
		
		int r, option;
		list_items:
		r = U.SearchItems(genre, I); 
		   
		if( r == -1 )
		goto displaygenre;
		
		E = U.ViewItem(I, arraybound);
		string Estatus = E.getstatus();
		cout << endl << endl;
		
		cout << "1 - Return to List of Items" << endl;
		cout << "2 - Go Back to Search" << endl;
		
		if(Estatus != "Sold")
		{
		cout << "3 - Buy Item" << endl;		
		inputchoice(option, 1 , 3);
	    }
	    else if(Estatus != "Available")
		inputchoice(option, 1 , 2);
	    		
		            switch(option)
		            {
						case 1:
							{
							cin.ignore();	
							goto list_items;
		                	break;
		                    }
		                    
		                case 2:
							{
							cin.ignore();	
							system("cls");
							goto usermenu;
		                	break;
		                    }
							    
		                case 3:
		                {
						U.BuyItem(I, E, arraybound);
						cout << endl << endl;
		                cout << "1 - Give Feedback" << endl;
		                cout << "2 - Return to List of Items" << endl;
		                cout << "3 - Go Back to Search" << endl;
		                inputchoice(option, 1 , 3);
		                
		                           switch(option)
		                            {
									  case 2: 
		                              {
		                              cin.ignore();
		                              goto list_items;
		                              break;
		                              }
		                              
		                              case 3:
		                              {
		                              system("cls");	
		                              goto usermenu;
		                              break;
		                              }
		                               
									  case 1: 
									  {
									  U.Feedback();
									  goto usermenu;
									  
								      }
						            };			              
						}
		            };
	    }
	};
    return 0;
}

int displaymainmenu()
{	
		cout << "------------------------------------------- \n";
        cout << "             ONLINE ART SHOW\n";
        cout << "------------------------------------------- \n";
        
        cout << "Please select an option from the menu below - \n";
        cout << "1. Management Login \n";
        cout << "2. User Login \n";
        cout << "3. Quit \n \n" << endl;
}

void inputchoice(int &choice, int lower, int upper)
{
	int verify = 1;
		
	while(verify)
	{
	cout << endl << "Please select your choice: ";
    cin >> choice;	
		
	if (choice < lower || choice > upper)
    {
        cout << endl;
        cout << "**ERROR** - Invalid Selection\n" << endl;
        verify = 1;
    }   
    else 
    verify = 0;
    }
}


int DisplayUserMainMenu()
{		
	cout << "Please select an option from the menu below: \n";
    cout << "1. User Login\n";
    cout << "2. Create an account\n";
	cout << "3. Back to Main Menu.\n";
}

int Validation(string &username, string &password)
{
	
	int no_number = 0, plength;
	bool uppercase = false, number = false, specialchar = false, correct = true, length = false;
		
	plength = password.length();
	
	if(plength >= 8)
	length = true;
	
	for(int i = 0 ; i < password.length(); i ++)
    {
    	if  (  (password.at(i) >= 65) && (password.at(i) <= 90)  )
    	uppercase = true;
    	
    	else if  (  (password.at(i) >= 48) && (password.at(i) <= 57)  )
    	no_number = no_number + 1;
    	
    	else if    ( (   (  (password.at(i) >= 33) && (password.at(i) <= 47)  )  ||  (  (password.at(i) >= 58) && (password.at(i) <= 64)  )    )   ||  (  (password.at(i) >= 91) && (password.at(i) <= 96)  ) )
    	specialchar = true;  	   	
    }	 
	
	if (no_number >= 2) 
	number = true;
	
	
	
	if ( username.find(" ", 0) != -1)
	{
	cout << endl << "Username is Incorrect - Contains Spaces" << endl << endl;	
	correct = false;
    }
	    
	if(uppercase == false) 
	{
	cout << endl << "Passwrod is Incorrect - Contains No Uppercase Letter" << endl << endl;
	correct = false;
    }
    
    if(length == false) 
	{
	cout << endl << "Passwrod is Incorrect - Contains Less than 8 Charecters" << endl << endl;
	correct = false;
    }
	
	if (number == false)
	{
	cout << endl << "Passwrod is Incorrect - Contains Insufficient Numbers" << endl << endl;	
	correct = false;
    }
	
	if (specialchar == false) 
	{
	cout << endl << "Passwrod is Incorrect - Contains No Special Charecter" << endl << endl;	
	correct = false;
    }
	
	if (username == password)
	{
	cout << endl << "Password and Username are Same! " << endl << endl;	
	correct = false;
    }
    
    if (correct == true)
    return 0;
    else if (correct == false)
    return 1;
    
}

void DisplayGenre()
{
	string genre;
	cout << "-------------------------------------------\n";
	cout << "    Please let us know your preference\n";
	cout << "-------------------------------------------\n";
	cout << "-> Nature Art    \n";
	cout << "-> Object Art    \n";
	cout << "-> Abstract Art  \n";	
}
















