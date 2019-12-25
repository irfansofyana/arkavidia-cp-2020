#include <tcframe/spec.hpp>

using namespace tcframe;
using namespace std;

typedef long long LL;

const MAX_N = 100000;
const MAX_B = 100000;
const MAX_Q = 2000;

class ProblemSpec : public BaseProblemSpec{

};

class TestSpec : public BaseTestSpec<ProblemSpec>{
    protected:
        void TestCases(){
            for (int i = 0; i < 2; ++i){
                CASE(
                    N = rnd.nextInt(1, 1*MAX_N/100),
                    randomArrayRange(N, arr, 1, 1*MAX_B/5),
                    Q = rnd.nextInt(1, 1*MAX_Q/5),
                    randomQuery(N,Q,arr_q)
                );
            }
            for (int i = 0; i < 4; ++i){
                CASE(
                    N = rnd.nextInt(1, 1*MAX_N/10),
                    randomArrayRange(N, arr, 1, 1*MAX_B/5),
                    Q = rnd.nextInt(1, 1*MAX_Q/5),
                    randomQuery(N,Q,arr_q)
                );
            }
            for (int i = 0; i < 4; ++i){
                CASE(
                    N = rnd.nextInt(1, 1*MAX_N/10),
                    randomArrayRange(N, arr, 1, 1*MAX_B),
                    Q = rnd.nextInt(1, 1*MAX_Q),
                    randomQuery(N,Q,arr_q)
                );
            }
            for (int i = 0; i < 4; ++i){
                CASE(
                    N = rnd.nextInt(1, 1*MAX_N),
                    randomArrayRange(N, arr, 1, 1*MAX_B/5),
                    Q = rnd.nextInt(1, 1*MAX_Q/5),
                    randomQuery(N,Q,arr_q)
                );
            }
            for (int i = 0; i < 4; ++i){
                CASE(
                    N = rnd.nextInt(1, 1*MAX_N),
                    randomArrayRange(N, arr, 1, 1*MAX_B/5),
                    Q = rnd.nextInt(1, 1*MAX_Q),
                    randomQuery(N,Q,arr_q)
                );
            }
            for (int i = 0; i < 4; ++i){
                CASE(
                    N = rnd.nextInt(1, 1*MAX_N),
                    randomArrayRange(N, arr, 1, 1*MAX_B),
                    Q = rnd.nextInt(1, 1*MAX_Q),
                    randomQuery(N,Q,arr_q)
                );
            }
        }
    private: 
        void randomArrayRange(int N, vector<int> & a, int lo, int hi){
            a.clear();
            for (int i = 0; i < N; i++){
                a.push_back(rnd.nextInt(lo, hi));
            }
        }
        void randomQuery(int N,int Q,vector<pair<int,int> > q){
            int L,R;
            q.clear();
            for (int i = 0;i<Q;i++){
                L = rnd.nextInt(1,N);
                R = rnd.nextInt(L,N);
                q.push_back(make_pair(L,R));
            }
        }
};