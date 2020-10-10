#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define sd(n) scanf("%lf", &n)
#define pll pair <ll, ll>
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; i++)
#define for0(i, stop) for(ll i = 0; i < stop; i++)
#define rep1(i, start) for(ll i = start; i >= 1; i--)
#define rep0(i, start) for(ll i = (start-1); i >= 0; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define endl '\n'

string s;
vector <ll> v[3000009];
vector <ll> ans[3000009];
ll mx[3000009];

int main()
{
    fastio;
    ll n, k;
    cin >> n >> k;
    cin >> s;

    ll step = 0, tot = 0;
    while(1) {
        bool chk = 1;

        step++;
        for(ll i = 0; i < (ll)s.length() - 1; i++) {
            if(s[i] == 'R' && s[i+1] == 'L') {
                chk = 0;
                v[step].pb(i);
                tot++;

                swap(s[i], s[i+1]);
                i++;
            }
        }

        if(step > k && !chk) {
            cout << -1 << endl;
            return 0;
        }


        if(chk) break;
    }

    if(tot < k) {
        cout << -1 << endl;
        return 0;
    }

    ll sz = tot, rest = k, now = 1;
    for(ll i = 1; i <= step; i++) {
        for(ll idx : v[i]) {

            if(sz < rest) {
                cout << -1 << endl;
                return 0;
            }

            if(idx < mx[now]) {
                now++;
                ans[now].pb(idx);
                sz--, rest--;
                mx[now] = idx;
                continue;
            }

            if(sz == rest) {
                ans[now].pb(idx);
                sz--, rest--;
                now++;
                continue;
            }

            mx[now] = idx;
            ans[now].pb(idx);
            sz--;
        }
    }

    //cout << sz <<  "  " << rest << "  " << now << endl;
    if(sz != 0 || rest != 0) {
        cout << -1 << endl;
        return 0;
    }

    for(ll i = 1; i <= k; i++) {
        cout << ans[i].size();
        for(ll idx : ans[i])
            cout << " " << (idx+1);

        cout << endl;
    }

    return 0;
}