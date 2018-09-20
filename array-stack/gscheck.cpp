#include <iostream>
#include "char_stack.h"
using namespace std;

int main(int argc, char* const argv[]) {
    char line[250];
    char final[250];
	char_stack s;
    int linenumber = 0;
    int length = 0;
    
    
    while (cin.getline(line, 250)) {
        length = strlen(line);
        linenumber++;
        
        for (int i = 0; i<length; i++) {
            char c = line[i];
            
//CHECKING ( ):
            
            if ( c=='(' ) { //found opening symbol->push on the stack
                s.push(c);
            }
            else if( c==')' ){  //found closing symbol
                if (s.empty()) { //nothing to match with
                    cout << "Error on line " << linenumber << ": Too many )" << endl;
                    for (int j=0; j<length; j++) { //printing the line
                        if (j==i) {
                            cout << line[j] << endl;
                            for (int k=0; k<=j; k++) {
                                if (line[k] == '\t') {
                                    cout << '\t';
                                }
                                else{cout << " ";}
                            }
                            
                        }
                        else{ cout << line[j]; }
                    }
                    cout << endl;
                    return 1;
                }
                
                if ( s.top() == '{' ) {  //wrong type
                    cout << "Error on line " << linenumber << ": Read " << c << " , expected }" << endl;
                    for (int j=0; j<length; j++) {
                        if (j==i) {
                            cout << line[j] << endl;
                            for (int k=0; k<=j; k++) {
                                if (line[k] == '\t') {
                                    cout << '\t';
                                }
                                else{cout << " ";}
                            }
                        }
                        else{ cout << line[j]; }
                    }
                    cout << endl;
                    return 1;
                }
                if ( s.top() == '[') {
                    cout << "Error on line " << linenumber << ": Read " << c << " , expected ]" << endl;
                    for (int j=0; j<length; j++) {
                        if (j==i) {
                            cout << line[j] << endl;
                            for (int k=0; k<=j; k++) {
                                if (line[k] == '\t') {
                                    cout << '\t';
                                }
                                else{cout << " ";}
                            }
                        }
                        else{ cout << line[j]; }
                    }
                    cout << endl;
                    return 1;
                }
                char l = s.pop();
            }
            
//CHECKING [ ]:
            if ( c=='[' ) { //found opening symbol->push on the stack
                s.push(c);
                
            }
            else if( c==']' ){  //found closing symbol
                if (s.empty()) { //nothing to match with
                    cout << "Error on line " << linenumber << ": Too many ]" << endl;
                    for (int j=0; j<length; j++) {
                        if (j==i) {
                            cout << line[j] << endl;
                            for (int k=0; k<=j; k++) {
                                if (line[k] == '\t') {
                                    cout << '\t';
                                }
                                else{cout << " ";}
                            }
                        }
                        else{ cout << line[j]; }
                    }
                    cout << endl;
                    return 1;
                }
                
                if ( s.top() == '(' ) {  //wrong type
                    cout << "Error on line " << linenumber << ": Read " << c << " , expected )" << endl;
                    for (int j=0; j<length; j++) {
                        if (j==i) {
                            cout << line[j] << endl;
                            for (int k=0; k<=j; k++) {
                                if (line[k] == '\t') {
                                    cout << '\t';
                                }
                                else{cout << " ";}
                            }
                        }
                        else{ cout << line[j]; }
                    }
                    cout << endl;
                    return 1;
                }
                if ( s.top() == '{') {
                    cout << "Error on line " << linenumber << ": Read " << c << " , expected }" << endl;
                    for (int j=0; j<length; j++) {
                        if (j==i) {
                            cout << line[j] << endl;
                            for (int k=0; k<=j; k++) {
                                if (line[k] == '\t') {
                                    cout << '\t';
                                }
                                else{cout << " ";}
                            }
                        }
                        else{ cout << line[j]; }
                    }
                    cout << endl;
                    return 1;
                }
                char l = s.pop();
            }

//CHECKING { }:
            if ( c=='{' ) { //found opening symbol->push on the stack
                s.push(c);
            }
            else if( c=='}' ){  //found closing symbol
                if (s.empty()) { //nothing to match with
                    cout << "Error on line " << linenumber << ": Too many }" << endl;
                    for (int j=0; j<length; j++) {
                        if (j==i) {
                            cout << line[j] << endl;
                            for (int k=0; k<=j; k++) {
                                if (line[k] == '\t') {
                                    cout << '\t';
                                }
                                else{cout << " ";}
                            }
                        }
                        else{cout << line[j];}
                    }
                    cout << endl;
                    return 1;
                }
                //not empty but:
                
                if ( s.top() == '(' ) {  //wrong type
                    cout << "Error on line " << linenumber << ": Read " << c << " , expected )" << endl;
                    for (int j=0; j<length; j++) {
                        if (j==i) {
                            cout << line[j] << endl;
                            for (int k=0; k<=j; k++) {
                                if (line[k] == '\t') {
                                    cout << '\t';
                                }
                                else{cout << " ";}
                            }
                        }
                        else{cout << line[j];}
                    }
                    cout << endl;
                    return 1;
                }
                if ( s.top() == '[') {
                    cout << "Error on line " << linenumber << ": Read " << c << " , expected ]" << endl;
                    for (int j=0; j<length; j++) {
                        if (j==i) {
                            cout << line[j] << endl;
                            for (int k=0; k<=j; k++) {
                                if (line[k] == '\t') {
                                    cout << '\t';
                                }
                                else{cout << " ";}
                            }
                        }
                        else{cout << line[j];}
                    }
                    cout << endl;
                    return 1;
                }
                char l = s.pop();
                
            }
            if (cin.peek()==EOF) {
                for (int i=0; i<length; i++) {
                    final[i] = line[i];
                }
            }
        }
        
    }
    
    
    
    if (s.empty()) {
        cout << "No Errors Found" << endl;
        return 0;
    }
    else{
        char c = s.top();
        cout << "Error on line " << linenumber << ": Too many " << c << endl;
        for (int k=0; k<length; k++) {
            cout << final[k];
        }
        cout << endl;
        return 0;
    }

    
}


