#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 2e5+55;
int x[MAXN];
int cnt[MAXN];
int ans[MAXN];

// int arr[MAXN];
int block;

struct query {
    int l, r;
};

query queries[MAXN];


// int brute(int a, int b) {
//     int index = 0;
//     char flag = true;
// 
//     for(int i = 0; i < (b - a); i++) {
//         arr[i] = 0;
//     }
// 
//     for(int i = a; i <= b; i++) {
//         for(int j = 0; j < index; j++) {
//             if(arr[j] == x[i]) {
//                 flag = false;
//                 break;
//             }
//         }
//         if(flag) {
//             arr[index] = x[i];
//             index++;
//         } 
//         flag = true;
//     }
//     return index;
// }
//

bool compare(query a, query b) {
    if(a.l / block != b.l / block) {
        return (a.l / block) < (b.l / block);
    } 
    return a.r < b.r;
}

void print_queries(int n) {
    for(int i = 0; i < n; i++) {
        printf("%d %d\n", queries[i].l, queries[i].r);
    }
    puts("");
}

void print_cnt(int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", cnt[i]);
    }
    puts("");
}

int main() {
    // Need to implement both index compression and a way to save the index of each query
    int n, q; 
    scanf("%d %d", &n, &q);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    block = (int)sqrt(n) + 1;

    int a, b;
    for(int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        a--; b--;
        queries[i] = {a, b};
        // printf("%d\n", brute(a, b));
    }

    sort(queries, queries+q, compare);

    print_queries(q);


    // Iterate over sorted queries according to mo's algorithm
    int curr = 0;
    int l = queries[0].l, r = queries[0].l;
    for(int i = 0; i < q; i++) {
        print_cnt(n);

        printf("%d\n", curr);

        while(l < queries[i].l) {
            cnt[x[l]]--;
            if(cnt[x[l]] == 0) {
                curr--;
            }
            l++;
        }

        while(l > queries[i].l) {
            cnt[x[l]]++;
            if(cnt[x[l]] == 1) {
                curr++;
            }
            l--;
        }

        printf("%d\n", curr);

        while(r <= queries[i].r) {
            cnt[x[r]]++;
            if(cnt[x[r]] == 1) {
                curr++;
            }
            r++;
        }


        while(r > queries[i].r+1) {
            cnt[x[r]]--;
            if(cnt[x[r]] == 0) {
                curr--;
            }
            r--;
        }
        printf("L: %d R: %d, %d\n", l, r, curr);
    }

}
