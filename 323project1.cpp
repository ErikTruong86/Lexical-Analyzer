/*
  Names:
  Jeena Shetti
  Dalisa Nguyen
  Erik Truong
  Katherine Correa
  Casey Thatsanaphonh
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
#include <locale>
#include <string>
using namespace std;

vector<string> lexiconHolder;
vector<string> tokenHolder;

//Checks if the string is a digit
bool isDigit(const string &str) {
  return std::all_of(str.begin(), str.end(), ::isdigit);
}

// Check if the string that we had is a keyword or not.
void compareKeywords(string tempString)
{
  vector <string> keywords = {"auto","break","case","char","const","continue","default",
            "do","double","else","enum","extern","float","for","goto",
            "if","int","long","register","return","short","signed",
            "sizeof","static","struct","switch","typedef","union",
            "unsigned","void","volatile","while"};

    if(isDigit(tempString)) {
      lexiconHolder.push_back(tempString);
      tokenHolder.push_back("DIGIT      = ");
    }
    else if ( find( keywords.begin(), keywords.end(), tempString) != keywords.end())
    {
      lexiconHolder.push_back(tempString);
      tokenHolder.push_back("KEYWORD    = ");

    } else {
      lexiconHolder.push_back(tempString);
      tokenHolder.push_back("IDENTIFIER = ");
    }
}

void loopThrough(string line, vector<char> temp,  int &i, int &begining, int &end){
  string tempString = "";
  char tempChar;

  end = i;
  for (int j = begining; j < end; j++)
    {
      //Pulls the char element from the vector and appends it into the string
      tempChar = temp.at(j);
      tempString += tempChar;
    }
    begining = end + 1;
    compareKeywords(tempString);
}

void lexer(string line)
{

  vector<char> temp;
  int begining = 0;
  int end = 0;
  string contents = "";

  //copies the line and inserts it back into temp as chars
  copy(line.begin(), line.end(), back_inserter(temp));

  // Loops through the newly created vector<char>
  for(int i = 0; i < temp.size(); i++)
  {
    string contents = "";
    switch (temp[i]) {
      // Comments
      case '!':
        for (int k = i; k < temp.size(); k++)
        {
          if (temp.at(k) == '!') {
            i = k;
          }
        }
        break;

      // whitespace
      case ' ':
        loopThrough(line, temp, i, begining, end);
        break;

      // newline
      case '\n':
        loopThrough(line, temp, i, begining, end);
        break;

      // ===== SEPARATORS ======
      case '(':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("SEPARATOR  = ");
        break;

      case ')':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("SEPARATOR  = ");
        break;

      case '{':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("SEPARATOR  = ");
        break;

      case '}':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("SEPARATOR  = ");
        break;

      case '[':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("SEPARATOR  = ");
        break;

      case ']':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("SEPARATOR  = ");
        break;

      case ',':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("SEPARATOR  = ");
        break;

      case '.':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("SEPARATOR  = ");
        break;

      case ':':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("SEPARATOR  = ");
        // tokenHolder.push_back(" = SEPARATOR");
        break;

      case ';':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("SEPARATOR  = ");
        break;

      // ===== OPERATORS =====
      case '+':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("OPERATOR   = ");
        break;

      case '-':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("OPERATOR   = ");
        break;

      case '*':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("OPERATOR   = ");
        break;

      case '=':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("OPERATOR   = ");
        break;

      case '/':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("OPERATOR   = ");
        break;

      case '%':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("OPERATOR   = ");
        break;

      case '<':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("OPERATOR   = ");
        break;

      case '>':
        loopThrough(line, temp, i, begining, end);
        contents += temp.at(i);
        lexiconHolder.push_back(contents);
        tokenHolder.push_back("OPERATOR   = ");
        break;
      }
    }
  }

int main() {

  string var;
  //define and open the input file
  ifstream input_file("original Input.txt");
  //define and open the output file
  ofstream output_file("output.txt");

  //error check
  if ( !input_file.is_open() ) {
    cout << "There is no text file to read" << endl;
    exit(0);
  }
  //iterates through the file

  output_file << "LEXEMES" << "      " << "TOKENS" << endl << endl;
  while ( getline( input_file, var) )
  {
      var +='\n';
      lexer(var);
  }

  for(int i = 0; i < lexiconHolder.size(); i++)
  {
    output_file << tokenHolder.at(i) << lexiconHolder.at(i) << endl;
  }
  cout << "Check the output.txt for the results" << endl;
  input_file.close();
  output_file.close();
}
