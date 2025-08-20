void spiral(node *root) {
    stack<node *> st1, st2;
    if (root == nullptr) return;
    st1.push(root);
    while(!st1.empty() || !st2.empty()) {
        while(!st1.empty()) {
            node *top1 = st1.top();
            st1.pop();
            cout << top1->data << " ";
            if (top1->right != nullptr) {
                st2.push(top1->right);
            }
            if (top1->left != nullptr) {
                st2.push(top1->left);
            }
        }
        while(!st2.empty()) {
            node *top2 = st2.top();
            st2.pop();
            cout << top2->data << " ";
            if (top2->left != nullptr) {
                st1.push(top2->left);
            }
            if (top2->right != nullptr) {
                st1.push(top2->right);
            }
        }
    }
}
