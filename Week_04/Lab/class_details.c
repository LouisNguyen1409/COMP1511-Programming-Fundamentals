// Written 08/03/2023
// By Dinh Minh Nhat Nguyen z5428797
//
// Interactive program to scan in and display the details of students in a
// class.


#include <stdio.h>

//TODO use these enums and #defines to clean up the code
#define MAX_CLASS_SIZE 20
#define MAX_EXAM_MARK 40
#define MAX_ASSIGMENTS_MARK 60
#define NOT_FOUND -1

enum loop_sentinal { STOP_LOOPING, KEEP_LOOPING };
enum command {HELP, PRINT_STUDENT, PRINT_CLASS, QUIT, INVALID_COMMAND };
enum degree_type {UGRD, PGRD, INVALID_DEGREE};
enum major {
    COMPA1,
    COMPD1,
    COMPE1,
    COMPI1,
    COMPJ1,
    COMPN1,
    COMPS1,
    COMPY1,
    NONE
};

struct student {
    int z_id;
    int major;
    int degree_type;
    double assignments_mark;
    double exam_mark;
    double course_grade;
};

// Function Prototypes
int scaninning_class_size(void);
void print_degree_options(void);
int scanning_student_z_id(void);
int scanning_degree_type(void);
void print_command(void);
void print_major(int major);
void print_degree_type(int z_id, int degree_type);
void print_result(double assignments_mark, double exam_mark, double course_grade);
int scanning_major(void);
double scanning_ass_mark(void);
double checking_ass_mark(int assignments_mark);
double scanning_exam_mark(void);
double checking_exam_mark(int exam_mark);
int scanning_command(void);
void check_degree_type(int degree_type, int major);
int check_class_size(int class_size);
int check_student_index(struct student class[MAX_CLASS_SIZE], int class_size, int z_id);

//TODO CLEAN UP THIS CODE
int main(void) {
    int class_size = scaninning_class_size();
    if (check_class_size(class_size) == 0) {
        return 1;
    }
    struct student class[MAX_CLASS_SIZE];
    for (int i = 0; i < class_size; i++) {
        printf("Student %d: \n", i + 1);
        struct student new_student;
        new_student.z_id = scanning_student_z_id();
        print_degree_options();
        new_student.degree_type = scanning_degree_type();
        new_student.major = NONE;
        if (new_student.degree_type == 0) {
            printf("Select Major: \n");
            for (int major = 0; major <= 8; major++) {
                printf("%d: ", major);
                print_major(major);
            }
            new_student.major = scanning_major();
        }
        double assignments_mark = scanning_ass_mark();
        assignments_mark = checking_ass_mark(assignments_mark);
        double exam_mark = scanning_exam_mark();
        exam_mark = checking_exam_mark(exam_mark);
        new_student.assignments_mark = assignments_mark;
        new_student.exam_mark = exam_mark;
        new_student.course_grade = exam_mark + assignments_mark;
        class[i] = new_student;
    }
    int is_looping = KEEP_LOOPING;
    while (is_looping) {
        printf("Enter Command Number (0 for Help): ");
        int command = scanning_command();
        if (command == 0) {
            print_command();
        } else if (command == 1) {
            int z_id = scanning_student_z_id();
            int student_index = check_student_index(class, class_size, z_id);
            if (student_index == NOT_FOUND) {
                printf("No student with that zID exists\n");
            } else {
                print_degree_type(class[student_index].z_id
                , class[student_index].degree_type);
                check_degree_type(class[student_index].degree_type
                , class[student_index].major);
                print_result(class[student_index].assignments_mark
                , class[student_index].exam_mark, class[student_index].course_grade);
            }
        } else if (command == 2) {
            printf("Students: \n");
            for (int i = 0; i < class_size; i++) {
                struct student student = class[i];
                print_degree_type(student.z_id, student.degree_type);
                check_degree_type(student.degree_type, student.major);
                print_result(student.assignments_mark, student.exam_mark
                , student.course_grade);
            }
        } else if (command == QUIT) {
            is_looping = STOP_LOOPING;
        } else {
            printf("Invalid Command\n");
        }
    }
    printf("Exiting Program\n");
    return 0;
}

// Function Below

int scaninning_class_size(void) {
    int class_size;
    printf("Enter Class Size: ");
    scanf("%d", &class_size);
    return class_size; 
}

void print_degree_options(void) {
    printf("Select Degree Type: \n");
    printf("0: Undergraduate\n");
    printf("1: Postgraduate\n");
}

int scanning_student_z_id(void) {
    int z_id;
    printf("Enter zID: ");
    scanf("%d", &z_id);
    return z_id;
}

int scanning_degree_type(void) {
    int scanned_degree_type;
    scanf("%d", &scanned_degree_type);
    int degree_type = INVALID_DEGREE;
    if (scanned_degree_type == UGRD || scanned_degree_type == PGRD) {
        degree_type = scanned_degree_type;
    }
    return degree_type;
}

void print_command(void) {
    printf("Enter a number corresponding to one of the following commands: \n");
    printf("0 (Help): Display program instructions\n");
    printf("1 (Display Student): Print the details of a specific student\n");
    printf("2 (Display Class): Print the details of all students in a class\n");
    printf("3 (Quit): Exit the program\n");
}

void print_major(int major) {
    if (major == COMPA1) {
        printf("Computer Science\n");
    } else if (major == COMPD1) {
        printf("Database Systems\n");
    } else if (major == COMPE1) {
        printf("eCommerce Systems\n");
    } else if (major == COMPI1) {
        printf("Artificial Intelligence\n");
    } else if (major == COMPJ1) {
        printf("Programming Languages\n");
    } else if (major == COMPN1) {
        printf("Computer Networks\n");
    } else if (major == COMPS1) {
        printf("Embedded Systems\n");
    } else if (major == COMPY1) {
        printf("Security Engineering\n");
    } else {
        printf("None\n");
    }
}

void print_degree_type(int z_id, int degree_type) {
    printf("z%07d: {\n", z_id);
    printf("\tDegree Type: ");
    if (degree_type == UGRD) {
        printf("Undergraduate\n");
    } else if (degree_type == PGRD) {
        printf("Postgraduate\n");
    } else {
        printf("INVALID\n");
    }
}

void print_result(double ass_mark, double exam_mark, double course_grade) {
    printf("\tAssignments Mark: %3.02lf/%d\n", ass_mark, MAX_ASSIGMENTS_MARK);
    printf("\tExam Mark: %3.02lf/%d\n", exam_mark, MAX_EXAM_MARK);
    printf("\tCourse Grade: %3.02lf/%d\n", course_grade
    , MAX_ASSIGMENTS_MARK + MAX_EXAM_MARK);
    printf("}\n");
}

int scanning_major(void) {
    int scanned_major;
    scanf("%d", &scanned_major);
    int major = NONE;
    if (scanned_major >= COMPA1 && scanned_major < NONE) {
        major = scanned_major;
    }
    return major;
}

double scanning_ass_mark(void) {
    printf("Enter Assignments mark (out of %d): ", MAX_ASSIGMENTS_MARK);
    double assignments_mark;
    scanf("%lf", &assignments_mark);
    return assignments_mark;
}

double checking_ass_mark(int assignments_mark) {
    if (assignments_mark > MAX_ASSIGMENTS_MARK) {
        assignments_mark = MAX_ASSIGMENTS_MARK;
    } else if (assignments_mark < 0) {
        assignments_mark = 0;
    }
    return assignments_mark;
}

double scanning_exam_mark(void) {
    printf("Enter exam mark (out of %d): ", MAX_EXAM_MARK);
    double exam_mark;
    scanf("%lf", &exam_mark);
    return exam_mark;
}

double checking_exam_mark(int exam_mark) {
    if (exam_mark > MAX_EXAM_MARK) {
        exam_mark = MAX_EXAM_MARK;
    } else if (exam_mark < 0) {
        exam_mark = 0;
    }
    return exam_mark;
}

int scanning_command(void) {
    int scanned_command;
    scanf("%d", &scanned_command);
    int command = INVALID_COMMAND;
    if (scanned_command >= HELP && scanned_command <= QUIT) {
        command = scanned_command;
    }
    return command;
}

void check_degree_type(int degree_type, int major) {
    if (degree_type == UGRD) {
        printf("\tMajor: ");
        print_major(major);
    }
}

int check_class_size(int class_size) {
    if (class_size <= 0 || class_size > MAX_CLASS_SIZE) {
        printf("Class Size must be between 1 and %d\n", MAX_CLASS_SIZE);
        return 1;
    }
    return 0;
}

int check_student_index(struct student class[MAX_CLASS_SIZE], int class_size, int z_id) {
    int student_index = NOT_FOUND;
    for (int i = 0; i < class_size; i++) {
        if (class[i].z_id == z_id) {
            student_index = i;
        }
    }
    return student_index;
}

