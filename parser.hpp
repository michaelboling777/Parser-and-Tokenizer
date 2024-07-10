#ifndef PARSER_HPP
#define PARSER_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <string>
#include <stack>
using namespace std;

// global
vector<string> file_tok;
int parser_loc_count;

// part (a)
void Expr(vector<string> &parse_tok, ofstream &File_Exit);
void A(vector<string> &parse_tok, ofstream &File_Exit);
void B(vector<string> &parse_tok, ofstream &File_Exit);
void C(vector<string> &parse_tok, ofstream &File_Exit);
void D(vector<string> &parse_tok, ofstream &File_Exit);
void E(vector<string> &parse_tok, ofstream &File_Exit);
void F(vector<string> &parse_tok, ofstream &File_Exit);

// part (b)
void CondExpr(vector<string> &parse_tok, ofstream &File_Exit);
void G(vector<string> &parse_tok, ofstream &File_Exit);
void H(vector<string> &parse_tok, ofstream &File_Exit);
void I(vector<string> &parse_tok, ofstream &File_Exit);
void J(vector<string> &parse_tok, ofstream &File_Exit);
void K(vector<string> &parse_tok, ofstream &File_Exit);

// part (c)
void BlockStatements(vector<string> &parse_tok, ofstream &File_Exit);
void Total_Statement(vector<string> &parse_tok, ofstream &File_Exit);
void Repeat_r(vector<string> &parse_tok, ofstream &File_Exit);
void Statement(vector<string> &parse_tok, ofstream &File_Exit);
void IfStatement(vector<string> &parse_tok, ofstream &File_Exit);
void Which_State(vector<string> &parse_tok, ofstream &File_Exit);
void Optional_Else(vector<string> &parse_tok, ofstream &File_Exit);
void WhileStatement(vector<string> &parse_tok, ofstream &File_Exit);

// part (d)
void FuncDef(vector<string> &parse_tok, ofstream &File_Exit);
void Arg_list(vector<string> &parse_tok, ofstream &File_Exit);
void Arg_sequence(vector<string> &parse_tok, ofstream &File_Exit);
void CallStatement(vector<string> &parse_tok, ofstream &File_Exit);
void arg_list_call(vector<string> &parse_tok, ofstream &File_Exit);
void arg_list_sequence(vector<string> &parse_tok, ofstream &File_Exit);

// part (e)
void L(vector<string> &parse_tok, ofstream &File_Exit);
void M(vector<string> &parse_tok, ofstream &File_Exit);
void N(vector<string> &parse_tok, ofstream &File_Exit);
void O(vector<string> &parse_tok, ofstream &File_Exit);
void P(vector<string> &parse_tok, ofstream &File_Exit);

// part (f)
void Entire_Program(vector<string> &parse_tok, ofstream &File_Exit);
void Generate_rec(vector<string> &parse_tok, ofstream &File_Exit);

#endif
