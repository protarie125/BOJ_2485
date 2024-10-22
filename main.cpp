#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n;
vl T;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  T = vl(n);
  for (auto&& t : T) {
    cin >> t;
  }

  auto d = T[1] - T[0];
  for (auto i = 2; i < n; ++i) {
    const auto& dif = T[i] - T[i - 1];
    d = gcd(d, dif);
  }

  auto ans = T.back() - T.front();
  ans /= d;
  ans -= n;
  ans += 1;
  cout << ans;

  return 0;
}