/**
  * Partner1:
  * Name: Jiaqi Fan
  * PID: A12584051
  * Partner2:
  * Name: Xuanru Zhu
  * PID: A91064234
  * Date: 1/26/2017
  * PA2
  */
// this file holdes all the tests for all three data scrutures, BST, Hasp, Tries
// test the method insert and find. with many edge cases

#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#define LETTERS 26
using namespace std;


int main(int argc, char** argv)
{

  //Initialize words
  vector<std::string> words;
  //add a new vector for test
  vector<std::string> words2;
  vector<std::string> words3;
  vector<string>::iterator wit;
  vector<string>::iterator wen;
  //initialize nonwords
  set<string> nope;
  set<string>::iterator nit;
  set<string>::iterator nen;

  //Initialize data structures
  DictionaryBST d_bst;
  DictionaryHashtable d_ht;
  DictionaryTrie dt;
  DictionaryTrie dt2;
  DictionaryTrie freq_test;
  int t_bst, t_ht, tt;

  words.push_back("harry");
  words.push_back("sriram");
  words.push_back("cse");
  words.push_back("crucio");
  words.push_back("autocomplete");
  
  
  cout << "Inserting into Dictionaries..." << endl;
  //set the iterator to the beginning of the words
  wit = words.begin();
  wen = words.end();
  //loop through all the words
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      //insert the elements
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 1);
      cout << t_bst << " " << t_ht << " "<< tt << "... ";
      if(!t_bst)
	{
          //print fail message when insert fail
	  cout << "failed for DictionaryBST... ";
	}
      if(!t_ht)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(!tt)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(t_bst && t_ht && tt)
	{
	  // pass message when insert complete
	  cout << "PASSED! :D ";
	}
      cout << endl;
    }

  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;
  // this is the same thing from above
  // checking insert dupe elements
  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 0);
      if(t_bst)
        {
          cout << "failed for DictionaryBST... ";
        }
      if(t_ht)
        {
          cout << "failed for DictionaryHashset... ";
        }
      if(tt)
        {
          cout << "failed for DictionaryTrie... ";
        }
      if(!t_bst && !t_ht && !tt)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

  cout << endl;

  
/*You are supposed to add more test cases in this file */

  //this is the piazza test for all data strutures 
  words2.push_back(" app");
  words2.push_back("app  p");
  words2.push_back("ap pp  e");
  words2.push_back("app  pe");
  words2.push_back("apppe ");
  words2.push_back("basketball");
  words2.push_back("asterisk");
  words2.push_back(" basket");
  words2.push_back("application");
  words2.push_back("a");
  words2.push_back("aa");
  words2.push_back("aaa");
  words2.push_back("aa a");
  words2.push_back("app");
  words2.push_back("gugglebee");
  words2.push_back("waldos");
  words2.push_back("are you not entertained");
  words2.push_back("never");
  words2.push_back("gonna");
  words2.push_back("give");
  words2.push_back("you");
  words2.push_back("up");
  words2.push_back("never gonna give you up");

  
  cout << "Inserting more elements into Dictionaries..." << endl;
  //loop though my vector and insert all the testing elements into the three scruture
  wit = words2.begin();
  wen = words2.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 1);
     
      if(!t_bst)
	{
	  cout << "failed to insert for DictionaryBST... (second 'apppe' failed means success)";
	}
      if(!t_ht)
	{
	  cout << "failed to insert for DictionaryHashset... (second 'apppe' failed means success)";
	}
      if(!tt)
	{
	  cout << "failed to insert for DictionaryTrie... (second 'apppe' failed means success)";
	}
      if(t_bst && t_ht && tt)
	{
	  cout << "PASSED! for inserting :D ";
	}
      cout << endl;
    }

  cout << "Testing for find method for all three data scrutures..." << endl;
  //loop throught my second vector and find all the elements inside vector
  wit = words2.begin();
  wen = words2.end();
  for(; wit != wen; ++wit){
      cout << "Finding the elements in words2 : ...";
      t_bst = d_bst.find(*wit);
      t_ht = d_ht.find(*wit);
      tt = dt.find(*wit);
      if(!t_bst)
	{
	  cout << "failed to find for DictionaryBST... ";
	}
      if(!t_ht)
	{
	  cout << "failed to find for DictionaryHashset... ";
	}
      if(!tt)
	{
	  cout << "failed to find for DictionaryTrie... ";
	}
      if(t_bst && t_ht && tt)
	{
	  cout << "PASSED! Test for find :D ";
	}
      cout << endl;
  }
  //use the piazza test to tes the elements that is not in the data structure
  words3.push_back("risk");
  words3.push_back("waldo");
  words3.push_back("carmen sandiego");
  words3.push_back("applesauce");
  words3.push_back("never gonna");
  words3.push_back("bask");
  words3.push_back("entertained");
  words3.push_back("guggle");
  words3.push_back("a job in the industry");
  words3.push_back("alaska");

   cout << "Testing for find item that does not exist method for all three data scrutures..." << endl;
  //loop throught my second vector and find all the elements inside vector
  wit = words3.begin();
  wen = words3.end();
  for(; wit != wen; ++wit){
      cout << "Finding the elements in words3 : ...";
      t_bst = d_bst.find(*wit);
      t_ht = d_ht.find(*wit);
      tt = dt.find(*wit);
      if(t_bst)
	{
	  cout << "failed to find for DictionaryBST... ";
	}
      if(t_ht)
	{
	  cout << "failed to find for DictionaryHashset... ";
	}
      if(tt)
	{
	  cout << "failed to find for DictionaryTrie... ";
	}
      if(!t_bst && !t_ht && !tt)
	{
	  cout << "PASSED! Test for find :D ";
	}
      cout << endl;
  }
  //test for freq
  dt2.insert("cse",1);
  int test = dt2.getFreq("cse");
  cout << "freq should be 1 and is " << test << endl;
  dt2.insert("cse upper",2);
  int test2 = dt2.getFreq("cse upper");
  cout << "freq should be 2 and is " << test2 << endl;

  //test for auto complete function
  vector<string>::iterator wit2;
  vector<string>::iterator wen2;
  dt2.insert("a", 500);
  dt2.insert("a lot of", 10);
  dt2.insert("a bunch of", 5);
  dt2.insert("csebb", 200);
  dt2.insert("cseaaa", 33);
  dt2.insert("cse bbb", 22);
  dt2.insert("hello world", 32);
  dt2.insert("hello hi", 96);
  dt2.insert("haha h", 1);
  dt2.insert("haha hhh", 13);
  //test find 2 items
  vector<std::string> answer = dt2.predictCompletions("cse", 2);
  wit2 = answer.begin();
  wen2 = answer.end();
  for(; wit2 != wen2; ++wit2){
    cout << *wit2 << ", ";
  }
  cout << endl;
  //test for legal completions is less than num_completions
  vector<std::string> answer2 = dt2.predictCompletions("cse", 100);
  wit2 = answer2.begin();
  wen2 = answer2.end();
  for(; wit2 != wen2; ++wit2){
    cout << *wit2 << ", ";
  }
  cout << endl;
  //test for prefix is complete word
  vector<std::string> answer3 = dt2.predictCompletions("a", 2);
  wit2 = answer3.begin();
  wen2 = answer3.end();
  for(; wit2 != wen2; ++wit2){
    cout << *wit2 << ", ";
  }
  cout << endl;
  //test for no legal completions
  vector<std::string> answer4 = dt2.predictCompletions("ha", 1);
  if(answer4.empty())
    return -1;
  else
    cout << "passed no legal completions test" << endl;
  //test for empty prefix
  vector<std::string> answer5 = dt2.predictCompletions("", 1);
  if(!answer5.empty())
    return -1;
  else
    cout << "passed no empty prefix test" << endl;

  //test for invalid input
  vector<std::string> answer6 = dt2.predictCompletions("123", 1);
  if(!answer6.empty())
    return -1;
  else
    cout << "passed invalid input test" << endl;

  //test for 0 num_completions
  vector<std::string> answer7 = dt2.predictCompletions("cse", 0);
  if(!answer7.empty())
    return -1;
  else
    cout << "passed test for 0 num_completion" << endl;


  return 0;
}
