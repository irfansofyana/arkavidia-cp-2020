#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int Max = 100000;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, M, K;
    vector<int> U, V;
    vector<int> res;

    void InputFormat() {
        LINE(N, M, K);
        LINES(U, V) % SIZE(M);
    }

    void OutputFormat() {
        LINES(res) % SIZE(N);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(1 <= N && N <= Max);
        CONS(1 <= M && M <= Max);
        CONS(1 <= K && K <= Max);
        CONS(eachElementBetween(U, 0, N - 1));
        CONS(eachElementBetween(V, 0, N - 1));
        CONS(noDoubleEdge(U, V));
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

    bool noDoubleEdge(const vector<int> &u, const vector<int>& v) {
  		int len = u.size();
  		set<int> st[N + 5];
  		for (int i = 0; i < len; i++) {
  			if (st[u[i]].find(v[i]) != st[u[i]].end()) return false;
  			st[u[i]].insert(v[i]);
  		}
  		return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
    	Input({
    		"3 6 2",
    		"0 1",
    		"0 2",
    		"1 0",
    		"1 2",
    		"2 0",
    		"2 1"
    	});
    	Output({
    		"6",
    		"3",
    		"3"
    	});
    }

    void BeforeTestCase() {
        U.clear();
        V.clear();
        res.clear();
    }

    void TestCases() {
    	CASE(N = 5, M = 3, K = 2, randomGraph(N, M, U, V));
    	CASE(N = 7, M = 2, K = 1, randomGraph(N, M, U, V));
    	CASE(N = 10, M = 8, K = 10, randomGraph(N, M, U, V));
    	CASE(N = 1, M = 1, K = 10, U = {0}, V = {0});
    	CASE(N = 2, M = 2, K = 2, randomConnectedGraph(N, M, U, V));
    	CASE(N = 5, M = 4, K = 3, randomConnectedGraph(N, M, U, V));
    	CASE(N = 10, M = 9, K = 1000, randomConnectedGraph(N, M, U, V));
    	for (int i = 0; i < 5; i++) {
    		CASE(N = rnd.nextInt(10, Max / 2), M = rnd.nextInt(1, N - 2), K = rnd.nextInt(1, Max), randomGraph(N, M, U, V));
    	}
    	for (int i = 0; i < 5; i++) {
    		CASE(N = rnd.nextInt(Max / 2 + 1, Max), M = rnd.nextInt(1, N - 2), K = rnd.nextInt(Max / 2, Max), randomGraph(N, M, U, V));
    	}
    	for (int i = 0; i < 5; i++) {
    		CASE(N = rnd.nextInt(10, Max / 2), M = rnd.nextInt(N - 1, N + rnd.nextInt(0, 105)), K = rnd.nextInt(1, Max), randomConnectedGraph(N, M, U, V));
    	}
    	for (int i = 0; i < 5; i++) {
    		CASE(N = rnd.nextInt(Max / 2 + 1, Max), M = rnd.nextInt(N - 1, N + rnd.nextInt(0, 105)), K = rnd.nextInt(Max / 2, Max), randomConnectedGraph(N, M, U, V));
    	}
    	CASE(N = 10, M = 100, completeGraph(N, M, U, V));
    	CASE(N = 100, M = 10000, completeGraph(N, M, U, V));
    	CASE(N = 316, M = 99856, completeGraph(N, M, U, V));
    }

private:

    void renumber(int n, vector<int>& u, vector<int>& v) {
        vector<int> permutation;
        for (int i = 0; i < n; i++) {
            permutation.push_back(i);
        }
        rnd.shuffle(permutation.begin(), permutation.end());
        for (int i = 0; i < (int) u.size(); i++) {
            u[i] = permutation[u[i]];
            v[i] = permutation[v[i]];
        }
    }

    void randomGraph(int n, int m, vector<int>& u, vector<int>& v) {
    	set<int> st[N + 5];
    	for (int i = 1; i <= m; i++) {
    		int cur_u, cur_v;
    		while (1) {
    			cur_u = rnd.nextInt(0, n - 1);
    			cur_v = rnd.nextInt(0, n - 1);
    			if (st[cur_u].find(cur_v) != st[cur_u].end()) continue;
    			st[cur_u].insert(cur_v);
    			break;
    		}
    		u.push_back(cur_u);
    		v.push_back(cur_v);
    	}
    	renumber(n, u, v);
    }

    void randomTree(int n, vector<int>& u, vector<int>& v) {
		for (int i = 1; i < n; i++) {
		    u.push_back(i);
		    v.push_back(rnd.nextInt(0, i - 1));
		}
		renumber(n, u, v);
	}

    void randomConnectedGraph(int n, int m, vector<int> &u, vector<int> &v) {
    	assert(m >= n - 1);
    	randomTree(n, u, v);
    	while (u.size() < m) {
    		int newU = rnd.nextInt(0, N - 2);
    		int newV = rnd.nextInt(newU + 1, N - 1);
    		u.push_back(newU);
    		v.push_back(newV);
    	}
    }

    void completeGraph(int n, int m, vector<int> &u, vector<int> &v) {
    	assert(m == n * n);
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			u.push_back(i);
    			v.push_back(j);
    		}
    	}
    }
};
