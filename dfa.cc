#include "dfa.hh"

using namespace std;


int main() {
	cout << "Enter the number of States of DFA (eg. 3): ";
	int n; cin >> n;
	cout << "Enter the character set (eg. 01): ";
	string charSet; cin >> charSet;
	DFA d(n, charSet);
	d.input();
	cout <<endl<<"DFA INITIALISED.\nReady to accept words.\n";
	d.output();
	d.accepter();
}
