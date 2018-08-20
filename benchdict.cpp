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
// this file is the used to test benchamark functions for dictionary 
// that we implement in DictionartBST, DictionaryHashTable, DictionaryTrie
// calculate the the time to find for elements and number of elements
// this functioin take four arguments

#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>

using std::vector;
using std::ostream;
using std::ifstream;
using std::string;
using std::find;
using std::endl;
using std::cout;
/*
 * this is the main function that will run those three dictionaries
 * this main method took four arguments
 * argv[1] = minimun size 
 * argv[2] = the step size
 * argv[3] = number of iteration
 * argv[4] = the dictionary file
 * output the result in a table format with number of words on left
 * and time in nanoseconds on the right
 */
int main(int argc, char* argv[])
{
  // to clear magic number 
  int input = 5;
  int arg_one = 1;
  int arg_two = 2;
  int arg_three = 3;
  int arg_four = 4;
  // number of iteration 
  int repeat = 50;
  //number if words
  int num_word = 100;
  //check the argumnets are legal
  if(argc != input){
    std::cout << "wrong number of input argument." << endl;
    return -1;
  }
  //get the value of arguments 
  int min_size = atoi(argv[arg_one]);
  int step_size = atoi(argv[arg_two]);
  int num_iterations = atoi(argv[arg_three]);
  long long total_time = 0;
  long long average = 0;
  std::string check = "";
  //the file stream to read from dictionary
  std::ifstream dictFile;

  Timer t;
  Utils utils;
  //first we test the bst dictionary
  std::cout << "DictionaryBST is benchmarking" << endl;
  for (int c = 0; c < num_iterations; c++) {
    dictFile.open(argv[arg_four]);
    //check the readin file is legal
    if(!dictFile.is_open()){
      cout << "Invalid input file! \n";
      dictFile.close();
      return -1;
    }
    //create a new BST and a string vector 
    DictionaryBST *lexiconBst = new DictionaryBST();
    vector<string> *words = new vector<string>();
    for (int i = 0; i < min_size + (c * step_size) + num_word; i++) {
        getline(dictFile, check);
        if (dictFile.eof()) {
	    //this is where we handle the edge case
	    //if there are not enough words to read
	    //both for bst or the 100 words vector
            std::cout << "Warning! Not enough words! Only " << 
                           i << " words read from file." << endl;
            return -1;
        }
    }
    //reset the pointer of the file stream
    dictFile.close();
    dictFile.open(argv[arg_four]);
    if(!dictFile.is_open()){
      //check for input is legal again when we read again
      cout << "Invalid input file! \n";
      dictFile.close();
      return -1;
    }
    //call the util load dict helper method   
    utils.load_dict(*lexiconBst, dictFile, (min_size + (c * step_size)));

    

    utils.load_vector(*words, dictFile, num_word);
    //start calculating the time
    for(int i = 0; i < repeat; i++){
      t.begin_timer();
      for (string w : *words) {
        lexiconBst->find(w);
      }
      long long time = t.end_timer();
      total_time += time;
    }
    //solve for the average time used for 50 literation
    average = (total_time / repeat);
    cout << min_size + (c * step_size) << "\t" << average << endl;
    //reset total time and average
    total_time = 0;
    average = 0;
    //delete the the pointer prevent from memory leak
    delete lexiconBst;
    delete words;
    dictFile.close();
  }
  //Second is the hash table dictionary
  std::cout << "DictionaryHashTable is benchmarking" << endl;
  for (int j = 0; j < num_iterations; j++) {
    dictFile.open(argv[arg_four]);
    if(!dictFile.is_open()){
      //check the readin file is legal
      cout << "Invalid input file! \n";
      dictFile.close();
      return -1;
    }
    //create a new hash table to output the result
    DictionaryHashtable *lexiconHt = new DictionaryHashtable();
    vector<string> *words = new vector<string>();
    //this is checking for the edge case mentioned
    for (int i = 0; i < min_size + (j * step_size); i++) {
        getline(dictFile, check);
        if (dictFile.eof()) {
            std::cout << "Warning! Not enough words! Only " << 
                           i << " words read from file." << endl;
            return -1;
        }
    }
    //reset the ifstream pointer to the beginning
    dictFile.close();
    dictFile.open(argv[arg_four]);
    if(!dictFile.is_open()){
      //check for the stream legality 
      cout << "Invalid input file! \n";
      dictFile.close();
      return -1;
    }
    //call the util helper functions
    utils.load_dict(*lexiconHt, dictFile, min_size + (j * step_size));

    utils.load_vector(*words, dictFile, num_word);
    //calculate the average time used 
    for(int i = 0; i < repeat; i++){
      t.begin_timer();
      for (string w : *words) {
        lexiconHt->find(w);
      }
      long long time = t.end_timer();
      total_time += time;
    }
    average = (total_time / repeat);
    //output them in the table format
    cout << min_size + (j * step_size) << "\t" << average << endl;
    //reset the time and average value
    total_time = 0;
    average = 0;
    //delete the to prevent from memory leak
    delete lexiconHt;
    delete words;
    dictFile.close();
  }

  //last one is the MWT dictionary
  std::cout << "DictionaryTrie is benchmarking" << endl;
  for (int k = 0; k < num_iterations; k++) {
    dictFile.open(argv[arg_four]);
    //check for the dictionary file is legal or not
    if(!dictFile.is_open()){
      cout << "Invalid input file! \n";
      dictFile.close();
      return -1;
    }
    //create a new tries
    DictionaryTrie *lexiconTrie = new DictionaryTrie();
    vector<string> *words = new vector<string>();
    //handle the edge case mentioned by the write up
    for (int i = 0; i < min_size + (k * step_size); i++) {
        getline(dictFile, check);
        if (dictFile.eof()) {
            std::cout << "Warning! Not enough words! Only " << 
                           i << " words read from file." << endl;
            return -1;
        }
    }
    //reset the ifstream pointer to the beginning by close and open it
    dictFile.close();
    dictFile.open(argv[arg_four]);  
    if(!dictFile.is_open()){
      cout << "Invalid input file! \n";
      dictFile.close();
      return -1;
    }
    //call the util helper method
    utils.load_dict(*lexiconTrie, dictFile, min_size + (k * step_size));
    utils.load_vector(*words, dictFile, num_word);
    //calcuate the average time used
    for(int i = 0; i < repeat; i++){
      t.begin_timer();
      for (string w : *words) {
        lexiconTrie->find(w);
      }
      long long time = t.end_timer();
      total_time += time;
    }
    //output the time and the words number in table format
    average = (total_time / repeat);
    cout << min_size + (k * step_size) << "\t" << average << endl;
    //reset totoal time and average for next call
    total_time = 0;
    average = 0;
    //delete the vector prevent from memoty leak
    delete lexiconTrie;
    delete words; 
    dictFile.close();
  }
  return 0; 
}
