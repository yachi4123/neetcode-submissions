class DSU{
    int n;
    vector<int>parent;
    vector<int>rank;
    public:
    DSU(int n){
        this->n = n;
        for(int i=0 ; i<n ; i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int val){
        if(parent[val] == val){ // return only if we found the ultimate parent
            return val;
        }
        else{
            return parent[val] = find(parent[val]); // path compression & finding ultimate parent
        }
    }

    int UnionByRank(int a, int b){
        int parA = find(a); // find parent of a
        int parB = find(b); // find parent of b

        if(parA==parB)return -1;

        // we do union on the basis of the rank of their parent
        int rankA = rank[parA];
        int rankB = rank[parB];

        if(rankA == rankB){ // both parents rank is equal
            parent[parB] = parA; // connect b to a and chage parent to a's parent
            rank[parA]++; // increase the rank of parA
        }
        else if(rankA < rankB){ // connect a to b
            parent[parA] = parB;
        }
        else{
            parent[parB] = parA;
        }
        return 1;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,pair<int,int>>>vp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                vp.push_back({a,{i,j}});
            }
        }
        sort(vp.begin(),vp.end());
        DSU dsu(n);
        int ans = 0;
        for(int i=0;i<vp.size();i++){
            int wt = vp[i].first;
            int a = vp[i].second.first;
            int b = vp[i].second.second;
            if(dsu.UnionByRank(a,b)==1)ans+=wt;
        }
        return ans;
    }
};
