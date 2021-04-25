#pragma once
using namespace std;

namespace ph::assembly {
extern "C" int someFunction();
extern "C" double sum (double [], unsigned);
extern "C" int myloop ();
extern "C" int passing_one_parameter (int);
extern "C" int passing_two_parameters (int, int);
extern "C" int passing_three_parameters (int, int, int);
extern "C" int passing_four_parameters (int, int, int, int);
}
