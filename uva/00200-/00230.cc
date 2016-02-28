#include<iostream>
using namespace std;
const int BOOK = 50000, QUERY = 50000;

enum State{SHELVE,BORROWED,TORETURN};

int nBook, nQuery;
pair<string,string> book[BOOK]; //(author,title)
string query[QUERY][2];

void read(){
  nBook = nQuery = 0;
  while(1){
    string s;
    getline(cin,s);
    if(s=="END") break;
    int fstQuote = s.find('"');
    int scdQuote = s.find('"',fstQuote+1);
    book[nBook++] = make_pair(s.substr(scdQuote+5),s.substr(fstQuote+1,scdQuote-fstQuote-1));
  }

  while(1){
    string s;
    getline(cin,s);
    if(s=="END") break;
    if(s!="SHELVE"){
      query[nQuery][0] = s.substr(0,s.find(' '));
      int fstQuote = s.find('"');
      int scdQuote = s.find('"',fstQuote+1);      
      query[nQuery++][1] = s.substr(fstQuote+1,scdQuote-fstQuote-1);
    }
    else{
      query[nQuery++][0] = "SHELVE";
    }
  }
}


void work(){
  sort(book,book+nBook);

  static int state[BOOK];
  for(int i=0;i<nBook;i++) state[i] = SHELVE;
  
  for(int i=0;i<nQuery;i++){
    if(query[i][0]=="SHELVE"){
      int last = -1;
      for(int j=0;j<nBook;j++)
        if(state[j]==TORETURN){
          cout << "Put " << '"'+book[j].second+'"';
          if(last==-1)
            cout << " first" << endl;
          else
            cout << " after " << '"'+book[last].second+'"' << endl;
          last = j;
          state[j] = SHELVE;
        }
        else if(state[j]==SHELVE)
          last = j;
      cout << "END" << endl;
    }
    else if(query[i][0]=="BORROW"){
      for(int j=0;j<nBook;j++)
        if(book[j].second==query[i][1])
          state[j] = BORROWED;
    }
    else if(query[i][0]=="RETURN"){
      for(int j=0;j<nBook;j++)
        if(book[j].second==query[i][1])
          state[j] = TORETURN;
    }
  }
}


int main(){
  read();
  work();
  return 0;
}
