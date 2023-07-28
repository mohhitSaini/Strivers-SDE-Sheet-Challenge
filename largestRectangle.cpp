int largestRectangle(vector<int>& heights) {
    int n = heights.size();
    vector<int> prevSmaller(n);
    vector<int> nextSmaller(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i] && st.top() != -1 && st.top() != n) {
            st.pop();
        }
        if (st.empty()) {
            prevSmaller[i] = -1;
        } else {
            prevSmaller[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i] && st.top() != -1 && st.top() != n) {
            st.pop();
        }
        if (st.empty()) {
            nextSmaller[i] = n;
        } else {
            nextSmaller[i] = st.top();
        }
        st.push(i);
    }

    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {
        ans = max(ans, (nextSmaller[i] - prevSmaller[i] - 1) * heights[i]);
    }
    return ans;
}
