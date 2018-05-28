#include<iostream>
#include<set>
#include<unordered_set>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

double f(double x, int primesLessThan) {
	return exp(x) - pow(x, primesLessThan);
}

double fPrime(double x, int primesLessThan) {
	return exp(x) - primesLessThan * pow( x, primesLessThan - 1 );
}

double newton(double x, int primesLessThan) {
	double epsilon = 0.5;
	double h = f(x, primesLessThan) / fPrime(x, primesLessThan);
	cout << "initial h : " << h << "\n";
	while(abs(h) > epsilon) {
		h = f(x, primesLessThan) / fPrime(x, primesLessThan);
		x = x - h;
		cout << "Next guess for max_val: " << x << "\n";
	}
	return x;
}

int main()
{
	// Newton's method hits an overflow method. 
	// Alternate would be to find the uppper limit of numbers using pi(n), 
	// with pi as the prime number counting function
	//int primesLessThan = 10000; 
	//double guess = 100000;
	//double max_guess = newton( guess, primesLessThan );
	
	// use a sieve to find the ith prime
	int max_val = 250000;
	
	unordered_set<int> nums;
	for(int i = max_val; i >= 0; i-- ) {
		nums.insert(i);
	}
	int mid_val = max_val / 2;
	unordered_set<int>::const_iterator found;

	std::unordered_set<int> :: iterator i;
        for(i = nums.begin(); i != nums.end(); ++i)
	            cout << *i << '\t';

	cout << "\n now removing multiples \n";
	for(int i = 2; i < mid_val; i++) {
		found = nums.find(i); 
		if(found != nums.end() ){
			// new prime
			int multiple = i * 2;
			while(multiple < max_val ) {
				nums.erase(multiple);
				multiple = multiple + i;
			}
		}
	}

	vector<int> tmp(nums.begin(), nums.end());

        for(int i = 0; i< tmp.size(); i++)
		cout << tmp.at(i) << '\t';

	cout << "10001th prime: " << tmp.at(10001 + 1);
	return 0;
}
