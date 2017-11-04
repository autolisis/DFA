#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

// A DFA is a 5 tuple with
// Q = {0..NumStates}, q0 = initialState, F = finalStates,
// Sigma = charSet, del = Mapping between states and characters
class DFA {
		size_t numStates;
		set <int> finalStates;
		int initialState;

		set <char> charSet;

		map <char, vector <int> > del;

	public:
		DFA(size_t numS, string charS) {
			numStates = numS;
			for (auto&& character : charS) {
				charSet.insert(character);
				vector <int> a(numStates, -1);
				del[character] = a;
				cout << "Enter states for character"
					<< "\n In the form m:n (Upon reading character " << character
					<<", it will move to state n if currentlly in state m.)"
					<<"\nEnter -1:-1 to terminate";
				while (true) {
					int m,n;
					scanf("%d:%d", &m, &n);
					if (m==-1)
						break;
					del[character].at(m)=n;
				}
			}
			cout << "Enter initial state for the DFA: ";
			cin >> initialState;
			cout << "Enter final states for the DFA: (Enter -1 to terminate)";
			while (true) {
				int a;
				cin >> a;
				if (a==-1)
					break;
				finalStates.insert(a);
			}
		}
		bool accept(string word) {
			int curState = initialState;

			for (auto&& symbol : word) {
				curState = nextState(curState, symbol);
			}

			if (finalStates.find(curState) != finalStates.end())
				return true;
			else
				return false;
		}

		int nextState(int current, char symbol) {
			return del[symbol].at(current);
		}

};

int main() {
	cout << "Enter the number of States of DFA (eg. 3): ";
	int n; cin >> n;
	cout << "Enter the character set (eg. 01): ";
	string charSet; cin >> charSet;
	DFA d(n, charSet);
	cout << "Enter the word to be accepted (Enter exit to exit): ";
	string word; cin >> word;
	while ((word.compare("exit") != 0)){
		if (d.accept(word))
			cout << "Word has been ACCEPTED: "<< word <<endl;
		else
			cout << "Word has NOT been ACCEPTED: "<< word <<endl;
		cin >> word;
	}
}
