#include<iostream>
#include<set>
#include<unordered_set>
#include<vector>
#include<string>
#include<math.h>
using namespace std;


int main()
{

	// use a sieve to find the ith prime
	int max_val = 2000000;
	
	unordered_set<int> nums;
	for(int i = max_val; i >= 0; i-- ) {
		nums.insert(i);
	}
	int mid_val = max_val / 2;


	cout << "\n now removing multiples \n";
	unordered_set<int>::const_iterator found;
	for(int i = 2; i <= mid_val; i++) {
		found = nums.find(i); 
		if(found != nums.end() ){
			// new prime
			int multiple = i * 2;
			while(multiple <= max_val ) {
				nums.erase(multiple);
				multiple = multiple + i;
			}
		}
	}

	long out = 0;
	for(unordered_set<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr)
		out += *itr;
 
//	for(unordered_set<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr)
              //cout<< *itr << "\t";

	cout << "sum of primes: " << out-1;
	return 0;
}
