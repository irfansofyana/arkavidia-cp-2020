#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    long long A;
    int res;

    void InputFormat() {
        LINE(A);
    }

    void OutputFormat() {
        LINE(res);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(1 <= A && A <= 1000000000000000000);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "4"
        });
        Output({
            "8"
        });
    }
    void SampleTestCase2() {
        Input({
            "5"
        });
        Output({
            "22"
        });
    }

    void TestCases() {
        CASE(A = 4);
        CASE(A = 5);
        CASE(A = 19283928192);
        CASE(A = 500000);
        CASE(A = 1000000000000000000);
        CASE(A = 3);
        CASE(A = 1000000000000);
        CASE(A = 283928192892222222);
        CASE(A = rnd.nextLongLong(1, 1000000000000000000));
        CASE(A = rnd.nextLongLong(1, 1000000000000000000));
        CASE(A = rnd.nextLongLong(1, 1000000000000000000));
        CASE(A = rnd.nextLongLong(1, 1000000000000000000));
        CASE(A = rnd.nextLongLong(1, 1000000000000000000));
    }
};