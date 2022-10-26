/*
 Author : Mahmoud Ismail
 Date   : 26/10/2022
*/
#include <iostream>
#include <vector>
using namespace std;

// write your implementation here
int removeElement(int val,vector<int>&nums)
{
  int count = 0;
  for(int i = 0 ; i<nums.size(); i++){
      if(val != nums[i]){
          nums[count] = nums[i];
          count++;
      }
  }
    return count;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
