#ifndef _PCH_HPP_
#define _PCH_HPP_

// ******************************
// *! include different
// *
// * #include <XXX.h> // C
// * #include <XXX>   // C++
// *
// * #include "XXX.hpp" // own
// *
// ******************************

// * 算法
#include <algorithm>
using std::max;
using std::min;

#include <utility>
using std::swap;

#include <cstring>  // C字串 // 不用 std::
#include <string.h> // C字串 // strcat
#include <string>
using std::string;

#include <limits>
using std::numeric_limits; // 通过模板 numeric_limits 来准确的获取具体数值类型的极值，避免数值的溢出。

// * STL
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::array;
using std::deque;
using std::forward_list;
using std::list;
using std::map;
using std::queue;
using std::set;
using std::stack;
using std::unordered_map;
using std::unordered_set;
using std::vector;

// * C++ 基本輸出入
#include <iostream>
// static int cin_cout_speedup = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }(); // cin endl 解綁, 加速输入輸出
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

// * 文件輸出入
#include <fstream>
using std::fstream;
using std::ifstream;
using std::ofstream;

// * 輸出 填滿
#include <iomanip>
using std::setfill;
using std::setw;

// * 鍵盤輸出入
#include <windows.h> // QueryPerformanceFrequency, QueryPerformanceCounter
                     // GetAsyncKeyState(VK_) // 鍵盤輸出入

// ! vvvvv e.g. using namespace std vvvvv
// using namespace std;
// ! ^^^^^ e.g. using namespace std ^^^^^

#endif // _PCH_HPP_