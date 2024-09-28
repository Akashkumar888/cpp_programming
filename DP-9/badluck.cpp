#include<iostream>
#include<vector>
#include<cstring>
#include<iomanip>
using namespace std;
double dp_r[101][101][101];
double dp_s[101][101][101];
double dp_p[101][101][101];
double fr(int r, int s, int p) {
    if (r == 0 || s == 0) return 0.0;
    if (p == 0) return 1.0;
    if (dp_r[r][s][p] > -0.9) return dp_r[r][s][p];
    double ans = 0.0;
    double total = r*s+s*p+p*r;
    ans += fr(r, s - 1, p) * (r * s) / total;
    ans += fr(r, s, p - 1) * (s * p) / total;
    ans += fr(r - 1, s, p) * (p * r) / total;
    dp_r[r][s][p] = ans;
    return ans;
}

double fs(int r, int s, int p) {
    if (p == 0 || s == 0) return 0.0;
    if (r == 0) return 1.0;
    if (dp_s[r][s][p] > -0.9) return dp_s[r][s][p];

    double ans = 0.0;
    double total = r * s + s * p + p * r;
    ans += fs(r, s - 1, p) * (r * s) / total;
    ans += fs(r, s, p - 1) * (s * p) / total;
    ans += fs(r - 1, s, p) * (p * r) / total;
    dp_s[r][s][p] = ans;
    return ans;
}

double fp(int r, int s, int p) {
    if (r == 0 || p == 0) return 0.0;
    if (s == 0) return 1.0;
    if (dp_p[r][s][p] > -0.9) return dp_p[r][s][p];

    double ans = 0.0;
    double total = r * s + s * p + p * r;
    ans += fp(r, s - 1, p) * (r * s) / total;
    ans += fp(r, s, p - 1) * (s * p) / total;
    ans += fp(r - 1, s, p) * (p * r) / total;
    dp_p[r][s][p] = ans;
    return ans;
}

int main() {
    int r, s, p;
    cin >> r >> s >> p;

    memset(dp_r, -1.0, sizeof(dp_r));
    memset(dp_s, -1.0, sizeof(dp_s));
    memset(dp_p, -1.0, sizeof(dp_p));

    double ans_r = fr(r, s, p);
    double ans_s = fs(r, s, p);
    double ans_p = fp(r, s, p);

    cout << fixed << setprecision(12) << ans_r << " " << ans_s << " " << ans_p << endl;

    return 0;
}
