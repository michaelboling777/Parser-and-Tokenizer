#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include "parser.hpp"

using namespace std;

//========================================================================
void parse_all_toks(vector<string> &parse_tok, ofstream &File_Exit)
{
    // this calls the non-terminal that will start it all
    Entire_Program(parse_tok, File_Exit);
    // after finished, gather what is left :)

    // if all the tokens incremented through equals the total tokens from the input file...
    if (parser_loc_count == parse_tok.size())
    {
        cout << "Parsing complete" << endl;
        File_Exit << "Parsing complete" << endl;

        cout << "The total amount of parse_tok parsed is..." << parser_loc_count << endl;
        File_Exit << "The total amount of parse_tok parsed is..." << parser_loc_count << endl;
    }
}
//========================================================================
void Entire_Program(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE Entire_Program  --> Generate_rec" << endl;
    File_Exit << "PRODUCTION RULE Entire_Program  --> Generate_rec" << endl;
    cout << endl;
    // just call Generate_rec..
    Generate_rec(parse_tok, File_Exit);
}
//========================================================================

void Generate_rec(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE Generate_rec   --> FuncDef Generate_rec | ε" << endl;
    File_Exit << "PRODUCTION RULE Generate_rec   --> FuncDef Generate_rec | ε" << endl;

    if (!parse_tok[parser_loc_count].empty())
    {
        // if not empty then call the 2 functions...
        FuncDef(parse_tok, File_Exit);
        Generate_rec(parse_tok, File_Exit);
    }
    else
    {
        // else, print epsilon char
        cout << endl;
        cout << "--> ε" << endl;
        File_Exit << "--> ε" << endl;

        cout << endl;
    }
}
//========================================================================

void L(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << endl;
    cout << "PRODUCTION RULE L --> read id ;" << endl;
    File_Exit << "PRODUCTION RULE L --> read id ;" << endl;
    // print out all 3 terminals ...
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;

    parser_loc_count++;
    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    parser_loc_count++;
    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    parser_loc_count++;
}
//========================================================================

void M(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << endl;
    cout << "PRODUCTION RULE M --> write Expr ;" << endl;
    File_Exit << "PRODUCTION RULE M --> write Expr ;" << endl;

    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    // increment past and call Expr
    parser_loc_count++;
    Expr(parse_tok, File_Exit);
    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    parser_loc_count++;
}
//========================================================================

void N(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE N --> let id = Expr ;" << endl;
    File_Exit << "PRODUCTION RULE N --> let id = Expr ;" << endl;

    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;
    // increment past terminals..
    cout << endl;
    parser_loc_count++;
    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    parser_loc_count++;
    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    parser_loc_count++;
    // stopping after here because I am not counting the ":" to be inputted only the "="
    Expr(parse_tok, File_Exit);
    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    parser_loc_count++;
}
//========================================================================

void O(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE O --> return Expr ;" << endl;
    File_Exit << "PRODUCTION RULE O --> return Expr ;" << endl;

    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    parser_loc_count++;
    // increment past return and call Expr non-terminal...
    Expr(parse_tok, File_Exit);
    // counting for the required semi-colons here....
    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    parser_loc_count++;
}
//========================================================================

void P(vector<string> &parse_tok, ofstream &File_Exit)
{

    cout << "PRODUCTION RULE P --> break ;" << endl;
    File_Exit << "PRODUCTION RULE P --> break ;" << endl;

    cout << endl;
    // output break...
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    // increment past break
    parser_loc_count++;

    // counting for the required semi-colon here....
    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    parser_loc_count++;
}
//========================================================================

void FuncDef(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE FuncDef --> function id ( Arg_list ) BlockStatements" << endl;
    File_Exit << "PRODUCTION RULE FuncDef --> function id ( Arg_list ) BlockStatements" << endl;

    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    parser_loc_count++;
    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;
    cout << endl;
    parser_loc_count++;

    if (parse_tok[parser_loc_count] == "(")
    {
        cout << endl;
        cout << "--> " << parse_tok[parser_loc_count] << endl;
        File_Exit << parse_tok[parser_loc_count] << endl;

        cout << endl;
        // increment past (
        parser_loc_count++;
        // call non-terminal
        Arg_list(parse_tok, File_Exit);
        cout << endl;
    }
    if (parser_loc_count < parse_tok.size() && parse_tok[parser_loc_count] == ")")
    {
        // check for closing ) and increment past it
        cout << endl;
        cout << "--> " << parse_tok[parser_loc_count] << endl;
        File_Exit << parse_tok[parser_loc_count] << endl;

        cout << endl;
        parser_loc_count++;
    }
    BlockStatements(parse_tok, File_Exit);
}
//========================================================================

void Arg_list(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE Arg_list --> ε | id Arg_sequence" << endl;
    File_Exit << "PRODUCTION RULE Arg_list --> ε | id Arg_sequence" << endl;

    if (!parse_tok[parser_loc_count].empty())
    {
        cout << endl;
        cout << "--> " << parse_tok[parser_loc_count] << endl;
        File_Exit << parse_tok[parser_loc_count] << endl;

        cout << endl;
        parser_loc_count++;
        // increment past id and call non-terminal
        Arg_sequence(parse_tok, File_Exit);
    }
    else
    {

        cout << endl;

        cout << "--> ε" << endl;
        File_Exit << "--> ε" << endl;

        cout << endl;
    }
}
//========================================================================

void Arg_sequence(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE Arg_sequence --> , id Arg_sequence | ε" << endl;
    File_Exit << "PRODUCTION RULE Arg_sequence --> , id Arg_sequence | ε" << endl;

    if (parse_tok[parser_loc_count] == ",")
    {
        cout << endl;
        cout << "--> " << parse_tok[parser_loc_count] << endl;
        File_Exit << parse_tok[parser_loc_count] << endl;

        cout << endl;
        parser_loc_count++;
        cout << endl;
        cout << "--> " << parse_tok[parser_loc_count] << endl;
        File_Exit << parse_tok[parser_loc_count] << endl;

        cout << endl;
        // increment past id
        parser_loc_count++;
        // call non-terminal
        Arg_sequence(parse_tok, File_Exit);
    }
    else
    {
        // then, its empty if we dont find ,

        cout << endl;
        cout << "--> ε" << endl;
        File_Exit << "--> ε" << endl;

        cout << endl;
    }
}
//========================================================================

void CallStatement(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE CallStatement --> call id ( arg_list_call ) ;" << endl;
    File_Exit << "PRODUCTION RULE CallStatement --> call id ( arg_list_call ) ;" << endl;

    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    parser_loc_count++;
    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    // increment past id...
    parser_loc_count++;
    if (parse_tok[parser_loc_count] == "(")
    {
        cout << endl;
        cout << "--> " << parse_tok[parser_loc_count] << endl;
        File_Exit << parse_tok[parser_loc_count] << endl;

        cout << endl;
        parser_loc_count++;
        // call non-terminal..
        arg_list_call(parse_tok, File_Exit);
        cout << endl;
    }
    if (parser_loc_count < parse_tok.size() && parse_tok[parser_loc_count] == ")")
    {
        // checking for closing parenthesis...
        cout << endl;
        cout << "--> " << parse_tok[parser_loc_count] << endl;
        File_Exit << parse_tok[parser_loc_count] << endl;

        cout << endl;
        parser_loc_count++;
    }
}
//========================================================================

void arg_list_call(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE arg_list_call --> ε | Expr arg_list_sequence" << endl;
    File_Exit << "PRODUCTION RULE arg_list_call --> ε | Expr arg_list_sequence" << endl;

    if (!parse_tok[parser_loc_count].empty())
    {
        // call non-terminals when not empty...
        Expr(parse_tok, File_Exit);
        arg_list_sequence(parse_tok, File_Exit);
    }
    else
    {
        cout << endl;
        cout << "--> ε" << endl;
        File_Exit << "--> ε" << endl;

        cout << endl;
    }
}
//========================================================================

void arg_list_sequence(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE arg_list_sequence --> ε | , Expr arg_list_sequence" << endl;
    File_Exit << "PRODUCTION RULE arg_list_sequence --> ε | , Expr arg_list_sequence" << endl;

    if (!parse_tok[parser_loc_count].empty())
    {
        cout << endl;
        cout << "--> " << parse_tok[parser_loc_count] << endl;
        File_Exit << parse_tok[parser_loc_count] << endl;

        cout << endl;
        // increment past "," and call non-terminals...
        parser_loc_count++;
        Expr(parse_tok, File_Exit);
        arg_list_sequence(parse_tok, File_Exit);
    }
    else
    {
        // empty...
        cout << endl;
        cout << "--> ε" << endl;
        File_Exit << "--> ε" << endl;

        cout << endl;
    }
}
//========================================================================

void BlockStatements(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE BlockStatements --> { Total_Statement }" << endl;
    File_Exit << "PRODUCTION RULE BlockStatements --> { Total_Statement }" << endl;

    if (parse_tok[parser_loc_count] == "{")
    {
        cout << endl;
        cout << "--> " << parse_tok[parser_loc_count] << endl;
        File_Exit << parse_tok[parser_loc_count] << endl;

        cout << endl;
        // increment past parenthesis and call nonterminal..
        parser_loc_count++;
        Total_Statement(parse_tok, File_Exit);
        cout << endl;
    }
    if (parser_loc_count < parse_tok.size() && parse_tok[parser_loc_count] == "}")
    {
        // check for and consume closing parenthesis...
        cout << endl;
        cout << "--> " << parse_tok[parser_loc_count] << endl;
        File_Exit << parse_tok[parser_loc_count] << endl;

        cout << endl;
        parser_loc_count++;
    }
}
//========================================================================

void Total_Statement(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE Total_Statement --> Statement Repeat_r | ε" << endl;
    File_Exit << "PRODUCTION RULE Total_Statement --> Statement Repeat_r | ε" << endl;

    if (!parse_tok[parser_loc_count].empty())
    {
        // if emtpy, call non- terminals...
        Statement(parse_tok, File_Exit);
        Repeat_r(parse_tok, File_Exit);
    }
    else
    {
        cout << endl;
        cout << "--> ε" << endl;
        File_Exit << "--> ε" << endl;

        cout << endl;
    }
}

//========================================================================

void Repeat_r(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE Repeat_r --> Statement Repeat_r | ε" << endl;
    File_Exit << "PRODUCTION RULE Repeat_r --> Statement Repeat_r | ε" << endl;

    if (!parse_tok[parser_loc_count].empty())
    {
        // if not empty then call non terminals...
        Statement(parse_tok, File_Exit);
        Repeat_r(parse_tok, File_Exit);
    }
    else
    {
        cout << endl;
        cout << "--> ε" << endl;
        File_Exit << "--> ε" << endl;

        cout << endl;
    }
}
//========================================================================

void Statement(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE Statement --> IfStatement | WhileStatement | Expr ; | L | M | N | O | P" << endl;
    File_Exit << "PRODUCTION RULE Statement --> IfStatement | WhileStatement | Expr ; | L | M | N | O | P" << endl;

    // checking token values w/ alot of if /else statements.. :)
    if (parser_loc_count < parse_tok.size() && (parse_tok[parser_loc_count] == "if"))
    {
        IfStatement(parse_tok, File_Exit);
    }
    else if (parser_loc_count < parse_tok.size() && (parse_tok[parser_loc_count] == "while"))
    {
        WhileStatement(parse_tok, File_Exit);
    }
    else if (parser_loc_count < parse_tok.size() && (parse_tok[parser_loc_count] == "call"))
    {
        CallStatement(parse_tok, File_Exit);
    }
    else if (parser_loc_count < parse_tok.size() && (parse_tok[parser_loc_count] == "read"))
    {
        L(parse_tok, File_Exit);
    }
    else if (parser_loc_count < parse_tok.size() && (parse_tok[parser_loc_count] == "write"))
    {
        M(parse_tok, File_Exit);
    }
    else if (parser_loc_count < parse_tok.size() && (parse_tok[parser_loc_count] == "let"))
    {
        N(parse_tok, File_Exit);
    }
    else if (parser_loc_count < parse_tok.size() && (parse_tok[parser_loc_count] == "return"))
    {
        O(parse_tok, File_Exit);
    }
    else if (parser_loc_count < parse_tok.size() && (parse_tok[parser_loc_count] == "break"))
    {
        P(parse_tok, File_Exit);
    }
    else
    {
        // then, it must be Expr...
        Expr(parse_tok, File_Exit);
    }
}
//========================================================================

void IfStatement(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE IfStatement --> ifkeyword ( CondExpr ) Which_State Optional_Else" << endl;
    File_Exit << "PRODUCTION RULE IfStatement --> ifkeyword ( CondExpr ) Which_State Optional_Else" << endl;

    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    // increment past ifkeyword
    parser_loc_count++;
    if (parse_tok[parser_loc_count] == "(" && parser_loc_count < parse_tok.size())
    {
        cout << endl;
        cout << "--> " << parse_tok[parser_loc_count] << endl;
        File_Exit << parse_tok[parser_loc_count] << endl;

        cout << endl;
        // increment past 1st brack...
        parser_loc_count++;
        CondExpr(parse_tok, File_Exit);
        cout << endl;
        if (parser_loc_count < parse_tok.size() && parse_tok[parser_loc_count] == ")")
        {
            cout << endl;
            cout << "--> " << parse_tok[parser_loc_count] << endl;
            File_Exit << parse_tok[parser_loc_count] << endl;

            cout << endl;
            // increment past 2nd brack...
            parser_loc_count++;
        }
    }
    // now call required non-terminals...
    Which_State(parse_tok, File_Exit);
    Optional_Else(parse_tok, File_Exit);
}
//========================================================================

void WhileStatement(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE WhileStatement --> whilekeyword ( CondExpr ) Which_State" << endl;
    File_Exit << "PRODUCTION RULE WhileStatement --> whilekeyword ( CondExpr ) Which_State" << endl;

    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    parser_loc_count++;

    if (parse_tok[parser_loc_count] == "(" && parser_loc_count < parse_tok.size())
    {
        cout << endl;
        cout << "--> " << parse_tok[parser_loc_count] << endl;
        File_Exit << parse_tok[parser_loc_count] << endl;

        cout << endl;
        // increment past first bracket...
        parser_loc_count++;
        CondExpr(parse_tok, File_Exit);
        cout << endl;
        if (parser_loc_count < parse_tok.size() && parse_tok[parser_loc_count] == ")")
        {
            cout << endl;
            cout << "--> " << parse_tok[parser_loc_count] << endl;
            File_Exit << parse_tok[parser_loc_count] << endl;

            cout << endl;
            // increment past 2nd bracket...
            parser_loc_count++;
        }
    }
    // now we should be able to call Which_State....
    Which_State(parse_tok, File_Exit);
}
//========================================================================

void Which_State(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE Which_State --> BlockStatements | Statement" << endl;
    File_Exit << "PRODUCTION RULE Which_State --> BlockStatements | Statement" << endl;

    if (parse_tok[parser_loc_count] == "{" && parser_loc_count < parse_tok.size())
    {
        BlockStatements(parse_tok, File_Exit);
    }
    // assume if no bracket input then its a statement...
    else
    {
        Statement(parse_tok, File_Exit);
    }
}
//========================================================================

void Optional_Else(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE Optional_Else --> elsekeyword Which_State | ε" << endl;
    File_Exit << "PRODUCTION RULE Optional_Else --> elsekeyword Which_State | ε" << endl;

    // check if token location is "else", perform grammar rules if so...
    if (parse_tok[parser_loc_count] == "else" && parser_loc_count < parse_tok.size())
    {
        cout << endl;
        cout << "--> " << parse_tok[parser_loc_count] << endl;
        File_Exit << parse_tok[parser_loc_count] << endl;

        cout << endl;
        parser_loc_count++;
        Which_State(parse_tok, File_Exit);
    }
    else
    {
        cout << endl;
        cout << "--> ε" << endl;
        File_Exit << "--> ε" << endl;

        cout << endl;
    }
}
//========================================================================

void CondExpr(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE CondExpr --> G H" << endl;
    File_Exit << "PRODUCTION RULE CondExpr --> G H" << endl;

    G(parse_tok, File_Exit);
    H(parse_tok, File_Exit);
}

//========================================================================

void G(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE G --> Expr I Expr" << endl;
    File_Exit << "PRODUCTION RULE G --> Expr I Expr" << endl;

    // of recursive nature.... "I" and the 2nd Expr will wait after the first Expr is "expanded"
    Expr(parse_tok, File_Exit);
    I(parse_tok, File_Exit);
    Expr(parse_tok, File_Exit);
}

//========================================================================

void H(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE H --> K G H | ε" << endl;
    File_Exit << "PRODUCTION RULE H --> K G H | ε" << endl;
    // checking if token is of the logical ops...
    if (parser_loc_count < parse_tok.size() && (parse_tok[parser_loc_count] == "&" || parse_tok[parser_loc_count] == "|"))
    {
        K(parse_tok, File_Exit);
        G(parse_tok, File_Exit);
        H(parse_tok, File_Exit);
    }
    else
    {
        // we can assume epsilon if not...
        cout << endl;
        cout << "--> ε" << endl;
        File_Exit << "--> ε" << endl;

        cout << endl;
    }
}

//========================================================================

void K(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE K --> & | |" << endl;
    File_Exit << "PRODUCTION RULE K --> & | |" << endl;

    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    parser_loc_count++;
}

//========================================================================

void I(vector<string> &parse_tok, ofstream &File_Exit)
{
    // check if token is of the operators...
    cout << "PRODUCTION RULE I --> > | < | == | <= | >= | !=" << endl;
    File_Exit << "PRODUCTION RULE I --> > | < | == | <= | >= | !=" << endl;

    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    // we must always increment parser_loc_count if we indeed do find a operator from our input file...
    parser_loc_count++;
}

//========================================================================

void Expr(vector<string> &parse_tok, ofstream &File_Exit)
{

    cout << "PRODUCTION RULE Expr --> A B" << endl;
    File_Exit << "PRODUCTION RULE Expr --> A B" << endl;

    A(parse_tok, File_Exit);
    B(parse_tok, File_Exit);
}

//========================================================================

void A(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE A --> D E" << endl;
    File_Exit << "PRODUCTION RULE A --> D E" << endl;

    D(parse_tok, File_Exit);
    E(parse_tok, File_Exit);
}

//========================================================================

void B(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE B --> C A B | ε" << endl;
    File_Exit << "PRODUCTION RULE B --> C A B | ε" << endl;
    // checking if current location is of the operators... if so then call the given functions (as specified by in the grammar)
    if (parser_loc_count < parse_tok.size() && (parse_tok[parser_loc_count] == "+" || parse_tok[parser_loc_count] == "-"))
    {
        C(parse_tok, File_Exit);
        A(parse_tok, File_Exit);
        B(parse_tok, File_Exit);
    }
    else
    {
        cout << endl;
        cout << "--> ε" << endl;
        File_Exit << "--> ε" << endl;

        cout << endl;
    }
}

//========================================================================

void C(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE C --> + | -" << endl;
    File_Exit << "PRODUCTION RULE C --> + | -" << endl;

    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    parser_loc_count++;
}

//========================================================================

void D(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE D --> ( Expr ) | id | number" << endl;
    File_Exit << "PRODUCTION RULE D --> ( Expr ) | id | number" << endl;

    if (parser_loc_count < parse_tok.size())
    {
        if (parse_tok[parser_loc_count] == "(")
        {
            cout << endl;
            cout << "--> " << parse_tok[parser_loc_count] << endl;
            File_Exit << parse_tok[parser_loc_count] << endl;

            cout << endl;
            parser_loc_count++;
            Expr(parse_tok, File_Exit);
            cout << endl;
            if (parser_loc_count < parse_tok.size() && parse_tok[parser_loc_count] == ")")
            {
                cout << endl;
                cout << "--> " << parse_tok[parser_loc_count] << endl;
                File_Exit << parse_tok[parser_loc_count] << endl;

                cout << endl;
                parser_loc_count++;
            }
        }
        else if (!parse_tok[parser_loc_count].empty())
        {
            cout << endl;
            cout << "--> " << parse_tok[parser_loc_count] << endl;
            File_Exit << "--> " << parse_tok[parser_loc_count] << endl;
            cout << endl;
            parser_loc_count++;

            //-------------
            // checking if ")" is at the end of either id or number

            if (parser_loc_count < parse_tok.size() && parse_tok[parser_loc_count] == ")")
            {
                cout << endl;
                cout << "--> " << parse_tok[parser_loc_count] << endl;
                File_Exit << "--> " << parse_tok[parser_loc_count] << endl;

                cout << endl;
                parser_loc_count++;
            }
        }
    }
}

//========================================================================

void E(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE E --> F D E | ε" << endl;
    File_Exit << "PRODUCTION RULE E --> F D E | ε" << endl;
    if (parser_loc_count < parse_tok.size() && (parse_tok[parser_loc_count] == "*" || parse_tok[parser_loc_count] == "/" || parse_tok[parser_loc_count] == "%" || parse_tok[parser_loc_count] == "^") && !parse_tok[parser_loc_count].empty())
    {

        F(parse_tok, File_Exit);
        D(parse_tok, File_Exit);
        E(parse_tok, File_Exit);
    }
    else
    {
        cout << endl;
        cout << "--> ε" << endl;
        File_Exit << "--> ε" << endl;

        cout << endl;
    }
}

//========================================================================

void F(vector<string> &parse_tok, ofstream &File_Exit)
{
    cout << "PRODUCTION RULE F --> * | / | % | power" << endl;
    File_Exit << "PRODUCTION RULE F --> * | / | % | power" << endl;

    cout << endl;
    cout << "--> " << parse_tok[parser_loc_count] << endl;
    File_Exit << parse_tok[parser_loc_count] << endl;

    cout << endl;
    parser_loc_count++;
}

//========================================================================

int main()
{
    //========================================================================
    char character;

    ifstream File_Here("parser_input.txt");
    ofstream File_Exit("parser_output.txt");

    ofstream myfile;

    string file_chars;
    myfile.open("parser_output.txt");

    // read and push tokens the vector
    while (File_Here >> file_chars)
    {
        file_tok.push_back(file_chars);
    }
    cout << "Parsing beginning... " << endl
         << endl;
    File_Exit << "Parsing beginning..." << endl
              << endl;

    for (int i = 0; i < file_tok.size(); i++)
    {
        cout << file_tok[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < file_tok.size(); i++)
    {
        File_Exit << file_tok[i] << " ";
    }
    parse_all_toks(file_tok, File_Exit);

    File_Here.close();
    File_Exit.close();

    return 0;

    //========================================================================
}
