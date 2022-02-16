#include <gtest/gtest.h>
#include <vector>
#include <stack>
#include "mymap.h"
#include "myrandom.h"

using namespace std;


 TEST(mymap, defaultConstructor) {
    

for(int i=0; i<30;i++){
  mymap<int,int> map;
    ASSERT_EQ(map.Size(), 0);
  mymap<int,string> maps;
    ASSERT_EQ(maps.Size(), 0);
  mymap<int,double> mapd;
    ASSERT_EQ(mapd.Size(), 0);
  mymap<int,float> mapf;
    ASSERT_EQ(mapf.Size(), 0);
   mymap<int,char> mapc;
    ASSERT_EQ(mapc.Size(), 0);
  
}
  
  
  
 }


TEST(mymap, putAndSize){
  
 mymap<int,int> map;

 int arr[] = {2, 1, 3};
for (int i = 0; i < 3; i++) {
map.put(arr[i], arr[i]);
}
  
   int arr9[] = {34,55,78,102,555,3333,2222,69303,44,3332};
  mymap<int,int> map9;
  for(int i =0;i<10;i++){
    
    map9.put(arr9[i], arr9[i]);
    EXPECT_EQ(map9.Size(), i+1);
  }
  
   mymap<int,int> map8;
  int arr8[] = {12, 8, 15, 4, 10, 14, 17, 2, 6, 9, 11, 13, 16, 18, 1, 3, 5, 7, 0};
  for(int i =0;i<19;i++){
    
    map8.put(arr8[i], arr8[i]);
    EXPECT_EQ(map8.Size(), i+1);
  }
  
   char arr7[] = {'a','k','s','r','m', 'j','d', 'l', 'o', 'p','b','e','f','c'};
  mymap<int,char> map7;
  for(int i =0;i<14;i++){
    
    map7.put(i, arr7[i]);
     EXPECT_EQ(map7.Size(), i+1);

  }  
 
  EXPECT_EQ(map9.Size(), 10);
EXPECT_EQ(map.Size(), 3);
  
mymap<int,string> maps;

string arrs[] = {"apple", "orange"};
for (int i = 0; i < 2; i++) {
maps.put(i, arrs[i]);
}
EXPECT_EQ(maps.Size(), 2);
  
  
  
 }


TEST(mymap, containsAndGet){
  
 mymap<int,int> map;

 int arr[] = {2, 1, 3};
for (int i = 0; i < 3; i++) {
   map.put(arr[i], arr[i]);
   EXPECT_TRUE(map.contains(arr[i]));
   EXPECT_EQ(map.get(arr[i]), arr[i]);
  
}
    
  
   int arr9[] = {34,55,78,102,555,3333,2222,69303,44,3332};
  mymap<int,int> map9;
  for(int i =0;i<10;i++){
    
    map9.put(arr9[i], arr9[i]);
     EXPECT_TRUE(map9.contains(arr9[i]));
   EXPECT_EQ(map9.get(arr9[i]), arr9[i]);
  }
  
   mymap<int,int> map8;
  int arr8[] = {12, 8, 15, 4, 10, 14, 17, 2, 6, 9, 11, 13, 16, 18, 1, 3, 5, 7, 0};
  for(int i =0;i<19;i++){
    
    map8.put(arr8[i], arr8[i]);
     EXPECT_TRUE(map8.contains(arr8[i]));
   EXPECT_EQ(map8.get(arr8[i]), arr8[i]);
  }
  
   char arr7[] = {'a','k','s','r','m', 'j','d', 'l', 'o', 'p','b','e','f','c'};
  mymap<int,char> map7;
  for(int i =0;i<14;i++){
    
    map7.put(i, arr7[i]);
     EXPECT_TRUE(map7.contains(i));
   EXPECT_EQ(map7.get(i), arr7[i]);

  }
}




TEST(mymap,  Brackets){
  
 mymap<int,int> map;

 int arr[] = {2, 1, 3};
for (int i = 0; i < 3; i++) {
   map.put(arr[i], arr[i]);
   EXPECT_EQ(map[(arr[i])], arr[i]);
  
}
    
  
   int arr9[] = {34,55,78,102,555,3333,2222,69303,44,3332};
  mymap<int,int> map9;
  for(int i =0;i<10;i++){
    
    map9.put(arr9[i], arr9[i]);
   
   EXPECT_EQ(map9[(arr9[i])], arr9[i]);
  }
  
   mymap<int,int> map8;
  int arr8[] = {12, 8, 15, 4, 10, 14, 17, 2, 6, 9, 11, 13, 16, 18, 1, 3, 5, 7, 0};
  for(int i =0;i<19;i++){
    
    map8.put(arr8[i], arr8[i]);
     EXPECT_TRUE(map8.contains(arr8[i]));
   EXPECT_EQ(map8[(arr8[i])], arr8[i]);
  }
  
   char arr7[] = {'a','k','s','r','m', 'j','d', 'l', 'o', 'p','b','e','f','c'};
  mymap<int,char> map7;
  for(int i =0;i<14;i++){
    
    map7.put(i, arr7[i]);
     EXPECT_TRUE(map7.contains(i));
   EXPECT_EQ(map7[i], arr7[i]);

   }
}


TEST(mymap,copyConstructor2){ // test copyConstructor
  mymap<int, int> map;
  int arr[] = {12, 8, 15, 4, 10, 14, 17, 2, 6, 9, 11, 13, 16, 18, 1, 3, 5, 7, 0};
  for (int i = 0; i < 19; i++) {
		map.put(arr[i], arr[i]);
  }
	mymap<int, int> mapCopy = map;
	EXPECT_EQ(mapCopy.toString(), map.toString());
	for (int i = 0; i < 19; i++) {
		EXPECT_EQ(mapCopy.get(arr[i]), map.get(arr[i]));
  }
	EXPECT_EQ(mapCopy.toString(), map.toString());
}





// only can pass with //balanceNode
// TEST(mymap, Milestone1_Everything) {
//     // test to compare with C++ map
//     mymap<int, int> mapMine;
//     map<int,int> mapSol;
//     int n = 10000;  // # of elements inserted

//     // fill up BOTH maps
//     for (int i = 1; i <= n; i++) {
//         int key = randomInteger(0,10000);  // given
//         int val = randomInteger(0,10000);

//         mapMine.put(key, val);
//         mapSol[key] = val;
//     }
//     // 1. Assert sizes are equal
//     EXPECT_EQ(mapMine.Size(), mapSol.size());
//     // 2. String test (order is correct)
//     stringstream solution("");
//     // Fill string stream with mapSol
//     for (auto e : mapSol) {
//         solution << "key: " << e.first;
//         solution << " value: " << e.second << endl;
// 	 // 3. Test map contents
//         EXPECT_TRUE(mapMine.contains(e.first));
//          EXPECT_EQ(mapMine.get(e.first), e.second);
//      }
//      EXPECT_EQ(mapMine.toString(), solution.str());
// }






TEST(mymap,stringstream) {
   mymap<int, int> test;
   stringstream dump("");
   int n = 10;
   // add some values:
   for(int i = n; i > 0; i--)
   {
	// put values
	  test.put(i, i);
   }
	// build stringstream:
     for(int i = 1; i <= n; i++){
    dump << "key: " << i<< " " << "value: " << i << "\n";
     }
  cout << "======" << endl; 
  // test toString output
   cout << dump.str() << endl;
   cout << "---------" << endl;
   cout << test.toString() <<endl;
   
   ASSERT_EQ(dump.str(), test.toString());
}

TEST(mymap, streeTesting) {
   // from project pdf:
   mymap<int, int> test;
   map<int, int> correct;
   int seed = 1000000;
   for(int i = 0; i < 10000;
   i++) {
	// randomize key and val
    int k = randomInteger(0,seed);
    int v = randomInteger(0,seed);
    test.put(k, v);
    correct[k] = v;
   }
   EXPECT_EQ(test.Size(),correct.size());
   // after this point test
   // test inserts and string
   // like in first 2 tests
}






TEST(mymap, contains){
  
  mymap<int,string> maps;

string arrs[] = {"apple", "orange"};
for (int i = 0; i < 2; i++) {
maps.put(i, arrs[i]);
  
}
  
   mymap<int,int> map;

 int arr[] = {2, 1, 3};
for (int i = 0; i < 3; i++) {
 
map.put(i, arr[i]);

}
   
  for (int i = 0; i < 3; i++){

   
  EXPECT_EQ(map.contains(2), true);
   
}
  
for (int i = 0; i < 2; i++){
  EXPECT_EQ(maps.contains(i), true);
}
  EXPECT_EQ(maps.contains(1), true);
 

   EXPECT_EQ(maps.contains(5),false);
  
  
  
  
     mymap<int,int> map1;

 int arr1[] = {2, 1, 3,10,5,9,4};
for (int i = 0; i <7 ; i++) {
 
map1.put(i, arr1[i]);

}
  
  for (int i = 0; i <7 ; i++) {
 
   EXPECT_EQ(map1.contains(i), true);

}
  
  
}



TEST(mymap,get){
  mymap<int,int> map;
  int arr[] = {2, 1, 3};
  for(int i = 0; i < 3; i++) {
  map.put(arr[i], arr[i]);
  }
  
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(map.get(arr[i]), arr[i]);
    EXPECT_EQ(map.Size(), 3);
  }
}

TEST(mymap, toString){
  mymap<int,int> map;
  int arr[] = {2, 1, 3};
  for(int i = 0; i < 3; i++) {
  map.put(arr[i], arr[i]);
  }
  string sol = "key: 1 value: 1\nkey: 2 value: 2\nkey: 3 value: 3\n";
  cout<<map.toString();
 EXPECT_EQ(sol, map.toString());
}



TEST(mymap,ioperator){
  
   mymap<int,int> map;
  int arr[] = {2, 1, 3};
  
  for(int i = 0; i < 3; i++) {
    map.put(arr[i], arr[i]);
  }
  
  for (int i = 0; i < 3; i++) {
  EXPECT_EQ(map[arr[i]], arr[i]);
  EXPECT_EQ(map.Size(), 3);
}
     map[5];
  EXPECT_EQ(map.Size(),4);
   map[10];
  EXPECT_EQ(map.Size(),5);
 
  
  
}




TEST(mymap,access) {
   mymap<int, int> testMe;
   map<int, int> correct;
   testMe.put(10, 50);
   correct.emplace(
pair<int, int>(10, 50));
   // check if key exists:
   EXPECT_EQ(true,
      testMe.contains(10));
   // check the values:
   EXPECT_EQ(testMe.get(10),
correct[10]);
   EXPECT_EQ(testMe[10],
correct[10]);
  // try to make this test
  // repetitive using loops
}

//************************
TEST(mymap, begin){
   mymap<int, int> map;
  int arr[] = {2, 1, 3, 5, 10, 22};
  int order[] = {1, 2, 3, 5, 10, 22};
  for (int i = 0; i < 3; i++) {
  map.put(arr[i], arr[i]);
  }
  int i = 0;
  for (auto key : map) {
    EXPECT_EQ(order[i++], key);
  }
}



// only can pass with //balanceNode
// TEST(mymap,MS3){

// mymap<int, int> test;
//    map<int, int> correct;
//    int seed = 1000000;
//    for(int i = 0; i < 30; i++) {
// 	// randomize key and val
// 	int k = randomInteger(0,seed);
// 	int v = randomInteger(0,seed);
// 	test.put(k, v);
// 	correct[k] = v;
//    }
//    stringstream ss;

//    for (int key : test) {
//       // it does work like this
//       ss << "key: " << key << " value: " << test[key] << endl;
//    }
  
//   // loop should be in order
//   ASSERT_EQ(test.toString(), ss.str());


// }

TEST(mymap,clear){
  mymap<int, int> map;
  int arr[] = {2, 1, 3, 5, 22};
  for (int i = 0; i < 5; i++) {
  map.put(arr[i], arr[i]);
  }
  map.clear();
EXPECT_EQ(map.Size(), 0);
}

TEST(mymap,clear2){
  mymap<int,int> m;
  for (int i=0;i<1000;i++) {
    int x = randomInteger(0,10000);
    m.put(x, x);
    EXPECT_NE(m.Size(), 0);
  }
  m.clear();
  ASSERT_EQ(m.Size(), 0);


}

TEST(mymap,clear3){ // test clear
  mymap<int, int> map;
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
	int correct[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
  for (int i = 0; i < 3; i++) {
  map.put(arr[i], arr[i]);
  }
  int i = 0;
  for (auto key : map) {
    EXPECT_EQ(correct[i++], key);

	}
  map.clear();
	EXPECT_EQ(map.Size(), 0);
}


TEST(mymap, forloop){ // test forloop for iterator
   mymap<int, int> map;
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
	int begin[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
  for (int i = 0; i < 100; i++) {
		map.put(arr[i], begin[i]);
  }
  int i = 0;
  for (auto key : map) {
    EXPECT_EQ(begin[i++], key);
  }
}


TEST(mymap, begin2){ // test forloop for iterator
   mymap<int, int> map;
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
	int correct[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
  for (int i = 0; i < 3; i++) {
  map.put(arr[i], arr[i]);
  }
  int i = 0;
  for (auto key : map) {
    EXPECT_EQ(correct[i++], key);

	}

}

TEST(mymap,copy){
  mymap<int, int> map;
  int arr[] = {2, 1, 3, 5, 22};
  for (int i = 0; i < 5; i++) {
  map.put(arr[i], arr[i]);
  }
  cout<<"before: \n"<<map.toString()<<"size: "<<map.Size()<<endl;
mymap<int, int> mapCopy;
  
mapCopy = map;

   cout<<"after: \n"<<mapCopy.toString()<<"size: "<<mapCopy.Size()<<endl;
}

TEST(mymap,copy2) {
  mymap<int,int> m1;
  for (int i=0;i<1000;i++) {
    int x = randomInteger(0,10000);
    m1.put(x, x);
  }
  mymap<int,int> m2 = m1;
  ASSERT_EQ(m2.Size(), m1.Size());
  ASSERT_EQ(
    m2.toString(),
    m1.toString());
}


TEST(mymap,copyConstructor){
  mymap<int, int> map;
  int arr[] = {2, 1, 3, 5, 22,11};
  for (int i = 0; i < 6; i++) {
  map.put(arr[i], arr[i]);
  }
  cout<<"before: \n"<<map.toString()<<"size: "<<map.Size()<<endl;
mymap<int, int> mapCopy = map;

   cout<<"after: \n"<<mapCopy.toString()<<"size: "<<mapCopy.Size()<<endl;
}

TEST(mymap,toVector){
      // test to compare with C++ map
    mymap<int, int> mapMine;
    vector<pair<int, int> > solution;
    int n = 5;  // # of elements inserted

    // fill up BOTH maps
    for (int i = 1; i <= n; i++) {
        int key = randomInteger(0,10000);  // given
        int val = randomInteger(0,10000);

        mapMine.put(key, val);
      solution.push_back(make_pair(key,val));
  
      
    }
   sort(solution.begin(), solution.end());
  for(auto i: solution){
   cout<<"key: "<<i.first<<"Val: "<<i.second<<endl;
  }
  
  vector<pair<int, int> > nV=mapMine.toVector();
    for(auto i: nV){
   cout<<"key: "<<i.first<<"Val: "<<i.second<<endl;
  }
  EXPECT_EQ(solution, mapMine.toVector());
  
  
}

TEST(mymap, checkBalance){
  
mymap<int, int> map;
int arr[] = {2, 1, 3};
for (int i = 0; i < 3; i++) {
map.put(arr[i], arr[i]);
}
string sol = "key: 2, nL: 1, nR: 1\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\n";
EXPECT_EQ(map.checkBalance(), sol);
  
  
}

 TEST(mymap, checkBalance1){
  
mymap<int, int> map;
int arr[] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

  for (int i = 0; i <9; i++) {
    map.put(arr[i], arr[i]);
  }
   

  
    cout<<map.toString()<<endl;
  

  cout<<map.checkBalance();

  
  
}


 TEST(mymap, MS5){
   mymap<string, string> map;
   string arr[]={"peach","mango","orange","coconut","grapefruit","lemon","berry","banana","kiwi"};
   
     for (int i = 0; i <9; i++) {
    map.put(arr[i], arr[i]);
  }
   
     cout<<map.toString()<<endl;
  

  cout<<map.checkBalance();
   
   
   
 }

TEST (mymap, basicTest11M5){
  mymap<int,int> m;
  vector<pair<int,int>> v;
  string s = "";
 int arr[] = {10,7,8,5,2,17,34,55,78,102,555,3333,2222,69303,44,3332,5679,17};
//  int arr[] = {34,55,78,102,555,3333,2222,69303,44,3332};
// 12, 8, 15, 4, 10, 14, 17, 2, 6, 9, 11,  13, 16, 18, 1, 3, 5, 7
// int arr[] = {1, 12, 4, 8, 13, 7};
  // int arr[] = {12, 8, 15, 4, 10, 14, 17, 2, 6, 9, 11, 13, 16, 18, 1, 3, 5, 7, 0};
//   char arr[] = {'a','k','s','r','m', 'j', 'l', 'o', 'p'};
  for (int i=0;i<19;i++) {
    m.put(arr[i], arr[i]);
   v.push_back(make_pair(arr[i],arr[i]));
  }
  mymap<int, int> mapCopy = m;
 ASSERT_EQ(mapCopy.Size(), m.Size());
 ASSERT_EQ(mapCopy.toString(), m.toString());


}




