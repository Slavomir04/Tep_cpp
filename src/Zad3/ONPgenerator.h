//
// Created by slawe on 08.11.2024.
//

#ifndef ONPGENERATOR_H
#define ONPGENERATOR_H
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <cmath>

using namespace std;

bool isOperator(char c_is_char) {
    return c_is_char == '+' || c_is_char == '-' || c_is_char == '*' || c_is_char == '/';
}

bool isFunction(const string &str_token) {
    return str_token == "cos" || str_token == "sin";
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToRPN(const string &expression) {
    string output;
    string operators[100];  // tablica symulująca stos dla operatorów
    int top = -1;           // wskaźnik na szczyt stosu

    istringstream tokens(expression);
    string token;
    while (tokens >> token) {
        if (isdigit(token[0])) { // liczba
            output += token + " ";
        }
        else if (isalpha(token[0])) { // funkcja np. cos, sin
            operators[++top] = token;
        }
        else if (token == "(") {
            operators[++top] = token;
        }
        else if (token == ")") {
            // Zdejmujemy operatory aż do napotkania "("
            while (top >= 0 && operators[top] != "(") {
                output += operators[top--] + " ";
            }
            top--; // usuń "(" z "stosu"
            if (top >= 0 && isFunction(operators[top])) {
                output += operators[top--] + " "; // dodaj funkcję do wyjścia
            }
        }
        else if (isOperator(token[0])) {
            // Zdejmujemy operatory o wyższym lub równym priorytecie
            while (top >= 0 && isOperator(operators[top][0]) && precedence(operators[top][0]) >= precedence(token[0])) {
                output += operators[top--] + " ";
            }
            operators[++top] = token; // Dodajemy operator na stos
        }
    }

    // Przenosimy resztę operatorów do wyniku
    while (top >= 0) {
        output += operators[top--] + " ";
    }

    return output;
}



#endif //ONPGENERATOR_H
