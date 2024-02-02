
#include <cctype>  // ?
#include "dfa.h"
#include <string>
// #include "tokens.h"
using namespace std;
using std::make_pair;
#include <utility>  // pair is in here
#include <vector>  // arr of undefined length
#include <iostream>

void StateMachine::reset() {
    // called to reset the state machine to its initial state.
    // This allows me to run tests over and over again with the
    // same StateMachine.

    currentState = 0;
    token = TokenType::TokEOF;
}

TokenType StateMachine::next(StringStack &stack, std::string &lexeme) {

    // 6-state machine. Each index in the vector is a state.
    vector< pair<char, int> > transitions[6];

    // define transitions from state 0:

    // The pairs map keys to their associated values. In this context, that's mapping
    //    symbols to the states they transition to. 
    transitions[0].push_back(make_pair('\\', 1));  // a slash takes you to state 1 (whitespace)
    transitions[0].push_back(make_pair(' ', 2));  // a space takes you to state 2 (whitespace)

    // state 0 to state 3 (C++ identifiers):
    transitions[0].push_back(make_pair('a', 3));  // [a-zA-Z_] takes you to state 3
    transitions[0].push_back(make_pair('b', 3));
    transitions[0].push_back(make_pair('c', 3));
    transitions[0].push_back(make_pair('d', 3));
    transitions[0].push_back(make_pair('e', 3));
    transitions[0].push_back(make_pair('f', 3));
    transitions[0].push_back(make_pair('g', 3));
    transitions[0].push_back(make_pair('h', 3));
    transitions[0].push_back(make_pair('i', 3));
    transitions[0].push_back(make_pair('j', 3));
    transitions[0].push_back(make_pair('k', 3));
    transitions[0].push_back(make_pair('l', 3));
    transitions[0].push_back(make_pair('m', 3));
    transitions[0].push_back(make_pair('n', 3));
    transitions[0].push_back(make_pair('o', 3));
    transitions[0].push_back(make_pair('p', 3));
    transitions[0].push_back(make_pair('q', 3));
    transitions[0].push_back(make_pair('r', 3));
    transitions[0].push_back(make_pair('s', 3));
    transitions[0].push_back(make_pair('t', 3));
    transitions[0].push_back(make_pair('u', 3));
    transitions[0].push_back(make_pair('v', 3));
    transitions[0].push_back(make_pair('w', 3));
    transitions[0].push_back(make_pair('x', 3));
    transitions[0].push_back(make_pair('y', 3));
    transitions[0].push_back(make_pair('z', 3));
    transitions[0].push_back(make_pair('A', 3));  // uppercase
    transitions[0].push_back(make_pair('B', 3));
    transitions[0].push_back(make_pair('C', 3));
    transitions[0].push_back(make_pair('D', 3));
    transitions[0].push_back(make_pair('E', 3));
    transitions[0].push_back(make_pair('F', 3));
    transitions[0].push_back(make_pair('G', 3));
    transitions[0].push_back(make_pair('H', 3));
    transitions[0].push_back(make_pair('I', 3));
    transitions[0].push_back(make_pair('J', 3));
    transitions[0].push_back(make_pair('K', 3));
    transitions[0].push_back(make_pair('L', 3));
    transitions[0].push_back(make_pair('M', 3));
    transitions[0].push_back(make_pair('N', 3));
    transitions[0].push_back(make_pair('O', 3));
    transitions[0].push_back(make_pair('P', 3));
    transitions[0].push_back(make_pair('Q', 3));
    transitions[0].push_back(make_pair('R', 3));
    transitions[0].push_back(make_pair('S', 3));
    transitions[0].push_back(make_pair('T', 3));
    transitions[0].push_back(make_pair('U', 3));
    transitions[0].push_back(make_pair('V', 3));
    transitions[0].push_back(make_pair('W', 3));
    transitions[0].push_back(make_pair('X', 3));
    transitions[0].push_back(make_pair('Y', 3));
    transitions[0].push_back(make_pair('Z', 3));
    transitions[0].push_back(make_pair('_', 3));  // underscore

    // state 0 to state 4 (0 is an integer):
    transitions[0].push_back(make_pair('0', 4));  // a zero takes you to state 4

    // state 0 to state 5 (positive integers):
    transitions[0].push_back(make_pair('1', 5));  // [1-9] takes you to state 5
    transitions[0].push_back(make_pair('2', 5));
    transitions[0].push_back(make_pair('3', 5));
    transitions[0].push_back(make_pair('4', 5));
    transitions[0].push_back(make_pair('5', 5));
    transitions[0].push_back(make_pair('6', 5));
    transitions[0].push_back(make_pair('7', 5));
    transitions[0].push_back(make_pair('8', 5));
    transitions[0].push_back(make_pair('9', 5));

    // transitions from state 1:
    transitions[1].push_back(make_pair('t', 2));  // tab
    transitions[1].push_back(make_pair('n', 2));  // newline
    transitions[1].push_back(make_pair('r', 2));  // carriage return

    // transitions from state 2 (whitespace):
    transitions[2].push_back(make_pair('\\', 1));
    transitions[2].push_back(make_pair(' ', 2));

    // transitions from state 3 (C++ identifiers):
    transitions[3].push_back(make_pair('a', 3));  //  [a-zA-Z0-9_] self-loop
    transitions[3].push_back(make_pair('b', 3));
    transitions[3].push_back(make_pair('c', 3));
    transitions[3].push_back(make_pair('d', 3));
    transitions[3].push_back(make_pair('e', 3));
    transitions[3].push_back(make_pair('f', 3));
    transitions[3].push_back(make_pair('g', 3));
    transitions[3].push_back(make_pair('h', 3));
    transitions[3].push_back(make_pair('i', 3));
    transitions[3].push_back(make_pair('j', 3));
    transitions[3].push_back(make_pair('k', 3));
    transitions[3].push_back(make_pair('l', 3));
    transitions[3].push_back(make_pair('m', 3));
    transitions[3].push_back(make_pair('n', 3));
    transitions[3].push_back(make_pair('o', 3));
    transitions[3].push_back(make_pair('p', 3));
    transitions[3].push_back(make_pair('q', 3));
    transitions[3].push_back(make_pair('r', 3));
    transitions[3].push_back(make_pair('s', 3));
    transitions[3].push_back(make_pair('t', 3));
    transitions[3].push_back(make_pair('u', 3));
    transitions[3].push_back(make_pair('v', 3));
    transitions[3].push_back(make_pair('w', 3));
    transitions[3].push_back(make_pair('x', 3));
    transitions[3].push_back(make_pair('y', 3));
    transitions[3].push_back(make_pair('z', 3));
    transitions[3].push_back(make_pair('A', 3));  // uppercase
    transitions[3].push_back(make_pair('B', 3));
    transitions[3].push_back(make_pair('C', 3));
    transitions[3].push_back(make_pair('D', 3));
    transitions[3].push_back(make_pair('E', 3));
    transitions[3].push_back(make_pair('F', 3));
    transitions[3].push_back(make_pair('G', 3));
    transitions[3].push_back(make_pair('H', 3));
    transitions[3].push_back(make_pair('I', 3));
    transitions[3].push_back(make_pair('J', 3));
    transitions[3].push_back(make_pair('K', 3));
    transitions[3].push_back(make_pair('L', 3));
    transitions[3].push_back(make_pair('M', 3));
    transitions[3].push_back(make_pair('N', 3));
    transitions[3].push_back(make_pair('O', 3));
    transitions[3].push_back(make_pair('P', 3));
    transitions[3].push_back(make_pair('Q', 3));
    transitions[3].push_back(make_pair('R', 3));
    transitions[3].push_back(make_pair('S', 3));
    transitions[3].push_back(make_pair('T', 3));
    transitions[3].push_back(make_pair('U', 3));
    transitions[3].push_back(make_pair('V', 3));
    transitions[3].push_back(make_pair('W', 3));
    transitions[3].push_back(make_pair('X', 3));
    transitions[3].push_back(make_pair('Y', 3));
    transitions[3].push_back(make_pair('Z', 3));
    transitions[3].push_back(make_pair('0', 3));  // numbers
    transitions[3].push_back(make_pair('1', 3));
    transitions[3].push_back(make_pair('2', 3));   
    transitions[3].push_back(make_pair('3', 3));
    transitions[3].push_back(make_pair('4', 3));
    transitions[3].push_back(make_pair('5', 3));   
    transitions[3].push_back(make_pair('6', 3));
    transitions[3].push_back(make_pair('7', 3));
    transitions[3].push_back(make_pair('8', 3));
    transitions[3].push_back(make_pair('9', 3));
    transitions[3].push_back(make_pair('_', 3));  // underscore

    // transitions from state 4 (none):

    // transitions from state 5:
    transitions[5].push_back(make_pair('0', 3)); // [0-9]
    transitions[5].push_back(make_pair('1', 3));   
    transitions[5].push_back(make_pair('2', 3));   
    transitions[5].push_back(make_pair('3', 3));
    transitions[5].push_back(make_pair('4', 3));
    transitions[5].push_back(make_pair('5', 3));   
    transitions[5].push_back(make_pair('6', 3));
    transitions[5].push_back(make_pair('7', 3));
    transitions[5].push_back(make_pair('8', 3));
    transitions[5].push_back(make_pair('9', 3));

    bool eof = false;

    // List of accepting states: [2, 3, 4, 5]   (if state >1, it's accepting)

    while (true) {  // infinite loop - we break out of this when we return something.
        int thisInt = stack.get();
        
        if ((thisInt == -1) && (eof == false)) {
            eof = true;
            stack.unget();
            if (currentState == 2) {
                currentState = 0;
                std::cout << lexeme << std::endl;
                return TokWhitespace;
            }
            if (currentState == 3) {
                currentState = 0;
                std::cout << "****************" << std::endl;
                std::cout << lexeme << std::endl;
                return TokIdentifier;
            }
            if (currentState == 4 || currentState == 5) {
                currentState = 0;                
                std::cout << lexeme << std::endl;
                return TokInteger;
            }
        }
        else if ((thisInt == -1) && (eof == true))
            lexeme = "";
            return TokEOF;
            // return TokenType::TokEOF;  ungetting and returning token instead...
        
        char thisChar = char(thisInt);

        // we need this flag so we can return a TokError when we don't find a valid transition:
        bool validTransition = false;  

        // Iterate thru the possible transitions from our current state to check whether this
        //    symbol is a valid transition:

        // .first refers to the KEY in the kv pair, and second refers to the VALUE in the kv pair.
        // for each transition in our vector of transition pairs from this state:
        for (auto transition : transitions[currentState])
            if (transition.first == thisChar) { 
                // if here, the symbol we just read in is a valid transition from our current state!
                currentState = transition.second;  // transition on this symbol to the next state
                lexeme += thisChar;
                validTransition = true;
                break;  // Out of for loop. We already discovered a valid transition on this symbol.
            }

        if (!validTransition && currentState < 2) {  // if in a dead state
            currentState = 0;  // do we want to go back to state zero when there's an error?
            return TokenType::TokError;  // darn.
        }
        // If we're in an accepting state, we should keep reading in new symbols until we read a
        //     symbol that doesn't have a defined transition. At that point, we have reached the
        //     end of the lexeme. 
        if (!validTransition && currentState > 1)  {  // if at the end of the lexeme
            stack.unget();
            lexeme.pop_back();
            
            // return the thing and be done!
            if (currentState == 2) {
                currentState = 0;
                token = TokWhitespace;
            }
            else if (currentState == 3) {
                currentState = 0;
                token = TokIdentifier;
            }
            else if (currentState == 4 || currentState == 5) {
                currentState = 0;
                token = TokInteger;
            }
        }

        // IMPLICIT break out of the while loop to read the next character.
    }

}
