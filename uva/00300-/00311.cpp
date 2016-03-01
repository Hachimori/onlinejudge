#include<iostream>
#include<assert.h>

class Info_packet{
 public:	
  
  int one;
  int two;
  int three;
  int four;
  int five;
  int six;

  Info_packet(){
    one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
  }

  Info_packet(int d1, int d2, int d3, int d4, int d5, int d6){
    one = d1, two = d2, three = d3, four = d4, five = d5, six = d6;
  }
  
}; 

int num_packet;
int num_box[7];

bool ckeck_box(){
  
  for(int i=1;i<7;i++){
    if(num_box[i]!=0) return false;
  }
  
  return true;

}

class Solver{
 public:
  
  bool read(){
    int d1, d2, d3, d4, d5, d6;
    
    cin >> d1 >> d2 >> d3 >> d4 >> d5 >> d6;
    if(d1==0 && d2==0 && d3==0 && d4==0 && d5==0 && d6==0 ) return false;

    num_box[1] = d1, num_box[2] = d2, num_box[3] = d3;
    num_box[4] = d4, num_box[5] = d5, num_box[6] = d6; 

    return true;
  }

  void work(){
   
    for(num_packet=0;ckeck_box()==false;num_packet++){

      Info_packet packet=Info_packet();

      if(num_box[6]>0){ 
	packet.six=1;
	num_box[6]--;
	continue;
      }

      if(num_box[5]>0){
	packet.five=1;
	num_box[5]--;
      }

      if(num_box[4]>0 && packet.five==0){
	packet.four=1;
	num_box[4]--;
      }

      if(num_box[3]>0 && packet.five==0 && packet.four==0){
	for(int i=0;num_box[3]>0 && i<4;num_box[3]--,i++){
	  packet.three++;
	}
      }

      if(num_box[2]>0 && packet.five==0){
	
	if(packet.four==1){
	  for(int i=0;num_box[2]>0 && i<5;num_box[2]--,i++){
	    packet.two++;
	  }
	}
	else if(packet.three>0){
	  if(packet.three==1){
	    for(int i=0;num_box[2]>0 && i<5;num_box[2]--,i++){
	      packet.two++;
	    }
	  }
	  else if(packet.three==2){
	    for(int i=0;num_box[2]>0 && i<3;num_box[2]--,i++){
	      packet.two++;
	    }
	  }
	  else if(packet.three==3){
	    packet.two++;
	    num_box[2]--;
	  }
	}
	else if(packet.four==0 && packet.three==0){
	  for(int i=0;num_box[2]>0 && i<9;num_box[2]--,i++){
	    packet.two++;
	  }
	}
	else assert(0);

      }

      if(num_box[1]>0){
	int limit = 36-packet.five*25-packet.four*16-packet.three*9-packet.two*4;
	if(limit<0) assert(0);
	
	for(int i=0;num_box[1]>0 && i<limit;num_box[1]--,i++){
	  packet.one++;
	}
      }

    }
    
    cout << num_packet << endl;

  }
  
};

main(){

  Solver solver;

  while(true){
    if(solver.read()==false) break;
    solver.work();
  }

}
