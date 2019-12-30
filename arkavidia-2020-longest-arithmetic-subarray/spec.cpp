#include <tcframe/spec.hpp>

using namespace tcframe;
using namespace std;


class ProblemSpec : public BaseProblemSpec {
protected:
    
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
        CONS(1 <= N && N <= NMax);
		CONS(eachElementBetween(H, 2, HMax));
		CONS(1 <= K && K <= INF);
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
	
	void BeforeTestCase() {
		H.clear();
		isPrime.assign(HMax + 1, true);
		isPrime[1] = false;
		for (long long i = 2; i <= HMax; i++) {
			if (isPrime[i]) {
				primes.push_back(i);
				for (long long j = i * i; j <= HMax; j += i)
					isPrime[j] = false;			
			}
		}
		lenPrimes = (int) primes.size() - 1;
	}	

    void TestCases() {
       
    }

private:
  

};

