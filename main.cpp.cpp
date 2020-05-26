#include <iostream>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp; 
unordered_map<string, int> mp1;
int main () {
    float s=0,l1,l2;
  string myText,word;

 
  ifstream MyReadFile("filename.txt");
  

  
 while (MyReadFile >> word) 
    {  transform(word.begin(), word.end(), word.begin(), ::tolower); 
	for (int i = 0, len = word.size(); i < len; i++) 
    { 
       
        if (ispunct(word[i])) 
        { 
            word.erase(i--, 1); 
            len = word.size(); 
        } 
    } 
	  mp[word]+=1;
       
    } 
    unordered_map<string, int>:: iterator p1;
    for (p1 = mp.begin(); p1 != mp.end(); p1++)
	{
		int k=pow(p1->second,2);
		l1+=k;
	}

  // Close the file
  MyReadFile.close();
  ifstream MyReadFile1("filename1.txt");
  

  
 while (MyReadFile1 >> word) 
    { transform(word.begin(), word.end(), word.begin(), ::tolower); 
	for (int i = 0, len = word.size(); i < len; i++) 
    { 
       
        if (ispunct(word[i])) 
        { 
            word.erase(i--, 1); 
            len = word.size(); 
        } 
    } 
	  mp1[word]+=1;
       
    } 

    for (p1 = mp1.begin(); p1 != mp1.end(); p1++)
	{
		int k=pow(p1->second,2);
		l2+=k;
	}
 unordered_map<string, int>:: iterator p; 
  
    for (p1 = mp.begin(); p1 != mp.end(); p1++)
	{
	 
	    for (p = mp1.begin(); p != mp1.end(); p++) 
	    {
	    	if(p->first==p1->first)
	    	{
	    	  s=s+(p->second*p1->second);
			}
    	}
   }
    	
  cout<<"inner product is ="<<s/(sqrt(l1)*sqrt(l2))<<"\n";
  // Close the file
  MyReadFile1.close();
}

