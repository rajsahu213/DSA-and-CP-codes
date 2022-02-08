#include<bits/stdc++.h>
using namespace std;
void managerooms()
{
	int opt,rno,flag=0;
	do{
		cout<<"\n### Manage Rooms ###";
		cout<<"\n1. Add Room";
		cout<<"\n2. Search Room";
		cout<<"\n3. Back to Main Menu";
		cout<<"\n\nEnter Option: ";
		cin>>opt;

		switch(opt)
		{
			case 1:  cout<<"enter room number: ";
					 cin>>rno;
					 for(int i=0;i<count;i++)
					 {
					 	if(rooms[i].roomnumber==rno)
					 	{
					 		flag=1;
					 	}
					 }	
					 if(flag==1){cout<<"this room number is already taken, enter unique room number\n";
									flag=0;}
					else{
						rooms[count]=room.addroom(rno);
						count++;
					}
					break;

			case 2: cout<<"enter the room number: ";
					cin>>rno;
					room.searchroom(rno);
					break;

			case 3: break;
			default: cout<<"wrong input! enter once again\n";
		}
	}while(opt!=3);
}
int main()
{
    int opt;
    do{
    	cout<<"######## Hotel Management #########\n";
		cout<<"\n1. Manage Rooms";
		cout<<"\n2. Check-In Room";
		cout<<"\n3. Available Rooms";
		cout<<"\n4. Search Customer";
		cout<<"\n5. Check-Out Room";
		cout<<"\n6. Guest Summary Report";
		cout<<"\n7. Exit";
		cout<<"\n\nEnter Option: ";
		cin>>opt;

		switch(opt)
		{
			case 1: managerooms();
					break;
			case 2:	

			case 7: cout<<"THANK YOU FOR USING THE SOFTWARE\n";
					break;
			default:cout<<"wrong input! enter once again\n";			
		}

    }while(opt!=7);
}