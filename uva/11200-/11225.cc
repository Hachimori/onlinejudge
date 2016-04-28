#include<iostream>
#include<string>
#include<sstream>
#define EPS 1.0e-9
using namespace std;

bool oulder(string s){
  if(s=="fool") return true;

  stringstream in(s);
  in >> s;
  if(s!="one" && s!="twenty-one") return false;
  in >> s;
  in >> s;
  return s=="trumps";
}

double value(string s){
  if(oulder(s)) return 4.5;
  stringstream in(s);
  in >> s;
  if(s=="king") return 4.5;
  if(s=="queen") return 3.5;
  if(s=="knight") return 2.5;
  if(s=="jack") return 1.5;
  return 0.5;
}

int main(){
  int cases;
  cin >> cases;

  for(int k=0;k<cases;k++){
    if(k) cout << endl;

    int nCard;
    cin >> nCard;
    
    int nOuld = 0;
    double score = 0;
    string str; getline(cin,str);

    for(int i=0;i<nCard;i++){
      getline(cin,str);
      
      if(oulder(str)) nOuld++;
      score += value(str);
    }
    
    switch(nOuld){
    case 0: score -= 56; break;
    case 1: score -= 51; break;
    case 2: score -= 41; break;
    case 3: score -= 36; break;
    }

    cout << "Hand #" << k+1 << endl;
    if(score>-EPS)
      cout << "Game won by " << (int)(score+0.5) << " point(s)." << endl;
    else
      cout << "Game lost by " << (int)(-score+0.5) << " point(s)." << endl;
  }

  return 0;
}
