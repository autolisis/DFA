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
	cout << "Enter the word to be accepted\n(Enter exit to exit): ";
	string word; cin >> word;
	while ((word.compare("exit") != 0)){
		if (d.accept(word))
			cout << "Word has been ACCEPTED: "<< word <<endl;
		else
			cout << "Word has NOT been ACCEPTED: "<< word <<endl;
		cin >> word;
	}
}
