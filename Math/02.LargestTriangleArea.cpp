#include<bits/stdc++.h>
using namespace std;

double largestTriangleArea(vector<vector<int>>& points) {
    double ans=0;
    int n = points.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int x3 = points[k][0];
                int y3 = points[k][1];

                double d1 = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
                double d2 = sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
                double d3 = sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));

                double s = (d1 + d2 + d3)/2.0;
                double area = sqrt(s*(s-d1)*(s-d2)*(s-d3));
                ans =max(ans,area);
            }
        }
    }

    return ans;
}
int main(){
    vector<vector<int>>points={{2,3},{5,1},{8,7},{0,2}};
    cout<<largestTriangleArea(points);
    return 0;
}