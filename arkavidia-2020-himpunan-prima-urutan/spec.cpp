#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    vector<int> H;
    long long K;
    int res;

    void InputFormat() {
        LINE(N);
        LINE(H % SIZE(N));
        LINE(K);
    }

    void OutputFormat() {
        LINE(res);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(1 <= N && N <= 100000);
        CONS(eachElementBetween(H, 2, 2000000));
        CONS(1 <= K && K <= 1000000000000000000);
    }

private:
    bool eachElementBetween(const vector<int>& v, int lo, int hi) {
        for (int x : v) {
            if (x < lo || x > hi) {
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "2",
            "2 3",
            "9"
        });
        Output({
            "6"
        });
    }

    void TestCases() {
        CASE(N = 2, H = {2, 3}, K = 9);
        CASE(N = 1, H = {2}, K = 64);
        CASE(N = 3, H = {3, 5, 7}, K = 21);
    }
};
