#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename, vector<string> &name,  vector<int> &scores,  vector<char> &grade){
    ifstream datafile(filename.c_str()); 
    string text;
    char n[100];
    char format[] = "%[^:]: %d %d %d";
    while(getline(datafile,text)){
        int score[3];
        sscanf(text.c_str(),format, n , &score[0], &score[1], &score[2]);
        name.push_back(n);
        scores.push_back(score[0] + score[1] + score[2]);
        grade.push_back(score2grade(score[0] + score[1] + score[2]));
    }
}

void getCommand(string &cmd, string &key){
    cout << "Please input your command : ";
    cin >> cmd >> key;
}

void searchName(vector<string> name, vector<int> scores, vector<char> grade, string key){
    cout << "---------------------------------\n";
    int nLength = name.size();
    bool founded = 1;
    for(int i = 0; i < nLength; ++i){
        if(toUpperStr(name[i]) == toUpperStr(key)){
            cout << name[i] << "'s score = " << scores[i] << endl;
            cout << name[i] << "'s score = " << grade[i] << endl;
            founded = 0;
    }
        } 
    if(founded) {
        cout << "Cannot found.\n";
    }
    cout << "---------------------------------";
}

void searchGrade(vector<string> name, vector<int> scores, vector<char> grade, string key){
    cout << "---------------------------------\n" ;
    int gLength = name.size();
    bool founded = 1;
    for(int i = 0; i < gLength; ++i){
        string grd(1,grade.at(i));
        if(grd == toUpperStr(key)){

            cout << name[i] << scores[i] << grade[i];
            founded = 0;
    }
        } 
    if(founded) {
        cout << "Cannot found.\n";
    }
    cout << "---------------------------------";
}



int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);

    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
