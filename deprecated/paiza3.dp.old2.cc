#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>

typedef signed long long SLL;
const SLL MAX_SLL = 0x7FFFFFFFFFFFFFFF;

unsigned m = 0, n = 0;
std::vector<int> q, r;

SLL min(const SLL *v, unsigned begin, unsigned end) {
	SLL x = MAX_SLL;
	for(unsigned i=begin; i<end; ++i) {
		if(v[i] == -1) continue;
		x = std::min(v[i], x);
	}
	return x;
}

const unsigned K = 300000;
SLL *new_dp, *old_dp;

inline SLL* clear_dp_table(SLL *table) {
	for(unsigned l=0; l<K; ++l) table[l] = -1;
	table[0] = 0;
	return table;
}

inline SLL* initial_dp_table(SLL *table) {
	table = new SLL[K];
	clear_dp_table(table);
	return table;
}

inline SLL dp_update(SLL oldValue, SLL newValue) {
	if(oldValue != -1)
		return std::min(oldValue, newValue);
	else
		return newValue;
}

SLL search_dp(unsigned k) {
	clear_dp_table(new_dp);
	
	for(unsigned l=0; l<K; ++l) {
		if(old_dp[l] == -1) continue;
		
		if(q[k]+l < K) {
			new_dp[ q[k]+l ] = dp_update(new_dp[ q[k]+l ], old_dp[l] + r[k]);
		}
		
		new_dp[l] = dp_update(new_dp[l], old_dp[l]);
	}
	
	::memmove(old_dp, new_dp, sizeof(SLL)*K);
	
	if(k == n) {
		return min(old_dp, m, K);
	} else {
		return search_dp(k+1);
	}
}

SLL search_dp() {
	new_dp = initial_dp_table(new_dp);
	old_dp = initial_dp_table(old_dp);
	return search_dp(1);
}

int main(int argc, char **argv) {
	std::cin >> m >> n;
	
	q = std::vector<int>(n+1);
	r = std::vector<int>(n+1);
	q[0] = 0;
	r[0] = 0;
	for(unsigned i=1; i<=n; ++i)
		std::cin >> q[i] >> r[i];
	
	std::cout << search_dp() << std::endl;
	
	return 0;
}
