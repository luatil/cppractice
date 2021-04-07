#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, std::less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

struct Segment {
    int left;
    int right;
    int id;
 
    bool operator <(const Segment& rhs) {
        return std::make_tuple(left, -right, id) <
               std::make_tuple(rhs.left, -rhs.right, rhs.id);
    }
};
 
int main() {
    int n;
    scanf("%d", &n);
 
    std::vector<Segment> segments;
    segments.reserve(n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        segments.push_back({l, r, i});
    }
    std::sort(segments.begin(), segments.end());

    std::vector<int> isContained(n);
    // Use pairs to get a multiset
    ordered_set<std::pair<int, int>> st;
    for (const Segment& segment: segments) {
        // -1 simply because no element has the id -1
        isContained[segment.id] = st.size() - st.order_of_key({segment.right, -1});
        st.insert({segment.right, segment.id});
    }
 
    std::vector<int> contains(n);
    st.clear();
    for (auto it = segments.rbegin(); it != segments.rend(); ++it) {
        const auto& segment = *it;
        contains[segment.id] = st.order_of_key({segment.right+1, -1});
        st.insert({segment.right, segment.id});
    }

    for (int id: contains) {
        printf("%d ", id);
    }
    puts("");
    for (int id: isContained) {
        printf("%d ", id);
    }
    puts("");
}