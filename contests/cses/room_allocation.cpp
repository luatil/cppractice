#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class t> using ordered_set =tree<t, null_type, std::less<t>, rb_tree_tag,tree_order_statistics_node_update> ;

struct Segment {
    int left;
    int right;
    int id;
 
    bool operator <(const Segment& rhs) {
        return std::make_tuple(left, right, id) <
               std::make_tuple(rhs.left, rhs.right, rhs.id);
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<Segment> segments;
    segments.reserve(n);
    int l, r;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        segments.push_back({l, r, i});
    }
    std::sort(segments.begin(), segments.end());

    int maxNumberOfRooms = 0, lastRoom = 1;
    priority_queue<pair<int, int>> pq; // min heap to store departure times
    vector<int> whichRoom(n);

    for(const auto&segment : segments) {
        if(pq.empty()) {
            lastRoom = 1;
            whichRoom[segment.id] = lastRoom;
            pq.push({-segment.right, lastRoom});
        } else {
            auto [minDepartureTime, roomId] = pq.top();
            if(-minDepartureTime < segment.left) {
                pq.pop();
                pq.push({-segment.right, roomId});
                whichRoom[segment.id] = roomId;
            } else {
                lastRoom++;
                pq.push({-segment.right, lastRoom});
                whichRoom[segment.id] = lastRoom;
            }
        }
        maxNumberOfRooms = max(maxNumberOfRooms, int(pq.size()));
    }


    cout << maxNumberOfRooms << '\n';
    for(const auto&el : whichRoom) {
        cout << el << ' ';
    }
    cout << '\n';
}