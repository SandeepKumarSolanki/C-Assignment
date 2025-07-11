#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Student Data Structure
struct Student {
    string name;
    string studentId;
    vector<int> gradePoints;
    vector<int> credits;
};

// Function to convert grade to grade points with ranges
double gradeToPoints(char grade, double percentage) {
    if (grade == 'A') {
        if (percentage >= 9.5) return 10; // A+
        else return 9; // A
    } else if (grade == 'B') {
        return 8; // B
    } else if (grade == 'C') {
        return 7; // C
    } else if (grade == 'D') {
        return 6; // D
    } else if (grade == 'E') {
        return 5; // E
    } else if (grade == 'F') {
        return 0; // F
    }
    return -1; // Invalid grade
}

// Function to calculate CGPA
double calculateCGPA(const vector<int>& points, const vector<int>& credits) {
    int totalPoints = 0;
    int totalCredits = 0;
    
    for (size_t i = 0; i < points.size(); i++) {
        totalPoints += points[i] * credits[i];
        totalCredits += credits[i];
    }
    
    return (double)totalPoints / totalCredits;
}

// Function to handle user input safely
template <typename T>
T safeInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear(); // clear input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please try again." << endl;
        } else {
            return value;
        }
    }
}

int main() {
    int numSemesters = safeInput<int>("Enter number of semesters: ");
    
    Student student;
    student.name = safeInput<string>("Enter student's name: ");
    student.studentId = safeInput<string>("Enter student ID: ");
    
    double cgpa = 0;
    for (int sem = 1; sem <= numSemesters; sem++) {
        int numSubjects = safeInput<int>("Enter the number of subjects for semester " + to_string(sem) + ": ");
        vector<int> gradePoints;
        vector<int> credits;
        
        // Input grades and credits for each subject
        for (int i = 0; i < numSubjects; i++) {
            char grade;
            cout << "Enter grade for subject " << i + 1 << " (A+/A/B+/B/C/D/E/F): ";
            cin >> grade;
            grade = toupper(grade); // Convert grade to uppercase to avoid mismatch

            if (grade != 'A' && grade != 'B' && grade != 'C' && grade != 'D' && grade != 'E' && grade != 'F') {
                cout << "Invalid grade entered. Please enter a valid grade (A+/A/B+/B/C/D/E/F)." << endl;
                return -1;
            }

            double percentage = safeInput<double>("Enter percentage for subject " + to_string(i + 1) + ": ");
            int credit = safeInput<int>("Enter the credit hours for subject " + to_string(i + 1) + ": ");
            
            // Store the grade points and credits
            gradePoints.push_back(gradeToPoints(grade, percentage));
            credits.push_back(credit);
        }
        
        // Calculate CGPA for the semester
        double semesterCGPA = calculateCGPA(gradePoints, credits);
        cout << "CGPA for semester " << sem << ": " << semesterCGPA << endl;
        
        cgpa += semesterCGPA;
    }

    // Calculate overall CGPA
    cgpa /= numSemesters;

    // Output final CGPA
    cout << "Your overall CGPA is: " << cgpa << endl;

    return 0;
}
