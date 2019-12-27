#include <tcframe/spec.hpp>
using namespace tcframe;
#define MAXN 10000000
#define MAXK 100000

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, K;
    int ans;

    void InputFormat() {
        LINE(N, K);
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(1 <= N && N <= MAXN);
        CONS(1 <= K && K <= MAXK);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "10 4"
        });
        Output({
            "0"
        });
    }

    void TestCases() {
        CASE(N = 1, K = 1);
        CASE(N = MAXN, K = MAXK);
        CASE(N = rnd.nextInt(1, MAXN/2) * 2 - 1, K = 1);
        CASE(N = rnd.nextInt(1, MAXN/2) * 2, K = 1);
        for(int i = 0; i < 4; i++){
            CASE(N = rnd.nextInt(1, MAXN/2) * 2, K = rnd.nextInt(1, MAXK));
        }
        CASE(N = rnd.nextInt(1, MAXN/2) * 2 - 1, K = 3);
        CASE(N = rnd.nextInt(1, MAXN/2) * 2 - 1, K = 5);
        CASE(N = rnd.nextInt(1, MAXN/2) * 2 - 1, K = 8);
        for(int i = 0; i < 9; i++){
            CASE(N = rnd.nextInt(1, MAXN/2) * 2 - 1, K = rnd.nextInt(1, MAXK));
        }
    }
};