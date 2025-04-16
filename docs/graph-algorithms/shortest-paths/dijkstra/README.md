# ダイクストラ法 (Dijkstra's Algorithm)

## 概要
ダイクストラ法は、グラフ上の単一始点最短経路問題を解くためのアルゴリズムです。非負の辺重みを持つグラフにおいて、ある頂点から他のすべての頂点への最短経路を求めることができます。

## 原理
ダイクストラ法は貪欲法に基づいており、以下の手順で動作します：

1. 始点の距離を0、他のすべての頂点の距離を無限大に初期化する
2. 未処理の頂点の中から、現時点で最短距離が最小の頂点を選ぶ
3. 選んだ頂点から到達可能な各頂点について、その頂点を経由した場合の距離を計算し、現在の距離より小さければ更新する
4. すべての頂点が処理されるまで2-3を繰り返す

優先度付きキュー（ヒープ）を使用することで、最短距離が最小の頂点を効率的に選択できます。

## 実装

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

vector<ll> dijkstra(const vector<vector<pair<int, int>>>& G, int start, int V) {
    vector<ll> dist(V, INF);
    dist[start] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (dist[v] < d)
            continue;

        for (auto [to, cost] : G[v]) {
            if (dist[to] > dist[v] + cost) {
                dist[to] = dist[v] + cost;
                pq.emplace(dist[to], to);
            }
        }
    }

    return dist;
}

int main() {
    // 入力
    int V, E, r;
    cin >> V >> E >> r;

    vector<vector<pair<int, int>>> G(V);
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].emplace_back(t, d);
    }

    // ダイクストラ法で最短経路を計算
    vector<ll> dist = dijkstra(G, r, V);

    // 結果の出力
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }

    return 0;
}
```

## 計算量
- 時間複雑度: O((V + E) log V)
  - V: 頂点数
  - E: 辺数
- 空間複雑度: O(V + E)

## 応用例
- 道路ネットワークにおける最短経路探索
- ネットワークルーティングアルゴリズム
- 地図アプリケーションの経路計算
- ゲームAIの経路探索

## 最適化
1. **フィボナッチヒープの使用**: 理論上、フィボナッチヒープを使用することで時間複雑度を O(E + V log V) に改善できます。
2. **二分ヒープの代わりに配列を使用**: 頂点数が少ない場合や辺の重みが整数で範囲が限られている場合、配列を使った実装も効率的です。
3. **停止条件の追加**: 特定の終点までの最短経路のみを求める場合、その頂点に到達したら早期に終了できます。

## 制約と注意点
- 辺の重みは非負でなければなりません。負の辺がある場合はベルマンフォード法を使用します。
- 密なグラフでは、優先度付きキューを使わない実装の方が効率的な場合があります。

## 関連問題
- [AOJ GRL_1_A: Single Source Shortest Path](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A)
- [AtCoder ABC 035 D - トレジャーハント](https://atcoder.jp/contests/abc035/tasks/abc035_d)
- [AtCoder ABC 012 D - バスと避けられない運命](https://atcoder.jp/contests/abc012/tasks/abc012_4)

## 関連アルゴリズム
- **ベルマンフォード法**: 負の辺を含むグラフでも使用可能
- **ワーシャルフロイド法**: すべての頂点ペア間の最短経路を求める
- **A*アルゴリズム**: ヒューリスティックを用いた最短経路探索
