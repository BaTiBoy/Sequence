#include "Sequence.h"
#include <iostream>
using namespace std;

int main()
{
	string s1 = "dna.txt";
	Sequence s(s1);
	cout << s.length() << endl;
	cout << s.numberOf('A') << endl;
	cout << s.numberOf('T') << endl;
	cout << s.numberOf('C') << endl;
	cout << s.numberOf('G') << endl;
	cout << s.longestConsecutive() << endl;
	cout << s.longestRepeated() << endl;
}
