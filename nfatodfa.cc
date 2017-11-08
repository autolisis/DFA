#include <bitset>
#include "dfa.hh"
#include "nfa.hh"

using namespace std;

#define MAXSTATES 32

int main() {
	cout << "Enter the number of States of NFA (eg. 3): ";
	int n; cin >> n;
	cout << "Enter the character set (eg. 01): ";
	string charSet; cin >> charSet;
	NFA a(n, charSet);
	DFA b(1<<n, charSet);//Initialise a DFA with 2^n states and same character Set
	set < set <int> > possibleStates;
	int init[] = {a.initialState};
	b.initialState = 1 << a.initialState;
	possibleStates.insert(set <int>(init, init+1));
	bool hasPhi = false;
	for (auto&& currentState : possibleStates) {
		int currentBits = 0;
		for (auto&& st : currentState)
			currentBits ^= 1<<st;
		for (auto&& symbol : charSet) {
			set <int> newState = a.nextState(currentState, symbol);
			int nextBits = 0;
			// If the NFA hangs in some case we need to deal with it by adding a phi state
			// (state 0)
			if (newState.empty())
				hasPhi = true;
			for (auto&& st : newState) {
				nextBits ^= 1<<st;
				if (a.finalStates.count(st) > 0)
					b.finalStates.insert(nextBits);
			}
			b.del[currentBits][symbol] = nextBits;
			possibleStates.insert(newState);
		}
	}
	if (hasPhi)
		for (auto&& symbol : charSet)
			b.del[0][symbol] = 0;

	b.output();
	cout << "Process ended";
}
