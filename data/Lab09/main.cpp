#include "executive.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {

  string filename = argv[1];
  executive exec(filename);
  return 0;
}