#define toStr(s) #s
#define io(v) std::cin >> v
#define foreach(v, i) for (size_t i = 0, end = v.size(); i < end; ++i)
#define FUNCTION(name, op) static inline void name(int &a, int const &b) {if (b op a) a = b;}
#define INF ((unsigned int) -1)

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
    int n; cin >> n;
    vector<int> v(n);
    foreach(v, i) {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach(v, i) {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }
    int ans = mx - mn;
    cout << toStr(Result =) <<' '<< ans;
    return 0;
}
