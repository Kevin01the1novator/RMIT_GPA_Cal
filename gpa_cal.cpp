#include <iostream>
#include <vector>
using namespace std;


int grade_point_conversion(vector<int>* score_arr_ptr, vector<int>* grade_point_arr_ptr) {
    grade_point_arr_ptr->clear(); // Clear any existing values
    int total_grade_points = 0;
    
    for (int score : *score_arr_ptr) {
        int grade_point = 0;
        if (score >= 80 && score <= 100) {
            grade_point = 4;
        } else if (score >= 70 && score<=79) {
            grade_point = 3;
        } else if (score >= 60 && score<= 69) {
            grade_point = 2;
        } else if (score >= 50 && score<=59) {
            grade_point = 1;
        } else if (score < 50) {
            grade_point = 0;
        }
        grade_point_arr_ptr->push_back(grade_point);
        total_grade_points += grade_point;
    }
    
    return total_grade_points;
}

float gpa_calculation(int total_grade_point, int credit_counter, vector<int>* grade_point_arr_ptr) {
    int credit = 12;
    int total_credits = credit * credit_counter; // Total credits taken

    int total_weighted_points = 0;
    // Process each grade point and multiply by credit value
    for (int i = 0; i < grade_point_arr_ptr->size(); i++) {
        int weighted_points = (*grade_point_arr_ptr)[i] * credit;
        total_weighted_points += weighted_points;
    }
    
    // Calculate GPA - weighted points divided by total credits
    float gpa = static_cast<float>(total_weighted_points) / total_credits;
    return gpa;
}


int main(){
    vector<int> score_arr = {70,50,60,71,65,53,60,81,81,92,81,64,81,75,80,81,81};
    vector<int> grade_point_arr = {};

    int score;
    int credit_counter = 0;

    //If not choose to manually enter score, then specify score in the score_arr above.
    if (score_arr.empty()) {
        while(1) {
            cout<<"Enter your score (enter -1 to Exit Input Loop): ";
            cin >> score;
            if (score >= 1) {
                score_arr.push_back(score);
                credit_counter +=1;
            }
    
            else if (score == -1) {
                break;
            }
        }   
        cout << "Score Entered";
        for (int i : score_arr) {
            cout << i << ", ";
        }
    }

    else {
        credit_counter = score_arr.size();
    }
    
    //Calculate total Grade Points
    cout << "\nCalculating grade points..." << endl;
    int total_grade_points = grade_point_conversion(&score_arr, &grade_point_arr);
    
    cout << "Grade points: ";
    for (int gp : grade_point_arr) {
        cout << gp << ", ";
    }
    cout << "\nTotal grade points: " << total_grade_points << endl;

    //Calculation of GPA
    float gpa = gpa_calculation(total_grade_points, credit_counter, &grade_point_arr);
    cout << "The GPA is: " << gpa << endl;

}