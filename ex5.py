import fileinput
import json
import os


def names_of_registered_students(input_json_path, course_name):
    """
    This function returns a list of the names of the students who registered for
    the course with the name "course_name".

    :param input_json_path: Path of the students database json file.
    :param course_name: The name of the course.
    :return: List of the names of the students.
    """
    listOfStudents = []

    try:
        with open(input_json_path, 'r') as file:
            loaded_dict = json.load(file)
    except IOError:
        print('Error in opening file')
        return
    else:
        for value in loaded_dict.values():
            for subject in value["registered_courses"]:
                if subject == course_name:
                    listOfStudents.append(value["student_name"])
        file.close()
        return listOfStudents

        pass


def enrollment_numbers(input_json_path, output_file_path):
    """
    This function writes all the course names and the number of enrolled
    student in ascending order to the output file in the given path.

    :param input_json_path: Path of the students database json file.
    :param output_file_path: Path of the output text file.
    """

    students_dict = {}
    try:
        with open(input_json_path, 'r') as inputFile:
            loaded_dict = json.load(inputFile)
    except IOError:
        print('Error in opening file')
        return

    else:
        for value in loaded_dict.values():
            for subject in value["registered_courses"]:
                if subject in students_dict.keys():
                    students_dict[subject] += 1
                else:
                    students_dict[subject] = 1

        sorted_list = sorted(students_dict.keys())
        new_student_dict = {}
        for key in sorted_list:
            new_student_dict[key] = students_dict[key]

        try:
            with open(output_file_path, 'w') as outputFile:
                for key in new_student_dict.keys():
                    outputFile.write('"' + key + '" ' + str(new_student_dict[key])+'\n')
        except IOError:
            print('Error in opening file')
            return
    pass


def courses_for_lecturers(json_directory_path, output_json_path):
    """
    This function writes the courses given by each lecturer in json format.

    :param json_directory_path: Path of the semsters_data files.
    :param output_json_path: Path of the output json file.
    """
    dictOfLecturers = {}

    for file in os.listdir(json_directory_path):
        file_path = os.path.join(json_directory_path, file)
        path_tuple = os.path.splitext(file_path)
        if path_tuple[1] == '.json':
            try:
                with open(file_path, 'r') as inputFile:
                    loaded_dict = json.load(inputFile)
                    for course in loaded_dict.values():
                        for lecturer in course["lecturers"]:
                            if lecturer in dictOfLecturers.keys():
                                if course["course_name"] in dictOfLecturers[lecturer]:
                                    continue
                                else:
                                    dictOfLecturers[lecturer].append(course["course_name"])
                            else:
                                dictOfLecturers[lecturer] = [course["course_name"]]
            except IOError:
                print('Error in opening file')
                return
    try:
        with open(output_json_path, 'w') as outputFile:
            json.dump(dictOfLecturers, outputFile, indent=4)
    except IOError:
        print('Error in opening file')
        return

    pass
