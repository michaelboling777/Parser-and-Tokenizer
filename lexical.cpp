#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// global: (1)
int token_loc_count = 0;
vector<string> vector_token_store;
vector<string> stor_keyw_here = {"function", "if", "while", "break", "else", "return", "read", "write", "let", "call"};

//===========================================================
//===========================================================

// main function
vector<string> tokenizer(string input, ofstream &File_Exit, ofstream &tokens_t) //(2)
{
    while (token_loc_count < input.size())
    {

        // assign ch_name to given input location.... this is very important for when we "continue" so ch_name will get initialized at the beginning of the "while" loop
        char ch_name = 'a';
        ch_name = input[token_loc_count];

        //===========================================================
        //===========================================================

        // Check if the given character name at its iteration is a whitespace or not
        if (isspace(ch_name)) //(3)
        {
            // increment token_loc_count depending on how many we find
            token_loc_count++;

            // return to beg of while loop if found
            continue;
        }

        //===========================================================
        //===========================================================

        // we check if ch_name isdigit or not
        if (isdigit(ch_name)) // (4)
        {

            int final_locate = 1;

            final_locate = token_loc_count;

            // ONLY if final_locate < input string AND that specific value at input string is a digit or not
            while (isdigit(input[final_locate]) && final_locate < input.size())
            {
                final_locate++;
            }

            // We create a string from what we iterated through... and print it out and assign it integer value
            // since we know it to be (from inside our if statement)

            // NOTE: we print out value of string (what we iterated through) from starting position to the difference of our final position and our starting position

            cout << "Token: Integer(" << input.substr(token_loc_count, final_locate - token_loc_count) << ")" << endl;
            File_Exit << "Token: Integer(" << input.substr(token_loc_count, final_locate - token_loc_count) << ")" << endl;
            tokens_t << input.substr(token_loc_count, final_locate - token_loc_count) << endl;

            // We must update our token count with how many digits we iterated through.
            token_loc_count = final_locate;

            // go to beg of while loop
            continue;
        }

        //===========================================================
        //===========================================================

        // Now, create a string that represents ALL operators we must search for //(5)
        string Operators_values_all = "+-/*^%><=!|&{};,()";

        // We know .find() returns npos if nothing found hence, != npos we know our char is an operator in that string
        if (Operators_values_all.find(ch_name) != string::npos)
        {

            // create a string that will represent what we iterate through
            string Oper_value_tok;

            int final_locate = 1;

            final_locate = token_loc_count;

            // same pattern as when searching for integers... we just add the condition that the char must exist in our string
            while (final_locate < input.size() && (Operators_values_all.find(input[final_locate]) != string::npos))
            {

                final_locate++;
            }

            // the string represents all the chars we iterated through that are of our required operators value
            Oper_value_tok = input.substr(token_loc_count, final_locate - token_loc_count);

            // We will search for the given opeartor values and if the string represents them... we will print it out as such.

            if (Oper_value_tok == "|")
            {
                cout << "Token: Or(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: Or(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == "&")
            {
                cout << "Token: And(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: And(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == "!")
            {
                cout << "Token: Not(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: Not(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == "<")
            {
                cout << "Token: LThan(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: LThan(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == ">")
            {
                cout << "Token: GThan(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: GThan(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == "!=")
            {
                cout << "Token: Not Equal(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: Not Equal(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == "==")
            {
                cout << "Token: Equal(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: Equal(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == ">=")
            {
                cout << "Token: Greater Equal(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: Greater Equal(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == "<=")
            {
                cout << "Token: Less Equal(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: Less Equal(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == "=")
            {
                cout << "Token: Assignment(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: Assignment(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == "+")
            {
                cout << "Token: Addition(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: Addition(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == "-")
            {
                cout << "Token: Subtraction(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: Subtraction(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == "*")
            {
                cout << "Token: Multiplication(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: Multiplication(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == "/")
            {
                cout << "Token: Division(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: Division(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == "^")
            {
                cout << "Token: Power(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: Power(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == "%")
            {
                cout << "Token: Remainder or Modulo(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: Remainder or Modulo(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == "{")
            {
                cout << "Token: LPar(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: LPar(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == "}")
            {
                cout << "Token: RPar(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: RPar(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == "(")
            {
                cout << "Token: LBrac(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: LBrac(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == ")")
            {
                cout << "Token: RBrac(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: RBrac(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == ";")
            {
                cout << "Token: Semicolon(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: Semicolon(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }
            else if (Oper_value_tok == ",")
            {
                cout << "Token: Comma(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: Comma(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }

            // if nothing of the sort above was found then it must be an unknown
            else
            {
                cout << "Token: Unknown(" << Oper_value_tok << ")" << endl;
                File_Exit << "Token: Unknown(" << Oper_value_tok << ")" << endl;
                tokens_t << Oper_value_tok << endl;
            }

            token_loc_count = final_locate;

            // return to beg of while loop since we printed some value out
            continue;
        }

        //===========================================================
        //===========================================================

        // checking for comments....
        if (ch_name == '#') //(6)
        {
            int final_locate = token_loc_count;

            // pretty much same pattern as before... but now we loop until a newline char is found
            while (final_locate < input.size() && input[final_locate] != '\n')
            {

                final_locate++;
            }

            // Now that we use .substr to capture the "string" that represents our comment from when a # started to the termination (... it encountered a newline)
            // again, same pattern as before.
            cout << "Token: Comment(" << input.substr(token_loc_count, (final_locate - token_loc_count)) << ")" << endl;
            File_Exit << "Token: Comment(" << input.substr(token_loc_count, (final_locate - token_loc_count)) << ")" << endl;
            tokens_t << input.substr(token_loc_count, (final_locate - token_loc_count)) << endl;
            token_loc_count = final_locate;

            // go to beg of while loop
            continue;
        }

        //===========================================================
        //===========================================================

        // Now, we have covered integers, operators, and comments... so we must check for identifiers, keywords, and unknowns still

        // check if the char is of alphabetic value or not...
        if (isalpha(ch_name)) //(7)
        {
            int final_locate = 1;
            final_locate = token_loc_count;

            // same thing as before ... except, we must check if the char at the given location is either a num or an alphabet
            while ((isalnum(input[final_locate])) && final_locate < input.size())
            {
                // if true... increment
                final_locate++;
            }

            // now, I create a string that I am going to compare to see if it is of a required keyword or not
            // this string represents everything that was iterated through above (until our while loop conditions were not satisfied)
            string keyword_verify_str = input.substr(token_loc_count, final_locate - token_loc_count);

            // Now, our vector that represents our keywords ... we must use the .find() functionto compare if the string we created using the above while loop is contained at all in that vector
            // So, if the .find() f(x) actually finds keyword_verify_str in the vector it WILL not be at the .end()
            if (find(stor_keyw_here.begin(), stor_keyw_here.end(), keyword_verify_str) != stor_keyw_here.end())
            {
                // if found keyword... then state the string that supposedly represents it!

                cout << "Token: Keyword(" << input.substr(token_loc_count, final_locate - token_loc_count) << ")" << endl;
                File_Exit << "Token: Keyword(" << input.substr(token_loc_count, final_locate - token_loc_count) << ")" << endl;
                tokens_t << input.substr(token_loc_count, final_locate - token_loc_count) << endl;
            }
            else
            {
                // We can see that our last condition for the tokenizer is to check for an identifier... well if we made it this far
                //  and the string we created is not a keyword we can assume it IS an identifier

                // NOTE ... also, we know its not an unknown value because we specified that the character must start with an alphabetic character
                // which was stated by our directions ... but it can also be alphanumeric (we covered that in our while loop) .. also stated in directions.

                cout << "Token: Identifier(" << input.substr(token_loc_count, final_locate - token_loc_count) << ")" << endl;
                File_Exit << "Token: Identifier(" << input.substr(token_loc_count, final_locate - token_loc_count) << ")" << endl;
                tokens_t << input.substr(token_loc_count, final_locate - token_loc_count) << endl;
            }
            // update tok location
            token_loc_count = final_locate;

            // return to beg of while loop
            continue;
        }

        //===========================================================
        //===========================================================

        // Once we have made it this far... the only thing left for that single specific character to be ... is of unknown value
        // so, we must cover that condition...
        cout << "Token: Unknown(" << ch_name << ")" << endl; //(8)
        File_Exit << "Token: Unknown(" << ch_name << ")" << endl;
        tokens_t << ch_name << endl;

        token_loc_count++;
    }

    return vector_token_store;
}

//===========================================================
//===========================================================

int main()
{
    char character;

    ifstream File_Here("input.txt");
    ofstream File_Exit("lexical_output.txt");
    ofstream tokens_t("parser_input.txt");

    ofstream myfile;
    ofstream myfile2;
    myfile.open("lexical_output.txt");
    myfile2.open("parser_input.txt");

    string file_chars;

    while (File_Here.get(character))
    {
        file_chars = (file_chars + character);
    }

    tokenizer(file_chars, myfile, myfile2);

    File_Here.close();
    File_Exit.close();

    return 0;
}
