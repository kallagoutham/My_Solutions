//1st Appproach T(N)=O(n^2)
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        for(int i=0;i<n;i++){
            reverse(image[i].begin(),image[i].end());
            for(int j=0;j<n;j++){
                image[i][j]^=1;
            }
        }
        return image;
    }
};

/*-----------------------------------------------------------------------------------------------------------------------*/
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        vector<int> temp(n,1);
        for(int i=0;i<n;i++){
            transform(image[i].begin(),image[i].end(),temp.begin(),image[i].begin(),bit_xor<int>());
            reverse(image[i].begin(),image[i].end());
        }
        return image;
    }
};
/*-----------------------------------------------------------------------------------------------------------------------*/
