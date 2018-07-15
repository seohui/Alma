#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int n, m;
int n_in[101] = { 0, };
int m_in[101] = { 0, };
int n_seq[101] = { 0, };
int m_seq[101] = { 0, };

int max_LIS(int base, int n_index, int m_index) {
    if (n_index >= n && m_index >= m)
        return 0;
    int n_target=n, m_target=m;
    for (int i=n_index; i<n; i++) {
        if (base <= n_in[i]) {
            n_target = i;
            break;
        }
    }
    for (int i=m_index; i<m; i++) {
        if (base <= m_in[i]) {
            m_target = i;
            break;
        }
    }
    if (n_target == n && m_target == m) {
        return 0;
    } else if (n_target == n) {
        if (m_seq[m_target] != -1)
            return m_seq[m_target];
        return m_seq[m_target] = max_LIS(m_in[m_target], n_target, m_target+1)+1;
    } else if (m_target == m) {
        if (n_seq[n_target] != -1)
            return n_seq[n_target];
        return n_seq[n_target] = max_LIS(n_in[n_target], n_target+1, m_target)+1;
    } else {
        if (n_in[n_target] == m_in[m_target]) {
            if (n_seq[n_target] != -1)
                return n_seq[n_target];
            return n_seq[n_target] = m_seq[m_target] = 
                max_LIS(n_in[n_target], n_target+1, m_target+1)+1;
        } else if (n_in[n_target] < m_in[m_target]) {
            if (n_seq[n_target] != -1)
                return n_seq[n_target];
            return n_seq[n_target] = max_LIS(n_in[n_target], n_target+1, m_target)+1;
        } else {
            if (m_seq[m_target] != -1)
                return m_seq[m_target];
            return m_seq[m_target] = max_LIS(m_in[m_target], n_target, m_target+1)+1;
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> n >> m;
        memset(n_seq, -1, (n+1)*sizeof(int));
        memset(m_seq, -1, (m+1)*sizeof(int));
        for (int i=0; i<n; i++)
            cin >> n_in[i];
        for (int i=0; i<m; i++)
            cin >> m_in[i];
        int max = 0;
        for (int i=0; i<n; i++) {
            if (max < max_LIS(INT_MIN, i, 0))
                max = n_seq[i];
        }
        for (int j=0; j<m; j++) {
            if (max < max_LIS(INT_MIN, 0, j))
                max = m_seq[i];
        }
        cout << max<< endl;
    }
    return 0;
}
