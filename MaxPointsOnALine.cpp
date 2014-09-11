/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {

       int max_num = 0;
       map<double,int> m;

       for( int i = 0; i < points.size(); i++){

           m.clear();
           m[INT_MIN] = 0;
           int duplicate = 1;

           for( int j = 0; j < points.size(); j++){

               if( i == j){

                   continue;
               }

               if( points[i].x == points[j].x && points[i].y == points[j].y){
                   duplicate ++;
                   continue;
               }

               double k = ( points[i].x == points[j].x ) ? INT_MAX : (double)( points[j].y - points[i].y) / ( points[j].x - points[i].x);
               m[k]++;
           }

           map<double,int>::iterator iter = m.begin();

           for( ; iter != m.end(); iter++){

               if( iter->second + duplicate > max_num ){

                   max_num = iter->second + duplicate;
               }
           }

       }

       return max_num;
    }
};
