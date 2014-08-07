#include <iostream>
#include <vector>
#include <algorithm>

unsigned m = 0, n = 0;
std::vector<unsigned> q, r;

unsigned sum(const std::vector<unsigned>& v) {
	unsigned s = 0;
	/*for(unsigned i : v) s += r[i];*/
	for(auto itr=v.begin(); itr!=v.end(); ++itr)
		s += r[*itr];
	return s;
}

unsigned search_all(std::vector<unsigned>& v, unsigned k) {
	unsigned p = 0xFFFFFFFF;
	if(k >= m) return sum(v);
	for(unsigned i=0; i<n; ++i) {
		if(std::find(v.begin(), v.end(), i) != v.end()) continue;
		std::vector<unsigned> u(v);
		u.push_back(i);
		p = std::min(search_all(u, k+q[i]) , p);
	}
	return p;
}

unsigned search_all() {
	std::vector<unsigned> v(0);
	return search_all(v, 0);
}

int main(int argc, char **argv) {
	std::cin >> m >> n;
	
	q = std::vector<unsigned>(n);
	r = std::vector<unsigned>(n);
	for(unsigned i=0; i<n; ++i)
		std::cin >> q[i] >> r[i];
	
	std::cout << search_all() << std::endl;
	
	return 0;
}
