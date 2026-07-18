عندك Array من الأرقام، ومسموح تعمل k عمليات.
كل عملية = تزود أي عنصر بمقدار 1.
المطلوب: أكبر عدد من العناصر تقدر تخليهم متساويين
auto bad = [&](const std::vector<int>& x, int k) {
        sort(x.begin(), x.end());
        int64_t t = {};
        int i = {};
        int r = 1;
        for (int j = {}; j < x.size(); j++) {
            t += x[j];
            while (1LL * x[j] * (j - i + 1) - t > k) {
                t -= x[i];
                ++i;
            }
            r = std::max(r, j - i + 1);
            r = (r < (j - i + 1)? (j - i + 1) : r);
        }
        return r;
};
