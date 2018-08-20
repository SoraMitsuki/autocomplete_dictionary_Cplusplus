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
// this file holdes all the function for Hashtable, insert and find
// constructor and dectructor detail described in DictionaryHashtable.h file

#include "util.h"
#include "DictionaryHashtable.h"

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){
  table = new std::unordered_set<std::string>();
}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{
  //check for the param is empty or not
  if(word == ""){
    return false;
  }
  //insert
  std::pair<std::unordered_set<std::string>::iterator, bool> success;
  success = table->insert(word);
  return success.second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
  //check for the param is empty or not
  if(word == ""){
    return false;
  }
  //processed to find return true when find otherwise false
  std::unordered_set<std::string>::const_iterator find;
  std::unordered_set<std::string>::const_iterator nothing(NULL);
  find = table->find(word);
  if(find != nothing){
    return true;
  }
  else{
    return false;
  }
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){
  delete table; //empty the table
}
