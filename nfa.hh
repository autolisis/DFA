#include <iostream>
#include <set>
#include <map>

using namespace std;
// An NFA is a 5 tuple with
// Q = {0..NumStates}, q0 = initialState, F = finalStates,
// Sigma = charSet, del = Mapping between states and characters
class NFA {
public:
	size_t numStates;
	set <int> states;
	set<int> finalStates;
	int initialState;

	set<char> charSet;

	// Transition function is a mapping
	// Current State, Character Read -> Set of Next States
	map<int, map<char, set<int> > > del;

	NFA(size_t numS, string charS) {
		numStates = numS;
		// Initialise set of states
		for (unsigned int i = 0; i < numStates; i++)
			states.insert(states.end(), i);
		// Initialise character set
		for (auto &&character : charS)
			charSet.insert(character);

		cout << "Enter initial state for the NFA: ";
		cin >> initialState;
		cout << "Enter final states for the NFA: (Enter -1 to terminate)";
		while (true) {
			int finalState;
			cin >> finalState;
			if (finalState == -1)
				break;
			finalStates.insert(finalState);
		}
		cout << "Enter the state Transition table in the form a b c <d..> -1\n"
			<< "Where a = Current State, b is character read, c <d..> are Next States\n"
			<< "[Enter -1 to terminate]";
		while (true) {
			cout << "Enter a b c <d..>: ";
			int a; char b; int c;
			cin >> a;
			if (a == -1)
				break;
			cin >> b;
			while (true) {
				cin >> c;
				if (c == -1)
					break;
				del[a][b].insert(c);
			}
		}
	}
	set <int> nextState(set <int> currentState, char symbol) {
		set <int> next;
		for (auto&& state : currentState)
			for (auto&& nextstate : del[state][symbol]) {
				next.insert(nextstate);
			}
		return next;
	}
};
