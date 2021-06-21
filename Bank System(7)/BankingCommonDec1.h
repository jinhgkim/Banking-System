#ifndef BANKING_COMMON_H
#define BANKING_COMMON_H

#include<iostream>
#include<cstring>

using namespace std;
const int NAME_LEN = 20;

enum { NEW_ACCOUNT = 1, DEPOSIT, WITHDRAW, VIEW_ACCOUNT, EXIT };
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
enum { NORMAL = 1, CREDIT = 2 };

#endif // !BANKING_COMMON_H

