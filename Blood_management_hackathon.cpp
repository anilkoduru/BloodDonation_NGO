#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

struct info{
    string name;
    int number;
    string blood_grp;
    string hos_name;
};
void printsingle(info i);

void readdata(vector <info>& v_info){
    ifstream fin;
    fin.open("data.txt");
    if(!fin){
        cout << "Unable to read the data" << endl;
        exit(1);
    }
    string line;
    while(!fin.eof()){
        getline(fin,line);
        istringstream iss(line);
        string donor_name;
        string ph_number;
        string blood_group;
        string hospital_name;
        getline(iss,donor_name,',');
        getline(iss,ph_number,',');
        getline(iss,blood_group,',');
        getline(iss,hospital_name,',');
        info temp;
        temp.name = donor_name;
        temp.number = atoi(ph_number.c_str());
        temp.blood_grp = blood_group;
        temp.hos_name = hospital_name;
        v_info.push_back(temp);
    }
    fin.close();
}

void printdata(vector <info> v_info){
    cout << endl << setw(20) << left << "Name"
         << setw(15) << left << "Mobile Number"
         << setw(5) << left << "Blood"
         << setw(20) << right << "Hospital" << endl;
    for(vector <info>::iterator it = v_info.begin();it != v_info.end();it++){
        printsingle(*it);
    }

}

void printsingle(info i){
    cout << setw(20) << left << i.name
         << setw(15) << left << i.number
         << setw(5) << left << i.blood_grp
         << setw(20) << right << i.hos_name << endl;
}

void save_data(vector <info>& v_info){
    ofstream fout;
    fout.open("data.txt");
    if(fout.fail()){
        cout << "There is an error in opening the file";
        exit(1);
    }
    int count = 0;
    for(vector <info>::iterator it = v_info.begin();it != v_info.end();it++){
        fout << it->name << "," << it->number << "," << it->blood_grp << "," << it->hos_name << "," << endl;
        count++;
        if(count != v_info.size()){
            cout << endl;
        }
    }
    fout.close();
}

void send_notification(vector <info> v_info){
    string need;
    cout << "Enter the blood for which we need to send the notification :";
    cin >> need;
    cout << "We don't have " << need << "blood ,if you can donate pls reply" << endl;
    for(vector <info>::iterator it = v_info.begin();it != v_info.end();it++){
        if(it->blood_grp == need){
            cout << "notification is sent to " << it->name << endl;
        }
    }
}

void search_for_blood(vector <info> v_info){
    string need;
    cout << "Enter the blood which is to be searched : ";
    cin >> need;
    for(vector <info>::iterator it = v_info.begin();it != v_info.end();it++){
        if(it->blood_grp == need){
            cout << "Blood grp is available "<< endl ;
            cout << "Hospital name - " << it->hos_name << endl;
            cout << "Donor is " << it->name << endl;
        }
    }
}

void any_notification(){
    string s;
    cout << "notification received for donation of blood ,"
         << "Are you willing to donate : ";
    cin >> s;
    if(s == "yes"){
        cout << "Thank you!,You can come tomorrow" << endl;
    }
    else{
        cout << "Thank you, for your reply" << endl;
    }
}

void register_details(vector <info>& v_info){
    info temp;
    cout << "Enter your name : ";
    cin >> temp.name;
    cout << "Enter your mobile number : ";
    cin >> temp.number;
    cout << "Enter your blood group : ";
    cin >> temp.blood_grp;
    cout << "Enter the hospital you want to donate : ";
    cin >> temp.hos_name;
    v_info.push_back(temp);
}

int main()
{
    vector <info> v_info;
    readdata(v_info);
    int choice;
    bool quit = false;
    while(!quit){
        cout << endl << "1.To enter as admin." << endl
             << "2.To enter as user." << endl
             << "3.To exit" << endl << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch(choice){
        case 1:
            cout << "Successfully logged in." << endl;
            cout << "1.list of donors." << endl
                 << "2.Searching for required blood." << endl
                 << "3.Send notifications for blood requesting." << endl << endl;
            cin >> choice;
            switch(choice){
            case 1:
                printdata(v_info);
                cout << endl;
                break;
            case 2:
                search_for_blood(v_info);
                break;
            case 3:
                send_notification(v_info);
                break;
            default:
                cout << "Select the correct option." << endl;
                break;
            }
            break;
        case 2:
            cout << "Successfully logged in." << endl;
            cout << "1.To register." << endl
                 << "2.Any notifications." << endl << endl;
            cin >> choice;
            switch(choice){
            case 1:
                register_details(v_info);
                save_data(v_info);
                break;
            case 2:
                any_notification();
                break;
            default:
                cout << "Select the correct option." << endl;
                break;
            }
            break;
        case 3:
            quit = true;
            break;
        }

    }
    return 0;
}











