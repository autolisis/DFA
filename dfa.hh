#include <iostream>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

template<typename T> void printElement(T t, const int& width) {
	cout << right << setw(width) << setfill(' ') << t;
}

// A DFA is a 5 tuple with
// Q = {0..NumStates}, q0 = initialState, F = finalStates,
// Sigma = charSet, del = Mapping between states and characters
class DFA {
	public:
		size_t numStates;
		set <int> finalStates;
		int initialState;

		set <char> charSet;

		// Transition function is a mapping
		// Current State, Character Read -> Next State
		map <int, map <char, int> > del;

		DFA(size_t numS, string charS) {
			numStates = numS;
			for (auto&& character : charS) {
				charSet.insert(character);
			}
		}
		void input() {
			cout << "Enter initial state for the DFA: ";
			cin >> initialState;
			cout << "Enter final states for the DFA: (Enter -1 to terminate)";
			while (true) {
				int finalState; cin >> finalState;
				if (finalState==-1)
					break;
				finalStates.insert(finalState);
			}
			cout << "Enter the state Transition table in the form a b c \
				Where a = Current State, b is character read, c is Next State\
				Enter -1 to terminate";
			while (true) {
				cout << "a b c : ";
				int a; char b; int c;
				cin >> a;
				if (a==-1)
					break;
				cin >> b >> c;
				del[a][b]=c;
			}
		}
		void output() {
			cout << "\nInitial State of DFA: "<<initialState;
			cout << "\nSet of final States of DFA: {";
			for (auto&& finalstate : finalStates) {
				cout << finalstate <<", ";
			}
			cout << "}\n";
			printElement("Character read ►", 20);
			for (auto &&ch : charSet) {
				printElement(ch, 3);
			}
			cout << endl;
			printElement("Current State ▼", 20);
			cout << endl;
			for (auto&& state : del) {
				printElement(state.first, 18);
				for (auto &&ch : charSet) {
					printElement(state.second[ch], 3);
				}
				cout << endl;
			}
		}
		bool accept(string word) {
			int curState = initialState;
			for (auto&& symbol : word)
				curState = nextState(curState, symbol);

			if (finalStates.count(curState) > 0)
				return true;
			else
				return false;
		}
		int nextState(int current, char symbol) {
			return del[current][symbol];
		}
		void accepter() {
			cout << "Enter the word to be accepted\n(Enter exit to exit): ";
			string word; cin >> word;
			while ((word.compare("exit") != 0)){
				if (accept(word))
					cout << "Word has been ACCEPTED: "<< word <<endl;
				else
					cout << "Word has NOT been ACCEPTED: "<< word <<endl;
				cin >> word;
			}
		}
};
