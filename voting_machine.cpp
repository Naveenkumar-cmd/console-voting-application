#include <bits/stdc++.h>

using namespace std;

int main(){
	//bool type variable to run the whole voting operations until the the voter is true meaning voter is coming to vote
	bool voting_process = true;
	//variables to store the count of vote different party will receive
	int bjp = 0, inc = 0, aap = 0, tmc = 0, rjd = 0;
	//password to authenticate admin
	string admin_pass = "admin1234";
	//force admin to make only 3 attempts to authenticate
	int admin_auth_attempts = 3;
	//loop the voting operations until admin decides to stop
	while(voting_process){
		//User identification: whether they are a voter or admin - only admin can end the voting process
		cout<<"please enter carefully 1. voter 2. admin: ";
		user: //start from here again if user mistakenly entered the wrong choice
		int user_type;
		cin>>user_type;
		//if user is a voter- he can proceed with the voting process
		if(user_type == 1){
			cout<<"\nparties: 1. BJP 2. INC 3. AAP 4. TMC 5. RJD\n\n"; //voter will have a choice to enter the number of the party they wish to vote for
			cout<<"enter the party number, you wan to vote for: ";
			party: //start from here again if voter mistakenly entered the wrong choice
			int party_no;
			cin>>party_no;
			switch(party_no){
				case 1: bjp++;
				break;
				case 2: inc++;
				break;
				case 3: aap++;
				break;
				case 4: tmc++;
				break;
				case 5: rjd++;
				break;
				default: cout<<"\nplease enter a valid party number: ";
				goto party; //go to this label to offer a voter every chance to enter a valid party number, in case they entered a wrong choice
			}
		}
		//if user is an admin - he can stop or continue with the voting process
		else if(user_type == 2){
			//authenticating admin before taking any actions
			admin_auth:
			cout<<"\nplease enter admin password: ";
			string pass;
			cin>>pass;
			if(pass == admin_pass){
				//functionality to choose if admin wish to end the voting process anytime or continue with it
				cout<<"\npress 0 if voting is over, 1 if continue: ";
				decision: //start from here again if admin mistakenly entered the wrong choice
				int choice; cin>>choice;
				if(choice == 0){
					voting_process = false;
				}
				else if(choice == 1){
					cout<<"\n";
					continue;
				}
				else{
					cout<<"\nplease enter a valid choice: ";
					goto decision; //go to this label to offer an admin every chance to enter a valid choice, in case they entered a wrong choice
				}
			}
			else{
				//if all 3 attempts left - auth failed
				if(admin_auth_attempts == 1){
					cout<<"\nadmin authentication failed, can't let you in\n";
				}
				//else down the attempts count by 1 and show the necessary message
				else{
					admin_auth_attempts--;
					cout<<"\nwrong admin password, "<<admin_auth_attempts<<" attempts left\n";
					goto admin_auth;//go to admin authentication process in case admin entered wrong password
				}
			}
		}
		else{
			cout<<"\nplease enter valid user type: ";
			goto user; //go to this label to offer a user every chance to enter a valid user type, in case they entered a wrong choice
		}
		cout<<"\n";
	}
	//savin votes recieved by individual parties into a vector container
	vector<int> v;
	v.push_back(bjp);
	v.push_back(inc);
	v.push_back(aap);
	v.push_back(tmc);
	v.push_back(rjd);
	//finding party with maximum votes
	int winner = *max_element(v.begin(), v.end());
	cout<<"\n";
	cout<<"BJP: "<<bjp<<endl<<"INC: "<<inc<<endl<<"AAP: "<<aap<<endl<<"TMC: "<<tmc<<endl<<"RJD: "<<rjd<<endl;
	//handling clear win scenario
	if(winner == bjp && bjp != inc && bjp != aap && bjp != tmc && bjp != rjd){
		cout<<"\nBJP Won"<<endl;
	}
	else if(winner == inc && inc != bjp && inc != aap && inc != tmc && inc != rjd){
		cout<<"\nINC Won"<<endl;
	}
	else if(winner == aap && aap != bjp && aap != inc && aap != tmc && aap != rjd){
		cout<<"\nAAP Won"<<endl;
	}
	else if(winner == tmc && tmc != bjp && tmc != inc && tmc != aap && tmc != rjd){
		cout<<"\nTMC Won"<<endl;
	}
	else if(winner == rjd && rjd != bjp && rjd != inc && rjd != aap && rjd != tmc){
		cout<<"\nRJD Won"<<endl;
	}
	//handling draw scenario
	else{
		vector<string> party;
		for(int i = 0; i < v.size(); i++){
			if(winner == v[i]){
				if(i == 0){
					party.push_back("BJP");
				}
				else if(i == 1){
					party.push_back("INC");
				}
				else if(i == 2){
					party.push_back("AAP");
				}
				else if(i == 3){
					party.push_back("TMC");
				}
				else if(i == 4){
					party.push_back("RJD");
				}
			}
		}
		cout<<"There has been a draw among: ";
		for(int i = 0; i < party.size(); i++){
			cout<<party[i]<<" ";
		}
	}
	return 0;
}
