#include<bits/stdc++.h>
using namespace std;

namespace name1 {
  int x = 100;
}

namespace my_namespace {
  int x = 5;
}

int main() {

  cout << name1::x << endl;
  cout << my_namespace::x;
}
