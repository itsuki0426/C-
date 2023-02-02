#include <iostream>
using namespace std;
string S;
long long N, Q;
long long a[200009], b[200009];
long long T[200009], H[200009];
long long Power100[200009];
long long mod = 2147483647;
long long hash_value(int l, int r)
{
    long long val = H[r] - (H[l - 1] * Power100[r - l + 1] % mod);
    if (val < 0)
        val += mod;
    return val;
}
int main(void)
{
    cin >> N >> Q;
    cin >> S;
    for (int i = 1; i <= Q; i++)
        cin >> a[i] >> b[i];
    for(int i = 1; i<= N; i++) T[i] = (S[i - 1] - 'a') + 1;
    Power100[0] = 1; 
    for(int i = 1; i <= N; i++) Power100[i] = (100LL * H[i-1] + T[i]) % mod;
    H[0] = 1;
    for(int i = 1; i <= N; i++) H[i] = (100LL * H[i-1] + T[i]) % mod;
    for(int i = 1; i <= Q;i ++){
        long long hash1 = hash_value(a[i],(a[i] + b[i])/2);
        long long hash2 = hash_value(b[i],(a[i] + b[i])/2);
        if(hash1 == hash2) cout << "Yes" << endl;
        else cout << "No";
    }
} 