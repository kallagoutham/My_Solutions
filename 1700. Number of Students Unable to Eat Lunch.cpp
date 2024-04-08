class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int i=0,j=0;
        while(i<students.size()){
            if(sandwiches[j]==students[i]){
                j++;
                students.erase(students.begin()+i);
                i=0;
            }else{
                i++;
            }
        }
        return students.size();
    }
};
