#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>



//#include "Row.hpp"



void printRow(const long val){
  std::cout << "    |";
   for(int pos=24; pos > -1; pos--){
     if( ((val >> pos) & 1 ) == 1 ){
     std::cout << "*" << '|';
      }
     else { std::cout << " " << '|' ; }
   }

  std::cout << '\n';
}

void printHash(const std::vector<int> hash){

  std::cout <<" Hash : [" ;
  for(size_t pos=0; pos < hash.size(); pos++){

    std::cout<< hash[pos] << " " ;
  }
  std::cout << "]" << '\n';
}









std::vector<int> findHash(const long val){

  std::vector<int> result;
  long inter = val;
  int this_count = 0;

  for(int pos=24; pos > -1; pos--){

    if( ((val >> pos) & 1) == 1){
      this_count++;
    }
    else if(this_count !=0) {
      result.push_back(this_count);
      this_count = 0;
    }
  }
  if(this_count != 0 ){result.push_back(this_count);}
  return result;
}


//Function minSearch
long minSearch(const std::vector<int> hash){
  long init =  0;
  int stepper = 0;

  for(int pos = hash.size() - 1; pos > -1; pos--){
    for( int counter = 0; counter < hash[pos]; counter++){
      init =  (1 << stepper) | init ; 
      stepper++; }

    stepper++;
  }

  return init;
}


//Function maxSearch
long maxSearch(const std::vector<int> hash){
  long init = 0;
  int stepper = 24;

  for(int pos = 0; pos < hash.size(); pos++){
      for( int counter = 0; counter < hash[pos]; counter++){
	init  = (1 << stepper) | init ;
	stepper--;
      }
      stepper--;
    }
	return init;

  }


  //Functino getBit
  int getBit(const long val, const int index){
    long inter = val;    
    inter = inter >> index;
    return (inter & 1);
  }



  //Function get number of set bits in long
  int getLongBits(const long value){
    
    long  i = value;
    i = i - ((i >> 1) & 0x5555555555555555);
    i = (i & 0x3333333333333333) + ((i >> 2) & 0x3333333333333333);
    return (((i + (i >> 4)) & 0xF0F0F0F0F0F0F0F) * 0x101010101010101) >> 56;
  }
 

  //std::vector<Row> bruteRows(const std::vector<int> hash){

  //int totalPings = std::sum(hash.begin(), hash.end(), 0);


  //int minSearch = 


//Cull The possibilities based on 
void Cull(std::vector<long>& RowList, long Gun){

  auto cullit = [&] (long b){

    for(int i=0; i < 25; i++){
      if( (Gun >> i) == 1){
	if( (b >> i) == 1){return true;}
	else {return false;}
      }
      else {return true;}
    }
  };

  auto iter(std::remove_if( RowList.begin(), RowList.end(), cullit));
  RowList.erase(iter, RowList.end());
}



std::vector<long> FindRowPoss(int min, int max, std::vector<int> myHash){
      
  std::vector<int> tempHash;
      std::vector<long> ThisRowPoss;
      int sumInHash = std::accumulate(myHash.begin(), myHash.end(), 0 ); 
      int match = 0;
			      
for(long rower=long(min); rower < long(max); rower++){
  
    if(getLongBits(rower) == sumInHash){
      
      //std::cout << rower << '\n';
      tempHash = findHash(rower);
      
      if(tempHash.size() == myHash.size()){

	match = 0;
	for(size_t temppos=0; temppos < myHash.size(); temppos++){
	  if (tempHash[temppos] != myHash[temppos]){

	    match++;}
	}
	if (match == 0){

     
	  //if(std::equal(myHash.begin(),myHash.end(),tempHash.begin())){

	  // std::cout << rower << '\n';

	  // printHash(tempHash);
	  //  printRow(rower);
	  ThisRowPoss.push_back(rower);
	  match = 0;
	}
     
	}
      }
    
 }

 return ThisRowPoss;

}







int main(int argc, char *argv[]){


  std::vector<std::vector<long> > AllRowPoss;
  std::vector<long> ThisRowPoss;

  std::vector<std::vector<int> > hashCollection;

  int row1[] = {7,3,1,1,7}; std::vector<int> vrow1 (row1, row1 + sizeof(row1) / sizeof(int) ); hashCollection.push_back(vrow1);
  int row2[] = {1,1,2,2,1,1}; std::vector<int> vrow2 (row2, row2 + sizeof(row2) / sizeof(int) ); hashCollection.push_back(vrow2);
  int row3[] = {1,3,1,3,1,1,3,1}; std::vector<int> vrow3 (row3, row3 + sizeof(row3) / sizeof(int) ); hashCollection.push_back(vrow3);
  int row4[] = {1,3,1,1,6,1,3,1}; std::vector<int> vrow4 (row4, row4 + sizeof(row4) / sizeof(int) ); hashCollection.push_back(vrow4);
  int row5[] = {1,3,1,5,2,1,3,1}; std::vector<int> vrow5 (row5, row5 + sizeof(row5) / sizeof(int) ); hashCollection.push_back(vrow5);
  int row6[] = {1,1,2,1,1}; std::vector<int> vrow6 (row6, row6 + sizeof(row6) / sizeof(int) ); hashCollection.push_back(vrow6);
  int row7[] = {7,1,1,1,1,1,7}; std::vector<int> vrow7 (row7, row7 + sizeof(row7) / sizeof(int) ); hashCollection.push_back(vrow7);
  int row8[] = {3,3}; std::vector<int> vrow8 (row8, row8 + sizeof(row8) / sizeof(int) ); hashCollection.push_back(vrow8);
  int row9[] = {1,2,3,1,1,3,1,1,2}; std::vector<int> vrow9 (row9, row9 + sizeof(row9) / sizeof(int) ); hashCollection.push_back(vrow9);
  int row10[] = {1,1,3,2,1,1}; std::vector<int> vrow10 (row10, row10 + sizeof(row10) / sizeof(int) ); hashCollection.push_back(vrow10);
  int row11[] = {4,1,4,2,1,2}; std::vector<int> vrow11 (row11, row11 + sizeof(row11) / sizeof(int) ); hashCollection.push_back(vrow11);
  int row12[] = {1,1,1,1,1,4,1,3}; std::vector<int> vrow12 (row12, row12 + sizeof(row12) / sizeof(int) ); hashCollection.push_back(vrow12);
  int row13[] = {2,1,1,1,2,5}; std::vector<int> vrow13 (row13, row13 + sizeof(row13) / sizeof(int) ); hashCollection.push_back(vrow13);
  int row14[] = {3,2,2,6,3,1}; std::vector<int> vrow14 (row14, row14 + sizeof(row14) / sizeof(int) ); hashCollection.push_back(vrow14);
  int row15[] = {1,9,1,1,2,1}; std::vector<int> vrow15 (row15, row15 + sizeof(row15) / sizeof(int) ); hashCollection.push_back(vrow15);
  int row16[] = {2,1,2,2,3,1}; std::vector<int> vrow16 (row16, row16 + sizeof(row16) / sizeof(int) ); hashCollection.push_back(vrow16);
  int row17[] = {3,1,1,1,1,5,1}; std::vector<int> vrow17 (row17, row17 + sizeof(row17) / sizeof(int) ); hashCollection.push_back(vrow17);
  int row18[] = {1,2,2,5}; std::vector<int> vrow18 (row18, row18 + sizeof(row18) / sizeof(int) ); hashCollection.push_back(vrow18);
  int row19[] = {7,1,2,1,1,1,3}; std::vector<int> vrow19 (row19, row19 + sizeof(row19) / sizeof(int) ); hashCollection.push_back(vrow19);
  int row20[] = {1,1,2,1,2,2,1}; std::vector<int> vrow20 (row20, row20 + sizeof(row20) / sizeof(int) ); hashCollection.push_back(vrow20);
  int row21[] = {1,3,1,4,5,1}; std::vector<int> vrow21 (row21, row21 + sizeof(row21) / sizeof(int) ); hashCollection.push_back(vrow21);
  int row22[] = {1,3,1,3,10,2}; std::vector<int> vrow22 (row22, row22 + sizeof(row22) / sizeof(int) ); hashCollection.push_back(vrow22);
  int row23[] = {1,3,1,1,6,6}; std::vector<int> vrow23 (row23, row23 + sizeof(row23) / sizeof(int) ); hashCollection.push_back(vrow23);
  int row24[] = {1,1,2,1,1,2}; std::vector<int> vrow24 (row24, row24 + sizeof(row24) / sizeof(int) ); hashCollection.push_back(vrow24);
  int row25[] = {7,2,1,2,5}; std::vector<int> vrow25 (row25, row25 + sizeof(row25) / sizeof(int) ); hashCollection.push_back(vrow25);











  std::vector<int> myHash = vrow4;
  int min = minSearch(myHash);
  int max = maxSearch(myHash) + 1;
  min = 0;
  max = 33554430;

  std::cout << "min: "<<min <<"   max:  "<<max<< '\n';
  std::cout << "diff: "<<(max-min) << '\n';


  int count3 = getLongBits(long(10));
  int count255 = getLongBits(long(11));

  std::cout <<" counters :   " << count3 << "   "<<count255 << '\n';

  std::cout << getBit(long(3),0) << getBit(long(4),0) << '\n';

  int numresults = 0;

  printRow(long(33412601));
  printRow(long(33412602));

  std::cout << "asdhaihd" << '\n' ;
  printHash( findHash(long(16706302)));
  std::cout << "dhalds" << '\n' ;
  
  for(size_t Rowpos = 0; Rowpos <  hashCollection.size() ; Rowpos++){
    ThisRowPoss = FindRowPoss(min,max,hashCollection[Rowpos]);
    
    if(Rowpos == size_t(3)){Cull(ThisRowPoss, long(31518800));}
    if(Rowpos == size_t(8)){Cull(ThisRowPoss, long(4112000));}
    if(Rowpos == size_t(16)){Cull(ThisRowPoss, long(270608));}
    if(Rowpos == size_t(21)){Cull(ThisRowPoss, long(3195416));}
    
    AllRowPoss.push_back(ThisRowPoss);
    std::cout << "Number of possibilities for Row "<<Rowpos+1 <<" : " << ThisRowPoss.size() << '\n' ;
   }
  
  std::cout << "Here you go" << '\n';
  //printRow(AllRowPoss[3][0]);
  //printRow(AllRowPoss[4][0]);

  /*
  for(size_t mooberries = 0; mooberries < AllRowPoss[0].size(); mooberries++){
    printRow(AllRowPoss[0][mooberries]);
    printHash(findHash(AllRowPoss[0][mooberries]));
    } */
  
}
