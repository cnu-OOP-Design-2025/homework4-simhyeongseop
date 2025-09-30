#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    Student newStudent(name, id, midterm, final);
    students[num_of_students] = newStudent;
    num_of_students++;
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getID() == id) {
            for(int j = i; j < num_of_students - 1; j++) {
                students[j] = students[j + 1];
            }
            num_of_students--;
            break;
        }
    }
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getID() == student.getID()) {
            students[i] = student;
            break;
        }
    }
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    int student_idx = -1;
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getID() == id) {
            student_idx = i; break;
        }
    }
    return student_idx;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    int bestMidterm_idx = -1;
    int bestMidterm_id = -1;
    float bestMidterm = 0;
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getRecord().getMidterm() > bestMidterm) {
            bestMidterm_idx = i;
            bestMidterm_id = students[i].getID();
            bestMidterm = students[i].getRecord().getMidterm();
        }
    }
    return bestMidterm_id;
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    int bestFinal_idx = -1;
    int bestFinal_id = -1;
    float bestFinal = 0;
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getRecord().getFinal() > bestFinal) {
            bestFinal_idx = i;
            bestFinal_id = students[i].getID();
            bestFinal = students[i].getRecord().getFinal();
        }
    }
    return bestFinal_id;
}

int StudentManager::findBestStudent() const {
    /* TODO */
    int bestTotal_idx = -1;
    int bestTotal_id = -1;
    float bestTotal = 0;
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getRecord().getTotal() > bestTotal) {
            bestTotal_idx = i;
            bestTotal_id = students[i].getID();
            bestTotal = students[i].getRecord().getTotal();
        }
    }
    return bestTotal_id;
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float midterm_sum = 0.0f;
    for (int i = 0; i < num_of_students; i++) {
        midterm_sum += students[i].getRecord().getMidterm();
    }
    return ( midterm_sum / (float) num_of_students );
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    float final_sum = 0.0f;
    for (int i = 0; i < num_of_students; i++) {
        final_sum += students[i].getRecord().getFinal();
    }
    return ( final_sum / (float) num_of_students );
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    float total_sum = 0.0f;
    for (int i = 0; i < num_of_students; i++) {
        total_sum += students[i].getRecord().getTotal();
    }
    return ( total_sum / (float) num_of_students );
}

