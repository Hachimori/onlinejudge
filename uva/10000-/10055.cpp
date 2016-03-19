#include<iostream>
#include<stdlib.h>

main()
{

  long long a,b;

  while(1){

    cin >> a >> b;

    if(cin.eof()) break;

    if(b-a>0) cout << b-a << endl;
    else cout << a-b << endl;

  }

}
