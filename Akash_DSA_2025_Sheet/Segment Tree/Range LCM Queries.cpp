
class Solution {
  public:
    typedef long long ll;
    vector<ll> segTree;
    // GCD
    ll hcf(ll a, ll b){
        if(b == 0)return a;
        return hcf(b, a % b);
    }
    // LCM
    ll lcm(ll a, ll b){
        return (a / hcf(a, b)) * b;
    }
    /*
        BUILD SEGMENT TREE
    */
    void buildTree(int idx,int left,int right,vector<int> &arr){
        // leaf node
        if(left == right){
            segTree[idx] = arr[left];
            return;
        }
        int mid = left + (right - left) / 2;
        
        buildTree(2 * idx + 1,left,mid,arr);
        buildTree(2 * idx + 2,mid + 1,right,arr);

        segTree[idx] =lcm(segTree[2 * idx + 1],segTree[2 * idx + 2]);
    }
    /*
        UPDATE QUERY
    */
    void updateTree(int idx,int left,int right,int pos,int value){
        // leaf node
        if(left == right){
            segTree[idx] = value;
            return;
        }
        int mid = left + (right - left) / 2;
        if(pos <= mid){
            updateTree(2 * idx + 1,left,mid,pos,value);
        }
        else{
            updateTree(2 * idx + 2,mid + 1,right,pos,value);
        }

        segTree[idx] =lcm(segTree[2 * idx + 1],segTree[2 * idx + 2]);
    }
    /*
        RANGE LCM QUERY
    */
    ll queryTree(int idx,int left,int right,int start,int end){
        // no overlap
        if(right < start || left > end){
            return 1;
        }

        // complete overlap
        if(left >= start && right <= end){
            return segTree[idx];
        }

        int mid = left + (right - left) / 2;

        ll leftLcm = queryTree(2 * idx + 1,left,mid,start,end);

        ll rightLcm =queryTree(2 * idx + 2,mid + 1,right,start,end);

        return lcm(leftLcm, rightLcm);
    }
    vector<long long>RangeLCMQuery(vector<int> &arr,vector<vector<int>> &queries) {
        int n = arr.size();
        
        segTree.resize(4 * n);
        // build tree
        buildTree(0, 0, n - 1, arr);

        vector<ll> result;

        for(auto &query : queries){
            /*
                TYPE 1
                UPDATE QUERY
                [1,index,value]
            */
            if(query[0] == 1){
                int index = query[1];
                int value = query[2];

                updateTree(0,0,n - 1,index,value);
            }
            /*
                TYPE 2
                RANGE LCM QUERY
                [2,L,R]
            */
            else{
                int left = query[1];
                int right = query[2];

                ll ans = queryTree(0,0,n - 1,left,right);

                result.push_back(ans);
            }
        }
        return result;
    }
};

