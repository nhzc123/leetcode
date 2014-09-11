class Solution {
public:
    int candy(vector<int> &ratings) {

		int length = 0; //the descent length
		int total = 0; //the total number of candy
		int beforeDesc = 1; //the count of candy before desc
		int preCnt = 1; //the pre count of candy

		if(ratings.begin() != ratings.end()){

			total ++;

			for(vector<int>::iterator i = ratings.begin(); i != ratings.end(); i++){

				if(*i < *(i - 1)){

					length ++;

					if( beforeDesc <= length){

						total ++;

					}

					total += length;
					preCnt = 1;

				}
				else{

					int curCnt = 0;

					if( *i > *(i - 1)){

						curCnt = preCnt + 1;

					}
					else{

						cutCnt = 1;
					}

					total += cutCnt;
					beforeDesc = curCnt;
					preCur = curCnt;
					length = 0;

				}


		}


		}

		return total;

    }
};
