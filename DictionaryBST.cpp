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
// this file holdes all the function for BST, insert and find
// alse constructor and dectructor detail described in DictionaryBST.h file

#include "util.h"
#include "DictionaryBST.h"

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){
  tree = new std::set<std::string>();
}

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{
  //if the param is empty return false
  if(word == ""){
    return false;
  }
  //else insert into the bst call library function
  std::pair<std::set<std::string>::iterator, bool> success;
  success = tree->insert(word);
  return success.second;
}

// Return true if word is in the dictionary, and false otherwise /
bool DictionaryBST::find(std::string word) const
{
  // if the param is empty return false
  if(word == ""){
    return false;
  }
  //otherwist processed to find, by calling the library method
  std::set<std::string>::iterator find = tree->find(word);
  if(find != tree->end()){
    return true;
  }
  else{
    return false;
  }
}

/* Destructor */
DictionaryBST::~DictionaryBST(){
  delete tree; //empty the tree when end
}
