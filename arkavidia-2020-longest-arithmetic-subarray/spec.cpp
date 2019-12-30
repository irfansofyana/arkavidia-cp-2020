#include <tcframe/spec.hpp>
#include <assert.h>

using namespace tcframe;
using namespace std;

const int MAXN = 100000;
const int MAXQ = 100000;
const int MAXB = 1000000000;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    vector<int> arr;
    int Q;
    vector<int> L, R;
    vector<int> ans;
    
    void InputFormat() {
        LINE(N);
		LINE(arr % SIZE(N));
		LINE(Q);
        LINES(L, R) % SIZE(Q);
    }

    void OutputFormat() {
        LINES(ans) % SIZE(Q);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(1 <= N && N <= MAXN);
        CONS(eachElementBetween(arr, -MAXB, MAXB));
        CONS((int)arr.size() == N);
        CONS(1 <= Q && Q <= MAXQ);
        CONS((int)L.size() == Q);
        CONS((int)R.size() == Q);
        CONS(eachElementBetween(L, 1, N));
        CONS(eachElementBetween(R, 1, N));
        CONS(validRangeQuery(L, R));
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

    bool validRangeQuery(const vector<int>& L, const vector<int>& R){
        assert((int)L.size() == (int)R.size());
        for (int i = 0; i < (int)L.size(); ++i){
            if (L[i] > R[i]) return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
	
	
    void SampleTestCase1() {
        Input({
            "8",
			"1 3 5 6 7 8 10 12",
			"3",
            "1 8",
            "2 4",
            "6 6"
        });
        Output({
            "4",
            "2",
            "1"
        });
    }
	
	void BeforeTestCase() {
		
	}	

    void TestCases() {
       
    }

private:
  

};

