/**
 * Partner1:
 * Name: Jiaqi Fan
 * PID: A12584051
 * Partner2:
 * Name: Xuanru Zhu
 * PID: A91064234
 * Date: 2/7/2017
 * PA2
 */
// this file is the used to test hash functions that we found online
// also calculate the the number of hits and
// this functioin take 2 arguments


#include"util.h"
#include <iomanip>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

/*
 * the two hash function for strings that we found online are from
 * http://stackoverflow.com/questions/8317508/hash-function-for-a-string
 * those two functions were modified to best fit in my main
 */
int hashFunction1(string word, int tablesize){
  int sum = 0;
  for(unsigned int k = 0; k < word.length(); k++){
      sum = sum + int(word[k]);
  }
  return  sum % tablesize;
}

int hashFunction2(string word, int tablesize){
  int seed = 131;
  unsigned long hash = 0;
  for(unsigned int i = 0; i < word.length(); i++){
    hash = (hash * seed) + word[i];
  }
  return hash % tablesize;
}


/*
 * this is the main function that take 2 arugments
 * argv[1] is the txt file contain words
 * argv[2] is the table size
 */
int main(int argc, char* argv[]){
  std::ifstream input;
  int double_size = 2;
  int num_of_word = 0;
  input.open(argv[1]); //read the txt file
  if(!input.is_open()){
    cout << "Invalid input file! \n";
    input.close();
    return -1;
  }
  Utils utils;
  //read the input tablesize
  int tablesize = double_size * atoi(argv[double_size]);
  num_of_word = atoi(argv[double_size]);
  vector<string> words;
  utils.load_vector(words, input, num_of_word);
  //start testing the Hashfunction1
  vector<int> count1(tablesize, 0); //create the table
  input.close();
  auto iterator1 = words.begin();
  for(; iterator1 != words.end(); ++iterator1){
    //find the hash key by calling the hashfuncton1
    int hashcode1 = hashFunction1(*iterator1, tablesize);
    count1[hashcode1]++;
  }
  //get the worse case for finding the element
  int worsecase = *max_element(count1.begin(), count1.end());
  double average = 0.0;
  vector<int> temp(worsecase + 1, 0);
  for(unsigned int i = 0; i < count1.size(); i++) {
    temp[count1[i]]++;
    if(count1[i] != 0){
      //solve for the average step taken
      average += (double)((1 + count1[i]) * count1[i] / 2);
    }
  }
  //output the tablesize and number of words and print the table header
  cout << "Printing the statistics for hashFunction1 with hash table size "
       << tablesize << endl;
  cout << left << setw(8) << "#hits";
  cout << "#slots receiving the #hits" << endl;
  //print the results of number hit and slots in table format
  for(unsigned int i = 0; i < temp.size(); i++) {
    if(temp[i] != 0){
      cout << setw(8) << i;
      cout << temp[i] << endl;
    }
  }
  //print out the result
  cout << "The average number of steps for a successful search for hash function 1 would be "
  << (average / (double)num_of_word) << endl;
  cout << "The worst case steps that would be needed to find a word is " 
       << worsecase << endl;

  
  //start testing the Hashfunction2
  vector<int> count2(tablesize, 0); //create the table
  auto iterator2 = words.begin();
  for(; iterator2 != words.end(); ++iterator2){
    //find the hash key for the words by calling hash functuon 2
    int hashcode2 = hashFunction2(*iterator2, tablesize);
    count2[hashcode2]++;
  }
  //get the worse case for finding the element
  int worsecase2 = *max_element(count2.begin(), count2.end());
  double average2 = 0.0;
  vector<int> temp2(worsecase2 + 1, 0);
  for(unsigned int j = 0; j < count2.size(); j++) {
    temp2[count2[j]]++;
    if(count2[j] != 0){
      //calculate the average
      average2 += (double)((1 + count2[j]) * count2[j] / 2);
    }
  }
  ////output the tablesize and number of words and print the table header
  cout << "Printing the statistics for hashFunction2 with hash table size " 
       << tablesize << endl;
  cout << left << setw(8) << "#hits";
  cout << "#slots receiving the #hits" << endl;
  //print the results of #hits and slots in table format
  for(unsigned int j = 0; j < temp2.size(); j++) {
    if(temp2[j] != 0){
      cout << setw(8) << j;
      cout << temp2[j] << endl;
    }
  }
  //print out the result
  cout << "The average number of steps for a successful search for hash function 2 would be "
  << (average2 / (double)tablesize) << endl;
  cout << "The worst case steps that would be needed to find a word is " << worsecase2 << endl; 
  return 0;
}
