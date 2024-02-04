#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> opcodeTable = {
    {"ORG", 0}, {"AND", 1}, {"LDA", 2}, {"ADD", 3},
    {"STA", 4}, {"BUN", 5}, {"BSA", 6}, {"ISZ", 7},
    {"CLA", 8}, {"CLE", 9}, {"CMA", 10}, {"CME", 11},
    {"CIR", 12}, {"CIL", 13}, {"INC", 14}, {"SPA", 15},
    {"SNA", 16}, {"SZA", 17}, {"SZE", 18}, {"HLT", 19},
    {"INP", 20}, {"OUT", 21}, {"SKI", 22}, {"SKO", 23},
    {"ION", 24}, {"IOF", 25}, {"DEC", 26}, {"HEX", 27}
};

vector<string> tokenize(const string& line) {
    vector<string> tokens;
    istringstream iss(line);
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    string line;
    int address = 0;

    while (getline(input, line)) {
        vector<string> tokens = tokenize(line);

        if (tokens.empty()) {
            continue;
        }

        string opcode = tokens[0];
        int operand = 0;

        if (tokens.size() > 1) {
            if (opcode != "ORG" && opcode != "CLA" && opcode != "CLE" && opcode != "CMA" && opcode != "CME" &&
                opcode != "CIR" && opcode != "CIL" && opcode != "INC" && opcode != "SPA" && opcode != "SNA" &&
                opcode != "SZA" && opcode != "SZE" && opcode != "HLT" && opcode != "INP" && opcode != "OUT" &&
                opcode != "SKI" && opcode != "SKO" && opcode != "ION" && opcode != "IOF" && opcode != "DEC" &&
                opcode != "HEX") {
                operand = stoi(tokens[1]);
            }
        }

        if (opcode == "ORG") {
            address = operand;
        }
        else {
            output << address << ": " << opcodeTable[opcode] << operand << endl;
            address++;
        }
    }

    input.close();
    output.close();

    return 0;
}
