void topView(Node * root) {
        map<int,int> m;
        queue<pair<Node*,int>> q;
        int hd;
        if(root!=NULL){
            q.push({root,0});
        }
        while(!q.empty()){
            int s=q.size();
            while(s--){
                root=q.front().first;
                hd=q.front().second;
                if(m.find(hd)==m.end()){
                    m[hd]=root->data;
                }
                if(root->left!=NULL){q.push({root->left,hd-1});}
                if(root->right!=NULL){q.push({root->right,hd+1});}
                q.pop();
            }
        }
        for(auto &i:m){
            cout<<i.second<<" ";
        }
    }
