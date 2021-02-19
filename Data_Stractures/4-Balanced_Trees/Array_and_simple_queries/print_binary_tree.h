#ifndef __PRINT_BINARY_TREE_H_INCLUDED__
#define __PRINT_BINARY_TREE_H_INCLUDED__

#include <fstream>
#include <iostream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>

#include "implicit_treap.h"

int maxHeight(node *p);
std::string intToString(int val);
void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<node*>& nodesQueue, std::ostream& out);
void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<node*>& nodesQueue, std::ostream& out);
void printLeaves(int indentSpace, int level, int nodesInThisLevel, const std::deque<node*>& nodesQueue, std::ostream& out);
void printPretty(node *root, int level, int indentSpace, std::ostream& out);

#endif
// __PRINT_BINARY_TREE_H_INCLUDED__
