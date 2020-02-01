#include <tcframe/spec.hpp>
using namespace tcframe;

#define sz(a) (int)(a).size()
using ll = long long;

const int MAXN = 1e5;
const int MAXSZ = 50;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    vector<string> S;
    string ans;
    string impossible = "Tidak memiliki solusi";

    void InputFormat() {
        LINE(N);
        LINES(S) % SIZE(N);
    }

    // benerin multiple output format nanti
    void OutputFormat1() {
        RAW_LINE(impossible);
    }

    void OutputFormat2() {
        LINE(ans);
    }
    // -----

    void GradingConfig() {
        TimeLimit(1); // jangan lupa diganti
        MemoryLimit(64); // jangan lupa diganti
    }

    void Constraints() {
        CONS(1 <= N && N <= MAXN);
        CONS(eachStringValid(S));
        CONS(validInfinite(ans)); // checker belum ada
    }
private:
    bool eachStringValid(vector<string> S) {
        for (int i = 0; i < sz(S); i++) {
            if (!validSize(S[i])) {
                return false;
            }
            for (int j = 0; j < sz(S[i]); j++) {
                if (S[i][j] != 'A' && S[i][j] != 'B') {
                    return false;
                }
            }
        }
        return true;
    }

    bool validSize(string s) {
        return (1 <= sz(s) && sz(s) <= MAXSZ);
    }

    bool validInfinite(string ans) {
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "2",
            "A",
            "BBB"
        });
        Output({
            "Tidak memiliki solusi"
        });
    }

    map<ll, bool> vis[2];
    void BeforeTestCase() {
        S.clear();
        vis[0].clear();
        vis[1].clear();
    }

    void TestCases() {
        CASE(N = 1, randomArray(1, 1));
        CASE(N = 1, randomArray(2, 2));
        CASE(N = 1, randomArray(3, 3));
        CASE(N = 3, randomArray(2, 5));
        // tambah lagi nanti

        // MAX CONSTRAINT
        CASE(N = MAXN, randomArray(MAXSZ, MAXSZ));
    }
private:
    ll shift(int x) {
        return (ll) ((ll)1 << x);
    }

    string numToString(ll num, int type) {
        // biar gampang generate stringnya, pake bitmask
        // ada dua tipe mask, satu buat yang diawalin A...., satu lagi buat yang diawalin B
        // misal mask sama, type beda:
        // mask : 00000100010
        // mask 00000100010 type 0 jadi ABBBAB
        // mask 00000100010 type 1 jadi BAAABA
        string ret = "";
        int startBit;
        for (int i = 49; i >= 0; i--) {
            if (shift(i) & num) {
                startBit = i;
                break;
            }
        }
        while (startBit >= 0) {
            if (shift(startBit) & num) {
                if (type == 0) {
                    ret += "A";
                } else {
                    ret += "B";
                }
            } else {
                if (type == 0) {
                    ret += "B";
                } else {
                    ret += "A";
                }
            }
            startBit--;
        }
        return ret;
    }

    string makeString(int mnSz, int mxSz, int type) {
        ll num = rnd.nextLongLong(shift(mnSz - 1), shift(mxSz) - 1);
        while (vis[type][num]) {
            num = rnd.nextLongLong(shift(mnSz - 1), shift(mxSz) - 1);
        }
        vis[type][num] = true;
        return numToString(num, type);
    }

    void randomArray(int mnSz, int mxSz) {
        for (int i = 0; i < N; i++) {
            int rng = rnd.nextInt(0, 1);
            S.push_back(makeString(mnSz, mxSz, rng));
        }
    }

    // add more array type soon
};