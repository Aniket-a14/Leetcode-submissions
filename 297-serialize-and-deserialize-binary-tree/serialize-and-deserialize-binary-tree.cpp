class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "null";
        queue<TreeNode*> q;
        q.push(root);
        string res;
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                res += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                res += "null,";
            }
        }
        return res;
    }

    TreeNode* deserialize(string data) {
        if(data=="null") return NULL;
        stringstream ss(data);
        string curr = "";
        getline(ss,curr,',');
        TreeNode* root = new TreeNode(stoi(curr));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* fr = q.front();q.pop();
            getline(ss,curr,',');
            if(curr=="null"){
                fr->left = NULL;
            }else{
                fr->left = new TreeNode(stoi(curr));
                q.push(fr->left);
            }
            getline(ss,curr,',');
            if(curr=="null"){
                fr->right = NULL;
            }else{
                fr->right = new TreeNode(stoi(curr));
                q.push(fr->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));