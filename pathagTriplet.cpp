#include<iostream>
#include<set>
#include<unordered_set>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main()
{
	for(int i = 1; i < 500; i++) {
		for(int j = i; j < 500; j++) {
			if(pow(i, 2) + pow(j,2) == pow(1000 - i - j, 2 ) )
				cout << i <<" "<< j <<" "<< 1000 - i - j << "\n";
					
		}	
	}
	return 0;
}	
