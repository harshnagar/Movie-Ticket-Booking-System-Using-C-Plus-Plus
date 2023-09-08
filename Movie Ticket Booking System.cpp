#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
	int option;	
	unordered_map <int, unordered_map <string, unordered_map <string, string> > > booking_hist;
	map<string,int>free_seats;
	map<string,int>movies_price;
	free_seats["Avengers Endgame"]=300;
	free_seats["The Witcher"]=300;
	free_seats["Twilight Saga"]=300;
	free_seats["KGF Chapter 2"]=300;
	movies_price["Avengers Endgame"]=300;
	movies_price["The Witcher"]=350;
	movies_price["Twilight Saga"]=250;
	movies_price["KGF Chapter 2"]=300;
	p1:
	cout<<"-------------------------------------------------\n";
	cout<<"WELCOME TO MAXCINEMA MOVIE TICKET BOOKING SYSTEM\n";	
	cout<<"-------------------------------------------------\n";
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	cout<<"   Movies              Ticket Prices\n";
	cout<<"Avengers Endgame"<<"           "<<movies_price["Avengers Endgame"]<<"\n";
	cout<<"The Witcher"<<"                "<<movies_price["The Witcher"]<<"\n";
	cout<<"Twilight Saga"<<"              "<<movies_price["Twilight Saga"]<<"\n";
	cout<<"KGF Chapter 2"<<"              "<<movies_price["KGF Chapter 2"]<<"\n";
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";          
	cout<<"-------------------------------------------------\n";
	cout<<"Please Choose any Option from Below Menu: \n";
	cout<<"------------------------------------------------\n"
			"1 >> Book Movie Tickets.\n2 >> Cancel Movie Ticket.\n3 >> Print your Ticket.\n"
			"4 >> Change Ticket Price(For Admin).\n5 >> View All Booking Records(For Admin).\n"
			"6 >> Exit.\n---------------------------------------------------\n>>";
	cin>>option;
	if (option == 1){
		int movie_opt;
		p2:		
		cout<<"############################################\n";
		cout<<"Choose your Movie from the Below Options:\n";
		cout<<"--------------------------------------------\n"
				"1 >> Avengers Endgame(Hin/Eng).\n2 >> The Witcher(Hin/Eng).\n"
				"3 >> Twilight Saga(Hin/Eng).\n4 >> KGF Chapter 2(Hindi).\n"
				"5 >> Move to Main Menu.\n>>";
		cin>>movie_opt;
		if (movie_opt==1 or movie_opt==2 or movie_opt==3 or movie_opt==4){
			int lang, seats, av_seats, re_seats, confirm_ticket;
			long long int c_num;			
			string name;
			string lang_sel = "None";
			string sel_movie_name	= "None";
			switch(movie_opt){
				case 1:
					sel_movie_name="Avengers Endgame";
					av_seats = free_seats["Avengers Endgame"];
					re_seats = 300 - av_seats;
					break;
				case 2:
					sel_movie_name="The Witcher";
					av_seats = free_seats["The Witcher"];
					re_seats = 300 - av_seats;
					break;
				case 3:
					sel_movie_name="Twilight Saga";
					av_seats = free_seats["Twilight Saga"];
					re_seats = 300 - av_seats;
					break;
				case 4:
					sel_movie_name="KGF Chapter 2";
					av_seats = free_seats["KGF Chapter 2"];
					re_seats = 300 - av_seats;
					break;				
			}		
			
			p3:
			cout<<"--------------------------------------------\n";
			cout<<"You Opted for "<<sel_movie_name<<"\n";
			cout<<"--------------------------------------------\nPlease Choose the Language:\n"
				"1 >> English.\n2 >> Hindi.\n>>";
			cin>>lang;
			if (lang==1){
				lang_sel="English";				
			}
			else if (lang==2){
				lang_sel="Hindi";				
			}
			if (lang==1 or lang==2){												
				cout<<"--------------------------------------------\n";
				cout<<"You opted for "<< lang_sel<< " language.\n";
				p4:
				cout<<"-------------------------------------------\n"						
						"#Available Seats: "<<av_seats<<"   #Reserverd Seats: "<<re_seats<<"\n";
				cout<<"Please Enter Number of Seats to Book:\n>>";
				cin>>seats;
				if (seats>av_seats){
					cout<<"Number of Seats Should be less then "<<av_seats<<" Try Again.";
					goto p4;
				}
				else if (seats<=0){
					cout<<"Number of Seats Should be More then 0! Try Again.";
					goto p4;
				}
				else if (seats<av_seats or seats>0) {
					cout<<"--------------------------------------------\n";
					cout<<"You opted for "<<seats<<" Seats.\n";
					cout<<"-------------------------------------------\n";
					cout<<"Please Enter your Name >> ";
					cin.ignore(); 
					getline (cin,name);
					cout<<"Please Enter your Contact Number >> ";
					cin>>c_num;
					cout<<"--------------------------------------------\n";
					cout<<"Please Verify your Ticket Detials\n";
					cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
						  " Movie: "<<sel_movie_name<<"\n"
						  " Tickets Booked By: "<<name<<"\n"
						  " Language: "<<lang_sel<<" \n"
						  " Number of Seats: "<<seats<<" \n"
						  " Contact Number : "<<c_num<<"\n"
						  " Total Bill : "<<movies_price[sel_movie_name]*seats<<"\n"
						  "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
					p5:
					cout<<"Do you Want to Book the Ticket ?\n"
							"1 >> Yes\n2 >> No\n>>";
					cin>>confirm_ticket;
					if (confirm_ticket==1){
						booking_hist[c_num][sel_movie_name]["Movie"]=sel_movie_name;
						booking_hist[c_num][sel_movie_name]["Tickets Booked By"]=name;
						booking_hist[c_num][sel_movie_name]["Language"]=lang_sel;
						booking_hist[c_num][sel_movie_name]["Total Seats"]=to_string(seats);
						booking_hist[c_num][sel_movie_name]["Contact Number"]=to_string(c_num);
						booking_hist[c_num][sel_movie_name]["Total Bill"]=to_string(movies_price[sel_movie_name]*seats);
						free_seats[sel_movie_name]=av_seats-seats;
						cout<<"--------------------------------------------\n";
						cout<<"TICKETS BOOKED SUCCESSFULLY!\n";
						goto p1;											
					}
					else if(confirm_ticket==2){
						cout<<"TICKETS BOOKING CANCELLED!";
						goto p1;
					}
					else{
						cout<<"Please Choose a Valid Option!";
						goto p5;
					}
				}
				else{
					goto p3;
				}
				
			}
			else{
				cout<<"Please Choose a Valid Option!\n";
				goto p3;
			}			
		}
		else{
			cout<<"Please Choose a Valid Option!\n";
			goto p2;
		}	
	}				
	else if (option == 2){
		long long int usr_c_num;
		int count = 0;
		int temp = 0;
		map<int, string> t_list ;
		cout<<"Please Enter your Registered Phone Number, to check List your Tickets .\n"
				">>";
		cin>>usr_c_num;
		for (auto i : booking_hist[usr_c_num]){	
			temp=1;
			count=count+1;			
			cout<<"Ticket No : "<<count<<"\n";
			t_list[count] =	i.first;	
			cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";        	
        	for (auto j : booking_hist[usr_c_num][i.first]){					        		
        		cout << j.first <<  " : " << j.second << endl;        	
        	}
        	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		}
		if (count>0){
			int t_no;
			cout<<"Please Enter Ticket Number to Cancel from above list.\n>>";
			cin>>t_no;
			if (t_no<count or t_no>=0){
				booking_hist[usr_c_num].erase(t_list[t_no]);
				cout<<"Ticket Number "<<t_no<<" for Movie "<<t_list[t_no]<<" Cancelled Successfully.\n";
			}		
		}
		if (temp == 0){
			cout<<"--------------------------------------------\n";
			cout<<"NO TICKETS FOUND WITH CONTACT NUMBER "<<usr_c_num<<"\n";			
		}
		goto p1;
	}
	else if(option == 3){
		long long int usr_c_num;
		int temp=0;		
		cout<<"Please Enter your Registered Phone Number, to check your Ticket Status.\n"
				">>";
		cin>>usr_c_num;
		for (auto i : booking_hist[usr_c_num]){	
			temp=1;
			cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";        	
        	for (auto j : booking_hist[usr_c_num][i.first]){			        		
        		cout << j.first <<  " : " << j.second << endl;        	
        	}
        	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		}
		if (temp == 0){
			cout<<"--------------------------------------------\n";
			cout<<"NO TICKETS FOUND WITH CONTACT NUMBER "<<usr_c_num<<"\n";			
		}
		goto p1;
	}
	else if (option == 4) {
		string pass;
		int ch_tp,new_pr;		
		p7:
		int count = 1;
		cout << "Please Enter Admin Password to Continue.\n>>";
		cin >> pass;
		if (pass=="admin"){
			cout<<"Please Choose Movie from Below Menu to change its Ticket Price. \n";
			cout<<"--------------------------------------------\n"
				"1 >> Avengers Endgame(Hin/Eng).\n2 >> The Witcher(Hin/Eng).\n"
				"3 >> Twilight Saga(Hin/Eng).\n4 >> KGF Chapter 2(Hindi).\n"
				"5 >> Move to Main Menu.\n>>";
			cin>>ch_tp;
			switch(ch_tp){
				case 1:
					cout<<"Please Enter new Ticket Price.\n>>";
					cin>>new_pr;
					movies_price["Avengers Endgame"]=new_pr;
					cout<<"Price Changed Successfully to "<<new_pr<<"\n";
					goto p1;
					break;
				case 2:
					cout<<"Please Enter new Ticket Price.\n>>";
					cin>>new_pr;
					movies_price["The Witcher"]=new_pr;
					cout<<"Price Changed Successfully to "<<new_pr<<"\n";
					goto p1;
					break;
				case 3:
					cout<<"Please Enter new Ticket Price.\n>>";
					cin>>new_pr;
					movies_price["Twilight Saga"]=new_pr;
					cout<<"Price Changed Successfully to "<<new_pr<<"\n";
					goto p1;
					break;
				case 4:
					cout<<"Please Enter new Ticket Price.\n>>";
					cin>>new_pr;
					movies_price["KGF Chapter 2"]=new_pr;
					cout<<"Price Changed Successfully to "<<new_pr<<"\n";
					goto p1;
					break;				
				
			}
		}
		else{
			int ad_login;
			cout<<"Invalid Password Please try again!\n"
					"1) Move to Main Menu.\n2) Try again.";
			cin>>ad_login;
			if (ad_login==2){
				goto p7;
			}
			else {
				goto p1;
			}
		}
	}
	
	else if (option == 5) {
		p6:
		string pass;
		int temp = 0;		
		int count = 1;
		cout << "Please Enter Admin Password to Continue.\n>>";
		cin >> pass;
		if (pass=="admin"){
			for (auto i : booking_hist){
				temp = 1;
				for (auto j : booking_hist[i.first]){
					cout<<"Ticket "<<count<<"\n";
					cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";        	
		        	for (auto k : booking_hist[i.first][j.first]){			        		
		        		cout << k.first <<  " : " << k.second << endl;        	
		        	}
        			cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
        			count = count +1;
				}
			}
			if (temp == 0){
				cout<<"NO RECORDS FOUND!\n";
			}			
			goto p1;
		}
		else{
			int ad_login;
			cout<<"Invalid Password Please try again!\n"
					"1) Move to Main Menu.\n2) Try again.";
			cin>>ad_login;
			if (ad_login==2){
				goto p6;
			}
			else {
				goto p1;
			}
		}
	}
	else{
		cout<<"Please Choose a Valid Option!";
		goto p1;
	}			
}
