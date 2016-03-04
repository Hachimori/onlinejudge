#include<iostream>

main()
{

  long long A,limit,counter,tmp;

  for(int i=1;;i++){
    
    cin >> A >> limit;
    if(A==-1 && limit ==-1) break;

    tmp = A;

    for(counter=1;A<=limit && A!=1;counter++){
      
      if(A%2==0) A=A/2; 
      else A=A*3+1;
	
    }

    if(A>limit) counter--;

    cout << "Case " << i << ": A = " << tmp << ", limit = " << limit << ", number of terms = " << counter << endl;

  }


}
