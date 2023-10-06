struct Point {
    double x, y;
};

Point test_point[] = { { -1.0, 0.0 },
                       { 0.0, 1.0 },
                       { 1.0, 0.0 },
                       { 0.0, -1.0 } };

double lower_limit = 0.00001;

double distSum(Point p,Point arr[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++) {
        double distx = abs(arr[i].x - p.x);
        double disty = abs(arr[i].y - p.y);
        sum += sqrt((distx * distx) + (disty * disty));
    }
    return sum;
}

double geometricMedian(Point arr[], int n)
{
 
    Point current_point;
 
    for (int i = 0; i < n; i++) {
        current_point.x += arr[i].x;
        current_point.y += arr[i].y;
    }
 
    current_point.x /= n;
    current_point.y /= n;
 
    
    double minimum_distance = 
       distSum(current_point, arr, n);
 
    int k = 0;
    while (k < n) {
        for (int i = 0; i < n, i != k; i++) {
            Point newpoint;
            newpoint.x = arr[i].x;
            newpoint.y = arr[i].y;
            double newd = distSum(newpoint, arr, n);
            if (newd < minimum_distance) {
                minimum_distance = newd;
                current_point.x = newpoint.x;
                current_point.y = newpoint.y;
            }
        }
        k++;
    }
 
    
    double test_distance = 1000;
    int flag = 0;
 
   
    while (test_distance > lower_limit) {
 
        flag = 0;
 
       
        for (int i = 0; i < 4; i++) {
 
           
            Point newpoint;
            newpoint.x = current_point.x
                 + (double)test_distance * test_point[i].x;
            newpoint.y = current_point.y
                 + (double)test_distance * test_point[i].y;
 
            
            double newd = distSum(newpoint, arr, n);
 
            if (newd < minimum_distance) {
 
                minimum_distance = newd;
                current_point.x = newpoint.x;
                current_point.y = newpoint.y;
                flag = 1;
                break;
            }
        }
 
        if (flag == 0)
            test_distance /= 2;
    }
 
   return minimum_distance;
}
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
            int n=positions.size();
        Point arr[n];
            for(int i=0;i<n;i++){
                    arr[i].x=positions[i][0];
                    arr[i].y=positions[i][1];
            }
            return geometricMedian(arr,n);
    }
};