#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>
 
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
    int maxPastEnd = 0;
    for (const Segment& segment: segments) {
        if (segment.right <= maxPastEnd) {
            isContained[segment.id] = 1;
        } else {
            maxPastEnd = segment.right;
        }
    }
 
    std::vector<int> contains(n);
    int minPastEnd = 1000000001;
    for (auto it = segments.rbegin(); it != segments.rend(); ++it) {
        const auto& segment = *it;
        if (segment.right >= minPastEnd) {
            contains[segment.id] = 1;
        } else {
            minPastEnd = segment.right;
        }
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