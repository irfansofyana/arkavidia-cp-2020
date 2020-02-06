#include <tcframe/spec.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace tcframe;

const int MAXQ = 2e4;

class ProblemSpec: public BaseProblemSpec{
    protected:
        int q;
        vector<int> op;
        vector<string> query_string;
        vector<int> ans;

        void InputFormat(){
            LINE(q);
            LINES(op, query_string) % SIZE(q);
        }

        void OutputFormat(){
            LINES(ans) % SIZE(q);
        }

        void GradingConfig(){
            TimeLimit(2);
            MemoryLimit(128);
        }

        void Constraints(){
            CONS(1 <= q && q <= MAXQ);
            CONS(stringContainsAB(query_string));
            CONS(eachElementBetween(op, 1, 2));
            CONS(stringSize(query_string));
        }

    private:
        bool stringContainsAB(const vector<string>& a){
            for (string x : a){
                for (int j = 0; j < x.size(); ++j){
                    if (x[j] != 'A' && x[j] != 'B'){
                        return false;
                    }
                }
            }
            return true;
        }

        bool eachElementBetween(const vector<int>& a, int lo, int hi){
            for (int x : a){
                if (x < lo || x > hi) {
                    return false;
                }
            }
            return true;
        }

        bool stringSize(const vector<string> &a){
            for (string x : a){
                if (x.size() > 30) {
                    return false;
                }
            }
            return true;
        }
};

class TestSpec : public BaseTestSpec<ProblemSpec>{
    protected:
        void BeforeTestCase(){
            op.clear();
            query_string.clear();
        }

        void TestCases(){
            CASE(q = 5, op={1, 1, 1, 2, 2}, query_string={"ABAB","ABAA","ABAAA", "ABAB", "ABAAA"});
            CASE(q = 6, op={1, 1, 1, 1, 1, 1}, query_string={"AAABBB", "AAAB", "AAAAAAB", "AAB", "AAAAAAAAAAAAAAAAAA", "AAABA"});
            for (int i = 0; i < 3; ++i){
                CASE(
                    q = rnd.nextInt(10, 100),
                    randomOperation(q, op, query_string, q/5)
                );
            }
            for (int i = 0; i < 3; ++i){
                CASE(
                    q = rnd.nextInt(101, 1000),
                    randomOperation(q, op, query_string, q/10)
                );
            }
            for (int i = 0; i < 3; ++i){
                CASE(
                    q = rnd.nextInt(1001, 10000),
                    randomOperation(q, op, query_string, q/100)
                );
            }
            for (int i = 0; i < 5; ++i){
                CASE(
                    q = rnd.nextInt(10001, MAXQ),
                    randomOperation(q, op, query_string, q/1000)
                );
            }
        }

    private:
        string randomString(int n){
            string res = "";
            for (int i = 0; i < n; ++i){
                int ch = rnd.nextInt(0, 1);
                res += char(ch + 'A');
            }
            return res;
        }

        string randomStringAB(int n, int tipe){
            string res = "";
            int k;
            if (n == 1) k = 1;
            else k = rnd.nextInt(1, n/2);
            for (int i = 0; i < k; ++i){
                res += (tipe == 0 ? 'A' : 'B');
            }
            for (int i = 0; i < n-k; ++i){
                int rd = rnd.nextInt(0, 1);
                res += char(rd + 'A');
            }
            return res;
        }

        void randomOperation(int q, vector<int> &op, vector<string> &query_string, int limit){
            multiset<string> ms;
            int phase1 = rnd.nextInt(1, q/3);
            for (int i = 0; i < phase1; ++i){
                int sz = rnd.nextInt(1, 30);
                string tes = randomStringAB(sz, rnd.nextInt(0, 1));
                ms.insert(tes);
                query_string.push_back(tes);
                op.push_back(1);
            }
            
            int cnt = 0;
            for (int i = 0; i < q-phase1; ++i){
                if (cnt < limit/3 || ms.size() == 0){
                    int sz = rnd.nextInt(1, 30);
                    string tes = (rnd.nextInt(0, 1) == 0 ? randomString(sz):randomStringAB(sz, rnd.nextInt(0, 1)));
                    ms.insert(tes);
                    query_string.push_back(tes);
                    op.push_back(1);
                }else{
                    int sz = min((int)ms.size(), 1000);
                    string get = *(ms.begin());
                    for (multiset<string>::iterator it = ms.begin(); sz > 0 && it != ms.end(); ++it){
                        --sz;
                        if (sz == 0){
                            get = *it;
                            break;
                        }
                    }
                    query_string.push_back(get);
                    ms.erase(ms.find(get));
                    op.push_back(2);
                }
                ++cnt;
                if (cnt == limit) cnt = 0;
            }
        }

};