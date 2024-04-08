class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circular_count = 0;
        int square_count = 0;
        for (int student : students) {
            if (student == 0) {
                circular_count++;
            } else {
                square_count++;
            }
        }

        for (int sandwich : sandwiches) {
            if (sandwich == 0 && circular_count > 0) {
                circular_count--; 
            } else if (sandwich == 1 && square_count > 0) {
                square_count--; 
            } else {
                // no more sandwiches of the type that the student prefers
                // the remaining students can't eat
                break;
            }
        }
        return circular_count + square_count;
    }
};